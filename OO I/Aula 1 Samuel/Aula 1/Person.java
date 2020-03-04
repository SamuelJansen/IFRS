public class Person {
 
    private String name;
    
    private Integer age;
    
    public Person(String name, Integer age) {
        this.name = name;
        this.age = age;
    }
    
    public void haveBirthday(){
        this.age += 1;
    }
    
    public String toString(){
        // System.out.println();
        String toStringReturn = 
            "Wellcome " + this.name + '\n' +
            "You are " + this.age + "years old";
        return toStringReturn;
    }
}