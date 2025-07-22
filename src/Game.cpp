#include "Game.hpp"
#include <SFML/Window/VideoMode.hpp>
#include <imgui.h>
#include <iostream>

Game::Game() : m_gameView(sf::FloatRect({ 0.f, 0.f }, { BASE_WINDOW_WIDTH, BASE_WINDOW_HEIGHT })) {
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

void Game::handleEvents() {
    while (const std::optional event = window_.pollEvent()) {
        ImGui::SFML::ProcessEvent(window_, *event);

        if (event->is<sf::Event::Closed>()) {
            window_.close();
        }

        if (!states_.empty()) {
            states_.back()->handleInput(*event, window_);
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
    ImGui::Text("View: %0.fx%0.f", m_gameView.getSize().x, m_gameView.getSize().y);
    ImGui::SeparatorText("More");

    if (ImGui::Button("Show state info")) {
        m_showStateDebugWindow = !m_showStateDebugWindow;
    }

    ImGui::End();

    if (m_showStateDebugWindow) {
        ImGui::Begin("State Info", &m_showStateDebugWindow);

        if (!states_.empty()) {
            ImGui::Text("Current: %s", states_.back()->getName().c_str());
        } else {
            ImGui::Text("Current: No active state");
        }

        ImGui::Text("States:");
        for (std::unique_ptr<GameState>& state : states_) {
            ImGui::BulletText("%s", state->getName().c_str());
        }

        ImGui::End();
    }

    if (!states_.empty()) {
        states_.back()->update(dt, window_);
    }
}

void Game::render() {
    window_.clear();
    window_.setView(m_gameView);

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
