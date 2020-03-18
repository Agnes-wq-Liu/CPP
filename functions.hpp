//Comp 322 Assignment 1 Agnes Liu 260713093
#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>

void greetAndInstruct();
void displayBoard(char board[]);
bool checkIfLegal(int cellNbre, char board[]);
bool checkWinner (char board[]);
void computerMove(char board[]);
bool isFull(char board[]);
#endif
