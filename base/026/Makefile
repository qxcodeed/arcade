run: student

extra = main.cpp

% : %.cpp
	g++ -Wall $@.cpp $(extra) -o $@.out
	tk run $@.out Readme.md
	rm -f $@.out
