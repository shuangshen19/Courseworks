# RPG: Adventurer Squad I

## Description of Requirement:
This is a simple RPG game, the setting is that the user can use two characters (the thieves and the monk respectively) to interact with the program by various commands, so that the various commands can allow the user to go deep into the environment and bring himself into In the game, interact with the game; I designed some instructions so that the user can clearly know how to do it next. This should be in line with the needs of the user. I also designed some dialogues to make the game more flexible and flexible. Users are more attractive to this game.

## Inheritance and object design:
I used 5 objects, namely Basecharacter, Robber, Monk, Team, Method. When writing Object, I first recorded the screen that the user would run out when executing; in Basecharacter, I wrote Robber and Monk that are connected Set up (such as food plus HP, etc.), and be regarded as the robber and monk's parent class, and then write down the robber and monk’s respective design (such as the different situations and their skills when unconscious). It can be more convenient to use the main program. In Team, I wrote the functions common to the team (such as gold coins, time, etc.), and in the Method, I wrote the introduction and the function of obtaining the title. These programs can interact with the main program when the main program defines objects, run out of the predetermined screen, and interact with the main program in their respective fields.

## Procedure flow chart:
I designed a while loop and used if-else to input the information for debugging and judging user input:
User input
Follow user input to determine different responses
As shown below

## Player manual:
* run_cmd🡪Compile and enter javachw4.java🡪Enter java hw4 to execute the program
* After completing the above input, the initial screen of the game will run out
* Input the corresponding command to operate, if you forget the command during the game, you can also input the command to get the command
* Enter the corresponding gameplay to get gold coins
* Gold coins can be used to buy water or food to replenish MP and HP
* Enter the corresponding gameplay for adventure and obtain ancient treasures or prophet’s stones
* Finally count the number of various items, and give the corresponding title
* Enter to exit the program

## Other:
My program is roughly divided into 3 parts, the first is the initial screen, the second is the user enters various commands to interact with the program, and the last is to run the corresponding results; the user should enter the corresponding commands and calculation steps to achieve excellence The title.