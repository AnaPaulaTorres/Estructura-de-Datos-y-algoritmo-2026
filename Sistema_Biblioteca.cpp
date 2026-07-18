#include <iostream>
#include <string>
using namespace std;

struct Libro
{
    string codigo;
    string titulo;
    string autor;
    int stock;
};

struct Usuario
{
    string codigo;
    string nombre;
};

Libro libros[100];
Usuario usuarios[100];

int totalLibros = 0;
int totalUsuarios = 0;

void registrarLibro()
{
    string codigo;
    bool existe = false;

    cout << "\n=== REGISTRAR LIBRO ===\n";

    cout << "Codigo: ";
    cin >> codigo;

    for(int i = 0; i < totalLibros; i++)
    {
        if(libros[i].codigo == codigo)
        {
            existe = true;
        }
    }

    if(existe)
    {
        cout << "\nERROR: El codigo ya existe.\n";
        return;
    }

    libros[totalLibros].codigo = codigo;

    cin.ignore();

    cout << "Titulo: ";
    getline(cin, libros[totalLibros].titulo);

    if(libros[totalLibros].titulo.empty())
    {
        cout << "\nERROR: Titulo vacio.\n";
        return;
    }

    cout << "Autor: ";
    getline(cin, libros[totalLibros].autor);

    cout << "Stock: ";
    cin >> libros[totalLibros].stock;

    if(libros[totalLibros].stock < 0)
    {
        cout << "\nERROR: Stock invalido.\n";
        return;
    }

    totalLibros++;

    cout << "\nLibro registrado correctamente.\n";
}

void buscarLibro()
{
    string codigo;
    bool encontrado = false;

    cout << "\nIngrese codigo del libro: ";
    cin >> codigo;

    for(int i = 0; i < totalLibros; i++)
    {
        if(libros[i].codigo == codigo)
        {
            cout << "\n===== LIBRO ENCONTRADO =====\n";
            cout << "Codigo: " << libros[i].codigo << endl;
            cout << "Titulo: " << libros[i].titulo << endl;
            cout << "Autor : " << libros[i].autor << endl;
            cout << "Stock : " << libros[i].stock << endl;

            encontrado = true;
            break;
        }
    }

    if(!encontrado)
    {
        cout << "\nLibro no encontrado.\n";
    }
}

void registrarUsuario()
{
    string codigo;
    bool existe = false;

    cout << "\n=== REGISTRAR USUARIO ===\n";

    cout << "Codigo: ";
    cin >> codigo;

    for(int i = 0; i < totalUsuarios; i++)
    {
        if(usuarios[i].codigo == codigo)
        {
            existe = true;
        }
    }

    if(existe)
    {
        cout << "\nERROR: Usuario ya registrado.\n";
        return;
    }

    usuarios[totalUsuarios].codigo = codigo;

    cin.ignore();

    cout << "Nombre: ";
    getline(cin, usuarios[totalUsuarios].nombre);

    if(usuarios[totalUsuarios].nombre.empty())
    {
        cout << "\nERROR: Nombre vacio.\n";
        return;
    }

    totalUsuarios++;

    cout << "\nUsuario registrado correctamente.\n";
}

void registrarPrestamo()
{
    string codigo;

    cout << "\nCodigo del libro: ";
    cin >> codigo;

    for(int i = 0; i < totalLibros; i++)
    {
        if(libros[i].codigo == codigo)
        {
            if(libros[i].stock <= 0)
            {
                cout << "\nERROR: No hay stock disponible.\n";
                return;
            }

            libros[i].stock--;

            cout << "\nPrestamo realizado correctamente.\n";
            cout << "Stock actual: "
                 << libros[i].stock
                 << endl;

            return;
        }
    }

    cout << "\nLibro no encontrado.\n";
}

void mostrarCatalogo()
{
    if(totalLibros == 0)
    {
        cout << "\nNo existen libros registrados.\n";
        return;
    }

    cout << "\n===== CATALOGO =====\n";

    for(int i = 0; i < totalLibros; i++)
    {
        cout << "\nCodigo: " << libros[i].codigo;
        cout << "\nTitulo: " << libros[i].titulo;
        cout << "\nAutor : " << libros[i].autor;
        cout << "\nStock : " << libros[i].stock;
        cout << "\n----------------------";
    }

    cout << endl;
}

int main()
{
    int opcion;

    do
    {
        cout << "\n\n================================";
        cout << "\n SISTEMA DE BIBLIOTECA";
        cout << "\n================================";

        cout << "\n1. Registrar Libro";
        cout << "\n2. Buscar Libro";
        cout << "\n3. Registrar Usuario";
        cout << "\n4. Registrar Prestamo";
        cout << "\n5. Mostrar Catalogo";
        cout << "\n0. Salir";

        cout << "\n\nOpcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                registrarLibro();
                break;

            case 2:
                buscarLibro();
                break;

            case 3:
                registrarUsuario();
                break;

            case 4:
                registrarPrestamo();
                break;

            case 5:
                mostrarCatalogo();
                break;

            case 0:
                cout << "\nFin del programa.\n";
                break;

            default:
                cout << "\nOpcion invalida.\n";
        }

    } while(opcion != 0);

    return 0;
}
