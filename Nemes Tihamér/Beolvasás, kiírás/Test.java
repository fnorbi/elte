import java.util.Scanner;
import java.math.BigInteger;

public class Test {
    
    public static void main(String[] args) {
        
		Scanner reader = new Scanner(System.in);
		
		int n = reader.nextInt();
		reader.close();
		
        System.out.println((int) Math.pow(n,2));
		
    }
    
}