#include "config.h"

class Snake{

    public :

    Snake();
    void setupSnake( int snl );
    bool verifyBorder( int snl );
    void update_snake_coordinates( int snl, int dxdy[] );
    int* getSnake();

    private :

    int m_snake[2*SNAKE_LEN];

};