###############################################################
# Program:
#     Project 4, Asteroids
#     Brother Helfrich, CS165
# Author:
#     Travis Confer
#     Robert Dickerson
#     Mark Decker
# Summary:
#     Interstellar-the videogame
#     Actually, Asteroids is like the classic arcade style game
#     with a few friendly power-ups. Those powerups include a 
#     graphical update with stars and colored objects, a shotgun
#     firing mode, and bombs. We feel that we have earned whatever
#     extra credit you deem worthy for these added gameplay features.
#
#     Estimated:  100.0
#     Actual:     30.0 between us
###############################################################

###############################################################
# The main programs
###############################################################
a.out :  play.o game.o ship.o point.o uiDraw.o uiInteract.o velocity.o inertia.o bullet.o asteroids.o	
	g++ play.o game.o ship.o point.o uiDraw.o uiInteract.o velocity.o inertia.o bullet.o asteroids.o -lglut -lGLU 
	tar -cf asteroids.tar *.cpp *.h makefile

###############################################################
# Individual files
###############################################################
uiInteract.o : uiInteract.cpp uiInteract.h  point.h
	g++ -c uiInteract.cpp

uiDraw.o : uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

point.o : point.cpp point.h
	g++ -c point.cpp

velocity.o : velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

inertia.o : inertia.cpp inertia.h velocity.h
	g++ -c inertia.cpp

asteroids.o : asteroids.cpp inertia.h
	g++ -c asteroids.cpp

bullet.o : bullet.cpp inertia.h
	g++ -c bullet.cpp

ship.o : ship.cpp inertia.h
	g++ -c ship.cpp

game.o : game.cpp game.h uiInteract.h uiDraw.h inertia.h
	g++ -c game.cpp

play.o : play.cpp uiDraw.h uiInteract.h game.h point.h inertia.h
	g++ -c play.cpp

###############################################################
# General rules
###############################################################
clean :
	rm a.out *.o

all :  a.out 
