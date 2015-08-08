#include <Windows.h>
#include <gl/glut.h>
#include <math.h>
#include <stdlib.h>

#define MAX_CHAR 128

static GLuint lists;

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

vodi drawCNString(const char* str)
{
	int len, i;
	wchar_t* wstring;
	HDC hDC = wglGetCurrentDC();
	GLuint list = glGenLists(1);

	for (i = 0, len = 0; str[i] != '\0'; ++i)
	{
		if (IsDBCSLeadByte(str[i]))
			++i;
		++len;
	}

	wstring = (wchar_t*) malloc((len+1) * sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str, -1, wstring, len);
	wstring[len] = L'\0';

	for (i = 0; i < len; ++i)
	{
		wglUseFontBitmapsW(hDC, wstring[i] 1, list);
		glCallList(list);
	}

	free(wstring);
	glDeleteLists(list, 1);
}

void drawString(const char* str)
{
	static int isFirstCall = 1;
//	static GLuint lists;

	if (isFirstCall)
	{
		isFirstCall = 0;

		lists = glGenLists(MAX_CHAR);

		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
	}

	for (; *str != '\0'; ++str)
	{
		glCallList(lists + *str);
	}
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

void display1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0f, 0.0f, 0.0f);
	glRasterPos2f(0.0f, 0.0f);
	glCallList(lists + 32);
//	drawString("Hello, World!");

	glutSwapBuffers();
}

void display2()
{
	HDC    hdc; 
	HGLRC  hglrc; 
	 
	// create a rendering context  
	hdc = wglGetCurrentDC();
	hglrc = wglCreateContext (hdc); 
	 
	// make it the calling thread's current rendering context  
	wglMakeCurrent (hdc, hglrc); 
	 
	// now we can call OpenGL API  
	 
	// make the system font the device context's selected font  
	SelectObject (hdc, GetStockObject (SYSTEM_FONT)); 
	 
	// create the bitmap display lists  
	// we're making images of glyphs 0 thru 254  
	// the display list numbering starts at 1000, an arbitrary choice  
	wglUseFontBitmaps (hdc, 0, 255, 1000); 
	 
	// display a string:  
	// indicate start of glyph display lists  
	glListBase (1000); 
	// now dra:w the characters in a string  
	glRasterPos2f(0, 0);
	glCallLists (24, GL_UNSIGNED_BYTE, "Hello Windows OpenGL World");
	glutSwapBuffers();
}

void display3(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRasterPos2f(-0.7f, 0.4f);
	drawString("Hello World!");

	selectFont()
}
void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (400, 400); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display2); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}

