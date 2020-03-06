
/**
Crie uma classe que se chame Empresa.
Crie um vetor de 10 funcionarios
Crie um método para adicionar funcionarios
Crie um método para demitir funcionarios
Crie um método que mostra o nome do funcionário e seu salario 
 */

import java.util.*;
public class Empresa
{
    private ArrayList<Funcionario> funcionarios = new ArrayList<Funcionario>();
    
    public Empresa(){
        while (this.funcionarios.size() < 10) {
            this.funcionarios.add(new Funcionario()); // due null constructor
        }
        //for (int i=0; i<10; i++){
        //    this.funcionarios.add(new Funcionario()); // due null constructor
        //}
    }
    
    public void addFuncionario(Funcionario funcionario){
        this.funcionarios.add(funcionario);
    }
    
    public void removeFuncionario(Funcionario funcionario){
        if (this.funcionarios.indexOf(funcionario) >= 0) {
            this.funcionarios.remove(funcionario);
        }
        else {
            System.out.println("Funcionario não encontrado");
        }
    }
    
    public void removeFuncionarioByIndex(Integer funcionarioIndex){
        if (funcionarioIndex >= 0 && funcionarioIndex < this.funcionarios.size()) {
            this.funcionarios.remove(funcionarioIndex);
        }
        else {
            System.out.println("Index inválido");
        }
    }
    
    public void printFuncionario(Funcionario funcionario){
        if (this.funcionarios.indexOf(funcionario) >= 0) {
            System.out.println(funcionario.funcionarioToString());
        }
        else {
            System.out.println("Funcionario não encontrado");
        }
    }
    
    public void printFuncionarioByIndex(Integer funcionarioIndex){
        if (funcionarioIndex >= 0 && funcionarioIndex < this.funcionarios.size()) {
            System.out.println(this.funcionarios.get(funcionarioIndex).toString());
        }
        else {
            System.out.println("Index inválido");
        }
    }
}
