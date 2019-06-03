#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// refactored adventurer card case
int adventurerRef(struct gameState *state){
    int drawntreasure = 0;
    int currentPlayer = whoseTurn(state);
    int cardDrawn;
    int temphand[MAX_HAND];
    int z = 1;

     while(drawntreasure<2){
	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
	  shuffle(currentPlayer, state);
	}
	drawCard(currentPlayer, state);
	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	  drawntreasure++;
	else{
	  temphand[z]=cardDrawn;
	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
	  z++;
	}
      }
      while(z-1>=0){
	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
	z=z-1;
      }
      return 0;

}

int randomTest()
{
    int numPlayers = rand() % (4-2 + 1) + 2;
    int currentPlayer = rand() % (numPlayers - 2 + 1) + 2;
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    struct gameState* gS = newGame();
    //struct gameState gS;

    initializeGame(numPlayers, kingdomCards, 20, gS);
    int deckCount = gS->handCount[currentPlayer];
    int handPos = rand() % (deckCount) + 1;

    adventurerCase(gS);
    printf(gS->deckCount);

    if(gS->deckCount != (deckCount + 2))
    {
        printf("ERROR: ");
        exit(200);
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    randomTest();
    return 0;
}