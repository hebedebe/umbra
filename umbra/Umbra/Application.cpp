#include "Application.h"

#include <ctime>
#include <format>
#include <iostream>
#include <vector>

#include "Screen.h"
#include "Misc/ParticleEmitter.h"
#include "Misc/ParticleSystem.h"
#include "Misc/ParticleAttributeModifier.h"

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

		for (int i = 0; i < actors.size();)
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

		for (auto actor : actors)
		{
			actor->Render();
		}

		DrawText(std::format("FPS: {}", GetFPS()).c_str(), 20, 20, 25, BLACK);
		DrawText(std::format("{:.2} ms", GetFrameTime() * 1000).c_str(), 20, 55, 25, BLACK);
		m_screen->EndFrame();
	}

	for (auto actor : actors)
	{
		delete actor;
	}

	m_screen->Close();

	return EXIT_SUCCESS;
}
