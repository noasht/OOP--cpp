/* Assignment: 1 Question number 1
Author: Noa Shem Tov   */

#include "TicTacToe.h"
using namespace std;

TicTacToe::TicTacToe()//default constructor
{
    board = CreateGameBoard();//function that creat board and initialization every checker to empty and return the address
    turn = PLAYER_X;//the default, X start first
    game_over = false;//chang only in case of wining or draw
}//TicTacToe
char ** TicTacToe::CreateGameBoard()const//initialization the board with space in each checker
{
   char ** tempOfBoard = new char *[SIZE_OF_BOARD];//dynamic memory allocation, first rows then column
    for(int i = ZERO; i < SIZE_OF_BOARD; ++i)
        tempOfBoard[i] = new char [SIZE_OF_BOARD];
    for(int i = ZERO; i < SIZE_OF_BOARD; ++i)
        for (int j = ZERO; j < SIZE_OF_BOARD; ++j)
            tempOfBoard[i][j] = SPACE;//initialization the board to space which is mark for empty
    return tempOfBoard;//return the address of the board
}//CreateGameBoard
TicTacToe::TicTacToe(const char &turn)//constructor by parameter
{
    board = CreateGameBoard();//function that creat board and initialization every checker to empty and return the address
    InitializationTurn(turn);//constructor with the choice of users who starts first it must be X or O else, it will be X
    game_over = false;//chang only in case of wining or draw
}//TicTacToe
void TicTacToe::InitializationTurn(const char &turnX)//initialization the turn it can be only X or O
{
    if(turnX != PLAYER_O && turnX != O_SMALL)
        this-> turn = PLAYER_X;//if the input wasn't O or correct
    else
        this-> turn = PLAYER_O;
}//InitializationTurn
TicTacToe::TicTacToe(const TicTacToe &GameX)//copy constructor because of the dynamic memory allocation
{
    this->board = CreateGameBoard();//function that creat board and initialization every checker to empty and return the address
    for (int i = ZERO; i < SIZE_OF_BOARD; ++i)
        for (int j = ZERO; j < SIZE_OF_BOARD; ++j)
            this->board[i][j] = GameX.board[i][j];//copy the data from one board to another
    this->turn = GameX.turn;//copy the data of who need to play
    this->game_over = GameX.game_over;//if the game over or not in a game that is copied
}//TicTacToe
TicTacToe::~TicTacToe()//destructor
{
    for(int i = ZERO; i < SIZE_OF_BOARD; ++i)
        delete [] board[i];//delete the rows
    delete [] board;//delete the board
}//~TicTacToe
void TicTacToe::step(int &row,int &col)//mark X or O in coordinates that the current player has selected
{
    while(!LegalCoordinates(row,col));//until the coordinates will be valid, this function also set the board
}//step
bool TicTacToe::LegalCoordinates(int &row,int &col)//check if the coordinates are legal
{
    cout<<"Player "<<this->turn<<", please type 2 coordinate between 1 to 3"<<endl;
    cin>>row>>col;//input of the coordinates
    return (LegalLocation(row,col));//check if the coordinates are valid tha place has to be empty and in the range between 1 and 3
}//LegalCoordinates
bool TicTacToe::LegalLocation(const int &row,const int &col)//check if the coordinates between 1 and 3
{
    //check if the input is valid
    if(row >= ONE)
        if(row <= THREE)
            if(col >= ONE)
                if(col <= THREE)
                    return availablePlace(row,col);//the input is valid now need to check if the place is empty and not chosen yet
    return false;//if the coordinates are not between 1 and 3, the user need to type again coordinates
}//LegalLocation
bool TicTacToe::availablePlace(const int &row,const int &col)//check if the coordinates is empty place and there is no X or O then set the board
{
    if(this->board[row - ONE][col - ONE] == SPACE)//if the place not chosen yet
    {
        this->board[row - ONE][col - ONE] = this->turn;//set the board
        return true;//the input was valid
    }
    return false;//the place been selected, the user need to type another coordinates
}//availablePlace
state TicTacToe::game_state(const int &row,const int &col) const//check the board after every step
{
    if(ThereIsThreeMarks(row,col))//if there is 3 same marks in diagonal or the same row/col
    {
        if(this->turn == PLAYER_O)//check who won the game
            return O_WIN;
        return X_WIN;
    }
    if (CheckersFull())//when no one won and the board is full which means draw
        return DRAW;
    return NOT_FINISHED;//no one of the last option means that should be another round
}//game_state
bool TicTacToe::ThereIsThreeMarks(const int &row,const int &col)const//check if someone won
{
    //there is a winner when tha same mark showed in the same row/column or one of the two diagonal
    if(ThreeMarksInColumn(col) || ThreeMarksInRow(row) || ThreeMarksInDiagonal(row,col))
        return true;
    return false;
}//ThereIsThreeMarks
bool TicTacToe::ThreeMarksInColumn(const int &col)const//check if the col that been selected by the player has the same marks
{
    for (int i = ZERO; i < SIZE_OF_BOARD; ++i)
        if(board[i][col - ONE] != this->turn)//there is no sequence of the same mark in column
            return false;
    return true;
}//ThreeMarksInColumn
bool TicTacToe::ThreeMarksInRow(const int &row)const//check if the row that been selected by the player has the same marks
{
    for (int i = ZERO; i < SIZE_OF_BOARD; ++i)
        if(board[row - ONE][i] != this->turn)//there is no sequence of the same mark in row
            return false;
    return true;
}//ThreeMarksInRow
bool TicTacToe::ThreeMarksInDiagonal(const int &row,const int &col)const//check if the diagonals have the same marks
{
    if(row == col)
        return RightDiagonal(row);//check the right diagonal
    if(row + col == FOUR)
        return LeftDiagonal();//check the left diagonal
    return false;//is not a cell from diagonal (2,1) || (1,2) || (3,2) || (2,3)
}//ThreeMarksInDiagonal
bool TicTacToe::RightDiagonal(const int &row)const//check the right diagonal (1,1) (2,2) etc.
{
    for (int i = ZERO; i < SIZE_OF_BOARD; ++i)
       if(board[i][i] != this->turn)
       {
           if (row == TWO)//if this is the center checker on the board it can be on the another diagonal too
               return LeftDiagonal();
           return false;
       }
    return true;
}//RightDiagonal
bool TicTacToe::LeftDiagonal()const//check the left diagonal in the another side
{
    for (int i = ZERO; i < SIZE_OF_BOARD; ++i)
        if(board[i][TWO - i] != this->turn)//there is no sequence of the same mark in row
            return false;
    return true;
}//LeftDiagonal
bool TicTacToe::CheckersFull()const//if the board is full without winning
{
    for (int i = ZERO; i < SIZE_OF_BOARD ; ++i)
        for (int j = ZERO; j < SIZE_OF_BOARD; ++j)
            if(board[i][j] == SPACE)//if there is checker empty the board not full, and it's not a draw
                return false;
    return true;
}//CheckersFull
void TicTacToe::print()const//print the board
{
    cout<<"       |       |       "<<endl;
    cout<<"   "<<board[ZERO][ZERO]<<"   |   "<<board[ZERO][ONE]<<"   |   "<<board[ZERO][TWO]<<endl;
    cout<<"_______|_______|_______"<<endl;
    cout<<"       |       |       "<<endl;
    cout<<"   "<<board[ONE][ZERO]<<"   |   "<<board[ONE][ONE]<<"   |   "<<board[ONE][TWO]<<endl;
    cout<<"_______|_______|_______"<<endl;
    cout<<"       |       |       "<<endl;
    cout<<"   "<<board[TWO][ZERO]<<"   |   "<<board[TWO][ONE]<<"   |   "<<board[TWO][TWO]<<endl;
    cout<<"       |       |       "<<endl;
}//print
void TicTacToe::play()//the function that manage the game the only function that public except for the constructor's function
{
    int row,col;//the 2 coordinates the curren player tyoe
    cout<<endl<<"Welcome to Tic-tac-toe"<<endl;
    do
    {
        step(row,col);//the function that set the board by the step of the players
        print();//print the updated board
        switch (game_state(row,col))//game_stat return the stat of the game can be: win/draw/not finished yet
        {
            case X_WIN:
                cout<<"The game ended with victory"<<endl<<" well done player X"<<endl;
                game_over = true;//the game is over
                break;
            case O_WIN:
                cout<<"The game ended with victory"<<endl<<" well done player O"<<endl;
                game_over = true;//the game is over
                break;
            case DRAW:
                cout<<"The game ended in a draw, successfully next time"<<endl;
                game_over = true;//the game is over
                break;
            default:
                if(this->turn == PLAYER_X)//switch between the players and now the second player need to type coordinates
                    this->turn = PLAYER_O;
                else
                    this->turn = PLAYER_X;
        }
    }while(!game_over);//while the game is not over
}//play