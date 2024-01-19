#include "../../include/base/engine.hpp"

Engine::Engine(Window* window) {
    this->window = window;
}

void Engine::run(int framesPerSecond) {
    this->window->getScreen()->setFramesPerSecond(framesPerSecond);
    this->window->getScreen()->init();
    this->window->getScreen()->setRenderer(SDL_CreateRenderer(this->window->getBase(), -1, this->window->getScreen()->getFlags()));
    this->running = true;
    SDL_Init(SDL_INIT_EVERYTHING);

    while (this->running) {
	this->window->getScreen()->tick();

	if (this->window->getScreen()->getEvent()->type == SDL_QUIT) {
	    this->running = false;
	}
    
	SDL_Delay(1000.0 / this->window->getScreen()->getFramesPerSecond());
    }
}
