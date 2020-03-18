/*
 * Assign1_Agnes Liu_260713093.cpp
 *
 *  Created on: Feb. 14, 2020
 *      Author: agnes
 */




/*
 * //Comp322 Assignment 1 Agnes Liu 260713093
 *
 *  Created on: Feb. 13, 2020
 *      Author: agnes
 */

// i/o example

#include <iostream>
#include <algorithm>

using namespace std;

void greetAndInstruct()
{
	 char i;
	 cout << "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer." << endl;
	 cout << "The board is numbered from 1 to 27 as per the following:" << endl;
	 cout << "1 |2 |3     10|11|12     19|20|21" << endl;
	 cout << "-------     --------     --------" << endl;
	 cout << "4 |5 |6     13|14|15     22|23|24" << endl;
	 cout << "-------     --------     --------" << endl;
	 cout << "7 |8 |9     16|17|18     25|26|27" << endl;
	 cout << "-------     --------     --------" << endl;
	 cout << "Player starts first. Simply input the number of the cell you want to occupy. Player's move is marked with X. Computer's move is marked with O:" << endl;
	 cout << "Start? (y/n)" << endl;
	 cin >> i;
	 if (i=='n'){
		 cout << "Have a good day!" << endl;
		 exit(0);
		 return;
	 }
	 else if (i=='y'){
		 cout << "Let's game!" << endl;
		 return;
	 }
	 else{
		 cout << "invalid input" << endl;
		 return greetAndInstruct();
	 }

}

void displayBoard(char board[])
{
	char the_print[4][35] = {"1 |2 |3     10|11|12     19|20|21\n","4 |5 |6     13|14|15     22|23|24\n","7 |8 |9     16|17|18     25|26|27\n","-------     --------     --------\n"};
	char withST [27];
	bool non_emp = false;
	for (int i = 0;i<27;i++){
		if (board[i]=='X'){
			withST[i] ='X';
			non_emp = true;
		}
		else if (board[i]=='O'){
			withST[i] ='O';
			non_emp = true;
		}
		else{
			continue;
		}

	}
	if (non_emp==false){
		std::cout << the_print[0] << the_print[3] << the_print[1]<< the_print[3] << the_print[2] << the_print[3];
	}
	else{
		for (int i =0;i<9;i++){
			if ((withST[i]== 'X' or (withST[i]=='O'))and((i+1)%3==0)){
				//change the 6th of the string
				int row = (i+1)/3;
				the_print[row-1][6]=withST[i];//[6]=*withST[i];
			}
			else if ((withST[i]== 'X' or (withST[i]=='O'))and((i+1)%3==2)){
				int row = (i+1)/3;
				the_print[row][3]=withST[i];
			}
			else if ((withST[i]== 'X' or (withST[i]=='O'))and((i+1)%3==1)){
				int row = (i+1)/3;
				the_print[row][0]=withST[i];
			}
		}
		for (int i =9;i<18;i++){
			if ((withST[i]== 'X' or (withST[i]=='O'))and((i+1)%3==0)){
				//change the 6th of the string
				int row = (i+1)/3-3;
				the_print[row-1][18]=withST[i];//[6]=*withST[i];
				the_print[row-1][19]=' ';
			}
			else if ((withST[i]== 'X' or (withST[i]=='O'))and((i+1)%3==2)){
				int row = (i+1)/3-3;
				the_print[row][15]=withST[i];
				the_print[row][16]=' ';
			}
			else if ((withST[i]== 'X' or (withST[i]=='O'))and((i+1)%3==1)){
				int row = (i+1)/3-3;
				the_print[row][12]=withST[i];
				the_print[row][13]=' ';
			}
		}
		for (int i =18;i<27;i++){
			if ((withST[i]== 'X' or (withST[i]=='O'))and((i+1)%3==0)){
				//change the 6th of the string
				int row = (i+1)/3-6;
				the_print[row-1][31]=withST[i];//[6]=*withST[i];
				the_print[row-1][32]=' ';
			}
			else if ((withST[i]== 'X' or (withST[i]=='O'))and((i+1)%3==2)){
				int row = (i+1)/3-6;
				the_print[row][28]=withST[i];
				the_print[row][29]=' ';
			}
			else if ((withST[i]== 'X' or (withST[i]=='O'))and((i+1)%3==1)){
				int row = (i+1)/3-6;
				the_print[row][25]=withST[i];
				the_print[row][26]=' ';
			}
		}
		std::cout << the_print[0] << the_print[3] << the_print[1]<< the_print[3] << the_print[2] << the_print[3];
	}
}

bool isFull (char board[]){
	bool full = true;
	for (int i =0;i<27;i++){
		if (board[i]=='N'){
			full = false;
			break;
		}
		else{
			continue;
		}
	}
	return full;
}

