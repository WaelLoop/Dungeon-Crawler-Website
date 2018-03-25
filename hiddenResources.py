#!/usr/bin/env python
import cgi
print "Content-Type:text/html\n\n"
form=cgi.FieldStorage()
#getting the player's inventory
inventory=form.getvalue("inventory")
l=inventory.split(',')
playerMana=int(l[0])
playerGold=int(l[1])
#getting the player's resources request
text=form.getvalue("text")
value=text.split(",")
mana=int(value[0])
gold=int(value[1])
#summing gold and mana and applying the rule
total=gold+mana
previousMana= 0
previousGold=0
if total > 5:
	print("<html><head><title>T&W</title></head><body><center>You are allowed to carry up to 5 items!!!!!</center></body></html>")
else:
	su=gold+playerGold#sum
        if su >=100:#if sum is more than 100, player wins
                print('<html><head><title>T&W</title></head><body><center><h1><b>Congratulations. You reached 100 gold and won!! </b></h1></center><img src=\"http://shadowthehedgehogxxx.weebly.com/uploads/2/4/9/9/24997883/8721035_orig.jpg\" width=\"260px\" height=\"230px\"> <img src=\"http://shadowthehedgehogxxx.weebly.com/uploads/2/4/9/9/24997883/8721035_orig.jpg\" width=\"260px\" height=\"230px\"><img src=\"http://shadowthehedgehogxxx.weebly.com/uploads/2/4/9/9/24997883/8721035_orig.jpg\" width=\"260px\" height=\"230px\"><img src=\"http://shadowthehedgehogxxx.weebly.com/uploads/2/4/9/9/24997883/8721035_orig.jpg\" width=\"260px\" height=\"230px\"><img src=\"http://shadowthehedgehogxxx.weebly.com/uploads/2/4/9/9/24997883/8721035_orig.jpg\" width=\"260px\" height=\"230px\"><img src=\"http://shadowthehedgehogxxx.weebly.com/uploads/2/4/9/9/24997883/8721035_orig.jpg\" width=\"260px\" height=\"230px\"><img src=\"http://shadowthehedgehogxxx.weebly.com/uploads/2/4/9/9/24997883/8721035_orig.jpg\" width=\"260px\" height=\"230px\"></body></html>')
	else:#otherwise do the following
		string=open('../resources.csv','r')
		lines=string.readline()
		z=lines.split(',')
		previousMana=int(z[0])
		previousGold=int(z[1])
		string.close()
		previousMana-=mana
		previousGold-=gold

		if(previousMana<0 or previousGold<0):
			print("<html><head><title>T&W</title></head><body><center>Hey! Don't take more than you can carry! Go away!</center></body></html>")
		else:
			#casting previousGold and previousMana to strings
			previousMana=str(previousMana)
			previousGold=str(previousGold)
			string2=open("../resources.csv",'w')
			string2.write(''+previousMana+','+previousGold+',1')
			string2.close()
			#adding the requested gold and mana to the player's inventory
			playerMana+=mana
			playerGold+=gold
			#casting them to strings
			playerMana=str(playerMana)
			playerGold=str(playerGold)
			print '<html><head><title>T&W</title></head><body><center><h1><b>T&W\'s Room</b></h1></center></br><center><img src="http://www.pxleyes.com/images/contests/empty%20room/fullsize/sourceimage.jpg" width="1000px" height="550px"></br><table><tr><form action="http://www.cs.mcgill.ca/~walhas1/cgi-bin/callNorth.py" method="get"><input type="submit" value="North"><input type="hidden" name="inventory" value="'+playerMana+','+playerGold+'"><input type="hidden" name="URL" value="http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory='+playerMana+'%2C'+playerGold+'"></form></tr><tr><td><form action="callWest.py" method="get"><input type="submit" value="West"><input type="hidden" name="inventory" value="'+playerMana+','+playerGold+'"><input type="hidden" name="URL" value="http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory='+playerMana+'%2C'+playerGold+'"></form></td><td><form action="http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi" method="get"><input type="text" name="command"><input type="submit" value="Submit"><input type="hidden" name="inventory" value="'+playerMana+','+playerGold+'"></form></td><td><form action="http://www.cs.mcgill.ca/~walhas1/cgi-bin/callEast.py" method="get"><input type="submit" value="East"><input type="hidden" name="inventory" value="'+playerMana+','+playerGold+'"><input type="hidden" name="URL" value="http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory='+playerMana+'%2C'+playerGold+'"></form></td></tr></table><form action="http://www.cs.mcgill.ca/~walhas1/cgi-bin/callSouth.py" method="get"><input type="submit" value="South"><input type="hidden" name="inventory" value="'+playerMana+','+playerGold+'"><input type="hidden" name="URL" value="http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory='+playerMana+'%2C'+playerGold+'"></form></center><center>Output:</center></body></html>'
