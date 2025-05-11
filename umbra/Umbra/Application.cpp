#include "Application.h"

#include <ctime>
#include <iostream>

#include "Screen.h"

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

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();

		m_screen->NewFrame();

		//tings go here

		m_screen->EndFrame();
	}

	m_screen->Close();

	return EXIT_SUCCESS;
}
