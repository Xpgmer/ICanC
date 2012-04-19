/*
 * SourceFormat.h
 *
 *  Created on: Feb 15, 2011
 *      Author: Team Cougar
 */

#ifndef SOURCEFORMAT_H_
#define SOURCEFORMAT_H_
#include <unistd.h>
#include <string>
#include <sys/param.h>
#include "NodeData.h"
#include <vector>
#include <sstream>
#include <iostream> // added on windows
#include <fstream> // added on windows
#include <cstdlib> //added for compilation of the system calls and unsigned/signed values warnings

using namespace std;

class SourceFormat {
public:
	//helper functions to format the source code
	string removeAllWhite (std::string &str);
	void runAStyle();
	string getAStylePath();
	string getWorkingPath();
	void setAStylePath();
	SourceFormat(string n);
	virtual ~SourceFormat();
	string getCodePath();
	vector<NodeData> getNodes();
	bool isDecisionStatement(string n, vector<string> m);
	int getTotalLines() const;
private:
	vector<NodeData> conditionalNodes;
	string workingPath;
	stringstream aStylePath;
	stringstream codePath;
	stringstream command;
	vector <string> sourceCodeVector;
	vector <string> decisionStatements;
	int totalLines;
};

#endif /* SOURCEFORMAT_H_ */
