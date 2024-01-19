#pragma once

#include <SDL2/SDL.h>
#include <string>

#include "screen.hpp"

#define private private:
#define public public:

class Window {
    public enum GraphicsAPI {
	OpenGL = SDL_WINDOW_OPENGL,
	Vulkan = SDL_WINDOW_VULKAN
    };

    public enum Visibility {
	Hidden = SDL_WINDOW_HIDDEN,
	Shown = 0
    };

    public enum Expansion {
	Floating = 0,
	Minimized = SDL_WINDOW_MINIMIZED,
	Maximized = SDL_WINDOW_MAXIMIZED
    };

    public enum DPI {
	Low = 0,
	High = SDL_WINDOW_ALLOW_HIGHDPI
    };

    private std::string title;
    private int x;
    private int y;
    private int width;
    private int height;
    private int minimumWidth;
    private int minimumHeight;
    private int maximumWidth;
    private int maximumHeight;
    private float brightness;
    private float opacity;
    private bool hasShape;
    private bool foreign;
    private bool popupMenu;
    private bool fullscreen;
    private bool alwaysOnTop;
    private bool bordered;
    private bool focused;
    private bool resizable;
    private GraphicsAPI graphicsAPI;
    private Visibility visibility;
    private Expansion expansion;
    private DPI dpi;
    private unsigned int flags;
    private SDL_Window* base;
    private Screen* screen;

    public Window(
	std::string title = "Untitled",
	int x = SDL_WINDOWPOS_CENTERED,
	int y = SDL_WINDOWPOS_CENTERED,
	int width = 512 * 16.0/9,
	int height = 512,
	int minimumWidth = 512 * 16.0/9,
	int minimumHeight = 512,
	int maximumWidth = 512 * 16.0/9,
	int maximumHeight = 512,
	float brightness = 1.0,
	float opacity = 1.0,
	bool hasShape = true,
	bool foreign = true,
	bool popupMenu = false,
	bool fullscreen = false,
	bool alwaysOnTop = false,
	bool bordered = true,
	bool focused = true,
	bool resizable = false,
	GraphicsAPI graphicsAPI = GraphicsAPI::OpenGL,
	Visibility visibility = Visibility::Shown,
	Expansion expansion = Expansion::Floating,
	DPI dpi = DPI::Low
    );

    public void setTitle(std::string),
		setX(int),
		setY(int),
		setWidth(int),
		setHeight(int),
		setMinimumWidth(int),
		setMinimumHeight(int),
		setMaximumWidth(int),
		setMaximumHeight(int),
		setBrightness(float),
		setOpacity(float),
		setFullScreen(bool),
		attachScreen(Screen*);

    public std::string getTitle(void);

    public int getX(void),
	       getY(void),
	       getWidth(void),
	       getHeight(void);

    public float getBrightness(void),
		 getOpacity(void);

    public SDL_Window* getBase(void);
    public Screen* getScreen(void);
};
