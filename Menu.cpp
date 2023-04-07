#include <iostream>
#include "cancion.h"
#include <limits>
using namespace std;

/* FUNCIONES */
void menuPrincipal();
void SubMenuOperacionesCanciones();
void SubMenuOperacionesPlaylist();
void SubMenuReproduccion();

int main()
{
    menuPrincipal();

    return 0;
}

void menuPrincipal()
{
    int opcion = -1;
    while (opcion != 5)
    {

        // Código de escape ANSI para cambiar el color del texto a rojo
        std::cout << "\033[31m";
        std::cout << "\n-- MENU PRINCIPAL --\n"
                  << std::endl;
        // Código de escape ANSI para restablecer el color del texto a su valor predeterminado
        std::cout << "\033[0m";
        cout << "1. Operaciones de canciones\n";
        cout << "2. Operaciones de Playlist\n";
        cout << "3. Reproduccion\n";
        cout << "4. Carga masiva\n";
        cout << "5. Salir\n";
        cout << "Ingrese la opcion: ";
        cin >> opcion;
        while (cin.fail() || opcion < 0 || opcion > 5)
        {
            cin.clear();
            cin.ignore(256, '\n'); // Limpia el buffer del teclado
            cout << "Opcion invalida. Ingrese un valor valido: ";
            cin >> opcion;
        }
        switch (opcion)
        {
        case 1:
            SubMenuOperacionesCanciones();
            break;
        case 2:
            SubMenuOperacionesPlaylist();
            break;
        case 3:
            SubMenuReproduccion();
            break;
        case 4:
            cout << "Carga masiva" << endl;
            break;
        default:
            break;
        }
    }
}

