#!/usr/bin/env python
import cgi
from subprocess import call
#We first modify the resources.csv to set it to unoccupied. but first we take the gold and mana
string=open('../resources.csv','r')
lines=string.read()
li=lines.split(',')
previousMana=int(li[0])
previousGold=int(li[1])
string.close()
#casting previousGold and previousMana to strings
previousMana=str(previousMana)
previousGold=str(previousGold)
string2=open("../resources.csv",'w')
string2.write(''+previousMana+','+previousGold+',0')
string2.close()
#getting the players inventory
form=cgi.FieldStorage()
player=form["inventory"].value
li2=player.split(',')
playerMana=str(li2[0])
playerGold=str(li2[1])
#finally call the other player's transporter.py
print"Content-type:text/html"
print"Location:http://www.cs.mcgill.ca/~jcao25/cgi-bin/transporter.py?inventory="+playerMana+"%2C"+playerGold+"&URL=http%3A%2F%2Fwww.cs.mcgill.ca%2F%7Ewalhas1%2Fcgi-bin%2Froom.cgi%3Fcommand%3DREFRESH%26inventory%3D"+playerMana+"%252C"+playerGold+"\r\n"
