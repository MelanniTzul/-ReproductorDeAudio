//instalar sudo apt install libtinyxml2-dev
// g++ -o programa programa.cpp -ltinyxml2 compilar
#include "tinyxml2.h" // Incluimos la librería libtinyxml2 para la carga masiva
#include <iostream>
#include <string>

void CargaMasiva()
{
    // Abrir el archivo XML
    tinyxml2::XMLDocument doc;  // Creamos un objeto XMLDocument
    if (doc.LoadFile("archivo.xml") != tinyxml2::XML_SUCCESS) {  // Cargamos el archivo en el objeto y verificamos si hay errores
        std::cerr << "Error al cargar el archivo XML" << std::endl;  // Si hay errores, imprimimos un mensaje de error en la consola
        return;  // Salimos del programa con un código de error
    }

    // Acceder a los elementos en el archivo
    tinyxml2::XMLElement* root = doc.FirstChildElement("root");  // Obtenemos el elemento raíz del archivo XML y lo almacenamos en un puntero XMLElement*
    if (root) {  // Verificamos si se encontró el elemento raíz
        // Acceder a los elementos hijos de <root>
        for (tinyxml2::XMLElement* child = root->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
            // Procesar cada elemento hijo
            const char* nombre = child->Attribute("nombre");  // Obtenemos el valor del atributo "nombre" del elemento hijo
            const char* valor = child->GetText();  // Obtenemos el texto dentro del elemento hijo
            std::cout << "Elemento: " << nombre << " - Valor: " << valor << std::endl;  // Imprimimos el nombre y valor del elemento hijo en la consola
        }
    }

    return ;  // Salimos del programa con un código de éxito
}