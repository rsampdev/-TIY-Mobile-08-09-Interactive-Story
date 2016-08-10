//
//  RoomFunctions.c
//  Interactive Story
//
//  Created by Rodney Sampson on 8/9/16.
//  Copyright © 2016 Rodney Sampson II. All rights reserved.
//

#include "RoomFunctions.h"

char * getKitchenDialog() {
    return "Inside the kitchen you look for your dog for a little before stopping infront of the old gas stove.\n\nDo you turn it on? Enter '0' to turn it on or enter '1' to leave it alone.\n\n";
}

char * getLivingRoomDialog() {
    return "Inside the living room you look for your dog for a little before you think of trying to lure it with music.\n\nDo you turn on the old radio in the corner of the living room on? Enter '0' to turn it on or enter '1' to leave it alone.\n\n";
}

char * getBedroomDialog() {
    return "Inside the bedroom there is only an empty bedframe and a broken lamp.\n";
}

char * getBasementDialog() {
    return "Inside you find your dog eating spiders. You pick it up and leave the house. Never to return.\n";
}

char * getBathroomDialog() {
    return "You cringe in horror at what you see.";
}

char * getLibraryDialog() {
    return "Books! Glorious Books! Gloooriiiousss Booooks!!! And no dogs!\n";
}

void interactWithKitchen(int yesOrNo) {
    if (yesOrNo == 0) {
        printf("\nYou turn the stove on and stare deeply into the fire.\n\n'Am I in a function' you think.\n\nYou stay there forever.");
    } else {
        printf("\nYou leave the stove alone.\n");
    }
}

void interactWithLivingRoom(int yesOrNo) {
    if (yesOrNo == 0) {
        printf("\nYou turn it on. The dog does not come.");
    } else {
        printf("\nYou leave the radio alone.\n");
    }
}
