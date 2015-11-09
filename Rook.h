#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class Rook : public Piece
{
 public:
  char rook_dir_[4] = {-0x01, -0x10, +0x01, +0x10};
  void GenMove(unsigned char cur_pos, unsigned char side, Board board);
};

#endif
