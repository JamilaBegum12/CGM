#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
//#include <math.h>
#include<bits/stdc++.h>
using namespace std;
int width = 800;
int hight = 600;
double angle = 0 ;
void init()
{
    // Set display window color to as glClearColor(R,G,B,Alpha)
    glClearColor(0, 0, 1, 1);
    glMatrixMode(GL_PROJECTION);   // Set projection parameters.
    // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)
    gluOrtho2D(-400, width -400, -300, hight-300);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void spin()
{
    angle = angle + 0.00001;
    if (angle >= 360)
    {
        angle = 0;
    }
    glutPostRedisplay();
}
void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);  // Clear display window
    glColor3f(1, 1, 1);            // Set color as glColor3f(R,G,B)
    glRotatef(angle, 0, 0, 1);
    glRecti(-50, -50, 50, 50);
    glColor3f(1, 1, 0);
    glRecti(-25, 50, 25, 300);
    glColor3f(1, 0, 0);
    glRecti(-300, -25, -50, 25);
    glColor3f(0.4, 0, 0);
    glRecti(-25, -300, 25, -50);
    glColor3f(0.4, 0.2, 0.6);
    glRecti(50, -25, 300, 25);
    // Process all OpenGL routine s as quickly as possible
    glFlush();
    glutSwapBuffers();
}

int main(int agrc, char ** argv)
{
    // Initialize GLUT
    glutInit(&agrc, argv);
    // Set display mode
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    // Set top – left display window position.
    glutInitWindowPosition(100, 100);
    // Set display window width and height
    glutInitWindowSize(width, hight);
    // Create display window with the given title
    glutCreateWindow("Rotating Fan");
    // Execute initialization procedure
    init();
    // Send graphics to display window
    glutDisplayFunc(draw);
    glutIdleFunc(spin);
    // Display everything and wait.
    glutMainLoop();
}
