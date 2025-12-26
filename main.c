#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main ()
{
    FILE *in = stdin;
    char *pthrow = calloc(100, sizeof(char));
    // Read the first line and throwaway (version)
    fgets(pthrow, 100, in);
    // Read the second line and discard (comment)
    fgets(pthrow, 100, in);
    // Read the third line (width and height)
    char *pdim = calloc(100, sizeof(char));
    fgets(pdim, 100, in);
    // Read the fourth line and discard (max color value)
    fgets(pthrow, 100, in);
    free(pthrow);

    int width = -1;
    int height = -1;
    sscanf(pdim, "%d %d\n", &width, &height);
    free(pdim);
    printf("Width: %d, Height: %d\n", width, height);


    SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
    
    Uint32 color = 0;
    SDL_Rect pixel = (SDL_Rect) {0, 0, 1, 1};
    for (int y = 0; y < height; y++) 
    {
        for (int x = 0; x < width; x++) 
        {
            Uint8 r, g, b;
            r = (char) getchar();
            g = (char) getchar();
            b = (char) getchar();
            color = SDL_MapRGB(psurface->format, r, g, b);
            pixel.x = x;
            pixel.y = y;
            SDL_FillRect(psurface, &pixel, color);
        }
    }
    
    SDL_UpdateWindowSurface(pwindow);

    int app_running = 1;
    while (app_running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                app_running = 0;
            }
        }
    }
}
