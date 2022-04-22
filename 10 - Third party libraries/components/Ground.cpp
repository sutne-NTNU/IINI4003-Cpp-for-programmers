//
// Created by Sivert Utne on 09/10/2020.
//
#include <OpenGL/glu.h>
#include <btBulletDynamicsCommon.h>



class Ground
{
	btStaticPlaneShape shape;
	btDefaultMotionState motion_state;

public:
	btRigidBody body;



	Ground() : shape(btVector3(0.0, 1.0, 0.0), 0.0),
	           body(0.0, &motion_state, &shape)
	{
		body.setRollingFriction(0.1);
		body.setRestitution(0.8);
	}



	void draw() const
	{
		auto position = body.getCenterOfMassPosition();

		float size = 20.0;

		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.1, 0.8, 0.1);
		glNormal3f(0.0, 1.0, 0.0);
		glVertex3f(position.x() - size, position.y(), position.z() + size);
		glVertex3f(position.x() - size, position.y(), position.z() - size);
		glVertex3f(position.x() + size, position.y(), position.z() + size);
		glVertex3f(position.x() + size, position.y(), position.z() - size);
		glEnd();
	}
};