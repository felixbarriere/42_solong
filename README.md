# 42_solong

This projects goal is to create your own 2D game where you have a map that can have different dimensions and contents.

## Requirements to run the game
Only tested on macOS Catalina (Version 10.15.7).
To run it on Linux, you will find a [tutorial](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#compilation-on-linux) and the [minilibx](https://github.com/42Paris/minilibx-linux)to add to the project.

## Map
A valid map is structured as followed:

- 1 player (P)
- at least 1 exit (E)
- at least 1 collectible (C)`
- is recatangular
- has a solid outside border out of walls (1)
- all the empty spaces are filled with 0
- map has to be .ber
- no other characters than: P, E C 1 0

## During the game
- The player can only be moved by WASD.
- The player can not move into walls.
- The player can only exit if all collectibles are collected.
- The amount of movements is counted and displayed in the terminal.

All the visualization is done with the help of the MiniLibX library.

## Run the game

compile with 
> make all

run the game with 
> ./so_long maps/mymap.ber
