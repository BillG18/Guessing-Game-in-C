/*
 * GuessingGame.c
 *
 *  Created on: Mar 14, 2016
 *      Author: Billy
 */

#include <stdio.h>

//function checks if a value is within the predefined range of numbers
int ask_in_range(min, max){
	int value;
	while (min >= value || value >= max){//while statement executes as long as the value is outside of the range
		printf("Please enter a number: \n");
		fflush(stdout);//encountered difficulty getting eclipse to print statements as the program was running even though statments all ended with a newline, the easiest slution I could find was to manually "flush" each printf to get the program working
		scanf("%d", &value);//assigns the next input to be the value to be compared within the range
		if (min <= value && value <= max){
			break;//if sucessful (the value is within the range) the loop breaks
		}
		printf("Your number is outside of [%d, %d] range.\n",min, max);//if tge value is incorrect a message is displayed informing the user of the range and the loop begins again
		fflush(stdout);
	}

	return value;//returns the guessed value
}
int guessing_game(num, rangemin, rangemax){
	int guess;//the users guess
	int guesscount = 0;//number of guesses
	while (guess != num){

		guess = ask_in_range(rangemin, rangemax);//calls the ask_in_range function to determine if a guess is valid
		//notifies the user if the guess is too high or too low
		if (guess > num){
			printf("Too high!\n");
			fflush(stdout);
		}
		if (guess < num){
			printf("Too low!\n");
			fflush(stdout);
		}
		guesscount++;//increases the guess count by one for every guess
	}
	printf("Good job! You took %d guesses.", guesscount);
	fflush(stdout);
	return 0;
}


//main function
int main(){

	guessing_game(10, -100, 100);

	return 0;
}
