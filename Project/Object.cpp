#include "Object.h"

CObject::CObject()
: mShapeType(SOLID_SPHERE), mSize(0.f), mAngle(0.f), mNowAngle(0.f)
{
}
CObject::~CObject()
{
}

GLvoid CObject::render()
{
	void(__stdcall *Shape[8])(GLdouble)= { SolidSphere, SolidCube, SolidTeapot, SolidTorus, WireSphere, WireCube, WireTeapot, WireTorus};

	glPushMatrix();
	glTranslatef(mStartPosition.GetX(), mStartPosition.GetY(), mStartPosition.GetZ());

	glRotatef(mNowAngle, mRotate.GetX(), mRotate.GetY(), mRotate.GetZ());
	glTranslatef(mPosition.GetX(), mPosition.GetY(), mPosition.GetZ());
	glColor3ub(mColor.GetX(), mColor.GetY(), mColor.GetZ());
	Shape[mShapeType](mSize);

	mNowAngle += mAngle;

	if (mNowAngle >= 360.f)
		mNowAngle = 0.f;

	glPopMatrix();
}

