#include "window.h"

window::window() : mRoot(0), mPluginsCfg(Ogre::StringUtil::BLANK) {
}

window::~window() {
  delete mRoot;
}

bool window::run() {
  mPluginsCfg = "plugins.cfg";

  Ogre::Root* mRoot = new Ogre::Root(mPluginsCfg);
  
  Ogre::RenderSystem* system = mRoot->getRenderSystemByName("OpenGL Rendering Subsystem");
  mRoot->setRenderSystem(system);

  system->setConfigOption("Full Screen", "No");
  system->setConfigOption("Video Mode", "800 x 600 @ 32-bit colour");

  mWindow = mRoot->initialise(true, "Athelia");

  Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

  Ogre::SceneManager* mSceneMgr;

  mSceneMgr = mRoot->createSceneManager("DefaultSceneManager");

  Ogre::Camera* mCamera;

  mCamera = mSceneMgr->createCamera("PlayerCam");

  mCamera->setPosition(Ogre::Vector3(10, 5, 10));

  mCamera->lookAt(Ogre::Vector3(0, 0, 0));

  mCamera->setNearClipDistance(1);

  Ogre::Viewport *vp = mWindow->addViewport(mCamera);

  vp->setBackgroundColour(Ogre::ColourValue(0,0, 0.2));

  mCamera->setAspectRatio(Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));

  mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

  cube cube1 = cube(1.0, 1.0, 0.0, 5.0,  mSceneMgr);

  mSceneMgr->setAmbientLight(Ogre::ColourValue(0.6, 0.6, 0.6));

  Ogre::Light* light_1 = mSceneMgr->createLight("MainLight");

  light_1->setPosition(20, 5, 0);

  while(true) {
    Ogre::WindowEventUtilities::messagePump();
    if(mWindow->isClosed()) {
      return false;
    }

    if(!mRoot->renderOneFrame()) return false;
  }

  return true;
}
