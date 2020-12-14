//La classe Board permet de représenter le plateau de jeu et a comme attribut la taille du snake et la mémoire du plateau
#include "Board.h"
#include <iostream>

Board::Board() : m_snl(3), m_background() {

}

//Il faut initialiser le plateau au début de la partie
void Board::backgroundSetup(){
  for( int i=0; i<nx*ny; i++){
    m_background[i] = -1;
  }
  for (int i=0; i<nx; i++){
    m_background[i] = 1;
    m_background[i+nx*(ny-1)] = 1;
  }
  for (int j=0; j<ny; j++){
    m_background[j*nx] = 1;
    m_background[j*nx + nx-1] = 1;
  }
}

//A la fin de chaque itération il faut rajouter les nouvelles coordonnées du snake
void Board::add_snake( int snake[2*SNAKE_LEN] ){
  for (int i = 0; i < m_snl; i++) {
    m_background[snake[i] + nx*snake[i + SNAKE_LEN]] = 1;
  }
}

//Mais avant il faut enlever les anciennes
void Board::remove_snake( int snake[2*SNAKE_LEN] ){
  for (int i = 0; i < m_snl; i++) {
    m_background[snake[i] + nx*snake[i + SNAKE_LEN]] = 0;
  }
}

//Quand le snake mange une pomme il faut en recréer une aléatoirement sur le plateau
void Board::createFood(int food[2]){
    if( food[0] == 0){
        food[0] = rand()%(nx-2) + 1;//j'ai mis 1 à la place de 2
        food[1] = rand()%(ny-2) + 1;//idem
        m_background[food[1]*nx+food[0]] = 2;

    }
}

//Les getters

int* Board::getBackground(){
  return m_background;
}

int Board::getSnakelength(){
  return m_snl;
}

//Quand le snake mange une pomme sa taille augment de 1
void Board::incr_snl(){
  m_snl ++;
}