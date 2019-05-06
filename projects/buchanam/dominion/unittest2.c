#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int testSmithyRefactored()
{
    // create testing environment
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy};
    struct gameState G;

    initializeGame(2, k, 20, &G);
    int handPos = 0;
    int currentPlayer = whoseTurn(&G);

    int previousHandCount = G.handCount[currentPlayer];
    smithyCase(currentPlayer, &G, handPos);
    if (*(G.handCount) != previousHandCount)
        printf("smithyRefactored(): PASS when handcount changes when Smithy is called\n");
    else
        printf("smithyRefactored(): FAIL when handcount doesn't change when Smithy is called\n");

    return 0;
}

int main(int argc, char *argv[])
{
    testSmithyRefactored();
    return 0;
}