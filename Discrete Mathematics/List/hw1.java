import java.util.*;

public class hw1
{
	public static void main(String[] args)
	{
		// initialize
		Scanner cin = new Scanner(System.in);
		String[] w = new String [5];
		String search;
		
		// input 5 words into w[]
		System.out.println("Please input 5 words!");
		int a;
		for(a = 0; a < 5; a++)
		{
			if(a == 0) System.out.print("Please input the first word: ");
			else if(a == 1) System.out.print("\nPlease input the second word: ");
			else if(a == 2) System.out.print("\nPlease input the third word: ");
			else if(a == 3) System.out.print("\nPlease input the fourth word: ");
			else if(a == 4) System.out.print("\nPlease input the fifth word: ");
			w[a] = cin.nextLine();
			System.out.println("\n--------------------------------------");
			System.out.print("LIST: ");
			int b;
			for(b = 0; b <= a; b++) System.out.print(w[b] + " ");
			
		}
		System.out.println("\n--------------------------------------");
		// search function
		System.out.print("Please input the word you'd like to search: ");
		search = cin.nextLine();
		int check = 2, ch = 0;
		
		for(a = 0; a < 5 ; a++)
		{
			if(search.equals(w[a])) 
			{
				if(ch == 0) System.out.print("The position of the word in the list is: ");
				System.out.print(a+1 + " ");
				check = 1;
				ch = 1;
			}
		}
		if(check == 2) System.out.println("Sorry, the word is not in the list.");
	}
}	