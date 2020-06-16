SCRUM.wt: SCRUMBoard.o WtEnvironment.o SCRUMMain.o
	g++ SCRUMBoard.o WtEnvironment.o SCRUMMain.o -o SCRUM.wt -lwthttp -lwt

SCRUMBoard.o: SCRUMBoard.cpp
	g++ -std=c++14 -c SCRUMBoard.cpp -lwthttp -lwt

WtEnvironment.o: WtEnvironment.cpp
	g++ -std=c++14 -c WtEnvironment.cpp -lwthttp -lwt

SCRUMMain.o: SCRUMMain.cpp
	g++ -std=c++14 -c SCRUMMain.cpp -lwthttp -lwt

clean:
	rm *.o SCRUM.wt
