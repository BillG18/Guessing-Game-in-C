/*
 * GuessingGameRandom.c
 *
 *  Created on: Mar 14, 2016
 *      Author: Billy
 */

#include <stdio.h>


int guesscount = 0;//number of guesses
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
int guessing_game_random(rangemin, rangemax){
	int guess;//the users guess


	int range;//range number can be generated in
	int num;//number generated

	//defines the possible range and value of random integer using absoulte value and random functions from studio h
	range = abs(rangemin)+abs(rangemax);
	srand(time(NULL));//updates the seed used for randomization in order to avoid repeatedly generating the same number
	num = rand() % range + (rangemin);


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
	printf("Good job! You took %d guesses.\n", guesscount);
	fflush(stdout);
	return 0;
}


//main function
int main(){
	//int prevscore=0;

	guessing_game_random(-500, 500);


	//converts the text in a file to chracters and returns the characters that are the previous high score
	FILE *pointer = fopen("score.txt", "r");
	char score[4];
	fgets(score, 4, pointer);
	printf("The previous player had a score of: %s\nHow'd you do?\n", score);
	fflush(stdout);
	fclose(pointer);

	//opens a file and rewrites the score to be the number of guesses from the curren tplayer before closing
	FILE *pointer2 = fopen("score.txt", "w+");
	fprintf(pointer2, "%d", guesscount);
	fclose(pointer);

	return 0;
}

//in the worst possible scenario it may take up to 999 guesses before finding the value when the range is (-500, 500)
