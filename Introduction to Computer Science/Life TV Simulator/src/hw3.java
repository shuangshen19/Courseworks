import java.util.*;
public class hw3
{
	public static void main(String[] args)
	{
		boolean flag = true;
		
		// declare TV names
		String[] tv = {"AATZ", "BBTZ", "CCTZ"};
		// declare show names
		String[][] tvShow = new String [3][4];
		tvShow[0][0] = "GoMoring News";
		tvShow[0][1] = "The News Room";
		tvShow[0][2] = "Weather Night";
		tvShow[0][3] = "Advertising Time";
		tvShow[1][0] = "Studio Classroom";
		tvShow[1][1] = "Taiwanese Drama";
		tvShow[1][2] = "Empresses in the Palace";
		tvShow[1][3] = "Sports Time";
		tvShow[2][0] = "Teletubbies Say Hello";
		tvShow[2][1] = "Little Witch DOREMI";
		tvShow[2][2] = "Phineas and Ferb";
		tvShow[2][3] = "Disney Cinema";
		// declare show contents
		String[][] tvShowContent = new String [3][4];
		tvShowContent[0][0] = "Hello everyone, this is GoMoring News! \nNow, we are going to look at today's news!";
		tvShowContent[0][1] = "Good afternoon, this is the news room. \nI'm Anchor Shen, and now I'm going to report the latest news!";
		tvShowContent[0][2] = "Good evening, this is Weather Night. \nI'm Anchor Shen, and now I'm going to report tomorrow's weather!";
		tvShowContent[0][3] = "This is advertising time. \nThere are many ads you can watch.";
		tvShowContent[1][0] = "This is Studio Classroom! \nWelcome and have a greaat time learning English!";
		tvShowContent[1][1] = "This is a Taiwanese drama. \nThe story is about a snake and a scholar.";
		tvShowContent[1][2] = "This a story about a woman named Zhen Huan lived in a palace.";
		tvShowContent[1][3] = "This is a show about sports. \nThere are many races you can watch.";
		tvShowContent[2][0] = "Teletubbies are saying Hello to you!";
		tvShowContent[2][1] = "This is a story about a girl and her friends becoming witches.";
		tvShowContent[2][2] = "The show follows the adventures of Phineas Flynn and Ferb \nas they seek ways to occupy their time during their summer vacation.";
		tvShowContent[2][3] = "You're now watching the movie: Snow White";
		
		// call classes
		Scanner cin = new Scanner(System.in);
		Time ti = new Time();
		Volume vol = new Volume();
		Channel ch = new Channel();
		Show sh = new Show();
		
		// set and get tv's, show's, content's words
		ch.setName(tv);
		String[] tvGet = ch.getName();
		sh.setName(tvShow);
		String[][] tvShowGet = sh.getName();
		sh.setContent(tvShowContent);
		String[][] tvShowContentGet = sh.getContent();
		
		// welcome the user
		System.out.println("\nWelcome to my TV simulator! Hope you have a great time!");
		System.out.println("You can choose an order to input:\n(channel +, channel -, channel N(N=1,2,3), volume +, volume -, setTime 00:00~23:59)");
		System.out.println("");
		
		do
		{
			// print the preset scene
			System.out.println("The number of the channel: " + (ch.getNumber()+1));
			System.out.println("The name of the channel: " + tvGet[ch.getNumber()]);
			ti.printMimicTime();
			vol.printVolume();
			System.out.println("The name of the show: " + tvShowGet[ch.getNumber()][sh.getNumber()]);
			System.out.println("-----------------------------------------------------------");
			System.out.println(tvShowContentGet[ch.getNumber()][sh.getNumber()]);
			System.out.println("===========================================================");
			System.out.print("Please input an order: ");
			String input = cin.nextLine();
			System.out.println("===========================================================");
			int space = input.indexOf(" ");
			
			try
			{
				// seperate the input words
				String input1 = input.substring(0,space);
				String input2 = input.substring(space+1,input.length());
			
				// input exit
				if(input.equals("exit"))
				{
					flag = false;
					break;
				}
				if(input1.equals("channel"))
				{
					// input channel and input + or - or 1 or 2 or 3 or so on sitiuations
					switch(input2.charAt(0))
					{
						case '+':
							ch.numberUp();
							break;
					
						case '-':
							ch.numberDown();
							break;
					
						default:
							int x = Integer.parseInt(input2);
							switch(x)
							{
								case 1:
									ch.setNumber(x - 1);
									break;
					
								case 2:
									ch.setNumber(x - 1);
									break;
					
								case 3:
									ch.setNumber(x - 1);
									break;
							
								default:
									System.out.println("Wrong channel symbol input!");
									break;
							}
							break;
					}
				}
				else if(input1.equals("volume"))
				{
					// input volume and input + or - or so on situations
					if(input2.equals("+"))vol.volumeUp();
					else if(input2.equals("-"))vol.volumeDown();	
					else System.out.println("Wrong volume symbol input!");
				}
				else if(input1.equals("setTime"))
				{
					// seperate the second part of the input words
					int semicolon = input2.indexOf(":");
					String hour = input2.substring(0,semicolon);
					String minute = input2.substring(semicolon+1,input2.length());
					// send hour and minute to Time class
					ti.setMimicTime(hour,minute);
					int h = Integer.parseInt(hour);
					int m = Integer.parseInt(minute);
				
					// judging the show time has to be
					if(h >= 0 && h < 24 && m >= 0 && m < 60)
					{
						int total;
						total = h * 60 + m;
				
						if(total > 240 && total <= 660)sh.setNumber(0);
						else if(total > 660 && total <= 840)sh.setNumber(1);
						else if(total > 840 && total <= 1200)sh.setNumber(2);
						else if(total <= 240 || total > 1200)sh.setNumber(3);
					}
					else System.out.println("Wrong time input! Please input setTime 00:00~23:59!");
				}
				else System.out.println("Wrong input! Please input an order!");
			}
			catch(Exception e)
			{
				System.out.println("Wrong input! Please input an order!");
				continue;
			}
		}while(flag = true);
		System.out.println("Thank you for your watching! Have a good day!");
	}
}	