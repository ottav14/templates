#include <iostream>
#include <SDL2/SDL.h>

int main() {

  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;
  SDL_Event e;

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_CreateWindowAndRenderer(1920, 1080, 0, &window, &renderer);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  // Draw a red rectangle
  SDL_Rect rect = {100, 100, 200, 150};
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
  SDL_RenderFillRect(renderer, &rect);

  // Update the window
  SDL_RenderPresent(renderer);

  // Main loop: handle events
  bool quit = false;
  SDL_Event event;
  while (!quit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
	quit = true;
      }
    }
  }

  // Clean up resources
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();


  std::cout << "Ran" << std::endl;
  return 0;

}
