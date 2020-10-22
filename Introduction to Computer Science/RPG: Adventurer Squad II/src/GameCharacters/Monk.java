package GameCharacters;
public class Monk extends BaseCharacter
{
	private int Jewel;
	
	public Monk(int a)
	{
		Jewel = a;
	}
	public void setData(int b, int c, int d, int e)
	{
		HP = b;
		MP = c;
		FP = d;
		Jewel = e;
	}
	
	// all siuation connect to MP, HP, FP, Jewel
	// skill of Monk
	public void healMonk()
	{
		if(MP >= 30)
		{
			MP-=30;
			FP+=30;
			if(HP > 35)HP = 100;
			else HP+=65;
		}
		else System.out.println("You don't have enough MP to heal yourself.");
	}
	
	public void heal()
	{
		if(MP >= 30)
		{
			MP-=30;
			FP+=30;
		}
		else System.out.println("You don't have enough MP to heal.");
	}
	
	public void adventure()
	{
		MP-=60;
		FP+=60;
		Jewel++;
		HP-=60;
	}
	
	public void comaAdventure()
	{
		MP-=60;
		FP+=60;
		Jewel++;
		HP = 0;
	}
	
	public int getJewel()
	{
		return Jewel;
	}
	
	public void printStatus()
	{
		super.printStatus();
		System.out.println("I'm the monk, I can heal everybody!");
	}
	
	public void performByBard()
	{
		if(FP >= 25) FP-=25;
		else FP = 0;
	}
}