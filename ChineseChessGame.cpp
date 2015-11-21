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
