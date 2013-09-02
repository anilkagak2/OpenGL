LIB = -lGL -lGLU -lglut
CPP = g++ -Wall

all: vertexList sol3V sol4V 
	$(CPP) torus.cpp -o torus $(LIB)
	$(CPP) quadrics-surface.cpp -o quadrics-surface $(LIB)
	$(CPP) quadrics.cpp -o quadrics $(LIB)
	$(CPP) vertexList-demo.cpp vertexList.o -o vertexList-demo $(LIB)

sol3V: vertexList
	$(CPP) vertexList-sol3.cpp vertexList.o -o vertexList-sol3 $(LIB)

sol4V: vertexList
	$(CPP) vertexList-sol4.cpp vertexList.o -o vertexList-sol4 $(LIB)

vertexList:
	$(CPP) -c vertexList.cpp -o vertexList.o 

clean:
	rm -rf torus quadrics quadrics-surface vertexList.o vertexList-demo vertexList-sol3
