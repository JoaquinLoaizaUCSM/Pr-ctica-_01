// Sirve para ahorrar el trabajo de poner el System
import static java.lang.System.out;

//Todo debe estar en un main para que el IDE ejecute
public class Main_Persona_v3 {

    public static void main(String[] args){
        Persona Yhosfer = new Persona("Yhosfer", 23);
        Yhosfer.saludar();
    }
    public static class Persona {
        private String nombre;
        private int edad;

        public Persona(String nombre, int edad) {
            this.nombre = nombre;
            this.edad = edad;
        }

        public void saludar() {
            out.println("Hola, soy " + nombre + " y tengo " + edad + " años xdxd.");
        }

    }

}
