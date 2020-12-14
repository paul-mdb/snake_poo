#include "config.h"
#include "internals.h"
#include "display.h"
#include "food.h"
#include "Snake.h"
#include "Board.h"

class Game {
    public :
    Game();
    void startGame(Snake snake, Board board, Food food);
    void snake_movement( int key );

    private :
    int m_score;
    int m_dxdy[2];
    int m_lap;

};