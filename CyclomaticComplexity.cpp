/*
 * CyclomaticComplexity.cpp
 *
 *  Created on: 2011-03-14
 *      Author: Team Cougar
 */

#include <vector>
#include "NodeData.h"
#include <string>
#include "CyclomaticComplexity.h"
#include "LogicAnalyzer.h"
#include <iostream>
#include <sstream>

using namespace std;

CyclomaticComplexity::CyclomaticComplexity(vector<NodeData> nodeVector, vector < vector<int> > Vector){
    nodeDataVector = nodeVector;
    DirectedVector = Vector;

}


vector < vector<string> >CyclomaticComplexity::findpath(unsigned int startnode, unsigned int endnode, unsigned int previous){
    string returnValue;
    vector < vector<string> > paths;
    vector <string> path;
    if (startnode == endnode){
        returnValue = "end";
        path.push_back(returnValue);
        paths.push_back(path);
    }
    else{
        for (unsigned int i=0;i<DirectedVector.size();i++){
            if ((DirectedVector[startnode][i]==1)){
                if (!((previous > startnode)&& (i == startnode+1))){
                    vector < vector <string> > store = findpath(i,endnode, startnode);
                    if (startnode%2!=0){
                    	returnValue = nodeDataVector.at(startnode/2).getBooleanExpression();

                    	for(int j =0; j<(int)store.size();j++){
                    		vector<string>::iterator it = store[j].begin();

                    		store[j].insert(it, 1, returnValue);
                    		paths.push_back(store[j]);
                    	}

                    }
                    else{
                    	returnValue = nodeDataVector.at(startnode/2).getDecisionType() + nodeDataVector.at(startnode/2).getBooleanExpression();
                    	for(int j =0; j<(int)store.size();j++){
                    		vector<string>::iterator it = store[j].begin();
                    		store[j].insert(it, 1, returnValue);
                    		paths.push_back(store[j]);
                    	}

                    }
                }
            }
        }
    }
    return paths;
}

string CyclomaticComplexity::printPaths(){
    int endnode = nodeDataVector.size()*2;
    ostringstream ss;
     vector < vector<string> > paths = findpath(0,endnode, 0);
    for (int i=0;i<(int)paths.size();i++){
    	ss << i+1 << ": "<< paths[i].at(0);
    	for (unsigned int j=1; j<paths[i].size();j++){
    		ss << ", " << paths[i].at(j);
    	}
        ss << endl << endl;
    }
    string output = ss.str();
    return output;
}

int CyclomaticComplexity :: getCyclomaticComplexity(){
	//string PDFdest;
	//LogicAnalyzer logicanalyzer(nodeDataVector, PDFdest);
	//int complexity = logicanalyzer.countEdges(DirectedVector) - logicanalyzer.countNodes(DirectedVector) +1;
	int endnode = nodeDataVector.size()*2;
	vector < vector<string> > paths = findpath(0,endnode, 0);
	int complexity = paths.size();
	return complexity;
}


