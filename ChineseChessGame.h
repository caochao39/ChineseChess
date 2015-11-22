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
#include <vector>
class ChineseChessGame
{
 public:
 	Board board_;
 	bool finished_;
	const short piece_value_[8] = {1000, 20, 20, 40, 90, 45, 10, 0};//general, advisor, bishop, horse, rook, cannon
  bool side_;//0 for user 1 for AI
  short piece_[48] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    199, 198, 200, 197, 201, 196, 202, 195, 203, 164, 170, 147, 149, 151, 153, 155,
    55, 54, 56, 53, 57, 52, 58, 51, 59, 84, 90, 99, 101, 103, 105, 107
  };
  std::vector<move> move_vc;

  ChineseChessGame();//constructor
  void Start();
  void GenAllMove(int side);
  void ShowBoard();
  void PlayerMove();
  void MovePiece(unsigned char from, unsigned char to, bool side);
  void AIMove();
  int Evaluation();
  int ToSubscript(short p);
  void AIMovePiece(move & mv);
  void AIUnMovePiece(move & mv);
  void TestMove(Piece *piece, short pos);
  bool IsEnd();
  move AlphaBetaSearch();
  bool CheckJiang(bool side);
  void CollectMove(Piece * pie, unsigned char cur_pos, unsigned char side,  Board board);
};
#endif

