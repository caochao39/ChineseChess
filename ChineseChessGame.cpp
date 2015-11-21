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
  //  while(!CheckEnd())
  while(1)
    {
      PlayerMove();
      //      ShowBoard();
    }

}

void ChineseChessGame::PlayerMove()
{
  short piece;
  short piece_pos;
  short next_pos;
  bool side = 0;
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
              //              std::cout << "piece: " << piece << std::endl;
              MovePiece(piece_pos, next_pos, side);
              ShowBoard();
            }
        }
    }
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
