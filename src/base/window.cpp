#include "../../include/base/window.hpp"

Window::Window(
    std::string title,
    int x,
    int y,
    int width,
    int height,
    int minimumWidth,
    int minimumHeight,
    int maximumWidth,
    int maximumHeight,
    float brightness,
    float opacity,
    bool hasShape,
    bool foreign,
    bool popupMenu,
    bool fullscreen,
    bool alwaysOnTop,
    bool focused,
    bool bordered,
    bool resizable,
    GraphicsAPI graphicsAPI,
    Visibility visibility,
    Expansion expansion,
    DPI dpi
) {
    this->title.assign(title);
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->minimumWidth = minimumWidth;
    this->minimumHeight = minimumHeight;
    this->maximumWidth = maximumWidth;
    this->maximumHeight = maximumHeight;
    this->brightness = brightness;
    this->opacity = opacity;
    this->hasShape = hasShape;
    this->foreign = foreign;
    this->popupMenu = popupMenu;
    this->fullscreen = fullscreen;
    this->alwaysOnTop = alwaysOnTop;
    this->focused = focused;
    this->bordered = bordered;
    this->resizable = resizable;
    this->graphicsAPI = graphicsAPI;
    this->visibility = visibility;
    this->expansion = expansion;
    this->dpi = dpi;

    this->flags =
	(this->hasShape    ? ~SDL_WINDOW_LACKS_SHAPE   : 0) |
	(this->foreign     ?  SDL_WINDOW_FOREIGN       : 0) |
	(this->popupMenu   ?  SDL_WINDOW_POPUP_MENU    : 0) |
	(this->fullscreen  ?  SDL_WINDOW_FULLSCREEN    : 0) |
	(this->alwaysOnTop ?  SDL_WINDOW_ALWAYS_ON_TOP : 0) |
	(this->bordered    ? ~SDL_WINDOW_BORDERLESS    : 0) |
	(this->focused     ? ~SDL_WINDOW_INPUT_FOCUS   : 0) |
	(this->resizable   ?  SDL_WINDOW_RESIZABLE     : 0) |
	 this->graphicsAPI				    |
	 this->visibility			            |
	 this->expansion				    |
	 this->dpi;

    SDL_Window* window = SDL_CreateWindow(this->title.c_str(), this->x, this->y, this->width, this->height, this->flags);
    SDL_SetWindowBrightness(window, this->brightness);
    SDL_SetWindowOpacity(window, this->opacity);
    SDL_SetWindowMinimumSize(window, this->minimumWidth, minimumHeight);
    SDL_SetWindowMaximumSize(window, this->maximumWidth, this->maximumHeight);
}

void Window::setTitle(std::string title) {
    this->title.assign(title);
}

void Window::setX(int x) {
    this->x = x;
}

void Window::setY(int y) {
    this->y = y;
}

void Window::setWidth(int width) {
    this->width = width;
}

void Window::setHeight(int height) {
    this->height = height;
}

void Window::setMinimumWidth(int width) {
    this->minimumWidth = width;
    SDL_SetWindowMinimumSize(this->getBase(), this->minimumWidth, this->minimumHeight);
}

void Window::setMinimumHeight(int height) {
    this->minimumHeight = height;
    SDL_SetWindowMinimumSize(this->getBase(), this->minimumWidth, this->minimumHeight);
}

void Window::setMaximumWidth(int width) {
    this->maximumWidth = width;
    SDL_SetWindowMaximumSize(this->getBase(), this->maximumWidth, this->maximumHeight);
}

void Window::setMaximumHeight(int height) {
    this->maximumHeight = height;
    SDL_SetWindowMinimumSize(this->getBase(), this->maximumWidth, this->maximumHeight);
}

void Window::setBrightness(float brightness) {
    this->brightness = brightness;
    SDL_SetWindowBrightness(this->getBase(), this->brightness);
}

void Window::setOpacity(float opacity) {
    this->opacity = opacity;
    SDL_SetWindowOpacity(this->getBase(), this->opacity);
}

void Window::setFullScreen(bool fullscreen) {
    this->fullscreen = fullscreen;
    SDL_SetWindowFullscreen(this->getBase(), this->fullscreen);
}

void Window::attachScreen(Screen* screen) {
    this->screen = screen;
}

std::string Window::getTitle(void) {
    return this->title;
}

int Window::getX(void) {
    return this->x;
}

int Window::getY(void) {
    return this->y;
}

int Window::getWidth(void) {
    return this->width;
}

int Window::getHeight(void) {
    return this->height;
}

float Window::getBrightness(void) {
    return this->brightness;
}

float Window::getOpacity(void) {
    return this->opacity;
}

SDL_Window* Window::getBase(void) {
    return this->base;
}

Screen* Window::getScreen(void) {
    return this->screen;
}
