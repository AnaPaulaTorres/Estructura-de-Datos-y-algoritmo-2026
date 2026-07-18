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
    try
    {
        string codigo, titulo, autor;
        int stock;

        cout << "\n===== REGISTRAR LIBRO =====\n";

        cout << "Codigo: ";
        cin >> codigo;

        for(int i = 0; i < totalLibros; i++)
        {
            if(libros[i].codigo == codigo)
            {
                throw "El codigo ya existe";
            }
        }

        cin.ignore();

        cout << "Titulo: ";
        getline(cin, titulo);

        if(titulo.empty())
        {
            throw "El titulo no puede estar vacio";
        }

        cout << "Autor: ";
        getline(cin, autor);

        cout << "Stock: ";
        cin >> stock;

        if(stock < 0)
        {
            throw "El stock no puede ser negativo";
        }

        libros[totalLibros].codigo = codigo;
        libros[totalLibros].titulo = titulo;
        libros[totalLibros].autor = autor;
        libros[totalLibros].stock = stock;

        totalLibros++;

        cout << "\nLibro registrado correctamente.\n";
    }
    catch(const char* mensaje)
    {
        cout << "\nERROR: " << mensaje << endl;
    }
}

void buscarLibro()
{
    try
    {
        string codigo;

        cout << "\nIngrese codigo del libro: ";
        cin >> codigo;

        bool encontrado = false;

        for(int i = 0; i < totalLibros; i++)
        {
            if(libros[i].codigo == codigo)
            {
                cout << "\n===== LIBRO ENCONTRADO =====\n";
                cout << "Codigo : " << libros[i].codigo << endl;
                cout << "Titulo : " << libros[i].titulo << endl;
                cout << "Autor  : " << libros[i].autor << endl;
                cout << "Stock  : " << libros[i].stock << endl;

                encontrado = true;
                break;
            }
        }

        if(!encontrado)
        {
            throw "Libro no encontrado";
        }
    }
    catch(const char* mensaje)
    {
        cout << "\nERROR: " << mensaje << endl;
    }
}

void registrarUsuario()
{
    try
    {
        string codigo;
        string nombre;

        cout << "\n===== REGISTRAR USUARIO =====\n";

        cout << "Codigo: ";
        cin >> codigo;

        for(int i = 0; i < totalUsuarios; i++)
        {
            if(usuarios[i].codigo == codigo)
            {
                throw "Usuario ya registrado";
            }
        }

        cin.ignore();

        cout << "Nombre: ";
        getline(cin, nombre);

        if(nombre.empty())
        {
            throw "El nombre no puede estar vacio";
        }

        usuarios[totalUsuarios].codigo = codigo;
        usuarios[totalUsuarios].nombre = nombre;

        totalUsuarios++;

        cout << "\nUsuario registrado correctamente.\n";
    }
    catch(const char* mensaje)
    {
        cout << "\nERROR: " << mensaje << endl;
    }
}

void registrarPrestamo()
{
    try
    {
        string codigo;

        cout << "\nCodigo del libro: ";
        cin >> codigo;

        bool encontrado = false;

        for(int i = 0; i < totalLibros; i++)
        {
            if(libros[i].codigo == codigo)
            {
                encontrado = true;

                if(libros[i].stock <= 0)
                {
                    throw "No hay stock disponible";
                }

                libros[i].stock--;

                cout << "\nPrestamo registrado correctamente.\n";
                cout << "Stock actual: "
                     << libros[i].stock
                     << endl;

                break;
            }
        }

        if(!encontrado)
        {
            throw "Libro no encontrado";
        }
    }
    catch(const char* mensaje)
    {
        cout << "\nERROR: " << mensaje << endl;
    }
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
        cout << "\n--------------------------";
    }

    cout << endl;
}

int main()
{
    int opcion;

    do
    {
        cout << "\n\n====================================";
        cout << "\n SISTEMA DE GESTION DE BIBLIOTECA";
        cout << "\n====================================";

        cout << "\n1. Registrar Libro";
        cout << "\n2. Buscar Libro";
        cout << "\n3. Registrar Usuario";
        cout << "\n4. Registrar Prestamo";
        cout << "\n5. Mostrar Catalogo";
        cout << "\n0. Salir";

        cout << "\n\nSeleccione una opcion: ";
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
                cout << "\nPrograma finalizado.\n";
                break;

            default:
                cout << "\nOpcion invalida.\n";
        }

    } while(opcion != 0);

    return 0;
}
