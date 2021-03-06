public class Robber extends BaseCharacter
{
	private int Treasure;
	
	public Robber(int a)
	{
		Treasure = a;
	}
	
	// all siuation connect to MP, HP, FP, Treasure
	// skill of Robber
	public void loot()
	{
		MP-=20;
		FP+=40;
		HP-=30;
	}
	
	public void comaLoot()
	{
		MP-=20;
		FP+=40;
		HP = 0;
	}
	
	public void adventure()
	{
		MP-=30;
		FP+=40;
		Treasure++;
		HP-=60;
	}
	
	public void comaAdventure()
	{
		MP-=30;
		FP+=40;
		Treasure++;
		HP = 0;
	}
	
	public void healByMonk()
	{
		if(HP > 35)HP = 100;
		else HP+=65;
	}
	
	public int getTreasure()
	{
		return Treasure;
	}
	
	public void printStatus()
	{
		super.printStatus();
		System.out.println("I'm the robber, I'm the Robin Hood!");
	}
}