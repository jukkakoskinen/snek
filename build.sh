mkdir -p bin
cc -std=c99 -O3 -I./lib/raylib/include -I./src -framework Cocoa -framework IOKit src/*.c ./lib/raylib/lib/libraylib.a -o bin/snek
