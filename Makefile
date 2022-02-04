CC = g++
CFLAGS = -g -Wall -std=c++11

a.out: MyTime.o MyTime_Main.o
	$(CC) $(CFLAGS) MyTime.o MyTime_Main.o -o a.out

MyTime.o: MyTime.cc MyTime.h
	$(CC) $(CFLAGS) -c MyTime.cc

MyTime_Main.o: MyTime_Main.cc MyTime.h
	$(CC) $(CFLAGS) -c MyTime_Main.cc

clean:
	rm -rf *.o a.out