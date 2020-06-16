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
#include "WtEnvironment.h"


void boardApplication::AddTask(std::vector<std::vector<std::string> > GridStrings){
	this->size++;
	this->table->clear();
	for(int i = 0; i < (this->size); i++){
		for(int j = 0; j < 4; j++){
			this->table->elementAt((i),(j))->addNew<Wt::WText>(GridStrings[i][j]);
			this->table->elementAt((i),(j))->setStyleClass("tr");
		}
	}
	this->TCells.push_back(this->table->elementAt((this->size - 1),(0)));
	this->addFlagProg = 1;


}

boardApplication::boardApplication(const Wt::WEnvironment& env)
				: Wt::WApplication(env){
	std::string fullstring = "";
	Wt::WApplication::useStyleSheet("style.css");
	Wt::WApplication::setBodyClass("body");
	setTitle("Scrum Task Board");
	this->taskEdit = root()->addWidget(Wt::cpp14::make_unique<Wt::WLineEdit>("Enter Task Here"));
	this->taskEdit->setFocus();
	this->taskEdit->setStyleClass("newTask");
	MovesText = root()->addWidget(std::make_unique<Wt::WText>(std::to_string(numMoves)));

	MovesText->setStyleClass("movesStyle");
	Wt::WPushButton *addButton = root()->addWidget(std::make_unique<Wt::WPushButton>("Add Task"));
	addButton->setStyleClass("button1");
	
	Wt::WPushButton *addButton2 = root()->addWidget(std::make_unique<Wt::WPushButton>("Add Task"));
	addButton2->setStyleClass("button2");
	Wt::WContainerWidget *w2 = root()->addWidget(std::make_unique<Wt::WContainerWidget>());
	w2->setContentAlignment(Wt::AlignmentFlag::Center);
	w2->setStyleClass("container1");
	table = w2->addWidget(std::make_unique<Wt::WTable>());
	table->setHeaderCount(0);
	table->setWidth(Wt::WLength("80%"));
	//For now we are just creating a grid
	//Later we will add a clear add table to add the task to the grid an increase the size of the grid by one
	for(int i = 0; i < this->size; i++){
		for(int j = 0; j < 4; j++){
			if(j == 0){
				
				table->elementAt((i), (j))->addNew<Wt::WText>("To Do");
				table->elementAt((i),(j))->setStyleClass("tr");
			}	
			else if(j == 1){
				table->elementAt((i), (j))->addNew<Wt::WText>("In Progress");
				table->elementAt((i),(j))->setStyleClass("tr");
			}
	
			else if(j == 2){
				table->elementAt((i), (j))->addNew<Wt::WText>("Review");
				table->elementAt((i),(j))->setStyleClass("tr");
			}	
			else if(j == 3){
				table->elementAt((i), (j))->addNew<Wt::WText>("Done");
				table->elementAt((i),(j))->setStyleClass("tr");
			}
		}
	}
	table->setStyleClass("string-item");
	table->addStyleClass("table-bordered");

	ScrumBoard *Sboard = new ScrumBoard();

	auto TasktoProgress = [=]{
		MovesText->setText(std::to_string(this->numMoves++));
	};
	auto TaskAdder = [=]{
		this->taskText = this->taskEdit->displayText();
		this->taskTextStr = this->taskText.toUTF8();
		Sboard->AddTasker(taskTextStr);
		if(Sboard->flag == 1){
			this->AddTask(Sboard->GridStrings);
			Sboard->flag = 0;
		}
		if(addFlagProg == 1){
			//this->TCells[this->size - 2]->clicked().connect(boost::bind(&ScrumBoard::TasktoProgress, i, j));
			//this->TCells[this->size - 2]->clicked().connect(f1);			
			//this->TCells[this->size - 2]->clicked().connect(boost::bind(boardApplication::TasktoProgress()));
			addFlagProg = 0;
		}
	};
	addButton->clicked().connect(std::bind(TaskAdder));

}

