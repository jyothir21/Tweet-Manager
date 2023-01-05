a3: createTweets.o displayTweets.o searchTweets.o stopWords.o deleteNthTweet.o saveTweetsToFile.o loadTweetsFromFile.o sortUserid.o mainA3.o 
	gcc createTweets.o displayTweets.o searchTweets.o stopWords.o deleteNthTweet.o saveTweetsToFile.o loadTweetsFromFile.o sortUserid.o mainA3.o -o a3
   
sortUserid.o: sortUserid.c headerA3.h 
	gcc -Wall -std=c99 -c sortUserid.c 

loadTweetsFromFile.o: loadTweetsFromFile.c headerA3.h 
	gcc -Wall -std=c99 -c loadTweetsFromFile.c 

saveTweetsToFile.o: saveTweetsToFile.c headerA3.h 
	gcc -Wall -std=c99 -c saveTweetsToFile.c 

deleteNthTweet.o: deleteNthTweet.c headerA3.h 
	gcc -Wall -std=c99 -c deleteNthTweet.c 

stopWords.o: stopWords.c headerA3.h 
	gcc -Wall -std=c99 -c stopWords.c 

searchTweets.o: searchTweets.c headerA3.h 
	gcc -Wall -std=c99 -c searchTweets.c 

displayTweets.o: displayTweets.c headerA3.h 
	gcc -Wall -std=c99 -c displayTweets.c 

createTweets.o: createTweets.c headerA3.h 
	gcc -Wall -std=c99 -c createTweets.c 

mainA3.o: mainA3.c headerA3.h 
	gcc -Wall -std=c99 -c mainA3.c
 
clean: 
	rm *.o a3 