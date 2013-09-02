#include <GL/glut.h>
#include <cmath>

#define toRad(a) a*3.14/180
int square[4][2] = {{3,3}, {0,3}, {0,0}, {3,0}};
int mesh_width = 4;
int mesh_height = 4;
// Clears the window and draws the torus.
void display() {
    float mesh_scale = 10.0;
    float mesh_trans[2];
    mesh_trans[0] = -((mesh_width-1)/2.0)*mesh_scale;
    mesh_trans[1] = -((mesh_height-1)/2.0)*mesh_scale;

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);

    float v[3];
    int row, col;
    for (row=0; row<mesh_height-1; row++)
        for (col=0; col<mesh_width-1; col++)
        {
            v[0] = (col * mesh_scale) + mesh_trans[0]; // X
            v[1] = (row * mesh_scale) + mesh_trans[1]; // Y
            glVertex2f(v[0], v[1]);

            v[0] = (col * mesh_scale) + mesh_trans[0]; // X
            v[1] = ((row+1) * mesh_scale) + mesh_trans[1]; // Y
            glVertex2f(v[0], v[1]);

            v[0] = ((col+1) * mesh_scale) + mesh_trans[0]; // X
            v[1] = ((row+1) * mesh_scale) + mesh_trans[1]; // Y
            glVertex2f(v[0], v[1]);

            // second triangle
            v[0] = ((col+1) * mesh_scale) + mesh_trans[0]; // X
            v[1] = ((row+1) * mesh_scale) + mesh_trans[1]; // Y
            glVertex2f(v[0], v[1]);
            //
            v[0] = (col * mesh_scale) + mesh_trans[0]; // X
            v[1] = (row * mesh_scale) + mesh_trans[1]; // Y
            glVertex2f(v[0], v[1]);

            v[0] = ((col+1) * mesh_scale) + mesh_trans[0]; // X
            v[1] = (row * mesh_scale) + mesh_trans[1]; // Y
            glVertex2f(v[0], v[1]);
        }
    glEnd();
    glFlush();
}

// Sets up global attributes like clear color and drawing color, and sets up
// the desired projection and modelview matrices.
void init() {

  // Set the current clear color to black and the current drawing color to
  // white.
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glColor3f(1.0, 1.0, 1.0);

  // Set the camera lens to have a 60 degree (vertical) field of view, an
  // aspect ratio of 4/3, and have everything closer than 1 unit to the
  // camera and greater than 40 units distant clipped away.
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, 4.0/3.0, 1, 40);

  // Position camera at (4, 6, 5) looking at (0, 0, 0) with the vector
  // <0, 1, 0> pointing upward.
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
//  gluLookAt(4, 6, 5, 0, 0, 0, 0, 1, 0);
}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 600);
  glutCreateWindow("A Simple Torus");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}
