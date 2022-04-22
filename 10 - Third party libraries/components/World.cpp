//
// Created by Sivert Utne on 09/10/2020.
//
#include <SFML/Graphics.hpp>
#include <btBulletDynamicsCommon.h>



class World
{
	btDefaultCollisionConfiguration collision_configuration;
	btCollisionDispatcher dispatcher;
	btDbvtBroadphase broadphase;
	btSequentialImpulseConstraintSolver solver;

public:
	btDiscreteDynamicsWorld dynamics;

	Ground ground;
	Sphere ball;
	std::vector<Cube> cubes;

	btVector3 initial_position = btVector3(5, 3.1, 0);
	btVector3 initial_velocity = btVector3(-5, 0, 0);
	btTransform transform;



	World() : dispatcher(&collision_configuration),
	          dynamics(&dispatcher, &broadphase, &solver, &collision_configuration),
	          cubes(6)
	{
		dynamics.setGravity(btVector3(0, -9.81, 0));

		// Add objects to the physics engine
		dynamics.addRigidBody(&ground.body);
		for(auto &cube : cubes)
		{
			dynamics.addRigidBody(&cube.body);
		}

		// Position ground
		transform.setIdentity();
		transform.setOrigin(btVector3(0.0, 0.0, 0.0));
		ground.body.setCenterOfMassTransform(transform);

		setUpCubes();
		setUpBall();
	}



	void draw()
	{
		ground.draw();
		ball.draw();
		for(auto &cube : cubes)
		{
			cube.draw();
		}
	}



	void throw_ball()
	{
		dynamics.addRigidBody(&ball.body);
	}



	void move_horizontal(float horizontal_pos)
	{
		transform.setIdentity();
		initial_position.setX(horizontal_pos);
		transform.setOrigin(initial_position);
		ball.body.setCenterOfMassTransform(transform);
	}



	void move_vertical(float vertical_pos)
	{
		transform.setIdentity();
		initial_position.setY(vertical_pos + float(0.1));
		transform.setOrigin(initial_position);
		ball.body.setCenterOfMassTransform(transform);
	}



	void set_startingVelocity(float velocity)
	{
		initial_velocity = btVector3(-velocity, 0, 0);
		ball.body.setLinearVelocity(initial_velocity);
	}



	void setUpCubes()
	{
		transform.setIdentity();
		float posX = -1.0;
		transform.setOrigin(btVector3(posX, 0.1, -0.2));
		cubes[0].body.setCenterOfMassTransform(transform);
		transform.setOrigin(btVector3(posX, 0.1, 0.0));
		cubes[1].body.setCenterOfMassTransform(transform);
		transform.setOrigin(btVector3(posX, 0.1, 0.2));
		cubes[2].body.setCenterOfMassTransform(transform);
		transform.setOrigin(btVector3(posX, 0.3, -0.1));
		cubes[3].body.setCenterOfMassTransform(transform);
		transform.setOrigin(btVector3(posX, 0.3, 0.1));
		cubes[4].body.setCenterOfMassTransform(transform);
		transform.setOrigin(btVector3(posX, 0.5, 0.0));
		cubes[5].body.setCenterOfMassTransform(transform);
	}



	void setUpBall()
	{
		transform.setIdentity();
		transform.setOrigin(initial_position);
		ball.body.setCenterOfMassTransform(transform);
		ball.body.setLinearVelocity(initial_velocity);
		ball.body.setAngularVelocity(btVector3(0, 0, 0));
	}



	void restart(float &initX, float &initY, float &initV)
	{
		initial_position.setX(initX);
		initial_position.setY(initY + float(0.1));
		initial_velocity.setX(-initV);
		dynamics.removeCollisionObject(&ball.body);
		setUpBall();
		setUpCubes();
	}
};

