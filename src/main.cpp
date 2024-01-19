#include "../include/base/engine.hpp"

#define public public
#define implements : public

class GameScreen implements Screen {
    const unsigned long pixels[16] = {
	0xFFFFFFFF
    };

    void init(void) override {

    }

    void update(float delta) override {

    }

    void render(void) override {
    }

    ScreenSetup(GameScreen)
};

int main(void) {
    GameScreen screen(
	true,
	true,
	false,
	true,
	SDL_PIXELFORMAT_RGBA8888,
	60,
	SDL_TEXTUREACCESS_STATIC,
	16,
	16
    );

    Window window;
    window.attachScreen(&screen);

    Engine engine(&window);
    engine.run(60);
}
