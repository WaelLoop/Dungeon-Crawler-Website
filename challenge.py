#!/usr/bin/env python
import random
import cgi
import os
import sys
#generating a random number so that the computer chooses the shape
list=["Rock","Paper","Scissors"]
number=int(random.random()*3)
#getting the resources.
string=open('../resources.csv','r')
lines=string.readline()
z=lines.split(',')
previousMana=int(z[0])
previousGold=int(z[1])
string.close()
form=cgi.FieldStorage()
shape=form.getvalue("text")
inventory=form.getvalue("inventory")
z=inventory.split(',')
mana=int(z[0])#mana
gold=int(z[1])#gold
mana=str(mana)
gold=str(gold)
print("Content-Type:text/html\n\n")
#if the both choose rock, do the following
if shape == "Rock" and list[number] == "Rock":
	txt=open('./challengePics/rockX2.html', 'r')
        for line in txt:
                print line
        txt.close()
#if player chooses rock and computer chooses paper, do the following
elif shape == "Rock" and list[number] == "Paper":
	txt=open('./challengePics/rockPaper.html', 'r')
        for line in txt:
                print line
        txt.close()
#if player chooses rock and computer chooses scissors, do the following
elif shape == "Rock" and list[number] == "Scissors":
	print '<html><body><head><title>T&W</title><style>p.left{float: left;}p.right{float: right;}p.button{margin: 7cm 0 0 0;}p.resources{margin: 6cm 0 0 0;}p.center{margin: 6cm 0 0 0;}</style></head><body><center><img src="http://www.cs.mcgill.ca/~walhas1/cgi-bin/challengePics/rock.png" width="600px" height="250px" align="left"><img src="http://www.cs.mcgill.ca/~walhas1/cgi-bin/challengePics/scissorsRight.png" width="600px" height="250px" align="right"></center></br> <div><p class="left">You chose Rock.</p><p class="right"> The computer chose Scissors.</p></div></br><p class="center"><center><b> You won! Great Job!.</b></center></p><p class="resources"><center> The room has ',previousMana,' mana and ',previousGold,' gold. Pick what you want in mana,gold format. E.g.: 3,2. (P.S: You are allowed to pick up to<b> 5 items</b> only).</p></br><form action="http://www.cs.mcgill.ca/~walhas1/cgi-bin/hiddenResources.py" method="get"><input type="text" name="text"><input type="submit" value="Submit"><input type="hidden" name="inventory" value="'+mana+','+gold+'"></form></body></html>'
#if the player chooses Paper and computer chooses rock, do the following
elif shape == "Paper" and list[number] == "Rock":		
	print '<html><body><head><title>T&W</title><style>p.left{float: left;}p.right{float: right;}p.button{margin: 7cm 0 0 0;}p.resources{margin: 6cm 0 0 0;}p.center{margin: 6cm 0 0 0;}</style></head><body><center><img src="http://www.cs.mcgill.ca/~walhas1/cgi-bin/challengePics/paper.png" width="600px" height="250px" align="left"><img src="http://www.cs.mcgill.ca/~walhas1/cgi-bin/challengePics/rock.png" width="600px" height="250px" align="right"></center></br> <div><p class="left">You chose Paper.</p><p class="right"> The computer chose Rock.</p></div></br><p class="center"><center><b> You won! Great Job!.</b></center></p><p class="resources"><center> The room has ',previousMana,' mana and ',previousGold,' gold. Pick what you want in mana,gold format. E.g.: 3,2. (P.S: You are allowed to pick up to<b> 5 items</b> only).</p></br><form action="http://www.cs.mcgill.ca/~walhas1/cgi-bin/hiddenResources.py" method="get"><input type="text" name="text"><input type="submit" value="Submit"><input type="hidden" name="inventory" value="'+mana+','+gold+'"></form></body></html>'
#if both choose paper, do the following
elif shape == "Paper" and list[number] == "Paper":
	txt=open('./challengePics/paperX2.html', 'r')
       	for line in txt:
                print line
	txt.close()
#if player chooses paper and computer chooses scissors, do the following
elif shape == "Paper" and list[number] == "Scissors":
	txt=open('./challengePics/paperScissors.html', 'r')
       	for line in txt:
       	        print line
	txt.close()
