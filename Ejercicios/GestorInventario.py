class Producto:
    def __init__(self, nombre, descripcion, cantidad, precio):
        self.nombre = nombre
        self.descripcion = descripcion
        self.cantidad = cantidad
        self.precio = precio


class Cliente:
    def __init__(self, ID, nombre, telefono):
        self.id = ID
        self.nombre = nombre
        self.telefono = telefono


class Pedido:
    def __init__(self, cliente, producto):
        self.cliente = cliente
        self.producto = producto


class Registro:
    def __init__(self):
        self.listaProductos = []
        self.pedidos = []
        self.ventas = []
        self.reporteVentas = []

    def agregarProductos(self, productos):
        self.listaProductos.extend(productos)

    def mostrarProductos(self):
        print(
            "{:<20} {:<10} {:<10} {:<10}".format(
                "Nombre", "Cantidad", "Precio", "Descripcion"
            )
        )
        for producto in self.listaProductos:
            print(
                "{:<20} {:<10} {:<10} {:<10}".format(
                    producto.nombre,
                    producto.cantidad,
                    producto.precio,
                    producto.descripcion,
                )
            )

    def buscarProducto(self, nombreProducto):
        for producto in self.listaProductos:
            if producto.nombre == nombreProducto:
                return producto
        return None

    def hacerPedido(self, pedido):
        self.pedidos.append(pedido)
        print("Agregado al carrito.")

    def actualizarInventario(self, pedido):
        for producto in self.listaProductos:
            if producto.nombre == pedido.producto.nombre:
                producto.cantidad -= 1
                if producto.cantidad == 0:
                    self.listaProductos.remove(producto)
                return

    def registrarVentas(self):
        for pedido in self.pedidos:
            self.actualizarInventario(pedido)
            self.ventas.append(pedido)
            self.reporteVentas.append(pedido)
        self.pedidos = []

    def agregarProducto(self, producto):
        self.listaProductos.append(producto)

    def eliminarProducto(self, nombreProducto):
        self.listaProductos = [
            producto
            for producto in self.listaProductos
            if producto.nombre != nombreProducto
        ]

    def mostrarReporteVentas(self):
        total = 0
        print(
            "{:<20} {:<10} {:<10} {:<10}".format(
                "Nombre", "Cantidad", "Precio", "Descripcion"
            )
        )
        for pedido in self.reporteVentas:
            print(
                "{:<20} {:<10} s/{:<10} {:<10}".format(
                    pedido.producto.nombre,
                    1,
                    pedido.producto.precio,
                    pedido.producto.descripcion,
                )
            )
            total += pedido.producto.precio
        print(f"Total: s/{total}")


def menuCliente(registro):
    registro.mostrarProductos()

    while nombreProducto := input("Ingrese el nombre del producto que desea comprar: "):
        producto = registro.buscarProducto(nombreProducto)

        if producto is not None:
            cliente = Cliente(1, "Perez", "1234567890")
            registro.hacerPedido(Pedido(cliente, producto))
        else:
            print("Producto no encontrado. Intente nuevamente.")

    registro.registrarVentas()
    print("Compra realizada con exito.")

    registro.mostrarReporteVentas()

    input("Presione cualquier boton para continuar")
    menuPrincipal(registro)


def menuAdministrador(registro):
    while True:
        print("1) Agregar producto")
        print("2) Eliminar producto")
        print("3) Mostrar productos")
        print("4) Mostrar reporte de ventas")
        print("5) Regresar")

        selectCantidad = int(input())

        if selectCantidad == 1:
            nombre = input("Ingrese el nombre del producto: ")
            descripcion = input("Ingrese la descripcion del producto: ")
            cantidad = int(input("Ingrese la cantidad del producto: "))
            precio = float(input("Ingrese el precio del producto: "))
            registro.agregarProducto(Producto(nombre, descripcion, cantidad, precio))

        elif selectCantidad == 2:
            nombreProducto = input(
                "Ingrese el nombre del producto que desea eliminar: "
            )
            registro.eliminarProducto(nombreProducto)

        elif selectCantidad == 3:
            registro.mostrarProductos()

        elif selectCantidad == 4:
            registro.mostrarReporteVentas()

        elif selectCantidad == 5:
            menuPrincipal(registro)
        else:
            print("Opcion no valida. Intente nuevamente.")


def menuPrincipal(registro):
    print("Bienvenido al sistema sistema")
    print("1) Cliente")
    print("2) Administrador")
    print("3) Salir")
    permiso = int(input())

    if permiso == 1:
        menuCliente(registro)
    elif permiso == 2:
        menuAdministrador(registro)
    elif permiso == 3:
        print("Gracias por usar el sistema")
    else:
        print("Opcion no valida. Intente nuevamente.")


def main():
    registro = Registro()
    registro.agregarProductos(
        [
            Producto("CocaCola", "Refresco de cola", 10, 1.5),
            Producto("Pepsi", "Refresco de cola", 10, 1.5),
            Producto("Sprite", "Refresco de limon", 10, 1.5),
            Producto("Fanta", "Refresco de naranja", 10, 1.5),
            Producto("Agua", "Agua natural", 10, 1.0),
            Producto("Jugo", "Agua de sabor", 10, 1.5),
            Producto("Cerveza", "Cerveza", 10, 2.5),
        ]
    )

    menuPrincipal(registro)


if __name__ == "__main__":
    main()
