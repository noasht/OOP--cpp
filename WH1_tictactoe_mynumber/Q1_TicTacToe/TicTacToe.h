/* Assignment: 1 Question number 1
Author: Noa Shem Tov   */

#ifndef HW1_TICTACTOE_H
#define HW1_TICTACTOE_H

#include <iostream>

#define SIZE_OF_BOARD 3 //the size of the game board
#define SPACE ' ' //mark for empty place in the board
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define O_SMALL 'o'
#define ONE 1
#define TWO 2
#define FOUR 4
#define THREE 3
#define ZERO 0

enum state {X_WIN, O_WIN, DRAW, NOT_FINISHED};//the status of the game

class TicTacToe {

private:

    char** board;//the board of the game
    char turn;//which player play right now
    bool game_over;//initialization to false turn to ture when someone win or the game ended with draw

    //functions
    void step(int &row,int &col);//mark X or O in coordinates that the current player has selected
    state game_state(const int &row,const int &col)const;//check the board after every step
    void print()const;//print the board
    char ** CreateGameBoard()const;//initialization the board with space in each checker
    void InitializationTurn(const char &turnX);//initialization the turn it can be only X or O
    bool LegalCoordinates(int &row,int &col);//check if the coordinates are legal
    bool LegalLocation(const int &row,const int &col);//check if the coordinates between 1 and 3
    bool availablePlace(const int &row,const int &col);//check if the coordinates is empty place and there is no X or O then set the board
    bool ThereIsThreeMarks(const int &row,const int &col)const;//check if someone won
    bool CheckersFull()const;//if the board is full without winning
    bool ThreeMarksInColumn(const int &col)const;//check if the col that been selected by the player has the same marks
    bool ThreeMarksInRow(const int &row)const;//check if the row that been selected by the player has the same marks
    bool ThreeMarksInDiagonal(const int &row,const int &col)const;//check if the diagonals have the same marks
    bool RightDiagonal(const int &row)const;//check the right diagonal (1,1) (2,2) etc.
    bool LeftDiagonal()const;//check the left diagonal in the another side

public:
    TicTacToe();//default constructor
    TicTacToe(const char &turn);//constructor by parameter
    TicTacToe(const TicTacToe &GameX);//copy constructor because of the dynamic memory allocation
    ~TicTacToe();//destructor
    void play();//the function that manage the game the only function that public except for the constructor's function
};

#endif //HW1_TICTACTOE_H