bool checkIfLegal(int cellNbre, char board[]){
	bool full = isFull(board);
	if (full){
		return false;
	}
	if ((cellNbre<1)or(cellNbre>27)){
		int i;
		cout << "Illegal move: location does not exist.\nTry another spot:";
		cin >> i;
		return checkIfLegal(i,board);
	}
	else if ((board[cellNbre-1]=='X') or (board[cellNbre-1]=='O')){
		int i;
		cout << "Illegal move: location already occupied.\nTry another spot:";
		cin >> i;
		return checkIfLegal(i,board);
	}
	else{
		cout << "Legal move. Proceeding." << endl;
		return true;
	}
}

bool checkWinner(char board[]){
	/*consider: if 5 or 23 is occupied by 1 of the players, we only need to check the *
		within its own board
		added here the normal cases for 14*/
	for (int i = 4;i<23;i+=9){
		if (board[i]!='N'){
			char p = board[i];
			if ((board[i-4]==p and board[i+4]==p) or (board[i-2]==p and board[i+2]==p)or(board[i-3]==p and board[i+3]==p)or(board[i-1]==p and board[i+1]==p)){
				cout << "Winner: "<< p << endl;
				return true;
			}
		}
	}
	/*now I want to consider all the border winnings[2,4,6,8]
	* [11,13,15,17] [20,22,24,26]
	*/
	for (int i =2;i<21;i+=9){
		for (int j = i;j<i+7;j+=2){
			if ((j==i) or (j==i+6)){
				int ti = j-1;
				if (board[ti]!='N'){
					if (board[ti-1]==board[ti] and board[ti]==board[ti+1]){
						cout << "Winner: "<< board[ti] << endl;
						return true;
					}
				}
			}
			else if ((j==i+2) or (j==i+4)){
				int ti = j-1;
				if (board[ti]!='N'){
					if ((board[ti-3]==board[ti]) and (board[ti]==board[ti+3])){
						cout << "Winner: "<< board[ti] << endl;
						return true;
					}
				}
			}
		}
	}
	/*the complicated cases always involve 11,14, and 17. consider
	 * 11 and 17 first as they are the simplest
	 */
	for (int i =10;i<17;i+=6){
		if (board[i]!='N'){
			if (board[i-8]==board[i] and board[i]==board[i+8]){
				cout << "Winner: "<< board[i] << endl;
				return true;
			}
			else if (board[i-10]==board[i] and board[i]==board[i+10]){
				cout << "Winner: " << board[i] << endl;
				return true;
			}
		}
	}
//finally the 14: 1--27,7--21, 4--24,6--22, and same-cell-across-3 case
	//14 special:
	if (board[13]!='N'){
		if ((board[0]==board[13] and board[26]==board[13])or(board[6]==board[13] and board[20]==board[13])or(board[3]==board[13] and board[23]==board[13])or(board[5]==board[13] and board[21]==board[13])){
			cout << "Winner: "<<board[13] << endl;
			return true;
		}
	}
	//same cells
	for (int i =9;i<18;i++){
		if ((board[i-9]==board[i] and board[i]==board[i+9]) and(board[i]!='N')){
			cout << "Winner: " <<board[i] << endl;
			return true;
		}
	}
	for (int i=12;i<15;i++){
		if (board[i]!='N'){
			if ((board[i-12]==board[i]) and (board[i+12]==board[i])){
				cout << "Winner: " <<board[i] << endl;
				return true;
			}
		}
	}
	return false;
}

