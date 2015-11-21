#include "Horse.h"
#include <iostream>



void Horse::GenMove(unsigned char cur_pos, unsigned char side, Board board)
{
  int sideTag = 16 * side + 16;
  short next_move;
  short check_pos;
  for(int i = 0; i < 8; i++)
    {
      //for each direction
      next_move = cur_pos + horse_dir_[i];
      if(in_board_[next_move])
        {
          check_pos = cur_pos + horse_check_[i];
          if(board.board_[check_pos] == 0)
            {
              //there is no piece on the horse leg
              if(!(board.board_[next_move] & sideTag))
                {
		                  //there is no piece with the same side at the next position
                  SaveMove(cur_pos, next_move);
		
                }
            }
        }
    }
}
