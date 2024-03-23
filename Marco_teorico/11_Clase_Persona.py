class Persona:
    def __init__(self, nombre = "Desconocido", edad = 0):
        self.nombre = nombre
        self.edad = edad

    def imprimir_informacion(self):
        print("Nombre:", self.nombre)
        print("Edad:",self.edad)

#Modifique el programa para probar los valores predeterminadoso "base"
P1 = Persona()
print("--Prueba--")
P1.imprimir_informacion()

print("--Con datos--")
P1.edad = 18
P1.nombre = "Grossman"
P1.imprimir_informacion()