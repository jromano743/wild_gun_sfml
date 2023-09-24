#include "HotelWindow.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

HotelWindow::HotelWindow() {
	HotelWindow::positionX = 0;
	HotelWindow::positionY = 0;
	HotelWindow::isOpen = false;
	HotelWindow::isEnemy = false;
	sprite.setPosition(sf::Vector2f(positionX, positionY));
	loadSprites();
}

HotelWindow::HotelWindow(float posX, float posY) {
	positionX = posX;
	positionY = posY;
	isOpen = getRandomNumber(2);
	isEnemy = getRandomNumber(2);
	sprite.setPosition(sf::Vector2f(positionX, positionY));
	loadSprites();
}

void HotelWindow::setWindowStatus() {
	if (isOpen) {
		isEnemy = getRandomNumber(2);
		int index = getRandomNumber(3);
		if (isEnemy) {
			sprite.setTexture(window_enemy[index]);
		}
		else {
			sprite.setTexture(window_people[index]);
		}
	}
	else {
		sprite.setTexture(windowClose);
	}
}

void HotelWindow::loadSprites() {
	windowClose.loadFromFile("res/images/window_closed.png");
	windowOpen.loadFromFile("res/images/window_open.png");
	window_people[0].loadFromFile("res/images/window_people1.png");
	window_people[1].loadFromFile("res/images/window_people2.png");
	window_people[2].loadFromFile("res/images/window_people3.png");
	window_enemy[0].loadFromFile("res/images/window_enemy1.png");
	window_enemy[1].loadFromFile("res/images/window_enemy2.png");
	window_enemy[2].loadFromFile("res/images/window_enemy3.png");
}

int HotelWindow::getRandomNumber(int max) {
	return(rand() % max);
}

void HotelWindow::resetWindow() {
	isEnemy = getRandomNumber(2);
	isOpen = getRandomNumber(2);
	setWindowStatus();
}
void HotelWindow::shot(int *points, int *lives) {
	if (isOpen) {
		sprite.setTexture(windowOpen);
		if (isEnemy) {
			*points += 100;
		}
		else {
			*points -= 1000;
			*lives -= 1;
		}
		isOpen = false;
	}

}
bool HotelWindow::getIsOpen() {
	return(isOpen);
}
Sprite HotelWindow::getSprite() {
	return(sprite);
}
void HotelWindow::closeWindow(int *points, int *lives) {
	if (isOpen) {
		if (isEnemy) {
			*lives -= 1;
		}
		else {
			*points += 100;
		}
	}
}

void HotelWindow::spriteCloseWindow() {
	sprite.setTexture(windowClose);
}
HotelWindow::~HotelWindow() {

}
