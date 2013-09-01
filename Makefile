LIB = -lGL -lGLU -lglut

all:
	g++ torus.cpp -o torus $(LIB)
	g++ quadrics-surface.cpp -o quadrics-surface $(LIB)
	g++ quadrics.cpp -o quadrics $(LIB)

clean:
	rm -rf torus quadrics quadrics-surface
