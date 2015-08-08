#include <windows.h>
#include <gl/glut.h>
#include <stdlib.h>

void Drawing();
void DrawPolygon(int, int);
void OnMouse(int, int, int, int);
void OnKeyboard(unsigned char, int, int);

void Initialization();
void OnDisplay();
void OnDisplayS();
void OnReshape(int, int);

void DrawString(const char* str);

#define MAX_CHAR 128

int winWidth(500), winHeight(500);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Demo");

	Initialization();
	//glutDisplayFunc(OnDisplay);
	glutDisplayFunc(OnDisplayS);
	glutReshapeFunc(OnReshape);

	glutMainLoop();
	return 0;
}

void Drawing()
{

}

void OnDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	Drawing();
	
	glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2i(0, winHeight - 15);
	DrawString("Hello, OpenGL");

	glutSwapBuffers();
}

void Initialization()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void OnReshape(int w, int h)
{
	winWidth = w;
	winHeight = h;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, w, 0, h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void DrawString(const char* str)
{
	static int isFirstCall = 1;
	static GLuint lists;

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

void DrawStringCN(const char* str)
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
		wglUseFontBitmapsW(hDC, wstring[i], 1, list);
		glCallList(list);
	}

	free(wstring);
	glDeleteLists(list, 1);
}

void SelectFont(int size, int charset, const char* face)
{
	HFONT hFont = CreateFontA(size, 0, 0, 0, FW_MEDIUM, 0, 0, 0,
		charset, OUT_DEFAULT_PRECIS, CLIP_CHARACTER_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, face);
	HFONT hOldFont = (HFONT)SelectObject(wglGetCurrentDC(), hFont);
	DeleteObject(hOldFont);
}

void OnDisplayS()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	Drawing();

	SelectFont(48, ANSI_CHARSET, "Comic Sans MS");
	glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2i(0, winHeight - 45);
	DrawString("Hello, OpenGL");


	SelectFont(48, GB2312_CHARSET, "楷体_GB2312");
	glColor3f(1.0f, 0.0f, 0.0f);
	glRasterPos2i(0, winHeight - 120);
	DrawStringCN("Hello, 简体汉字");

	SelectFont(48, DEFAULT_CHARSET, "华文仿宋");
	glColor3f(0.0f, 1.0f, 0.0f);
	glRasterPos2i(0, winHeight - 180);
	DrawStringCN("傳統的中國漢字");

	glutSwapBuffers();
}





