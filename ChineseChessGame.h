#ifndef CHINESECHESSGAME_H
#define CHINESECHESSGAME_H
#include <iostream>
#include "Board.h"
#include "Piece.h"
#include "Horse.h"
class ChineseChessGame
{
 public:
  //  Board board_;
  bool finished_;
  unsigned char side_;
  void start();
};

#endif
