#include <iostream>
#include "sys/ioctl.h"

#include "stdlib.h"

#include "config.h"
#include "internals.h"
#include "display.h"
#include "food.h"
#include "Snake.h"
#include "Board.h"
#include "game.h"

int main(){

  Snake snake;
  Board board;
  Food food;
  Game game;
  game.startGame(snake, board, food);
  return 0;
}
