#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void iniciarSDL() {
    SDL_Init( SDL_INIT_EVERYTHING );
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE );
    SDL_WM_SetCaption( "juego street", NULL );
}

SDL_Surface* cargarImagen(const char direccion[50]) {
    SDL_Surface* imagen = NULL;
    SDL_Surface* optimizada = NULL;

    imagen = SDL_LoadBMP(direccion);
    if(imagen != NULL) {
        optimizada = SDL_DisplayFormat(imagen);
        SDL_FreeSurface(imagen);
    }

    if(optimizada == NULL) {
        cout << "fallo carga de imagen" << direccion << endl;
    }
    Uint32 colorkey = SDL_MapRGB(optimizada->format, 0, 0, 0);
    SDL_SetColorKey(optimizada, SDL_SRCCOLORKEY, colorkey);

    return optimizada;
}



void aplicarSuperficie(int x, int y, SDL_Surface* imagen, SDL_Surface* destino, SDL_Rect *clip = NULL) {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(imagen, clip, destino, &offset);
}

bool checkpos(SDL_Rect& rect, int x, int y )
{
    if( ( x > rect.x ) && ( x < rect.x + rect.w ) && ( y > rect.y ) && ( y < rect.y + rect.h ) )
        {

            return true;
        }
    else
        {
            return false;
        }

    return true;
}

bool check_collision( SDL_Rect A, SDL_Rect B )
{
    //Los lados del rectangulo
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calcular los lados del rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    //Calcular los lados del rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    //Si cualquiera de los lados de A estan fuera de los de B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //Si ninguno de los lados de A esta fuera de B
    return true;
}




#endif // FUNCIONES_H_INCLUDED
