#pragma once
#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
struct Textobj
{
	sf::Font font;
	sf::Text text;
	int leftScore;
};
void textInit(Textobj& textobj, int score) {
	textobj.font.loadFromFile("DS-DIGIB.ttf");
	textobj.text.setString(std::to_string(score));
	textobj.text.setFont(textobj.font);
	textobj.text.setCharacterSize(FONT_SIZE);
	textobj.text.setPosition(TEXT_POS);
}
void textUpdate(Textobj& textobj, int score) {
	textobj.text.setString(std::to_string(score));
}
void textDraw(sf::RenderWindow& window, const Textobj& text) {
	window.draw(text.text);
}
