generate solve transform: generate.o solve.o transform.o sudoku.o
	g++ -o generate generate.o sudoku.o
	g++ -o solve solve.o sudoku.o
	g++ -o transform transform.o sudoku.o

generate.o: generate.cpp
	g++ -c generate.cpp

solve.o: solve.cpp
	g++ -c solve.cpp

transform.o: transform.cpp
	g++ -c transform.cpp

sudoku.o: sudoku.cpp sudoku.h
	g++ -c sudoku.cpp

clean:
	rm generate solve transform *.o
