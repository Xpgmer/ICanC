/*
 * NodeData.cpp
 *
 *  Created on: Feb 16, 2011
 *      Author: Team Cougar
 */

#include "NodeData.h"
using namespace std;

NodeData::NodeData() {
	// TODO Auto-generated constructor stub

}

NodeData::~NodeData() {
	// TODO Auto-generated destructor stub
}

string NodeData::getBooleanExpression() const
{
    return booleanExpression;
}

string NodeData::getCodeWithinPath() const
{
    return codeWithinPath;
}

string NodeData::getDecisionType() const
{
    return decisionType;
}

int NodeData::getEndLineNumber() const
{
    return endLineNumber;
}

int NodeData::getStartLineNumber() const
{
    return startLineNumber;
}

void NodeData::setBooleanExpression(string booleanExpression)
{
    this->booleanExpression = booleanExpression;
}

void NodeData::setCodeWithinPath(string codeWithinPath)
{
    this->codeWithinPath = codeWithinPath;
}

void NodeData::setDecisionType(string decisionType)
{
    this->decisionType = decisionType;
}

void NodeData::setEndLineNumber(int endLineNumber)
{
    this->endLineNumber = endLineNumber;
}

void NodeData::setStartLineNumber(int startLineNumber)
{
    this->startLineNumber = startLineNumber;
}


