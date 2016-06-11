/*
*	Player.cpp
*	Rumble
*
*	Created by: Reuben Dales, Lance Donnell, Lance Harris, Josh Prow.
*	Dated: 25 October 2015
*
*/

#include "Character.h"

Player::Player(int &health, float &speed, int &stamina, int choice, sf::Texture playerTexture) : Character(health, speed, stamina)
{
	this->texture = playerTexture;

	spriteXPos = 0;
	spriteYPos = 0;
	SPRITEWIDTH = 16;
	SPRITEHEIGHT = 16;
	SPRITEMAX = 4;
	SPRITEGAP = 1;

	//base stats
	attack = 2;

	//potions
	healthPotionNumber = 1; //to test
	staminaPotionNumber = 0;

	//vitamins
	strengthVitaminNumber = 0;
	healthVitaminNumber = 0;
	staminaVitaminNumber = 0;

	//gold
	goldStash = 0;
	choice = 1;
	score = 0;

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(SPRITEGAP,SPRITEGAP,SPRITEWIDTH,SPRITEHEIGHT));
	sprite.setScale(1.5, 1.5);
	facing = RIGHT;
}

void Player::processDirectionalKeyPresses(Map &map, int &iterations)
{	
	//RIGHT
	if(((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))))
	{
		setFacing(Character::RIGHT);
		walk(map,iterations);
	}
	//LEFT
	else if(((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))))
	{
		setFacing(Character::LEFT);
		walk(map,iterations);
	}
	//UP
	else if(((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))))
	{
		setFacing(Character::UP);
		walk(map,iterations);
	}
	//DOWN
	else if(((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))))
	{
		setFacing(Character::DOWN);
		walk(map,iterations);
	}
}

//determines vector aiming and allows player to shoot projectiles where the mouse is (limited to 4 directions)
void Player::processMouseAiming(sf::Vector2f mPos)
{
	sf::Vector2f pPos = sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y);

	//works out the degrees of the vector between the player position and the mouse position
	float degrees = atan2f(mPos.y - pPos.y, mPos.x - pPos.x) * 180 / 3.14159 /* PI */;
	//std::cout<< "Degrees: " << degrees <<std::endl;

	if(degrees <= 140 && degrees > 35)
	{
		turn(2); //DOWN
	}
	if(degrees <= -40 && degrees > -140)
	{
		turn(0);//UP
	}
	if(degrees > -40 && degrees <= 35)
	{
		turn(1);//RIGHT
	}
	if(degrees <= -140 || degrees > 140)
	{
		turn(3);//LEFT
	}	
}

int Player::getGoldStash()
{
	return goldStash;
}

void Player::setGoldStash(int amount)
{
	this->goldStash = amount;
}

void Player::increaseGoldStash(int newGold)
{
	goldStash += newGold;
}

void Player::decreaseGoldStash(int value)
{
	goldStash -= value;
}

bool Player::useStrengthVitamin()
{
	if(strengthVitaminNumber > 0)
	{
		attack += 1;
		removeStrengthVitamin();
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::useHealthVitamin()
{
	if(healthVitaminNumber > 0)
	{
		health += 10;
		removeHealthVitamin();
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::useStaminaVitamin()
{
	if(staminaVitaminNumber > 0)
	{
		stamina += 10;
		removeStaminaVitamin();
		return true;
	}
	else
	{
		return false;
	}
}

//Potion methods
int Player::getHealthPotionNumber()
{
	return healthPotionNumber;
}

void Player::setHealthPotionNumber(int amount)
{
	this->healthPotionNumber = amount;
}

int Player::getStaminaPotionNumber()
{
	return staminaPotionNumber;
}

void Player::removeHealthPotion()
{
	healthPotionNumber-=1;
}

void Player::removeStaminaPotion()
{
	staminaPotionNumber-=1;
}

void Player::giveStaminaPotion()
{
	staminaPotionNumber+=1;
}

void Player::giveHealthPotion()
{
	healthPotionNumber+=1;
}

void Player::giveStrengthVitamin()
{
	strengthVitaminNumber+=1;
}

void Player::giveHealthVitamin()
{
	healthVitaminNumber+=1;
}
	
void Player::giveStaminaVitamin()
{
	staminaVitaminNumber+=1;
}

void Player::removeStrengthVitamin()
{
	strengthVitaminNumber-=1;
}

void Player::removeHealthVitamin()
{
	healthVitaminNumber-=1;
}
	
void Player::removeStaminaVitamin()
{
	staminaVitaminNumber-=1;
}

int Player::getStrengthVitaminNumber()
{
	return strengthVitaminNumber;
}

int Player::getStaminaVitaminNumber()
{
	return staminaVitaminNumber;
}

int Player::getHealthVitaminNumber()
{
	return healthVitaminNumber;
}

void Player::setSprite(int choice)
{
	if(choice==0)
	{
		spriteXPos = 0;
		spriteXPosMax = 3;
		spriteXPosMin = 0;
	}
	else if(choice==1)
	{
		spriteXPos = 7; //121 / 7 = 17. which is the width of sprite + gap
		spriteXPosMax = 9;
		spriteXPosMin = 7;
	}
	//1,1,17,17 
	this->sprite.setTextureRect(sf::IntRect((spriteXPos * SPRITEWIDTH) + (SPRITEGAP * spriteXPos)+SPRITEGAP, (spriteYPos * SPRITEWIDTH) + (SPRITEGAP * spriteYPos)+SPRITEGAP, SPRITEWIDTH, SPRITEHEIGHT));
}

int Player::getChoice()
{
	return choice;
}

void Player::setChoice(int choice)
{
	this->choice = choice;
}

void Player::fullHealth(int health)
{
	this->health = health;
}

int Player::getScore()
{
	return score;
}

void Player::setScore(int score)
{
	this->score = score;
}

void Player::increaseScore(int amount)
{
	this->score += amount;
}

Player::~Player()
{
}