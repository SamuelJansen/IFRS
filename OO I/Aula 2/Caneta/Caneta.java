import java.lang.StringBuilder;

public class Caneta
{
    public String modelo;
    private float ponta;
    
    public Caneta(String modelo,float ponta){
        this.modelo = modelo;
        this.ponta = ponta;
    }
    
    // null constructor
    public Caneta(){
        this.modelo = "";
        this.ponta = 0.7f;
    }

    public void setModelo(String modelo){
        this.modelo = modelo;
    }
    
    public String getModelo(){
        return this.modelo;
    }
    
    public void setPonta(float ponta){
        this.ponta = ponta;
    }
    
    public float getPonta(){
        return this.ponta;
    }
    
    public String toString(){
        return new StringBuilder()
            .append("Modelo: ")
            .append(this.modelo)
            .append(", ponta: ")
            .append(this.ponta)
            .toString();
    }
    
    public void getStatus(){
        System.out.println(this);
    }
}
