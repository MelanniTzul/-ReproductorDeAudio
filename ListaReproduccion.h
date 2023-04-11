#include <iostream>
#include <string>
#include "PlayList.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>

using namespace std;

// Las canciones se deben reproducir desde terminal.
// Para esto se deberá elegir una playlist la cual contendrá todas las canciones a reproducir.

struct ListaReproduccion
{
    ListSongs *listSongs; // lista de canciones
    Song *inicio;
    Song *fin;
    int id;
};

const char* AUDIO_FILE = "audio.mp3";

// Estructura que contiene los datos del archivo de audio
struct AudioData {
    uint8_t* buffer;
    uint32_t size;
};



void Normal()
{
    // Reproduce las canciones en el orden qué se encuentran en la playlist y al terminar la misma se detiene. (Nota: Para esta reproducción se debe utilizar una lista doblemente enlazada)
}

void Repetir()
{
    // Reproduce las canciones en el orden qué se encuentran en la playlist y al terminar vuelve a iniciar desde la primer canción (Nota: Para esta reproducción se debe usar una lista circular o una doblemente circular)
}

void Siguiente()
{
    // Reproduce la canción qué sigue en la lista.
}

void Anterior()
{
    // Reproduce la canción anterior en la lista.
}

void Listadereproducción()
{
    // Te muestra las canciones qué se reproducirá después de la canción actual.
}

void Agregarcanciónlistareproducción()
{
    // Listará la lista de canciones (store) y permitirá agregar una canción después de
    // la canción qué se esté reproduciendo en ese momento. Para esto deberá implementar una Pila como “lista prioritaria” por lo cual antes de seguir con la lista de reproducción deberá confirmar que esta “lista prioritaria” esté vacía.
    //(Nota: Para esta reproducción se debe utilizar una Pila → FILO)
}
