#include "Application.h"

#include <ctime>
#include <format>
#include <iostream>
#include <vector>

#include "Car.h"
#include "RenderUtils.h"
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

	ParticleSystem* pSystem = new ParticleSystem;
	

	std::vector<Texture2D> carSprites = RenderUtils::LoadSpriteSheet("./Umbra/Textures/Tex_BlueCar.png", 16, 16);
	Car* car = new Car{
		SpriteStack {
			carSprites,
			-3
		},
		4000,
		6,
		360*10,
		10
	};
	car->transform.position = { 400, 400 };


	RadialParticleEmitter* pEmitter = new RadialParticleEmitter(car->transform, pSystem);
	Texture particleTex = LoadTexture("./Umbra/Textures/Tex_DefaultParticle.png");
	pEmitter->emissionAngles = { 0, 2*PI };
	pEmitter->emissionAngles = { 30, 50 };
	pEmitter->particlesPerEmission = 1;
	pEmitter->emissionTimer = 0.002f;
	pEmitter->AddAttribute(new TextureAttributeModifier(&particleTex));
	pEmitter->AddAttribute(new ScaleAttributeRandomiser(0.05f, 0.1f));
	pEmitter->AddAttribute(new ScaleChangeAttributeRandomiser(-1.f, -0.05f));
	pEmitter->AddAttribute(new ColorAttributeRandomiser(GRAY, BLACK));
	pEmitter->AddAttribute(new ColorLerpSpeedAttributeRandomiser(0, 10));
	pEmitter->AddAttribute(new TargetColorAttributeRandomiser(Color{255,255,255,0}, Color{ 255,255,255,0 }));

	actors.emplace_back(pSystem);
	actors.emplace_back(pEmitter);
	actors.emplace_back(car);

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
			pEmitter->transform.position = car->transform.position;
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
