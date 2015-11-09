ChineseChessGame: main.o ChineseChessGame.o
	g++ main.o ChineseChessGame.o -o ChineseChessGame

main.o: main.cpp ChineseChessGame.h
	g++ -c main.cpp

ChineseChessGame.o: ChineseChessGame.cpp ChineseChessGame.h Board.o
	g++ -c ChineseChessGame.cpp

Board.o: Board.cpp Board.h
	g++ -c Board.cpp

clean:
	rm *o ChineseChessGame
