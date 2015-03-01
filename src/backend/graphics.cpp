#include <string>

#include "graphics.h"

graphicsHandler graphics;

int graphicsHandler::initGraphics(std::string renderSystem, std::string windowTitle, bool fullScreen, std::string videoMode, std::string pluginsFile, std::string resourcesFile, std::string logFile){
    //Get the root going to call off of
    gamesystem.root = std::unique_ptr<Ogre::Root>(new Ogre::Root(pluginsFile, resourcesFile, logFile));
    //Load our rendering system. Probably RenderSystem_GL or RenderSystem_GL_d
    gamesystem.root->loadPlugin(renderSystem);
    renderer = gamesystem.root->getRenderSystemByName("OpenGL Rendering Subsystem"); //This isn't very flexible!
    gamesystem.root->setRenderSystem(renderer);
    //Load any config into the render system
    if(fullScreen==true){
        renderer->setConfigOption("Full Screen", "True");
    } else {
        renderer->setConfigOption("Full Screen", "False");
    }
    renderer->setConfigOption("Video Mode", videoMode);
    //Setup window
    window = gamesystem.root->initialise(true, windowTitle);
    //Setup sceneManager
    sceneMgr = createSceneManager();
    //SDKTrays
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation("SdkTrays.zip", "Zip");
    //Setup our overlay stuff
    overlaySystem = new Ogre::OverlaySystem();
    sceneMgr->addRenderQueueListener(overlaySystem);
    trayMgr = new OgreBites::SdkTrayManager("Interface", window, inputContext, this);
    //Show debug window with FPS stats
    trayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);

    return 1;
}

Ogre::SceneManager* graphicsHandler::createSceneManager(std::string managerName){
    return gamesystem.root->createSceneManager(managerName);
}

int graphicsHandler::checkRenderWindow(){
    if(getCurrentWindow() != NULL)
        return 1;
    else
        return -1;
}

int graphicsHandler::checkSceneManager(){
    if(getActiveSceneManager() != NULL)
        return 1;
    else
        return -1;
}

Ogre::SceneManager* graphicsHandler::getActiveSceneManager(){
    return sceneMgr;
}

Ogre::RenderWindow* graphicsHandler::getCurrentWindow(){
    return window;
}
