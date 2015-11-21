#include <iostream>
#include "ChineseChessGame.h"
int main()
{
  ChineseChessGame game;
    game.Start();
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
