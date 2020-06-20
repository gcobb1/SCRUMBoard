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
			if((i == numBlue) && (j == 0)){
				this->table->elementAt((i),(j))->setId("t123");
			}
		}
	}
	for(int k = 1; k < size; k++){
		this->TCells[k] = this->table->elementAt((k),(0));
		this->TCells2[k] = this->table->elementAt((k),(1));
		this->TCells3[k] = this->table->elementAt((k),(2));
		this->TCells4[k] = this->table->elementAt((k),(3));
	}
	this->addFlagProg = 1;


}
void boardApplication::ClearAddBlue2(int numBlue){
	//this->size++;
	this->table->clear();
	for(int i = 0; i < (this->size); i++){
		for(int j = 0; j < 4; j++){
			this->table->elementAt((i),(j))->addNew<Wt::WText>(this->Matrix1[i][j]);
			this->table->elementAt((i),(j))->setStyleClass("td");
			if((i == numBlue) && (j == 1)){
				this->table->elementAt((i),(j))->setId("t123");
			}
		}
	}
	for(int k = 1; k < size; k++){
		this->TCells[k] = this->table->elementAt((k),(0));
		this->TCells2[k] = this->table->elementAt((k),(1));
		this->TCells3[k] = this->table->elementAt((k),(2));
		this->TCells4[k] = this->table->elementAt((k),(3));
	}
	this->addFlagProg = 1;


}
void boardApplication::ClearAddBlue3(int numBlue){
	//this->size++;
	this->table->clear();
	for(int i = 0; i < (this->size); i++){
		for(int j = 0; j < 4; j++){
			this->table->elementAt((i),(j))->addNew<Wt::WText>(this->Matrix1[i][j]);
			this->table->elementAt((i),(j))->setStyleClass("td");
			if((i == numBlue) && (j == 2)){
				this->table->elementAt((i),(j))->setId("t123");
			}
		}
	}
	for(int k = 1; k < size; k++){
		this->TCells[k] = this->table->elementAt((k),(0));
		this->TCells2[k] = this->table->elementAt((k),(1));
		this->TCells3[k] = this->table->elementAt((k),(2));
		this->TCells4[k] = this->table->elementAt((k),(3));
	}
	this->addFlagProg = 1;


}
void boardApplication::ClearAddBlue4(int numBlue){
	//this->size++;
	this->table->clear();
	for(int i = 0; i < (this->size); i++){
		for(int j = 0; j < 4; j++){
			this->table->elementAt((i),(j))->addNew<Wt::WText>(this->Matrix1[i][j]);
			this->table->elementAt((i),(j))->setStyleClass("td");
			if((i == numBlue) && (j == 3)){
				this->table->elementAt((i),(j))->setId("t123");
			}
		}
	}
	for(int k = 1; k < size; k++){
		this->TCells[k] = this->table->elementAt((k),(0));
		this->TCells2[k] = this->table->elementAt((k),(1));
		this->TCells3[k] = this->table->elementAt((k),(2));
		this->TCells4[k] = this->table->elementAt((k),(3));
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
		this->TCells3[k] = this->table->elementAt((k),(2));
		this->TCells4[k] = this->table->elementAt((k),(3));
	}
	this->addFlagProg = 1;


}
void boardApplication::AddTask2(std::vector<std::vector<std::string> > GridStrings){
	//this->size2++;
	this->table->clear();
	for(int i = 0; i < (this->size); i++){//size will be replaced with size max unless I decide to not make it dynamic
		for(int j = 0; j < 4; j++){
			this->table->elementAt((i),(j))->addNew<Wt::WText>(GridStrings[i][j]);
			this->table->elementAt((i),(j))->setStyleClass("td");
		}
	}
	for(int k = 1; k < this->size; k++){
		this->TCells[k] = this->table->elementAt((k),(0));
		this->TCells2[k] = this->table->elementAt((k),(1));
		this->TCells3[k] = this->table->elementAt((k),(2));
		this->TCells4[k] = this->table->elementAt((k),(3));
	}
	this->addFlagProg = 1;
}
void boardApplication::AddTask3(std::vector<std::vector<std::string> > GridStrings){
	//this->size2++;
	this->table->clear();
	for(int i = 0; i < (this->size); i++){//size will be replaced with size max unless I decide to not make it dynamic
		for(int j = 0; j < 4; j++){
			this->table->elementAt((i),(j))->addNew<Wt::WText>(GridStrings[i][j]);
			this->table->elementAt((i),(j))->setStyleClass("td");
		}
	}
	for(int k = 1; k < this->size; k++){
		this->TCells[k] = this->table->elementAt((k),(0));
		this->TCells2[k] = this->table->elementAt((k),(1));
		this->TCells3[k] = this->table->elementAt((k),(2));
		this->TCells4[k] = this->table->elementAt((k),(3));
	}
	this->addFlagProg = 1;
}
void boardApplication::AddTask4(std::vector<std::vector<std::string> > GridStrings){
	//this->size2++;
	this->table->clear();
	for(int i = 0; i < (this->size); i++){//size will be replaced with size max unless I decide to not make it dynamic
		for(int j = 0; j < 4; j++){
			this->table->elementAt((i),(j))->addNew<Wt::WText>(GridStrings[i][j]);
			this->table->elementAt((i),(j))->setStyleClass("td");
		}
	}
	for(int k = 1; k < this->size; k++){
		this->TCells[k] = this->table->elementAt((k),(0));
		this->TCells2[k] = this->table->elementAt((k),(1));
		this->TCells3[k] = this->table->elementAt((k),(2));
		this->TCells4[k] = this->table->elementAt((k),(3));
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

	auto Header = Wt::cpp14::make_unique<Wt::WText>("Scrum Task Board!");
	HeaderText = root()->addWidget(std::make_unique<Wt::WText>("Scrum Task Board!"));
	HeaderText->setStyleClass("Header1");

	this->taskEdit = root()->addWidget(Wt::cpp14::make_unique<Wt::WLineEdit>("Enter Task Here"));
	this->taskEdit->setFocus();
	this->taskEdit->setStyleClass("newTask");
	MovesText = root()->addWidget(std::make_unique<Wt::WText>(std::to_string(numMoves)));

	MovesText->setStyleClass("movesStyle");
	Wt::WPushButton *addButton = root()->addWidget(std::make_unique<Wt::WPushButton>("Add To: To Do"));
	addButton->setStyleClass("button1");
	
	Wt::WPushButton *addButton2 = root()->addWidget(std::make_unique<Wt::WPushButton>("Add To: In Progress"));
	addButton2->setStyleClass("button2");
	Wt::WPushButton *addButton3 = root()->addWidget(std::make_unique<Wt::WPushButton>("Add To: Review"));
	addButton3->setStyleClass("button3");
	Wt::WPushButton *addButton4 = root()->addWidget(std::make_unique<Wt::WPushButton>("Add To: Done"));
	addButton4->setStyleClass("button4");

	Wt::WContainerWidget *w2 = root()->addWidget(std::make_unique<Wt::WContainerWidget>());
	w2->setContentAlignment(Wt::AlignmentFlag::Center);
	w2->setStyleClass("container1");
	this->TCells.resize(100);
	this->TCells2.resize(100);	
	this->TCells3.resize(100);	
	this->TCells4.resize(100);
	table = w2->addWidget(std::make_unique<Wt::WTable>());
	table->setHeaderCount(0);
	table->setWidth(Wt::WLength("100%"));
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
	static std::vector<std::function<void(int)>> functors2;
	static std::vector<std::function<void(int)>> functors3;
	static std::vector<std::function<void(int)>> functors4;
	functors.clear();
	functors2.clear();
	functors3.clear();	
	functors4.clear();
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
			if(this->size > 1){
				for(int incrementer2 = 1; incrementer2 < this->size; incrementer2++){
					this->TCells2[incrementer2]->clicked().connect(std::bind(functors2[incrementer2], incrementer2));
				}
			}
			if(this->size > 1){
				for(int incrementer3 = 1; incrementer3 < this->size; incrementer3++){
					this->TCells3[incrementer3]->clicked().connect(std::bind(functors3[incrementer3], incrementer3));
				}
			}
			if(this->size > 1){
				for(int incrementer47 = 1; incrementer47 < this->size; incrementer47++){
					this->TCells4[incrementer47]->clicked().connect(std::bind(functors4[incrementer47], incrementer47));
				}
			}


			//this->indexClicked = 1;
			//this->table->elementAt((2), (2))->setStyleClass("td");
			//this->table->elementAt((2), (2))->setId("t123");
		});
	}
	for(int i3 = 0; i3 < 100; i3++){
		functors2.push_back([this](int incrementer99){
		//	MovesText->setText(std::to_string(this->numMoves)); 
			this->numMoves = incrementer99;
			
			MovesText->setText(std::to_string(this->numMoves));
			this->ClearAddBlue2(this->numMoves);		
			if(this->size > 1){
				for(int incrementer98 = 1; incrementer98 < this->size; incrementer98++){	
					this->TCells[incrementer98]->clicked().connect(std::bind(functors[incrementer98], incrementer98));	
				}
			}
			if(this->size > 1){
				for(int incrementer97 = 1; incrementer97 < this->size; incrementer97++){
					this->TCells2[incrementer97]->clicked().connect(std::bind(functors2[incrementer97], incrementer97));
				}
			}
			if(this->size > 1){
				for(int incrementer77 = 1; incrementer77 < this->size; incrementer77++){
					this->TCells3[incrementer77]->clicked().connect(std::bind(functors3[incrementer77], incrementer77));
				}
			}
			if(this->size > 1){
				for(int incrementer117 = 1; incrementer117 < this->size; incrementer117++){
					this->TCells4[incrementer117]->clicked().connect(std::bind(functors4[incrementer117], incrementer117));
				}
			}



		});
	}

	for(int i4 = 0; i4 < 100; i4++){
		functors3.push_back([this](int incrementer90){
		//	MovesText->setText(std::to_string(this->numMoves)); 
			this->numMoves = incrementer90;
			
			MovesText->setText(std::to_string(this->numMoves));
			this->ClearAddBlue3(this->numMoves);		
			if(this->size > 1){
				for(int incrementer88 = 1; incrementer88 < this->size; incrementer88++){	
					this->TCells[incrementer88]->clicked().connect(std::bind(functors[incrementer88], incrementer88));	
				}
			}
			if(this->size > 1){
				for(int incrementer87 = 1; incrementer87 < this->size; incrementer87++){
					this->TCells2[incrementer87]->clicked().connect(std::bind(functors2[incrementer87], incrementer87));
				}
			}
			if(this->size > 1){
				for(int incrementer86 = 1; incrementer86 < this->size; incrementer86++){
					this->TCells3[incrementer86]->clicked().connect(std::bind(functors3[incrementer86], incrementer86));
				}
			}
			if(this->size > 1){
				for(int incrementer116 = 1; incrementer116 < this->size; incrementer116++){
					this->TCells4[incrementer116]->clicked().connect(std::bind(functors4[incrementer116], incrementer116));
				}
			}


		});
	}
	for(int i5 = 0; i5 < 100; i5++){
		functors4.push_back([this](int incrementer70){
		//	MovesText->setText(std::to_string(this->numMoves)); 
			this->numMoves = incrementer70;
			
			MovesText->setText(std::to_string(this->numMoves));
			this->ClearAddBlue4(this->numMoves);		
			if(this->size > 1){
				for(int incrementer78 = 1; incrementer78 < this->size; incrementer78++){	
					this->TCells[incrementer78]->clicked().connect(std::bind(functors[incrementer78], incrementer78));	
				}
			}
			if(this->size > 1){
				for(int incrementer107 = 1; incrementer107 < this->size; incrementer107++){
					this->TCells2[incrementer107]->clicked().connect(std::bind(functors2[incrementer107], incrementer107));
				}
			}
			if(this->size > 1){
				for(int incrementer106 = 1; incrementer106 < this->size; incrementer106++){
					this->TCells3[incrementer106]->clicked().connect(std::bind(functors3[incrementer106], incrementer106));
				}
			}
			if(this->size > 1){
				for(int incrementer105 = 1; incrementer105 < this->size; incrementer105++){
					this->TCells4[incrementer105]->clicked().connect(std::bind(functors4[incrementer105], incrementer105));
				}
			}



		});
	}

