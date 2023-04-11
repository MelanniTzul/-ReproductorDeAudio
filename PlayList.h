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

/*Agregar canciones a la playlist*/
void addSongsPlaylist(ListSongs *&head, int id, Song *&song)
{
    int idCancion;
    if (song == nullptr)
    {

        cout << "No existe canciones, ingrese canciones" << endl;
        return; // para que ya no siga
    }
    else
    {
        while (idCancion!=0)
        {
            ViewListSongs(song); // listamos canciones
            cout << "Ingrese el id de la cancion que desea agregar a la playlist o 0 para salir" << endl;
            cin >> idCancion;
            Song *temp = song;
            while (temp != nullptr && temp->id != idCancion)
            {

                temp = temp->next; // buscando playlist
            }

            if (temp == nullptr)
            {
                cout << "Cancion no encontrada" << endl;
                return;
            }

            ListSongs *newListSongs = new ListSongs();
            newListSongs->song = temp;    // Asignamos cancion
            newListSongs->next = nullptr; // se establece el campo null,lo que indica que no hay ningún otro nodo siguiente en la lista
            if (head == nullptr)
            {
                head = newListSongs;
            }
            else
            {
                // si el puntero head no es nullptr, se recorre la lista enlazada hasta encontrar
                // el ultimo nodo, y se agrega el nodo newListSongs al final de la lista
                ListSongs *cancionActual = head; // Se inicializa un puntero "cancionActual" al primer nodo de la lista.
                while (cancionActual->next != nullptr)
                {
                    cancionActual = cancionActual->next; // se actualiza cancionActual al siguiente nodo de la lista
                }
                cancionActual->next = newListSongs;
            }
        }
    }
}

// listaPlaylists: es un puntero a un arreglo de objetos PlayList, que almacena todas las playlists creadas en el programa.
// id: es una referencia a un entero que indica el número de playlists que hay en el arreglo listaPlaylists
// listSong: es un puntero a un arreglo de objetos Song, que contiene todas las canciones disponibles en el programa.
//  función para crear una nueva playlist
void NewPlayList(PlayList *&head, int id, ListSongs *&listSongs, Song *&song)
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

    if (head == nullptr) // si es diferente de null
    {
        head = nuevaPlaylist; // se crea una playlist
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
        // Llamar a la funcion ingresar cancion
        addSongsPlaylist(nuevaPlaylist->listSongs, id, song);
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

void UpdatePlaylist(PlayList *&playlists)
{
    int idUpdate;
    string nameUpdate, descriptionUpdate;

    if (playlists != nullptr)
    {
        ViewPlayList(playlists);
        cout << "Ingrese el id de la play list que desea modificar: " << endl;
        cin >> idUpdate;
        if (playlists->id == idUpdate)
        {
            cout << "Ingrese el nuevo nombre de la playlist" << endl;
            std::cin.ignore();
            std::getline(std::cin, nameUpdate);
            cout << "Ingrese la nueva descripcon de la playlist" << endl;
            std::getline(std::cin, descriptionUpdate);
            playlists->name = nameUpdate;
            playlists->description = descriptionUpdate;
            cout << "Datos actualizados correctamente: \nNombre: " << playlists->name << "\nDescripcion: " << playlists->description << endl;
        }
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
    // Si la primera playlist de la lista coincide con el id, eliminarla
    else if (playList->id == id)
    {                              // Verifica si el primer elemento de la lista coincide con el id de la playlist que se va a eliminar
        PlayList *temp = playList; // Si coincide, se crea un puntero temporal que apunta a la cabeza de la lista
        playList = playList->next; // Se actualiza la cabeza de la lista para que apunte al segundo elemento
        delete temp;               // Se elimina el primer elemento utilizando el puntero temporal
    }
    // Si la playlist no es la primera, buscarla en la lista
    else
    {                                        // Si el primer elemento no coincide con el id de la playlist que se va a eliminar
        PlayList *prevSong = playList;       // Se crea un puntero que apunta al primer elemento de la lista
        PlayList *currSong = playList->next; // Se crea otro puntero que apunta al segundo elemento de la lista
        while (currSong != nullptr && currSong->id != id)
        {                              // Se recorre la lista hasta encontrar el elemento que coincide con el id de la playlist o llegar al final de la lista
            prevSong = currSong;       // Se actualiza el puntero previo al elemento actual
            currSong = currSong->next; // Se actualiza el puntero al elemento actual
        }
        if (currSong != nullptr)
        {                                    // Si se encontró un elemento que coincide con el id de la playlist
            prevSong->next = currSong->next; // Se actualiza el puntero del elemento anterior para saltar el elemento actual
            delete currSong;                 // Se elimina el elemento actual
        }
    }
}
// Actualizar playlist

void listarPlaylistCancion(PlayList *&playlists, ListSongs *&listSongs)
{
    int opcion = -1;
    int idPlaylist;

    while (opcion != 0)
    {
        cout << "1.Listar playlist" << endl;
        cout << "2.Listar canciones de la playlist" << endl;
        cout << "0.Regresar" << endl;
        cin >> opcion;

        while (cin.fail() || opcion < 0 || opcion > 2)
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Opcion invalida. Ingrese un valor valido: ";
            cin >> opcion;
        }

        switch (opcion)
        {
        case 1:
            // LISTAR PLAYLIST
            if (playlists != nullptr)
            {
                cout << "LISTA DE PLAYLIST" << endl;
                PlayList *temp = playlists;
                while (temp != nullptr)
                {
                    cout << "Nombre de la playlist: " << temp->name << "\nDescripcion: " << temp->description << endl;
                    temp = temp->next;
                }
            }
            else
            {
                cout << "No existen playlist creadas, cree playlist 🎵" << endl;
            }

            break;

        case 2:
            // LISTAR LAS CANCIONES DE LA PLAY LIST

            if (playlists != nullptr)
            {
                cout << "LISTA DE PLAYLIST" << endl;
                PlayList *temp = playlists;
                while (temp != nullptr)
                {
                    cout << "Nombre de la playlist: " << temp->name << "\nDescripcion: " << temp->description << "\nId: " << temp->id << endl;
                    temp = temp->next;
                }

                cout << "Ingrese el id de la playlist que desea listar canciones: " << endl;
                cin >> idPlaylist;
                temp = playlists; // inicializar playlist desde el principio
                while (temp != nullptr && temp->id != idPlaylist)
                {

                    temp = temp->next; // buscando playlist
                }

                if (temp == nullptr) // verificamos si encontro playlist
                {
                    cout << "Playlist no encontrada" << endl;
                    return; // acabar la ejecucion no seguir
                }

                cout << "Nombre de la playlist: " << temp->name << endl;
                ListSongs *listplaylist = temp->listSongs;

                while (listplaylist != nullptr)
                {
                    cout << "Canciones de la playlist: " << listplaylist->song->name << "" << endl;
                    listplaylist = listplaylist->next; // se actualiza cancionActual al siguiente nodo de la lista
                }
            }
            else
            {
                cout << "No existen playlist creadas, cree playlist 🎵" << endl;
            }

            break;

            break;

        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    }
}
