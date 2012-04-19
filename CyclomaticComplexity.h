/*
 * CyclomaticComplexity.h
 *
 *  Created on: 2011-03-14
 *      Author: Team Cougar
 */

#ifndef CYCLOMATICCOMPLEXITY_H_
#define CYCLOMATICCOMPLEXITY_H_

#include <vector>
#include "LogicAnalyzer.h"
#include "NodeData.h"
#include <sstream>
#include <string>
#include <cstdlib> // added for signed unsigned warning

class CyclomaticComplexity{
public:

	CyclomaticComplexity(vector<NodeData> nodeVector, vector < vector<int> > Vector);
	vector< vector<string> > findpath(unsigned int startnode, unsigned int endnode, unsigned int previous);
	string printPaths();
	int getCyclomaticComplexity();


private:
	vector < vector<int> > DirectedVector;
	vector<NodeData> nodeDataVector;


};



#endif /* CYCLOMATICCOMPLEXITY_H_ */
