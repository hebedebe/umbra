#include <raylib/raylib.h>
#include "Umbra/Application.h"

#include <iostream>

int main()
{
    std::cout << "I'm umbraing it\n";

    Application* app = new Application();
    int status = app->Run();

    return status;
}