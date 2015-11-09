#ifndef CANNON_H
#define CANNON_H
#include "Piece.h"
class Cannon : public Piece
{
 public: 
  char cannon_dir_[4] = {-0x01, +0x01, -0x10, +0x10};
  void GenMove(unsigned char cur_pos, unsigned char side, Board board); 
};
#endif
