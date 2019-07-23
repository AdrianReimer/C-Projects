cmake_minimum_required(VERSION 3.14)
project(ConsoleGame C)

set(CMAKE_C_STANDARD 11)


add_executable(ConsoleGame src/main.c src/World/World.c src/World/World.h src/Enemy/Tower/Cannon.c src/Enemy/Tower/Cannon.h src/Enemy/Tower/Laser.c src/Enemy/Tower/Laser.h src/Enemy/Trap/Spike.c src/Enemy/Trap/Spike.h src/Player/Player.c src/Player/Player.h)