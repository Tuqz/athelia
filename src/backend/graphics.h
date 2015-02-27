#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <memory>

#include "OGRE/Ogre.h"
#include "cube.h"
#include "gamesystem.h"

class graphicsHandler{
public:
    //Initializations and creations
    int initGraphics(std::string renderSystem, std::string windowTitle, bool fullScreen = false, std::string videoMode = "800 x 600 @ 32-bit colour", std::string pluginsFile = "", std::string resourcesFile = "", std::string logFile = "debug.log");
    Ogre::SceneManager* createSceneManager(std::string managerName="DefaultSceneManager");

    //Utility
    //Check private variables. May be used later for debugging
    int checkRenderWindow();
    int checkSceneManager();
    //Get defaults related to graphics
    std::string getActiveSceneManager();
private:
    Ogre::RenderSystem *renderer;
    Ogre::RenderWindow *window;
    Ogre::SceneManager *sceneMgr;
}; extern graphicsHandler graphics;

#endif // GRAPHICS_H_INCLUDED
