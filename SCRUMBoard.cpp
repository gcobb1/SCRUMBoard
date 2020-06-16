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

		

