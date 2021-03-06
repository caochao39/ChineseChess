#include "Advisor.h"
#include <iostream>

void Advisor::GenMove(unsigned char cur_pos, unsigned char side, Board board)
{
  unsigned char next_move;
  int sideTag = side * 16 + 16;

  for(int i = 0; i < 4; i++)
    {
      next_move = cur_pos + advisor_dir_[i];
      if(in_board_[next_move])
        {
          if(!(board.board_[next_move] & sideTag))
            {
	      //	      std::cout << "i: "<< i << std::endl;
              SaveMove(cur_pos, next_move);
            }
        }
    }
}
