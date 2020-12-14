#include "config.h"

class Board{

    public :

    Board(); // constructeur
    void backgroundSetup();
    void add_snake( int snake[2*SNAKE_LEN] );
    void remove_snake( int snake[2*SNAKE_LEN] );
    void createFood(int food[2]);
    int* getBackground();
    int getSnakelength();
    void incr_snl();

    private :

    int m_background[nx*ny];
    int m_snl;

};