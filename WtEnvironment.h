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
#include <functional>
class ScrumBoard;
class boardApplication : public Wt::WApplication
{
public:

        boardApplication(const Wt::WEnvironment& env);
 
        void TasktoProgress(){
                this->MovesText->setText(std::to_string(this->numMoves++));
        }
        void ClearAddBlue(int numBlue);
        void ClearAddBlue2(int numBlue); 
        void ClearAddBlue3(int numBlue);
        void ClearAddBlue4(int numBlue);
	void AddTask(std::vector<std::vector<std::string> > GridStrings);
        void AddTask2(std::vector<std::vector<std::string> > GridStrings);
        void AddTask3(std::vector<std::vector<std::string> > GridStrings);
        void AddTask4(std::vector<std::vector<std::string> > GridStrings);
protected:
        int size = 1;
	int size2 = 1;
	int size3 = 1;
	int size4 = 1;
        Wt::WText *ToDo;
        Wt::WText *Doing;
        Wt::WText *Done;
        //Wt::WLineEdit *taskEdit_;
        Wt::WTable *table;
        Wt::WColor *Color;
        Wt::WLineEdit *taskEdit;
        Wt::WString taskText;
        Wt::WString taskText2;
	Wt::WString taskText3;
        std::string taskTextStr;
        std::string taskTextStr2;
	std::string taskTextStr3;
	std::string taskTextStr4;
        std::vector<Wt::WTableCell *> TCells; 
        std::vector<Wt::WTableCell *> TCells2;
        std::vector<Wt::WTableCell *> TCells3;
        std::vector<Wt::WTableCell *> TCells4;
	int noGood = 0;
	int addFlagProg = 0;
        Wt::WText *MovesText;
        Wt::WText *HeaderText;
	int numMoves = 0;
	int toDoCount = 0;
	int indexClicked = 1;
	int indexClickedInc = 1;
	std::vector<std::vector<std::string> > Matrix1;
};
#endif
