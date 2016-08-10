//
//  main.c
//  Interactive Story
//
//  Created by Rodney Sampson on 8/9/16.
//  Copyright © 2016 Rodney Sampson II. All rights reserved.
//

#include <stdio.h>
#include <term.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "RoomFunctions.h"

void startGame(bool override);

void leaveRoom(char * userInput, bool * insideRoom);

void gameOver(bool override);

void clearScreen();

int main(int argc, const char * argv[]) {
    
    startGame(false);
    
    return 0;
}

void startGame(bool override) {
    char yes[3] = "yes";
    char leave[5] = "leave";
    int roomNumber = -1;
    char * roomName = "";
    char userInput[1] = " ";
    bool insideRoom = false;
    bool insideHouse = false;
    char roomOptions[7] = {'1', '2', '3', '4', '5', '6', '7'};
    
    printf("You are walking your dog one day when you find a pokemon with your phone.");
    printf("\n\nWhile you are trying to do curve balls your dog gets lose and runs away.");
    printf("\n\nYou chase it all the way down the street until you reach an old abandoned house.");
    printf("\n\nThe house's door is open and your dog runs inside. Do you go inside the house to find your dog?");
    printf("\n\nType 'yes' to go inside the house or 'no' to leave.\n\n");
    
    fpurge(stdin);
    scanf("%s", userInput);
    
    if (override || userInput[0] == yes[0]) {
        
        printf("\nYou go inside the house. The house is one long hallway with three doors on each side, all the doors are open");
        printf("\n\nYou walk down the hallway and look in each room.");
        printf("\n\nFrom the door the three on the left are a kitchen, a living room and a bedroom.");
        printf("\n\nFrom the door the three on the right are a a set of stairs that go to the basement, a bathroom and a library.");
        
        insideHouse = true;
        userInput[0] = '6';
        
        while(insideHouse) {
            
            printf("\n\nEnter the corresponding number for the room to go inside it.");
            printf("\n\nEnter 1: kitchen, Enter 2: living room, Enter 3: bedroom.");
            printf("\n\nEnter 4: basement, Enter 5: bathroom, Enter 6: library.");
            printf("\n\nOnce inside of a room enter 7 for the hallway. Type 'leave' to leave the house when in the hallway\n\n");
            
            fpurge(stdin);
            scanf("%s", userInput);
        
            if (userInput[0] == leave[0]) {
                printf("\nYou leave the house and go catch that pokemon. The next day you get a new dog. You lose that one too.");
                gameOver(false);
            }
            
            for (int i = 0; i < 7; i++) {
                if (userInput[0] == roomOptions[i]) {
                    roomNumber = roomOptions[i];
                    
                    switch (userInput[0]) {
                        case '1':
                            roomName = "kitchen";
                            roomNumber = 1;
                            break;
                        case '2':
                            roomName = "living room";
                            roomNumber = 2;
                            break;
                        case '3':
                            roomName = "bedroom";
                            roomNumber = 3;
                            break;
                        case '4':
                            roomName = "basement";
                            roomNumber = 4;
                            break;
                        case '5':
                            roomName = "bathroom";
                            roomNumber = 5;
                            break;
                        case '6':
                            roomName = "library";
                            roomNumber = 6;
                            break;
                        default:
                            break;
                    }
                    
                    printf("\nYou go into the %s.\n\n", roomName);
                    
                    insideRoom = true;
                }
            }
            
            while (insideRoom) {
                switch (roomNumber) {
                    case 1: {
                        printf("%s", getKitchenDialog());
                        
                        fpurge(stdin);
                        scanf("\n%s", userInput);
                        
                        if (userInput[0] == '0') {
                            interactWithKitchen(0);
                            insideRoom = false;
                            insideHouse = false;
                            gameOver(false);
                        } else {
                            interactWithKitchen(1);
                            leaveRoom(userInput, &insideRoom);
                        }
                    }
                    case 2:{
                        printf("%s", getLivingRoomDialog());
                        
                        fpurge(stdin);
                        scanf("\n\n%s", userInput);
                        
                        if (userInput[0] == '0') {
                            interactWithLivingRoom(0);
                        } else {
                            interactWithLivingRoom(1);
                        }
                        
                        leaveRoom(userInput, &insideRoom);
                    }
                    case 3:  {
                        printf("%s", getBedroomDialog());
                        
                        leaveRoom(userInput, &insideRoom);
                    }
                    case 4: {
                        printf("%s", getBasementDialog());
                        insideRoom = false;
                        insideHouse = false;
                        gameOver(false);
                    }
                    case 5:  {
                        printf("%s", getBathroomDialog());
                        
                        leaveRoom(userInput, &insideRoom);
                    }
                    case 6: {
                        printf("%s", getLibraryDialog());
                        
                        leaveRoom(userInput, &insideRoom);
                    }
                    default:
                        printf("How did you even get here?");
                        gameOver(true);
                        break;
                }
                
            }
            
        }
        
        gameOver(false);
        
    } else {
        printf("\nYou leave the house and go catch that pokemon. The next day you get a new dog. You lose that one too.");
        gameOver(false);
    }
}

void leaveRoom(char * userInput, bool * insideRoom) {
    bool * insideRoomAddress;
    insideRoomAddress = insideRoom;
    
    printf("\nType '7' to leave the room: ");
    fpurge(stdin);
    scanf("%s", userInput);
    if (userInput[0] == '7') {
        printf("\nYou are now back in the hallway");
        *insideRoomAddress = false;
    }
}

void gameOver(bool override) {
    printf("\n\nGame Over!\n\n");
    printf("Do you want to play again? Type '0' to play again or type '1' to close the program: ");
    
    char close = ' ';
    
    fpurge(stdin);
    scanf("%c", &close);
    
    if (override || close == '0') {
        
        // clearScreen();
        
        printf("\n");
        printf("restarting...\n\n");
        sleep(1);
        printf("restarting...\n\n");
        sleep(1);
        printf("restarting...\n\n");
        sleep(1);
        printf("_____________\n\n");
        
        startGame(true);
    }
}

/* void clearScreen() {
 if (!cur_term) {
 int result;
 setupterm( NULL, STDOUT_FILENO, &result );
 if (result <= 0) {
 return;
 }
 }
 
 putp( tigetstr( "clear" ) );
 } */
