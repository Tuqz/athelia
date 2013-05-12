#ifndef WINDOW_H
#define WINDOW_H

#include "OGRE/OgreRoot.h"
#include "OGRE/OgreCamera.h"
#include "OGRE/OgreViewport.h"
#include "OGRE/OgreSceneManager.h"
#include "OGRE/OgreRenderWindow.h"
#include "OGRE/OgreWindowEventUtilities.h"

#include "cube.h"

class window {
 public:
  window();
  virtual ~window();
  bool run();
  Ogre::RenderWindow* mWindow;
 private:
  Ogre::Root* mRoot;
  Ogre::String mPluginsCfg;
};

#endif
