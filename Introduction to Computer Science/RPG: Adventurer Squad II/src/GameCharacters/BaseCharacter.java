package GameCharacters;
public abstract class BaseCharacter
{
	protected int FP, HP, MP;
	
	// set
	public BaseCharacter()
	{
		this(0, 100, 80);
	}
	public BaseCharacter(int fp, int hp, int mp)
	{
		FP = fp;
		HP = hp;
		MP = mp;
	}
	
	public void printStatus()
	{
		System.out.println("HP: " + HP + "/100" + ", MP: " + MP + "/80" + ", FP: " + FP);
	}
	
	// the function of buy and eat food/drink
	public void buy_food()
	{
		FP+=10;
	}
	
	public void buy_drink()
	{
		FP+=10;
	}
	
	public void eat()
	{
		if(HP > 60)HP = 100;
		else HP+=40;
	}
	
	public void drink()
	{
		if(MP > 20)MP = 80;
		else MP+=60;
	}
	
	public void rest()
	{
		FP = 0;
	}
	
	// in/after coma situation 
	public void afterComa()
	{
		HP = 50;
		FP = 0;
	}
	
	public void coma()
	{
		HP = 0;
	}
	
	public abstract void adventure();
	
	public abstract void comaAdventure();
	
	// return FP, HP, MP
	public int getFP()
	{
		return FP;
	}
	
	public int getHP()
	{
		return HP;
	}
	
	public int getMP()
	{
		return MP;
	}
	
	public void improve()
	{
		FP+=25;
	}
}
