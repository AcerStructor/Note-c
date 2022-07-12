#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "constants.h"

// SDL Declaration:
SDL_Window* window;
SDL_Renderer* renderer;

// Game Setup:
void Game_Setup() {
    // 
}
// Keyboard Event:
void Game_KeyEvent(SDL_Event* event, int* isRunning) {
    switch(event->key.keysym.sym) {
    case SDLK_ESCAPE:
        *isRunning = FALSE;
        break;
    }
}
// Main Window Event:
void Game_ProcessEvent(SDL_Event* event, int* isRunning) {
    while (SDL_PollEvent(event)) {
        switch(event->type) {
        case SDL_QUIT:
            *isRunning = FALSE;
            break;
        case SDL_KEYDOWN:
            Game_KeyEvent(event, isRunning);
            break;
        }
    }
}
// Game Update:
void Game_Update() {
    // Soon!
}
// Game Render:
void Game_Render() {
    // Window Background:
    SDL_SetRenderDrawColor(renderer, 62, 62, 62, 62);
    SDL_RenderClear(renderer);

    // Draw Here:

    // Draw Everything to the screen:
    SDL_RenderPresent(renderer);
    SDL_Delay(100); // Don't burn up CPU
}
// Game Initialization:
int Game_Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr ,"Error: Initializing SDL.\n");
        return FALSE;
    }

    // Initialize Window:
    window = SDL_CreateWindow(PROGRAM_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    if (window == NULL) { // Check if window is not initialized:
        fprintf(stderr ,"Error: Initializing Window.\n");
        return FALSE;
    }

    // Initialize Renderer:
    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == NULL) { // Check if renderer is not initialized:
        fprintf(stderr, "Error: Initializing renderer.\n");
        return FALSE;
    }

    return TRUE;
}
// Cleans up SDL before ending the program:
void Game_Destroy() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    // Initialize boolean and event:
    int isRunning = Game_Init();
    SDL_Event event;

    Game_Setup();
    while (isRunning == TRUE) {
        Game_ProcessEvent(&event, &isRunning);
        Game_Update();
        Game_Render();
    }
    Game_Destroy();

    return EXIT_SUCCESS;
}