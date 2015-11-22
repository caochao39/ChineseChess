#include "Rook.h"

void Rook::GenMove(unsigned char cur_pos, unsigned char side, Board board)
{
  unsigned char next_move;
  int sideTag = side * 16 + 16;
  for(int i = 0; i < 4; i++)
    {
      for(int j = 1; j <= 9; j++)
        {
          next_move = cur_pos + j * rook_dir_[i];
          if(!board.in_board_[next_move])
            {
              break;
            }
          if(board.board_[next_move] == 0)
            {
              SaveMove(cur_pos, next_move);
            }
          else if(board.board_[next_move] & sideTag)
            {
              break;
            }
          else
            {
              SaveMove(cur_pos, next_move);
              break;
            }
        }

    }
}
