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
          if(CheckJiang(1-side_))
            {
              std::cout << "Jiang!!!" << std::endl;
            }
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
  int b_value = 0;//black
  int w_value = 0;//red
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
  // std::cout << "w value: " << w_value << std::endl;
  // std::cout << "b value: " << b_value << std::endl;
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
  MovePiece(piece_[piece], next_pos, side_);
  ShowBoard();

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
void ChineseChessGame::MovePiece(short from, short to, bool side)
{
  //  std::cout << "from: " << from << " to: " << to << std::endl;
  //  std::cout << (board_.board_[to] == 0) << " "<< board_.board_[to] <<   std::endl;
  int sideTag = side * 16 + 16;  
  if(board_.board_[to] == 0)
    {
      board_.board_[to] = board_.board_[from];
      piece_[board_.board_[from]] = to;
      board_.board_[from] = 0;
    }
  else if(!(sideTag & board_.board_[to]) )//if sideTag equal 1 then is self guy
    { 
      board_.board_[to] = board_.board_[from];
      piece_[board_.board_[from]] = to;
      piece_[board_.board_[to]] = 0;
      board_.board_[from] = 0;
    }
  else
    {
      std::cout << "You cannot shoot teamate!" << std::endl;
    }
}

bool ChineseChessGame::CheckJiang(bool side)
{
  short wGeneral, bGeneral;//position of the two generals on board
  bool jiang; // 1 for jiang otherwise 0
  int sideTag = 32 - side * 16;
  int op_side = 1 - side;//opponent
  wGeneral = piece_[16];
  bGeneral = piece_[32];

  if(!wGeneral || !bGeneral)
    {
      return 0;
    }
  //check if they can see each other
  jiang = 1;
  if(wGeneral % 16 == bGeneral % 16)
    {
      for(wGeneral = wGeneral - 16; wGeneral != bGeneral; wGeneral = wGeneral - 16)
        {
          if(board_.board_[wGeneral])
            {
              jiang = 0;
              break;
            }
        }
      if(jiang)
        {
          return jiang;
        }
    }
  
  short gen_pos = piece_[48 - sideTag];//position of general of this side
  
  //check if attacked by horse
  Horse horse;
  short piece_pos;
  short next_move;
  for(int i = 5; i <= 6; i++)//horse position
    {
      piece_pos = piece_[sideTag + i];
      if(!piece_pos)
        {
          continue;
        }
      for(int j = 0; j < 8; j++)//8 directions of horse
        {
          next_move = piece_pos + horse.horse_dir_[j];
          if(next_move != gen_pos)
            {
              continue;
            }
          //check if the position is legal
          if(legal_position_[op_side][next_move] & position_mask_[3])
            {
              short horse_check = piece_pos + horse.horse_check_[j];
              if(!board_.board_[horse_check])
                {
                  return 1;
                }
            }
        }
    }
  //check if attacked by rook
  jiang = 1;
  short pos_add;
  for(int i = 7; i <= 8; i++)
    {
      piece_pos = piece_[sideTag + i];
      if(!piece_pos)
        {
          continue;
        }
      if(piece_pos %16 == gen_pos %16)//at the same column
        {
          pos_add = (piece_pos > gen_pos ? -16 : 16);
          for(piece_pos = piece_pos + pos_add; piece_pos != gen_pos; piece_pos = piece_pos + pos_add)
            {
              if(board_.board_[piece_pos])
                {
                  jiang = 0;
                  break;
                }
            }
          if(jiang)
            {
              return jiang;
            }
        }
      else if(piece_pos / 16 == gen_pos / 16)
        {
          pos_add = (piece_pos > gen_pos ? -1 : 1);
          for(piece_pos = piece_pos + pos_add; piece_pos != gen_pos; piece_pos = piece_pos + pos_add)
            {
              if(board_.board_[piece_pos])
                {
                  jiang = 0;
                  break;
                }
            }
          if(jiang)
            {
              return jiang;
            }
          
        }
    }

  //check if attacked by cannon
  bool overFlag = 0;
  for(int i = 9; i <= 10; i++)
    {
      piece_pos = piece_[sideTag + i];
      if(!piece_pos)
        {
          continue;
        }
      if(piece_pos % 16 == gen_pos % 16)
        {
          pos_add = (piece_pos > gen_pos ? -16 : 16);
          for(piece_pos = piece_pos + pos_add; piece_pos != gen_pos; piece_pos = piece_pos + pos_add)
            {
              if(board_.board_[piece_pos])
                {
                  if(!overFlag)
                    {
                      overFlag = 1;
                    }
                  else
                    {
                      overFlag = 2;
                      break;
                    }
                }
            }
          if(overFlag == 1)
            {
              return 1;
            }
        }
      else if(piece_pos / 16 == gen_pos / 16)
        {
          pos_add = (piece_pos > gen_pos ? -1 : 1);
          for(piece_pos = piece_pos + pos_add; piece_pos != gen_pos; piece_pos = piece_pos + pos_add)
            {
              if(board_.board_[piece_pos])
                {
                  if(!overFlag)
                    {
                      overFlag = 1;
                    }
                  else
                    {
                      overFlag = 2;
                      break;
                    }
                }
            }
          if(overFlag == 1)
            {
              return 1;
            }
        }
    }

  //check if attacked by pawn
  Pawn pawn;
  for(int i = 11; i <= 15; i++)
    {
      piece_pos = piece_[sideTag + i];
      if(!piece_pos)
        {
          continue;
        }
      for(int j = 0; j < 3; j++)
        {
          next_move = piece_pos + pawn.pawn_dir_[op_side][j];
          if((next_move == gen_pos) && (legal_position_[op_side][next_move] & position_mask_[6]))
            {
              return 1;
            }
        
        }
    }
  return 0;
}
void ChineseChessGame::GenAllMove(int side)
{
  move_vc.clear();
	int sideTag;
  short piece_pos;
	sideTag = 16 + side * 16;
  short p;//piece
  for(int i = 0; i < 16; i++)
    {
      p = sideTag + i;
      piece_pos = piece_[p];//get piece position
      if(piece_pos == 0)
        {
          continue;
        }
      switch(i)
        {
        case 0: //general
          {
            General general;
            general.GenMove(piece_pos, side, board_);
            for(int i = 0; i < general.move_num_; i++)
              {
                move_vc.push_back(general.move_array_[i]);
              }
            break;
          }
        case 1://advisor
        case 2:
          {
            Advisor advisor;
            advisor.GenMove(piece_pos, side, board_);
            for(int i = 0; i < advisor.move_num_; i++)
              {
                move_vc.push_back(advisor.move_array_[i]);
              }
            break;
          }
        case 3://bishop
        case 4:
          {
            Bishop bishop;
            bishop.GenMove(piece_pos, side, board_);
            for(int i = 0; i < bishop.move_num_; i++)
              {
                move_vc.push_back(bishop.move_array_[i]);
              }
            break;
          }
        case 5://horse
        case 6:
          {
            Horse horse;
            CollectMove(&horse, piece_pos, side, board_);
            break;
          }
        case 7: //rook
        case 8:
          {
            Rook rook;
            CollectMove(&rook, piece_pos, side, board_);
            break;
          }
        case 9: //cannon
        case 10:
          {
            Cannon cannon;
            CollectMove(&cannon, piece_pos, side, board_);
            break;
          }
        case 11: //pawn
        case 12:
        case 13:
        case 14:
        case 15:
          {
            Pawn pawn;
            CollectMove(&pawn, piece_pos, side, board_);
            break;
          }
        }
    }
  
}
void ChineseChessGame::CollectMove(Piece * pie, unsigned char cur_pos, unsigned char side, Board board)
{
  pie->GenMove(cur_pos, side, board);
  for(int i = 0; i < pie->move_num_; i++)
    {
      move_vc.push_back(pie->move_array_[i]);
    }

  
}
