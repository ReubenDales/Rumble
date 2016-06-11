/*
*	menu.h
*	Rumble
*
*	Created by: Reuben Dales, Lance Donnell, Lance Harris, Josh Prow.
*	Dated: 12 November 2015
*
*/

#pragma once
#include "SFML/Graphics.hpp"

#define Max_Num 3
class Menu
{
public:
	Menu(float width, float hieght);
	~Menu();

	void draw(sf::RenderWindow &window);
	void Move();
	void selectOption(int &state,  sf::RenderWindow &window);

	int selectedItemIndex;
private :
	
	sf::Font font;
	sf::Text menu[Max_Num];

	sf::Text newGame;
	sf::Text Exit;
};

