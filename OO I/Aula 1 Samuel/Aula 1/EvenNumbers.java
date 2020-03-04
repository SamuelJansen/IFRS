public class EvenNumbers {
    
    private String evenNumbersAsString;
    private Integer FIRST_NUMBER = 1;
    private Integer LAST_NUMBER = 20000;
    private String SEPARATOR = ", ";
    private String BREAK_LINE = "\n";
    private Integer EVEN_DIVISOR = 2;
    private Integer TIME_TO_BREAK_LINE = 18;

    public EvenNumbers() {
        this.evenNumbersAsString = "";
    }
    
    public String getAllEvenNumbersAsString() {
        for (Integer number = this.FIRST_NUMBER; number <= this.LAST_NUMBER; number++) {
            if (this.itsAEvenNumber(number)){
                this.updateEvenNumbersSetAsString(number);
            }
        }
        return this.evenNumbersAsString;
    }
    
    public Boolean itsAEvenNumber(Integer number) {
        return (number % this.EVEN_DIVISOR) == 0;
    }
    
    public Boolean itsTimeToBreakLine(Integer number) {
        return (number % this.TIME_TO_BREAK_LINE) == 0;
    }
    
    public Boolean itsTimeToAddSeparator(Integer number) {
        return ((this.LAST_NUMBER - number) >= this.EVEN_DIVISOR);
    }
    
    public void updateEvenNumbersSetAsString(Integer evenNumber) {
        this.evenNumbersAsString += evenNumber;
        
        if (this.itsTimeToAddSeparator(evenNumber)) {
            this.addSeparator();
        }
        
        if (this.itsTimeToBreakLine(evenNumber)) {
            this.addBreakLine();
        }
    }
    
    public void addSeparator() {
        this.evenNumbersAsString += this.SEPARATOR;
    }
    
    public void addBreakLine() {
        this.evenNumbersAsString += this.BREAK_LINE;
    }
}
