#include <GL/glut.h>

int p1[] = {10,20};
int p2[] = {100,400};
int p3[] = {60,20};
int p4[] = {80,140};
int p5[] = {180,90};

int square[4][2] = {{10,20}, {110,20}, {110,130}, {10,130}};

GLsizei winW = 1024, winH = 768;
void init () {
    glClearColor (1,1,1,0); // white
}

void wireQuadSurfs () {
    glClear (GL_COLOR_BUFFER_BIT);

//    gluLookAt (2.0,2.0,2.0, 0.0,0.0,0.0, 0.0,0.0,1.0);

    glColor3f (0,0,1);
    glPushMatrix ();
    glutSolidSphere(0.1, 20, 20);
//    glTranslatef (1.0, 1.0, 0.0);
//    glutWireSphere (0.75, 100, 50);
    glPopMatrix (); 

    glColor3f (0.0, 1.0, 0.0);              // set line segment color to red
    glBegin (GL_POLYGON);
        glVertex2iv (p1);
        glVertex2iv (p2);
        glVertex2iv (p3);
        glVertex2iv (p4);
        glVertex2iv (p5);
    glEnd (); 

    // SQUARE
    glColor3f (1.0, 0.5, 0.0);              // set line segment color to red
    glBegin (GL_LINE_LOOP);
        glVertex2iv (square[0]);
        glVertex2iv (square[1]);
        glVertex2iv (square[2]);
        glVertex2iv (square[3]);
    glEnd ();

    glBegin(GL_QUADS); // of the color cube
 
   // Top-face
   glColor3f(0.0f, 1.0f, 0.0f); // green
   glVertex3f(1.0f, 1.0f, -1.0f);
   glVertex3f(-1.0f, 1.0f, -1.0f);
   glVertex3f(-1.0f, 1.0f, 1.0f);
   glVertex3f(1.0f, 1.0f, 1.0f);
 
   // Bottom-face
   glColor3f(1.0f, 0.5f, 0.0f); // orange
   glVertex3f(1.0f, -1.0f, 1.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glVertex3f(1.0f, -1.0f, -1.0f);
 
   // Front-face
   glColor3f(1.0f, 0.0f, 0.0f); // red
   glVertex3f(1.0f, 1.0f, 1.0f);
   glVertex3f(-1.0f, 1.0f, 1.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glVertex3f(1.0f, -1.0f, 1.0f);
 
   // Back-face
   glColor3f(1.0f, 1.0f, 0.0f); // yellow
   glVertex3f(1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, 1.0f, -1.0f);
   glVertex3f(1.0f, 1.0f, -1.0f);
 
   // Left-face
   glColor3f(0.0f, 0.0f, 1.0f); // blue
   glVertex3f(-1.0f, 1.0f, 1.0f);
   glVertex3f(-1.0f, 1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
 
   // Right-face
   glColor3f(1.0f, 0.0f, 1.0f); // magenta
   glVertex3f(1.0f, 1.0f, -1.0f);
   glVertex3f(1.0f, 1.0f, 1.0f);
   glVertex3f(1.0f, -1.0f, 1.0f);
   glVertex3f(1.0f, -1.0f, -1.0f);
 
glEnd(); // of the color cube 

/*    glPushMatrix ();
    glTranslatef (1.0, -0.5, 0.5);
    glutWireSphere (0.7, 2.0, 7.6);
    glPopMatrix ();

    GLUquadricObj *cylinder;
    glPushMatrix ();
    glTranslatef (0.0, 1.2, 0.8);
    cylinder = gluNewQuadric ();
    gluQuadricDrawStyle (cylinder, GLU_LINE);
    gluCylinder (cylinder, 0.6, 0.6, 1.5, 6, 4);
//    glutWireSphere (0.75, 8, 6);
    glPopMatrix ();
*/
    glFlush ();
}

void winReshapeFcn (GLint W, GLint H) {
    /* glViewport (0, 0, W, H);
       glMatrixMode (GL_PROJECTION);
       glOrtho (-2.0, 2.0, -2.0, 2.0, 0.0, 5.0);

       glMatrixMode (GL_MODELVIEW);
       glClear (GL_COLOR_BUFFER_BIT); */

    glViewport(0, 0, W, H);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, W, H, 0.0f, 0.0f, 1.0f);
 //   glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity(); 

    /*if (H == 0) H = 1;                        // To prevent divide by 0
    GLfloat aspect = (GLfloat)W / (GLfloat)H; // Compute aspect ratio

    // Set the viewport (display area on the window) to cover the whole application window
    glViewport(0, 0, W, H);

    // Adjust the aspect ratio of projection's clipping volume to match the viewport 
    glMatrixMode(GL_PROJECTION);   // Select Projection matrix
    glLoadIdentity();              // Reset the Projection matrix

    // Either "perspective projection" or "orthographic projection", NOT both
    // 3D Perspective Projection (fovy, aspect, zNear, zFar), relative to camera's eye position 
    // gluPerspective(45.0, aspect, 0.1, 100.0);

    // OR
    // 3D Orthographic Projection (xLeft, xRight, yBottom, yTop, zNear, zFar),
    // relative to camera's eye position.
    if (W <= H) 
        glOrtho(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect, -1.0, 1.0);  // aspect <= 1
    else 
        glOrtho(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0, -1.0, 1.0);  // aspect > 1

    // Reset the Model-View matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); */
}

int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (100, 100);
    glutInitWindowSize (winW, winH);
    glutCreateWindow ("Wire-frame quadric surfaces");

    init ();
    glutDisplayFunc (wireQuadSurfs);
    glutReshapeFunc (winReshapeFcn);

    glutMainLoop ();
    return 0; 
}
