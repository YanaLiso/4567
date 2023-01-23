#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include "ball.h"
#include "rowbrick.h"
#include "bat.h"

/*void rectInit(sf::RectangleShape& rect, const sf::Color rectColor, const sf::Vector2f rectStartPosition) {
	rect.setSize(BAT_SIZE);
	rect.setFillColor(rectColor);
	rect.setPosition(rectStartPosition);
}*/

bool pointInRect(sf::RectangleShape rect, sf::Vector2f point) {
	return	rect.getPosition().x <= point.x &&
		point.x <= rect.getPosition().x + rect.getSize().x &&
		rect.getPosition().y <= point.y &&
		point.y <= rect.getPosition().y + rect.getSize().y;
}

void ballCollidedWithBricks(Ball& ball, Brickrow& brickrow) {
	sf::Vector2f midLeft{
		ball.shape.getPosition().x,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	sf::Vector2f midTop{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y
	};
	sf::Vector2f midBottom{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y + 2 * BALL_RADIUS
	};
	sf::Vector2f midRight{
		ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	for (int i = 0; i < brickrow.size; i++) {
		if (pointInRect(brickrow.brickArr[i].shape, midTop)) {
			std::swap(
				brickrow.brickArr[i],
				brickrow.brickArr[brickrow.size - 1]
			);
			brickrow.size--;
			ball.speedY = -ball.speedY;
			break;
		}
	}
	for (int i = 0; i < brickrow.size; i++) {
		if (pointInRect(brickrow.brickArr[i].shape, midLeft)) {

			std::swap(
				brickrow.brickArr[i],
				brickrow.brickArr[brickrow.size - 1]
			);
			brickrow.size--;
			ball.speedY = -ball.speedY;
			break;
		}
	}
	for (int i = 0; i < brickrow.size; i++) {
		if (pointInRect(brickrow.brickArr[i].shape, midBottom)) {
			std::swap(
				brickrow.brickArr[i],
				brickrow.brickArr[brickrow.size - 1]
			);
			brickrow.size--;
			ball.speedY = -ball.speedY;
	        break;
		}
	}
			for (int i = 0; i < brickrow.size; i++) {
				if (pointInRect(brickrow.brickArr[i].shape, midRight)) {
					std::swap(
						brickrow.brickArr[i],
						brickrow.brickArr[brickrow.size - 1]
					);
					brickrow.size--;
					ball.speedY = -ball.speedY;
					break;
				}
			}
		}
void ballCollidedWithBat(Ball& ball,Bat& bat) {
	sf::Vector2f leftTop{ ball.shape.getPosition().x, ball.shape.getPosition().y };
	sf::Vector2f midLeft{ ball.shape.getPosition().x, ball.shape.getPosition().y + BALL_RADIUS };
	sf::Vector2f leftBottom{ ball.shape.getPosition().x, ball.shape.getPosition().y +
		2 * BALL_RADIUS };
	sf::Vector2f midTop{ ball.shape.getPosition().x + BALL_RADIUS,  ball.shape.getPosition().y };
	sf::Vector2f midBottom{ ball.shape.getPosition().x + BALL_RADIUS,  ball.shape.getPosition().y +
		2 * BALL_RADIUS };
	sf::Vector2f rightTop{ ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y };
	sf::Vector2f midRight{ ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y + BALL_RADIUS };
	sf::Vector2f rightBottom{ ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y + 2 * BALL_RADIUS };


	//от правого края 
	if (pointInRect(bat.shape, midLeft) && pointInRect(bat.shape, leftTop) ||
		pointInRect(bat.shape, midLeft) && pointInRect(bat.shape, leftBottom))
	{
		ball.speedX = -ball.speedX;
		if (ball.speedX > 0) ball.speedX++;
		else ball.speedX--;
		if (ball.speedY > 0) ball.speedY++;
		else ball.speedY--;
	}
	//от верхнего края
	if (pointInRect(bat.shape, midBottom) && pointInRect(bat.shape, leftBottom) ||
		pointInRect(bat.shape, midBottom) && pointInRect(bat.shape, rightBottom))
	{
		ball.speedY = -ball.speedY;
	}
	//от нижнего края 
	if (pointInRect(bat.shape, midTop) && pointInRect(bat.shape, leftTop) ||
		pointInRect(bat.shape, midTop) && pointInRect(bat.shape, rightTop))
	{
		ball.speedY = -ball.speedY;
	}
	//в ракетку попал только левый верхний угол
	if ((pointInRect(bat.shape, leftTop) || pointInRect(bat.shape, leftBottom)) &&
		pointInRect(bat.shape, midLeft))
	{
		ball.speedY = -ball.speedY;
	}
}