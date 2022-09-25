#ifndef _SDL2_Header
#define _SDL2_Header
#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#endif

#ifndef SDL2_gfx_extension
#define SDL2_gfx_extension
#include "SDL2_gfx_extension.h"
#endif

#ifndef _Point_Header
#define _Point_Header
#include "Point.h"
#endif

#ifndef _Color_Def
#define _Color_Def
SDL_Color Red = {255, 0, 0};
SDL_Color Green = {0, 255, 0};
SDL_Color Blue = {0, 0, 255};
SDL_Color Black = {0, 0, 0};
SDL_Color White = {0xff, 0xff, 0xff};
#endif

#ifndef _BST_Support
#define _BST_Support
#include "BST_node.h"
#include "BST_Class.h"
#include <iostream>
#include <vector>

using namespace std;

enum align
{
    alignLeft,
    alignCenter,
    alignRight
};
// Define Window Size
const int WIDTH = 1024;
const int HEIGHT = 720;
//PI
const float PI = 3.14159265358979323846264338327950288419716939937510;

SDL_Renderer *renderer;
SDL_Window *window;

int display_width;
int display_height;
int display_x, display_y;
BST my_tree;
vector<int> node_list;

void draw_text(SDL_Renderer *renderer, int x, int y, char message[], SDL_Color color, int alignment)
{
    SDL_Rect text_rect;
    SDL_Surface *messageSurface;
    int message_width;
    int message_height;
    SDL_Texture *textTexture;

    TTF_Font *Sans = TTF_OpenFont("FreeSans.ttf", 12); //this opens a font style and sets a size
    TTF_SizeText(Sans, message, &message_width, &message_height);
    messageSurface = TTF_RenderText_Blended(Sans, message, color);
    TTF_CloseFont(Sans);
    switch (alignment)
    {
    case alignLeft:
        text_rect.x = x; //controls the rect's x coordinate
        break;
    case alignCenter:
        text_rect.x = x - (message_width / 2); //controls the rect's x coordinate
        break;
    case alignRight:
        text_rect.x = x - message_width; //controls the rect's x coordinate
        break;
    }
    text_rect.y = y;              // controls the rect's y coordinte
    text_rect.w = message_width;  // controls the width of the rect
    text_rect.h = message_height; // controls the height of the rect
    textTexture = SDL_CreateTextureFromSurface(renderer, messageSurface);
    SDL_RenderCopy(renderer, textTexture, NULL, &text_rect);
    SDL_DestroyTexture(textTexture);
}

void Draw_node(int x, int y, int info, SDL_Renderer *renderer)
{
    thickCircleColor(renderer, x + 15, y + 15, 15, 0xff000000, 2);
    char s[100];
    sprintf(s, "%i", info);
    draw_text(renderer, x + 15, y + 7, s, Red, alignCenter);
}

void Draw_Tree(int h, int x, int y, int space, BST_node *n, SDL_Renderer *renderer)
{
    int gap;

    Draw_node(x, y, n->info, renderer);
    gap = space / 2;
    if (n->left != 0)
    {
        aalineColor(renderer, x + 10, y + 29, x - gap + 15, y + 60, 0xff000000);
        Draw_Tree(h + 1, x - gap, y + 60, gap, n->left, renderer);
    }
    if (n->right != 0)
    {
        aalineColor(renderer, x + 20, y + 29, x + gap + 15, y + 60, 0xff000000);
        Draw_Tree(h + 1, x + gap, y + 60, gap, n->right, renderer);
    }
}

int init()
{
    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        printf("SDL_Init Error: %s", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Binary Search Tree Animation Demo for CSCI415", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    if (window == NULL)
    {
        printf("SDL_CreateWindow Error: %s", SDL_GetError());
        SDL_Quit();
        return 2;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        SDL_DestroyWindow(window);
        printf("SDL_CreateRenderer Error: %s", SDL_GetError());
        SDL_Quit();
        return 3;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return -1;
    }

    //Initialize SDL_ttf
    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return -1;
    }
    return 0;
}

#endif
