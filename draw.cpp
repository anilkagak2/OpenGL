#include <GL/glut.h>
#include <iostream>
#include <cstdio>

#define WIDTH       480
#define HEIGHT      480

#define RED         0
#define GREEN       0
#define BLUE        0
#define ALPHA       1

#define KEY_ESC     27

GLvoid initGL () {
    glClearColor (RED, GREEN, BLUE, ALPHA);
}

GLvoid window_reshape (GLsizei width, GLsizei height) {
    glViewPort (0, 0, width, height);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective (45, (GLdouble)width/(GLdouble)height, 1, 10);
    glMatrixMode(GL_MODELVIEW);
}
void render_scene () {
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
          glVertex3f(1, 0, 0);
          glVertex3f(1, 1, 0);
          glVertex3f(0, 1, 0);
    glEnd ();
}

GLvoid window_display () {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0); 
    render_scene();
    glFlush();
}

GLvoid window_key(unsigned char key, int x, int y) 
{  
    switch (key) {    
        case KEY_ESC:  
            exit(1);                      
            break; 

        default:
            printf ("Pressing %d doesn't do anything.\n", key);
            break;
    }    
}

void init_scene () {}

int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_RGBA);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Square");

    initGL ();
    init_scene ();
    glutDisplayFunc (&window_display);
    glutReshapeFunc (&window_reshape);
    glutKeyboardFunc (&window_key);
    glutMainLoop ();

    return 0;
}
