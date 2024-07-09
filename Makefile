build:
	gcc -Wall -Werror -Wextra -pedantic ./src/*.c -lm -o the_maze `sdl2-config --cflags` `sdl2-config --libs`;

run:
	./the_maze;

clean:
	rm the_maze;
