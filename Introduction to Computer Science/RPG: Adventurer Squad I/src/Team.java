public class Team 
{
	private int Gold, Food, Drink, Day;
	
	// all the situation connect to Gold, Food, Drink, Day
	public Team(int a, int b, int c, int d)
	{
		Day = a;
		Gold = b;
		Food = c;
		Drink = d;
	}
	
	public void buy_food()
	{
		Food+=2;
		Gold--;
	}
	
	public void buy_drink()
	{
		Drink+=1;
		Gold--;
	}
	
	public void eat()
	{
		Food--;
	}
	
	public void drink()
	{
		Drink--;
	}
	
	public void loot()
	{
		Gold+=2;
	}
	
	public void coma()
	{
		Day+=3;
		Food-=3;
	}
	
	public void rest()
	{
		Day++;
		Food--;
	}
	
	public void restDay(int e)
	{
		Day = Day + e;
		Food = Food - e;
	}

	// return Gold, Food, Drink, Day
	public int getGold()
	{
		return Gold;
	}
	
	public int getFood()
	{
		return Food;
	}
	
	public int getDrink()
	{
		return Drink;
	}
	
	public int getDay()
	{
		return Day;
	}
	
	public void printStatus()
	{
		System.out.println("Day: " + Day + " ,Gold: " + Gold + " ,Food: " + Food + " ,Drink: " + Drink);
	}
}
