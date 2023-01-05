//including required header file
#include "headerA3.h"
#include "personalHeader.h"

/*
    loadTweetsFromFile: loads tweets from a user requested file and save it to the linked list
    In: tweet ** tweetList
    Out: NONE
    Post: recieves the head of the linked list from the main, reads the data from the user requested file and appends it to the linked list
*/
void loadTweetsFromFile(tweet ** tweetList)
{
    //declaring required variables
    FILE *inputFile;
    tweet *newNode;
    tweet *temp;
    bool validFileInput, unique;
    int counter, numOfCommas;
    char * token;
    char fileName[141];
    char tempFileName[141];
    char tempString[1000];

    //initalizing required variables
    validFileInput = false;
    unique = false;

    //while-loop until validFileInput is true
    while(validFileInput == false)
    {
        //initalizing counter to 1
        counter = 1;

        //prompting user to enter the file name they want to load and storing it into filename
        printf("Enter a filename to load from: ");
        scanf("%s", fileName);
        
        //copying the file name into a temp variable and tokenizing it
        strcpy(tempFileName, fileName);
        token = strtok(tempFileName, " \t.");

        //while-loop until the end of the token
        while(token != NULL)
        {
            //if statement to check if the user has entered in the format of file correctly
            if(strcmp(token, "csv") == 0 && counter == 2)
            {
                validFileInput = true;
            }

            //if statement to check if the file name continues after the .csv and sets validFileInput to false
            if(validFileInput == true && counter > 2)
            {
                //setting validFileInput to false
                validFileInput = false;
            }

            //incrementing counter
            counter++;
            
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
    inputFile = fopen(fileName, "r");

    //if statement checking to see if the file opened properly, and printing to user if the file was not opened properly
    if(inputFile == NULL)
    {
        printf("Could not open file!\n");
        return;
    }
    else
    {        
        //while-loop to read from file
        while(fgets(tempString, sizeof(tempString), inputFile) != NULL)
        {
            //if statement checking to see if its not end of file
            if(!feof(inputFile))
            {
                //removing the 2 '\n' characters at the end and replacing it with a null character
                tempString[strlen(tempString)-1] = '\0';
                tempString[strlen(tempString)-1] = '\0';
            }
            
            //inilitazing required variables and allocating memory for new node
            newNode = malloc(sizeof(tweet));
            counter = 0;
            numOfCommas = 0;

            //for-loop for length of tempString
            for(int i = 0; i < strlen(tempString); i++)
            {
                //if statement to check if the character in the string is a comma
                if(tempString[i] == ',')
                {
                    //incrementing comma counter
                    numOfCommas++;
                }
            }

            //tokenizing tempString by commas
            token = strtok(tempString, ",");

            //while-loop until end of token
            while(token != NULL)
            {
                //if-else statement to match each token to the corresponding structure variables in the node           
                if(counter == 0)
                {
                    //storing the token into newnode->id
                    newNode->id = atoi(token);

                    //setting unique variable to false, to check if the user id generated already exists, and using a while loop to generate a new value
                    unique = false;
                    while(unique == false)
                    {       
                        //assuming the generated user id is unique, and setting temp to the head 
                        unique = true;
                        temp = *tweetList;

                        //while-loop until the end of the list
                        while (temp != NULL)
                        {           
                            //if statement checking if the user id already exists in the linked list 
                            if(temp->id == newNode->id)
                            {
                                //generating a new value and adding it onto the already generated id, and setting unique to false to recheck if that number exists in the linked list
                                srand(time(NULL));
                                newNode->id += ((rand() % 999) + 1);
                                unique = false;
                            }

                            //moving onto the next node of the linked list
                            temp = temp -> next;
                        }
                    }
                }
                else if(counter == 1)
                {
                    //if counter is 1, copying token into newnode->user
                    strcpy(newNode->user, token);
                }
                else if(counter == 2)
                {
                    //if counter is 2, copying token into newnode->text
                    strcpy(newNode->text, token);                
                }
                else
                {
                    //if anything greater, check to see if counter us less than or equal to number of commas - 1
                    if(counter <= numOfCommas-1)
                    {
                        //appending a comma
                        strcat(newNode->text, ",");
                    }     

                    //appending the token           
                    strcat(newNode->text, token);
                }

                //incrementing counter and getting the next token
                counter++;
                token = strtok(NULL, ",");
            }

            //setting newNode->next to null
            newNode->next = NULL;

            //calling addNodeToList function to add this new node to the linked list
            addNodeToList(tweetList, newNode);   
        }   
    }     
    
    //print to user that the tweets were imported fine
    printf("Tweets Imported!\n");

    //closing file
    fclose(inputFile);
}