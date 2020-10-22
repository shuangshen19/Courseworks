import java.util.*;
public class hw4
{
	public static void main(String[] args)
	{
		// initialize
		Team team = new Team(1,0,0,0);
		Robber robber = new Robber(0);
		Monk monk = new Monk(0);
		Method method = new Method();
		Scanner cin = new Scanner(System.in);
		boolean flag = true;
		
		// introduce the game
		System.out.println("Welcome to my adventurers team!");
		method.Introduction();
		
		while(flag)
		{
			try{
			// start the game
			System.out.println("\nPresent Day: " + team.getDay());
			System.out.println("======================================================================");
			System.out.print("Please input an order: ");
			String input = cin.nextLine();
			System.out.println("======================================================================");
			
			// exit function
			if(input.equals("exit"))
			{
				flag = false;
				continue;
			}
			else if(input.equals("instruction"))method.Introduction();
			// help function
			else if(input.equals("help"))method.Instruction();
			// status function
			else if(input.equals("status"))
			{
				// print all status 
				System.out.print("Team Status: ");
				team.printStatus();
				System.out.print("Robber Status: ");
				robber.printStatus();
				System.out.print("Monk Status: ");
				monk.printStatus();
				System.out.println("Treasure: " + robber.getTreasure() + ",Jewel: " + monk.getJewel());
			}
			// rest and rest day function
			else if(input.substring(0,4).equals("rest"))
			{
				// judge the game is or isn't lack of food
				// if isn't, rest or rest day, and print all status 
				switch(input)
				{
					case "rest":
						if(team.getFood() == 0)
						{
							System.out.println("You don't have enough food.");
							flag = false;
							continue;
						}
						else 
						{
							team.rest();
							robber.rest();
							monk.rest();
							System.out.print("Team Status: ");
							team.printStatus();
							System.out.print("Robber Status: ");
							robber.printStatus();
							System.out.print("Monk Status: ");
							monk.printStatus();
							System.out.println("Treasure: " + robber.getTreasure() + ",Jewel: " + monk.getJewel());
						}
						break;
					
					case "rest 2":
						if(team.getFood() < 2)
						{
							System.out.println("You don't have enough food.");
							flag = false;
							continue;
						}
						else 
						{	
							team.restDay(2);
							robber.rest();
							monk.rest();
							System.out.print("Team Status: ");
							team.printStatus();
							System.out.print("Robber Status: ");
							robber.printStatus();
							System.out.print("Monk Status: ");
							monk.printStatus();
							System.out.println("Treasure: " + robber.getTreasure() + ",Jewel: " + monk.getJewel());
						}
						break;
						
					case "rest 3":
						if(team.getFood() < 3)
						{
							System.out.println("You don't have enough food.");
							flag = false;
							continue;
						}
						else 
						{
							team.restDay(3);
							robber.rest();
							monk.rest();
							System.out.print("Team Status: ");
							team.printStatus();
							System.out.print("Robber Status: ");
							robber.printStatus();
							System.out.print("Monk Status: ");
							monk.printStatus();
							System.out.println("Treasure: " + robber.getTreasure() + ",Jewel: " + monk.getJewel());
						}
						break;
						
					case "rest 4":
						if(team.getFood() < 4)
						{
							System.out.println("You don't have enough food.");
							flag = false;
							continue;
						}
						else 
						{
							team.restDay(4);
							robber.rest();
							monk.rest();
							System.out.print("Team Status: ");
							team.printStatus();
							System.out.print("Robber Status: ");
							robber.printStatus();
							System.out.print("Monk Status: ");
							monk.printStatus();
							System.out.println("Treasure: " + robber.getTreasure() + ",Jewel: " + monk.getJewel());
						}
						break;
						
					case "rest 5":
						if(team.getFood() < 5)
						{
							System.out.println("You don't have enough food.");
							flag = false;
							continue;
						}
						else 
						{
							team.restDay(5);
							robber.rest();
							monk.rest();
							System.out.print("Team Status: ");
							team.printStatus();
							System.out.print("Robber Status: ");
							robber.printStatus();
							System.out.print("Monk Status: ");
							monk.printStatus();
							System.out.println("Treasure: " + robber.getTreasure() + ",Jewel: " + monk.getJewel());
						}
						break;
						
					case "rest 6":
						if(team.getFood() < 6)
						{
							System.out.println("You don't have enough food.");
							flag = false;
							continue;
						}
						else 
						{
							team.restDay(6);
							robber.rest();
							monk.rest();
							System.out.print("Team Status: ");
							team.printStatus();
							System.out.print("Robber Status: ");
							robber.printStatus();
							System.out.print("Monk Status: ");
							monk.printStatus();
							System.out.println("Treasure: " + robber.getTreasure() + ",Jewel: " + monk.getJewel());
						}
						break;
						
					case "rest 7":
						if(team.getFood() < 7)
						{
							System.out.println("You don't have enough food.");
							flag = false;
							continue;
						}
						else 
						{
							team.restDay(7);
							robber.rest();
							monk.rest();
							System.out.print("Team Status: ");
							team.printStatus();
							System.out.print("Robber Status: ");
							robber.printStatus();
							System.out.print("Monk Status: ");
							monk.printStatus();
							System.out.println("Treasure: " + robber.getTreasure() + ",Jewel: " + monk.getJewel());
						}
						break;
						
					case "rest 8":
						if(team.getFood() < 8)
						{
							System.out.println("You don't have enough food.");
							flag = false;
							continue;
						}
						else 
						{
							team.restDay(8);
							robber.rest();
							monk.rest();
							System.out.print("Team Status: ");
							team.printStatus();
							System.out.print("Robber Status: ");
							robber.printStatus();
							System.out.print("Monk Status: ");
							monk.printStatus();
							System.out.println("Treasure: " + robber.getTreasure() + ",Jewel: " + monk.getJewel());
						}
						break;
						
					case "rest 9":
						if(team.getFood() < 9)
						{
							System.out.println("You don't have enough food.");
							flag = false;
							continue;
						}
						else 
						{
							team.restDay(9);
							robber.rest();
							monk.rest();
							System.out.print("Team Status: ");
							team.printStatus();
							System.out.print("Robber Status: ");
							robber.printStatus();
							System.out.print("Monk Status: ");
							monk.printStatus();
							System.out.println("Treasure: " + robber.getTreasure() + ",Jewel: " + monk.getJewel());
						}
						break;
						
					default:
						System.out.println("Wrong rest day input!");
						break;
				}
			}
			// skill robber loot function
			else if(input.equals("skill robber loot"))
			{  
				// judge MP and HP whether correspond the standard
				if(robber.getMP() >= 20)
				{
					if(robber.getHP() > 30)
					{
						team.loot();
						robber.loot();
						System.out.println("Gold+2, Robber HP-30, MP-20, FP+40");
						System.out.println("======================================================================");
						System.out.println("Gold: " + team.getGold());
						System.out.print("Robber Status: ");
						robber.printStatus();
					}
					// HP=0, went into a coma
					else
					{
						team.loot();
						robber.comaLoot();
						System.out.println("Gold+2, Robber HP-30, MP-20, FP+40");
						System.out.println("Robber's HP = 0, robber went into a coma.");
						System.out.println("======================================================================");
						System.out.println("Team activities stop 3 days!");	
						if(team.getFood() < 3)
						{
							System.out.println("Gold: " + team.getGold());
							System.out.println("You don't have enough food!");
							flag = false;
							continue;
						}
						else
						{
							team.coma();
							robber.afterComa();
							monk.rest();
							System.out.println("~~~~~~~~~~~~~~~~~~ COMA TIME ~~~~~~~~~~~~~~~~~~~");
							System.out.println("Robber's HP changes to 50, FP changes to 0, Monk's FP changes to 0.");
							System.out.print("Team Status: ");
							team.printStatus();
							System.out.print("Robber Status: ");
							robber.printStatus();
							System.out.print("Monk Status: ");
							monk.printStatus();
						}
					}
				}
				else System.out.println("You don't have enough MP to loot.");
			}
			// skill monk heal function
			else if(input.equals("skill monk heal monk"))
			{
				monk.healMonk();
				System.out.println("Monk HP+65, Monk MP-30, FP+30");
				System.out.println("======================================================================");
				System.out.print("Monk Status: ");
				monk.printStatus();
			}
			else if(input.equals("skill monk heal robber"))
			{
				monk.healRobber();
				robber.healByMonk();
				System.out.println("Robber HP+65, Monk MP-30, FP+30");
				System.out.println("======================================================================");
				System.out.println("Robber HP: " + robber.getHP());
				System.out.println("Monk MP: " + monk.getMP());
				System.out.println("Monk FP: " + monk.getFP());
			}
			// skill robber adventure
			else if(input.equals("skill robber adventure"))
			{
				// judge the day whether correspond the standard (2,4,6,8,10)
				if(team.getDay() % 2 == 0)
				{
					// judge the HP and MP whether correspond the standard
					if(robber.getMP() >= 30)
					{
						if(robber.getHP() > 60)
						{
							robber.adventure();
							System.out.println("Treasure+1, Robber HP-60, MP-30, FP+40");
							System.out.println("======================================================================");
							System.out.println("Robber Status: ");
							robber.printStatus();
							System.out.println("Treasure: " + robber.getTreasure());
						}
						else
						{
							// HP=0, went into a coma
							robber.comaAdventure();
							System.out.println("Treasure+1, Robber HP-60, MP-30, FP+40");
							System.out.println("Robber's HP = 0, robber went into a coma.");
							System.out.println("======================================================================");
							System.out.println("Team activities stop 3 days!");
							System.out.println("Treasure: " + robber.getTreasure());
							if(team.getFood() < 3)
							{
								System.out.println("You don't have enough food!");
								flag = false;
								continue;
							}
							else
							{
								team.coma();
								robber.afterComa();
								monk.rest();
								System.out.println("~~~~~~~~~~~~~~~~~~ COMA TIME ~~~~~~~~~~~~~~~~~~~");
								System.out.println("Robber's HP changes to 50, FP changes to 0, Monk's FP changes to 0.");
								System.out.print("Team Status: ");
								team.printStatus();
								System.out.print("Robber Status: ");
								robber.printStatus();
								System.out.print("Monk Status: ");
								monk.printStatus();
							}	
						}	
					}		
					else System.out.println("You don't have enough MP to adventure.");	
				}
				else System.out.println("You can use Robber Adventure when the day is 2, 4, 6, 8, 10.");
			}
			// skill monk adventure
			else if(input.equals("skill monk adventure"))
			{
				// judge the day whether correspond the standard (3,6,9)
				if(team.getDay() % 3 == 0)
				{
					// judge the HP and MP whether correspond the standard
					if(monk.getMP() >= 60)
					{
						if(monk.getHP() > 60)
						{
							monk.adventure();
							System.out.println("Jewel+1, Monk HP-60, MP-60, FP+60");
							System.out.println("======================================================================");
							System.out.println("Monk Status: ");
							monk.printStatus();
							System.out.println("Jewel: " + monk.getJewel());
						}
						else
						{
							// HP=0, went into a coma
							monk.comaAdventure();
							System.out.println("Jewel+1, Monk HP-60, MP-60, FP+60");
							System.out.println("Monk's HP = 0, monk went into a coma.");
							System.out.println("======================================================================");
							System.out.println("Team activities stop 3 days!");
							System.out.println("Jewel: " + monk.getJewel());
							if(team.getFood() < 3)
							{
								System.out.println("You don't have enough food!");
								flag = false;
								continue;
							}
							else
							{
								team.coma();
								monk.afterComa();
								robber.rest();
								System.out.println("~~~~~~~~~~~~~~~~~~ COMA TIME ~~~~~~~~~~~~~~~~~~~");
								System.out.println("Monk's HP changes to 50, FP changes to 0, Robber's FP changes to 0.");
								System.out.print("Team Status: ");
								team.printStatus();
								System.out.print("Robber Status: ");
								robber.printStatus();
								System.out.print("Monk Status: ");
								monk.printStatus();
							}
						}	
					}			
					else System.out.println("You don't have enough MP to adventure.");
				}	
				else System.out.println("You can use Monk Adventure when the day is 3, 6, 9.");
			}		
			// buy_food and buy_drink function
			// if gold=0, you can't buy anything
			else if(input.equals("skill robber buy_food"))
			{
				if(team.getGold() > 0)
				{
					team.buy_food();
					robber.buy_food();
					System.out.println("Gold-1, Food+2, Robber FP+10");
					System.out.println("======================================================================");
					System.out.println("Gold: " + team.getGold());
					System.out.println("Food: " + team.getFood());
					System.out.println("Robber FP: " + robber.getFP());
				}
				else System.out.println("You don't have enough gold.");
			}
			else if(input.equals("skill robber buy_drink"))
			{
				if(team.getGold() > 0)
				{
					team.buy_drink();
					robber.buy_drink();
					System.out.println("Gold-1, Drink+1, Robber FP+10");
					System.out.println("======================================================================");
					System.out.println("Gold: " + team.getGold());
					System.out.println("Drink: " + team.getDrink());
					System.out.println("Robber FP: " + robber.getFP());
				}
				else System.out.println("You don't have enough gold.");
			}
			else if(input.equals("skill monk buy_food"))
			{
				if(team.getGold() > 0)
				{
					team.buy_food();
					monk.buy_food();
					System.out.println("Gold-1, Food+2, Monk FP+10");
					System.out.println("======================================================================");
					System.out.println("Gold: " + team.getGold());
					System.out.println("Food: " + team.getFood());
					System.out.println("Monk FP: " + monk.getFP());
				}
				else System.out.println("You don't have enough gold.");
			}
			else if(input.equals("skill monk buy_drink"))
			{
				if(team.getGold() > 0)
				{
					team.buy_drink();
					monk.buy_drink();
					System.out.println("Gold-1, Drink+1, Monk FP+10");
					System.out.println("======================================================================");
					System.out.println("Gold: " + team.getGold());
					System.out.println("Drink: " + team.getDrink());
					System.out.println("Monk FP: " + monk.getFP());
				}
				else System.out.println("You don't have enough gold.");
			}	
			// eat food/drink function
			// if food/drink=0, you can't eat anything
			else if(input.equals("item robber food"))
			{
				if(team.getFood() > 0)
				{
					team.eat();
					robber.eat();
					System.out.println("Food-1, Robber HP+40");
					System.out.println("======================================================================");
					System.out.println("Food: " + team.getFood());
					System.out.println("Robber HP: " + robber.getHP());	
				}
				else System.out.println("You don't have enough food.");
			}
			else if(input.equals("item robber drink"))
			{
				if(team.getDrink() > 0)
				{
					team.drink();
					robber.drink();
					System.out.println("Drink-1, Robber MP+60");
					System.out.println("======================================================================");
					System.out.println("Drink: " + team.getDrink());
					System.out.println("Robber MP: " + robber.getMP());
				}
				else System.out.println("You don't have enough drink.");
			}
			else if(input.equals("item monk food"))
			{
				if(team.getFood() > 0)
				{
					team.eat();
					monk.eat();
					System.out.println("Food-1, Monk HP+40");
					System.out.println("======================================================================");
					System.out.println("Food: " + team.getFood());
					System.out.println("Monk HP: " + monk.getHP());
				}
				else System.out.println("You don't have enough food.");
			}
			else if(input.equals("item monk drink"))
			{
				if(team.getDrink() > 0)
				{
					team.drink();
					monk.drink();
					System.out.println("Drink-1, Monk MP+60");
					System.out.println("======================================================================");
					System.out.println("Drink: " + team.getDrink());
					System.out.println("Monk MP: " + monk.getMP());
				}
				else System.out.println("You don't have enough drink.");
			}
			else System.out.println("Wrong instruction input!");
			
			// (forced to rest situation)if one of both FP>=100, forced to rest
			if(monk.getFP() >= 100 || robber.getFP() >= 100)
			{
				team.rest();
				robber.rest();
				monk.rest();
				if(team.getFood() < 0)
				{
					System.out.println("You don't have enough food!");
					flag = false;
					continue;
				}
				else
				{
					System.out.println("One or Both character FP >= 100!");
					System.out.println("Team rest, Day+1");
					System.out.println("======================================================================");
					System.out.println("Pressent Day: " + team.getDay());
					System.out.println("Robber FP: " + robber.getFP());
					System.out.println("Monk FP: " + monk.getFP());
				}
			}
			// if day > 10, end game
			if(team.getDay() > 10)
			{
				flag = false;
				continue;
			}
			}	
			// catch the exceptions
			catch(StringIndexOutOfBoundsException e)
			{
				System.out.println("Wrong instruction input!");
			}
			catch(Exception e)
			{
				System.out.println("Wrong input!");
			}
		}
		
		// get title
		method.Title(robber.getTreasure(),monk.getJewel(),team.getGold(),team.getFood(),team.getDrink());
		// sentence of end game 
		method.EndGame();
	}
}	