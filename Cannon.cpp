#include "Cannon.h"

void Cannon::GenMove(unsigned char cur_pos, unsigned char side, Board board)
{
  unsigned char next_move;
  int sideTag = side * 16 + 16;
  int overFlag;
  for(int i = 0; i < 4; i++)
    {
      overFlag = 0;
      for(int j = 1; j <= 10; j++)
        {
          next_move = cur_pos + cannon_dir_[i] * j;
          if(board.in_board_[next_move] == 0)
            {
              break;
            }
          else if(board.board_[next_move] == 0)
            {
              if(!overFlag)
                {
                  SaveMove(cur_pos, next_move);
                }
            }
          else
            {
              if(!overFlag)
                {
                  overFlag = 1;
                }
              else
                {
                  if(!(board.board_[next_move] & sideTag))
                    {
                      SaveMove(cur_pos, next_move);
                    }
                  break;
                }
            }

        }
    }
}
