# Matching Game

## Descriptions
This assignment requires students to implement a flop matching game that allows two players to play in C language. This system must cover 52 playing cards and provide a game interface for players with 13 * 4 coordinates, allowing players to choose by inputting coordinates For the cards to be turned over, the system must determine whether the two cards turned over by the player are playing cards of the same number. If they are the same, the player gathers, the system removes the cards from the array, and the player can continue to turn the cards. If the numbers are not the same, the two cards will be covered, and another player will make the flop. When all the cards in the array have been removed, the game ends and the game result is displayed.

## Program flow:
This time the program is a matching game. I assume that users will have three requirements.
1. Easy-to-understand operating instructions
2. Beautiful interface
3. Remove the cards that have been matched
In response to these needs, I designed a simple operation mode. Like the initial instructions, it is very concise and clear. The coordinate positions arranged in order allow the user to operate happily, and once the card is removed, the screen will still be the same. Neat and beautiful; I think my design can attract users because of my streamlined and beautiful layout and simple operation methods. I can see all the options at once without making users feel confused.

## Program flow:
I designed the function of looping and inputting error detection and judging the coordinate code input by the user:
1. User input
2. Determine different responses based on user input

## Function/logic description:
I designed an array for the function of coordinate typesetting to run out a more beautiful screen; while judging user input, I designed the if function to judge whether the user input is correct and how to run it next, and use many arrays and cutting The function to store the corresponding information of each card.

## Instructions for use:
1. Compile hw2.c to execute the program
2. After completing the above input, the initial screen and simple operating instructions will appear
3. Enter the corresponding instruction, that is, enter the coordinates ((01,02) and (03,04) input as 01,02,03,04), etc. to operate, if you make a mistake, you will be reminded and you can enter again
4. Unlimited input is allowed until the cards are fully matched or enter exit to end the program

## Other:
My program is roughly divided into 4 parts, the first is the initial screen, the second is the user's input coordinates, the third part is to determine whether the user has repeatedly entered the matching cards, and finally the corresponding result is run; Only need to input the corresponding instruction.