// La classe Snake permet de représenterle snake sous forme de tableau de coordonnées
#include "Snake.h"
#include <iostream>

Snake::Snake() : m_snake(){

}

//initialise les coordonnées du snake en début de partie en prenant en argument la taille du snake
void Snake::setupSnake( int snl ){
  int x_init = 10;
  int y_init = 10;
  for (int i=0; i<snl; i++){
    m_snake[i] = x_init +i;
    m_snake[i+SNAKE_LEN] = y_init;
  }
}

//La partie s'arrête si la tête du snake sort du tableau ou bien rencontre la queue du snake
bool Snake::verifyBorder( int snl ) {
  bool boo = true;
  boo = (1<=m_snake[0]) && (m_snake[0]<nx-1) && (1<=m_snake[SNAKE_LEN]) && (m_snake[SNAKE_LEN]<ny-1);
  for (int i=2; i<snl; i++){
    if ((m_snake[i]==m_snake[0])&&(m_snake[i+SNAKE_LEN]==m_snake[SNAKE_LEN])){
      boo = false;
    }

  return boo;

}

//A chaque itération du jeu il faut mettre à jour les coordonnées du snake. En partant de la queue chaque case prend les
//coordonnées de la suivante. La tête avance de une case dans la direction du moment

void Snake::update_snake_coordinates( int snl, int dxdy[] ) {//Je ne comprends vraiment pas cette erreur...
    for (int i=snl; i > 0; i--){
      m_snake[i] = m_snake[i-1];
      m_snake[i+SNAKE_LEN] = m_snake[i+SNAKE_LEN-1];
    }
    m_snake[0] = m_snake[0] + dxdy[0];
    m_snake[SNAKE_LEN] = m_snake[SNAKE_LEN] + dxdy[1];
}

//Un getteur qui renvoie les coordonnées du snake
int* Snake::getSnake(){
  return m_snake;
}