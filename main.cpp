#include <iostream>
#include "ChineseChessGame.h"
int main()
{
  ChineseChessGame game;
  //  game.Start();
  Advisor advisor;
  General general;
  Bishop bishop;
  Horse horse;
  Rook rook;
  Cannon cannon;
  Pawn pawn;
  game.TestMove(&pawn, 101);
}
