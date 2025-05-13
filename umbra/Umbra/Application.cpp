#include "Application.h"

#include <ctime>
#include <format>
#include <iostream>
#include <vector>

#include "Screen.h"
#include "Misc/ParticleEmitter.h"
#include "Misc/ParticleSystem.h"
#include "Misc/ParticleAttributeModifier.h"
#include "Misc/SpriteStack.h"

Screen* Application::m_screen = nullptr;

Screen* Application::GetScreen()
{
	return m_screen;
}

Application::Application()
{
	m_screen = new Screen(); // create a screen (this comment explains that this line creates a screen)
	srand(time(nullptr)); // initialise random
}

Application::~Application()
{
	delete m_screen;
	m_screen = nullptr;
}

int Application::Run()
{
	// Attempt to initialise the window
	// if we fail return failure
	if (!m_screen->Open())
	{
		return EXIT_FAILURE;
	}

	std::vector<Actor*> actors;

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();

		// tick all the actors and delete and erase them if they're marked for deletion
		for (size_t i = 0; i < actors.size();)
		{
			Actor* actor = actors[i];
			actor->Tick(dt);
			if (actor->markedForDeletion)
			{
				delete actor;
				actors.erase(actors.begin() + i);
				continue;
			}
			i++;
		}

		m_screen->NewFrame();

		// render all the actors
		for (auto actor : actors)
		{
			actor->Render();
		}

		// debug info
		DrawText(std::format("FPS: {}", GetFPS()).c_str(), 20, 20, 25, BLACK);
		DrawText(std::format("{:.2} ms", GetFrameTime() * 1000).c_str(), 20, 55, 25, BLACK);

		m_screen->EndFrame();
	}

	// memory cleanup #yeah
	for (auto actor : actors)
	{
		delete actor;
	}

	m_screen->Close();

	return EXIT_SUCCESS;
}
