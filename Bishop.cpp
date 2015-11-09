#include "Bishop.h"

void Bishop::GenMove(unsigned char cur_pos, unsigned char side, Board board)
{
  unsigned char next_move;
  unsigned char check_pos;
  int sideTag = side * 16 + 16;
  for(int i = 0; i < 4; i++)
    {
      next_move = cur_pos + bishop_dir_[i];
      if(in_board_[next_move])
        {
          check_pos = cur_pos + bishop_check_[i];
          if(board.board_[check_pos] != 0)
            {
              if(board.board_[next_move] & sideTag)
                {
                  SaveMove(cur_pos, next_move);
                }
            }
        }
    }

}
