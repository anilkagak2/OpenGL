
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glut.h>

#include <iostream>
#include <vector>
using namespace std;


// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y=0; 
double rotate_x=0;

typedef struct pt {
    float x;
    float y;
} pt;

vector<pt> triangleMesh;
vector<int> indicesMesh;

void createVertices (pt p1, pt p2, pt p3) {
    int division = 5;

    if (triangleMesh.size () > 0) return;

    triangleMesh.push_back (p1);
    for (int i=1; i<=division; i++) {
        pt pl, pr;
        pl.x = ( p1.x * (division - i) + p2.x * i ) / division;
        pl.y = ( p1.y * (division - i) + p2.y * i ) / division;
        pr.x = ( p1.x * (division - i) + p3.x * i ) / division;
        pr.y = ( p1.y * (division - i) + p3.y * i ) / division;

        triangleMesh.push_back (pl);
        for (int j=1; j<i; j++) {
            pt p;
            p.x = ( pl.x * (i-j) + pr.x * j ) / i;
            p.y = ( pl.y * (i-j) + pr.y * j ) / i;
            triangleMesh.push_back (p);
        }

        triangleMesh.push_back (pr);
    }

    int prev = 0, cur = 1;
    for (int i=1; i<=division; i++) {
        indicesMesh.push_back (prev);
        indicesMesh.push_back (cur);
        indicesMesh.push_back (cur+1);

        for (int j=prev, k=cur+1; j<cur-1; j++, k++) {
            indicesMesh.push_back (j);
            indicesMesh.push_back (j+1);
            indicesMesh.push_back (k);

            indicesMesh.push_back (j+1);
            indicesMesh.push_back (k);
            indicesMesh.push_back (k+1);
        }

        prev = cur;
        cur += i+1;
    }
}

void render() {
}

// display() Callback function
// ----------------------------------------------------------
void display(){
 
  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
  // Reset transformations
  glLoadIdentity();
 
  // Other Transformations
  // glTranslatef( 0.1, 0.0, 0.0 );      // Not included
  // glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included
 
  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
 
  // Other Transformations
  // glScalef( 2.0, 2.0, 0.0 );          // Not included

  pt p1 = {0,0}, p2 = {1,0}, p3 = {1,1};
  createVertices (p1,p2,p3);
  glEnableClientState( GL_VERTEX_ARRAY );
  glVertexPointer ( 2, GL_FLOAT, 0, &triangleMesh[0] );
  glDrawElements( GL_LINE_LOOP, indicesMesh.size (), GL_UNSIGNED_INT, &indicesMesh[0] );
  glDisableClientState( GL_VERTEX_ARRAY ); 

  glFlush();
  glutSwapBuffers();
}

// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
 
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
 
  //  Request display update
  glutPostRedisplay();
 
}
 
 
// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]){
 
  //  Initialize GLUT and process user parameters
  glutInit(&argc,argv);
 
  //  Request double buffered true color window with Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 
  // Create window
  glutInitWindowSize(1000, 1000);
  glutCreateWindow("Awesome Mesh");
 
  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);
 
  // Callback functions
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
 
  //  Pass control to GLUT for events
  glutMainLoop();
 
  //  Return to OS
  return 0;
 
}
