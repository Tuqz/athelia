#include "graphics.h"
#include "input.h"
#include "patch.h"

int inputHandler::setupInputs(){
    //Setup the OIS::InputManager
    OIS::ParamList list;
	size_t windowHandle = 0;
	graphics.getCurrentWindow()->getCustomAttribute("WINDOW", &windowHandle);
	list.insert(std::make_pair("WINDOW", patch::to_string(windowHandle)));
	inputMgr = OIS::InputManager::createInputSystem(list);

    //Setup mouse and keyboard
    kb = (OIS::Keyboard *)(inputMgr->createInputObject(OIS::OISKeyboard, true));
    ms = (OIS::Mouse *)(inputMgr->createInputObject(OIS::OISMouse, true));

    //Set movement speed
    mMove = 250;
    mDirection = Ogre::Vector3::ZERO;

    //Bind our inputs to Ogre. This means that we depend on Ogre to keep a high FPS
    bindInput(ms, kb);

    return 1;
}

int inputHandler::bindInput(OIS::Mouse* localMS, OIS::Keyboard* localKB){
    gamesystem.root->addFrameListener(this);
    localKB->setEventCallback(this);
    localMS->setEventCallback(this);
}


bool inputHandler::frameRenderingQueued(const Ogre::FrameEvent &evt){
    bool result = true;
    OIS::Keyboard* keyboard = getActiveKeyboard();
    OIS::Mouse* mouse = getActiveMouse();
    keyboard->capture();
    mouse->capture();

    //Player movement
    gamesystem.sceneCamera->translate(mDirection * evt.timeSinceLastFrame, Ogre::Node::TS_LOCAL);

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

bool inputHandler::mouseMoved(const OIS::MouseEvent &arg){
    gamesystem.sceneCamera->yaw(Ogre::Degree(-mRotate * arg.state.X.rel), Ogre::Node::TS_WORLD);
    gamesystem.sceneCamera->pitch(Ogre::Degree(-mRotate * arg.state.Y.rel), Ogre::Node::TS_LOCAL);
    return true;
}

bool inputHandler::keyPressed(const OIS::KeyEvent &arg){
    switch(arg.key){
        case OIS::KC_ESCAPE:
            gamesystem.quitGame();
            break;
        case OIS::KC_UP:
            mDirection.z = -mMove;
            break;
        case OIS::KC_DOWN:
            mDirection.z = mMove;
            break;
        case OIS::KC_LEFT:
            mDirection.x = -mMove;
            break;
        case OIS::KC_RIGHT:
            mDirection.x = mMove;
            break;
    }
    return true;
}

bool inputHandler::keyReleased(const OIS::KeyEvent &arg){
    switch(arg.key){
        case OIS::KC_UP:
            mDirection.z = 0;
            break;
        case OIS::KC_DOWN:
            mDirection.z = 0;
            break;
        case OIS::KC_LEFT:
            mDirection.x = 0;
            break;
        case OIS::KC_RIGHT:
            mDirection.x = 0;
            break;
    }
    return true;
}
