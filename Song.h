#include <iostream>
#include <string>
using namespace std;

//Struct Song
struct Song
{
    string name;
    string path;//ruta
    int id;
    Song *next;//apunta a la siguiente cancion
};

/*FUNCION QUE PERMITE INSERCION DE NUEVAS CANCIONES A UNA LISTA ENLAZADA*/
// La función "addSong" agrega una nueva canción a una lista enlazada de canciones.
// Recibe cuatro parámetros:
// - Un puntero a un puntero de la estructura "Song" llamado "head", que apunta al primer nodo de la lista.
// - Una cadena "name" que representa el nombre de la nueva canción.
// - Una cadena "path" que representa la ubicación de la nueva canción en el disco.
// - Un entero "id" que representa el identificador único de la nueva canción.
void addSong(Song *&head, string name, string path,int id)
{
    // Se crea un nuevo objeto "Song" en el heap utilizando el operador "new" y se asigna a un puntero "newSong".
    Song *newSong = new Song();
    // Se asignan los valores de "name", "path" y "id" al objeto "newSong".
    newSong->name = name;
    newSong->path = path;
    newSong->id=id;
    // Se establece el campo "next" del objeto "newSong" en "nullptr", lo que indica que no hay ningún otro nodo siguiente en la lista.
    newSong->next = nullptr;
    if (head == nullptr)
    {
        head = newSong;
    }
    else
    {
        // Si el puntero "head" no es "nullptr", se recorre la lista enlazada hasta encontrar el último nodo, y se agrega el nodo "newSong" al final de la lista.
        Song *currSong = head; //currSong (cancion actual)   //// Se inicializa un puntero "currSong" al primer nodo de la lista.
        while (currSong->next != nullptr)
        {
            currSong = currSong->next;//// Se actualiza "currSong" al siguiente nodo de la lista.
        }
        currSong->next = newSong;// Se agrega "newSong" al final de la lista.
    }
}

/*FUNCION QUE LISTA LAS CANCIONES EXISTENTES EN LA LISTA*/
void ViewListSongs(Song *&playlist){
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


/*FUNCION QUE BUSCA UNA CANCION*/
Song* searchSong(Song *head, string name) {
    Song *currSong = head;// Inicializa un puntero que apunta a la cabeza de la lista de canciones
    // Recorre la lista de canciones hasta el final o hasta que se encuentre una coincidencia
    while (currSong != nullptr) {
        // Verifica si el nombre de la canción actual coincide con el nombre buscado
        if (currSong->name == name) {
            // Si se encuentra una coincidencia, devuelve un puntero a la canción actual
            return currSong;
        }
        // Si no se encuentra una coincidencia, pasa a la siguiente canción en la lista
        currSong = currSong->next;
    }
    // Si se recorre toda la lista y no se encuentra la canción buscada, devuelve NULL
    return nullptr;
}

