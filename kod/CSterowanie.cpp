#include "CSterowanie.h"

CSterowanie::CSterowanie() {
	up = false;
	down = false;
	left = false;
	right = false;
	shootUp = false;
	shootDown = false;
	shootLeft = false;
	shootRight = false;
	space = false;
	enter = false;
	esc = false;
};

void CSterowanie::sczytajPrzyciski() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		up = true;
	}
	else {
		up = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		down = true;
	}
	else {
		down = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		right = true;
	}
	else {
		right = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		left = true;
	}
	else {
		left = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		shootUp = true;
	}
	else {
		shootUp = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		shootDown = true;
	}
	else {
		shootDown = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		shootRight = true;
	}
	else {
		shootRight = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		shootLeft = true;
	}
	else {
		shootLeft = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		space = true;
	}
	else {
		space = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		enter = true;
	}
	else {
		enter = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
		esc = true;
	}
	else {
		esc = false;
	}
}