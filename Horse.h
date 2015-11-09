#ifndef HORSE_H
#define HORSE_H
#include "Piece.h"
class Horse : public Piece
{
 public:

   char horse_dir_[8] = {+0x0e, -0x12, -0x21, -0x1f, -0x0e, +0x12, +0x1f, +0x21};
   char horse_check_[8] = {-0x01, -0x01, -0x10, -0x10, +0x01, +0x01, +0x10, +0x10};
  void GenMove(unsigned char cur_pos, unsigned char side, Board board);
  
};
#endif
