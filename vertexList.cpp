#include "vertexList.h"


void drawTriangles (vector<Point3D> vertices, float color[3]) {
    // Represent the cube
    glPushMatrix ();
    glBegin (GL_TRIANGLES); 
    glColor3f (color[0], color[1], color[2]); // green

    // Front-face 0->1->2->3
    for (uint i=0; i<vertices.size (); i++) {
        cout << vertices[i][0] << " " << vertices[i][1] << " " <<vertices[i][2] << endl;
        glVertex3fv (vertices[i]);
    }

    glEnd ();
    glPopMatrix ();
    glFlush ();
}

void drawTrianglurMeshes (vector<Point3D> vertices, float color[3]) {
    // Represent the cube
    glPushMatrix ();
    glBegin (GL_TRIANGLE_STRIP); 
    glColor3f (color[0], color[1], color[2]); // green

    // Front-face 0->1->2->3
    for (uint i=0; i<vertices.size (); i++) {
        cout << vertices[i][0] << " " << vertices[i][1] << " " <<vertices[i][2] << endl;
        glVertex3fv (vertices[i]);
    }

    glEnd ();
    glPopMatrix ();
    glFlush ();
}

void drawPolygons (vector<Point3D> vertices, float color[3]) {
    // Represent the cube
    glPushMatrix ();
    glBegin (GL_POLYGON); 
    glColor3f (color[0], color[1], color[2]); // green

    // Front-face 0->1->2->3
    for (uint i=0; i<vertices.size (); i++) 
        glVertex3fv (vertices[i]);

    glEnd ();
    glPopMatrix ();
    glFlush ();
}

/*
 * 0->1->2->3 FRONT FACE
 * 4->5->6->7 BACK FACE
 * 0->1->4->5 TOP
 * 3->2->6->7 BOTTOM
 * 0->3->4->7 LEFT
 * 1->2->6->5 RIGHT
 * */
void drawCube (vector<Point3D> vertices, float color[3]) {
    if (vertices.size () < CUBE_VERTICES) {
        cerr << "Vertices required to represent a cube is " << CUBE_VERTICES << endl;
        return;
    }

    // Represent the cube
    glPushMatrix ();

    glBegin (GL_QUADS); 
    // glColor3f (color[0], color[1], color[2]); // green

    glColor3f(0.0f, 1.0f, 0.0f); // green
    // Front-face 0->1->2->3
    for (int i=0; i<4; i++)
        glVertex3fv (vertices[i]);

    glColor3f(1.0f, 0.5f, 0.0f); // orange
    // Back-face 4->5->6->7
    for (int i=4; i<8; i++)
        glVertex3fv (vertices[i]);

    glColor3f(1.0f, 0.0f, 0.0f); // red
    // Top-face 0->1->4->5 
    glVertex3fv (vertices[0]); glVertex3fv (vertices[1]);
    glVertex3fv (vertices[5]); glVertex3fv (vertices[4]);

    glColor3f(1.0f, 1.0f, 0.0f); // yellow
    // Bottom-face 3->2->6->7
    glVertex3fv (vertices[3]); glVertex3fv (vertices[2]);
    glVertex3fv (vertices[6]); glVertex3fv (vertices[7]);

    glColor3f(0.0f, 0.0f, 1.0f); // blue
    // Left-face 0->3->7->4
    glVertex3fv (vertices[0]); glVertex3fv (vertices[3]);
    glVertex3fv (vertices[7]); glVertex3fv (vertices[4]);

    glColor3f(1.0f, 0.0f, 1.0f); // magenta
    // Right-face 1->2->6->5 
    glVertex3fv (vertices[1]); glVertex3fv (vertices[2]);
    glVertex3fv (vertices[6]); glVertex3fv (vertices[5]);
    glEnd ();  

    glPopMatrix ();
    glFlush ();
}

void drawObjectGivenVertices (enum TypeOfObject typeOfObject, vector<Point3D> vertices, float color[3]) {
    switch ( typeOfObject ) {
        case CUBE:
            drawCube (vertices, color);
            break;
        case TRIANGULAR_MESHES:
            drawTrianglurMeshes (vertices, color);
            break;
        case TRIANGLE:
            drawTriangles (vertices, color);
            break;
        case POLYGON:
            drawPolygons (vertices, color);
            break;
        default:
            cerr << "OBJECT NOT SUPPORTED" << endl;
    }
}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
void glutMainDefault (int argc, char** argv, string programName, displayFunc display, keyControl keyboard,int iWS[2], int iWP[2]) {
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition (iWP[0], iWP[1]);
  glutInitWindowSize (iWS[0], iWS[1]);
  glutCreateWindow (programName.c_str ());

  glEnable(GL_DEPTH_TEST);

  glutDisplayFunc (display);
  glutKeyboardFunc (keyboard);
  glutInitDefault ();
  glutMainLoop ();
}

// Sets up global attributes like clear color and drawing color, and sets up
// the desired projection and modelview matrices.
void glutInitDefault() {
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
  gluLookAt(4, 6, 5, 0, 0, 0, 0, 1, 0);
}


