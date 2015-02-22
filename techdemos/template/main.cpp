#include <memory>
#include "OGRE/Ogre.h"

int main() {
	std::unique_ptr<Ogre::Root> root(new Ogre::Root("", "", "LOG_NAME")); //Don't use plugins.cfg, resources.cfg and write the logs to LOG_NAME
	root->loadPlugin("../plugins/RenderSystem_GL");
	
	Ogre::RenderSystem *renderer = root->getRenderSystemByName("OpenGL Rendering Subsystem");
	root->setRenderSystem(renderer); //Set up and choose OpenGL as the renderer
	
	renderer->setConfigOption("Full Screen", "No");
	renderer->setConfigOption("Video Mode", "800 x 600 @ 32-bit colour");
	
	Ogre::RenderWindow *window = root->initialise(true, "TECHDEMO_NAME"); //Create window
	
	Ogre::SceneManager *sceneMgr = root->createSceneManager("DefaultSceneManager"); //Use the default scene manager
	
	Ogre::Camera *camera = sceneMgr->createCamera("Camera");
	
	camera->setPosition(Ogre::Vector3(0, 0, 80));
	camera->lookAt(Ogre::Vector3(0, 0, -300)); //Put the camera at (0, 0, 80), and look back toward (0, 0, -300)
	camera->setNearClipDistance(5);
	
	Ogre::Viewport *view = window->addViewport(camera);
	view->setBackgroundColour(Ogre::ColourValue(0.0, 0.1, 0.9));
	camera->setAspectRatio(view->getActualWidth() / view->getActualHeight()); //Create a viewport with a blue-ish background and give it the aspect ratio of the window
	
	while(!window->isClosed()) {
		Ogre::WindowEventUtilities::messagePump();
		root->renderOneFrame();
	}
	
	return 0;
}
