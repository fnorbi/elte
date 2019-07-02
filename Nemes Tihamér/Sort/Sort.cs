using System;
using System.Collections.Generic;

public class Rec : IComparable<Rec>
{
	public string name;
	public int age;
	
	public Rec(string name, int age)
	{
		this.name = name;
		this.age = age;
	}

	public override string ToString()
	{
		return this.name + " " + this.age;
	}
	
	public int CompareTo(Rec o)
	{
		if(this.age < o.age)
		{
			return -1;
		}
		else if(this.age == o.age)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}
	
class Sort
{
	public static void kiir(List<Rec> adatok)
	{
		foreach(Rec r in adatok)
		{
			Console.WriteLine(r);
		}
	}
	
	public static void Main()
	{
		int n = Convert.ToInt32(Console.ReadLine());
		List<Rec> adatok = new List<Rec>();
		for(int i = 0; i < n; i++)
		{
			string[] temp = Console.ReadLine().Split();
			string name = temp[0];
			int age = Convert.ToInt32(temp[1]);
			adatok.Add(new Rec(name, age));
		}
		
		kiir(adatok);
		Console.WriteLine();
		
		adatok.Sort();
		//adatok.Reverse();
		
		kiir(adatok);
		
	}
}
