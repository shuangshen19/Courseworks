public class Time 
{
	private String mimicTime;
	
	// preset time
	public Time()
	{
		mimicTime = "08:00";
	}
	
	// pass two values to set the time
	public void setMimicTime(String m, String t) 
	{
		mimicTime = m + ":" + t;
	}
	// get the time
	public String getMimicTime()
	{
		return mimicTime;
	}

	// print the time
	public void printMimicTime()
	{
		System.out.println("The current time: " + mimicTime);
	}
}
