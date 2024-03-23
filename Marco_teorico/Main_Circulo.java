// Sirve para ahorrar el trabajo de poner el System
import static java.lang.System.out;

//Todo debe estar en un main para que el IDE ejecute
public class Main_Circulo {

    public static void main(String[] args){
        Forma F_01 = new Circulo(2); //Creacion objeto
        double area = F_01.area();
        double perimetro = F_01.perimetro();
        out.println("Area: " + area + " Perimetro: " + perimetro + ".");
    }
    interface Forma{
        double area();
        double perimetro();
    }

    public static class Circulo implements Forma {
        double radio;
        double Pi = Math.PI;
        public Circulo(double radio){
            this.radio = radio;
        }
        public double area() {
            return Pi * radio * radio;
        }

        public double perimetro() {
            return 2 * Pi * radio;
        }
    }

}