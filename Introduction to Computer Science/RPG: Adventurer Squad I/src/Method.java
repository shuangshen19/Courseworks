public class Method 
{
	// the introduction
	public void Introduction()
	{
		System.out.println("\nYou can use following instructions to play the game.");
		System.out.println("1. item robber/monk food/drink");
		System.out.println("2. skill robber/monk action");
		System.out.println("   robber's action: loot, adventure, buy_food, buy_drink; \n   monk's action: adventure, buy_food, buy_drink");
		System.out.println("3. skill monk action robber/monk");
		System.out.println("   monk's action: heal");
		System.out.println("4. rest");
		System.out.println("5. rest day (day = 2~9)");
		System.out.println("6. status");
		System.out.println("7. help");
		System.out.println("8. instruction");
		System.out.println("9. exit");
	}
	
	// the instruction
	public void Instruction()
	{
		System.out.println("item robber/monk food: robber/monk HP+40");
		System.out.println("item robber/monk drink: robber/monk MP+60");
		System.out.println("skill robber/monk buy_food: Gold-1, Food+2, robber/monk FP+10");
		System.out.println("skill robber/monk buy_drink: Gold-1, Drink+1, robber/monk FP+10");
		System.out.println("skill robber loot: Gold+2, robber HP-30, MP-20, FP+40");
		System.out.println("skill robber adventure: Treasure+1, robber HP-60, MP-30, FP+40");
		System.out.println("(You can use when the day is 2, 4, 6, 8, 10)");
		System.out.println("skill monk heal robber/monk: monk MP-30, FP+30, robber/monk HP+65");
		System.out.println("skill monk adventure: Jewel+1, monk HP-60, MP-60, FP-60");
		System.out.println("(You can use when the day is 3, 6, 9)");
		System.out.println("======================================================================");
	}
	
	// judge the given title
	public void Title(int a, int b, int c, int d, int e)
	{
		if(a >= 6)
		{
			System.out.println("Congratuation!! You have treasure >= 6.");
			System.out.println("Robber have the title: ~~Treasure Hunter~~");
		}
		if(b >= 3)
		{
			System.out.println("Excellent!! You have jewel >= 3.");
			System.out.println("Monk have the title: ~~Priest~~");
		}
		
		if(c >= 10)
		{
			System.out.println("Great!! You are good at managing finances.");
			System.out.println("Robber have the title: ~~Kaito Righteous Thief~~");
		}
		if((d + e) >= 20)
		{
			System.out.println("Wow!! You are really good at keeping stuffs.");
			System.out.println("Team have the title: ~~Storagekeeper~~");
		}
		if((a + b) == 0)
		{
			System.out.println("Team have the title: ~~Normal Life~~");
			System.out.println("Come again next, and try your best!");
		}
		if(!(a >= 6 && b >= 3 && c >= 10 && (d + e) >= 20 && (a + b) == 0))
			System.out.println("Sorry, you don't get any title!");
	}
	
	// the sentence of end game
	public void EndGame()
	{
		System.out.println("Game Over!!!");
		System.out.println("Thank you for your participation!");
	}
}
