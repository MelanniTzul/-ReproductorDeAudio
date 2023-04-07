#include <iostream>
#include <string>
using namespace std;

//Struct Song
struct Song
{
    string name;
    string path;//ruta
    int id;
    Song *next;
};

//Funcion que permite insercion de nuevas canciones a una lista enlazada 
void addSong(Song *&head, string name, string path,int id)
{
    Song *newSong = new Song();
    newSong->name = name;
    newSong->path = path;
    newSong->id=id;
    newSong->next = nullptr;
    if (head == nullptr)
    {
        head = newSong;
    }
    else
    {
        Song *currSong = head;
        while (currSong->next != nullptr)
        {
            currSong = currSong->next;
        }
        currSong->next = newSong;
    }
}

//Funcion que imprime las canciones de la lista
void ListSongs(Song * playlist){
    Song* currSong = playlist;
    while (currSong != nullptr) {
        cout << "Cancion: " << currSong->name << endl;
        cout << "Path: " << currSong->path << endl;
        cout << "ID: " << currSong->id << endl;
        cout <<"\n"<<endl;
        currSong = currSong->next;
    }
}   


/*FUNCION QUE ME ELIMINA UNA CANCION POR ID*/
void deleteSongId(Song *&head, int id) {
    //verificar si la lista esta vacia
    if (head == nullptr) {
        return;// Si la lista está vacía, simplemente retorna sin hacer nada
    } 
    // Si la primera canción de la lista coincide con el id, eliminarla
    else if (head->id == id) { // Verifica si el primer elemento de la lista coincide con el id de la canción que se va a eliminar
        Song *temp = head;// Si coincide, se crea un puntero temporal que apunta a la cabeza de la lista
        head = head->next;// Se actualiza la cabeza de la lista para que apunte al segundo elemento
        delete temp;// Se elimina el primer elemento utilizando el puntero temporal
    } 
     // Si la canción no es la primera, buscarla en la lista
    else {// Si el primer elemento no coincide con el id de la canción que se va a eliminar
        Song *prevSong = head;// Se crea un puntero que apunta al primer elemento de la lista
        Song *currSong = head->next;// Se crea otro puntero que apunta al segundo elemento de la lista
        while (currSong != nullptr && currSong->id != id) {// Se recorre la lista hasta encontrar el elemento que coincide con el id de la canción o llegar al final de la lista
            prevSong = currSong;// Se actualiza el puntero previo al elemento actual
            currSong = currSong->next;// Se actualiza el puntero al elemento actual
        }
        if (currSong != nullptr) {// Si se encontró un elemento que coincide con el id de la canción
            prevSong->next = currSong->next;// Se actualiza el puntero del elemento anterior para saltar el elemento actual
            delete currSong;// Se elimina el elemento actual
        }
    }
}


/*FUNCION QUE ME ELIMINA UNA CANCION POR NAME*/
void deleteSongName(Song *&head, string name) {
    //verificar si la lista esta vacia
    if (head == nullptr) {
        return;// Si la lista está vacía, simplemente retorna sin hacer nada
    } 
    // Si la primera canción de la lista coincide con el nombre, eliminarla
    else if (head->name == name) { // Verifica si el primer elemento de la lista coincide con el nombre de la canción que se va a eliminar
        Song *temp = head;// Si coincide, se crea un puntero temporal que apunta a la cabeza de la lista
        head = head->next;// Se actualiza la cabeza de la lista para que apunte al segundo elemento
        delete temp;// Se elimina el primer elemento utilizando el puntero temporal
    } 
     // Si la canción no es la primera, buscarla en la lista
    else {// Si el primer elemento no coincide con el nombre de la canción que se va a eliminar
        Song *prevSong = head;// Se crea un puntero que apunta al primer elemento de la lista
        Song *currSong = head->next;// Se crea otro puntero que apunta al segundo elemento de la lista
        while (currSong != nullptr && currSong->name!=name) {// Se recorre la lista hasta encontrar el elemento que coincide con el id de la canción o llegar al final de la lista
            prevSong = currSong;// Se actualiza el puntero previo al elemento actual
            currSong = currSong->next;// Se actualiza el puntero al elemento actual
        }
        if (currSong != nullptr) {// Si se encontró un elemento que coincide con el name de la canción
            prevSong->next = currSong->next;// Se actualiza el puntero del elemento anterior para saltar el elemento actual
            delete currSong;// Se elimina el elemento actual
        }
    }
}




/*



Song* searchSong(Song *head, string name) {
    Song *currSong = head;
    while (currSong != NULL) {
        if (currSong->name == name) {
            return currSong;
        }
        currSong = currSong->next;
    }
    return NULL;
}

*/
