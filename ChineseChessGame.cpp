#include "ChineseChessGame.h"
ChineseChessGame::ChineseChessGame(){}
void ChineseChessGame::ShowBoard()
{
  //  board_
  short piece_pos;
	for(int i = 3; i < 13; i++)
	{
		for(int j = 3; j < 12; j++)
			{
        piece_pos = (i << 4) + j;
        std::cout << board_.board_[piece_pos] << "\t";
        
			}
			std::cout << std::endl;
  }
  std::cout << std::endl;
	for(int i = 3; i < 13; i++)
	{
		for(int j = 3; j < 12; j++)
			{
        piece_pos = (i << 4) + j;
        std::cout << piece_pos << "\t";
        
			}
			std::cout << std::endl;
  }
}
void ChineseChessGame::Start()
{
	//initialize board
	ShowBoard();
  side_ = 0;
  //  while(!CheckEnd())
    while(!IsEnd())
    {
      if(side_ == 0)
        {
	  std::cout << "evaluation: "<< Evaluation() << std::endl; 
          PlayerMove();
          side_ = 1;
        }
      else
        {
          AIMove();
          side_ = 0;
        }

    }
  

}

bool ChineseChessGame::IsEnd()
{
  return 0;
}
void ChineseChessGame::AIMove()
{
  
}
int ChineseChessGame::ToSubscript(short p)
{
  if(p < 16 && p >= 48)
    {
      return 7;
    }
  if(p >= 32)
    {
      p = p - 16;
    }
  switch(p)
    {
    case 16: return 0;
    case 17:
    case 18: return 1;
    case 19:
    case 20: return 2;
    case 21:
    case 22: return 3;
    case 23:
    case 24: return 4;
    case 25:
    case 26: return 5;
    case 27:
    case 28:
    case 29:
    case 30:
    case 31: return 6;
    default: return 7;
    }
    
}
int ChineseChessGame::Evaluation()
{
  int b_value;//black
  int w_value;//red
  short piece_pos;
  for(int i = board_.row_start_; i < board_.row_end_; i++ )
    {
      for(int j = board_.col_start_; j < board_.col_end_; j++)
	{
	  piece_pos = (i << 4) + j;
	  if(board_.board_[piece_pos] == 0)//no piece
	    {
	      continue;
	    }
	  else if(board_.board_[piece_pos] < 32)//user
	    {
	      w_value = w_value + piece_value_[ToSubscript(board_.board_[piece_pos])];
	    }
	  else//AI
	    {
	      b_value = b_value + piece_value_[ToSubscript(board_.board_[piece_pos])];
	    }
	}
    }
  return w_value - b_value;
}
void ChineseChessGame::TestMove(Piece *piece, short pos)
{
  piece->GenMove(pos, 1, board_);
  for(int i = 0; i < piece->move_num_; i++)
    {
      std::cout << piece->move_array_[i].from << " " << piece->move_array_[i].to << std::endl;
    }
  std::cout << piece->move_num_ << std::endl;
}


void ChineseChessGame::PlayerMove()
{
  short piece;
  short piece_pos;
  short next_pos;
  std::cout << "Please choose a piece" << std::endl;
  std::cin >> piece;
  std::cout << "Please choose a move" << std::endl;
  std::cin >> next_pos;
  for(int i = 0; i < 13; i++)
    {
      for(int j = 0; j < 12; j++)
        {
          piece_pos = (i << 4) + j;
          if(board_.board_[piece_pos] == piece)
            {
              MovePiece(piece_pos, next_pos, side_);
              ShowBoard();
            }
        }
    }
}
void ChineseChessGame::AIMovePiece(move & mv){
      short tmp = board_.board_[mv.from];
      board_.board_[mv.from] = board_.board_[mv.to];
      board_.board_[mv.to] = tmp;
}
void ChineseChessGame::AIUnMovePiece(move & mv)
{
      short tmp = board_.board_[mv.to];
      board_.board_[mv.to] = board_.board_[mv.from];
      board_.board_[mv.from] = tmp;
}
void ChineseChessGame::MovePiece(unsigned char from, unsigned char to, bool side)
{
  int sideTag = side * 16 + 16;  
  if(!(sideTag & board_.board_[to]))//if sideTag equal 1 then is self guy
    {
      //TODO: check legal move
      unsigned char tmp = board_.board_[from];
      board_.board_[from] = board_.board_[to];
      board_.board_[to] = tmp;
    }
  else
    {
      std::cout << "You cannot shoot teamate!" << std::endl;
    }
}
void ChineseChessGame::GenAllMove(int side)
{
	int sideTag;
  short piece_pos;
	sideTag = 16 + side * 16;
	for(int i = 3; i < 13; i++)// 10 row
	{
		for(int j = 3; j < 12; j++)// 9 column
		{
			piece_pos = (i << 4) + j;
			if(!board_.board_[piece_pos] & sideTag)//other side
			{
				continue;
			}
      /*	switch(board_[piece_pos] - sideTag)
			{
				case 0: //general
				case 1: //advisor
				case 2: 
        }*/
		}
	}
}
