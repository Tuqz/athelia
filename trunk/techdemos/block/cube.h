#include <block.h>
#include "OGRE/OgreSceneManager.h"
#include "OGRE/OgreVector3.h"
#include "OGRE/OgreMaterial.h"
#include "OGRE/OgreString.h"

#pragma once

class Cube : public Block {
public:
	Cube(Ogre::SceneManager *sceneMgr, Ogre::MaterialPtr material);
	Cube(Ogre::Vector3 &pos, Ogre::SceneManager *sceneMgr, Ogre::MaterialPtr material);
	
	void detach(Ogre::SceneManager *sceneMgr); //gets rid of the cube from the scene.
	
	void yaw(double angle); //yaw angle radians
	
	~Cube();
};
