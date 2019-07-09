import java.util.Scanner;

public class feladat{
	
	public static void main(String[] args){
		
		Scanner reader = new Scanner(System.in);
		int n = reader.nextInt();
		
		int[] array = {0,0,0,0,0};
		for(int i = 0; i < n; i++){
			int jegy = reader.nextInt();
			array[jegy - 1]++;
		}
		
		for(int i = 0; i < 5; i++){
			System.out.print(array[i] + " ");
		}
		
	}
	
}