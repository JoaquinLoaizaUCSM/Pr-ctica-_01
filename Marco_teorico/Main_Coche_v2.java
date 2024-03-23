// Sirve para ahorrar el trabajo de poner el System
import static java.lang.System.out;

//Todo debe estar en un main para que el IDE ejecute
public class Main_Coche_v2 {

    public static void main(String[] args){
        Coche MK_01 = new Coche ("Nissan", "Amarillo", 0); //Aqui creo un objeto y le asigno atributos
        MK_01.acelerar(50);
        out.println("La velocidad actual del vehiculo marca " + MK_01.modelo + " color " + MK_01.color + " es de " + MK_01.velocidad);
        MK_01.frenar(30);
        out.println("Se redujo la velocidad en 30 por lo que su actual es de " + MK_01.velocidad);
    }
    public static class Coche {
        private String modelo;
        private String color;
        private int velocidad;

        public Coche(String modelo, String color, int velocidad) {
            this.modelo = modelo;
            this.color = color;
            this.velocidad = velocidad;
        }
        //Aqui agregue el parametro "variacion" en lugar de que se un aumento de 10, el usuario decidira cuanto más acelerar
        public void acelerar(int variacion) {
            this.velocidad += variacion;
        }

        public void frenar(int variacion){
            this.velocidad -= variacion;
        }

    }

}



