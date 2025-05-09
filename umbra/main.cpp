#include <Umbra/Application.h>

#include <iostream>

#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif


int main()
{
#if _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    std::cout << "I'm umbraing it\n";

    Application* app = new Application();
    int status = app->Run();
    delete app;

    return status;
}