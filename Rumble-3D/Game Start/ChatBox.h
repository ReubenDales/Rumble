/*
*	Character.h
*	Rumble
*
*	Created by: Reuben Dales, Lance Donnell, Lance Harris, Josh Prow.
*	Dated: 25 October 2015
*
*/

#pragma once

#include <string.h>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class ChatBox
{
private:
	sf::RectangleShape textBox;
	sf::Font font;
	sf::Text text;
	sf::Text textSpaceMessage;
	float renderWindowX;
	float renderWindowY;
	float width;
	float height;
	int lineLimit;
	int pageLimit;
	string message;
	string messageLine;
	bool redraw;
	int numOfBoxes;
	int start;
	int boxesDone;
	bool next;

public:
	ChatBox(int winX, int winY);
	~ChatBox(void);
	void displayMessage(sf::RenderWindow &window);
	void setTextSettings(string fontTtf, int size, sf::Color Colour);
	void SetCharaterLineLimit(int limit);
	void setMessage(string message, sf::RenderWindow &window);
	void redrawChat(bool status);
	void setPageLineLimit(int Limit);
	void setNext(bool choice);
	void displayConstantMessage(sf::RenderWindow &window);
	bool getRedraw();
};

