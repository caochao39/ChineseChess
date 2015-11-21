#include "Pawn.h"

void Pawn::GenMove(unsigned char cur_pos, unsigned char side, Board board)
{
  unsigned char next_move;
  int sideTag = side * 16 + 16;
  for(int i = 0; i < 3; i++)
    {
      next_move = cur_pos + pawn_dir_[side][i];
      if(in_board_[side][next_move])
        {
          if(!(board.board_[next_move] & sideTag))
            {
              SaveMove(cur_pos, next_move);
            }
        }
    }
}
