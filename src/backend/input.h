#ifndef input
#define input

#include "OIS/OISMouse.h"
#include "OIS/OISKeyboard.h"
#include "OIS/OISInputManager.h"

class inputHandler : public Ogre::FrameListener, public OIS::MouseListener, public OIS::KeyListener {
public:
    int setupInputs(OIS::Mouse *mouse, OIS::Keyboard *keyboard);

    OIS::Mouse* getActiveMouse();
    OIS::Keyboard* getActiveKeyboard();
private:
    OIS::Keyboard* kb;
    OIS::Mouse* ms;
};

#endif // input
