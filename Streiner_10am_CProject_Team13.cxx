#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <iostream>


// Team 13, Harrison George Dom


//Title:ENERGY BUILT TO “GO WITH THE FLOW”
//Our paper is on the sustainability, evaluation, application, and future of flow batteires. 
//Lithium ions seem to often cause fires and harm nature. 
//This is why we researched the flow battery and it's capabilities to be an alternative to the usual lithium ion battery.

//Our app gives the user of their choice between playing a Charge Casino game, learning about the flow battery, and comparing flow batteries to their own batteries.
//In the Charge casion game you will play a maybe familiar card game but instead you win volts to charge your battery!
//The second option will provide a paragraph about how the mechanics of a flow battery works.
//The third option would tell you how much longer your car would last if it was using a vanadium flow batttery.




// Function prototypes

int value(void);
void playBlackjack();
int dealerturn(int dealerScore, int dealerCard);
void winnercheck(int playerscore, int dealerscore);
int playerturn(int playerscore, char choice, int playerCard);
int batlife(int);
char goagain();

int main() {
	char choice;
	int choice1;

	do{
	choice1=value();
	
	/*****************************************************************************************************/
	// game feature, do while sequencing for error checking
	if(choice1==1)
	{
	do{
		
		playBlackjack();
		do{
			choice = goagain();
		}while((choice != 'y')&&(choice != 'n')&&(choice != 'Y')&&(choice != 'N'));
	}while((choice == 'Y') || (choice == 'y'));
	
	}
	/*****************************************************************************************************/
	// information on the vanadium battery
	else if(choice1==2)
	{
		printf("The current design for these large-scale batteries is just multiple smaller cells spot welded together to a conductive material such as nickel in series to achieve a high voltage.\nThis is why separating the anode and cathode from each other was the design for the flow battery.\nA flow battery is structured by having two tanks, one for positive particles and one for negative particles, on either side of a stack of cells.\nThere are pipes that connect each tank to the cell stack that pump a liquid electrolyte throughout the system which transfers the electrons to the cell stack and then into a power converter.\nThis structure orientation can generate electricity by a series of electrochemical interactions between the two substances in either tank.\nWhen the battery is in a state of charging, the electrons within the mixture are pushed to a non-ideal state which creates a growing potential energy for the electrons to return to a favorable position.\n\n");
	}
	/*****************************************************************************************************/
	else if(choice1==3)
	{
		int carbat,vlife,llife;
		carbat = batlife(carbat);
		
		
		vlife=20-carbat;
		llife=4-carbat;
	
	// giving advice on the current life of user battery
		printf("If you had a vanadium battery, your car battery would last for %d more years.\n",vlife);
	if (llife==0)
	{
		printf("\nIt is time to get your battery replaced!\n");
		printf("\n you are generally supposed to change your car battery every 4 years.\n");
	}
	else if (llife<=0)
	{
		printf("Your car battery is %d year(s) out of date! \nGet a new one unless you enjoy jump starting your car!\n",llife);
	}
	else
	{
		printf("You have about %d year(s) of battery life left before you should get it replaced.\n",llife);
	}

	}
	}while(1);
    return 0;
}
/*****************************************************************************************************/
// function for running the game once again
char goagain(){
char choice;

printf("would you like to play again? y/n\n");
		scanf(" %c", &choice);
		return(choice);
	
}



/*****************************************************************************************************/
// function to get user selected feature
int value(void)
{
	int choice1;
	

	printf("\n\nEnter a 1 if you would like to play a Charge Casino game\nEnter a 2 if you would like to learn about how the Flow Battery works\nEnter a 3 if you would like to compare your battery to a flow battery: ");
	scanf("%d",&choice1);	do
	{
	}while(choice1!=1 && choice1 !=2 && choice1!=3);
	
	printf("\n\n\n");
	
	return(choice1);
}

/*****************************************************************************************************/
// runs battery game feature
void playBlackjack() {
    int playerscore = 0, dealerscore = 0;
    int playerCard, dealerCard;
    char choice;
    printf("\n\n\ncharge your lithium battery as close as you can to 21 without going over, if you do, it is too bad your battery is\n made with lithium because your battery might just explode!\n\n");
    
    // Initial draw
    playerCard = rand() % 10;
    playerscore += playerCard;
    printf("the initial charge on your battery is %d\n", playerscore);

    dealerCard = rand() % 10;
    dealerscore += dealerCard;
    
    printf("the initial charge on the dealer's battery is %d\n", dealerscore);
    
    playerscore = playerturn(playerscore,choice,playerCard);
    dealerscore = dealerturn(dealerscore,dealerCard);
    winnercheck(playerscore, dealerscore);
}


/*****************************************************************************************************/

    // Player's turn
int playerturn(int playerscore, char choice, int playerCard){
    while (playerscore < 21) {
		do{
        printf("Do you want another charge? (y/n): ");
        scanf(" %c", &choice);
        }while((choice != 'y')&&(choice != 'n'));
        if (choice == 'y') {
            playerCard = rand() % 10;
            playerscore += playerCard;
            printf("Your Battery is at: %d volts\n", playerscore);
        }
        else {
            break;
		}
		
        
    
    }
    return(playerscore);
}
/*****************************************************************************************************/

    // Dealer's turn
int dealerturn(int dealerscore, int dealerCard){
    while (dealerscore < 17) {
        dealerCard = rand() % 10;
        dealerscore += dealerCard;
        
        
    }
    return(dealerscore);
    }
    
/*****************************************************************************************************/


    // Determine the winner
void winnercheck(int playerscore, int dealerscore){
    printf("Dealer's charge: %d\n", dealerscore);
    printf("Your Battery is at: %d volts\n", playerscore);
    if (playerscore > 21) {
        printf("You battery exploded! Dealer wins.\n");
    } else if (dealerscore > 21 || playerscore > dealerscore) {
        printf("You win! your battery is fully charged\n");
    } else if (playerscore < dealerscore) {
        printf("Dealer's battery charged first.\n");
    } else {
        printf("It's a tie!\n");
    }
}
/*****************************************************************************************************/
// function for getting user battery life
int batlife(int carbat){
	
	printf("Welcome to the Battery Estimator!\n");
	printf("Please enter how long you have had your current car battery for (in years) : \n\n");
	
	scanf("%d",&carbat);
	return(carbat);
}






