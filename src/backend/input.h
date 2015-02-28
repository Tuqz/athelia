#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "OIS/OISMouse.h"
#include "OIS/OISKeyboard.h"
#include "OIS/OISInputManager.h"

/*!
    * \brief    The "inputHandler" class manages user input from devices such as mice and keyboards.
    * \author   Jacob843
    * \author   Tuqz
    * \version  0.0.1a
*/

class inputHandler : public Ogre::FrameListener, public OIS::MouseListener, public OIS::KeyListener {
public:
    int setupInputs();

    //Handle inputs
    int handleKeyboard(const Ogre::FrameEvent &evt);
    int handleMouse(const OIS::MouseEvent &evt);

    //Override Ogre frameRenderingQueued
    int bindInput(OIS::Mouse* localMS, OIS::Keyboard* localKB);
    bool frameRenderingQueued(const Ogre::FrameEvent &evt);

    //Utilities
    OIS::Mouse* getActiveMouse();
    OIS::Keyboard* getActiveKeyboard();
    OIS::InputManager* getInputManager();
private:
    OIS::InputManager *inputMgr;
    OIS::Keyboard* kb;
    OIS::Mouse* ms;

    bool mouseMoved( const OIS::MouseEvent &arg ){}
    bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id ){}
    bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id ){}

    bool keyPressed(const OIS::KeyEvent &arg);
    bool keyReleased(const OIS::KeyEvent &arg);
}; extern inputHandler input;

#endif // INPUT_H_INCLUDED
