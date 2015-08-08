#include <GL/glut.h>
#include <math.h>

int i, j;
const int N = 40;
float x[N], y[N];
#define PI 3.1416

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void DisplayLine()
{
	int p1 [] = {110, 50};
	int p2 [] = {20, 0};
	int p3 [] = {55, 80};
	int p4 [] = {90, 0};
	int p5 [] = {0, 50};

	glClear(GL_COLOR_BUFFER_BIT);

	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(5);

	glBegin(GL_LINE_LOOP);
		//glVertex2iv(p1);
		//glVertex2iv(p2);
		//glVertex2iv(p3);
		//glVertex2iv(p4);
		//glVertex2iv(p5);
	for (i = 0; i < N; i++)
	{
		x[i] = 0.8 * cos(2*i*PI/N) * 50 + 50;
		y[i] = 0.6 * sin(2*i*PI/N) * 50 + 50;
		glVertex2f(x[i], y[i]);
	}

	glEnd();

	glFlush();
}


void DisplayParaLines()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor4f(1.0, 0.0,0.0, 1.0);
	glLineWidth(5);

	glBegin(GL_LINES);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
	glEnd();

	glFlush();
}


void DisplayRect()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(1.0, 0.0,0.0, 1.0);

	glBegin(GL_QUADS);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
	glEnd();

	glFlush();
}



void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);

	glColor3f(1, 0, 0);

	glBegin(GL_LINE_LOOP);
	for (i = 0; i < N; i++)
	{
		x[i] = 0.8 * cos(2*i*PI/N);
		y[i] = 0.8 * cos(2*i*PI/N);
		glVertex2f(x[i], y[i]);
	}
	glEnd();

	glFlush();
}


void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 300);
	glutCreateWindow("OpenGL test application");
	init();
	glutDisplayFunc(DisplayLine);
//	glutDisplayFunc(Display);
	//glutDisplayFunc(DisplayRect);
	//glutDisplayFunc(DisplayParaLines);
	glutMainLoop();
}