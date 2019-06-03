#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int testCRRefactored()
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
    if (*(G.handCount) == previousHandCount + 3)
        printf("councilRoomRefactored(): PASS when handcount changes to previous + 3 when CR is called\n");
    else
        printf("councilRoomRefactored(): FAIL when handcount doesn't change to previous + 3 when CR is called\n");

    handPos = -2;
    if (*(G.handCount) == previousHandCount + 3)
        printf("councilRoomRefactored(): PASS when handcount changes to previous + 3 when CR is called\n");
    else
        printf("councilRoomRefactored(): FAIL when handcount doesn't change to previous + 3 when CR is called\n");

    handPos = 2;
    if (*(G.handCount) == previousHandCount + 3)
        printf("councilRoomRefactored(): PASS when handcount changes to previous + 3 when CR is called\n");
    else
        printf("councilRoomRefactored(): FAIL when handcount doesn't change to previous + 3 when CR is called\n");
    
    handPos = 30000;
    if (*(G.handCount) == previousHandCount + 3)
        printf("councilRoomRefactored(): PASS when handcount changes to previous + 3 when CR is called\n");
    else
        printf("councilRoomRefactored(): FAIL when handcount doesn't change to previous + 3 when CR is called\n");
    return 0;
}

int main(int argc, char *argv[])
{
    testCRRefactored();
    return 0;
}