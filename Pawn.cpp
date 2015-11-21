#include "Pawn.h"
#include <iostream>
void Pawn::GenMove(unsigned char cur_pos, unsigned char side, Board board)
{
  char pawn_dir_tmp[2][8] = {//0 for red 1 for black
    {-0x01, +0x01, -0x10, 0,  0, 0, 0, 0},
    {-0x01, +0x01, +0x10, 0, 0, 0, 0, 0}};
  short next_move;
  int sideTag = side * 16 + 16;
  for(int i = 0; i < 2; i++)
    {
      for(int j = 0; j < 3; j++)
	{
	  std::cout << static_cast<int>(pawn_dir_[i][j]) << " ";
	}
      std::cout << std::endl;
    }
  for(int i = 0; i < 3; i++)
    {
      next_move = cur_pos + pawn_dir_tmp[side][i];
      if(in_board_[side][next_move])
        {
          if(!(board.board_[next_move] & sideTag))
            {
              SaveMove(cur_pos, next_move);
            }
        }
    }
}
