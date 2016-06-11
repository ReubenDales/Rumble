/*
*	Character.h
*	Rumble
*
*	Created by: Reuben Dales, Lance Donnell, Lance Harris, Josh Prow.
*	Dated: 25 October 2015
*
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"

const int FRAMES = 4;

class Character
{
public:
	enum Facing
	{
		UP,
		RIGHT,
		DOWN,
		LEFT
	};

	bool rowBoundary();
	bool columnBoundary();

	int getColumn();
	int getRow();

	enum Aiming
	{
		UPAIM,
		RIGHTAIM,
		DOWNAIM,
		LEFTAIM
	};

	void setHealth(int health);
	void setSpeed(float speed);
	void setAttack(int attack);
	void setToughness(int toughness);
	void setStamina(int &stamina);

	int getHealth();
	float getSpeed();
	int getAttack();
	int getToughness();
	int getStamina();
	sf::Vector2f getPosition();

	void walk(Map &map, int &iterations);
	void knockback(Map &map, int &iterations, int Direction);

	sf::Sprite getSprite();
	void setFacing(Facing facing);
	void turn(int direction);
	void setPosition(int row, int column);
	bool takeDamage(int damage);

	void setSprite(sf::Sprite sprite);

	int getFacing();

	void setDead(int choice);

	Character(int health, float speed, int stamina);
	~Character();

protected:
	Facing facing;
	Aiming aiming;

	int health;
	float speed;
	int attack;
	int toughness;
	int stamina;
	int frame;
		
	int spriteXPos, spriteXPosMax, spriteXPosMin;
	int spriteYPos;

	int SPRITEWIDTH;
	int SPRITEHEIGHT;
	int SPRITEMAX;
	int SPRITEGAP;

	static const int left[FRAMES];
	static const int right[FRAMES];
	static const int down[FRAMES];
	static const int up[FRAMES];

	sf::Sprite sprite;
	sf::Texture texture;
};


class Player: public Character{
public:
	Player(int &health, float &speed, int &stamina, int choice, sf::Texture playerTexture);
	~Player();

	void processDirectionalKeyPresses(Map &map, int &iterations);
	void processMouseAiming(sf::Vector2f mPos);
	void setSprite(int choice);
	int getChoice();
	void setChoice(int choice);
	void fullHealth(int health);

	//Potion stuff//
	int getHealthPotionNumber();
	void setHealthPotionNumber(int amount);
	int getStaminaPotionNumber();
	void removeHealthPotion();
	void removeStaminaPotion();
	void giveStaminaPotion();
	void giveHealthPotion();

	//Vitamin stuff//
	int getStrengthVitaminNumber();
	int getStaminaVitaminNumber();
	int getHealthVitaminNumber();
	void removeStrengthVitamin();
	void removeHealthVitamin();
	void removeStaminaVitamin();
	void giveStrengthVitamin();
	void giveHealthVitamin();
	void giveStaminaVitamin();

	bool useStrengthVitamin();
	bool useHealthVitamin();
	bool useStaminaVitamin();

	//GOLD STASH STUFF
	int getGoldStash();
	void setGoldStash(int amount);
	void increaseGoldStash(int newGold);
	void decreaseGoldStash(int value);

	//PLAYER SCORE
	int getScore();
	void setScore(int score);
	void increaseScore(int amount);

protected:
	int strengthVitaminNumber;
	int healthVitaminNumber;
	int staminaVitaminNumber;
	int healthPotionNumber;
	int staminaPotionNumber;
	int choice;
	int goldStash;
	int score;
};

class Enemy: public Character{
public:
	enum Type
	{
		ZOMBIE,
		BOSS
	};
	Enemy(int health, float speed, int attack, Type type, sf::Vector2f location, sf::Texture enemyTexture);
	~Enemy();
	bool calcMovement(Player target, Map &map, int &iterations);
	int getFHealth();
	int attackTimer;
	Type type;

protected:
	int fullHealth;
	float moveColumn;
	float moveRow;
};