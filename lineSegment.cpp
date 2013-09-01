#include <GL/glut.h>

GLuint startList;

void init () {
    glClearColor (0, 0, 0, 1);      // display color = white
    glMatrixMode (GL_PROJECTION);           // Set projection parameters
    //gluOrtho2D (0.0, 200.0, 0.0, 150.0);

    GLUquadricObj *qobj;
    // Create 4 display lists, each with a different quadric object.
    // Different draw styles and surface normal specifications are
    // demonstrated.
    startList = glGenLists( 1 );
    qobj = gluNewQuadric();
    gluQuadricDrawStyle( qobj, GLU_FILL );
    gluQuadricNormals( qobj, GLU_SMOOTH );      // smooth shaded
    glNewList( startList, GL_COMPILE );
    gluSphere( qobj, 200, 1500, 10 );
    glEndList();

  /*  gluQuadricDrawStyle( qobj, GLU_FILL );
    gluQuadricNormals( qobj, GLU_FLAT );        // flat shaded
    glNewList( startList+1, GL_COMPILE );
    gluCylinder( qobj, 0.5, 0.3, 1.0, 15, 5 );
    glEndList();

    gluQuadricDrawStyle( qobj, GLU_LINE);       // all polygons wireframe 
    gluQuadricNormals( qobj, GLU_NONE );
    glNewList( startList+2, GL_COMPILE );
    gluDisk( qobj, 0.25, 1.0, 20, 4 );
    glEndList();

    gluQuadricDrawStyle( qobj, GLU_SILHOUETTE );   // boundary only 
    gluQuadricNormals( qobj, GLU_NONE );
    glNewList( startList+3, GL_COMPILE );
    gluPartialDisk( qobj, 0.0, 1.0, 20, 4, 0.0, 225.0 );
    glEndList();
*/
    gluDeleteQuadric(qobj); 
}

void squareBlackBox () {
//    glRotatef(45, 0, 0, 1);
//    glScalef(0.5, 1, 1);
//    glTranslatef(-0.5, -0.5, 0);

    glClear (GL_COLOR_BUFFER_BIT);          // clear display window
    glColor3f (1, 1, 1);              // set line segment color to red
    glCallList (startList);
 /*   glBegin (GL_POLYGON);
        glVertex3f(0, 0, 0);
        glVertex3f(150, 0, 0);
        glVertex3f(150, 150, 0);
        glVertex3f(0, 150, 0);
    glEnd (); */

    glFlush ();                             // Process all opengl routines as quickly as possible
}

int main (int argc, char **argv) {
    glutInit (&argc, argv);                         // Initialize GLUT
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set Display mode
    glutInitWindowPosition (50, 100);               // Set top-get display-window position
    glutCreateWindow ("An Example OpenGL program"); // Create display window

    init ();
    glutDisplayFunc (squareBlackBox);               // Send graphics to display window
    glutMainLoop ();                                // Display everything and wait

    return 0;
}
