/*
 * SourceFormat.cpp
 *
 *  Created on: Feb 15, 2011
 *      Author: Cisc320 Team Cougar
 */

#include "SourceFormat.h"
using namespace std;

SourceFormat::SourceFormat(string CodePathIn) {
    getWorkingPath(); //get the source code path
    setAStylePath();//make it as the AStyle source code path
    codePath << CodePathIn;
}
vector<NodeData> SourceFormat::getNodes(){
    vector<NodeData> returnVector;
    NodeData pushedNode;
    string codeInPath;
    int braceCount = 0;
    int lineCounter= 0;
    int booleanBracketCount = 0;
    string word;
    stringstream linestream;
    string booleanExp;
    string holder;
    for(int i =0 ; i< (signed)sourceCodeVector.size(); i++){
        linestream.flush();
        stringstream linestream(sourceCodeVector.at(i));
        lineCounter++;
        while(linestream >> word ){
            if(isDecisionStatement(word, decisionStatements)){ 					// if its a decision statement do
                pushedNode.setStartLineNumber(lineCounter);

                holder = word;													//creates copy of word for case where decision statement has a space (i.e. else if)
                linestream >> word;
                if (word == "if"){												//Checks for 2nd word "if"
                    holder.append(" ");											//Put a space between else_if
                    pushedNode.setDecisionType(holder + word);
                    linestream >> word;											//continue on to the next word
                }
                else{
                    pushedNode.setDecisionType(holder);
                }														//Get the next word
                do{
                    if(word == "(")booleanBracketCount++;						//If the next word after decision is '(' then increase count
                    else if(word == ")")booleanBracketCount--;					//Decrease on ')'
                    booleanExp += word;											//Append word to booleanExpression followed by  a space
                }while(linestream >> word && booleanBracketCount != 0);
                pushedNode.setBooleanExpression(booleanExp);					//Set the boolean expression found above
                booleanExp = "";												//reset boolean expression to null

                string newLine;
                int tempLineCounter = i + 1;
                do{
                    //Increase bracecount
                    stringstream getNewLine(sourceCodeVector.at(tempLineCounter));		//redeclare, to set pointer back to 0 (i.e first word). a better approach would be setting get pointer = 0 but couldnt figure out tellg() function
                    getNewLine >> newLine;

                    if(newLine == "{") braceCount++;
                    else if(newLine == "}") braceCount--;
                    codeInPath += sourceCodeVector.at(tempLineCounter);
                    tempLineCounter++;
                    newLine = "";														//reset newLine to null
                }while(braceCount!=0);		//when bracecount = 0 that means we are back at the level of where it should be
                if(pushedNode.getDecisionType() == "else"){
                    pushedNode.setBooleanExpression("");
                }
                pushedNode.setEndLineNumber(tempLineCounter);			//get endline
                pushedNode.setCodeWithinPath(codeInPath);				//Push code between braces
                codeInPath = "";
                returnVector.push_back(pushedNode);
            }
        }
    }
    totalLines = lineCounter;
    return returnVector;
}

int SourceFormat::getTotalLines() const
{
    return totalLines;
}

bool SourceFormat::isDecisionStatement(string inString, vector<string> in){
    for (int k = 0 ; k < (signed)in.size(); k++){					//check if current value is a decision statement
        if (inString  == in[k]){
            return 1;
        }
    }
    return 0;
}

string SourceFormat::removeAllWhite (std::string &str){
    std::string temp;
    for (unsigned int i = 0; i < str.length(); i++){
        if (str[i] != ' ') temp += str[i];
    }
    return temp;
}

SourceFormat::~SourceFormat() {}//deconstructor

string SourceFormat::getWorkingPath(){
    char path1[MAXPATHLEN];  // This is a buffer for the text
    getcwd(path1, MAXPATHLEN);
    string returnPath(path1);
    workingPath = returnPath;
    return returnPath;
}
void SourceFormat::setAStylePath(){
    aStylePath  << workingPath;
}

string SourceFormat::getAStylePath(){
    return aStylePath.str();
}

string SourceFormat::getCodePath(){
    return codePath.str();
}

void SourceFormat::runAStyle(){
    string word;
    string line;

    #ifdef WIN32
    command << aStylePath.str() << "\\AStyle.exe " << codePath.str() << " --style=whitesmith --pad-paren-in --pad-header "; // windows
    #else
    //command << "/Developer/iCanC/astyle " << codePath.str() << " --style=whitesmith --pad-paren-in --pad-header "; // crude mac
    command << aStylePath.str() << "/astyle " << codePath.str() << " --style=whitesmith --pad-paren-in --pad-header "; // mac
    #endif

    cout << command.str() << endl;
    system(command.str().c_str());

    ifstream sourceCode(codePath.str().c_str());
    if(!sourceCode.is_open()) {cout<<"file NOT open properly, exiting."<<endl;} //if couldn't find the source code file

    ifstream decisionFile("c_decisions.txt"); //make sure the directory CHANGED
    if(!decisionFile.is_open()) {cout<<"Decision file NOT open properly, exiting."<<endl;} //if couldn't find the source code file
    while (decisionFile >> word) {
        decisionStatements.push_back(word);
    }

    while(getline(sourceCode,line)) {
        sourceCodeVector.push_back(line);
    }
}
