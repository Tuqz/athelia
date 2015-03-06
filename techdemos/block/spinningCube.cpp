#include <inputManager.h>
#include "spinningCube.h"

bool SpinningCube::frameRenderingQueued(const Ogre::FrameEvent &evt) {
	if(inputManager::getInstance()->getState("RotRight")) {
		node->yaw(Ogre::Radian(0.01));
	}
	
	if(inputManager::getInstance()->getState("RotLeft")) {
		node->yaw(Ogre::Radian(-0.01));
	}
	return true;
}
