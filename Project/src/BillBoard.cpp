#include "Billboard.h"


Billboard::Billboard(void)
{
}

Billboard::~Billboard(void)
{
}

void Billboard::ReadFile(string fileName)
{
	if (textureNumber >= 0)
		glDeleteTextures(1, &textureNumber);

	textureImage.ReadFile(fileName);

	glGenTextures(1, &textureNumber);
	glBindTexture(GL_TEXTURE_2D, textureNumber);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureImage.width, textureImage.height, 0, 
		GL_RGB, GL_UNSIGNED_BYTE, textureImage.image);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
}

void Billboard::SetSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

void Billboard::SetLocation(Vector3 location)
{
	this->location = location;
}

void Billboard::SetOrientation(float orientation)
{
	this->orientation = orientation;
}

void Billboard::Draw()
{	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureNumber);
	glDisable(GL_LIGHTING);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(location.x, location.y, location.z);
	glRotatef(orientation, 0, 1, 0);
	glScalef(width, height, 1);
	glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2f(0, 0);
		glVertex3f(-0.5, 0, 0);
		glTexCoord2f(1, 0);
		glVertex3f(0.5, 0, 0);
		glTexCoord2f(1, 1);
		glVertex3f(0.5, 1, 0);
		glTexCoord2f(0, 1);
		glVertex3f(-0.5, 1, 0);
	glEnd();	
	
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(location.x, 0, location.z);
	glRotatef(orientation, 0, 1, 0);
	glScalef(0.5, location.y, 1);
	glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex3f(-0.5, 0, 0);
		glVertex3f(0.5, 0, 0);
		glVertex3f(0.5, 1, 0);
		glVertex3f(-0.5, 1, 0);
	glEnd();

	glPopMatrix();

	glEnable(GL_LIGHTING);
}
