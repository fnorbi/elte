import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections; //sorthoz

public class Sort{
	
	public static class Rec implements Comparable<Rec>{
		String name;
		int age;
		
		public Rec(String name, int age){
			this.name = new String(name);
			this.age = age;
		}
		
		@Override
		public String toString(){
			return this.name + " " + this.age;
		}
		
		@Override
		public int compareTo(Rec o){
			if(this.age < o.age){
				return -1;
			}else if(this.age == o.age){
				return 0;
			}else{
				return 1;
			}
		}
	}
	
	public static void kiir(List<Rec> adatok){
		for(Rec r : adatok){
			//System.out.println(r.name + " " + r.age);
			System.out.println(r);
		}
	}
	
	public static void main(String[] args){
		Scanner reader = new Scanner(System.in);
		List<Rec> adatok = new ArrayList<>();
		
		int n = reader.nextInt();
		
		for(int i = 0; i < n; i++){
			String name = reader.next();
			int age = reader.nextInt();
			adatok.add(new Rec(name, age));
		}
		
		reader.close();
		
		kiir(adatok);
		System.out.println();
		
		Collections.sort(adatok);
		//Collections.sort(adatok, Collections.reverseOrder());
		
		kiir(adatok);
		
	}
}