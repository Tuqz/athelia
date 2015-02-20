#include "cube.h"
#include "OGRE/OgreVector3.h"
#include "OGRE/OgreSceneManager.h"
#include "OGRE/OgreMaterial.h"

Cube::Cube(Ogre::SceneManager *sceneMgr, Ogre::MaterialPtr material) : Block(Ogre::Vector3(0, 0, 0)) {
	setId();
	dim = 1;
	ent = sceneMgr->createEntity("Block" + std::to_string(id), Ogre::SceneManager::PT_CUBE);
	node = sceneMgr->getRootSceneNode()->createChildSceneNode();
	node->attachObject(ent);
	ent->setMaterial(material);
	node->setScale(Ogre::Vector3(0.3, 0.3, 0.3));
	node->setPosition(Ogre::Vector3(0, 0, 0));
}

Cube::Cube(Ogre::Vector3 &position, Ogre::SceneManager *sceneMgr, Ogre::MaterialPtr material) : Block(position) {
	setId();
	dim = 1;
	ent = sceneMgr->createEntity("Block" + std::to_string(id), Ogre::SceneManager::PT_CUBE);
	node = sceneMgr->getRootSceneNode()->createChildSceneNode();
	node->attachObject(ent);
	ent->setMaterial(material);
	node->setPosition(position);
	node->setScale(Ogre::Vector3(0.3, 0.3, 0.3));
}

void Cube::detach(Ogre::SceneManager *sceneMgr) {
	node->detachObject(ent);
	sceneMgr->destroyEntity(ent);
	sceneMgr->destroySceneNode(node);
}

void Cube::yaw(double angle) {
	node->yaw(Ogre::Radian(angle));
}

Cube::~Cube() {
	Block::unused.push_back(id);
}
