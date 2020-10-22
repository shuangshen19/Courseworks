import java.util.*;
public class fibonacci
{ 
	public static void main(String[] args)
	{ 
		int f=0,f0=1,f1=1; 
		Scanner cin = new Scanner(System.in);
		System.out.println("Please enter a number: ");
		int n = cin.nextInt();
		if (n <= 1) return n;
		for(int i = 2; i <= n; i++ )
		{  
			f = f0 + f1; 
			f0 = f1; 
			f1 = f;
		} 
		System.out.print(f);
	} 
} 