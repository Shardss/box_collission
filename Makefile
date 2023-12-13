all:
	g++ -I include -L lib -o helloworld helloworld.cpp -lmingw32 -lSDL2main -lSDL2 -llibSDL2_image

	