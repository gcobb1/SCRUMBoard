SCRUM.wt: SCRUMBoard.o WtEnvironment.o ScrumMain.o
	g++ SCRUMBoard.o WtEnvironment.o ScrumMain.o -o SCRUM.wt -lwthttp -lwt

SCRUMBoard.o: SCRUMBoard.cpp
	g++ -std=c++14 -c SCRUMBoard.cpp -lwthttp -lwt

WtEnvironment.o: WtEnvironment.cpp
	g++ -std=c++14 -c WtEnvironment.cpp -lwthttp -lwt

ScrumMain.o: ScrumMain.cpp
	g++ -std=c++14 -c ScrumMain.cpp -lwthttp -lwt

clean:
	rm *.o SCRUM.wt
