#include <iostream>
using namespace std;

// Función para mostrar el conjunto
void mostrarConjunto(int conjunto[], int tam) {
    cout << "{ ";
    for (int i = 0; i < tam; i++) {
        cout << conjunto[i] << " ";
    }
    cout << "}" << endl;
}

// Función para ingresar un conjunto de números
void ingresarConjunto(int conjunto[], int &tam) {
    cout << "Ingrese el tamaño del conjunto: ";
    cin >> tam;
    for (int i = 0; i < tam; i++) {
        cout << "Ingrese elemento " << i + 1 << ": ";
        cin >> conjunto[i];
    }
}

// Función para obtener la unión de dos conjuntos ingresados por el usuario
void unionConjuntos(int A[], int tamA, int B[], int tamB, int resultado[], int &tamR) {
    tamR = 0;
    for (int i = 0; i < tamA; i++) {
        bool encontrado = false;
        for (int j = 0; j < tamR; j++) {
            if (resultado[j] == A[i]) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            resultado[tamR] = A[i];
            tamR++;
        }
    }
    for (int i = 0; i < tamB; i++) {
        bool encontrado = false;
        for (int j = 0; j < tamR; j++) {
            if (resultado[j] == B[i]) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            resultado[tamR] = B[i];
            tamR++;
        }
    }
}

// Función para obtener la intersección de dos conjuntos ingresados por el usuario
void interseccionConjuntos(int A[], int tamA, int B[], int tamB, int resultado[], int &tamR) {
    tamR = 0;
    for (int i = 0; i < tamA; i++) {
        for (int j = 0; j < tamB; j++) {
            if (A[i] == B[j]) {
                bool encontrado = false;
                for (int k = 0; k < tamR; k++) {
                    if (resultado[k] == A[i]) {
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    resultado[tamR] = A[i];
                    tamR++;
                }
            }
        }
    }
}

// Función para calcular el MCD de dos números
int mcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Clase para representar un nodo en un árbol binario
struct Nodo {
    int valor;
    Nodo *izq, *der;
    Nodo(int v) : valor(v), izq(nullptr), der(nullptr) {}
};

// Función para crear un árbol binario interactivo
Nodo* crearArbol() {
    int valor;
    cout << "Ingrese el valor del nodo (o -1 para no agregar): ";
    cin >> valor;

    if (valor == -1)
        return nullptr;

    Nodo* nuevoNodo = new Nodo(valor);
    cout << "Agregando hijo izquierdo de " << valor << endl;
    nuevoNodo->izq = crearArbol();
    cout << "Agregando hijo derecho de " << valor << endl;
    nuevoNodo->der = crearArbol();

    return nuevoNodo;
}

// Función para mostrar el árbol binario en preorden
void mostrarPreorden(Nodo* nodo) {
    if (nodo != nullptr) {
        cout << nodo->valor << " ";
        mostrarPreorden(nodo->izq);
        mostrarPreorden(nodo->der);
    }
}

// Función para mostrar el árbol binario en inorden
void mostrarInorden(Nodo* nodo) {
    if (nodo != nullptr) {
        mostrarInorden(nodo->izq);
        cout << nodo->valor << " ";
        mostrarInorden(nodo->der);
    }
}

// Función para mostrar el árbol binario en postorden
void mostrarPostorden(Nodo* nodo) {
    if (nodo != nullptr) {
        mostrarPostorden(nodo->izq);
        mostrarPostorden(nodo->der);
        cout << nodo->valor << " ";
    }
}

int main() {
    int A[10], B[10];
    int resultado[20];   
    int tamA, tamB, tamR;         
    int opcion;
    Nodo* raiz = nullptr; // Nodo raíz para el árbol binario

    do {
        cout << "\n--- Menú de Operaciones ---" << endl;
        cout << "1. Unión de conjuntos" << endl;
        cout << "2. Intersección de conjuntos" << endl;
        cout << "3. Calcular el MCD de dos números" << endl;
        cout << "4. Crear árbol binario" << endl;
        cout << "5. Mostrar árbol binario en preorden" << endl;
        cout << "6. Mostrar árbol binario en inorden" << endl;
        cout << "7. Mostrar árbol binario en postorden" << endl;
        cout << "8. Salir" << endl;
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el primer conjunto:" << endl;
                ingresarConjunto(A, tamA);
                cout << "Ingrese el segundo conjunto:" << endl;
                ingresarConjunto(B, tamB);
                unionConjuntos(A, tamA, B, tamB, resultado, tamR);
                cout << "Unión: ";
                mostrarConjunto(resultado, tamR);
                break;
            case 2:
                cout << "Ingrese el primer conjunto:" << endl;
                ingresarConjunto(A, tamA);
                cout << "Ingrese el segundo conjunto:" << endl;
                ingresarConjunto(B, tamB);
                interseccionConjuntos(A, tamA, B, tamB, resultado, tamR);
                cout << "Intersección: ";
                mostrarConjunto(resultado, tamR);
                break;
            case 3: {
                int num1, num2;
                cout << "Ingrese el primer número: ";
                cin >> num1;
                cout << "Ingrese el segundo número: ";
                cin >> num2;
                cout << "El MCD de " << num1 << " y " << num2 << " es: " << mcd(num1, num2) << endl;
                break;
            }
            case 4:
                cout << "Creando árbol binario:" << endl;
                raiz = crearArbol();
                break;
            case 5:
                if (raiz != nullptr) {
                    cout << "Árbol Binario (Preorden): ";
                    mostrarPreorden(raiz);
                    cout << endl;
                } else {
                    cout << "Primero debe crear el árbol binario." << endl;
                }
                break;
            case 6:
                if (raiz != nullptr) {
                    cout << "Árbol Binario (Inorden): ";
                    mostrarInorden(raiz);
                    cout << endl;
                } else {
                    cout << "Primero debe crear el árbol binario." << endl;
                }
                break;
            case 7:
                if (raiz != nullptr) {
                    cout << "Árbol Binario (Postorden): ";
                    mostrarPostorden(raiz);
                    cout << endl;
                } else {
                    cout << "Primero debe crear el árbol binario." << endl;
                }
                break;
            case 8:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Inténtalo de nuevo." << endl;
        }
    } while (opcion != 8);

    return 0;
}