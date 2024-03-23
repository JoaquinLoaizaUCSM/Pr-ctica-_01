class Estudiante:
    def __init__(self, nombre, edad, carrera):
        self.nombre = nombre
        self.edad = edad
        self.carrera = carrera

    def matricularse(self, curso):
        curso.agregar_estudiante(self)

class Curso:
    def __init__(self, nombre, codigo, cupos):
        self.nombre = nombre
        self.codigo = codigo
        self.cupos = cupos
        self.estudiantes = []

    def agregar_estudiante(self, estudiante):
        if len(self.estudiantes) < self.cupos:
            self.estudiantes.append(estudiante)
            print(f"{estudiante.nombre} se ha matriculado en el curso de {self.nombre}")
        else: print(f"Lo siento, el curso {self.nombre} está lleno")

Grossman = Estudiante("Grossman", "18", "Sistemas")
Lenguajes = Curso("LP_02", "SC023",32)
Formativa = Curso("Formativa", "SC056",0)

Grossman.matricularse(Lenguajes)
Grossman.matricularse(Formativa)