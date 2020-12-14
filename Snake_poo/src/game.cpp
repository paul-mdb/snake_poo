//La classe Game est celle où se déroule le jeu et dans laquelle les autres classes intéragissent
#include "game.h"
#include <iostream>
#include "sys/ioctl.h"

#include "stdlib.h"

#include "config.h"
#include "internals.h"
#include "display.h"
#include "food.h"
#include "Snake.h"
#include "Board.h"

//Les attributs sont le score, la direction dans laquelle se déplace le snake et le temps entre l'impression des tableaux de chaque itération
Game::Game() : m_score(0), m_dxdy({1,0}), m_lap(300){

}

//Il faut interpréter les commandes de l'utilisateur pour changer la direction du snake
void Game::snake_movement( int key ){
  if (key == 68){
    m_dxdy[0] = -1;
    m_dxdy[1] = 0;
  }

  else if (key == 67){
    m_dxdy[0] = 1;
    m_dxdy[1] = 0;
  }
  else if (key == 66){
    m_dxdy[0] = 0;
    m_dxdy[1] = 1;
  }
  else if (key == 65){
    m_dxdy[0] = 0;
    m_dxdy[1] = -1;
  }
}

//Le jeu se lance et continue jusqu'à ce que le snake sorte ou se morde la queue
void Game::startGame(Snake snake, Board board, Food food){



    //On initialise le plateau
    board.backgroundSetup();
    snake.setupSnake( board.getSnakelength() );

    board.createFood( food.getFood() );

    while( true ){
        internal::frameSleep(m_lap);
        if( internal::keyEvent() ){
            int a = getchar();
            int b = getchar();
            int key = getchar();
            snake_movement(key);        }
        backgroundClear();
        board.add_snake( snake.getSnake() );
        printFrame( board.getBackground() );
        board.remove_snake( snake.getSnake() );
        
        bool out =  snake.verifyBorder( board.getSnakelength() );

        //Si le joueur à perdu à cette itération

        if( out == false ){
            std::cout << "Bravo ! Vous avez effectué un score de ";
            std::cout << m_score << std::endl;
            std::cerr << "" << std::endl;
            exit(1);
        }
        
        //Si il a mangé la pomme
        bool eat = food.eatFood(snake.getSnake());
        if(eat){
            board.createFood(food.getFood());
            board.incr_snl();
            m_score++;
            if (m_lap > 30){
              m_lap = m_lap - 10;
            }
        }
        snake.update_snake_coordinates(board.getSnakelength(), m_dxdy);

    }
}