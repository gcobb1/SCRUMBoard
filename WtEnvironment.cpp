//I beleve  need to create a vector of functor objects up to 100 tasks and each object tells the index that corresponds to the task. 100 possible slots to connect.




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
#include <functional>

void boardApplication::ClearAddBlue(int numBlue){
	//this->size++;
	this->table->clear();
	for(int i = 0; i < (this->size); i++){
		for(int j = 0; j < 4; j++){
			this->table->elementAt((i),(j))->addNew<Wt::WText>(this->Matrix1[i][j]);
			this->table->elementAt((i),(j))->setStyleClass("td");
			if(i == numBlue){
				this->table->elementAt((i),(j))->setId("t123");
			}
		}
	}
	for(int k = 1; k < size; k++){
		this->TCells[k] = this->table->elementAt((k),(0));
		this->TCells2[k] = this->table->elementAt((k),(1));
	}
	this->addFlagProg = 1;


}

void boardApplication::AddTask(std::vector<std::vector<std::string> > GridStrings){
	this->size++;
	this->table->clear();
	for(int i = 0; i < (this->size); i++){
		for(int j = 0; j < 4; j++){
			this->table->elementAt((i),(j))->addNew<Wt::WText>(GridStrings[i][j]);
			this->table->elementAt((i),(j))->setStyleClass("td");
			//this->table->elementAt((i),(j))->setId("t123");
		}
	}
	for(int k = 1; k < size; k++){
		this->TCells[k] = this->table->elementAt((k),(0));	
		this->TCells2[k] = this->table->elementAt((k),(1));
	}
	this->addFlagProg = 1;


}
void boardApplication::AddTask2(std::vector<std::vector<std::string> > GridStrings){
	this->size2++;
	this->table->clear();
	for(int i = 0; i < (this->size); i++){//size will be replaced with size max unless I decide to not make it dynamic
		for(int j = 0; j < 4; j++){
			this->table->elementAt((i),(j))->addNew<Wt::WText>(GridStrings[i][j]);
			this->table->elementAt((i),(j))->setStyleClass("td");
		}
	}
	for(int k = 1; k < size2; k++){
		this->TCells[k] = this->table->elementAt((k),(0));
		this->TCells2[k] = this->table->elementAt((k),(1));
	}
	this->addFlagProg = 1;
}

