
//tic-tac-toe game

#include<iostream>
using namespace std;

//function to draw tic-tac-toe board
void drawBoard(char board[3][3]){
    cout<<"-------------"<<endl;
    for(int i=0;i<3;i++){
        cout<<"| ";
        for(int j=0;j<3;j++){
            cout<<board[i][j]<<" | ";
        }
        cout<<"\n-------------\n";
    }
}
bool checkWin(char board[3][3],char player){
    for(int i=0;i<3;i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}
int main(){
    //initialize 3x3 tictactoe board
    char board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

    char player='X';
    int row,col;
    int turn;

    cout<<"\n\tWelcome to tic-tac-toe game!!!\n"<<endl;

    //game
    for(turn=0;turn<9;turn++){

        //draw board for tic-tac-toe
        drawBoard(board);

        while(true){
            cout<<"\nPlayer "<<player<<", enter (0-2) row and (0-2) column: ";
            cin>>row>>col;
            if(board[row][col]!=' '||row<0||col<0||row>3||col>3)
                cout<<"\n\tInvalid move. Try again"<<endl;
            else
                break;//valid input.exits loop
        }
        //make moves
        board[row][col]=player;

        //check win after each move
        if(checkWin(board,player)){
            drawBoard(board);
            cout<<"\n\tPlayer "<<player<<" wins!"<<endl;
            break;
        }
        //second player's turn
        player=(player=='X') ? 'O' : 'X';
    }

    //end of the game
    drawBoard(board);

    //checking for a draw game
    if(turn==9&&!checkWin(board,'X')&&checkWin(board,'O')){
        cout<<"\n\tIt's a draw!!!"<<endl;
    }
    return 0;
};
