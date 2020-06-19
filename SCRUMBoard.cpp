/*****
Author: Gavin Cobb
Date: April 2020

The purpose of this file is to define the member methods that correspond to the backend that is used to manipulate the front end stylings
Board object is the underlying computational model of the display puzzle
*****/


#include "SCRUMBoard.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>



void ScrumBoard::AddTasker(std::string taskString){
	this->sizeBoard = this->sizeBoard + 1;
	this->GridStrings.resize(sizeBoard + 1);
	this->flag = 1;
	this->GridStrings[this->sizeBoard].push_back(taskString);
	this->GridStrings[this->sizeBoard].push_back("");
	this->GridStrings[this->sizeBoard].push_back("");
	this->GridStrings[this->sizeBoard].push_back("");
}

void ScrumBoard::AddTasker2(std::string taskString2){
	this->sizeBoard2 = this->sizeBoard2 + 1;
	int pickedNum = 101;
	for(int i = 1; i < this->GridStrings.size(); i++){
		if(GridStrings[i][0] == taskString2){
			GridStrings[this->sizeBoard2][1] = taskString2;
			pickedNum = i;
			break;
		}
		
	}
	if(pickedNum != 101){
		for(int j  = (pickedNum + 1); j < this->GridStrings.size(); j++){ 
			GridStrings[j - 1][0] = GridStrings[j][0];
			if(j == (this->GridStrings.size() - 1)){
				GridStrings[j][0] = " ";
			}
		}
	}
	//this->GridStrings.resize(sizeBoard + 1);
	this->flag2 = 1;
	//this->GridStrings[this->sizeBoard].push_back(taskString);
	//this->GridStrings[this->sizeBoard].push_back("");
	//this->GridStrings[this->sizeBoard].push_back("");
	//this->GridStrings[this->sizeBoard].push_back("");
}

		

