// C++ recursive program to solve Tower of Hanoi game for the graph:
// {(Start, Aux1), (Aux1, Aux2), (Aux2, Aux3), (Aux3,Aux4), (Aux4, Aux1), (Aux1, Dest)}

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// The move2 function is a recursive function that checks if the call is a base case else
// it will call a smaller version of itself using disc-1 where disc is the current number disks
// that the function must move. It will also rearange and pass the pegs, which are string
// variables, needed to perform the call along with the output stream that is needed to print
// the moves. The "if" stetements in between the recursive calls are for printing out an extra
// move if one needs to be done for moving the disks into the loop from peg "Start" or for
// moving them out of the loop to peg "Dest". The variables "totalDiscs" and "first" are needed
// for implelmenting these "if" statements.
// "totalDiscs" is the the total number of discs that are in the loop and functions like a
// global variable within the main function. "first" is used to signify that the extra move will
// be from "Start" to "Aux1" when true and from "Aux1" to "Dest" when false.
void move2(int disc, string start, string aux, string end, string extra, int* totalDiscs, bool first, ofstream& output)
{
	if (disc == 1) //Base case
	{
		output << "Move disk " << disc << " from " << start << " to " << aux << endl;
		output << "Move disk " << disc << " from " << aux << " to " << end << endl;
		return;
	}

	//General Case 
	move2(disc - 1, start, aux, end, extra, totalDiscs, first, output);
	if ((disc > *totalDiscs) && (start == "Aux1") && first)
	{
		output << "Move disk " << disc << " from " << "Start" << " to " << start << endl;
		(*totalDiscs)++;
	}
	output << "Move disk " << disc << " from " << start << " to " << aux << endl;
	move2(disc - 1, end, extra, start, aux, totalDiscs, first, output);
	output << "Move disk " << disc << " from " << aux << " to " << end << endl;
	if ((disc == *totalDiscs) && (end == "Aux1") && !first)
	{
		output << "Move disk " << disc << " from " << end << " to " << "Dest" << endl;
		(*totalDiscs)--;
	}
	move2(disc - 1, start, aux, end, extra, totalDiscs, first, output);
}

// This is the main function which will print to an output file the moves for each of the
// hard-coded tower of hanoi inputs by calling the "move2" function and passing to it the pegs 
// of the loop of the graph i.e. Aux1, Aux2, Aux3, and Aux4. It will also pass by reference 
// the local variable "discsInLoop" to simulate a global variable that keeps track of the 
// number of disks within the loop of the graph. The boolean "StartOrEnd" is also passed to 
// signify whether the moves being done are from peg "Start" to the loop when true or from 
// the loop to peg "Dest" when false.
int main()
{
	ofstream toOutput;
	toOutput.open("Tower of Hanoi Solutions.txt");
	int inputDiscs[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//Prints hard-coded solution for a Tower of Hanoi game for 1 disk
	toOutput << "Tower of Hanoi game for " << 1 << " disk:" << endl;
	toOutput << "Move disk " << 1 << " from " << "Start" << " to " << "Aux1" << endl;
	toOutput << "Move disk " << 1 << " from " << "Aux1" << " to " << "Dest" << endl;
	toOutput << "End of game for " << 1 << " disks.\n" << endl;
	
	//Handles Tower of Hanoi games for 2 to 10 disks
	for (int i = 0; i < 9; i++)
	{
		toOutput << "Tower of Hanoi game for " << inputDiscs[i] << " disks:" << endl;
		
		bool StartOrEnd = true;
		int discsInLoop = 0;
		toOutput << "Move disk " << 1 << " from " << "Start" << " to " << "Aux1" << endl;
		move2(inputDiscs[i] - 1, "Aux1", "Aux2", "Aux3", "Aux4", &discsInLoop, StartOrEnd, toOutput);

		toOutput << "Move disk " << inputDiscs[i] << " from " << "Start" << " to " << "Aux1" << endl;
		toOutput << "Move disk " << inputDiscs[i] << " from " << "Aux1" << " to " << "Dest" << endl;

		StartOrEnd = false;
		discsInLoop = inputDiscs[i] - 1;
		move2(inputDiscs[i] - 1, "Aux3", "Aux4", "Aux1", "Aux2", &discsInLoop, StartOrEnd, toOutput);
		toOutput << "Move disk " << 1 << " from " << "Aux1" << " to " << "Dest" << endl;
		
		toOutput << "End of game for " << inputDiscs[i] << " disks.\n" << endl;
	}
	toOutput.close();
	cout << "End of program." << endl;
	return 0;
}
