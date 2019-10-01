
#include <Bomberman/Window/Helpers.hpp>
#include <SFML/Window.hpp>

#include <iostream>

#ifdef BOMBERMAN_WINDOWS
    #include <windows.h>
#endif

namespace bmb
{

//////////////////////////////////////////////////////////
void maximizeWindow(sf::Window & window)
{
#ifdef BOMBERMAN_WINDOWS
    ::ShowWindow(window.getSystemHandle(), SW_MAXIMIZE);
#else
    #ifdef BOMBERMAN_DEBUG
        std::clog << "Auto maximize window is not supported on this platform yet.\n";
    #endif
#endif
}

}