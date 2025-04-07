#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Estructura para representar un producto
struct Producto {
    string nombre;
    float precio;
    int cantidad;
};

// Prototipos de funciones
void mostrarMenu();
void agregarProducto(Producto inventario[], int& contador);
void mostrarInventario(Producto inventario[], int contador);

int main() {
    Producto inventario[5]; // Arreglo de 5 productos
    int opcion;
    int contador = 0; // Contador de productos agregados

    do {
        mostrarMenu();
        cin >> opcion;

        // Limpiar el buffer de entrada
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                if (contador < 5) {
                    agregarProducto(inventario, contador);
                } else {
                    cout << "Inventario lleno. No se pueden agregar mas productos." << endl;
                }
                break;
            case 2:
                mostrarInventario(inventario, contador);
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }

        cout << "\nPresione Enter para continuar...";
        cin.get();

    } while (opcion != 0);

    return 0;
}

void mostrarMenu() {
    cout << "\n===== INVENTARIO DE ABARROTES =====" << endl;
    cout << "1. Agregar producto" << endl;
    cout << "2. Mostrar inventario" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opcion: ";
}

void agregarProducto(Producto inventario[], int& contador) {
    cout << "\n--- AGREGAR PRODUCTO ---" << endl;

    cout << "Nombre del producto: ";
    getline(cin, inventario[contador].nombre);

    cout << "Precio del producto: Q.";
    cin >> inventario[contador].precio;

    cout << "Cantidad en existencia: ";
    cin >> inventario[contador].cantidad;

    // Limpiar buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nProducto agregado exitosamente!" << endl;
    contador++;
}

void mostrarInventario(Producto inventario[], int contador) {
    cout << "\n--- INVENTARIO ACTUAL ---" << endl;
    cout << "----------------------------------------" << endl;
    cout << "| Nombre              | Precio  | Cant |" << endl;
    cout << "----------------------------------------" << endl;

    if (contador == 0) {
        cout << "No hay productos en el inventario." << endl;
    } else {
        for (int i = 0; i < contador; i++) {
            cout << "| " << inventario[i].nombre;
            // Espacios para alinear la tabla
            for (int j = 0; j < 20 - inventario[i].nombre.length(); j++) {
                cout << " ";
            }

            cout << "| Q." << inventario[i].precio;
            // Espacios para alinear la tabla
            string precioStr = to_string((int)inventario[i].precio);
            for (int j = 0; j < 7 - precioStr.length(); j++) {
                cout << " ";
            }

            cout << "| " << inventario[i].cantidad;
            // Espacios para alinear la tabla
            string cantidadStr = to_string(inventario[i].cantidad);
            for (int j = 0; j < 4 - cantidadStr.length(); j++) {
                cout << " ";
            }

            cout << " |" << endl;
        }
    }

    cout << "----------------------------------------" << endl;
}