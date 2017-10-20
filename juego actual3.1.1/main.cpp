#include <cstdlib>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
#include "varglob.h"
#include "clasetimer.h"
#include "clases.h"
#include "boss.h"
#include "funciones.h"
#include "juego.h"
#include "enemigos.h"
#include "boss.h"
int main ( int argc, char** argv )
{
    iniciarSDL();
	TTF_Init();

    font = TTF_OpenFont("COPRGTB.ttf", 22);
    fonti =TTF_OpenFont("COPRGTB.ttf", 40);
    font3 = TTF_OpenFont("COPRGTB.ttf", 15);
    srand(0);

	JUEGO();
    TTF_CloseFont(font);
    TTF_CloseFont(fonti);
    TTF_CloseFont(font3);
    SDL_Quit();

    return 0;
}
