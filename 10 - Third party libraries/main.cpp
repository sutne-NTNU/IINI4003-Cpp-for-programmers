#include "./libs/imgui-sfml/imgui-SFML.h"
#include "./libs/imgui/imgui.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <OpenGL/glu.h>
#include <glm/glm.hpp>
#include <iostream>
#include <chrono>

#include "components/Ground.cpp"
#include "components/Sphere.cpp"
#include "components/Cube.cpp"
#include "components/World.cpp"

void print(const std::string &message)
{
	std::cout << message << std::endl;
}

class Application
{
	sf::ContextSettings context_settings;
	sf::RenderWindow window;
	glm::vec3 camera = glm::vec3(8.0, 4.0, 1.0);

	World world;
	bool ball_has_been_thrown;

public:
	Application() : context_settings(24),
					window(sf::VideoMode(1280, 900),
						   "SFML Example", sf::Style::Default, context_settings)
	{
		window.setFramerateLimit(60);
		window.setVerticalSyncEnabled(true);

		// Various settings
		glClearColor(0.5, 0.5, 0.5, 0.0);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		// Lighting
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		GLfloat ambient[] = {0.2, 0.2, 0.2, 1.0};
		GLfloat diffuse[] = {0.8, 0.8, 0.8, 1.0};
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

		glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.0);
		glEnable(GL_COLOR_MATERIAL);

		GLfloat spot_direction[] = {1.0, -1.0, -0.5};
		glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
		glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 75.0);
		GLfloat light_position[] = {-3.0, 10.0, 0.0, 1.0};
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);

		// Setup projection matrix
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0, 4.0 / 3.0, 0.1, 100.0);

		glMatrixMode(GL_MODELVIEW);

		// ImGui settings
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		ImGui::SFML::Init(window);
	}

	void restart(float horizontal_position, float vertical_position, float starting_velocity)
	{
		if (!ball_has_been_thrown)
			return;
		world.restart(horizontal_position, vertical_position, starting_velocity);
		camera.x = 3.0 + horizontal_position;
		camera.y = 1.0 + vertical_position;
		ball_has_been_thrown = false;
	}

	void throw_ball()
	{
		if (ball_has_been_thrown)
			return;
		world.throw_ball();
		ball_has_been_thrown = true;
	}

	void move_horizontal(float &horizontal_position)
	{
		if (horizontal_position < 0)
		{
			horizontal_position = 0;
			return;
		}
		else if (horizontal_position > 20)
		{
			horizontal_position = 20;
			return;
		}
		if (ball_has_been_thrown)
			return;
		world.move_horizontal(horizontal_position);
		camera.x = 3.0 + horizontal_position;
	}

	void set_startingVelocity(float &starting_velocity)
	{
		if (starting_velocity < 0)
		{
			starting_velocity = 0;
			return;
		}
		else if (starting_velocity > 20)
		{
			starting_velocity = 20;
			return;
		}
		if (ball_has_been_thrown)
			return;
		world.set_startingVelocity(starting_velocity);
	}

	void move_vertical(float &vertical_position)
	{
		if (vertical_position < 0)
		{
			vertical_position = 0;
			return;
		}
		else if (vertical_position > 5)
		{
			vertical_position = 5;
			return;
		}
		if (ball_has_been_thrown)
			return;
		world.move_vertical(vertical_position);
		camera.y = 1.0 + vertical_position;
	}

	void start()
	{
		sf::Clock delta_clock;

		auto last_time = std::chrono::system_clock::now();
		bool running = true;
		float vertical_position = 3.0;
		float horizontal_position = 5.0;
		float starting_velocity = 5.0;
		ball_has_been_thrown = false;
		while (running)
		{
			// Handle events
			sf::Event event;
			while (window.pollEvent(event))
			{
				ImGui::SFML::ProcessEvent(event);
				if (event.type == sf::Event::KeyPressed)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						window.close();
						running = false;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
					{
						restart(horizontal_position, vertical_position, starting_velocity);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					{
						starting_velocity += 0.5;
						set_startingVelocity(starting_velocity);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					{
						starting_velocity -= 0.5;
						set_startingVelocity(starting_velocity);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						throw_ball();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						horizontal_position -= 0.5;
						move_horizontal(horizontal_position);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						horizontal_position += 0.5;
						move_horizontal(horizontal_position);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						vertical_position += 0.5;
						move_vertical(vertical_position);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{
						vertical_position -= 0.5;
						move_vertical(vertical_position);
					}
				}
				else if (event.type == sf::Event::Closed)
				{
					window.close();
					running = false;
				}
			}

			ImGui::SFML::Update(window, delta_clock.restart());

			ImGui::Begin("ImGui");
			if (ImGui::Button("Restart (R)"))
			{
				restart(horizontal_position, vertical_position, starting_velocity);
			}
			if (ImGui::Button("Throw ball (space)"))
			{
				throw_ball();
			}
			if (ImGui::SliderFloat("Horizontal ball position (arrow keys: left/right)", &horizontal_position,
								   0.0, 20.0))
			{
				move_horizontal(horizontal_position);
			}
			if (ImGui::SliderFloat("Vertical ball position (arrow keys: up/down)",
								   &vertical_position, 0.0, 5.0))
			{
				move_vertical(vertical_position);
			}
			if (ImGui::SliderFloat("Starting velocity (W/S)",
								   &starting_velocity, 0.0, 20.0))
			{
				set_startingVelocity(starting_velocity);
			}
			ImGui::End();

			// Draw
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glLoadIdentity();

			gluLookAt(camera.x, camera.y, camera.z, // Camera position
					  0.0, 1.0, 0.0,				// Camera direction
					  0.0, 1.0, 0.0);				// Camera tilt

			auto time = std::chrono::system_clock::now();
			world.dynamics.stepSimulation(std::chrono::duration<float>(time - last_time).count());
			last_time = time;

			world.draw();

			window.pushGLStates();
			ImGui::SFML::Render(window);
			window.popGLStates();

			// Swap buffer (show result)
			window.display();
		}
		ImGui::SFML::Shutdown();
	}
};

int main()
{


	Application application;
	application.start();
}
