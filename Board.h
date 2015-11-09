#ifndef BOARD_H
#define BOARD_H

const int NOP = 0;//no piece on the position
const int PAWN = 1;
const int CONNON = 2;
const int CHARIOT = 3;
const int HORSE = 4;
const int MINISTER = 5;
const int ADVISER = 6;
const int GENERAL = 7;

const int P_VALUE[7] = //piece value
{
  1,//pawn before crossing the river 
  2,//pawn after crossing the river
  5,//cannon
  9,//chariot
  4,//horse
  2,//minister
  2//advisor
};

class Board
{ 
public:
  bool river_cross_[10]; 
  int board_[10][9] = {};
  int color_[10][9] = {}

  void Init();
};
#endif
