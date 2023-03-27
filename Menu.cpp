#include <iostream>
using namespace std;

/* FUNCIONES */
void menu();
void OperacionesCanciones();

int main()
{
    int opcion = -1;

    while (opcion != 0)
    {
        menu();
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
            OperacionesCanciones();
            break;
        case 2:
            cout << "Operaciones de Playlist" << endl;
            break;
        case 3:
            cout << "Reproduccion" << endl;
            break;
        case 4:
            cout << "Carga masiva" << endl;
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
        }
    }

    return 0;
}

void menu()
{
    cout << "\n-- MENU --\n";
    cout << "1. Operaciones de canciones\n";
    cout << "2. Operaciones de Playlist\n";
    cout << "3. Reproduccion\n";
    cout << "4. Carga masiva\n";
    cout << "0. Salir\n";
}

void OperacionesCanciones()
{
    int opcion = -1;
    while (opcion != 0)
    {
        cout << "\n-- Operaciones de Canciones --\n";
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