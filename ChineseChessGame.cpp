#include "ChineseChessGame.h"
#include <iomanip> 
ChineseChessGame::ChineseChessGame(){
  MaxDepth = 5;
  stack_top_ = 0;
}
void ChineseChessGame::ShowBoard()
{
  //  board_x
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
void ChineseChessGame::ShowUI()
{
    char col_num = 'a';
  std::cout << std::setw(2) << "" << " ";
    for(int j = board_.col_start_; j < board_.col_end_; j++)
      {
	//	std::cout << std::setw(2) << << " ";
	std::cout << col_num << "\t";
	col_num++;
      }
    std::cout << std::endl;
  int row_num = 0;
  for(int i = board_.row_start_; i < board_.row_end_; i++)
    {
      
      std::cout << std::setw(2) << row_num << " ";
      row_num++;
      for(int j = board_.col_start_; j < board_.col_end_; j++)
	{
	  short piece_pos = (i << 4) + j;
	  std::string appear;
	  switch(board_.board_[piece_pos])
	    {
	    case 0:
	      appear = ".";
	      break;
	    case 16:
	      appear = "帅";
	      break;
	    case 32:
	      appear = "將";
	      break;
	    case 17:
	    case 18:
	      appear = "士";
	      break;
	    case 33:
	    case 34:
	      appear = "仕";
	      break;
	    case 19:
	    case 20:
	      appear = "象";
	      break;
	    case 35:
	    case 36:
	      appear = "相";
	      break;
	    case 21:
	    case 22:
	      appear = "傌";
	      break;
	    case 37:
	    case 38:
	      appear = "馬";
	      break;
	    case 23:
	    case 24:
	      appear = "俥";
	      break;
	    case 39:
	    case 40:
	      appear = "車";
	      break;
	    case 41:
	    case 42:
	      appear = "砲";
	      break;
	    case 25:
	    case 26:
	      appear = "炮";
	      break;
	    case 27:
	    case 28:
	    case 29:
	    case 30:
	    case 31:
	      appear = "兵";
	      break;
	    case 43:
	    case 44:
	    case 45:
	    case 46:
	    case 47:
	      appear = "卒";
	      break;
	    }
	  std::cout << appear << "\t";
	}
      std::cout << std::endl;
    }

}
void ChineseChessGame::Start()
{
  //initialize board
  //ShowBoard();
  ShowUI();
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
	  /*GenAllMove(side_);
	    for(int i = 0; i < move_vc.size(); i++)
	    {
	    std::cout << "from: " << move_vc[i].from << " to: " << move_vc[i].to << std::endl;
	    }
	  */
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
  AlphaBetaSearch(MaxDepth, -1000000, 1000000);
  std::cout << "ai move from " << cur_best_move_.from << " to: " << cur_best_move_.to << std::endl;
  AIMovePiece(cur_best_move_);
  //  ShowBoard();
  ShowUI();
}
int ChineseChessGame::AlphaBetaSearch(int depth, int alpha, int beta)
{
  int value;
  move move_array[1280];
  move mv;
  int move_num;
  if(depth == 0)
    {
      return Evaluation();
    }
  GenAllMove(side_);
  for(int i = 0; i < move_vc.size(); i++)
    {
      move_array[i] = move_vc[i];
    }
  move_num = move_vc.size();
  /* for(int i = 0; i < move_vc.size(); i++)
     {
     std::cout << "from: " << move_vc[i].from << " to: " << move_vc[i].to << std::endl;
     }*/
  for(int i = 0; i < move_num; i++)
    {
      mv = move_array[i];
      AIMovePiece(move_array[i]);
      if(CheckJiang(side_))
	{
	  AIUnMovePiece();
	  continue;
	}
      value = -AlphaBetaSearch(depth - 1, -beta, -alpha);
      AIUnMovePiece();
      if(value >= beta)
	{
	  return beta;
	}
      if(value > alpha)
	{
	  alpha = value;
	  if(depth == MaxDepth)
	    {
	      std::cout << "update best move from " << mv.from << " to " << mv.to << std::endl;
	      cur_best_move_ = mv;
	    }
	}
      
    }
  return alpha;
	
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
  /*  for(int i = board_.row_start_; i < board_.row_end_; i++ )
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
  */
  for(int i = 16; i < 32; i++)
    {
      if(piece_[i] > 0)
	{
	  w_value = w_value + piece_value_[ToSubscript(i)];
	}
    }
  for(int i = 32; i < 48; i++)
    {
      if(piece_[i] > 0)
	{
	  b_value = b_value + piece_value_[ToSubscript(i)];
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


void getPlayerChoice(short &piece, short &move)
{
  short piece_row;
  char piece_col;
  short move_row;
  char move_col;
  std::cout << "Please choose a piece specified in row and column numbers (eg. e3)" << std::endl;
  std::cin >> piece_row >> piece_col;
  std::cout << "Please choose a destination specified in row and column numbers (eg. e3)" << std::endl;
  std::cin >> move_row >> move_col;
  short piece_pos = (piece_row ) * 16 + (piece_col - 'a') + 51 ;
  short move_pos = (move_row ) * 16 + (move_col - 'a') + 51;
  piece = piece_pos;
  move = move_pos;
  // std::cout << "piece position " << piece_pos << std::endl;
  //  std::cout << "move position " << move_pos << std::endl;
}

void ChineseChessGame::PlayerMove()
{
  short piece;
  short piece_pos;
  short next_pos;
  /*  std::cout << "Please choose a piece" << std::endl;
  std::cin >> piece;
  std::cout << "Please choose a move" << std::endl;
  std::cin >> next_pos;
  */
  piece = 0;
  while(piece == 0)
    {
      getPlayerChoice(piece_pos, next_pos);
      piece = board_.board_[piece_pos];
      if(piece == 0)
	{
	  std::cout << "There is no piece there!" << std::endl;
	}
      else
	{
	  break;
	}
    }
  MovePiece(piece_[piece], next_pos, side_);
  //  ShowBoard();
  ShowUI();

}
void ChineseChessGame::AIMovePiece(move & mv){

  move_stack_[stack_top_].from = mv.from;
  move_stack_[stack_top_].to = mv.to;
  move_stack_[stack_top_].eaten = board_.board_[mv.to];
  stack_top_ ++;

  if(board_.board_[mv.to] != 0)
    {
      piece_[board_.board_[mv.to]] = 0;
    }
  board_.board_[mv.to] = board_.board_[mv.from];
  piece_[board_.board_[mv.from]] = mv.to;
  board_.board_[mv.from] = 0;
}
void ChineseChessGame::AIUnMovePiece()
{
  stack_top_ --;
  short from = move_stack_[stack_top_].from;
  short to = move_stack_[stack_top_].to;
  short eaten = move_stack_[stack_top_].eaten;

  board_.board_[from] = board_.board_[to];
  piece_[board_.board_[from]] = from;
  board_.board_[to] = eaten;
  if(eaten != 0)
    {
      piece_[eaten] = to;
    }
  
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
      piece_[board_.board_[to]] = 0;
      board_.board_[to] = board_.board_[from];
      piece_[board_.board_[from]] = to;
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
