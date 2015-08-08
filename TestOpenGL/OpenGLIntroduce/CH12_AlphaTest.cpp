#include <gl/glut.h>
#include <stdio.h>
#include <stdlib.h>

#define WindowWidth		400
#define WindowHeight	400
#define WindowTitle		"OpenGL Œ∆¿Ì≤‚ ‘"

#define BMP_Header_Length 54

int power_of_two(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	return(n & (n-1)) == 0;
}


GLuint load_texture(const char* file_name)
{
	GLint width, height, total_bytes;
	GLubyte* pixels = 0;
	GLuint  texture_ID = 0;
	GLint last_texture_ID;
	FILE* pFile = fopen(file_name, "rb");
	if (pFile == 0)
	{
		return 0;
	}

	fseek(pFile, 0x0012, SEEK_SET);
	fread(&width, 4, 1, pFile);
	fread(&height, 4, 1, pFile);
	fseek(pFile, BMP_Header_Length, SEEK_SET);

	GLint line_bytes = width * 3;
	while (line_bytes % 4 != 0)
	{
		++line_bytes;
	}
	total_bytes = line_bytes * height;

	pixels = (GLubyte*)malloc(total_bytes);
	if (pixels == 0)
	{
		fclose(pFile);
		return 0;
	}

	if (fread(pixels, total_bytes, 1, pFile) <= 0)
	{
		free(pixels);
		fclose(pFile);
		return 0;
	}

	GLint max;
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max);
	if (!power_of_two(width) || !power_of_two(height)
		|| width > max || height > max)
	{
		const GLint new_width = 256;
		const GLint new_height = 256;
		GLint new_line_bytes, new_total_bytes;
		GLubyte* new_pixels = 0;
		
		new_line_bytes = new_width * 3;
		while (new_line_bytes % 4 != 0)
		{
			++new_line_bytes;
		}
		new_total_bytes = new_line_bytes * new_height;

		new_pixels = (GLubyte*)malloc(new_total_bytes);
		if (new_pixels == 0)
		{
			free(pixels);
			fclose(pFile);
			return 0;
		}

		gluScaleImage(GL_RGB, width, height, GL_UNSIGNED_BYTE, pixels,
			new_width, new_height, GL_UNSIGNED_BYTE, new_pixels);
		
		free(pixels);
		pixels = new_pixels;
		width = new_width;
		height = new_height;
	}

	glGenTextures(1, &texture_ID);
	if (texture_ID == 0)
	{
		free(pixels);
		fclose(pFile);
		return 0;
	}

	glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture_ID);
	glBindTexture(GL_TEXTURE_2D, texture_ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
		GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);
	glBindTexture(GL_TEXTURE_2D, last_texture_ID);

	free(pixels);
	return texture_ID;
}


void texture_colorkey(GLubyte r, GLubyte g, GLubyte b, GLubyte absolute)
{
	GLfloat width, height;
	GLubyte* pixels = 0;

	glGetTexLevelParameterfv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
	glGetTexLevelParameterfv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);

	pixels = (GLubyte*)malloc(width * height * 4);
	if (pixels == 0)
	{
		return;
	}
	glGetTexImage(GL_TEXTURE_2D, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, pixels);

	GLint i;
	GLint count = width * height;
	for (i = 0; i < count; ++i)
	{
		if (abs(pixels[i*4] - b) <= absolute 
			&& abs(pixels[i*4 + 1] - g) <= absolute
			&& abs(pixels[i*4 + 2] - r) <= absolute)
		{
			pixels[i*4 + 3] = 0;
		}
		else
		{
			pixels[i*4 + 3] = 255;
		}
	}
	glTexImage2D(GL_TEXTURE_2D, 0, GLUT_RGBA, width, height, 0,
		GL_BGRA_EXT, GL_UNSIGNED_BYTE, pixels);
	free(pixels);
}


void display(void)
{
	static int initialized = 0;
	static GLuint texWindow = 0;
	static GLuint texPicture = 0;

	if (!initialized)
	{
		texPicture = load_texture("pic.bmp");
		texWindow = load_texture("window.bmp");
		glBindTexture(GL_TEXTURE_2D, texWindow);
		texture_colorkey(255, 255, 255, 10);
		glEnable(GL_TEXTURE_2D);
		initialized = 1;
	}

	glClear(GL_COLOR_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, texPicture);
	glDisable(GL_ALPHA_TEST);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex2f( 1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex2f( 1.0f, -1.0f);
	}
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texWindow);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.5f);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex2f( 1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex2f( 1.0f, -1.0f);
	}
	glEnd();

	glutSwapBuffers();
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(WindowWidth, WindowHeight);
	glutCreateWindow(WindowTitle);
	glutDisplayFunc(&display);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	glutMainLoop();
	return 0;
}