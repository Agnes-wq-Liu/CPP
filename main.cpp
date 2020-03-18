//Comp322 Assignment 1 Agnes Liu 260713093
#include <iostream>
#include <algorithm>
#include "functions.hpp"
using namespace std;
int main (){
	greetAndInstruct();
	char board [27];
	for (int i = 0;i<27;i++){
		board[i] = 'N';
	}
	bool full = isFull(board);
	while (!full){
		bool w = checkWinner(board);
		if (!w){
			displayBoard(board);
			cout << "Please enter the pos index you'd like to occupy: " << endl;
			int i;
			cin >> i;
			bool x = checkIfLegal(i,board);
			if (x){
				board[i-1]='X';
				w = checkWinner(board);
				if (!w){
					if (!isFull(board)){
						computerMove(board);
					}
					else{
						cout << "It's a tie!" << endl;
						break;
					}
				}
				else{
					displayBoard(board);
					cout << "end of the game." << endl;
					break;
				}
			}
		}
		else{
			displayBoard(board);
			cout << "end of the game." << endl;
			break;
		}
	}

}
