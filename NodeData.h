/*
 * NodeData.h
 *
 *  Created on: Feb 16, 2011
 *      Author: Team Cougar
 */

#ifndef NODEDATA_H_
#define NODEDATA_H_
#include <string>

using namespace std;

class NodeData {
public:
	NodeData();
	virtual ~NodeData();

	//NodeData Accessors/mutators
    string getBooleanExpression() const;
    string getCodeWithinPath() const;
    string getDecisionType() const;
    int getEndLineNumber() const;
    int getStartLineNumber() const;
    void setBooleanExpression(string booleanExpression);
    void setCodeWithinPath(string codeWithinPath);
    void setDecisionType(string decisionType);
    void setEndLineNumber(int endLineNumber);
    void setStartLineNumber(int startLineNumber);

private:
    //Node Data attributes
	int startLineNumber;
	int endLineNumber;
	string decisionType;
	string booleanExpression;
	string codeWithinPath;


};

#endif /* NODEDATA_H_ */
