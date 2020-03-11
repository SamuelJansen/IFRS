import java.util.Scanner;


public class Main
{
    public void programa(){
    
        Caneta caneta = new Caneta();
        Scanner entrada = new Scanner(System.in);
        System.out.println("Digite o modelo da caneta: ");
        String modelo = entrada.nextLine();
        caneta.setModelo(modelo);
        System.out.println("Digite a ponta da caneta: ");
        float ponta = entrada.nextFloat();
        caneta.setPonta(ponta);
        caneta.getStatus();
        
    }
}
