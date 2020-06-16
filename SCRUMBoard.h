#ifndef SCRUM_BOARD_H
#define SCRUM_BOARD_H

/*****
Author: Gavin Cobb
Date: May 2020

The Purpose of this file is to store the class and member function declarations for the backend that creates manipulations for the front end to correlate to
*****/


#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>


class ScrumBoard{
public:

	ScrumBoard(){
		this->GridStrings.resize(1);
		this->sizeBoard = 0;
		this->GridStrings[0].push_back("To Do");		
		this->GridStrings[0].push_back("In Progress");
		this->GridStrings[0].push_back("Review");
		this->GridStrings[0].push_back("Done");
	}
	~ScrumBoard(){
		delete this;
	}
	void AddTasker(std::string taskString);
	
	//void TasktoProgress(ScrumBoard* Scrum){
		
	//	Scrum->MovesText->setText(std::to_string(Scrum->numMoves++));
	//};


	int sizeBoard = 0;
	std::vector<std::vector<std::string> > GridStrings;
	int flag = 0;	

};
#endif
