#include "DrivingSimulation.h"


DrivingSimulation::DrivingSimulation(void)
{
}


DrivingSimulation::~DrivingSimulation(void)
{
}

void DrivingSimulation::InitializeSimulation(int argc, char** argv)
{
	Simulation::InitializeSimulation(argc, argv);

	// Add your code here.
}

void DrivingSimulation::InitializeGraphics()
{
	Simulation::InitializeGraphics();

	glClearColor(1, 1, 1, 1);
	glColor3f(1, 0, 0);
	glPointSize(3.0);
}

void DrivingSimulation::Reshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);

	glViewport(0, 0, w, h);
}

void DrivingSimulation::Update()
{
}

void DrivingSimulation::Keyboard(unsigned char key, int x, int y)
{
}

void DrivingSimulation::SpecialKey(int key, int x, int y)
{
}

void DrivingSimulation::MouseMove(int x, int y)
{
}

void DrivingSimulation::PassiveMouseMove(int x, int y)
{
}

void DrivingSimulation::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

    GLfloat vertices[3][2] = {{0.0, 0.0},{25.0, 50.0},{50.0, 0.0}}; /* A triangle */

    int j, k;
    int rand();       /* standard random number generator */
    GLfloat p[2] = {7.5, 5.0};  /* An arbitrary initial point inside traingle */

	glBegin(GL_POINTS);
		for(k = 0; k < 20000; k++)
		{
			j = rand() % 3; /* pick a vertex at random */

		 /* Compute point halfway between selected vertex and old point */

			 p[0] = (p[0] + vertices[j][0]) / 2.0; 
			 p[1] = (p[1] + vertices[j][1]) / 2.0;
   
		 /* plot new point */
			glVertex2fv(p); 
		 }
	glEnd();

	glutSwapBuffers();
	glFlush();
}