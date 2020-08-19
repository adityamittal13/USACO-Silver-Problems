#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main(){
	ifstream inFile;
	inFile.open("teleport.in");

	int a, b, x, y;
	inFile >> a >> b >> x >> y;

	inFile.close();

	int steps = abs(a-b); // no teleport

	if (steps > ((abs(a-x) + abs(b-y)))){
		steps = abs(a-x) + abs(b-y);
	}
	if (steps > ((abs(a-y) + abs(b-x)))){
		steps = abs(a-y) + abs(b-x);
	}

	ofstream output;
	output.open("teleport.out");
	output << steps << endl;

	output.close();
}