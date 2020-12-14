//La classe Food mémorise la position de la pomme et vérifie si elle est mangée à chaque itération ou non
#include "stdlib.h"
#include "config.h"
#include "food.h"

Food::Food() : m_food({0,0}){

}


bool Food::eatFood(int* snake){
    if( (m_food[0]== snake[0]) && (m_food[1] == snake[SNAKE_LEN]) ){
        m_food[0] = 0;
        m_food[1] = 0;
        return true;
    }
    return false;
}

int* Food::getFood(){
    return m_food;
}