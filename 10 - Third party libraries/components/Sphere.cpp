//
// Created by Sivert Utne on 09/10/2020.
//

#include <OpenGL/glu.h>
#include <btBulletDynamicsCommon.h>



class Sphere
{
	btSphereShape shape;
	btDefaultMotionState motion_state;

public:
	btRigidBody body;



	Sphere() : shape(btScalar(0.1)),
	           body(1.0, &motion_state, &shape)
	{
		auto mass = 1.0 / body.getInvMass();

		btVector3 inertia;
		shape.calculateLocalInertia(mass, inertia);

		body.setMassProps(mass, inertia);
		body.setRollingFriction(0.1);
		body.setRestitution(0.8);
	}



	void draw()
	{
		glPushMatrix();
		auto position = body.getCenterOfMassPosition();
		glTranslatef(position.x(), position.y(), position.z());
		glColor3f(0.0, 0.0, 1.0);
		auto quadric = gluNewQuadric();
		gluSphere(quadric, shape.getRadius(), 32, 32);
		gluDeleteQuadric(quadric);
		glPopMatrix();
	}
};
