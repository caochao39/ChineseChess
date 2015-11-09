ChineseChessGame: main.o ChineseChessGame.o
	g++ main.o ChineseChessGame.o -o ChineseChessGame -std=c++11

main.o: main.cpp ChineseChessGame.h
	g++ -c main.cpp -std=c++11

ChineseChessGame.o: ChineseChessGame.cpp ChineseChessGame.h Board.o
	g++ -c ChineseChessGame.cpp -std=c++11

Board.o: Board.cpp Board.h
	g++ -c Board.cpp -std=c++11

clean:
	rm *.o
