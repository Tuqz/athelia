#include "cube.h"

cube::cube() {
}

cube::cube(Ogre::SceneManager* SceneMgr) {
  plus_xy = Ogre::Plane(Ogre::Vector3::UNIT_Z, 0.5);
  plus_xz = Ogre::Plane(Ogre::Vector3::UNIT_Y, 0.5);
  plus_yz = Ogre::Plane(Ogre::Vector3::UNIT_X, 0.5);

  minus_xy = Ogre::Plane(-Ogre::Vector3::UNIT_Z, 0.5);
  minus_xz = Ogre::Plane(-Ogre::Vector3::UNIT_Y, 0.5);
  minus_yz = Ogre::Plane(-Ogre::Vector3::UNIT_X, 0.5);

  Ogre::MeshManager::getSingleton().createPlane("plus_xy", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plus_xy, 1, 1, 20, 20, true, 1, 1, 1, Ogre::Vector3::UNIT_X);
  Ogre::MeshManager::getSingleton().createPlane("plus_xz", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plus_xz, 1, 1, 20, 20, true, 1, 1, 1, Ogre::Vector3::UNIT_Z);
  Ogre::MeshManager::getSingleton().createPlane("plus_yz", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plus_yz, 1, 1, 20, 20, true, 1, 1, 1, Ogre::Vector3::UNIT_Y);
  Ogre::MeshManager::getSingleton().createPlane("minus_xy", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, minus_xy, 1, 1, 20, 20, true, 1, 1, 1, -Ogre::Vector3::UNIT_X);
  Ogre::MeshManager::getSingleton().createPlane("minus_xz", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, minus_xz, 1, 1, 20, 20, true, 1, 1, 1, -Ogre::Vector3::UNIT_Z);
  Ogre::MeshManager::getSingleton().createPlane("minus_yz", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, minus_yz, 1, 1, 20, 20, true, 1, 1, 1, -Ogre::Vector3::UNIT_Y);

  Ogre::Entity* ent_plus_xy = SceneMgr->createEntity("plus_xy_ent", "plus_xy");
  Ogre::Entity* ent_plus_xz = SceneMgr->createEntity("plus_xz_ent", "plus_xz");
  Ogre::Entity* ent_plus_yz = SceneMgr->createEntity("plus_yz_ent", "plus_yz");
  Ogre::Entity* ent_minus_xy = SceneMgr->createEntity("minus_xy_ent", "minus_xy");
  Ogre::Entity* ent_minus_xz = SceneMgr->createEntity("minus_xz_ent", "minus_xz");
  Ogre::Entity* ent_minus_yz = SceneMgr->createEntity("minus_yz_ent", "minus_yz");


  SceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ent_plus_xy);
  SceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ent_plus_xz);
  SceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ent_plus_yz);
  SceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ent_minus_xy);
  SceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ent_minus_xz);
  SceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ent_minus_yz);

  ent_plus_xy->setCastShadows(true);
  ent_plus_xz->setCastShadows(true);
  ent_plus_yz->setCastShadows(true);
  ent_minus_xy->setCastShadows(true);
  ent_minus_xz->setCastShadows(true);
  ent_minus_yz->setCastShadows(true);
}

cube::cube(double scale, Ogre::SceneManager* SceneMgr) {
  plus_xy = Ogre::Plane(Ogre::Vector3::UNIT_Z, scale/2);
  plus_xz = Ogre::Plane(Ogre::Vector3::UNIT_Y, scale/2);
  plus_yz = Ogre::Plane(Ogre::Vector3::UNIT_X, scale/2);

  minus_xy = Ogre::Plane(-Ogre::Vector3::UNIT_Z, scale/2);
  minus_xz = Ogre::Plane(-Ogre::Vector3::UNIT_Y, scale/2);
  minus_yz = Ogre::Plane(-Ogre::Vector3::UNIT_X, scale/2);

  Ogre::MeshManager::getSingleton().createPlane("plus_xy", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plus_xy, scale, scale, 20, 20, true, 1, 1, 1, Ogre::Vector3::UNIT_X);
  Ogre::MeshManager::getSingleton().createPlane("plus_xz", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plus_xz, scale, scale, 20, 20, true, 1, 1, 1, Ogre::Vector3::UNIT_Z);
  Ogre::MeshManager::getSingleton().createPlane("plus_yz", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plus_yz, scale, scale, 20, 20, true, 1, 1, 1, Ogre::Vector3::UNIT_Y);
  Ogre::MeshManager::getSingleton().createPlane("minus_xy", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, minus_xy, scale, scale, 20, 20, true, 1, 1, 1, -Ogre::Vector3::UNIT_X);
  Ogre::MeshManager::getSingleton().createPlane("minus_xz", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, minus_xz, scale, scale, 20, 20, true, 1, 1, 1, -Ogre::Vector3::UNIT_Z);
  Ogre::MeshManager::getSingleton().createPlane("minus_yz", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, minus_yz, scale, scale, 20, 20, true, 1, 1, 1, -Ogre::Vector3::UNIT_Y);

  Ogre::Entity* ent_plus_xy = SceneMgr->createEntity("plus_xy_ent", "plus_xy");
  Ogre::Entity* ent_plus_xz = SceneMgr->createEntity("plus_xz_ent", "plus_xz");
  Ogre::Entity* ent_plus_yz = SceneMgr->createEntity("plus_yz_ent", "plus_yz");
  Ogre::Entity* ent_minus_xy = SceneMgr->createEntity("minus_xy_ent", "minus_xy");
  Ogre::Entity* ent_minus_xz = SceneMgr->createEntity("minus_xz_ent", "minus_xz");
  Ogre::Entity* ent_minus_yz = SceneMgr->createEntity("minus_yz_ent", "minus_yz");


  SceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ent_plus_xy);
  SceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ent_plus_xz);
  SceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ent_plus_yz);
  SceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ent_minus_xy);
  SceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ent_minus_xz);
  SceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ent_minus_yz);

  ent_plus_xy->setCastShadows(true);
  ent_plus_xz->setCastShadows(true);
  ent_plus_yz->setCastShadows(true);
  ent_minus_xy->setCastShadows(true);
  ent_minus_xz->setCastShadows(true);
  ent_minus_yz->setCastShadows(true);
}

