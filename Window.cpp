#include "Window.h"

Window::Window()
:x(800),
 y(600)
{
	window.create(sf::VideoMode(x,y), "Fiszki", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);
}

Window::~Window() {}

void Window::draw(sf::Drawable& d) { window.draw(d); }

sf::RenderWindow* Window::getWindow() { return &window; }

void Window::closeWindow() { window.close(); }

void Window::startRender() { window.clear(); }

void Window::finishRender() { window.display(); }

int Window::getX() { return x; }

int Window::getY() { return y; }