#ifndef CHINESECHESSGAME_H
#define CHINESECHESSGAME_H
#include <iostream>
#include "Board.h"
#include "Piece.h"
#include "Horse.h"
#include "Bishop.h"
#include "Advisor.h"
#include "Rook.h"
#include "Pawn.h"
class ChineseChessGame
{
 public:
 	Board board_;
 	bool finished_;
  unsigned char side_;
  ChineseChessGame();//constructor
  void Start();
  void GenAllMove(int side);
  void ShowBoard();
  void PlayerMove();
  void MovePiece(unsigned char from, unsigned char to, bool side);
};
#endif
