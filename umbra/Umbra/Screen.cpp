#include "Screen.h"

float Screen::Width() const
{
	return static_cast<float>(m_width);
}

float Screen::Height() const
{
	return static_cast<float>(m_height);
}

const string& Screen::Title()
{
	return m_title;
}

const Color& Screen::ClearColor() const
{
	return m_clearColor;
}

void Screen::SetWidth(int newWidth)
{
	m_width = newWidth;
	SetWindowSize(m_width, m_height);
}

void Screen::SetHeight(int newHeight)
{
	m_height = newHeight;
	SetWindowSize(m_width, m_height);
}

void Screen::SetTitle(const char* newTitle)
{
	m_title = newTitle;
	SetWindowTitle(m_title.c_str());
}

void Screen::SetClearColor(Color newClearColor)
{
	m_clearColor = newClearColor;
}

Screen::Screen()
	:m_width{ 800 }, m_height{ 800 }, m_title{ "Umbra Application" }, m_clearColor{ RAYWHITE },
	m_isUsingAudio{ false }
{
}

Screen::~Screen() = default;

bool Screen::Open(bool initialiseAudio)
{
	m_isUsingAudio = initialiseAudio;

	InitWindow(m_width, m_height, m_title.c_str());

	if (m_isUsingAudio)
	{
		InitAudioDevice();
	}

	// Returns if the window opened successfully;
	return IsWindowReady();
}

void Screen::Close()
{
	if (m_isUsingAudio)
	{
		CloseAudioDevice();
	}
	CloseWindow();
}

void Screen::NewFrame()
{
	BeginDrawing();
	ClearBackground(m_clearColor);
}

void Screen::EndFrame()
{
	EndDrawing();
}
