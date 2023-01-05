//including required header file
#include "headerA3.h"
#include "personalHeader.h"

/*
    saveTweetsToFile: takes the linked list and stores it to a file of users choice
    In: tweet * tweetList
    Out: NONE
    Post: takes the tweetlist from main and copies it to a CSV file of the users choice
*/
void saveTweetsToFile(tweet * tweetList)
{
    //declaring required variables
    FILE *inputFile;
    tweet * temp;
    bool validFileInput;
    int word;
    char * token;
    char fileName[141];
    char tempFileName[141];
    
    //initalizing bool variable to false for validation
    validFileInput = false;

    //while-loop until validFileInput is true
    while(validFileInput == false)
    {
        //initalizing word counter to 1
        word = 1;

        //prompting user to enter file name and storing it into fileName
        printf("Enter the filename where you would like to store your tweets: ");
        scanf("%s", fileName);
        
        //copying fileName into a temp variable, and tokenizing it
        strcpy(tempFileName, fileName);
        token = strtok(tempFileName, " \t.");

        //while-loop until the end of the token
        while(token != NULL)
        {
            //if statement to check if the user has entered in the format of file correctly
            if(strcmp(token, "csv") == 0 && word == 2)
            {
                //setting validFileInput to true
                validFileInput = true;
            }
            
            //if statement to check if the file name continues after the .csv and sets validFileInput to false
            if(validFileInput == true && word > 2)
            {
                //setting validFileInput to false
                validFileInput = false;
            }

            //incrementing word counter
            word++;
            
            //getting the next token
            token = strtok(NULL, " \t.");
        }

        //checking to see if the user entered invalid input
        if(validFileInput == false)
        {
            //printing to user that they entered invalid input and prompts them again
            printf("Invalid File Type! Please enter in format <filename>.csv\n\n");
        }
    }

    //opening the file the user requested in write mode
    inputFile = fopen(fileName, "w");

    //setting temp to the head of the list and while-loop to the end of the list
    temp = tweetList;
    while (temp != NULL)
    {
        //writing all the nodes in the list to the file in specified format
        fprintf(inputFile, "%d,%s,%s\n", temp->id, temp->user, temp->text);
        
        //traversing to the next node
        temp = temp -> next;
    }

    //print to user that it has been written to the file successfully
    printf("Output successful!\n");

    //closing the file
    fclose(inputFile);
}