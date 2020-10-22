public class Channel 
{
	private String[] name = new String[3];
	
	// use array to set the channel name
	public void setName(String[] n) 
	{
		for(int i = 0; i < 3; i++)
		{
			name[i] = n[i];
		}
	}
	// use array to get the channel name
	public String[] getName()
	{
		return name;
	}
	
	private int number;
	
	// preset the channel number
	public Channel()
	{
		number = 0;
	}
	// set the channel number
	public void setNumber(int a)
	{
		number = a;
	}
	// get the channel number
	public int getNumber()
	{
		return number;
	}
	
	// judging the channel number has to up or down
	public void numberUp()
    {
		if(number == 2)number = 0;
        else number++;
    }
	public void numberDown()
    {
        if(number == 0)number = 2;
        else number--; 
    }  	
}
