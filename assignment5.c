//Salam Fazil
//V00935894

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ROLL 1
#define MAX_ROLL 6
#define MIN_BET 5

int get_bet(int bankroll);
int play_again();
int compute_winnings(int num_matches, int bet);
int get_guess();
void roll_dice(int* die1, int* die2, int* die3);
int count_matches(int guess, int die1, int die2, int die3);
int play_round(int bet);
void play_game(int* bankroll);

int main(void) {

//play_again();


    // a test for get_bet
/*
    int bet = 0;

    printf("testing get_bet with $300 bankroll\n\n");
    bet = get_bet(300);
    printf("finished testing get_bet, returned result: %d", bet);
    printf("(returned result will be dependant on user input, cannot be >300)\n\n");

*/

    // some tests for compute_winnings
/*
    int winnings_result = 0;

    printf("testing compute_winnings with 0 matches and $50\n\n");
    winnings_result = compute_winnings(0, 50);
    printf("finished testing compute_winnings, returned result: %d (should be -50)\n\n", winnings_result);

    printf("testing compute_winnings with 1 match and $150\n\n");
    winnings_result = compute_winnings(1, 150);
    printf("finished testing compute_winnings, returned result: %d (should be 150)\n\n", winnings_result);

    printf("testing compute_winnings with 2 matches and $30\n\n");
    winnings_result = compute_winnings(2, 30);
    printf("finished testing compute_winnings, returned result: %d (should be 60)\n\n", winnings_result);

    printf("testing compute_winnings with 3 matches and $25\n\n");
    winnings_result = compute_winnings(3, 25);
    printf("finished testing compute_winnings, returned result: %d (should be 250)\n\n", winnings_result);

*/

    // some tests for count_matches
/*
    int match_count = 0;

    printf("testing count_matches with none matching\n\n");
    match_count = count_matches(4, 3, 5, 1);
    printf("finished testing count_matches, returned value: %d (should be 0)\n\n", match_count);

    printf("testing count_matches with 1 matching\n\n");
    match_count = count_matches(2, 2, 5, 3);
    printf("finished testing count_matches, returned value: %d (should be 1)\n\n", match_count);

    printf("testing count_matches with 2 matching\n\n");
    match_count = count_matches(3, 3, 5, 3);
    printf("finished testing count_matches, returned value: %d (should be 2)\n\n", match_count);

    printf("testing count_matches with 3 matching\n\n");
    match_count = count_matches(5, 5, 5, 5);
    printf("finished testing count_matches, returned value: %d (should be 3)\n\n", match_count);

    */


    // a test for play_round
/*
    printf("testing play_round with $30 bet\n\n");
    int round_result = play_round(30);
    printf("finished testing play_round with $30 bet, returned value was: %d\n", round_result);
    */

//printf("%d",get_guess());

/*
int a = 0;
int b = 0;
int c = 0;

int* x = &a;
int* y = &b;
int* z = &c;



roll_dice(x, y, z);

printf("%d %d %d", a, b, c);

 */

//play_round(34);

int a = 500;
int* ptr_a = &a;

play_game(ptr_a);

    return 0;
}


// Write your function definitions here:

//Purpose: Keeps prompting the user to enter a bet until he enters a valid one
//Arguments: int - Bankroll, the amount of money the user has
//Returns: int - the valid bet amount the user entered
int get_bet(int bankroll){

    int bet_amount = 0;

    printf("How much money do you want to bet?\n");
    scanf("%d", &bet_amount);

    while(bet_amount < MIN_BET || bet_amount > bankroll){
        printf("Too bad, that's invalid\nHow much money do you want to bet?\n");
        scanf("%d", &bet_amount);
    }
    return bet_amount;
}

//Purpose: Asks the user if he wants to play again after a round has finished
//Arguments: None
//Returns: int - Value
int play_again(){

    int value = 0;
    printf("Do you want to play again? (input 1 for yes and 0 for no)\n");
    scanf("%d", &value);

    while (value != 1 && value != 0){
        printf("Sorry man, that's invalid\nDo you want to play again? (input 1 for yes and 0 for no)\n\n");
        scanf("%d", &value);
    }
    if (value == 0){
        printf("See you later, have fun with your boring life!!!\n");
        return 0;
    }else if (value == 1){
        printf("Woooo!! Let's play again\n\n");
    }
    return value;
}

