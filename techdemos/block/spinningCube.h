#include <cube.h>

#pragma once

class SpinningCube : public Cube {
	bool frameRenderingQueued(const Ogre::FrameEvent &evt);
};
