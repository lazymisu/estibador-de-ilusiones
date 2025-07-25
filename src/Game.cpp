#include "Game.hpp"
#include "States/GameState.hpp"
#include "Utils/Definitions.hpp"

Game::Game() : context_{window_, asset_manager_} {
  initWindow();
  pushState(std::make_unique<MenuState>(context_));
}

Game::~Game() {
  ImGui::SFML::Shutdown();
  window_.close();
}

void Game::initWindow() {
  game_view_ = sf::View(
      sf::FloatRect({0.f, 0.f}, {kBaseWindowWidth, kBaseWindowHeight}));

  window_ = sf::RenderWindow(sf::VideoMode({kWindowWidth, kWindowHeight}),
                             kGameTitle);

  window_.setFramerateLimit(kFramerate);

  if (!ImGui::SFML::Init(window_)) {
    std::exit(EXIT_FAILURE);
  }
}

void Game::run() {
  while (window_.isOpen()) {
    sf::Time dt = clock_.restart();

    handleEvents();
    update(dt);
    render();
  }
}

void Game::handleEvents() {
  while (const std::optional event = window_.pollEvent()) {
    ImGui::SFML::ProcessEvent(window_, *event);

    if (event->is<sf::Event::Closed>()) {
      window_.close();
    }

    if (!game_states_.empty()) {
      game_states_.back()->handleInput(*event);
    }
  }
}

void Game::update(sf::Time dt) {
  ImGui::SFML::Update(window_, clock_.restart());

  ImGui::Begin("Debug Info");
  ImGui::Text("FPS: %.0f", ImGui::GetIO().Framerate);
  ImGui::Text("Delta Time: %.4f", clock_.getElapsedTime().asSeconds());
  ImGui::SeparatorText("Window");
  ImGui::Text("Resolution: %ix%i", window_.getSize().x, window_.getSize().y);
  ImGui::Text("View: %0.fx%0.f", game_view_.getSize().x,
              game_view_.getSize().y);
  ImGui::SeparatorText("More");

  if (ImGui::Button("Show state info")) {
    show_state_debug_window = !show_state_debug_window;
  }

  ImGui::End();

  if (show_state_debug_window) {
    ImGui::Begin("State Info", &show_state_debug_window);

    if (!game_states_.empty()) {
      ImGui::Text("Current: %s", game_states_.back()->getName().c_str());
    } else {
      ImGui::Text("Current: No active state");
    }

    ImGui::Text("States:");

    for (std::unique_ptr<GameState> &state : game_states_) {
      ImGui::BulletText("%s", state->getName().c_str());
    }

    ImGui::End();
  }

  if (!game_states_.empty()) {
    game_states_.back()->update(dt);
  }
}

void Game::render() {
  window_.clear();
  window_.setView(game_view_);

  if (!game_states_.empty()) {
    game_states_.back()->draw(window_);
  }

  ImGui::SFML::Render(window_);
  window_.display();
}

void Game::pushState(std::unique_ptr<GameState> state) {
  if (state) {
    game_states_.push_back(std::move(state));
  }
}

void Game::popState() {
  if (!game_states_.empty()) {
    game_states_.pop_back();
  }
}

void Game::changeState(std::unique_ptr<GameState> state) {
  popState();
  pushState(std::move(state));
}
