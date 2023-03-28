#include <iostream>
#include "Cancion.cpp"
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
    std::cout << "Este texto es de color azul!\n";
        // Código de escape ANSI para cambiar el color del texto a rojo
        std::cout << "\033[31m";
        std::cout << "\n-- MENU PRINCIPAL --\n" << std::endl;
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
    int opcion = -1;
    while (opcion != 0)
    {
        // Código de escape ANSI para cambiar el color del texto a rojo
        std::cout << "\033[31m";
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
            cin.ignore(256, '\n');
            cout << "Opcion invalida. Ingrese un valor valido: ";
            cin >> opcion;
        }
        switch (opcion)
        {
        case 1:
            cout << "Insertar" << endl;
            break;
        case 2:
            cout << "Eliminar" << endl;
            break;
        case 3:
            cout << "Buscar nombre" << endl;
            break;
        case 4:
            cout << "Listar canciones" << endl;
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
        std::cout << "\033[31m";
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
        // Código de escape ANSI para cambiar el color del texto a rojo
        std::cout << "\033[31m";
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