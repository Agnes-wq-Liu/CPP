/*
 * blackjack.cpp
 *
 *  Created on: Feb. 22, 2020
 *      Author: Agnes Liu 260713093
 */
#include "blackjack.h"
using namespace std;
int Card::getValue(){
	if ((int)cRank ==11 or (int)cRank==12 or (int)cRank ==13){
		return 10;
	}
	else{
		return (int) cRank;
	}
};
void Card::displayCard(){
	char sec;
        if ((int)cType==0){
                sec = 'C';
        }else if((int) cType==1){
                sec = 'D';
        }else if ((int) cType ==2){
                sec = 'H';
        }else if((int)cType ==3){
                sec = 'S';
        }
	char first;
	if ((int)cRank<11){
		cout << (int) cRank << sec << ' ';
	}else{
		if (cRank==11){
			first = 'J';
		}	
		else if (cRank==12){
			first = 'Q';
		}
		else if (cRank==13){
			first = 'K';
		}
	cout << first << sec << ' ';
	}
};

Hand::Hand(){};

void Hand::add(Card* card){
	hand.push_back(card);
};
void Hand::clear(){
	hand.clear();
};
int Hand::getTotal(bool player){
	int total = 0;
	int Acnt = 0;
	for (auto i : hand){
		if (i->getValue()==1 and player==true){
			Acnt++;
			if ((total+1==21) or (total+11==21)){
				//get 21 pts
				total = 21;
			}else if(total+11<21){
				//maximize the count
				total+=11;
			}else if (total+11>21){
				//prevent busting
				total+=1;
			}
			continue;
		}
		else{
			total = total+i->getValue();
			continue;
		}
	}
	return total;
};

Deck::Deck(){};

void Deck::populate(){
	for (int i = 1;i<14;i++){
		for (char j = 0;j<4;j++){
			Card::Rank r = static_cast<Card::Rank>(i);
			Card::Type t = static_cast<Card::Type>(j);
			Card* now = new Card(r,t);
			deck.push_back(now);
		}
	}
};
void Deck::shuffle(){
	for (int i =0;i<3;i++){
	//default shuffle times = 3;
	vector<bool> aval (52,true);
	//create boolean vector for available size 52;
		while(any_of(std::begin(aval), std::end(aval),[](bool x) {return (x==true);})){
			int rv1 = rand()%52;
			int rv2 = rand()%52;
			//generate 2 distinct random numbers
			//that store true in ava-array; swap their cards;
			iter_swap(deck.begin()+rv1,deck.begin()+rv2);
			//update available array by setting modified pos false;
			aval[rv1] =false;
			aval[rv2] = false;
		}
	}
};

void Deck::deal(Hand* h){
	Card* c = deck.front();
	h->add(c);
	//update deck
	deck.erase(deck.begin());
};
bool AbstractPlayer::isBusted(Hand h){
    int t = h.getTotal(false);
    if (t > 21){
        return true;
    }
    return false;
};

HumanPlayer::HumanPlayer(){};

bool HumanPlayer::isDrawing (Hand h){
	cout << "Do you want to draw? (y/n): ";
	char c = ' ';
	cin >> c;
	if (c=='y'){
		return true;
	}
	return false;
};


void HumanPlayer::announce(Hand p, Hand c){
    int pt = p.getTotal(true);
    int ct = c.getTotal(false);

    if (pt == ct){
        cout << "Push: no winner." << endl;
        return;
    }
    else if (pt > 21){
    	cout << "Player busts." << endl;
		cout << "Casino wins." << endl;
    }
    else if(ct > 21){
    	cout << "Casino busts." << endl;
		cout << "Player wins." << endl;
    }
    else if(pt == 21 or ct == 21){
    	if (pt==21){
    		cout << "Player wins." << endl;
    		return;
    	}else{
    		cout << "Casino wins." << endl;
    	}
    }else if (pt < ct){
        cout << "Casino wins." << endl;
    }else{
        cout << "Player wins." << endl;
    }

};

ComputerPlayer::ComputerPlayer(){};

bool ComputerPlayer::isDrawing(Hand h){
    int t = h.getTotal(false);
    if (t <= 16){
        return true;
    }
    return false;
};


BlackJackGame::BlackJackGame(){};

void BlackJackGame::play(){
    HumanPlayer player;
    d.populate();
    d.shuffle();
    //deal each player with open cards
    Hand p;
    d.deal(&p);
    d.deal(&p);
    Hand c;
    d.deal(&c);

    // display their cards
    cout << "Casino: ";
    for (auto i : c.hand){
        i->displayCard();
    }
    cout << "[" << c.getTotal(false) << "]" << endl;

    cout << "Player: ";
    for (auto i:p.hand){
        i->displayCard();
    }
    cout << "[" << p.getTotal(true) << "]" << endl;
    bool drawing = player.isDrawing(p);;

    while (drawing == true and p.getTotal(true) < 21){
        d.deal(&p);

        cout << "Player: ";
        for (auto i : p.hand){
            i->displayCard();
        }
        cout << "[" << p.getTotal(true) << "]" << endl;
        if (p.getTotal(true) >= 21){break;}
        drawing = player.isDrawing(p);

    }

    if (p.getTotal(true) >= 21){
    	player.announce(p, c);
        return;
    }
    bool comp_draw = casino.isDrawing(c);
    while(comp_draw == true and c.getTotal(false) < 16){
        d.deal(&c);

        cout << "Casino: ";
        for (auto i : c.hand){
            i->displayCard();
        }
        cout << "[" << c.getTotal(false) << "]" << endl;

        if (c.getTotal(false) >= 16){break;}

        comp_draw = casino.isDrawing(c);
    }

    player.announce(p, c);
    c.clear();
    p.clear();
};

