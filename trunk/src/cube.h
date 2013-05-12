#include "OGRE/OgrePlane.h"
#include "OGRE/OgreMeshManager.h"
#include "OGRE/OgreEntity.h"
#include "OGRE/OgreSceneManager.h"

class cube {
 public:
  cube();
  cube(Ogre::SceneManager* SceneMgr);
  cube(double scale, Ogre::SceneManager* SceneMgr);
  cube(double x_centre, double y_centre, double z_centre, Ogre::SceneManager* SceneMgr);
  cube(double x_centre, double y_centre, double z_centre, double scale, Ogre::SceneManager* SceneMgr);
  void texture(Ogre::SceneManager* SceneMgr, Ogre::String path_to_texture);
  ~cube();
 private:
  Ogre::Plane plus_xy;
  Ogre::Plane plus_xz;
  Ogre::Plane plus_yz;
  Ogre::Plane minus_xy;
  Ogre::Plane minus_xz;
  Ogre::Plane minus_yz;
};
