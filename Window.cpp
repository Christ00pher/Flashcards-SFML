#include "Window.h"

Window::Window()
{
	window.create(sf::VideoMode(800,600), "Fiszki");
	window.setFramerateLimit(60);
}

Window::~Window() {}

void Window::draw(sf::Drawable& d) { window.draw(d); }

sf::RenderWindow* Window::getWindow() { return &window; }

void Window::closeWindow() { window.close(); }

void Window::startRender() { window.clear(); }

void Window::finishRender() { window.display(); }