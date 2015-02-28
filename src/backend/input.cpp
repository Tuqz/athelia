#include "graphics.h"
#include "input.h"
#include "patch.h"

inputHandler input;

int inputHandler::setupInputs(){

    //Setup the OIS::InputManager
    OIS::ParamList list;
	size_t windowHandle = 0;
	graphics.getCurrentWindow()->getCustomAttribute("WINDOW", &windowHandle);
	list.insert(std::make_pair("WINDOW", patch::to_string(windowHandle)));
	inputMgr = OIS::InputManager::createInputSystem(list);

    //Setup mouse and keyboard
    kb = (OIS::Keyboard *)(inputMgr->createInputObject(OIS::OISKeyboard, false));
    ms = (OIS::Mouse *)(inputMgr->createInputObject(OIS::OISMouse, false));

    //Bind our inputs to Ogre. This means that we depend on Ogre to keep a high FPS
    bindInput(ms, kb);

    return 1;
}

int inputHandler::bindInput(OIS::Mouse* localMS, OIS::Keyboard* localKB){
   gamesystem.root->addFrameListener(this);
}


bool inputHandler::frameRenderingQueued(const Ogre::FrameEvent &evt){
    bool result = true;
    OIS::Keyboard* keyboard = getActiveKeyboard();
    keyboard->capture();
    if(keyboard->isKeyDown(OIS::KC_ESCAPE))
        gamesystem.quitGame();
    if(keyboard->isKeyDown(OIS::KC_UP)){
        gamesystem.sceneCamera->translate(0, 0, -.25);
    }
    if(keyboard->isKeyDown(OIS::KC_DOWN)){
        gamesystem.sceneCamera->translate(0, 0, .25);
    }
    if(keyboard->isKeyDown(OIS::KC_LEFT)){
        gamesystem.sceneCamera->translate(-.25, 0, 0);
    }
    if(keyboard->isKeyDown(OIS::KC_RIGHT)){
        gamesystem.sceneCamera->translate(.25, 0, 0);
    }
    return result;
}


OIS::Keyboard* inputHandler::getActiveKeyboard(){
    return kb;
}

OIS::Mouse* inputHandler::getActiveMouse(){
    return ms;
}

OIS::InputManager* inputHandler::getInputManager(){
    return inputMgr;
}

