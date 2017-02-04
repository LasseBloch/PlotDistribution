//
// Created by Lasse Lauritsen on 04/02/2017.
//

#include <array>
#include "game.h"

game::game(int screenWidth, int screenHeight) : screenHeight_(screenHeight), screenWidth_(screenWidth) {
  gen_ =  std::make_unique<dataGenerator>(screenWidth_/10);
}

bool game::init() {
  bool success = true;

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_Log("SDL could not be initialized! SDL_Error: %s\n", SDL_GetError());
    success = false;
  } else {
    // Create window
    window_ = SDL_CreateWindow("Random Number Distribution",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               screenWidth_,
                               screenHeight_,
                               SDL_WINDOW_SHOWN);
    if (window_) {
      // Create renderer for window_
      renderer_ = SDL_CreateRenderer(window_, -1, 0);
      if (!renderer_) {
        SDL_Log("Could not create renderer! SDL_Error: %s\n", SDL_GetError());
        success = false;
      } else {
        SDL_SetRenderDrawColor(renderer_, 255, 255, 255, SDL_ALPHA_OPAQUE);
      }
    } else {
      SDL_Log("Could not create window! SDL_Error: %s \n", SDL_GetError());
      success = false;
    }
  }
  return success;
}

void game::close() {
  SDL_DestroyRenderer(renderer_);
  renderer_ = nullptr;
  SDL_DestroyWindow(window_);
  window_ = nullptr;
  SDL_Quit();
}

int game::loop() {
  int data[screenWidth_/10];

  for (int n = 0; n < screenWidth_/10; n++) {
    data[n] = 0;
  }

  if (init()) {
    bool quit = false;
    SDL_Event evt;
    while (!quit) {
      // Handle events
      while (SDL_PollEvent(&evt)) {
        switch (evt.type) {
          case SDL_QUIT:quit = true;
            break;
          default:
            break;
        }
      }
      //gen_->addNumberUniform(data, screenWidth_/10);
      gen_->addNumberNormal(data, screenWidth_/10);
      drawDistrubution(data, screenWidth_/10);
    }
  } else {
    close();
    return -1;
  }
  close();
  return 0;
}

void game::drawDistrubution(int data[], int size) {
  SDL_Rect rects[size] ;
  int rect_width = screenWidth_/size;
  for (int n = 0; n < size; n++) {
    rects[n].y = screenHeight_ -  (5 * data[n]);
    rects[n].x = n * rect_width;
    rects[n].w = rect_width;
    rects[n].h = 5 * data[n];
  }
  SDL_SetRenderDrawColor(renderer_, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer_);
  SDL_SetRenderDrawColor(renderer_, 255, 255, 255, SDL_ALPHA_OPAQUE);
  SDL_RenderDrawRects(renderer_, rects, size);
  SDL_RenderPresent(renderer_);
}

