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
  /*  short from, to;
  while(1)
    {
      game.ShowBoard();
      std::cout << "from: " << " to: " << std::endl;
      std::cin >> from >> to;
      move mv;
      mv.from = from;
      mv.to = to;
      game.AIMovePiece(mv);
      game.ShowBoard();
      short tmp;
      std::cin >> tmp;
      game.AIUnMovePiece();
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
