#include "../../include/base/screen.hpp"

Screen::Screen(
    bool accelerated,
    bool vsync,
    bool software,
    bool targetTexture,
    SDL_PixelFormatEnum pixelFormat,
    int framesPerSecond,
    SDL_TextureAccess textureAccess,
    int width,
    int height
) {
    this->accelerated = accelerated;
    this->vsync = vsync;
    this->software = software;
    this->targetTexture = targetTexture;
    this->pixelFormat = pixelFormat;
    this->framesPerSecond = framesPerSecond;
    this->textureAccess = textureAccess;
    this->width = width;
    this->height = height;
}

void Screen::init(void) {}
void Screen::update(float) {}
void Screen::render(void) {}

void Screen::tick(void) {
    SDL_PollEvent(this->getEvent());
    this->update(1.0/this->framesPerSecond);
    this->render();
}

void Screen::clear(SDL_Color color) {
    SDL_SetRenderDrawColor(this->getRenderer(), color.r, color.g, color.b, color.a);
    SDL_RenderClear(this->getRenderer());
}

void Screen::setWidth(int width) {
    this->width = width;
}

void Screen::setHeight(int height) {
    this->height = height;
}

void Screen::setFramesPerSecond(int framesPerSecond) {
    this->framesPerSecond = framesPerSecond;
}

void Screen::setRenderer(SDL_Renderer* renderer) {
    this->renderer = renderer;
}

void Screen::setEventType(SDL_EventType type) {
    this->event.type = type;
}

int Screen::getWidth(void) {
    return this->width;
}

int Screen::getHeight(void) {
    return this->height;
}

int Screen::getFramesPerSecond(void) {
    return this->framesPerSecond;
}

SDL_Renderer* Screen::getRenderer(void) {
    return this->renderer;
}

SDL_Texture* Screen::getTexture(void) {
    return this->texture;
}

SDL_Event* Screen::getEvent(void) {
    return &this->event;
}
