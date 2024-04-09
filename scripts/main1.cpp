/*
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

// You must include the command line parameters for your main function
// to be recognized by SDL as a WinMain prototype's  impl
// do it or SDL_windows_main.c:80: undefined reference to `SDL_main',
//you can only have one definition of SDL_main in the CMake project
int some(int argc,char** argv) {

    // Pointers to our window and surface
    SDL_Surface* winSurface = nullptr;
    SDL_Window* window = nullptr;

    if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
        cout << "Error initializing SDL: " << SDL_GetError() << endl;
        return 1;
    }

    window = SDL_CreateWindow( "SDL is Awesome", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               640, 480, SDL_WINDOW_SHOWN );
    if ( !window ) {
        cout << "Error creating window: " << SDL_GetError()  << endl;
        return 1;
    }

    winSurface = SDL_GetWindowSurface( window );
    if ( !winSurface ) {
        cout << "Error getting surface: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_FillRect( winSurface, nullptr, SDL_MapRGB( winSurface->format, 255, 255, 255 ) );
    SDL_UpdateWindowSurface( window );
    system("pause");
    SDL_DestroyWindow( window );
    SDL_Quit();
    return 0;
}*/
