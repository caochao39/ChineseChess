ChineseChessGame: main.o ChineseChessGame.o
	g++ main.o ChineseChessGame.o -o ChineseChessGame -std=c++11

main.o: main.cpp ChineseChessGame.h
	g++ -c main.cpp -std=c++11

ChineseChessGame.o: ChineseChessGame.cpp ChineseChessGame.h Board.o Piece.o Horse.o General.o Advisor.o Bishop.o Rook.o Pawn.o
	g++ -c ChineseChessGame.cpp -std=c++11

Board.o: Board.cpp Board.h
	g++ -c Board.cpp -std=c++11

Piece.o: Piece.cpp Piece.h Board.o
	g++ -c Piece.cpp -std=c++11

Horse.o: Horse.cpp Horse.h Piece.h
	g++ -c Horse.cpp -std=c++11

General.o: General.cpp General.h Piece.h
	g++ -c General.cpp -std=c++11

Advisor.o: Advisor.cpp Advisor.h Piece.h
	g++ -c Advisor.cpp -std=c++11

Bishop.o: Bishop.cpp Bishop.h Piece.h
	g++ -c Bishop.cpp -std=c++11

Rook.o: Rook.cpp Rook.h Piece.h
	g++ -c Rook.cpp -std=c++11

Cannon.o: Cannon.cpp Cannon.h Piece.h
	g++ -c Cannon.cpp -std=c++11

Pawn.o: Pawn.cpp Pawn.h Piece.h
	g++ -c Pawn.cpp -std=c++11

clean:
	rm *.o
