import java.util.*;
public class GCD_LCM 
{
    public static void main(String[] argv) 
	{
		Scanner cin = new Scanner(System.in);
		System.out.println("Please enter a number: ");
		int n = cin.nextInt();
		System.out.println("Please enter another number: ");
		int m = cin.nextInt();
        System.out.println(gcd(n,m));
		System.out.println(lcm(n,m));
		System.out.println(lcm1(n,m));
    }
    
	public static int gcd(int x, int y) 
	{
        int tmp;
        // if x < y change x, y
        while (x % y != 0) 
		{
            tmp = y;
            y = x % y;
            x = tmp;
        }
        return y;
    }
	
	public static int lcm(int m, int n) 
	{ 
		return (m * n / gcd(m, n));
	}
	
	public static int lcm1(int x, int y) 
	{ 
		int tmp;
        // if x < y change x, y
        while (x % y != 0) 
		{
            tmp = y;
            y = x % y;
            x = tmp;
        }
		return (x);
	}
}  