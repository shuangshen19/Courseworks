# Vending Machine

## Descriptions
This time the program requires us to design the computerized simulation of the vending machine. I assume that the user (customers) will have two kinds of demand.
1. The user wants humanized operating instructions
2. Simple and precise operation interface
   
In response to these needs, I designed a clearly operation mode, which is like a normal menu. The order is well arranged and simple and beautiful so that users can operate happily. The attraction of my design is the simple and clear menu layout. I can see all the options at once, not distract them to choose.

## Program flow:
I designed the function of looping and inputting errors and judging the beverage code entered by the user:
1. User input
2. Determine different responses based on user input

## Function/logic description:
I designed an array for the function of menu layout to check whether there is inventory. If yes, it will display yes. To determine what kind of beverage code the user enters and how much to pay, I designed the if function to judge whether the user input is correct and how to run the next step.

## Instructions for use:
1. Enter TCF compile hw1.c to execute the program
2. After completing the above input, the screen of the simulated vending machine will appear
3. Enter the corresponding instruction to operate, if the input is wrong, it will run out to remind you and re-enter
4. Unlimited input is allowed until 8888 is entered to end the program

## Other:
My program is roughly divided into 3 parts, the first is the initial screen, the second is the user enter the beverage code, and finally in order to run the corresponding result, the user only needs to input the corresponding command.