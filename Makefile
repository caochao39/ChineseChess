ChineseChessGame: main.o ChineseChessGame.o
	g++ main.o ChineseChessGame.o -o ChineseChessGame

main.o: main.cpp ChineseChessGame.h
	g++ -c main.cpp

ChineseChessGame.o: ChineseChessGame.cpp ChineseChessGame.h
	g++ -c ChineseChessGame.cpp

clean:
	rm *.o