cube::cube(double x_centre, double y_centre, double z_centre, Ogre::SceneManager* SceneMgr) {
  plus_xy = Ogre::Plane(Ogre::Vector3::UNIT_Z, 0.5);
  plus_xz = Ogre::Plane(Ogre::Vector3::UNIT_Y, 0.5);
  plus_yz = Ogre::Plane(Ogre::Vector3::UNIT_X, 0.5);

  minus_xy = Ogre::Plane(-Ogre::Vector3::UNIT_Z, 0.5);
  minus_xz = Ogre::Plane(-Ogre::Vector3::UNIT_Y, 0.5);
  minus_yz = Ogre::Plane(-Ogre::Vector3::UNIT_X, 0.5);

  Ogre::MeshManager::getSingleton().createPlane("plus_xy", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plus_xy, 1, 1, 20, 20, true, 1, 1, 1, Ogre::Vector3::UNIT_X);
  Ogre::MeshManager::getSingleton().createPlane("plus_xz", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plus_xz, 1, 1, 20, 20, true, 1, 1, 1, Ogre::Vector3::UNIT_Z);
  Ogre::MeshManager::getSingleton().createPlane("plus_yz", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plus_yz, 1, 1, 20, 20, true, 1, 1, 1, Ogre::Vector3::UNIT_Y);
  Ogre::MeshManager::getSingleton().createPlane("minus_xy", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, minus_xy, 1, 1, 20, 20, true, 1, 1, 1, -Ogre::Vector3::UNIT_X);
  Ogre::MeshManager::getSingleton().createPlane("minus_xz", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, minus_xz, 1, 1, 20, 20, true, 1, 1, 1, -Ogre::Vector3::UNIT_Z);
  Ogre::MeshManager::getSingleton().createPlane("minus_yz", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, minus_yz, 1, 1, 20, 20, true, 1, 1, 1, -Ogre::Vector3::UNIT_Y);

  Ogre::Entity* ent_plus_xy = SceneMgr->createEntity("plus_xy_ent", "plus_xy");
  Ogre::Entity* ent_plus_xz = SceneMgr->createEntity("plus_xz_ent", "plus_xz");
  Ogre::Entity* ent_plus_yz = SceneMgr->createEntity("plus_yz_ent", "plus_yz");
  Ogre::Entity* ent_minus_xy = SceneMgr->createEntity("minus_xy_ent", "minus_xy");
  Ogre::Entity* ent_minus_xz = SceneMgr->createEntity("minus_xz_ent", "minus_xz");
  Ogre::Entity* ent_minus_yz = SceneMgr->createEntity("minus_yz_ent", "minus_yz");


  Ogre::SceneNode* xy_plus = SceneMgr->getRootSceneNode()->createChildSceneNode();
  xy_plus->attachObject(ent_plus_xy);
  Ogre::SceneNode* xz_plus = SceneMgr->getRootSceneNode()->createChildSceneNode();
  xz_plus->attachObject(ent_plus_xz);
  Ogre::SceneNode* yz_plus = SceneMgr->getRootSceneNode()->createChildSceneNode();
  yz_plus->attachObject(ent_plus_yz);
  Ogre::SceneNode* xy_minus = SceneMgr->getRootSceneNode()->createChildSceneNode();
  xy_minus->attachObject(ent_minus_xy);
  Ogre::SceneNode* xz_minus = SceneMgr->getRootSceneNode()->createChildSceneNode();
  xz_minus->attachObject(ent_minus_xz);
  Ogre::SceneNode* yz_minus = SceneMgr->getRootSceneNode()->createChildSceneNode();
  yz_minus->attachObject(ent_minus_yz);

  xy_plus->translate(Ogre::Vector3(x_centre, y_centre, z_centre));
  xz_plus->translate(Ogre::Vector3(x_centre, y_centre, z_centre));
  yz_plus->translate(Ogre::Vector3(x_centre, y_centre, z_centre));
  xy_minus->translate(Ogre::Vector3(x_centre, y_centre, z_centre));
  xz_minus->translate(Ogre::Vector3(x_centre, y_centre, z_centre));
  yz_minus->translate(Ogre::Vector3(x_centre, y_centre, z_centre));

  ent_plus_xy->setCastShadows(true);
  ent_plus_xz->setCastShadows(true);
  ent_plus_yz->setCastShadows(true);
  ent_minus_xy->setCastShadows(true);
  ent_minus_xz->setCastShadows(true);
  ent_minus_yz->setCastShadows(true);
}

