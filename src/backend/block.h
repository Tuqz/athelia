#include "OGRE/OgreVector3.h"
#include "OGRE/OgreEntity.h"
#include "OGRE/OgreSceneManager.h"
#include "OGRE/OgreMaterial.h"
#include <vector>

#pragma once

/*!
    * \brief    The "Block" class is one of several types of in-game objects. Blocks exist as terrain and other figures. This class controls those blocks.
    * \author   Jacob843
    * \author   Tuqz
    * \version  0.0.1a
*/

class Block {
protected:
	Ogre::Entity *ent;
	Ogre::SceneNode *node;
	int id;
	static std::vector<int> unused;
	void setId();
public:
	const Ogre::Vector3 pos;
	Block(const Ogre::Vector3 &position);
	void addToScene(Ogre::SceneManager *sceneMgr, double scale);
	void removeFromScene(Ogre::SceneManager *sceneMgr);
	void setMaterial(Ogre::MaterialPtr material);
};
