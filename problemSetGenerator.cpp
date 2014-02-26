#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main (int argc, char** argv) {
	//Handle the arguments

	if(argc < 4) {
		cout << "Usage: " << argv[0] << " <problem list file> <number of problems to select> <output file>\n";
		return 1;
	}

	ifstream inFile;
	int numberOfProblems;
	ofstream outFile;

	inFile.open(argv[1]);
	if(!inFile.is_open()) {
		cout << "Couldn't open file for reading: " << argv[1] << '\n';
		return 1;
	}

	numberOfProblems = atoi(argv[2]);
	
	outFile.open(argv[3]);
	if(!outFile.is_open()) {
		cout << "Couldn't open file for writing: " << argv[2] << '\n';
		return 1;
	}

	//Read the input file

	vector<string> problems;
	string line;

	while(getline(inFile, line)) {
		problems.push_back(line);
	}

	if(problems.size() < (unsigned)numberOfProblems) { 
		cout << "Can't select " << numberOfProblems << " problems from a set of only " << problems.size() << " problems!\n";
		return 1;
	}
	
	//Generate the problem set file

	//SEED rand, this is important.
	srand(time(NULL));

	for(int i = 0; i < numberOfProblems; i++) {
		int problemIndex = rand() % problems.size();
		outFile << problems[problemIndex] << '\n';
		problems.erase(problems.begin() + problemIndex);
	}

	//Clean up

	inFile.close();
	outFile.close();

	return 0;
}
