public class Team 
{
	private int Gold, Food, Drink, Day, House;
	
	// all the situation connect to Gold, Food, Drink, Day
	public Team(int a, int b, int c, int d, int e)
	{
		Day = a;
		Gold = b;
		Food = c;
		Drink = d;
		House = e;
	}
	public void setData(int i, int j, int k, int l, int m)
	{
		Day = i;
		Gold = j;
		Food = k;
		Drink = l;
		House = m;
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
	
	public void restDay(int f)
	{
		Day = Day + f;
		Food = Food - f;
	}
	
	public void improve()
	{
		House++;
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
	
	public int getHouse()
	{
		return House;
	}
	
	public void HouseTitle(int g)
	{
		if(g < 5)System.out.println(" Tent");
		else if(g < 10)System.out.println(" Yurt");
		else if(g < 15)System.out.println(" Straw House");
		else if(g < 20)System.out.println(" Cabin");
		else System.out.println(" Brick House");
	}
	
	public void printStatus(int h)
	{
		System.out.println("Day: " + Day + ", Gold: " + Gold + ", Food: " + Food + ", Drink: " + Drink);
		System.out.print("HOUSE LEVEL: " + House);
		HouseTitle(h);
	}
}
