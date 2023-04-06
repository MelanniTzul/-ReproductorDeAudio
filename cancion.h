#include <iostream>
#include <string>
using namespace std;

struct Song
{
    string name;
    string path;//ruta
    int id;
    Song *next;
};


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


void ListSongs(Song * playlist){
    // Imprime las canciones de la lista
    Song* currSong = playlist;
    while (currSong != nullptr) {
        cout << "Cancion: " << currSong->name << endl;
        cout << "Path: " << currSong->path << endl;
        cout << "ID: " << currSong->id << endl << endl;
        currSong = currSong->next;
    }
}   


/*
void deleteSong(Song *&head, string name) {
    if (head == NULL) {
        return;
    } else if (head->name == name) {
        Song *temp = head;
        head = head->next;
        delete temp;
    } else {
        Song *prevSong = head;
        Song *currSong = head->next;
        while (currSong != NULL && currSong->name != name) {
            prevSong = currSong;
            currSong = currSong->next;
        }
        if (currSong != NULL) {
            prevSong->next = currSong->next;
            delete currSong;
        }
    }
}

void listSongs(Song *head) {
    if (head == NULL) {
        cout << "No songs found." << endl;
    } else {
        Song *currSong = head;
        while (currSong != NULL) {
            cout << currSong->name << " - " << currSong->artist << endl;
            currSong = currSong->next;
        }
    }
}

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
