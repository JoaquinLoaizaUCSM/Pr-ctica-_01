// Sirve para ahorrar el trabajo de poner el System
import static java.lang.System.out;

//Todo debe estar en un main para que el IDE ejecute
public class Main_Coche {

    public static void main(String[] args){
        Coche Motor = new Coche ("Nissan",2019); //Aqui creo un objeto y le asigno atributos
        Motor.acelerar();
    }
    public static class Coche {
        private String modelo;
        private int año;

        //Esto es algo asi como un setter xdxd
        public Coche(String modelo, int año) {
            this.modelo = modelo;
            this.año = año;
        }

        public void acelerar() {
            out.println("El coche " + modelo + " del año " + año + " esta acelerando.");
        }

    }

}


