import java.util.*;
public class Prime_Divisors
{
	public static void main(String[] args) 
	{
		Scanner cin = new Scanner(System.in);
		System.out.println("Please enter a number: ");
		int n = cin.nextInt();
		prime_divisors(n);
    }
    
	public static void prime_divisors1(int x) 
	{
        int last=1,i;   
        for(i=2;i<=x;) 
		{
			if(x%i==0)
			{
				if(i!=last)
				{
					if(last==1)System.out.print(i);
					else System.out.print(", "+i);
					last=i;
				}
				x=x/i;
			}
			else i++;
		}
		System.out.println("");
    }
	
	public static void prime_divisors(int x) 
	{
        int last=1,i;   
        for(i=2;i<=x;i++) 
		{
			if(x%i==0)
			{
				if(i!=last)
				{
					if(last==1)System.out.print(i);
					else System.out.print(", "+i);
					last=i;
				}
				x=x/i;
			}
		}
		System.out.println("");
    }
}