//Purpose: Calculates how much money has been earned
//Arguments: int - num_matches, the number of matches. int - bet, how much the user bet
//Returns: int - the money earned
int compute_winnings(int num_matches, int bet){

    int money_earned = 0;

    if (num_matches == 0){
        money_earned = 0 - bet;
    }else if(num_matches == 1){
        money_earned = bet * 1;
    }else if(num_matches == 2){
        money_earned = bet * 2;
    }else if(num_matches == 3){
        money_earned = bet * 10;
    }

    return money_earned;
}

//Purpose: Keeps prompting the user to enter a dice roll guess until he enters a valid one
//Arguments: None
//Returns: int - the dice guess of the user
int get_guess(){

    int diceGuess = 0;
    printf("Enter Valid Dice Roll Guess:\n");
    scanf("%d", &diceGuess);

    while(diceGuess < MIN_ROLL || diceGuess > MAX_ROLL){
        printf("That's invalid\nEnter a Valid Dice Roll Guess:\n");
        scanf("%d", &diceGuess);
    }
    return diceGuess;
}

//Purpose: Rolls the 3 die
//Arguments: int* - die1. int* - die2, int* - die3
//Returns: Nothing (void)
void roll_dice(int* die1, int* die2, int* die3){

    *die1 = rand() % (MAX_ROLL - MIN_ROLL + 1) + MIN_ROLL;

    *die2 = rand() % (MAX_ROLL - MIN_ROLL + 1) + MIN_ROLL;

    *die3 = rand() % (MAX_ROLL - MIN_ROLL + 1) + MIN_ROLL;

}

//Purpose: Counts the number of matches
//Arguments: int guess - the users guess. int die1 - the rolled value of die one.
//           int die2 - the rolled value of die two
//           int die3 - the rolled value of die three
//Returns: int - the number of matches
int count_matches(int guess, int die1, int die2, int die3){

    int count = 0;

    if (guess == die1){
        count++;
    }
    if (guess == die2){
        count++;
    }
    if (guess == die3){
        count++;
    }

    return count;
}

//Purpose: Calls the previous functions in order to play 1 round of the game
//Arguments: int bet - the bet
//Returns: int - the money gained or lost (if lost it'll be a negative number
int play_round(int bet){

    int guess = get_guess();

    int acc_value_of_die1 = 0;
    int* ptr_value_of_die1 = &acc_value_of_die1;

    int acc_value_of_die2 = 0;
    int* ptr_value_of_die2 = &acc_value_of_die2;

    int acc_value_of_die3 = 0;
    int* ptr_value_of_die3 = &acc_value_of_die3;

    roll_dice(ptr_value_of_die1, ptr_value_of_die2, ptr_value_of_die3);

    printf("\nYou rolled: %d, %d, %d\n", acc_value_of_die1, acc_value_of_die2, acc_value_of_die3);

    int match_count = count_matches(guess, acc_value_of_die1, acc_value_of_die2, acc_value_of_die3);

    printf("\nYou guessed: %d\n", guess);
    printf("You have %d match(s)\n", match_count);

    int money = compute_winnings(match_count, bet);

    return money;
}

//Purpose: Calls the play_round function and other functions to play the game
//Arguments: int - Bankroll, the amount of money the user has
//Returns: Nothing (void)
void play_game(int* bankroll){

    int bet = get_bet(*bankroll);
    printf("You have bet $%d\n\n", bet);

    int money = play_round(bet);

    *bankroll = *bankroll + money;

    printf("\nYou have $%d left in your bankroll\n\n", *bankroll);

    int check = 0;

        while (*bankroll >= MIN_BET) {
            int value = play_again();

            if (value == 0){
                check = 1;
                break;

            }else {

                bet = get_bet(*bankroll);

                money = play_round(bet);

                *bankroll = *bankroll + money;

                printf("\nYou have $%d left in your bankroll\n\n", *bankroll);
            }
        }
        if (check == 1){
            printf("By the way, you have $%d left in your bankroll", *bankroll);
        }else {
            printf("No More Money, you lost man. Sucks for you. Go do something useful in your life and quit gambling all day");
        }
}