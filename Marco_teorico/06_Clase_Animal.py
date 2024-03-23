#Se crea una clase Animal la cual recibira el nombre del mismo
class Animal:
    def __init__(self, nombre):
        self.nombre = nombre

    def hacer_sonido(self):
        pass

#Se crean otras dos clases que heredan el atributo
class Perro(Animal):
    def hacer_sonido(self):
        print("Deberiamos invadir Polonia")

class Gato(Animal):
    def hacer_sonido(self):
        print("Si, la verdad que si")

#Se crean los objetos
a = Perro("Waos")
b = Gato("Si")

a.hacer_sonido()
b.hacer_sonido()