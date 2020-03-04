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
    private ArrayList<Funcionario> funcionarios;
    
    public Empresa(){
        for (int i=0; i<10; i++){
            this.funcionarios.add(new Funcionario()); // due null constructor
        }
    }
    
    public void addFuncionario(Funcionario funcionario){
        this.funcionarios.add(funcionario);
    }
    
    public void removeFuncionario(Funcionario funcionario){
        this.funcionarios.remove(this.funcionarios.indexOf(funcionario));
    }
    
    public void removeFuncionarioByIndex(Integer funcionarioIndex){
        this.funcionarios.remove(funcionarioIndex);
    }
    
    public void printFuncionario(Funcionario funcionario){
        System.out.println(funcionario.funcionarioToString());
    }
    
    public void printFuncionarioByIndex(Integer funcionarioIndex){
        System.out.println(this.funcionarios.get(funcionarioIndex).toString());
    }
}
