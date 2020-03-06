/**
Utilizando o blueJ crie uma classe funcionário que possua:
os atributos: nome, valorHora e horasTrabalhadas
crie métodos que alterem esses valores
Crie um método que calcule o valor do salario de acordo com os dados de cada funcionario
*/
public class Funcionario
{
    private String nome;
    private Double valorHora;
    private Integer horasTrabalhadas;
    
    public Funcionario(String nome, Double valorHora, Integer horasTrabalhadas) {
        this.nome = nome;
        this.valorHora = valorHora;
        this.horasTrabalhadas = horasTrabalhadas;
    }
    
    // null constructor
    public Funcionario() {
        this.nome = "";
        this.valorHora = 0.0;
        this.horasTrabalhadas = 0;
    }
    
    public void setNome(String nome){this.nome = nome;}
    public void setValorHora(Double valorHora){this.valorHora = valorHora;}
    public void setHorasTrabalhadas(Integer horasTrabalhadas){this.horasTrabalhadas = horasTrabalhadas;}
    
    public String getNome(){return this.nome;}
    public Double getValorHora(){return this.valorHora;}
    public Integer getHorasTrabalhadas(){return this.horasTrabalhadas;}
    public Double getSalario(){return this.horasTrabalhadas * this.valorHora;}
    
    public String funcionarioToString(){
        return "Nome: " + this.getNome() + ", salário: " + this.getSalario();
    }
    
}
