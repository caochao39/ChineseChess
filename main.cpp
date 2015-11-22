#include <iostream>
#include "ChineseChessGame.h"
int main()
{
  ChineseChessGame game;
     game.Start();
  /*  game.GenAllMove(1);
  std::cout << "total move " << std::endl;
  for(int i = 0; i < game.move_vc.size(); i++)
    {
      std::cout << "move " << i << ": " << "from: " << game.move_vc[i].from << " to " << game.move_vc[i].to << std::endl; 
      }*/
  Advisor advisor;
  General general;
  Bishop bishop;
  Horse horse;
  Rook rook;
  Cannon cannon;
  Pawn pawn;
  /*    for(int i = 0; i < 2; i++)
    {
      for(int j = 0; j < 3; j++)
	{
	  std::cout << static_cast<int>(pawn.pawn_dir_[i][j]) << " ";
	}
      std::cout << std::endl;
    }
  */
  //  game.TestMove(&pawn, 101);
}
