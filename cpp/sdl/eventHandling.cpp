#include<stdlib.h>
#include<SDL2/SDL.h>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;

SDL_Surface* gScreenSurface = NULL;

SDL_Surface* gXOut = NULL;

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if(SDL_Init( SDL_INIT_VIDEO) < 0)
    {
        printf("sdl could not initialize! sdl_Error: %s\n", SDL_GetError());
        success = false; 
    }
    else
    {
        //Get window surface
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if( gWindow == NULL){
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false; 
        }
        else{
            gScreenSurface = SDL_GetWindowSurface(gWindow);
    
        }

     }

    return success;
}

bool loadMedia()
{
     //Loading success flag
    bool success = true;

    //Load splash image
    gXOut = SDL_LoadBMP( "Content/sprites/hello_world.bmp" );
    if(gXOut == NULL)
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "Content/sprites/hello_world.bmp", SDL_GetError());
        success = false;
    }

    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( gXOut);
    gXOut = NULL;

    //Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

int main(int argc, char* args[]){

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //Start up SDL and create window
    if(!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        //Load media
        if(!loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Apply the image
            SDL_BlitSurface( gXOut, NULL, gScreenSurface, NULL);

            SDL_UpdateWindowSurface( gWindow);

            //Wait two seconds
            SDL_Delay(2000);
        }
    }
    while(!quit)
    {
        while( SDL_PollEvent( &e ) != 0)
        {
            //User requests quit
            if( e.type == SDL_QUIT)
            {
                quit = true;
                SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL );

                //Update the surface
                SDL_UpdateWindowSurface(gWindow);
            }
        }
    }
    close();
    return(0);

}
