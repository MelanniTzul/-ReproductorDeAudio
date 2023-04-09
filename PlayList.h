#include <iostream>
#include <string>
#include "Song.h"
using namespace std;

// Struc PlayList
/* Declaración de la estructura Playlist que contiene un name,
una descripción, numero de canciones y un puntero a la lista de canciones.*/

// Lista doblemente enlazada
struct ListSongs // lista de canciones
{
    Song *song;          // el puntero de una cancion, tiene las siguientes
    ListSongs *next;     // apuntar a la siguiente cancion
    ListSongs *anterior; // apuntar a la anteriro cancion
};

struct PlayList
{
    string name;        // nombre
    string description; // puntero a una lista de canciones
    int id;
    ListSongs *listSongs; // lista de canciones
    PlayList *next;       // siguiente cancion
};

// listaPlaylists: es un puntero a un arreglo de objetos PlayList, que almacena todas las playlists creadas en el programa.
// id: es una referencia a un entero que indica el número de playlists que hay en el arreglo listaPlaylists
// listSong: es un puntero a un arreglo de objetos Song, que contiene todas las canciones disponibles en el programa.
//  función para crear una nueva playlist
void NewPlayList(PlayList *&head, int id, ListSongs *listSongs, Song *listSong)
{
    string name, description;
    int numSongs;
    // pedir al usuario que ingrese el name y la descripción de la playlist
    cout << "Ingrese el nombre de la playlist: ";
    std::cin.ignore();
    getline(cin, name);
    cout << "Ingrese una descripcion de la playlist: ";
    getline(cin, description);
    cout << "¿Desea agregar canciones a la playlist? (1 = si, 0 = no): ";
    cin >> numSongs;
    cin.ignore(); // para evitar problemas con el salto de línea
    // Se crea una nueva playlist con los datos ingresados por el usuario
    PlayList *nuevaPlaylist = new PlayList(); // Inicialmente la lista de canciones está vacía
    nuevaPlaylist->name = name;
    nuevaPlaylist->description = description;
    nuevaPlaylist->id = id;

    if (head == nullptr)
    {
        head = nuevaPlaylist;
    }
    else
    {
        PlayList *PlayListActual = head;
        while (PlayListActual->next != nullptr)
        {
            PlayListActual = PlayListActual->next;
        }
        PlayListActual->next = nuevaPlaylist;
    }

    if (numSongs == 1)
    {
        if (listSong == nullptr)
        {
            cout << "No existe canciones, ingrese canciones" << endl;
            return; // para que ya no siga
        }
        ViewListSongs(listSong);
    }
    else
    {
    }
    cout << "Playlist creada exitosamente." << endl;
}

/*FUNCION QUE LISTA LAS PLAY LIST EXISTENTES EN LA LISTA*/
void ViewPlayList(PlayList *&playlist)
{
    PlayList *currSong = playlist;
    while (currSong != nullptr)
    {
        cout << "Play list: " << currSong->name << endl;
        cout << "Descripcion: " << currSong->description << endl;
        cout << "ID: " << currSong->id << endl;
        cout << "\n"
             << endl;
        currSong = currSong->next;
    }
}

/*FUNCION QUE ME ELIMINA UNA PLAY LIST POR ID*/
void deletePlayListId(PlayList *&playList, int id)
{
    int deleteId;
    

    // verificar si la lista esta vacia
    if (playList == nullptr)
    {
        return; // Si la lista está vacía, simplemente retorna sin hacer nada
    }
    // Si la primera canción de la lista coincide con el id, eliminarla
    else if (playList->id == id)
    {                              // Verifica si el primer elemento de la lista coincide con el id de la canción que se va a eliminar
        PlayList *temp = playList; // Si coincide, se crea un puntero temporal que apunta a la cabeza de la lista
        playList = playList->next; // Se actualiza la cabeza de la lista para que apunte al segundo elemento
        delete temp;               // Se elimina el primer elemento utilizando el puntero temporal
    }
    // Si la canción no es la primera, buscarla en la lista
    else
    {                                        // Si el primer elemento no coincide con el id de la canción que se va a eliminar
        PlayList *prevSong = playList;       // Se crea un puntero que apunta al primer elemento de la lista
        PlayList *currSong = playList->next; // Se crea otro puntero que apunta al segundo elemento de la lista
        while (currSong != nullptr && currSong->id != id)
        {                              // Se recorre la lista hasta encontrar el elemento que coincide con el id de la canción o llegar al final de la lista
            prevSong = currSong;       // Se actualiza el puntero previo al elemento actual
            currSong = currSong->next; // Se actualiza el puntero al elemento actual
        }
        if (currSong != nullptr)
        {                                    // Si se encontró un elemento que coincide con el id de la canción
            prevSong->next = currSong->next; // Se actualiza el puntero del elemento anterior para saltar el elemento actual
            delete currSong;                 // Se elimina el elemento actual
        }
    }
}

