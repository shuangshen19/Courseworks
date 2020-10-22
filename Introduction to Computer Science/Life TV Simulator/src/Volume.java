public class Volume 
{
	private int vol;
	
	// preset the volume
	public Volume()
	{
		vol = 10;
	}
	
	// judging the volume has to be up or down
	public void volumeUp()
	{
		if(vol == 15)
		{
			vol = 15;
			System.out.println("Volume is max.");
		}
		else vol++;
	}
	public void volumeDown()
	{
		if(vol == 0)
		{
			vol = 0;
			System.out.println("Volume is min.");
		}
		else vol--;
	}
	
	// print the volume
	public void printVolume()
	{
		System.out.println("The current volume: " + vol);
	}
}
