import java.util.*;
public class hw2
{
	public static void main(String[] args)
	{
		// declare the guessed words
		String guess[][] = new String [5][3];            
		guess[0][0] = "art";
		guess[0][1] = "sea";
		guess[0][2] = "pose";
		guess[1][0] = "history";
		guess[1][1] = "teacher";
		guess[1][2] = "certain";
		guess[2][0] = "identical";
		guess[2][1] = "lovable";
		guess[2][2] = "qualify";
		guess[3][0] = "satisfactory";
		guess[3][1] = "barbarian";
		guess[3][2] = "contemptible";
		guess[4][0] = "unprecedented";
		guess[4][1] = "superimpose";
		guess[4][2] = "rehabilitation";
		
		// the explainations of the words
		String explaination[][] = new String [5][3];            
		explaination[0][0] = "something that is created with imagination and skill and that is beautiful or that expresses important ideas or feelings";
		explaination[0][1] = "the salt water that covers much of the Earth's surface";
		explaination[0][2] = "the position in which someone stands, sits, lies down, etc., especially as a model for a photograph, painting, etc.";
		explaination[1][0] = "events of the past";
		explaination[1][1] = "a person or thing that teaches something; especially : a person whose job is to teach students about certain subjects";
		explaination[1][2] = "not having any doubt about something : convinced or sure";
		explaination[2][0] = "exactly alike or equal";
		explaination[2][1] = "easy to love : having attractive or appealing qualities";
		explaination[2][2] = "to give (someone) the necessary skill or knowledge to do a particular job or activity";
		explaination[3][0] = "good enough for a particular purpose";
		explaination[3][1] = "an uncivilized person";
		explaination[3][2] = "not worthy of respect or approval : deserving contempt";
		explaination[4][0] = "not done or experienced before";
		explaination[4][1] = "to place or lay (something) over something else";
		explaination[4][2] = "to bring (someone or something) back to a normal, healthy condition after an illness, injury, drug problem, etc.";
		hangmanPuzzle(16);
		
		// introduce the game
 		System.out.println("Welcome to HangMan! Hope you have a wonderful time in this game!"); 
		System.out.println("\n  ______      Following are the rules: ");
		System.out.println(" |      |     1. There are 5 levels (BABY, EASY, NORMAL, HARD and HELL).");
		System.out.println(" |     \\O/    2. Each leval has 3 rounds.");
		System.out.println(" |      |     3. When guessing the word, you can input a letter or a word.");
		System.out.println(" |     / \\    4. You have 15 chances to guess the words in each level.");
		System.out.println(" |            5. You can input #Help_Me to get 1 hint, but lose 2 chances.");
		System.out.println("_|_____       6. When the 15th guess is wrong, you fail the game.");
		System.out.println("\nStart to guess!!!");
		
		// change the string to int
		int level = 0; 
		int prompt = 0;
		char hint = 0;
		Scanner cin1 = new Scanner(System.in);
		String inputlevel;
		do
		{
			System.out.print("\nPlease input a level in upper case (BABY, EASY, NORMAL, HARD, HELL): "); 
			inputlevel = cin1.nextLine();
			if(inputlevel.equals("BABY"))level = 1;
			else if(inputlevel.equals("EASY"))level = 2;
			else if(inputlevel.equals("NORMAL"))level = 3;
			else if(inputlevel.equals("HARD"))level = 4;
			else if(inputlevel.equals("HELL"))level = 5;
			else    
			{
				// detect wrong format input
				System.out.println("\nWrong input! Please input BABY, EASY, NORMAL, HARD or HELL!");
				level = 0;
			}
		}while(level == 0);

		// use while loop to run the game 
		int round = 0;
		int a = 0;
		while(round <= 3 && a < 15)
		{
			// choose the right guessed word
			char wordToGuess[] = guess[level - 1][round].toCharArray();
			// the length of the guessef word
			int amountOfGuesses = wordToGuess.length;
			String playerGuess[] = new String[amountOfGuesses]; 
			for (int i = 0; i < playerGuess.length; i++) 
			{ 
 				playerGuess[i] = "_"; 
 			} 
			
			Scanner cin2 = new Scanner(System.in);
			System.out.println("\nThis is " + inputlevel + " level --- Round " + (round + 1));
			System.out.print(amountOfGuesses + " letters of the word: ");
			// use array to print the length of the guessed word ( _ _ _ represent the number of length)
			printArray(playerGuess);
			hangmanPuzzle(a);
			System.out.print("\nPlease input a letter or a word in lower case: ");
			String board[][] = new String[5][6];   
			for(int i = 0; i < 5; i++)  
			{
				for(int j = 0; j < 6; j++)
				{
					board[i][j] = " ";
				}
			}
			
			while(cin2.hasNext())
			{
				// check the input is equal to or is not equal to the guessed word
				int check = 0;
				String input = cin2.nextLine();
				int wrong = 0;
				
				String[] letter = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
				
				if(input.length() == 1)  
				{
					int k = 0;
					// make sure the user input a letter
					for(int i = 0; i < letter.length; i++)
					{
						if(input.equals(letter[i]))k++;
					}
					// user input a letter	
					if(k == 1)
					{
						for(int i = 0; i < amountOfGuesses; i++) 
						{
							// the user input a right letter, and show the place
							if(input.equals(guess[level - 1][round].substring(i,i+1)))
								playerGuess[i] = guess[level - 1][round].substring(i,i+1); 
							else
								wrong++;
						}
						// the user input a wrong letter
						if(wrong == amountOfGuesses)
						{
							System.out.println("\nYou guessed the wrong letter! Try again!");
							a++; 
						}
					}
					else
						// not a letter
						System.out.println("\nWrong input! Please input a letter or a word in lower case!");
				}
				// if the user's chance > 2, the user can use the hint function
				else if(input.equals("#Help_Me") && a < 13)
				{		
					for(;;)
					{
						int check_h = 0;
						Random r = new Random();
						hint = guess[level - 1][round].charAt(r.nextInt(amountOfGuesses));
							// check the hint letter hasn't been guessed
							for(int i = 0; i < 5; i++)
							{										
								for(int j = 0; j < 6; j++)
								{  
									if(String.valueOf(hint).equals(board[i][j]))check_h = 1;
								}
							}
						if(check_h==0)
						{				
							prompt = 1;
							break;
						}
					}
					a = a + 2;
				}
				// the user can't use the hint function
				else if(input.equals("#Help_Me") && a > 12)
				{       
					System.out.println("\nSorry, you don't have enough chances.");
				}
				else if(input.length() == amountOfGuesses)              
				{	   
					int k = 0;
					//if the user input a word
					for(int i = 0; i < input.length(); i++)		                         
					{
						for(int j = 0; j < 26; j++)
						{
							if(String.valueOf(input.charAt(i)).equals(letter[j]))k = 1;
						}
					}
					if(input.equals(guess[level - 1][round]))
					{
						for(int i = 0; i < amountOfGuesses; i++)
						{
							// the word is right, and show the place
							playerGuess[i] = guess[level - 1][round].substring(i,i+1);
						}
					}
					else if(k == 1)
					{
						// wrong word
						System.out.println("\nYou guessed the wrong word! Try again!");
						a++;
					}	
					else
						// not a word
						System.out.println("\nWrong input! Please input a letter or a word in lower case!");
				}
				else
					// not a word
					System.out.println("\nWrong input! Please input a letter or a word in lower case!");
				
				for(int i = 0; i < amountOfGuesses; i++)  
				{
					//if playerguess has "_" , the user hasn't guessed the letter
					if(playerGuess[i].equals("_"))
						check++;
				}
				
				String letter_b = "";
				for(int i = 0; i < amountOfGuesses; i++) 
				{
					letter_b = letter_b + playerGuess[i] + " ";
				}
				
				hangmanPuzzle(a);
				if(input.equals("a"))board[0][0] = "a";
				else if(input.equals("b"))board[0][1] = "b";
				else if(input.equals("c"))board[0][2] = "c";
				else if(input.equals("d"))board[0][3] = "d";
				else if(input.equals("e"))board[0][4] = "e";
				else if(input.equals("f"))board[0][5] = "f";
				else if(input.equals("g"))board[1][0] = "g";
				else if(input.equals("h"))board[1][1] = "h";
				else if(input.equals("i"))board[1][2] = "i";
				else if(input.equals("j"))board[1][3] = "j";
				else if(input.equals("k"))board[1][4] = "k";
				else if(input.equals("l"))board[1][5] = "l";
				else if(input.equals("m"))board[2][0] = "m";
				else if(input.equals("n"))board[2][1] = "n";
				else if(input.equals("o"))board[2][2] = "o";
				else if(input.equals("p"))board[2][3] = "p";
				else if(input.equals("q"))board[2][4] = "q";
				else if(input.equals("r"))board[2][5] = "r";
				else if(input.equals("s"))board[3][0] = "s";
				else if(input.equals("t"))board[3][1] = "t";
				else if(input.equals("u"))board[3][2] = "u";
				else if(input.equals("v"))board[3][3] = "v";
				else if(input.equals("w"))board[3][4] = "w";
				else if(input.equals("x"))board[3][5] = "x";
				else if(input.equals("y"))board[4][0] = "y";
				else if(input.equals("z"))board[4][1] = "z";	
				
				// show the current guessing word
				System.out.println("\nThe gussing word: " + letter_b);
				
				// if the user qualified, show the hint 
				if(prompt == 1)
				{									
					System.out.println("\nLetter [" + hint + "] is in the guessing word.");
					prompt = 0;
				}
							
				// show the guessed letters in board
				String letter_c = "";
				for(int i = 0; i < 5; i++)                          
				{
					for(int j = 0; j < 6; j++)
					{
						letter_c = letter_c + board[i][j] + " ";
					}
				}
				System.out.println("\nThe guessed letters: ");
				System.out.println(letter_c + " ");
				System.out.println("=================================================================================");
				if (check != 0)System.out.print("Please input a letter or a word in lower case: ");
				
				// check==0 represents the user pass a round
				if(check == 0)
				{
					round++;    
					// the user can enter the next round
					if(round != 3)        
					{
						System.out.println("The explaination of " + guess[level - 1][round - 1] + ": " + explaination[level - 1][round - 1]);
						System.out.println("\nExcellent! You guessed the word. \nAnd you are going to enter the next round.");
						break;
					}
					// the user passed 3 rounds and won the game
					else              
					{
						System.out.println("The explaination of " + guess[level - 1][round - 1] + ": " + explaination[level - 1][round - 1]);
						System.out.println("\nCongratuations!!!!! You won the game!");
						System.out.println("Goodbye! ^w^");
						System.exit(0);
					}
				}
			}
		}
	}
	
