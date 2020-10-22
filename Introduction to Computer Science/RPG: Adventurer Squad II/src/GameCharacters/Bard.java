package GameCharacters;
public class Bard extends BaseCharacter
{
	private int Egg;
	
	// set
	public Bard(int a)
	{
		Egg = a;
	}
	public void setData(int b, int c, int d, int e)
	{
		HP = b;
		MP = c;
		FP = d;
		Egg = e;
	}	
	
	// all siuation connect to MP, HP, FP, Egg
	// skill of Bard
	public void perform()
	{
		MP-=20;
		FP+=30;
	}
	
	public void adventure()
	{
		MP-=80;
		FP+=80;
		Egg++;
		HP-=90;
	}
	
	public void comaAdventure()
	{
		MP-=80;
		FP+=80;
		Egg++;
		HP = 0;
	}
	
	public void healByMonk()
	{
		if(HP > 35)HP = 100;
		else HP+=65;
	}
	
	public int getEgg()
	{
		return Egg;
	}
	
	public void printStatus()
	{
		super.printStatus();
		System.out.println("I'm the bard, I can sing!");
	}
}