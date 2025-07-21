#include "Game.hpp"

Game::Game() {
    initWindow();
    pushState(std::make_unique<MenuState>(*this));
}

Game::~Game() {
    ImGui::SFML::Shutdown();
    window_.close();
}

void Game::initWindow() {
    window_ = sf::RenderWindow(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), GAME_TITLE);
    window_.setFramerateLimit(FRAMERATE);

    if (!ImGui::SFML::Init(window_))
        std::exit(EXIT_FAILURE);
}

void Game::run() {
    while (window_.isOpen()) {
        sf::Time dt = clock_.restart();

        handleEvents();
        update(dt);
        render();
    }
}

void Game::closeWindow() {
    window_.close();
}

void Game::handleEvents() {
    while (const std::optional event = window_.pollEvent()) {
        ImGui::SFML::ProcessEvent(window_, *event);

        if (event->is<sf::Event::Closed>()) {
            window_.close();
        }

        if (!states_.empty()) {
            states_.back()->handleInput(*event);
        }
    }
}

void Game::update(sf::Time dt) {
    ImGui::SFML::Update(window_, clock_.restart());

    ImGui::Begin("Debug Info");
    ImGui::Text("FPS: %.0f", 1.0f / dt.asSeconds());

    if (!states_.empty()) {
        states_.back()->update(dt);
        ImGui::Text("State: %s", states_.back()->getName().c_str());
    } else {
        ImGui::Text("No active state");
    }

    ImGui::End();
}

void Game::render() {
    window_.clear();

    if (!states_.empty()) {
        states_.back()->draw(window_);
    }

    ImGui::SFML::Render(window_);
    window_.display();
}

void Game::pushState(std::unique_ptr<GameState> state) {
    if (state) {
        states_.push_back(std::move(state));
    }
}

void Game::popState() {
    if (!states_.empty()) {
        states_.pop_back();
    }
}

void Game::changeState(std::unique_ptr<GameState> state) {
    popState();
    pushState(std::move(state));
}
