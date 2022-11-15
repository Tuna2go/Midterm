compile: main.cpp 
	 g++ main.cpp -o a


run: a
	 ./a


clean: a
	 rm a