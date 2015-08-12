#include <gl/glut.h>
#include <math.h>

void MyDisplay01(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5.0f);

	//glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glBegin(GL_POINTS);
	{
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.5f, 0.0f);
	}
	glEnd();

	glFlush();
}

void MyDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);
	glFrontFace(GL_CCW);

	glBegin(GL_POLYGON);
	{
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f, -0.5f);
		glVertex2f( 0.0f,  0.0f);
		glVertex2f(-0.5f,  0.0f);
	}
	glEnd();

	glBegin(GL_POLYGON);
	{
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, 0.0f);
	}
	glEnd();
	glFlush();
}

const int n = 20;
const GLfloat R = 0.5f;
const GLfloat PI = 3.1415926536f;

void DrawCircle(void)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_POINTS);
	{
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.5f, 0.0f);
	}
	glEnd();
	//glBegin(GL_POLYGON);
	//{
	//	for (i = 0; i < n; ++i)
	//	{
	//		glVertex2f(R * cos(2*PI/n*i), R * sin(2*PI/n*i));
	//	}
	//}
	//glEnd();

	glFlush;
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("第一个OpenGL程序");
	glutDisplayFunc(&MyDisplay);
	//glutDisplayFunc(&DrawCircle);
	glutMainLoop();
	return 0;
}