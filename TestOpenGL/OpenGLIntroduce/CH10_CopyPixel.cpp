#include <stdio.h>
#include <stdlib.h>


#define WindowWidth		400
#define WindowHeight	400

#define BMP_Header_Length 54

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	{
		glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(1.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.5f, 1.0f);
	}
	glEnd();

	glPixelZoom(-0.5f, -0.5f);
	glRasterPos2i(1, 1);
	glCopyPixels();

	glutSwapBuffers();
}
