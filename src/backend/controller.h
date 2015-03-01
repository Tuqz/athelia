#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

/*!
    * \brief    Deprecated
    * \author   Jacob843
    * \author   Tuqz
    * \version  DEP
*/


class Controller : public Ogre::FrameListener {
public:
	Controller(OIS::Keyboard *kb, OIS::Mouse *ms) : keyboard(kb), mouse(ms) {}

    bool mouseMoved(const OIS::MouseEvent &evt){
        //mouse stuff
        gamesystem.sceneCamera->yaw(Ogre::Degree(-mRotate * evt.state.X.rel), Ogre::Node::TS_WORLD);
        gamesystem.sceneCamera->pitch(Ogre::Degree(-mRotate * evt.state.Y.rel), Ogre::Node::TS_LOCAL);
        return true;
    }

private:
	OIS::Keyboard *keyboard;
	OIS::Mouse *mouse;

	Ogre::Real mRotate = 0.13;

};

#endif // CONTROLLER_H_INCLUDED
