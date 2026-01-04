CXXFLAGS = -Wall -Wextra -Wpedantic -g -O3

all: TerrainGen

TerrainGen: mapgen.o perlin.o main.o
	g++ mapgen.o perlin.o main.o -o TerrainGen 

mapgen.o: Map_gen.cpp Map_gen.h
	g++ $(CXXFLAGS) -c Map_gen.cpp -o mapgen.o 

perlin.o: Perlin_Noise.cpp Perlin_Noise.h
	g++ $(CXXFLAGS) -c Perlin_Noise.cpp -o perlin.o 

main.o: main.cpp Map_gen.h Perlin_Noise.h
	g++ $(CXXFLAGS) -c main.cpp -o main.o 

clean:
	@rm -rf *.o TerrainGen