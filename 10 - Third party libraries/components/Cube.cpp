//
// Created by Sivert Utne on 09/10/2020.
//
#include <OpenGL/glu.h>
#include <btBulletDynamicsCommon.h>
#include <iostream>



extern "C" {
// Implementation is in libs/glut_shapes.c
void glutSolidCube(GLdouble size);
}



class Cube
{
	btBoxShape shape;
	btDefaultMotionState motion_state;

public:
	btRigidBody body;



	Cube() : shape({ 0.1, 0.1, 0.1 }),
	         body(1.0, &motion_state, &shape)
	{
		auto mass = 1.0 / body.getInvMass();

		btVector3 inertia;
		shape.calculateLocalInertia(mass, inertia);

		body.setMassProps(mass, inertia);
		body.setFriction(0.5);
		body.setRollingFriction(0.1);
		body.setRestitution(0.2);
	}



	void draw()
	{
		glPushMatrix();
		auto position = body.getCenterOfMassPosition();
		glTranslatef(position.x(), position.y(), position.z());
		auto orientation = body.getOrientation();
		auto axis = orientation.getAxis().normalize();
		glRotatef(orientation.getAngle() * 180.0 / M_PI,
		          axis.x(),
		          axis.y(),
		          axis.z());

		glColor3f(0.9, 0.0, 0.4);
		glutSolidCube(0.2);
		glPopMatrix();
	}
};
