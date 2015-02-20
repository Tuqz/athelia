#include "OGRE/OgreVector3.h"
#include "OGRE/OgreEntity.h"
#include <vector>

#pragma once

class Block {
protected:
	Ogre::Entity *ent;
	Ogre::SceneNode *node;
	int id;
	static std::vector<int> unused;
	void setId();
public:
	const Ogre::Vector3 pos;
	double dim;
	Block(const Ogre::Vector3 &position);
};
