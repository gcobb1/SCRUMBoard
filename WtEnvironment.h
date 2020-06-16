#ifndef Wt_Environment_H
#define Wt_Environment_H

/*****
Author: Gavin Cobb
Date: May 2020

The purpose of this file is to the hold the class member declarations for the boardApplication that corresponds to the front end and connects to the
backend of the board object created
*****/




#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WTableCell.h>
#include <Wt/WTable.h>
#include <string>
#include <vector>
#include <iostream>
#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <cstdlib>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "SCRUMBoard.h"
class ScrumBoard;
class boardApplication : public Wt::WApplication
{
public:

        boardApplication(const Wt::WEnvironment& env);
 
        void TasktoProgress(){
                this->MovesText->setText(std::to_string(this->numMoves++));
        }
        void AddTask(std::vector<std::vector<std::string> > GridStrings);
protected:
        int size = 1;
        Wt::WText *ToDo;
        Wt::WText *Doing;
        Wt::WText *Done;
        //Wt::WLineEdit *taskEdit_;
        Wt::WTable *table;
        Wt::WColor *Color;
        Wt::WLineEdit *taskEdit;
        Wt::WString taskText;
        std::string taskTextStr;
        std::vector<Wt::WTableCell *> TCells;
        int addFlagProg = 0;
        Wt::WText *MovesText;
	int numMoves = 0;
};
#endif