//MovesText->setText(std::to_string(this->numMoves++));
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
		if((taskTextStr == " ") || (taskTextStr == "")){
			this->noGood = 1;
		}
		if(this->noGood == 0){

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
					for(int incrementer = 1; incrementer < this->size; incrementer++){	
						//indexClickedInc = incrementer;			
								//this->TCells[incrementer]->clicked().connect(std::bind(functors[incrementer]));	
						this->TCells[incrementer]->clicked().connect(std::bind(functors[incrementer], incrementer));	
					}
				//}
				//if(this->size > 1){
					for(int incrementer2 = 1; incrementer2 < this->size; incrementer2++){
						this->TCells2[incrementer2]->clicked().connect(std::bind(functors2[incrementer2], incrementer2));
					}
					for(int incrementer3 = 1; incrementer3 < this->size; incrementer3++){
						this->TCells3[incrementer3]->clicked().connect(std::bind(functors3[incrementer3], incrementer3));
					}
					for(int incrementer7 = 1; incrementer7 < this->size; incrementer7++){
						this->TCells4[incrementer7]->clicked().connect(std::bind(functors4[incrementer7], incrementer7));
					}


				}
					//this->TCells[this->size - 2]->clicked().connect(std::bind(functors[this->size - 2]));
				//this->toDoCount++;
				//this->TCells[this->size - 2]->clicked().connect(boost::bind<void>(TasktoProgress)());	
				//this->TCells[this->size - 2]->clicked().connect(boost::bind(&ScrumBoard::TasktoProgress, i, j));
				//this->TCells[this->size - 2]->clicked().connect(f1);			
				//this->TCells[this->size - 2]->clicked().connect(boost::bind(boardApplication::TasktoProgress()));
				addFlagProg = 0;
			}
		}
		else{
			//error message
			this->noGood = 0;
		}
	};
	addButton->clicked().connect(std::bind(TaskAdder));



	auto TaskAdder2 = [=]{
		//if(indexClicked != 101){i
		if((this->numMoves > 0) && (this->numMoves < this->size + 1)){
			this->taskTextStr2 = Sboard->GridStrings[this->numMoves][0];//change to the table element at the index clicked from lambda function
			if((taskTextStr2 == " ") || (taskTextStr2 == "")){
				this->noGood = 1;
			}
			if(this->noGood == 0){
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
						for(int incrementer4 = 1; incrementer4 < this->size; incrementer4++){	
							this->TCells[incrementer4]->clicked().connect(std::bind(functors[incrementer4], incrementer4));	
						}
					}

					if(this->size > 1){
						for(int incrementer22 = 1; incrementer22 < this->size; incrementer22++){
							this->TCells2[incrementer22]->clicked().connect(std::bind(functors2[incrementer22], incrementer22));
						}
					}
					if(this->size > 1){
						for(int incrementer33 = 1; incrementer33 < this->size; incrementer33++){
							this->TCells3[incrementer33]->clicked().connect(std::bind(functors3[incrementer33], incrementer33));
						}
					}
					if(this->size > 1){
						for(int incrementer63 = 1; incrementer63 < this->size; incrementer63++){
							this->TCells4[incrementer63]->clicked().connect(std::bind(functors4[incrementer63], incrementer63));
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

					this->Matrix1 = Sboard->GridStrings;
				}
			}
			else{
				//error message;
				this->noGood = 0;
			}
		
		//this->indexClicked = 101;
		}
	};
	addButton2->clicked().connect(std::bind(TaskAdder2));
	auto TaskAdder3 = [=]{
		//if(indexClicked != 101){
		if((this->numMoves > 0) && (this->numMoves < this->size + 1)){

			this->taskTextStr3 = Sboard->GridStrings[this->numMoves][1];//change to the table element at the index clicked from lambda function
			if((taskTextStr3 == " ") || (taskTextStr3 == "")){
				this->noGood = 1;
			}
			if(this->noGood == 0){
				//this->taskTextStr2 = this->taskText2;
				Sboard->AddTasker3(taskTextStr3);
				if(Sboard->flag3 == 1){
					this->AddTask3(Sboard->GridStrings);
					Sboard->flag3 = 0;
				}
				if(addFlagProg == 1){
					//functors.push_back([this] { MovesText->setText(std::to_string(this->numMoves++)); });
					//auto lambda = [this] {  MovesText->setText(std::to_string(this->numMoves++)); };
					//vec1.push_back(lambda);
					//this->TCells[this->size - 2]->clicked().connect(std::bind(functors[this->toDoCount]));
					//if(this->toDoCount > 3){
					if(this->size > 1){
						for(int incrementer5 = 1; incrementer5 < this->size; incrementer5++){	
							this->TCells[incrementer5]->clicked().connect(std::bind(functors[incrementer5], incrementer5));	
						}
					}

					if(this->size > 1){
						for(int incrementer23 = 1; incrementer23 < this->size; incrementer23++){
							this->TCells2[incrementer23]->clicked().connect(std::bind(functors2[incrementer23], incrementer23));
						}
					}
					if(this->size > 1){
						for(int incrementer43 = 1; incrementer43 < this->size; incrementer43++){
							this->TCells3[incrementer43]->clicked().connect(std::bind(functors3[incrementer43], incrementer43));
						}
					}
					if(this->size > 1){
						for(int incrementer49 = 1; incrementer49 < this->size; incrementer49++){
							this->TCells4[incrementer49]->clicked().connect(std::bind(functors4[incrementer49], incrementer49));
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

					this->Matrix1 = Sboard->GridStrings;
				}
			}
			else{
				//error message
				this->noGood = 0;
			}
		
		//this->indexClicked = 101;
		}
	};
	addButton3->clicked().connect(std::bind(TaskAdder3));

	auto TaskAdder4 = [=]{
		//if(indexClicked != 101){
		if((this->numMoves > 0) && (this->numMoves < this->size + 1)){

			this->taskTextStr4 = Sboard->GridStrings[this->numMoves][2];//change to the table element at the index clicked from lambda function
			if((this->taskTextStr4 == " ") || (this->taskTextStr4 == "")){
				this->noGood = 1;
			}
			if(this->noGood == 0){	
			//this->taskTextStr2 = this->taskText2;
				Sboard->AddTasker4(taskTextStr4);
				if(Sboard->flag4 == 1){
					this->AddTask4(Sboard->GridStrings);
					Sboard->flag4 = 0;
				}
				if(addFlagProg == 1){
					//functors.push_back([this] { MovesText->setText(std::to_string(this->numMoves++)); });
					//auto lambda = [this] {  MovesText->setText(std::to_string(this->numMoves++)); };
					//vec1.push_back(lambda);
					//this->TCells[this->size - 2]->clicked().connect(std::bind(functors[this->toDoCount]));
					//if(this->toDoCount > 3){
					if(this->size > 1){
						for(int incrementer55 = 1; incrementer55 < this->size; incrementer55++){	
							this->TCells[incrementer55]->clicked().connect(std::bind(functors[incrementer55], incrementer55));	
						}
					}

					if(this->size > 1){
						for(int incrementer230 = 1; incrementer230 < this->size; incrementer230++){
							this->TCells2[incrementer230]->clicked().connect(std::bind(functors2[incrementer230], incrementer230));
						}
					}
					if(this->size > 1){
						for(int incrementer430 = 1; incrementer430 < this->size; incrementer430++){
							this->TCells3[incrementer430]->clicked().connect(std::bind(functors3[incrementer430], incrementer430));
						}
					}
					if(this->size > 1){
						for(int incrementer530 = 1; incrementer530 < this->size; incrementer530++){
							this->TCells4[incrementer530]->clicked().connect(std::bind(functors4[incrementer530], incrementer530));
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

					this->Matrix1 = Sboard->GridStrings;
				}
			}
			else{
				//error message
				this->noGood = 0;
			}
		
		}	
		//this->indexClicked = 101;
	};
	addButton4->clicked().connect(std::bind(TaskAdder4));

	//for(int inc = 1; inc < 99; inc++){
	//	this->TCells[inc]->clicked().connect(std::bind(functors[inc]));	
	//}
}

