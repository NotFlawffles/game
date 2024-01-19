#pragma once

#include <SDL2/SDL.h>

#define private private:
#define public public:

#define ScreenSetup(child) public: child(bool accelerated, bool vsync, bool software, bool targetTexture, SDL_PixelFormatEnum pixelFormat, int framesPerSecond, SDL_TextureAccess textureAccess, int width, int height): Screen(accelerated, vsync, software, targetTexture, pixelFormat, framesPerSecond, textureAccess, width, height) {}

class Screen {
    private bool accelerated;
    private bool vsync;
    private bool software;
    private bool targetTexture;
    private SDL_Renderer* renderer;
    private SDL_PixelFormatEnum pixelFormat;
    private int framesPerSecond;
    private SDL_TextureAccess textureAccess;
    private int width;
    private int height;
    private SDL_Texture* texture;
    private SDL_Event event;

    public Screen(
	bool accelerated = true,
	bool vsync = true,
	bool software = false,
	bool targetTexture = false,
	SDL_PixelFormatEnum pixelFormat = SDL_PixelFormatEnum::SDL_PIXELFORMAT_RGBA8888,
	int framesPerSecond = 60,
	SDL_TextureAccess textureAccess = SDL_TextureAccess::SDL_TEXTUREACCESS_TARGET,
	int width = 512 * 16.0/9,
	int height = 512
    );

    public virtual void init(void);
    public virtual void update(float);
    public virtual void render(void);

    public void tick(void);

    public void clear(SDL_Color);

    public void setWidth(int),
		setHeight(int),
		setFramesPerSecond(int),
		setRenderer(SDL_Renderer*),
		setEventType(SDL_EventType);

    public int getWidth(void),
	       getHeight(void),
	       getFramesPerSecond(void);

    public SDL_Renderer* getRenderer(void);
    public SDL_Texture* getTexture(void);
    public SDL_Event* getEvent(void);
};
