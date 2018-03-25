#!/usr/bin/env python
import cgi

print("Content-Type:text/html")
#getting the players inventory
form=cgi.FieldStorage()
inventory=form.getvalue("inventory")
inv=inventory.split(',')
mana=int(inv[0])
gold=int(inv[1])
#function to check if our room is occupied or not
def checkOccupied():
	resources=open('../resources.csv', 'r')
	string=resources.readline()
	li=string.split(',')
	csvOcc=int(li[2])
	if(csvOcc==1): #room is occupied
		return 1
	else: #room is not occupied
		return 0

check=checkOccupied()
if(check==1): #prompt the user to a busy page.
	print('\n\n')
	print """<html><head><title>T&W</title></head><body><center><b>Uh-Oh! Apparently there is someone in the room you requested.</b></center></br><center><a href="%s"><input type="submit" value="Go back to the previous room"></a></body></html>"""%form["URL"].value
else:
	#Otherwise, removing one mana, then making the check if the player still has mana or not.
	mana=mana-1
	if(mana<1):
		#Then the user is redirected to a "you lose" page
		print ('\n\n<html><head><style>body{background-color:#000000;color:white;}</style><title>T&W</title></head><body>Connection lost. Attempting to reestablish...<center><h1><b></b></h1></center></br><center><img src="../Game_Over.jpg" width="1000px" height="550px"></br><b><h1>You ran out of mana and died.</br> LOL are you kidding me? Y-you..you ran out of mana! How bad do you have to be to run out of mana?</br> HAHAHAHAHAHAHAHAHAHAHAHAHA </br> Literally nothing takes away your mana except for moving to a new room. Did you forget to pick up more? Seriously? My god this is embarrassing. I\'m sorry. I\'ll stop laughing now. </br></h1></b></center></body></html>')
	else:
		#We alter resources.csv to mark the room that the user is entering as occupied
		string=open('../resources.csv','r')
		lines=string.read()
		li=lines.split(',')
		previousMana=int(li[0])+1
		previousGold=int(li[1])
		string.close()
        	#casting previousGold and previousMana to strings
		previousMana=str(previousMana)
		previousGold=str(previousGold)
		string2=open("../resources.csv",'w')
		string2.write(''+previousMana+','+previousGold+',1')
		string2.close()
		mana=str(mana)
		gold=str(gold)
		print("\n\n")
		#print our page
		print '<html><head><title>T&W</title></head><body><center><h1><b>T&Ws Room</b></h1></center></br><center><img src=\"http://www.pxleyes.com/images/contests/empty%20room/fullsize/sourceimage.jpg\" width=\"1000px\" height=\"550px\"></br><table><tr><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/callNorth\" method=\"get\"><input type=\"submit\" value=\"North\"><input type=\"hidden\" name=\"inventory\" value=\"'+mana+','+gold+'\"><input type=\"hidden\" name=\"URL\" value=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory='+mana+'%2C'+gold+'\"></form></tr><tr><td><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/callWest.py\" method=\"get\"><input type=\"submit\" value=\"West\"><input type=\"hidden\" name=\"inventory\" value=\"'+mana+','+gold+'\"><input type=\"hidden\" name=\"URL\" value=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory='+mana+'%2C'+gold+'\"></form></td><td><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi\" method=\"get\"><input type=\"text\" name=\"command\"><input type=\"submit\" value=\"Submit\"><input type=\"hidden\" name=\"inventory\" value=\"'+mana+','+gold+'\"></form></td><td><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/callEast.py\" method=\"get\"><input type=\"submit\" value=\"East\"><input type=\"hidden\" name=\"inventory\" value=\"'+mana+','+gold+'><input type=\"hidden\" name=\"URL\" value=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory='+mana+'%2C'+gold+'\"></form></td></tr></table><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/callSouth.py\" method=\"get\"><input type=\"submit\" value=\"South\"><input type=\"hidden\" name=\"inventory\" value=\"'+mana+','+gold+'<input type=\"hidden\" name=\"URL\" value=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory='+mana+'%2C'+gold+'\"></form></center><center>Output:</center></body></html>'
