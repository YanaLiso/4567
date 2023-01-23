
#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
struct Brick
{
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f position;
};
void brickInit(Brick& brick, sf::Color color, sf::Vector2f position)
{
	brick.shape.setPosition(position);
	brick.shape.setSize(sf::Vector2f{ BRICK_WIDTH ,BRICK_HEIGHT });
	brick.shape.setFillColor(color);
}
void brickUpdate(Brick& brick)
{

}
void brickDraw(sf::RenderWindow& window, const Brick& text) {
	window.draw(text.shape);
}