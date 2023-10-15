#include <iostream>

using namespace std;

const int BOARD_SIZE=3;

// Function to draw the Tic-Tac-Toe board
void drawBoard(char board[BOARD_SIZE][BOARD_SIZE]){
    cout<<"-------------"<<endl;
    for (int i=0; i<BOARD_SIZE;++i){
        cout<<"| ";
        for (int j=0; j<BOARD_SIZE;++j) {
            cout<<board[i][j]<<" | ";
        }
        cout<<endl;
        cout<<"-------------"<<endl;
    }
}
// Function to check if a player has won
bool checkWin(char board[BOARD_SIZE][BOARD_SIZE], char player){
    // Check rows and columns
    for (int i=0; i<BOARD_SIZE;++i){
        if (board[i][0]==player && board[i][1]==player && board[i][2]==player)
            return true;
        if (board[0][i]==player && board[1][i]==player && board[2][i]==player)
            return true;
    }
    // Check diagonals
    if (board[0][0]==player && board[1][1]==player && board[2][2]==player)
        return true;
    if (board[0][2]==player && board[1][1]==player && board[2][0]==player)
        return true;

    return false;
}

// Function to check if the board is full (tie)
bool checkTie(char board[BOARD_SIZE][BOARD_SIZE]){
    for (int i=0; i<BOARD_SIZE;++i){
        for (int j=0; j<BOARD_SIZE;++j){
            if (board[i][j]==' ')
                return false;
        }
    }
    return true;
}

// Function to make a move
void makeMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char player){
    board[row][col]=player;
}

int main(){
    
	char playAgain;
    // Initialize the board with empty cells
    do{
		char board[BOARD_SIZE][BOARD_SIZE]; // Initialize an empty 3x3 board
    cout<<"Tic-Tac-Toe Game!"<<endl;
	char currentPlayer='X';
		int row, col;
	    for (int i=0; i<BOARD_SIZE;++i) {
	        for (int j=0; j<BOARD_SIZE;++j) {
	            board[i][j]=' ';
	        }
	    }
		int move;
	    while (true) {
	    	
	        drawBoard(board);
			cin.clear();
	        // Get the current player's move
	        cout<<"Player "<<currentPlayer<<", enter your move 1-9: ";
	        cin >>move;
			
			switch(move){
				case 1:
					row=2;col=0;break;
				case 2:
					row=2;col=1;break;
				case 3:
					row=2;col=2;break;
				case 4:
					row=1;col=0;break;
				case 5:
					row=1;col=1;break;
				case 6:
					row=1;col=2;break;
				case 7:
					row=0;col=0;break;
				case 8:
					row=0;col=1;break;
				case 9:
					row=0;col=2;break;
			}
	        // Check if the move is valid
	        if (row<0 || row >= BOARD_SIZE || col<0 || col >= BOARD_SIZE || board[row][col] != ' ') {
	            system("CLS");
				cout<<"Invalid move! Try again."<<endl;
	            continue;
	        }
	        // Make the move
	        makeMove(board, row, col, currentPlayer);
	        // Check if the current player has won
	        bool a=checkWin(board, currentPlayer);
	        if (a) {
	        	system("CLS");
	        	drawBoard(board);
	            cout<<"Player "<<currentPlayer<<" wins!"<<endl;
	            cout<<"Do You Want To Play Again? Y/N"<<endl;
	            
	            cin>>playAgain;
	            if(playAgain=='y'||playAgain=='Y'){
					for (int i=0; i<BOARD_SIZE;++i) {
				        for (int j=0; j<BOARD_SIZE;++j) {
				            board[i][j]=' ';
				        }
				    }
				}
	            else if(playAgain=='n'||playAgain=='N')
	            	break;
	        }
	
	        // Check for a tie
	        if (checkTie(board)) {
	        	system("CLS");
	        	drawBoard(board);
	            cout<<"It's a tie!"<<endl;
	            cout<<"Do You Want To Play Again? Y/N"<<endl;
	            cin>>playAgain;
	            if(playAgain=='y'||playAgain=='Y'){
					for (int i=0; i<BOARD_SIZE;++i) {
				        for (int j=0; j<BOARD_SIZE;++j) {
				            board[i][j]=' ';
				        }
				    }
				}
	            else if(playAgain=='n'||playAgain=='N')
	            	break;
	        }
	
	        // Switch to the other player
	        
	        currentPlayer=(currentPlayer=='X') ? 'O' : 'X';
			system("CLS");
			cout<<"Game Ongoing! "<<endl;
	    }
	
	}while(playAgain=='Y'||playAgain=='y');
}