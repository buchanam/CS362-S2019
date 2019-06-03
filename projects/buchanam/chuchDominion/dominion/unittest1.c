#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int testAdventurerRefactored()
{
    // create testing environment
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy};
    struct gameState G;

    initializeGame(2, k, 20, &G);
    int z;
    int cardDrawn;
    int drawntreasure = 3;
    int temphand[MAX_HAND];
    int currentPlayer = whoseTurn(&G);

    int previousHandCount = G.handCount[currentPlayer];
    adventurerCase(currentPlayer, &G, z, cardDrawn, drawntreasure, temphand);
    if (*(G.handCount) == previousHandCount)
        printf("adventurerRefactored(): PASS when handcount doesn't change while drawntreasure > 3\n");
    else
        printf("adventurerRefactored(): FAIL when handcount  changes while drawntreasure > 3\n");

    previousHandCount = G.handCount[currentPlayer];
    drawntreasure = 2;
    adventurerCase(currentPlayer, &G, z, cardDrawn, drawntreasure, temphand);
    if (*(G.handCount) != previousHandCount)
        printf("adventurerRefactored(): PASS when handcount changes while drawntreasure == 2\n");
    else
        printf("adventurerRefactored(): FAIL when handcount doesn't change while drawntreasure == 2\n");

    previousHandCount = G.handCount[currentPlayer];
    drawntreasure = 0;
    adventurerRef(&G);
    if (*(G.handCount) != previousHandCount)
        printf("adventurerRefactored(): PASS when handcount changes while drawntreasure == 0\n");
    else
        printf("adventurerRefactored(): FAIL when handcount doesn't change while drawntreasure == 0\n");

    previousHandCount = G.handCount[currentPlayer];
    drawntreasure = -2;
    adventurerCase(currentPlayer, &G, z, cardDrawn, drawntreasure, temphand);
    if (*(G.handCount) != previousHandCount)
        printf("adventurerRefactored(): PASS when handcount changes while drawntreasure == -2\n");
    else
        printf("adventurerRefactored(): FAIL when handcount doesn't change while drawntreasure == -2\n");
    return 0;
}

int main(int argc, char *argv[])
{
    testAdventurerRefactored();
    return 0;
}