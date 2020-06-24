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


//This function adds the first task to the board from the edit line connected to the front end by pushing the line onto the vector. 
void ScrumBoard::AddTasker(std::string taskString){
	this->sizeBoard = this->sizeBoard + 1;
	this->GridStrings.resize(sizeBoard + 1);
	this->flag = 1;
	this->GridStrings[this->sizeBoard].push_back(taskString);
	this->GridStrings[this->sizeBoard].push_back("");
	this->GridStrings[this->sizeBoard].push_back("");
	this->GridStrings[this->sizeBoard].push_back("");
	for(int i = 0; i < sizeBoard; i++){
		//makes sure that the line goes in front of blank lines
		if((this->GridStrings[i][0] == "") || (this->GridStrings[i][0] == " ")){
			this->GridStrings[i][0] = taskString;
			this->GridStrings[this->sizeBoard][0] = " ";
			break;
		} 
	}
}

//The next 3 functions are all similar in that they add a string from the previous selcted index and add it to the next column
void ScrumBoard::AddTasker2(std::string taskString2){
	this->sizeBoard2 = this->sizeBoard2 + 1;
	int pickedNum = 101;
	for(int i = 1; i < this->GridStrings.size(); i++){
		if(this->GridStrings[i][0] == taskString2){
			GridStrings[this->sizeBoard2][1] = taskString2;
			pickedNum = i;
			break;
		}
		
	}
	//the index that was matched is now blank and deleted then the next indexes in line are swapped
	if(pickedNum != 101){
		GridStrings[pickedNum][0] = " ";
		for(int j = pickedNum; j < (this->GridStrings.size() - 1); j++){
			GridStrings[j][0] = GridStrings[(j + 1)][0];
		}
		GridStrings[(this->GridStrings.size() - 1)][0] = " ";
	}
	this->flag2 = 1;
}

//See Above
void ScrumBoard::AddTasker3(std::string taskString3){
	this->sizeBoard3 = this->sizeBoard3 + 1;
	int pickedNum = 101;
	for(int i = 1; i < this->GridStrings.size(); i++){
		if(this->GridStrings[i][1] == taskString3){
			GridStrings[this->sizeBoard3][2] = taskString3;
			pickedNum = i;
			break;
		}
		
	}
	if(pickedNum != 101){
		GridStrings[pickedNum][1] = " ";
		for(int j = pickedNum; j < (this->GridStrings.size() - 1); j++){
			GridStrings[j][1] = GridStrings[(j + 1)][1];
		}
		GridStrings[(this->GridStrings.size() - 1)][1] = " ";
		this->sizeBoard2 = this->sizeBoard2 - 1;
	}
	this->flag3 = 1;
}

//see above
void ScrumBoard::AddTasker4(std::string taskString4){
	this->sizeBoard4 = this->sizeBoard4 + 1;
	int pickedNum = 101;
	for(int i = 1; i < this->GridStrings.size(); i++){
		if(this->GridStrings[i][2] == taskString4){
			GridStrings[this->sizeBoard4][3] = taskString4;
			pickedNum = i;
			break;
		}
		
	}
	if(pickedNum != 101){
		GridStrings[pickedNum][2] = " ";
		for(int j = pickedNum; j < (this->GridStrings.size() - 1); j++){
			GridStrings[j][2] = GridStrings[(j + 1)][2];
		}
		GridStrings[(this->GridStrings.size() - 1)][2] = " ";
		this->sizeBoard3 = this->sizeBoard3 - 1;
	}
	this->flag4 = 1;
}