	// use this change ___	into _ _ _
	public static void printArray(String[] array) 
	{ 
 		for (int i = 0; i < array.length; i++) 
		{ 
 			System.out.print(array[i] + " "); 
 		} 
 		System.out.println(); 
 	}
	
	// print the hangman picture puzzle
	public static void hangmanPuzzle(int a)    
	{
		if(a == 0)
		{
			System.out.println("=================================================================================");
			System.out.println("You have 15 chances, and you can input #Help_Me to get 1 hint by 2 chances."); 
			System.out.println("");
			System.out.println("");
			System.out.println("");
			System.out.println("");
			System.out.println("");
			System.out.println("");
			System.out.println("_|_____");
		}
		else if(a == 1)
		{
			System.out.println("=================================================================================");
			System.out.println("You still have 14 chances, and you can input #Help_Me to get 1 hint by 2 chances.");
			System.out.println("");
			System.out.println("");
			System.out.println("");
			System.out.println("");
			System.out.println("");
			System.out.println(" |");
			System.out.println("_|_____");
		}
		else if(a == 2)
		{
			System.out.println("=================================================================================");
			System.out.println("You still have 13 chances, and you can input #Help_Me to get 1 hint by 2 chances.");
			System.out.println("");
			System.out.println("");
			System.out.println("");
			System.out.println("");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println("_|_____");
		}
		else if(a == 3)
		{
			System.out.println("=================================================================================");
			System.out.println("You still have 12 chances, and you can input #Help_Me to get 1 hint by 2 chances.");
			System.out.println("");
			System.out.println("");
			System.out.println("");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println("_|_____");
		}
		else if(a == 4)
		{
			System.out.println("=================================================================================");
			System.out.println("You still have 11 chances, and you can input #Help_Me to get 1 hint by 2 chances.");
			System.out.println("");
			System.out.println("");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println("_|_____");
		}
		else if(a == 5)
		{
			System.out.println("=================================================================================");
			System.out.println("You still have 10 chances, and you can input #Help_Me to get 1 hint by 2 chances.");
			System.out.println("");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println("_|_____");
		}
		else if(a == 6)
		{
			System.out.println("=================================================================================");
			System.out.println("You still have 9 chances, and you can input #Help_Me to get 1 hint by 2 chances.");
			System.out.println("  __ ");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println("_|_____");
		}
		else if(a == 7)
		{
			System.out.println("=================================================================================");
			System.out.println("You still have 8 chances, and you can input #Help_Me to get 1 hint by 2 chances.");
			System.out.println("  ____ ");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println("_|_____");
		}
		else if(a == 8)
		{
			System.out.println("=================================================================================");
			System.out.println("You still have 7 chances, and you can input #Help_Me to get 1 hint by 2 chances.");
			System.out.println("  ______ ");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println("_|_____");
		}
		else if(a == 9)
		{
			System.out.println("=================================================================================");
			System.out.println("You still have 6 chances, and you can input #Help_Me to get 1 hint by 2 chances.");
			System.out.println("  ______ ");
			System.out.println(" |      |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println("_|_____");
		}
		else if(a == 10)
		{
			System.out.println("=================================================================================");
			System.out.println("You still have 5 chances, and you can input #Help_Me to get 1 hint by 2 chances.");
			System.out.println("  ______ ");
			System.out.println(" |      |");
			System.out.println(" |      O");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println("_|_____");
		}
		else if(a == 11)
		{
			System.out.println("=================================================================================");
			System.out.println("You still have 4 chances, and you can input #Help_Me to get 1 hint by 2 chances.");
			System.out.println("  ______ ");
			System.out.println(" |      |");
			System.out.println(" |      O");
			System.out.println(" |      |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println("_|_____");
		}
		else if(a == 12)
		{
			System.out.println("=================================================================================");
			System.out.println("You still have 3 chances, and you can input #Help_Me to get 1 hint by 2 chances.");
			System.out.println("  ______ ");
			System.out.println(" |      |");
			System.out.println(" |      O/");
			System.out.println(" |      |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println("_|_____");
		}
		else if(a == 13)
		{
			System.out.println("=================================================================================");
			System.out.println("You still have 2 chance.");
			System.out.println("  ______ ");
			System.out.println(" |      |");
			System.out.println(" |     \\O/");
			System.out.println(" |      |");
			System.out.println(" |");
			System.out.println(" |");
			System.out.println("_|_____");
		}
		else if(a == 14)
		{
			System.out.println("=================================================================================");
			System.out.println("You have the last chance.");
			System.out.println("  ______ ");
			System.out.println(" |      |");
			System.out.println(" |     \\O/");
			System.out.println(" |      |");
			System.out.println(" |     /");
			System.out.println(" |");
			System.out.println("_|_____");
		}
		else if(a == 15)
		{
			System.out.println("=================================================================================");
			System.out.println("Sorry! You are hanged.");
			System.out.println("  ______ ");
			System.out.println(" |      |");
			System.out.println(" |     \\O/");
			System.out.println(" |      |");
			System.out.println(" |     / \\");
			System.out.println(" |");
			System.out.println("_|_____");
			System.out.println("Game over. QAQ");
			System.exit(0);
		}
	}
}