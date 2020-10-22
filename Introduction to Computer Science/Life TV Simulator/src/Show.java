public class Show 
{
	private String[][] name = new String[3][4];
	private String[][] content = new String[3][4];	
	
	// use array to set the show name
	public void setName(String[][] s)
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				name[i][j] = s[i][j];
			}
		}
	}
	// use array to set the show content
	public void setContent(String[][] c)
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				content[i][j] = c[i][j];
			}
		}
	}
	// use array to get the show name
	public String[][] getName()
	{
		return name;
	}
	// use array to get the show content
	public String[][] getContent()
	{
		return content;
	}
	
	private int number;
	
	// preset the show number
	public Show()
	{
		number = 0;
	}
	
	// set the show number
	public void setNumber(int a)
	{
		number = a;
	} 
	// get the show number
	public int getNumber()
	{
		return number;
	}
}
