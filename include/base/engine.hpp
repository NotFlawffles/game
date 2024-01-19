#pragma once

#include "window.hpp"

#define private private:
#define public public:

class Engine {
    private Window* window;
    private bool running = false;

    public Engine(Window*);

    public void run(int);
};
