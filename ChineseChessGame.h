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
  short legal_position_[2][256] = {{
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
      0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
      0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
      0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
      0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
      0, 0, 0, 9, 1,25, 1, 9, 1,25, 1, 9, 0, 0, 0, 0,
      0, 0, 0, 9, 1, 9, 1, 9, 1, 9, 1, 9, 0, 0, 0, 0,
      0, 0, 0,17, 1, 1, 7,19, 7, 1, 1,17, 0, 0, 0, 0,
      0, 0, 0, 1, 1, 1, 3, 7, 3, 1, 1, 1, 0, 0, 0, 0, 
      0, 0, 0, 1, 1,17, 7, 3, 7,17, 1, 1, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
},{
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 1, 1,17, 7, 3, 7,17, 1, 1, 0, 0, 0, 0,
      0, 0, 0, 1, 1, 1, 3, 7, 3, 1, 1, 1, 0, 0, 0, 0,
      0, 0, 0,17, 1, 1, 7,19, 7, 1, 1,17, 0, 0, 0, 0,
      0, 0, 0, 9, 1, 9, 1, 9, 1, 9, 1, 9, 0, 0, 0, 0,
      0, 0, 0, 9, 1,25, 1, 9, 1,25, 1, 9, 0, 0, 0, 0,
      0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 
      0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
      0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
      0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
      0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
}};
  short position_mask_[7] = {2, 4, 16, 1, 1, 1, 8};// general, advisor, bishop, rook, horse, cannon, pawn
  move move_stack_[128];
  move cur_best_move_;
  int stack_top_ = 0;
  int MaxDepth = 5;
  ChineseChessGame();//constructor
  void Start();
  void GenAllMove(int side);
  void ShowBoard();
  void ShowUI();
  void PlayerMove();
  void MovePiece(short from, short to, bool side);
  void AIMove();
  int Evaluation();
  int ToSubscript(short p);
  void AIMovePiece(move & mv);
  void AIUnMovePiece();
  void TestMove(Piece *piece, short pos);
  bool IsEnd();
  int AlphaBetaSearch(int depth, int alpha, int beta);
  bool CheckJiang(bool side);
  void CollectMove(Piece * pie, unsigned char cur_pos, unsigned char side,  Board board);
};
#endif

