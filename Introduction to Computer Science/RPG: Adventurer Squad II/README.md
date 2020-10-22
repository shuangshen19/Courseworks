# RPG: Adventurer Squad II

## Description of Requirement:
This is an upgraded version of the previous RPG game. It adds a new character (bard), and also adds settings for building a hut and saving/reading files. Various commands can be used to interact with the program to make the user more than the previous one. I have designed some commands, such as: save/read files, so that the user can pause the game in the middle, which makes the game more convenient, and I also designed some small commands to make the user clear I know how to do it next. This should be in line with the needs of the user. I also continued the concept of the previous game and designed a small dialogue to make the game more flexible and make the user more interested in this game.

## Inheritance and object design:
I used 6 objects, namely Basecharacter, Robber, Monk, Bard, Team, and Method. When writing Object, I first booked the screen that the user would run out when executing. In Basecharacter, I wrote Robber, Monk and The same settings in Bard (such as HP for eating, FP during rest, etc.), and regarded as robbers, the parent class of the monks and Bard, and then write the robbers, the monks and Bard’s needs. The design (such as the different situations in the coma and the respective skills and the skills of building a hut) allows me to use the main program more efficiently. In Teamri, I wrote the functions common to the team (such as gold coins, time, huts, etc.) Programs can interact with the main program when defining objects in the main program, run out of the screen, and interact with the main program in their respective fields.

## Procedure flow chart:
I designed a while loop and used if-else to input the information for debugging and judging user input:
User input
Follow user input to determine different responses
As shown below

## Player manual:
* run_cmd🡪compile enter javachw5.java🡪 enter java hw5 to execute the program
* After completing the above input, the initial screen of the game will run out
* Input the corresponding command to operate, if you forget the command during the game, you can also input the command to get the command
* Enter the corresponding gameplay to get gold coins
* Gold coins can be used to buy water or food to replenish MP and HP
* You can also save the file midway, and the knight will continue to play next time
* Enter the corresponding gameplay for adventure and obtain ancient treasures or prophet’s stone or dragon egg
* Build huts to make the environment more comfortable
* The final count of the number of various items and the level of the cabin, so as to give the corresponding title
* Enter to exit the program

## Other:
My program is roughly divided into 4 parts. The first is the initial screen, the second is for the user to input various commands to interact with the program, the third is for saving/reading files, and the last is for running out the corresponding results; the user must input the corresponding The weighing number can be obtained according to the instructions and calculation method steps.
