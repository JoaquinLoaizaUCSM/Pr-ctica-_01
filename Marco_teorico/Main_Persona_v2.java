// Sirve para ahorrar el trabajo de poner el System
import static java.lang.System.out;

//Todo debe estar en un main para que el IDE ejecute
public class Main_Persona_v2 {

    public static void main(String[] args){
        Persona Grossman = new Persona ("Grossman",18); //Aqui creo un objeto y le asigno atributos
        out.println(Grossman.getNombre() + " tiene " + Grossman.getEdad() + " años.");
    }
    public static class Persona {
        private String nombre;
        private int edad;

        public Persona(String nombre, int edad) {
            this.nombre = nombre;
            this.edad = edad;
        }

        public void setNombre(String nombre) {
            this.nombre = nombre;
        }

        public String getNombre() {
            return this.nombre;
        }

        public void setEdad(int edad) {
            this.edad = edad;
        }

        public int getEdad() {
            return this.edad;
        }

    }

}