/*
     * LogicAnalyzer.cpp
     *
     *  Created on: Feb 4, 2011
     *      Author: Team Cougar
     */

    #include "LogicAnalyzer.h"

    using namespace std;

    LogicAnalyzer::LogicAnalyzer(vector<NodeData> nodeVector, string graphOutDir){
        NodeDataVector = nodeVector;
        graphWriteDir = graphOutDir;
    }

    vector< vector<int> > LogicAnalyzer:: createAdjacencyMatrix(){
        cout<<"Analyzing Source Code..."<<endl;
        arraysize = 2 *NodeDataVector.size() +1;		//+1 for end node
        vector< vector<int> > adjacencyMatrix(arraysize, vector<int>(arraysize));



        /*
    	 * Adjacency Matrix Generation code Algorithm
    	 * Notes: All lines and columns are decision statements, therefore there should be two paths (to 1's) on each row of the adjacency matrix
    	 *
    	 * Forward Checks (i.e i = 0 => i = size-1, and j = 0 => j = size - 1)
    	 * 1.	Checks if the code is within another node by checking (A.startline < B.startline && A.endline >  B.endline)
    	 * 		Then B is within A therefore A => B
    	 *
    	 * 2.	Checks for the first node after the endline of A by checking (A.getEndLineNumber() < B.getStartLineNumber())
    	 *		Therefore B starts right after A ends which means A =>B
    	 *
    	 * 3.	If the row line count == 1, then this means that  Check 2. was not satisfied.
    	 * 	 	This means there exists no node that starts after A, Therefore A => End
    	 *
    	 *
    	 */
        int hasWithin= 0;		//Flag set when the code has decision within it
        int hasAfter = 0;		//Flag set when the code has decision following it
        int done = 0;
        int count =0;
        int withinNode =0;
        int afterNode = 0;
        int switchLast=0;

        int switchEndLine=0; //******

        vector <int> loopStack;
        for (unsigned int i = 0; i < NodeDataVector.size() ; i++){
            done = 0;
            hasWithin = 0;
            hasAfter =0;
            count =0;
            withinNode =0;
            if (NodeDataVector.at(i).getDecisionType() == "switch"){
            	switchLast=i;  //record switch location for parallel case edges
            	switchEndLine = NodeDataVector.at(i).getEndLineNumber();  //*******
            }
            else if (NodeDataVector.at(i).getDecisionType() == "while"||NodeDataVector.at(i).getDecisionType() == "for"){
            	loopStack.push_back(i);
            }
            for (unsigned int j = 0; j < NodeDataVector.size(); j++){//setting all the false direct edges &&update haswithin/hasAfter
                if( NodeDataVector.at(i).getStartLineNumber() < NodeDataVector.at(j).getStartLineNumber() && NodeDataVector.at(i).getEndLineNumber() > NodeDataVector.at(j).getEndLineNumber()){
                    if(hasWithin == 0){
                        adjacencyMatrix[i*2][j*2] = 1;
                        withinNode = j*2;
                        count++;	//count of how many 1's are in  each row
                        hasWithin++;


                        if(NodeDataVector.at(i).getDecisionType() == "while"||NodeDataVector.at(i).getDecisionType() == "for"){
                        	int n=NodeDataVector.at(i).getEndLineNumber()+1;
                        	for (unsigned int k=i+1;k<NodeDataVector.size();k++){
                        		if(NodeDataVector.at(k).getStartLineNumber()>=n){
                        			int found=0;
                        			if (loopStack.size()>0){
                        				int lastLoopID=loopStack[loopStack.size()-2];
                        				for (unsigned int q=0; q<loopStack.size();q++){
                        					unsigned int loopRef=loopStack[q];
                        					if(adjacencyMatrix[loopRef*2][k*2]==1&&loopRef!=i){
                        						adjacencyMatrix[i*2][lastLoopID*2]=1;
                        						found=1;
                        						break;
                        					}
                        				}
                        			}
                        			if(found==0){
                        				adjacencyMatrix[i*2][k*2]=1; break;
                        			}
                        			break;
                        		}

                        	}
                        }//close at i is loop //////////////////////

                    }//hasWithin==0

                    if(NodeDataVector.at(i).getDecisionType() == "switch"&&(NodeDataVector.at(j).getDecisionType() == "case"||NodeDataVector.at(j).getDecisionType() == "default")){////
                                withinNode = j*2; adjacencyMatrix[i*2][j*2] = 0;
                               	hasWithin=1; count++;// switchLast=i;

                       } //////////////////////////////////////////
                }//j in i
                else if(NodeDataVector.at(i).getEndLineNumber() < NodeDataVector.at(j).getStartLineNumber()){//i finishes before j starts
                    if(hasAfter == 0 && (NodeDataVector.at(i).getDecisionType() != "while")&& (NodeDataVector.at(i).getDecisionType() != "for")&& (NodeDataVector.at(i).getDecisionType() != "switch")) {
                        adjacencyMatrix[i*2][j*2] = 1;
                        afterNode = j*2;
                        count++;
                        hasAfter++;
                    }
                    else if(hasAfter == 0 && ((NodeDataVector.at(i).getDecisionType() == "while") || (NodeDataVector.at(i).getDecisionType() == "for"))){
                        afterNode = j*2;
                        count++;
                        hasAfter++;
                    }
    				else if(hasAfter == 0 && NodeDataVector.at(i).getDecisionType() == "switch"){////
    					afterNode = j;
    					adjacencyMatrix[j*2][i*2] = 0;
                        while((NodeDataVector.at(afterNode).getDecisionType() == "case"||NodeDataVector.at(afterNode).getDecisionType() == "default")&& afterNode<((arraysize-1)/2)-1){//////////////
                        	afterNode = j+1;}//////////////
                        adjacencyMatrix[afterNode*2][i*2] = 0;
                        adjacencyMatrix[i*2][afterNode*2] = 0;
                        adjacencyMatrix[j*2][i*2] = 0;
                        afterNode=afterNode*2;
                        count++;
                        hasAfter++;
                    } //////////////////////////////////////////hasAfter == 0 &&

                }//close if j is within i
            }//close j for loop


            if(hasWithin == 1 && hasAfter == 0){			//Has something within, Does not have a node after it, Therefore go to END
            	if(NodeDataVector.at(i).getDecisionType()=="while"||NodeDataVector.at(i).getDecisionType()=="for"){
                	if(loopStack.size()==1){
                		adjacencyMatrix[i*2][arraysize-1] =1;
                		 adjacencyMatrix[i*2][i*2+1]=1;
                		 adjacencyMatrix[i*2][(i+1)*2]=0;
                		 adjacencyMatrix[i*2+1][(i+1)*2]=1;
                	}
                	else{
                		int loopRef=loopStack[loopStack.size()-2];
                		adjacencyMatrix[i*2][loopRef*2]=1 ;
                        adjacencyMatrix[i*2][(i+1)*2]=0;
                        adjacencyMatrix[i*2+1][(i+1)*2]=1;
                        adjacencyMatrix[i*2][i*2+1]=1;

                	}

                }
    			/*else if(NodeDataVector.at(i).getDecisionType()=="for"){ ////////////
                    adjacencyMatrix[arraysize - 1][i*2] =1 ;
                }*/
    			else if(NodeDataVector.at(i).getDecisionType()=="else"){                }
    			else if(NodeDataVector.at(i).getDecisionType()=="switch"){  adjacencyMatrix[i*2][i*2+1] =0 ;       }
                else {
                    adjacencyMatrix[i*2][arraysize - 1] =1 ;
                }
            if(loopStack.size()>0){
            	int loopID=loopStack[loopStack.size()-1];
            	for (unsigned int q=0; q<loopStack.size();q++){
            	      unsigned int loopRef = loopStack[q];
            	      if (adjacencyMatrix[loopRef*2][afterNode]==1 && loopRef!=i){
            	           adjacencyMatrix[i*2+1][afterNode]=0;
            	           adjacencyMatrix[i*2][afterNode]=0;
            	           	  if (NodeDataVector.at(i).getDecisionType()=="else"){
            	           		  adjacencyMatrix[i*2][loopID*2]=0;
            	                	 adjacencyMatrix[i*2+1][loopID*2]=1;
            	               }
            	               else if (NodeDataVector.at(i).getDecisionType()=="while" || NodeDataVector.at(i).getDecisionType()=="for"){
            	                	 int lastloopID = loopStack[loopStack.size()-2];
            	                	adjacencyMatrix[i*2][lastloopID*2]=1;
            	               }
            	               else if(NodeDataVector.at(i).getDecisionType()=="switch"){
                    	        	adjacencyMatrix[i*2][loopID*2]=0;
                    	        	adjacencyMatrix[i*2+1][loopID*2]=0;

                    	        }
            	               else{
            	                	adjacencyMatrix[i*2][loopID*2]=1;
            	                	adjacencyMatrix[i*2+1][loopID*2]=1;
            	                	}
            	            break;
            	        }

            	}//close for loop
            }
            }//has within, has after

            else if(hasWithin == 0 && hasAfter ==0){		//Does not have something within, Does Not have anything after it either
                //create linker node and boolean condition to end node
               if ((NodeDataVector.at(i).getDecisionType()=="while"||NodeDataVector.at(i).getDecisionType()=="for")&& NodeDataVector.at(i).getDecisionType() != "switch"){
                      adjacencyMatrix[i*2][i*2+1]=1;//while to test False
                      adjacencyMatrix[i*2][arraysize-1]=1;//false
                      adjacencyMatrix[i*2+1][i*2]=1;
                }
                else if (NodeDataVector.at(i).getDecisionType()=="else"){
                	adjacencyMatrix[i*2][i*2+1] = 1;
                	adjacencyMatrix[i*2+1][arraysize-1]=1;
                	 adjacencyMatrix[i*2][arraysize-1]=0;
                }
                else if(NodeDataVector.at(i).getDecisionType() == "case"||NodeDataVector.at(i).getDecisionType() == "default"){///// last case
                      adjacencyMatrix[(i-1)*2][i*2] = 0;
                      adjacencyMatrix[i*2][i*2+1]=0;
                      adjacencyMatrix[i*2+1][i*2]=1;//case statement to case
                      adjacencyMatrix[switchLast*2][i*2] = 0; // to case
                      adjacencyMatrix[switchLast*2][i*2+1] = 1;//switch to case true
                      count++;
                      adjacencyMatrix[i*2][arraysize-1]=1;//case to afternode
                }/////////////////////////////////
                else if(NodeDataVector.at(i).getDecisionType()=="switch"){  adjacencyMatrix[i*2][arraysize - 1] =0;
                adjacencyMatrix[i*2][i*2+1] =0;       }
                else{
                	adjacencyMatrix[i*2][arraysize-1] =1;
                	adjacencyMatrix[i*2][i*2+1] =1;
                	adjacencyMatrix[i*2+1][arraysize-1] =1;
                }

                if (loopStack.size()>0){
                  int loopID = loopStack[loopStack.size()-1];

                    for (unsigned int q=0; q<loopStack.size();q++){
                    	unsigned int loopRef = loopStack[q];
                        if (adjacencyMatrix[loopRef*2][(i+1)*2]==1 && loopRef!=i){
                        	adjacencyMatrix[i*2+1][(i+1)*2]=0;
                        	adjacencyMatrix[i*2][(i+1)*2]=0;
                        	adjacencyMatrix[i*2+1][loopID*2]=1;
                        	if (NodeDataVector.at(i).getDecisionType()=="else"){
                        	 adjacencyMatrix[i*2][loopID*2]=0;
                        	}
                        	else if (NodeDataVector.at(i).getDecisionType()=="while" || NodeDataVector.at(i).getDecisionType()=="for"){
              			       int lastloopID = loopStack[loopStack.size()-2];
                            	adjacencyMatrix[i*2][lastloopID*2]=1;
                        	}
                        	else if(NodeDataVector.at(i).getDecisionType()=="case" || NodeDataVector.at(i).getDecisionType()=="default" ){
                        		adjacencyMatrix[i*2][loopID*2]=1;
                        		adjacencyMatrix[i*2+1][loopID*2]=0;
                        	}
                        	else{
                        		adjacencyMatrix[i*2][loopID*2]=1;
                        		adjacencyMatrix[i*2+1][loopID*2]=1;
                        	}
                  break;
  	           	  }
                }//close for loop
               }//if loopstacksize
            }

            else if((hasWithin ==0 && hasAfter == 1)||(hasWithin ==1 && hasAfter == 1)){ //Does not have decision within, Does have decision after
            	int n=NodeDataVector.at(i).getEndLineNumber()+1; //set n to the line number right after this block
            	if ((NodeDataVector.at(i).getDecisionType()=="if" || NodeDataVector.at(i).getDecisionType()=="else if")&&hasWithin==0){ //if the node is "if" or "else if"
            		unsigned int m=0;
            		adjacencyMatrix[i*2][i*2+1]=1;
            		for(unsigned int k=i+1; k<NodeDataVector.size();k++){ //skip through all the else if and else blocks
            			if (NodeDataVector.at(k).getDecisionType()=="else if" && NodeDataVector.at(k).getStartLineNumber()==n){
            				n =NodeDataVector.at(k).getEndLineNumber()+1; //set n to the line number right after this block
            			}
            			else if(NodeDataVector.at(k).getDecisionType()=="else" && NodeDataVector.at(k).getStartLineNumber()==n){
            				n = NodeDataVector.at(k).getEndLineNumber()+1; //set n to the line number right after this block
            				break;}
            			else{ //not an 'else if' or 'else' statement
            				break;            			}
            		}//close k loop
            		int last=0;
            		for (m=i+1; m<NodeDataVector.size();m++){
            			if(NodeDataVector.at(m).getStartLineNumber() >= n){ //if start line is equal to or just greater than n, set a link from node i to this node
            				int found = 0;

            		//if node i is within a loop statement block, and node m has a link to a loop statement, set the link from node i to the previous loop statement
            				if (loopStack.size()>0){
            					int loopID = loopStack[loopStack.size()-1];
            					for (unsigned int q=0;q<loopStack.size();q++){
            						int loopRef = loopStack[q];
            						if (adjacencyMatrix[loopRef*2][m*2]==1 || n >= NodeDataVector.at(loopID).getEndLineNumber()){
            							adjacencyMatrix[i*2+1][loopID*2]=1;
            				        	found = 1;
            				        	break;
            				      }
            				   }
            			}
            //if node m doesn't have a link to a loop statement, set node i to node m
            			if (found==0){
            			adjacencyMatrix[i*2+1][m*2]=1;
            			break;
            			 }
            	 break;
            			}
            	//if node m is the end node, set node i to the end node
            		if (m==NodeDataVector.size()-1){
            			   last = 1;
            		}
            				//adjacencyMatrix[i*2+1][m*2]=1; break;}
            		}//close m loop

            		if (last){
            		        	if (loopStack.size()>0){
            		        int loopID = loopStack[loopStack.size()-1];
            		        	adjacencyMatrix[i*2+1][loopID*2]=1;
            		        	}
            		  else{
            		      adjacencyMatrix[i*2+1][m*2]=1;
            		      }
            	 }
            	}//close else if (decision is if or else if)////////////////////////////
            	else if ((NodeDataVector.at(i).getDecisionType()=="if" || NodeDataVector.at(i).getDecisionType()=="else if")&&hasWithin==1){
            		}
            	else if(NodeDataVector.at(i).getDecisionType() == "case"||NodeDataVector.at(i).getDecisionType() == "default"){/////
            		adjacencyMatrix[(i-1)*2][i*2] = 0;
            		adjacencyMatrix[switchLast*2][i*2] = 0;
            	    adjacencyMatrix[switchLast*2][i*2+1] = 1;//switch to case statement is true
            	    count++;
            	    afterNode=i+1;
            	    while ((NodeDataVector.at(afterNode).getDecisionType() == "case"||NodeDataVector.at(afterNode).getDecisionType() == "default") && afterNode<((arraysize-1)/2)-1){afterNode=afterNode+1;}
            	    if(afterNode==(((arraysize-1)/2)-1) && ((NodeDataVector.at(afterNode).getDecisionType()=="case"||NodeDataVector.at(afterNode).getDecisionType() == "default"))){//||NodeDataVector.at(afterNode).getDecisionType() == "default"
            	    	adjacencyMatrix[i*2][arraysize-1]=1;//case to afternode
            	    }
            	    else{adjacencyMatrix[i*2][afterNode*2]=1;
            	    if(loopStack.size()>0){
            	    	int loopID=loopStack[loopStack.size()-1];
            	    	adjacencyMatrix[i*2+1][loopID*2]=0;
            	    	adjacencyMatrix[i*2][(i+1)*2]=0;
            	    	adjacencyMatrix[i*2][arraysize-1]=0;
            	    	adjacencyMatrix[i*2][loopID*2]=1;
            	    	}//case to afternode
            	    }
            	    adjacencyMatrix[i*2+1][i*2]=1;//case statement to case
            	}/////////////////////////////////
            	else if (NodeDataVector.at(i).getDecisionType()=="else"){
            		adjacencyMatrix[i*2][i*2+1]=1;
            		adjacencyMatrix[i*2+1][afterNode]=1;
            		adjacencyMatrix[i*2][afterNode]=0;
            	}
            	else if ((NodeDataVector.at(i).getDecisionType()=="while"||NodeDataVector.at(i).getDecisionType()=="for")&&hasWithin==0){
                        adjacencyMatrix[i*2][i*2+1]=1;//while to test False
                        adjacencyMatrix[i*2+1][i*2]=1;//test false to decision
                        int n=NodeDataVector.at(i).getEndLineNumber()+1;
                        for(unsigned int k=i+1;k<NodeDataVector.size();k++){
                        	if(NodeDataVector.at(k).getStartLineNumber()>=n){
                        		adjacencyMatrix[i*2][k*2]=1;
                        		break;
                        	}
                        }
            	}
            	else if ((NodeDataVector.at(i).getDecisionType()=="while" || NodeDataVector.at(i).getDecisionType()=="for")&&hasWithin==1){
            		adjacencyMatrix[i*2][withinNode]=0;
            		adjacencyMatrix[i*2][i*2+1]=1;
            		adjacencyMatrix[i*2+1][withinNode]=1;
            	}
            	else if(NodeDataVector.at(i).getDecisionType()=="switch"){

            	}
            	else{
            		adjacencyMatrix[i*2][i*2+1]=1;
            		//adjacencyMatrix[i*2+1][afterNode]=1;///////////////////////////
            	}


            	if ((unsigned)afterNode==NodeDataVector.size()-1 && (NodeDataVector.at(i).getDecisionType()=="case" || NodeDataVector.at(i).getDecisionType()=="default")){
            		if (NodeDataVector.at(afterNode).getDecisionType()=="case" || NodeDataVector.at(afterNode).getDecisionType()=="default"){
            			afterNode= afterNode+1;
            		}
            	}
            	if (NodeDataVector.at(i).getDecisionType()=="case" || NodeDataVector.at(i).getDecisionType()=="default"){
            		afterNode=afterNode*2;
            	}

            	//checks whether the next node has a link (false) from a loop statement
            	        	//if yes, sets the true nodes of the decision statement to go to the previous loop statement
            	if (loopStack.size()>0){
            	  int loopID = loopStack[loopStack.size()-1];
            	   for (unsigned int q=0; q<loopStack.size();q++){
            	         unsigned int loopRef = loopStack[q];
            	         if (adjacencyMatrix[loopRef*2][afterNode]==1 && loopRef!=i){
            	        	 adjacencyMatrix[i*2+1][afterNode]=0;
            	        	 adjacencyMatrix[i*2][afterNode]=0;
            	        if (NodeDataVector.at(i).getDecisionType()=="else"){
            	        	adjacencyMatrix[i*2][loopID*2]=0;
            	        	adjacencyMatrix[i*2+1][loopID*2]=1;
            	        }
            	        else if (NodeDataVector.at(i).getDecisionType()=="while" || NodeDataVector.at(i).getDecisionType()=="for"){
            	        	int lastloopID = loopStack[loopStack.size()-2];
            	        	adjacencyMatrix[i*2][lastloopID*2]=1;
            	        	//adjacencyMatrix[lastloopID*2+1][loopID*2]=1;///////////
            	        	if (hasWithin ==0){
            	        		adjacencyMatrix[i*2+1][loopID*2]=1;
            	        	}
            	        }
            	        else if(NodeDataVector.at(i).getDecisionType()=="switch"){
            	        	adjacencyMatrix[i*2][loopID*2]=0;
            	        	adjacencyMatrix[i*2+1][loopID*2]=0;

            	        }
            	        else if(NodeDataVector.at(i).getDecisionType()=="case" || NodeDataVector.at(i).getDecisionType()=="default"){
            	        	adjacencyMatrix[i*2][afterNode]=0;
            	        	adjacencyMatrix[i*2][loopID*2]=1;

            	        }
            	        else{
            	        	adjacencyMatrix[i*2][loopID*2]=1;
            	        	adjacencyMatrix[i*2+1][loopID*2]=1;
            	        	}
            	     break;
            	         }
            	   }
            	}
            }//close if within =0, hasAfter=1
            if (loopStack.size()>0 && i+1<NodeDataVector.size()){
                	   for (int q=loopStack.size()-1; q>=0;q--){
                		   unsigned int loopID = loopStack[q];
                			   if (NodeDataVector.at(loopID).getEndLineNumber() < NodeDataVector.at(i+1).getStartLineNumber()){
                				   loopStack.pop_back();
                			   }
                	   }
                   }
        }//close i loop
        writeDotFile(adjacencyMatrix);
        return adjacencyMatrix;
    }

    void LogicAnalyzer::writeDotFile(vector< vector<int> > DirectedVector){
           ofstream graphFile("graphcode.dot");			//out DOT file for graph creation
           graphFile << "digraph G {"<<endl;
           graphFile << "size = \"8,10\""<<";"<<endl;

           for(unsigned int i = 0; i < NodeDataVector.size(); i++){
               graphFile << "\"" << NodeDataVector.at(i).getDecisionType() << NodeDataVector.at(i).getBooleanExpression()<< "\" [ style=filled, fillcolor=paleturquoise3];"<<endl;
           }
           graphFile << "Start [style=filled, shape=box, fillcolor=antiquewhite]; \n End [style=filled, shape=box, fillcolor=antiquewhite];\n";
           graphFile << "Start -> "<< "\""<< NodeDataVector.at(0).getDecisionType()<<NodeDataVector.at(0).getBooleanExpression()<< "\";\n";
           stringstream connectionStream;
           vector<string> Connections;
           string trueColor = "mediumseagreen";
           string falseColor = "red3";
           string color = "";

           for(int i = 0; i <arraysize; i++){											//Prints the completed directed graph
               color = trueColor;

               for(int j = 0; j < arraysize; j++){
                   /*4 Possibilities  for the matrix. Each decision statement has at least 2 options, and for a while loop
       					 *  ConnectionCount,DecisionType
       					 *
       					 *
       					 *  4 Possibilities for the row
       					 *  	0,0	Decision Statement -> Decision Statement
       					 *  	0,1	Decision Statement -> Connector
       					 *  	1,0	Connector 	-> Decision Statement
       					 *  	1,1	Connector 	-> Connector
       					*/

                   if(DirectedVector[i][j] ==1){
                       if(i % 2 == 0){
                           if(j % 2 ==0){		//Decision Statement -> Decision Statement
                               if(j == arraysize-1){
                                   graphFile << "\""<<  NodeDataVector.at(i/2).getDecisionType()<< NodeDataVector.at(i/2).getBooleanExpression()<< "\"" << " ->  End"<<"[color =" << color << "];"<<endl;
                                   color = falseColor;
                               }
                               else if(i == arraysize-1) {
                                   graphFile << "\""<< "End\" -> "<< "\"" << NodeDataVector.at(j/2).getDecisionType() <<  NodeDataVector.at(j/2).getBooleanExpression()<< "\";"<<endl;
                               }
                               else{		//Decision Statement -> Decision Statement
                                   if((NodeDataVector.at(j/2).getDecisionType() == ("while")||("for")) && j - i  < 0){/////// Return Statements should be black j - i < 0 if it is going backwards
                                       graphFile << "\""<<  NodeDataVector.at(i/2).getDecisionType() <<  NodeDataVector.at(i/2).getBooleanExpression() << "\""<< " -> " << "\""<< NodeDataVector.at(j/2).getDecisionType() <<  NodeDataVector.at(j/2).getBooleanExpression()<< "\";"<<endl;
                                   }
                                   else{
                                       graphFile << "\""<<  NodeDataVector.at(i/2).getDecisionType() <<  NodeDataVector.at(i/2).getBooleanExpression() << "\""<< " -> " << "\""<< NodeDataVector.at(j/2).getDecisionType() <<  NodeDataVector.at(j/2).getBooleanExpression()<< "\"[color =" << color << "];"<<endl;
                                       color = falseColor;
                                       if (NodeDataVector.at(j/2).getDecisionType() == ("case")||("default")){
                                    	   color = trueColor;
                                       } //////////////////////////////////
                                   }
                               }
                           }
                           else if(j % 2 ==1){		//Decision  -> 	Connector
                               graphFile <<"\""<< NodeDataVector.at(i/2).getDecisionType() <<  NodeDataVector.at(i/2).getBooleanExpression()<<"\" -> \""<< NodeDataVector.at(j/2).getBooleanExpression()<< "\""<< "[color =" << color << "];"<<endl;
                               color = falseColor;
                               if (NodeDataVector.at(j/2).getDecisionType() == ("case")||("default")){
                                   color = trueColor;
                               } //////////////////////////////////
                           }
                       }
                       else if(i % 2 == 1){
                           if(j % 2 ==0){		//connector -> DecisionStatement
                               if(j == arraysize-1){  //connector -> End
                                   graphFile << "\"" << NodeDataVector.at(i/2).getBooleanExpression() << "\" [style=filled, shape=doublecircle, fillcolor=palegreen3];"<<endl;			//Set node attributes. Done here since it choose t oonly do the ones which are active
                                   graphFile << "\"" <<NodeDataVector.at(i/2).getBooleanExpression() << "\" -> End " << "[color =" << color << "];"<<endl;
                                   color = falseColor;
                               }
                               else if(i == arraysize-1) { // End -> Connector
                                   graphFile << "\"" << NodeDataVector.at(j/2).getBooleanExpression() << "\" [style=filled, shape=doublecircle, fillcolor=palegreen3];"<<endl;			//Set node attributes
                                   graphFile << "\""<< "End\" -> "<< "\"" << NodeDataVector.at(j/2).getBooleanExpression()<< "\""<< "[color =" << color << "];"<<endl;
                                   color = falseColor;
                               }
                               else{	//connector -> Decision
                                   graphFile << "\"" << NodeDataVector.at(i/2).getBooleanExpression() << "\" [style=filled, shape=doublecircle, fillcolor=palegreen3];"<<endl;
                                   graphFile << "\"" <<NodeDataVector.at(i/2).getBooleanExpression() << "\" -> "<< "\""<<  NodeDataVector.at(j/2).getDecisionType() <<  NodeDataVector.at(j/2).getBooleanExpression()<< "\"" << "[color =" << color << "];"<<endl;
                                   color = falseColor;
                                   if (NodeDataVector.at(i/2).getDecisionType() == ("case")||("default")){
                                          color = trueColor;
                                   } //////////////////////////////////
                               }
                           }
                       }
                   }
               }
           }
           graphFile << "\n }";
           graphFile.close();
           //string command = "dot -Tpng   -o  ./analysis.png ./graphcode.dot";// /usr/local/bin/
           //string command = "dot -Tpng   -o  ./analysis.png C:/Users/User1/Desktop/2011School/CISC320/Project5March16/graphcode.dot";
           /////string command = "C:\\Program Files\\Graphviz2.26.3\\bin\\dot.exe" -Tpdf   C:/Users/user1/Desktop/2011School/CISC320/Project5March16th/graphcode.dot -o  ./analysis.pdf";
   string command=("dot -Tpng -o ./analysis.png ./graphcode.dot");
   //string command=("dot -Tpng -o ./analysis.png C:/Users/user1/Desktop/2011School/CISC320/Project5March16th/graphcode.dot");
           //command="./dot -Tpdf ./graphcode.dot   -o \""
           //command.append(graphWriteDir);
           //command += "\"";
           cout<<"Command was "<<command<<endl;

           system(command.c_str());
           cout<<"Dot File Creation Was A Success!" << endl;
           cout<<"done."<<endl;

       }




    int LogicAnalyzer::countEdges(vector< vector<int> > DirectedVector){
        int edgeCount= 0;
        for (unsigned int i = 0; i < DirectedVector.size() ; i++){				//Array Row Counter
            for ( unsigned int k = 0 ; k < DirectedVector.size(); k++){		//decision counter row
                if(DirectedVector[i][k] == 1){
                    edgeCount++;
                }
            }

        }
        return edgeCount;
    }
    int LogicAnalyzer::countNodes(vector< vector<int> > DirectedVector){
        int edgeCount= 0;
        int nodeCount = 0;
        for (unsigned int i = 0; i < DirectedVector.size() ; i++){				//Array Row Counter
            edgeCount= 0;
            for ( unsigned int k = 0 ; k < DirectedVector.size(); k++){		//decision counter row
                if(DirectedVector[i][k] == 1){
                    edgeCount++;
                }
            }
            if(edgeCount!=0){
                nodeCount++;
            }

        }
        return nodeCount;
    }


    void LogicAnalyzer::printArray(vector< vector<int> > DirectedVector){
        for (unsigned int i = 0; i < DirectedVector.size() ; i++){				//Array Row Counter
            for ( unsigned int k = 0 ; k < DirectedVector.size(); k++){		//decision counter row
                cout << DirectedVector[i][k];
                if(k == (unsigned)arraysize -1 ){
                    cout << endl;
                }
            }
        }
    }
