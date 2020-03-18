/*
 * blackjack.h
 *
 *  Created on: Feb. 22, 2020
 *      Author: Agnes Liu
 */

#ifndef blackjack_hpp
#define blackjack_hpp

#include<iostream>
#include<algorithm>
#include<cstdlib>
#include <ctime>
#include<vector>
#include<string>
#include<stack>
#include <list>
#include <stdio.h>
#include <random>
#include <chrono>
#include <cstdlib>
using namespace std;

class Card{
public:
	enum Rank {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK=10, QUEEN=10, KING=10};
	enum Type {CLUBS, DIAMONDS, HEARTS, SPADES};
	Card(Rank r, Type t){
		cRank = r;
		cType = t;
	}
	int getValue();
	void displayCard();

private:
	Rank cRank;
	Type cType;
};

class Hand{
public:
	Hand();
	vector<Card*> hand;
	void add(Card* c);
	void clear();
	int getTotal(bool player);
};

class Deck:Hand{
public:
	Deck();
	vector<Card*> deck;
	void populate();
	void shuffle();
	void deal(Hand* h);
};

class AbstractPlayer{
public:
	virtual bool isDrawing (Hand h) = 0;
	virtual ~AbstractPlayer(void){};
	bool isBusted (Hand h);
};

class HumanPlayer:public AbstractPlayer{
public:
	HumanPlayer();
	~HumanPlayer(void){};
	bool isDrawing (Hand h) override;
	void announce(Hand p, Hand c);
};

class ComputerPlayer:public AbstractPlayer{
public:
	ComputerPlayer();
	~ComputerPlayer(void){};
	bool isDrawing(Hand h) override;
};

class BlackJackGame{
public:
	Deck d;
	ComputerPlayer casino;
	BlackJackGame();
	~BlackJackGame(void){};
	void play();
};

#endif /* blackjack_hpp */
