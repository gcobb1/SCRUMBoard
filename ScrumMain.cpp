/*****

Author: Gavin Cobb
Title: ScrumTaskBoard
Alternate Title: Scrum Task Board
Version 1.0
Date: 01 May 2020
Description: Scrum Task board is an interactive web application written in C++, Wt framework, Css, and MySql, that allows users to organize tasks through to completion. This application allows for thorough management of ttasks whether that be daily to-do lists, or organizing full scale projects. Utilizing agile methodologies Scrum tasks board gives users a sense of accomplishment when completing there projects and seeing that final not marked as complete!
*****/

#include <Wt/WApplication.h>
#include "SCRUMBoard.h"
#include "WtEnvironment.h"

int main(int argc, char **argv){

//Creates instances of wt server
	return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env){
		return std::make_unique<boardApplication>(env);//change this to whatever the class name is
	});
}