cube::cube(double x_centre, double y_centre, double z_centre, double scale, Ogre::SceneManager* SceneMgr) {
  plus_xy = Ogre::Plane(Ogre::Vector3::UNIT_Z, scale/2);
  plus_xz = Ogre::Plane(Ogre::Vector3::UNIT_Y, scale/2);
  plus_yz = Ogre::Plane(Ogre::Vector3::UNIT_X, scale/2);

  minus_xy = Ogre::Plane(-Ogre::Vector3::UNIT_Z, scale/2);
  minus_xz = Ogre::Plane(-Ogre::Vector3::UNIT_Y, scale/2);
  minus_yz = Ogre::Plane(-Ogre::Vector3::UNIT_X, scale/2);

  Ogre::MeshManager::getSingleton().createPlane("plus_xy", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plus_xy, scale, scale, 20, 20, true, 1, 1, 1, Ogre::Vector3::UNIT_X);
  Ogre::MeshManager::getSingleton().createPlane("plus_xz", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plus_xz, scale, scale, 20, 20, true, 1, 1, 1, Ogre::Vector3::UNIT_Z);
  Ogre::MeshManager::getSingleton().createPlane("plus_yz", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plus_yz, scale, scale, 20, 20, true, 1, 1, 1, Ogre::Vector3::UNIT_Y);
  Ogre::MeshManager::getSingleton().createPlane("minus_xy", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, minus_xy, scale, scale, 20, 20, true, 1, 1, 1, -Ogre::Vector3::UNIT_X);
  Ogre::MeshManager::getSingleton().createPlane("minus_xz", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, minus_xz, scale, scale, 20, 20, true, 1, 1, 1, -Ogre::Vector3::UNIT_Z);
  Ogre::MeshManager::getSingleton().createPlane("minus_yz", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, minus_yz, scale, scale, 20, 20, true, 1, 1, 1, -Ogre::Vector3::UNIT_Y);

  Ogre::Entity* ent_plus_xy = SceneMgr->createEntity("plus_xy_ent", "plus_xy");
  Ogre::Entity* ent_plus_xz = SceneMgr->createEntity("plus_xz_ent", "plus_xz");
  Ogre::Entity* ent_plus_yz = SceneMgr->createEntity("plus_yz_ent", "plus_yz");
  Ogre::Entity* ent_minus_xy = SceneMgr->createEntity("minus_xy_ent", "minus_xy");
  Ogre::Entity* ent_minus_xz = SceneMgr->createEntity("minus_xz_ent", "minus_xz");
  Ogre::Entity* ent_minus_yz = SceneMgr->createEntity("minus_yz_ent", "minus_yz");


  Ogre::SceneNode* xy_plus = SceneMgr->getRootSceneNode()->createChildSceneNode();
  xy_plus->attachObject(ent_plus_xy);
  Ogre::SceneNode* xz_plus = SceneMgr->getRootSceneNode()->createChildSceneNode();
  xz_plus->attachObject(ent_plus_xz);
  Ogre::SceneNode* yz_plus = SceneMgr->getRootSceneNode()->createChildSceneNode();
  yz_plus->attachObject(ent_plus_yz);
  Ogre::SceneNode* xy_minus = SceneMgr->getRootSceneNode()->createChildSceneNode();
  xy_minus->attachObject(ent_minus_xy);
  Ogre::SceneNode* xz_minus = SceneMgr->getRootSceneNode()->createChildSceneNode();
  xz_minus->attachObject(ent_minus_xz);
  Ogre::SceneNode* yz_minus = SceneMgr->getRootSceneNode()->createChildSceneNode();
  yz_minus->attachObject(ent_minus_yz);

  xy_plus->translate(Ogre::Vector3(x_centre, y_centre, z_centre));
  xz_plus->translate(Ogre::Vector3(x_centre, y_centre, z_centre));
  yz_plus->translate(Ogre::Vector3(x_centre, y_centre, z_centre));
  xy_minus->translate(Ogre::Vector3(x_centre, y_centre, z_centre));
  xz_minus->translate(Ogre::Vector3(x_centre, y_centre, z_centre));
  yz_minus->translate(Ogre::Vector3(x_centre, y_centre, z_centre));

  ent_plus_xy->setCastShadows(true);
  ent_plus_xz->setCastShadows(true);
  ent_plus_yz->setCastShadows(true);
  ent_minus_xy->setCastShadows(true);
  ent_minus_xz->setCastShadows(true);
  ent_minus_yz->setCastShadows(true);
}

cube::~cube() {
}
