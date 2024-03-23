// Sirve para ahorrar el trabajo de poner el System
import static java.lang.System.out;

//Todo debe estar en un main para que el IDE ejecute
public class Main_Persona {

    public static void main(String[] args){
        Persona Grossman = new Persona("Grossman",18);
        Grossman.saludar();
        //Aqui se hereda el metodo saludar xd
        Estudiante Grossman_estudent = new Estudiante("Grossman",18,"Sistemas");
        Grossman_estudent.saludar();
        Grossman_estudent.estudiar();
    }
    public static class Persona {
        public String nombre;
        private int edad;

        public Persona(String nombre, int edad) {
            this.nombre = nombre;
            this.edad = edad;
        }

        public void saludar() {
            out.println("Hola me llamo " + nombre + " y tengo " + edad + " años.");
        }

    }

    public static class Estudiante extends Persona{
        private String carrera;

        public Estudiante(String nombre, int edad, String carrera){
            //Supongo que esto es lo que se lleva los atributos de la clase Persona a Estudiante
            super (nombre, edad);
            this.carrera = carrera;
        }

        public void estudiar(){
            //Tuve que cambiar a nombre a publico para que se pueda usar en la funcion
            out.println(nombre + " esta estudiando " + carrera + ".");
        }
    }

}