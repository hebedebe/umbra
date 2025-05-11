#include "Application.h"

#include <ctime>
#include <format>
#include <iostream>
#include <vector>

#include "Screen.h"
#include "Misc/ParticleEmitter.h"
#include "Misc/ParticleSystem.h"

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
	ParticleSystem* particleSystem = new ParticleSystem();
	actors.emplace_back(particleSystem);

	Texture particleTexture = LoadTexture("./Umbra/Textures/Tex_DefaultParticle.png");

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			RadialParticleEmitter* emitter = new RadialParticleEmitter(ActorTransform{ GetMousePosition() }, particleSystem);
			emitter->emissionAngles = { 0, 360 };
			emitter->emissionVelocities = { 10, 80 };
			emitter->emissionTimer = 0.0f;
			emitter->particlesPerEmission = 1;
			emitter->targetTexture = particleTexture;
			actors.emplace_back(emitter);
		}

		for (auto actor : actors)
		{
			actor->Tick(dt);
		}

		m_screen->NewFrame();

		for (auto actor : actors)
		{
			actor->Render();
		}

		DrawText(std::format("FPS: {}", GetFPS()).c_str(), 20, 20, 25, BLACK);
		m_screen->EndFrame();
	}

	for (auto actor : actors)
	{
		delete actor;
	}

	m_screen->Close();

	return EXIT_SUCCESS;
}
