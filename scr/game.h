//
// Created by Lasse Lauritsen on 04/02/2017.
//

#ifndef RANDOMNUMBERDISTRIBUTION_GAME_H
#define RANDOMNUMBERDISTRIBUTION_GAME_H

#include <SDL.h>
#include "dataGenerator.h"

class game {
 public:
  game(int screenWidth = 800, int screenHeight = 600);
  int loop();

 private:
  const int screenHeight_;
  const int screenWidth_;
  SDL_Window* window_ = nullptr;
  SDL_Renderer* renderer_ = nullptr;
  std::unique_ptr<dataGenerator> gen_;

  bool init();
  void close();
  void drawDistrubution(int data[], int size);
};

#endif //RANDOMNUMBERDISTRIBUTION_GAME_H
