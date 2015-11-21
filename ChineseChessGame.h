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
#include "General.h"
#include "Cannon.h"
class ChineseChessGame
{
 public:
 	Board board_;
 	bool finished_;
  bool side_;//0 for user 1 for AI

  ChineseChessGame();//constructor
  void Start();
  void GenAllMove(int side);
  void ShowBoard();
  void PlayerMove();
  void MovePiece(unsigned char from, unsigned char to, bool side);
  void AIMove();
  void TestMove(Piece *piece, short pos);
  bool IsEnd();
  move AlphaBetaSearch();
};
#endif
