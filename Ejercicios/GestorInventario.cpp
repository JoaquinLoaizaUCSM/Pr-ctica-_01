#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Cliente {
private:
    int idCliente;
    string telefono;

public:
    string nombre;

    Cliente(int idCliente=01, string nombre="", string telefono="1234567890")
    {
        this->idCliente = idCliente;
        this->nombre = nombre;
        this->telefono = telefono;
    }

    void mostrarCliente()
    {
        cout << "ID: " << idCliente
             << ", Nombre: " << nombre
             << ", Telefono: " << telefono << endl;
    }
};


class Producto{
public:
    string nombre;
    string descripsion;
    int cantidad;
    int precio;

    Producto(string nombre="",string descripsion="", int cantidad=0, double precio=0)
    {
        this->nombre= nombre;
        this->descripsion= descripsion;
        this->cantidad= cantidad;
        this->precio = precio;
    }

    void mostrarProducto()
    {
        cout << "Nombre: " << nombre
             << ", Cantidad: " << cantidad
             << ", Precio: " << precio << endl;
    }
};

class Pedido{
public:
    Cliente cliente;
    Producto producto;

    Pedido(Cliente cliente, Producto producto)
    {
        this->cliente = cliente;
        this->producto = producto;
    }
    void mostrarPedido()
    {
        cout << "Cliente: " << cliente.nombre
             << ", Producto: " << producto.nombre;
    }
};

class Registro{
public:
    // Atributos del registro
    vector<Producto> inventario;
    vector<Pedido> pedidos;
    vector<Producto> ventas;

    void agregarProducto(Producto p)
    {
        inventario.push_back(p);        // Agregar el producto al inventario
    }

    void agregarProductos(vector<Producto> productos)
    {
        for (Producto p : productos) {
            inventario.push_back(p);
        }
    }

    void eliminarProducto(string nombre)
    {
        for (int i = 0; i < inventario.size(); i++)
        {
            if (inventario[i].nombre == nombre)
            {
                inventario.erase(inventario.begin() + i);
            }
        }
    }

    Producto buscarProducto(string nombre)
    {
        for (Producto p : inventario)
        {
            if (p.nombre == nombre)
            {
                return p;
            }
        }
    }

    void mostrarProductos()
    {
        cout << "Productos disponibles" << endl;

        cout << setiosflags(ios::left)
             << setw(20)
             << "Nombre" << setw(20)
             << "Cantidad" << setw(20)
             << "Precio" << endl;
        cout << "------------------------------------------------------------\n";
        for (Producto producto : inventario) {
            cout << setw(20) << producto.nombre
                 << setw(20) << producto.cantidad
                 << setw(20) << producto.precio << endl;
        }
    }

    void hacerPedido(Pedido p)
    {
        pedidos.push_back(p);          // Agregar el pedido a la lista de pedidos
    }

    void registrarVentas()
    {
        for (Pedido pedido : pedidos)
        {
            ventas.push_back(pedido.producto);
        }

        for (Producto producto : ventas)
        {
            for (int i = 0; i < inventario.size(); i++)
            {
                if (producto.nombre == inventario[i].nombre)
                {
                    inventario[i].cantidad --;
                }
            }
        }

        pedidos.clear();            // Limpiar la lista de pedidos

    }

    void mostrarVentas()
    {
        cout << "Reporte de Ventas:\n";
        for (Producto producto : ventas)
        {
            cout << producto.nombre << ": " << producto.precio << "\n";
        }
    }

};


void realizarCompra(Registro& registro, Cliente& cliente) {
    string nombreProducto;
    bool opcion = true;

    while (opcion)
    {
        cout << "Ingrese el nombre del producto que desea comprar:" << endl;
        cin.ignore();       // Eliminar el salto de línea
        getline(cin, nombreProducto);       // Leer el nombre del producto

        Producto producto = registro.buscarProducto(nombreProducto);
        registro.hacerPedido(Pedido(cliente, producto));

        cout << "Desea comprar otro producto? (1: Si, 0: No)" << endl;
        cin >> opcion;
    }
}

void menuCliente(Registro registro) {
    Cliente cliente = Cliente(01, "Perez", "1234567890");
    cout << "Bienvenido cliente" << endl;
    cout << "Cliente: " << cliente.nombre << endl;

    registro.mostrarProductos();
    realizarCompra(registro, cliente);

    registro.registrarVentas();
    cout << "Compra realizada con exito." << endl;

}

Producto get_producto() {
    string nombre, descripcion;
    int cantidad;
    double precio;

    cout << "Ingrese el nombre del producto:" << endl;
    cin.ignore();    // Eliminar el salto de linea
    getline(cin, nombre);

    cout << "Ingrese la descripcion del producto:" << endl;
    getline(cin, descripcion);

    cout << "Ingrese la cantidad del producto:" << endl;
    cin >> cantidad;

    cout << "Ingrese el precio del producto:" << endl;
    cin >> precio;

    return  Producto(nombre, descripcion, cantidad, precio);
}

void eliminarProducto(Registro& registro) {
    string nombreProducto;

    cout << "Ingrese el nombre del producto que desea eliminar:" << endl;
    cin.ignore();   // Eliminar el salto de linea
    getline(cin, nombreProducto);

    registro.eliminarProducto(nombreProducto);
}

void menuAdministrador(Registro registro) {
    int selectCantidad;

    while (true)
    {
        cout << "Bienvenido administrador" << endl;
        cout << "1) Agregar producto" << endl
             << "2) Eliminar producto" << endl
             << "3) Mostrar productos" << endl
             << "4) Mostar ventas" << endl
             << "5) Salir" << endl;
        cin >> selectCantidad;

        switch (selectCantidad) {
            case 1:
                registro.agregarProducto(get_producto());
                break;
            case 2:
                eliminarProducto(registro);
                break;
            case 3:
                registro.mostrarProductos();
                break;
            case 4:
                registro.mostrarVentas();
                break;
            case 5:
                return;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
        }
    }
}

vector<Producto> listaProductos = {
        Producto("Coca Cola", "Refresco de cola", 10, 1.5),
        Producto("Pepsi", "Refresco de cola", 10, 1.5),
        Producto("Sprite", "Refresco de limon", 10, 1.5),
        Producto("Fanta", "Refresco de naranja", 10, 1.5),
        Producto("Agua", "Agua natural", 10, 1.0),
        Producto("Agua de sabor", "Agua de sabor", 10, 1.5),
        Producto("Cerveza", "Cerveza", 10, 2.5)
};



int main() {
    int permiso;

    Registro tienda;
    tienda.agregarProductos(listaProductos);      // Agrego los productos del contenedor

    /*Inicio de la aplicación
    EL cliente solo puede pedir los productos y comprar
    El administrador puede Agregar los productos, eliminar productos, mostrar productos y mostrar ventas
    */
    cout << "Bienvenido al sistema sistema" << endl;
    cout << "1) Cliente" << endl
         << "2) Administrador" << endl;
    cin >> permiso;

    if (permiso == 1)
    {
        menuCliente(tienda);
    }
    else if (permiso == 2)
    {
        menuAdministrador(tienda);
    }
    else
    {
        cout << "Opcion no valida. Intente nuevamente." << endl;
    }
}