#include "cube.h"
#include "OGRE/OgreVector3.h"
#include "OGRE/OgreSceneManager.h"
#include "OGRE/OgreMaterial.h"

Cube::Cube() : Block(Ogre::Vector3(0, 0, 0)) {
}

Cube::Cube(Ogre::Vector3 &position) : Block(position) {
}

void Cube::addToScene(Ogre::SceneManager *sceneMgr, double scale) { //scale is in OGRE units
	setId();
	dimensions = scale;
	ent = sceneMgr->createEntity("Block" + std::to_string(id), Ogre::SceneManager::PT_CUBE);
	node = sceneMgr->getRootSceneNode()->createChildSceneNode();
	node->attachObject(ent);
	node->setScale(Ogre::Vector3(scale/100.0, scale/100.0, scale/100.0)); //The default cube is 100 OGRE units
	node->setPosition(pos);
}

void Cube::removeFromScene(Ogre::SceneManager *sceneMgr) {
	node->detachObject(ent);
	sceneMgr->destroyEntity(ent);
	sceneMgr->destroySceneNode(node);
	Block::unused.push_back(id);
}

void Cube::setMaterial(Ogre::MaterialPtr material) {
	ent->setMaterial(material);
}
