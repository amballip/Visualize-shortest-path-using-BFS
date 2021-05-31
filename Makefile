
# $@ replaced by name of the target
# $< replaced by name of the first prerequisite
# $^ replaced by name of all prerequisites
# -E Preprocess only; do not compile, assemble or link.
# -S Compile only; do not assemble or link.
# -c Compile and assemble, but do not link.

cc:=g++
ccflags:=-O3 -Wall -std=c++17 #-fsanitize=address
target:=main
obj:= ./obj/main.o ./obj/BFS.o ./obj/color.o ./obj/DFS.o ./obj/random_generators.o ./obj/rectangle.o ./obj/delay.o ./obj/debug.o

all:$(target)


$(target):$(obj)
	$(cc) $(ccflags) $^ -o $@  -lsfml-graphics -lsfml-window -lsfml-system 

./obj/%.o: ./src/%.cpp
	$(cc) $(ccflags) -c $< -o $@

./src/header.h.gch: ./src/header.h
	$(cc) $(ccflags) -o $@  $<

clean:
	rm -f ./obj/*.o $(target) ./src/*.gch




