#include "Piece.h"

void Piece::InitMove()
{
  move_num_ = 0;
}

void Piece::SaveMove(unsigned char  from, unsigned char to)
{
  move_array_[move_num_].from = from;
  move_array_[move_num_].to = to;
  move_num_ ++;
}
