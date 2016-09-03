#include "Window.h"

Window::Window()
{
	window.create(sf::VideoMode(800,600), "Fiszki");
}

Window::~Window() {}

void Window::draw(sf::Drawable& d) { window.draw(d); }

sf::RenderWindow* Window::getWindow() { return &window; }

void Window::closeWindow() { window.close(); }

void Window::startRender() { window.clear(sf::Color::Blue); }

void Window::finishRender() { window.display(); }