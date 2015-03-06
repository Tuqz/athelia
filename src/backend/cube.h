#include "block.h"
#include "OGRE/OgreSceneManager.h"
#include "OGRE/OgreVector3.h"
#include "OGRE/OgreMaterial.h"
#include "OGRE/OgreString.h"
#include "OGRE/OgreSceneNode.h"

#pragma once

class Cube : public Block {
public:
	double dimensions;
	Cube();
	Cube(Ogre::Vector3 &pos);
	void addToScene(Ogre::SceneManager *sceneMgr, double scale);
	void removeFromScene(Ogre::SceneManager *sceneMgr);
	void setMaterial(Ogre::MaterialPtr material);
	//virtual bool frameRenderingQueued(const Ogre::FrameEvent &evt);
};
