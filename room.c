#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function that concatinates two ints together. e.g: concatenate(1,2) -> 12
unsigned concatenate(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;
}

int main(void){
	char command[10];//player's command
	char inventory[10];//player's inventory
	//variables
	int i=0;
	int j=0;
	int k=0;
	int h=0;
	int counter=0;

	char* data = getenv("QUERY_STRING");//getting the html query since we are using get
	char* p = data;
	//incrementing the counter because we want to know the size of the query for later use.
	while(k<100000) {
		if(*data == NULL) break;
		counter++;
		data++;
		k++;
	}
	//iterating through the query to get the player's command
	for(i;i<counter && *p != '=';i++){
		p++;
	}
	p++;//skipping the =
	//getting the command
	for(;i<counter && *p != '&';i++){
		if(*p=='+'){
			command[j]=' ';
		}
		else{	
			command[j]=*p;
		}	
		p++;
		j++;
	}
	command[j]='\0';//inserting a null
	//iterating through the query again to get the player's inventory
	for(;i<counter && *p!='=';i++) p++;
	p++;//skip the =
	//getting the the inventory
	for(;i<counter && *p!='&';i++){
		 if(*p == '%'){
                        p=p+2;
                        inventory[h]=',';
                        }
                 else{
                        inventory[h]=*p;
                 }
                 p++;
                 h++;
	}	
	inventory[h]='\0';
	//the commands provided from the rules
	char play[5]={'P','L','A','Y','\0'};
	char exit[5]={'E','X','I','T','\0'};
	char refresh[8]={'R','E','F','R','E','S','H','\0'};
	char drop[5]={'D','R','O','P','\0'};
	//printing an html page 
	printf("Content-type:text/html\n\n");

	//if its play then do the following
	if(strcmp(command,play) == 0){
		//variables
		int playerMana=0;
		int playerGold=0;
		int counterGold=0;
		int counterMana=0;
		int counter=0;
		char manaArray[3]={'0','0','\0'};
                int g=0;
		//seperating the mana from the gold and putting them into two different arrays
                for(g;inventory[g]!=',';g++){
                        manaArray[g]=inventory[g];
                }
                manaArray[g]='\0';
                g++;//skip the , in inventory
                int goldCounter=0;
                char goldArray[3]={'0','0','\0'};
                for(;inventory[g]!=NULL;g++){
                        goldArray[goldCounter]=inventory[g];
                        goldCounter++;
                }
                goldArray[goldCounter]='\0';

                for(counter=0;manaArray[counter]!='\0';counter++){
                        counterMana++;
                }
                for(counter=0;goldArray[counter]!='\0';counter++){
                        counterGold++;
                }
                //getting the value of mana and gold
                if(counterMana==1){
                        playerMana=manaArray[0]-'0';
                }
                else if (counterMana==2){
                        playerMana=concatenate(manaArray[0]-'0',manaArray[1]-'0');
                        playerMana=(int)playerMana;
                }
                //getting the value of gold, depending on mana
                if(counterGold==1 && counterMana==1){
                        playerGold=goldArray[0]-'0';
                }
                else if(counterGold==1 && counterMana==2){
                        playerGold=goldArray[0]-'0';
                }
                else if(counterGold==2 && counterMana==1){
                        playerGold=concatenate(goldArray[0]-'0',goldArray[1]-'0');
                        playerGold=(int)playerGold;
                }
                else if(counterGold==2 && counterMana==2){
                        playerGold=concatenate(goldArray[0]-'0',goldArray[1]-'0');
                        playerGold=(int)playerGold;
                }
		//printing the play page.
		printf("<html><head><title>T&W</title></head><body><center><h1><b>T&Ws Room</b></h1></center></br><center><img src=\"http://www.pxleyes.com/images/contests/empty%20room/fullsize/sourceimage.jpg\" width=\"1000px\" height=\"550px\"></br><table><tr><td><center><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/challenge.py\" method=\"get\"><input type=\"text\" name=\"text\"><input type=\"submit\" value=\"Submit\"><input type=\"hidden\" name=\"inventory\" value=\"%d,%d\"></form></center></td></tr></table><center>Output: You are now playing Rock, Paper, Scissor. Type in either Rock, Paper or Scissors. </center></body></html>",playerMana,playerGold);
	}
	//if its exit, then do the following
	else if(strcmp(command,exit)==0){
		//reading the csv file
		char resource[8];
		FILE *in =fopen("../resources.csv","rt");
		fgets(resource,8,in);
		fclose(in);
		
		//iterating through resource[]
		int counter=0;
		int counterGold=0;
		int counterMana=0;
		int resourceGold=0;
		int resourceMana=0;
		//getting the digits for mana
		for(counter=0;resource[counter]!=',';counter++){
			counterMana++;
		}
		counter++;//skip the ,
		//getting the digits for gold
		for(;resource[counter]!=',';counter++){
			counterGold++;
		}
		//getting the value of mana and gold
		if(counterMana==1){
			resourceMana=resource[0]-'0';
		}
		else if (counterMana==2){
			resourceMana=concatenate(resource[0]-'0',resource[1]-'0');
			resourceMana=(int)resourceMana;
		}
		//getting the value of gold, depending on mana
		if(counterGold==1 && counterMana==1){
			resourceGold=resource[2]-'0';
		}
		else if(counterGold==1 && counterMana==2){
			resourceGold=resource[3]-'0';
		}
		else if(counterGold==2 && counterMana==1){
			resourceGold=concatenate(resource[2]-'0',resource[3]-'0');
                        resourceGold=(int)resourceGold;
		}
		else if(counterGold==2 && counterMana==2){
                        resourceGold=concatenate(resource[3]-'0',resource[4]-'0');
                        resourceGold=(int)resourceGold;
                }

		//getting the value of player's inventory
		char manaArray[3]={'0','0','\0'};
                int g=0;
		//seperating the mana from the gold and putting them into two different arrays
                for(;inventory[g]!=',';g++){
                	manaArray[g]=inventory[g];
                }
                manaArray[g]='\0';
                g++;
                int goldCounter=0;
                char goldArray[3]={'0','0','\0'};
                for(;inventory[g]!=NULL;g++){
                	goldArray[goldCounter]=inventory[g];
                        goldCounter++;
                }
                goldArray[goldCounter]='\0';

		int playerGold=0;
		int playerMana=0;
		counter=0;
		counterGold=0;
		counterMana=0;
		for(counter=0;manaArray[counter]!='\0';counter++){
                        counterMana++;
                }
		for(counter=0;goldArray[counter]!='\0';counter++){
                        counterGold++;
                }
		//getting the value of mana and gold
                if(counterMana==1){
                        playerMana=manaArray[0]-'0';
                }
                else if (counterMana==2){
                        playerMana=concatenate(manaArray[0]-'0',manaArray[1]-'0');
                        playerMana=(int)playerMana;
                }
                //getting the value of gold, depending on mana
                if(counterGold==1 && counterMana==1){
                        playerGold=goldArray[0]-'0';
                }
                else if(counterGold==1 && counterMana==2){
                        playerGold=goldArray[0]-'0';
                }
                else if(counterGold==2 && counterMana==1){
                        playerGold=concatenate(goldArray[0]-'0',goldArray[1]-'0');
                        playerGold=(int)playerGold;
                }
                else if(counterGold==2 && counterMana==2){
                        playerGold=concatenate(goldArray[0]-'0',goldArray[1]-'0');
                        playerGold=(int)playerGold;
                }
		//adding players inventory to the resources
		resourceGold+=playerGold;
		resourceMana+=playerMana;
		//writing to the resources.csv
		FILE *out=fopen("../resources.csv","wt");
		fprintf(out,"%d,%d,0",resourceMana,resourceGold);
		fclose(out);
		//printing the exit page
		printf("<html><head><title>T&W</title><head><body><center><img src=\"http://www.sanfrancisco.net/pictures/alcatraz-cell-block.jpg\" width=\"1000px\" height=\"550px\"></br><center><b>FREEEEEEEEEEEEEEEEEEDOOOOOOOOOOOOOOOOOOOOOOOOMMMMMMMMMMMM!!!!!!!!!!</b></center></br><center><b>Thanks for playing by the way</b></center></body></html>");
	}
	//if its refresh then do the following
	else if(strcmp(command,refresh)==0){
		int counter=0;
		int playerMana=0;
                int playerGold=0;
                int counterMana=0;
                int counterGold=0;
                //getting the value of player's inventory to an array
                char manaArray[3]={'0','0','\0'};
                int g=0;
		//seperating the mana from the gold and putting them into two different arrays
                for(;inventory[g]!=',';g++){
                        manaArray[g]=inventory[g];
                }
                manaArray[g]='\0';
                g++;
                int goldCounter=0;
                char goldArray[3]={'0','0','\0'};
                for(;inventory[g]!=NULL;g++){
                        goldArray[goldCounter]=inventory[g];
                        goldCounter++;
                }
                goldArray[goldCounter]='\0';
                //getting the values from the arrays
                for(counter=0;manaArray[counter]!='\0';counter++){
                        counterMana++;
                }
                for(counter=0;goldArray[counter]!='\0';counter++){
                        counterGold++;
                }
                //getting the value of mana and gold
                if(counterMana==1){
                        playerMana=manaArray[0]-'0';
                }
                else if (counterMana==2){
                        playerMana=concatenate(manaArray[0]-'0',manaArray[1]-'0');
                        playerMana=(int)playerMana;
                }
                //getting the value of gold, depending on mana
                if(counterGold==1 && counterMana==1){
                        playerGold=goldArray[0]-'0';
                }
                else if(counterGold==1 && counterMana==2){
                        playerGold=goldArray[0]-'0';
                }
                else if(counterGold==2 && counterMana==1){
                        playerGold=concatenate(goldArray[0]-'0',goldArray[1]-'0');
                        playerGold=(int)playerGold;
                }
                else if(counterGold==2 && counterMana==2){
                        playerGold=concatenate(goldArray[0]-'0',goldArray[1]-'0');
                        playerGold=(int)playerGold;
                }
		//reading the resource.csv file	
		char resource[8];
                FILE *in =fopen("../resources.csv","rt");
                fgets(resource,8,in);
                fclose(in);
		//reseting the variables
		counter=0;
                counterGold=0;
                counterMana=0;
                int resourceGold=0;
                int resourceMana=0;
                //getting the digits for mana
                for(counter;resource[counter]!=',';counter++){
                        counterMana++;
                }
                counter++;//skip the ,
                //getting the digits for gold
                for(;resource[counter]!=',';counter++){
                        counterGold++;
                }
                //getting the value of mana and gold
                if(counterMana==1){
                        resourceMana=resource[0]-'0';
                }
                else if (counterMana==2){
                        resourceMana=concatenate(resource[0]-'0',resource[1]-'0');
                        resourceMana=(int)resourceMana;
                }
                //getting the value of gold, depending on mana
                if(counterGold==1 && counterMana==1){
                        resourceGold=resource[2]-'0';
                }
                else if(counterGold==1 && counterMana==2){
                        resourceGold=resource[3]-'0';
                }
                else if(counterGold==2 && counterMana==1){
                        resourceGold=concatenate(resource[2]-'0',resource[3]-'0');
                        resourceGold=(int)resourceGold;
                }
                else if(counterGold==2 && counterMana==2){
                        resourceGold=concatenate(resource[3]-'0',resource[4]-'0');
                        resourceGold=(int)resourceGold;
                }
		//inserting a 1(occupied) everytime the player types refresh
		FILE *out=fopen("../resources.csv","wt");
                fprintf(out,"%d,%d,1",resourceMana,resourceGold);
                fclose(out);
		//printing the refresh page
		printf("<html><head><title>T&W</title></head><body><center><h1><b>T&W's Room</b></h1></center></br><center><img src=\"http://www.pxleyes.com/images/contests/empty%20room/fullsize/sourceimage.jpg\" width=\"1000px\" height=\"550px\"></br><table><tr><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/callNorth.py\" method=\"get\"><input type=\"submit\" value=\"North\"><input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">",playerMana,playerGold);
		printf("<input type=\"hidden\" name=\"URL\" value=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory=%d%%2C%d\">",playerMana,playerGold);
		
		printf("</form></tr><tr><td><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/callWest.py\" method=\"get\"><input type=\"submit\" value=\"West\"><input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">",playerMana,playerGold);

		printf("<input type=\"hidden\" name=\"URL\" value=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory=%d%%2C%d\">",playerMana,playerGold);
		
		printf("</form></td><td><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi\" method=\"get\"><input type=\"text\" name=\"command\"><input type=\"submit\" value=\"Submit\"><input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">",playerMana,playerGold);		
		
		printf("</form></td><td><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/callEast.py\" method=\"get\"><input type=\"submit\" value=\"East\"><input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">",playerMana,playerGold);		
		
		printf("<input type=\"hidden\" name=\"URL\" value=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory=%d%%2C%d\">",playerMana,playerGold);
		
		printf("</form></td></tr></table><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/callSouth.py\" method=\"get\"><input type=\"submit\" value=\"South\"><input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">",playerMana,playerGold);
		printf("<input type=\"hidden\" name=\"URL\" value=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory=%d%%2C%d\">",playerMana,playerGold);
		
		printf("</form></center><center>Output:</center></body></html>");
	}
	//if its drop then do the following
	else if(strncmp(command,drop,4)==0){

                //reading the csv file
                char resource[8];
                FILE *in =fopen("../resources.csv","rt");
                fgets(resource,8,in);
                fclose(in);

		int counter=0;
                int counterGold=0;
                int counterMana=0;
                int resourceGold=0;
                int resourceMana=0;
                //getting the digits for mana
                for(counter=0;resource[counter]!=',';counter++){
                        counterMana++;
                }
                counter++;//skip the ,
                //getting the digits for gold
                for(;resource[counter]!=',';counter++){
                        counterGold++;
                }
                //getting the value of mana and gold
                if(counterMana==1){
                        resourceMana=resource[0]-'0';
                }
                else if (counterMana==2){
                        resourceMana=concatenate(resource[0]-'0',resource[1]-'0');
                        resourceMana=(int)resourceMana;
                }
                //getting the value of gold, depending on mana
                if(counterGold==1 && counterMana==1){
                        resourceGold=resource[2]-'0';
                }
                else if(counterGold==1 && counterMana==2){
                        resourceGold=resource[3]-'0';
                }
                else if(counterGold==2 && counterMana==1){
                        resourceGold=concatenate(resource[2]-'0',resource[3]-'0');
                        resourceGold=(int)resourceGold;
                }
                else if(counterGold==2 && counterMana==2){
                        resourceGold=concatenate(resource[3]-'0',resource[4]-'0');
                        resourceGold=(int)resourceGold;
                }

		//Getting inventory values and drop value

		char number[4]={'0','0','0','\0'}; //number represents the amount the user wants to drop
		int numCount=0;
		int g=0;
		for(;command[g+5]!=NULL;g++){
			number[g]=command[g+5];
		}
		number[g]='\0';
		
		if(strlen(number)>2){ //Then the user input was something like DROP 100, which should not even be a possibility
			printf("<html><body><center> Invalid input. You tried to drop way more gold than you have.</center> </body></html>");
		}
		
		else{
			char manaArray[3]={'0','0','\0'};
			g=0;
			//seperating the mana from the gold and putting them into two different arrays
			for(;inventory[g]!=',';g++){
				manaArray[g]=inventory[g];
			}
			manaArray[g]='\0';
			g++;
			int goldCounter=0;
			char goldArray[3]={'0','0','\0'};
			for(;inventory[g]!=NULL;g++){
				goldArray[goldCounter]=inventory[g];
				goldCounter++;
			}
			goldArray[goldCounter]='\0';
		
			unsigned goldDropped=0;
			unsigned manaGain;
			unsigned newMana=0;
			unsigned newGold=0;
	
			if(strlen(number)==1){ //Then no need to concatenate
				goldDropped=number[0]-'0';	
				goldDropped=(int)goldDropped;
			}
			else{
				goldDropped=concatenate((number[0]-'0'),(number[1]-'0'));
				goldDropped=(int)goldDropped;
	
			}
			//adding the dropped gold to the csv file
			resourceGold+=goldDropped;
			FILE *out=fopen("../resources.csv","wt");
                	fprintf(out,"%d,%d,1",resourceMana,resourceGold);
               	 	fclose(out);
			if(strlen(manaArray)==1){
				newMana=manaArray[0]-'0';
				newMana=(int)newMana;
			}
			else{
				newMana=concatenate((manaArray[0]-'0'),(manaArray[1]-'0'));
			}
			if(strlen(goldArray)==1){
				newGold=goldArray[0]-'0';
				newGold=(int)newGold;
			}
			else{
				newGold=concatenate((goldArray[0]-'0'),(goldArray[1]-'0'));
				newGold=(int)newGold;
			}
			manaGain=goldDropped/2;
			if(goldDropped>newGold){ //Then the user dropped too much gold
				printf("<html><head</head><body><h1><center><img src=\"http://i2.kym-cdn.com/entries/icons/facebook/000/018/489/nick-young-confused-face-300x256_nqlyaa.jpg\"></br>You dropped way too much gold! You would have negative gold, but since I am so nice, I will let you redo your decision! Go back.</center></h1></body></html>");
			}
			else{
				newGold=newGold-goldDropped;
				newMana=newMana+manaGain;
				//printing the drop page
				printf("<html><head><title>T&W</title></head><body><center><h1><b>T&Ws Room</b></h1></center></br><center><img src=\"http://www.pxleyes.com/images/contests/empty%20room/fullsize/sourceimage.jpg\" width=\"1000px\" height=\"550px\"></br><table><tr><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/callNorth.py\" method=\"get\"><input type=\"submit\" value=\"North\"><input type=\"hidden\" name=\"inventory\" value=\"%d,%d\"",newMana,newGold);

				printf("><input type=\"hidden\" name=\"URL\" value=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory=%d%%2C%d\">",newMana,newGold);

				printf("</form></tr><tr><td><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/callWest.py\" method=\"get\"><input type=\"submit\" value=\"West\"><input type=\"hidden\" name=\"inventory\" value=\"%d,%d\"",newMana,newGold);

				printf("><input type=\"hidden\" name=\"URL\" value=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory=%d%%2C%d\">",newMana,newGold);
	
				printf("</form></td><td><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi\" method=\"get\"><input type=\"text\" name=\"command\"><input type=\"submit\" value=\"Submit\"><input type=\"hidden\" name=\"inventory\" value=\"%d,%d\"",newMana,newGold);

				printf("</form><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/callEast.py\" method=\"get\"><input type=\"submit\" value=\"East\"><input type=\"hidden\" name=\"inventory\" value=\"%d,%d\"",newMana,newGold);

				printf("><input type=\"hidden\" name=\"URL\" value=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory=%d%%2C%d\">",newMana,newGold);
		
				printf("</form></td></tr></table><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/callSouth.py\" method=\"get\"><input type=\"submit\" value=\"South\"><input type=\"hidden\" name=\"inventory\" value=\"%d,%d\"",newMana,newGold);

				printf("><input type=\"hidden\" name=\"URL\" value=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory=%d%%2C%d\">",newMana,newGold);

				printf("</form></center><center>Output:</center></body></html>");
	
			}
		}	
        }
	//otherwise, print the following
	else{
		printf("<html><body><center> Invalid input. Type REFRESH, PLAY, EXIT or DROP N(N is an integer).</center> </body></html>");
	}
	return 0;
}