#if player chooses scissors and computer chooses rock, do the following
elif shape == "Scissors" and list[number] == "Rock":
	txt=open('./challengePics/scissorsRock.html', 'r')
	for line in txt:
        	print line
	txt.close()
#if player chooses scissors and computer chooses paper, do the following
elif shape == "Scissors" and list[number] == "Paper":
	print '<html><body><head><title>T&W</title><style>p.left{float: left;}p.right{float: right;}p.button{margin: 7cm 0 0 0;}p.resources{margin: 6cm 0 0 0;}p.center{margin: 6cm 0 0 0;}</style></head><body><center><img src="http://www.cs.mcgill.ca/~walhas1/cgi-bin/challengePics/scissorsLeft.png" width="600px" height="250px" align="left"><img src="http://www.cs.mcgill.ca/~walhas1/cgi-bin/challengePics/paper.png" width="600px" height="250px" align="right"></center></br> <div><p class="left">You chose Scissors.</p><p class="right"> The computer chose Paper.</p></div></br><p class="center"><center><b> You won! Great Job!.</b></center></p><p class="resources"><center> The room has ',previousMana,' mana and ',previousGold,' gold. Pick what you want in mana,gold format. E.g.: 3,2. (P.S: You are allowed to pick up to<b> 5 items</b> only).</p></br><form action="http://www.cs.mcgill.ca/~walhas1/cgi-bin/hiddenResources.py" method="get"><input type="text" name="text"><input type="submit" value="Submit"><input type="hidden" name="inventory" value="'+mana+','+gold+'"></form></body></html>'
#if both choose scissor, do the following
elif shape == "Scissors" and list[number] == "Scissors":
	txt=open('./challengePics/scissorsX2.html', 'r')
	for line in txt:
		print line
	txt.close()
#if the player types quit, do the following 
elif shape == "QUIT":
	print '<html><head><title>T&W</title></head><body><center><h1><b>T&Ws Room</b></h1></center></br><center><img src=\"http://www.pxleyes.com/images/contests/empty%20room/fullsize/sourceimage.jpg\" width=\"1000px\" height=\"550px\"></br><table><tr><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/callNorth.py\" method=\"get\"><input type=\"submit\" value=\"North\"><input type=\"hidden\" name=\"inventory\" value=\"'+mana+','+gold+'\"><input type=\"hidden\" name=\"URL\" value=\"http://www.cs.mcgill.ca/~walhas1/room.html?command=REFRESH&inventory='+mana+'%2C'+gold+'\"></form></tr><tr><td><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/callWest.py\" method=\"get\"><input type=\"submit\" value=\"West\"><input type=\"hidden\" name=\"inventory\" value=\"'+mana+','+gold+'\"><input type=\"hidden\" name=\"URL\" value=\"http://www.cs.mcgill.ca/~walhas1/room.html?command=REFRESH&inventory='+mana+'%2C'+gold+'\"></form></td><td><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi\" method=\"get\"><input type=\"text\" name=\"command\"><input type=\"submit\" value=\"Submit\"><input type=\"hidden\" name=\"inventory\" value=\"'+mana+','+gold+'\"></form></td><td><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/callEast.py\" method=\"get\"><input type=\"submit\" value=\"East\"><input type=\"hidden\" name=\"inventory\" value=\"'+mana+','+gold+'><input type=\"hidden\" name=\"URL\" value=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH&inventory='+mana+'%2C'+gold+'\"></form></td></tr></table><form action=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/callSouth.py\" method=\"get\"><input type=\"submit\" value=\"South\"><input type=\"hidden\" name=\"inventory\" value=\"'+mana+','+gold+'<input type=\"hidden\" name=\"URL\" value=\"http://www.cs.mcgill.ca/~walhas1/cgi-bin/room.cgi?command=REFRESH?inventory='+mana+'%2C'+gold+'\"></form></center><center>Output:</center></body></html>'
#otherwise, print the following
else:
	print("Wrong syntax. Please enter \"Rock\", \"Papers\", or \"Scissors\".")
	print("</center></body></head></html>")