void SubMenuOperacionesCanciones()
{
    Song *playlist = nullptr; // lista de canciones
    std::string name, path;

    int cont = 0; // Variable contador para id de cada cancion
    int opcion = -1;
    int op = -1;
    string deleteNameSong = "";
    int deleteId;
    string searchName = ""; // Variable para almacenar el nombre a buscar

    while (opcion != 0)
    {
        // Código de escape ANSI para cambiar el color del texto a azul
        std::cout << "\033[34m";
        cout << "\n-- SUBMENU DE OPERACIONES DE CANCIONES--\n";
        // Código de escape ANSI para restablecer el color del texto a su valor predeterminado
        std::cout << "\033[0m";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Buscar nombre\n";
        cout << "4. Listar canciones\n";
        cout << "0. Volver al menu principal\n";
        cout << "Ingrese la opcion: ";
        cin >> opcion;
        while (cin.fail() || opcion < 0 || opcion > 4)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar hasta el siguiente carácter de nueva línea
            cout << "Opcion invalida. Ingrese un valor valido: ";
            cin >> opcion;
        }
        switch (opcion)
        {
        case 1:
            /*INSERTAR CANCIONES*/
            // Pedir al usuario que ingrese los datos de la cancion
            std::cout << "Ingrese el nombre de la cancion: ";
            std::cin.ignore(); // Agregar esta línea para limpiar el búfer de entrada (area de memoria del sistema)
            // std::cin >> name;
            std::getline(std::cin, name);

            std::cout << "Ingrese el path (ruta) de la cancion: \n";
            // std::cin >> path;
            std::getline(std::cin, path);

            // Ingresar datos a la funcion addSong
            addSong(playlist, name, path, ++cont);
            break;
        case 2:
            /*ELIMINAR CANCIONES*/
            while (op != 0)
            {
                cout << "Eliminar cancion" << endl;
                cout << " 1. Eliminar por nombre" << endl;
                cout << " 2. Eliminar por id" << endl;
                cout << "0. Regresar" << endl;
                cin >> op;

                switch (op)
                {
                case 1:
                    /*ELIMINAR POR NOMBRE*/
                    if (playlist != nullptr) // verifica si la lista esta llena
                    {
                        ListSongs(playlist);
                        cout << "Ingrese el nombre de la cancion a eliminar: " << endl;
                        cin >> deleteNameSong;
                        deleteSongName(playlist, deleteNameSong); // ELIMINAR CANCION
                    }
                    else
                    { // si no esta imprime un mensaje que esta vacia
                        cout << "La lista esta vacia, ingrese canciones" << endl;
                    }

                    break;

                case 2:
                    if (playlist != nullptr)
                    {
                        /*ELIMINAR POR ID*/
                        ListSongs(playlist); // IMPRIMIR LISTA
                        cout << "Ingrese el ID de la cancion a eliminar:" << endl;
                        cin >> deleteId;
                        deleteSongId(playlist, deleteId); // ELIMINAR CANCION
                    }
                    else
                    {
                        cout << "La lista esta vacia, ingrese canciones" << endl;
                    }
                    break;

                default:
                    cout << "Opcion no valida. Intente de nuevo." << endl;
                    break;
                }
            }

            break;
        case 3:
            if (playlist != nullptr)
            {
                cout << "Lista de canciones: " << endl;
                ListSongs(playlist);
                // Pedir al usuario el nombre de la canción a buscar
                cout << "Ingrese el nombre de la cancion a buscar: " << endl;
               // cin >> searchName;
                std::cin.ignore(); // Agregar esta línea para limpiar el búfer de entrada (area de memoria del sistema)
                std::getline(std::cin, searchName);

                // Busca la canción en la lista
                Song *cancionEncontrada = searchSong(playlist, searchName);
                if (cancionEncontrada != nullptr)
                {
                    // Si se encontró la canción, imprime su nombre y artista
                    cout << "Canción encontrada: \nCanción: " << cancionEncontrada->name << " \nPath: " << cancionEncontrada->path<< " \nId: " << cancionEncontrada->id << endl;
                }
                else
                {
                      // Si no se encontró la canción, imprime un mensaje de error
                      cout << "La canción no fue encontrada en la lista." << endl;
                }
            }

                break;
            case 4:
                if (playlist != nullptr)
                {
                    cout << "LISTA DE CANCIONES" << endl;
                    ListSongs(playlist);
                }
                else
                {
                    cout << "La lista esta vacia, ingrese canciones" << endl;
                }
                break;

            default:
                break;
            }
        }
    }

    void SubMenuOperacionesPlaylist()
    {
        int opcion = -1;
        while (opcion != 0)
        {
            // Código de escape ANSI para cambiar el color del texto a rojo
            std::cout << "\033[34m";
            cout << "\n--SUBMENU OPERACIONES DE PLAYLIST--\n";
            // Código de escape ANSI para restablecer el color del texto a su valor predeterminado
            std::cout << "\033[0m";

            cout << "1. Crear\n";
            cout << "2. Eliminar\n";
            cout << "3. Actualizar\n";
            cout << "4. Listar\n";
            cout << "5. Agregar canciones\n";
            cout << "6. Eliminar canciones\n";
            cout << "0. Volver al menu principal\n";
            cout << "Ingrese la opcion: ";
            cin >> opcion;
            while (cin.fail() || opcion < 0 || opcion > 6)
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Opcion invalida. Ingrese un valor valido: ";
                cin >> opcion;
            }
            switch (opcion)
            {
            case 1:
                cout << "Crear" << endl;
                break;
            case 2:
                cout << "Eliminar" << endl;
                break;
            case 3:
                cout << "Actualizar" << endl;
                break;
            case 4:
                cout << "Listar" << endl;
                break;

            case 5:
                cout << "Agregar canciones" << endl;
                break;

            case 6:
                cout << "Eliminar canciones" << endl;
                break;
            }
        }
    }

    void SubMenuReproduccion()
    {
        int opcion = -1;
        while (opcion != 0)
        {
            // Código de escape ANSI para cambiar el color del texto a azul
            std::cout << "\033[34m";
            cout << "\n--SUBMENU REPRODUCCION--\n";
            // Código de escape ANSI para restablecer el color del texto a su valor predeterminado
            std::cout << "\033[0m";
            cout << "1. Normal\n";
            cout << "2. Repetir\n";
            cout << "3. Siguiente\n";
            cout << "4. Anterior\n";
            cout << "5. Lista de reproducción\n";
            cout << "6. Agregar canción a la lista de reproducción\n";
            cout << "0. Volver al menu principal\n";
            cout << "Ingrese la opcion: ";
            cin >> opcion;
            while (cin.fail() || opcion < 0 || opcion > 6)
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Opcion invalida. Ingrese un valor valido: ";
                cin >> opcion;
            }
            switch (opcion)
            {
            case 1:
                cout << "Normal" << endl;
                break;
            case 2:
                cout << "Repetir" << endl;
                break;
            case 3:
                cout << "Siguiente" << endl;
                break;
            case 4:
                cout << "Anterior" << endl;
                break;

            case 5:
                cout << "Lista de reproducción" << endl;
                break;

            case 6:
                cout << "Agregar canción a la lista de reproducción" << endl;
                break;
            }
        }
    }