int checkMove(char p, char board[]){
		/*consider: if 5 or 23 is occupied by 1 of the players, we only need to check the *
		within its own board
		added here the normal cases for 14*/
	for (int i = 4;i<23;i+=9){
		if (board[i]=='N'){
			if ((board[i-4]==p and board[i+4]==p) or (board[i-2]==p and board[i+2]==p)or(board[i-3]==p and board[i+3]==p)or(board[i-1]==p and board[i+1]==p)){
				return i;
			}
		}
		else if (board[i]==p){
			if ((board[i-4]==p and board[i+4]=='N') or (board[i-2]==p and board[i+2]=='N')or(board[i-3]==p and board[i+3]=='N')or(board[i-1]==p and board[i+1]=='N')){
				if (board[i-4]==p and board[i+4]=='N'){
					return (i+4);
				}
				else if (board[i-2]==p and board[i+2]=='N'){
					return (i+2);
				}
				else if (board[i-3]==p and board[i+3]=='N'){
					return (i+3);
				}
				else{
					return (i+1);
				}
			}
			else if ((board[i-4]=='N' and board[i+4]==p) or (board[i-2]=='N' and board[i+2]==p)or(board[i-3]=='N' and board[i+3]==p)or(board[i-1]=='N' and board[i+1]==p)){
				if (board[i-4]=='N' and board[i+4]==p){
					return (i-4);
				}
				else if (board[i-2]=='N' and board[i+2]==p){
					return (i-2);
				}
				else if (board[i-3]=='N' and board[i+3]==p){
					return (i-3);
				}
				else{
					return (i-1);
				}
			}
		}
		else{
			continue;
		}
	}
	/*now I want to consider all the border winnings[2,4,6,8]
	* [11,13,15,17] [20,22,24,26]
	*/
	for (int i =2;i<21;i+=9){
		for (int j = i;j<i+7;j+=2){
			if ((j==i) or (j==i+6)){
				int ti = j-1;
				if (board[ti]=='N'){
					if (board[ti-1]==p and p==board[ti+1]){
						return ti;
					}
				}
				else if (board[ti]==p){
					if (board[ti-1]==p and 'N'==board[ti+1]){
						return (ti+1);
					}
					else if (board[ti-1]=='N' and p==board[ti+1]){
						return (ti-1);
					}
				}
			}
			else if ((j==i+2) or (j==i+4)){
				int ti = j-1;
				if (board[ti]=='N'){
					if ((board[ti-3]==p) and (p==board[ti+3])){
						return ti;
					}
				}
				else if (board[ti]==p){
					if (board[ti-3]==p and 'N'==board[ti+3]){
						return (ti+3);
					}
					else if (board[ti-3]=='N' and p==board[ti+3]){
						return (ti-3);
					}
				}
			}
			else{
				continue;
			}
		}
	}
	/*the complicated cases always involve 11,14, and 17. consider
	 * 11 and 17 first as they are the simplest
	 */
	for (int i =10;i<17;i+=6){
		if (board[i]=='N'){
			if (board[i-8]==p and p==board[i+8]){
				return i;
			}
			else if (board[i-10]==p and p==board[i+10]){
				return i;
			}
		}
		else if (board[i]==p){
			if (board[i-8]==p and 'N'==board[i+8]){
				return (i+8);
			}
			else if (board[i-10]==p and 'N'==board[i+10]){
				return (i+10);
			}
			else if (board[i-10]=='N' and p==board[i+10]){
				return (i-10);
			}
			else if (board[i-8]=='N' and p==board[i+8]){
				return (i-8);
			}
		}
		else {
			continue;
		}
	}
//finally the 14: 1--27,7--21, 4--24,6--22, and same-cell-across-3 case
	//14 special:
	if (board[13]=='N'){
		if ((board[0]==p and board[26]==p)or(board[6]==p and board[20]==p)or(board[3]==p and board[23]==p)or(board[5]==p and board[21]==p)){
			return 13;
		}
	}
	else if (board[13]==p){
		if ((board[0]==p and board[26]=='N')or(board[6]==p and board[20]=='N')or(board[3]==p and board[23]=='N')or(board[5]==p and board[21]=='N')){
			if (board[26]=='N'){
				return (26);
			}
			else if (board[20]=='N'){
				return (20);
			}
			else if (board[23]=='N'){
				return (23);
			}
			else{
				return (21);
			}
		}
		else if ((board[0]=='N' and board[26]==p)or(board[6]=='N' and board[20]==p)or(board[3]=='N' and board[23]==p)or(board[5]=='N' and board[21]==p)){
			if (board[5]=='N'){
				return (5);
			}
			else if (board[3]=='N'){
				return (3);
			}
			else if (board[6]=='N'){
				return (6);
			}
			else{
				return (0);
			}
		}
	}
	//same cells
	for (int i =9;i<18;i++){
		if ((board[i-9]==p and p==board[i+9]) and(board[i]!='N')){
			return i;
		}
		else if ((board[i-9]=='N' and p==board[i+9]) and(board[i]==p)){
			return (i-9);
		}
		else if((board[i-9]==p and 'N'==board[i+9]) and(board[i]==p)){
			return (i+9);
		}
		else{
			continue;
		}
	}
	return -1;
}
void computerMove(char board[]){
	int x = checkMove('O',board);
	//cout << x << endl;
	if (x!=-1){
		board[x]='O';
	}
	else{
		int y = checkMove('X', board);
		//cout << y << endl;
		if (y!=-1){
			board[y] = 'O';
		}
		else{
			int best[] = {13,10,16,12,14};
			for (int i =0;i<5;i++){
				if (board[best[i]]=='N'){
					board[best[i]]='O';
					break;
				}
				else{
					for (int i=0;i<27;i++){
						if (board[i]=='N'){
							board[i]='O';
							break;
						}
					}
				}
			}
		}
	}
}