boardApplication::boardApplication(const Wt::WEnvironment& env)
				: Wt::WApplication(env){
//	std::vector<std::vector<std::string>> Matrix1;
//	for(int incrementW = 0; incrementW < 100; incrementW++){
//		intVec.push_back(incrementW);
//	}
	std::string fullstring = "";
//	int incrementer = 1;
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
	this->TCells.resize(100);
	this->TCells2.resize(100);	
	table = w2->addWidget(std::make_unique<Wt::WTable>());
	table->setHeaderCount(0);
	table->setWidth(Wt::WLength("80%"));
	//For now we are just creating a grid
	//Later we will add a clear add table to add the task to the grid an increase the size of the grid by one
	for(int i = 0; i < this->size; i++){
		for(int j = 0; j < 4; j++){
			if(j == 0){
				
				table->elementAt((i), (j))->addNew<Wt::WText>("To Do");
				table->elementAt((i),(j))->setStyleClass("td");
			}	
			else if(j == 1){
				table->elementAt((i), (j))->addNew<Wt::WText>("In Progress");
				table->elementAt((i),(j))->setStyleClass("td");
			}
	
			else if(j == 2){
				table->elementAt((i), (j))->addNew<Wt::WText>("Review");
				table->elementAt((i),(j))->setStyleClass("td");
			}	
			else if(j == 3){
				table->elementAt((i), (j))->addNew<Wt::WText>("Done");
				table->elementAt((i),(j))->setStyleClass("td");
			}
		}
	}
	table->setStyleClass("string-item");
	table->addStyleClass("table-bordered");

	ScrumBoard *Sboard = new ScrumBoard();
	//static std::vector<std::function<void(int)>> functors;
	
	static std::vector<std::function<void(int)>> functors;
	static std::vector<std::function<void()>> functors2;
	for(int i2 = 0; i2 < 100; i2++){
		
	//functors.push_back([this]{ 
	functors.push_back([this](int incrementer10){ 
			this->numMoves = incrementer10;
			MovesText->setText(std::to_string(this->numMoves));
			this->ClearAddBlue(this->numMoves);		
			if(this->size > 1){
				for(int incrementer = 1; incrementer < this->size; incrementer++){	
					this->TCells[incrementer]->clicked().connect(std::bind(functors[incrementer], incrementer));	
				}
			}
			if(this->size2 > 1){
				for(int incrementer2 = 1; incrementer2 < this->size2; incrementer2++){
					this->TCells2[incrementer2]->clicked().connect(std::bind(functors2[incrementer2]));
				}
			}
			//this->indexClicked = 1;
			//this->table->elementAt((2), (2))->setStyleClass("td");
			//this->table->elementAt((2), (2))->setId("t123");
		});
	}
	for(int i3 = 0; i3 < 100; i3++){
		functors2.push_back([this] { MovesText->setText(std::to_string(this->numMoves++)); });
	}

	//functors.push_back([this] { MovesText->setText(std::to_string(this->numMoves++)); });
	//functors.push_back([&] { return  10; });	
	//auto lambda = [this] {  MovesText->setText(std::to_string(0)); };
	//std::vector<std::function<void>> vec1;
	//auto TasktoProgress = [=]{
//		MovesText->setText(std::to_string(this->numMoves++));
	//};
	auto TaskAdder = [=]{
		this->taskText = this->taskEdit->displayText();
		this->taskTextStr = this->taskText.toUTF8();
		Sboard->AddTasker(taskTextStr);
		if(Sboard->flag == 1){
			this->AddTask(Sboard->GridStrings);
			Sboard->flag = 0;
		}
		if(addFlagProg == 1){
			
	
			//functors.push_back([this] { MovesText->setText(std::to_string(this->numMoves++)); });
			//auto lambda = [this] {  MovesText->setText(std::to_string(this->numMoves++)); };
			//vec1.push_back(lambda);
			//this->TCells[this->size - 2]->clicked().connect(std::bind(functors[this->toDoCount]));
			//if(this->toDoCount > 3){
			if(this->size > 1){
				this->Matrix1.clear();
				//this->Matrix1.resize(Sboard->GridStrings.size());
				//for(int cni = 0; cni < Matrix1.size(); cni++){
				//	this->Matrix1[cni].resize(4);
				//}
				//for(int vecinc = 0; vecinc < Sboard->GridStrings.size(); vecinc++){
				//	for(int vecinc2 = 0; vecinc2 < 4; vecinc2++){
						this->Matrix1 = Sboard->GridStrings;
					//}
				//}
				for(int incrementer = 1; incrementer < this->size; incrementer++){	
					//indexClickedInc = incrementer;			
							//this->TCells[incrementer]->clicked().connect(std::bind(functors[incrementer]));	
					this->TCells[incrementer]->clicked().connect(std::bind(functors[incrementer], incrementer));	
				}
			}
			if(this->size2 > 1){
				for(int incrementer2 = 1; incrementer2 < this->size2; incrementer2++){
					this->TCells2[incrementer2]->clicked().connect(std::bind(functors2[incrementer2]));
				}
			}

				//this->TCells[this->size - 2]->clicked().connect(std::bind(functors[this->size - 2]));
			//}
			//this->toDoCount++;
			
			//this->TCells[this->size - 2]->clicked().connect(boost::bind<void>(TasktoProgress)());	
			//this->TCells[this->size - 2]->clicked().connect(boost::bind(&ScrumBoard::TasktoProgress, i, j));
			//this->TCells[this->size - 2]->clicked().connect(f1);			
			//this->TCells[this->size - 2]->clicked().connect(boost::bind(boardApplication::TasktoProgress()));
			addFlagProg = 0;
		}
	};
	addButton->clicked().connect(std::bind(TaskAdder));


/*
	auto TaskAdder2 = [=]{
		if(indexClicked != 101){
			this->taskTextStr2 = Sboard->GridStrings[indexClicked][0];//change to the table element at the index clicked from lambda function
			
			//this->taskTextStr2 = this->taskText2;
			Sboard->AddTasker2(taskTextStr2);
			if(Sboard->flag2 == 1){
				this->AddTask2(Sboard->GridStrings);
				Sboard->flag2 = 0;
			}
			if(addFlagProg == 1){
				//functors.push_back([this] { MovesText->setText(std::to_string(this->numMoves++)); });
				//auto lambda = [this] {  MovesText->setText(std::to_string(this->numMoves++)); };
				//vec1.push_back(lambda);
				//this->TCells[this->size - 2]->clicked().connect(std::bind(functors[this->toDoCount]));
				//if(this->toDoCount > 3){
				if(this->size > 1){
					for(int incrementer1 = 1; incrementer1< this->size; incrementer1++){	
						//this->TCells[incrementer1]->clicked().connect(std::bind(functors[incrementer1], incrementer1));	
					}
				}
				if(this->size2 > 1){
					for(int incrementer22 = 1; incrementer22 < this->size2; incrementer22++){
						this->TCells2[incrementer22]->clicked().connect(std::bind(functors2[incrementer22]));
					}
				}
					//this->TCells[this->size - 2]->clicked().connect(std::bind(functors[this->size - 2]));
				//}
				//this->toDoCount++;
				
				//this->TCells[this->size - 2]->clicked().connect(boost::bind<void>(TasktoProgress)());	
				//this->TCells[this->size - 2]->clicked().connect(boost::bind(&ScrumBoard::TasktoProgress, i, j));
				//this->TCells[this->size - 2]->clicked().connect(f1);			
				//this->TCells[this->size - 2]->clicked().connect(boost::bind(boardApplication::TasktoProgress()));
				addFlagProg = 0;
			}
		}
		this->indexClicked = 101;
	};
	addButton2->clicked().connect(std::bind(TaskAdder2));
*/
	//for(int inc = 1; inc < 99; inc++){
	//	this->TCells[inc]->clicked().connect(std::bind(functors[inc]));	
	//}
}

