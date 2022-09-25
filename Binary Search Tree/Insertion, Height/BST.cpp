#define _GNU_SOURCE /* To get defns of NI_MAXSERV and NI_MAXHOST */
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <pthread.h>
#include <math.h>
#include "BST_Graphics.h"
#include "BST_Class.h"
using namespace std;

bool quit = false;
pthread_mutex_t received_message_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t vector_lock = PTHREAD_MUTEX_INITIALIZER;
bool refresh = false;

//******************************
// Do no touch this method!!
//******************************
int event_thread(void *arg)
{
    SDL_Event event;
    int key;

    while (!quit)
    {
        while (!quit && SDL_WaitEvent(&event))
        {
            SDL_PollEvent(&event);
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;

                break;
            case SDL_KEYDOWN:

                if (node_list.size() != 0)
                {
                    refresh = true;
                    key = node_list.front();
                    my_tree.Insert(key);
                    node_list.erase(node_list.begin());
                }

                switch (event.key.keysym.sym)
                {
                case SDLK_a:

                    break;
                case SDLK_d:

                    break;
                case SDLK_w:

                    break;
                case SDLK_x:

                    break;
                case SDLK_q:

                    break;
                case SDLK_e:

                    break;
                case SDLK_z:

                    break;
                case SDLK_c:

                    break;
                case SDLK_s:

                    break;
                case SDLK_ESCAPE: // Quitting game
                    quit = true;

                    break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button)
                {
                case SDL_BUTTON_LEFT:

                    break;
                }
            }
        }
        exit(0);
    }
    return 0;
}

//******************************
// Do no touch this method!!
//******************************
void InsertNodes(int key)
{
    node_list.push_back(key);
}

int main(int argc, char **argv)
{
    // variables

    char name_string[100] = {0};
    char temp_string[255] = {0}; // Maximum length of a string
    int myRole = 0;
    bool quit = false;
    SDL_Event event;
    int center_x, top_y;

    if (argc < 2)
    {
        cout << "Usage:" << endl;
        cout << "./BST.out key" << endl;
        cout << "press ESC to escape" << endl;
        cout << "Arguments:" << endl;
        cout << "key: keys that you are going to insert into the Binary Search Tree" << endl;
        cout << "Example:" << endl;
        cout << "./BST.out 1 2 3 4 5 6 7" << endl;
        cout << "    : It will insert 1, 2, 3, 4, 5, 6, 7 keys into the BST" << endl;
        // Test case:
        // ./BST.out 10 25 5 12 20 2 8 40 1
    }
    else
    {
        cout << "BST By Sunyoung Park" << endl;
        init();
        for (int i = 1; i < argc; i++)
            InsertNodes(atoi(argv[i]));
        //my_tree.MakeTree();
        // Initiaize event thread
        SDL_Thread *thread;
        thread = SDL_CreateThread(event_thread, "Tests", NULL);
        // clear window
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        // Animate Inserting nodes into my_tree
        while (!quit)
        {
            SDL_Delay(33);
            if (refresh)
            {
                // clear window
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderClear(renderer);
                int h = my_tree.Height();
                if (h > 0)
                {
                    display_width = (pow(2, h - 1) - 1) * 40 + 40;
                    display_height = ((h - 1) * 60 + 40);
                }
                BST_node *n = my_tree.root;

                if (n != 0)
                    Draw_Tree(0, display_width / 2 - 15 - display_x, 0 - display_y + 5, display_width / 2, n, renderer);
                SDL_RenderPresent(renderer);
                refresh = false;
            }
        }

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    return 0;
}