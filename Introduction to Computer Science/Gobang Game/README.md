# Gobang Game

## Descriptions
This time the content is a simplified version of the Gobang game. Two players are provided with black and white in turn to play on a 15x15 board, and the black plays first. When a player has reached a five-point connection (horizontal, vertical or oblique connection), the player wins. If the board is filled but no five-piece connection is generated, the game ends with a tie. The special feature of this system is that if no parameters are given when the program is executed, the game will start with a blank board; if the endgame file name is given as the execution parameter, such as `a.out chess1.txt`, the endgame will be this. The state of the board at the beginning of the game, the system will determine the next player based on the number of black and white pieces in the endgame, and continue the game until the winner is determined. Note: Endgame is a default board state, please refer to the attached `Endgame Format Description`

## Program flow:
This time the program is a matching game. I assume that users will have three requirements. The first is the beautiful user interface, the second is the simple and clear guidance, and the third is other more convenient functions. In response to these needs, I designed a square chessboard, and added some digital signs to make the screen more beautiful; and a simple operation mode, like the instructions at the beginning, is concise and clear. The chessboard arranged in order allows the user to understand at a glance The chess pieces put down; and I also designed the function of leaving and saving (you can directly enter exit or save when inputting), so that it can save the unfinished chess game in the middle and leave; I think my design can attract The user's place is my simple operation method and special additional functions, and the simplified chessboard can see all the chess pieces at once.

I designed the function of loop and input debugging and judge the coordinate code EX.[5-9] entered by the user:
* Exquisite chessboard
* User input
* Judge different responses based on user input

## Function/logic description:
1. Input debugging function, so that users can quickly know where their input is wrong
2. Exit function (enter exit directly), allowing users to leave the game directly
3. Save function (input save directly), so that the user can keep the unfinished game for the next connection
I designed the if function to judge whether the user input is correct and how to run out in the next step, and added the function of leaving and saving; when judging the coordinate position, I used the function of cutting to save Corresponding data of each chess piece, and when judging the function of connecting five pieces and reporting horses, I also used the if function as a judgment.

## Instructions for use:
1. Run the program
2. After completing the above input, the initial screen and simple operating instructions will appear
3. Enter the corresponding instruction, if you make a mistake, you will be reminded and can be entered again
4. Enter the coordinates (EX. [5-9])
5. Two users take turns to play chess, the black player plays first, if you want to leave first, you can use the storage function
6. When Sizi connects, it will run out to remind another user
7. Unlimited input is allowed, until the board is full or five pieces of connection or input exit to end the program

## Other:
My program is roughly divided into 4 parts, the first is the initial screen, the second is the user input coordinates, the third part is to determine what function the user enters, and finally the corresponding result is run; the user only needs to enter the corresponding The corresponding instruction can be.