#include <GL/glut.h>

GLsizei winW = 500, winH = 500;
void init () {
    glClearColor (1,1,1,0); // white
}

void displayWirePolyhedra () {
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0,0,1);

    gluLookAt (5,5,5, 0,0,0, 0,1,0);
    glScalef (1.5, 2.0, 1.0);
    glutWireCube (1.0);

    glScalef (0.8, 0.5, 0.8);
    glTranslatef (-6.0, -5.0, 0.0);
    glutWireDodecahedron ();

    glTranslatef (8.6, 8.6, 2.0);
    glutWireTetrahedron ();

    glTranslatef (-3.0, -1.0, 0.0);
    glutWireOctahedron ();

    glScalef (0.8, 0.8, 1.0);
    glTranslatef (4.3, -2.0, 0.5);
    glutWireIcosahedron ();

    glFlush ();
}

void winReshapeFcn (GLint newW, GLint newH) {
    glViewport (0, 0, newW, newH);
    glMatrixMode (GL_PROJECTION);
    glFrustum (-1.0, 1.0, -1.0, 1.0, 2.0, 20.0);

    glMatrixMode (GL_MODELVIEW);
    glClear (GL_COLOR_BUFFER_BIT);
}

int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (100, 100);
    glutInitWindowSize (winW, winH);
    glutCreateWindow ("Wire-frame polyhedra");

    init ();
    glutDisplayFunc (displayWirePolyhedra);
    glutReshapeFunc (winReshapeFcn);

    glutMainLoop ();
    return 0; 
}
