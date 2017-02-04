//
// Created by Lasse Lauritsen on 04/02/2017.
//

#ifndef RANDOMNUMBERDISTRIBUTION_GAME_H
#define RANDOMNUMBERDISTRIBUTION_GAME_H

#include <SDL.h>
class game {
 public:
  game(int screenWidth = 800, int screenHeight = 600);
  int loop();

 private:
  int const screenHeight_;
  int const screenWidth_;
  SDL_Window* window_ = nullptr;
  SDL_Renderer* renderer_ = nullptr;

  bool init();
  void close();

};

#endif //RANDOMNUMBERDISTRIBUTION_GAME_H
