#include <memory>
#include "OGRE/Ogre.h"
#include "OIS/OISMouse.h"
#include "OIS/OISKeyboard.h"
#include "OIS/OISInputManager.h"
#include <inputManager.h>
#include "spinningCube.h"

class FrameListener : public Ogre::FrameListener {
public:
	bool frameRenderingQueued(const Ogre::FrameEvent& evt) {
		return !inputManager::getInstance()->getState("Quit");
	}
};

int main() {
	std::unique_ptr<Ogre::Root> root(new Ogre::Root("", "", "cube.log")); //Don't use plugins.cfg, resources.cfg and write the logs to cube.log
	root->loadPlugin("../plugins/RenderSystem_GL");
	Ogre::RenderSystem *renderer = root->getRenderSystemByName("OpenGL Rendering Subsystem");
	root->setRenderSystem(renderer); //Set up and choose OpenGL as the renderer
	
	renderer->setConfigOption("Full Screen", "No");
	renderer->setConfigOption("Video Mode", "800 x 600 @ 32-bit colour");
	
	Ogre::RenderWindow *window = root->initialise(true, "Cube Demonstration"); //Create window
	
	Ogre::SceneManager *sceneMgr = root->createSceneManager("DefaultSceneManager"); //Use the default scene manager
	
	Ogre::Camera *camera = sceneMgr->createCamera("Camera");
	
	camera->setPosition(Ogre::Vector3(0, 0, 80));
	camera->lookAt(Ogre::Vector3(0, 0, -300)); //Put the camera at (0, 0, 80), and look back toward (0, 0, -300)
	camera->setNearClipDistance(5);
	
	Ogre::Viewport *view = window->addViewport(camera);
	view->setBackgroundColour(Ogre::ColourValue(0.0, 0.1, 0.9));
	camera->setAspectRatio(view->getActualWidth() / view->getActualHeight()); //Create a viewport with a blue-ish background and give it the aspect ratio of the window
	
	OIS::ParamList list;
	size_t windowHandle = 0;
	window->getCustomAttribute("WINDOW", &windowHandle);
	list.insert(std::make_pair("WINDOW", std::to_string(windowHandle)));
	OIS::InputManager *inputMgr = OIS::InputManager::createInputSystem(list);
	OIS::Keyboard* keyboard = (OIS::Keyboard *)(inputMgr->createInputObject(OIS::OISKeyboard, true));
	keyboard->setEventCallback(inputManager::getInstance());
	inputManager::getInstance()->addCommand("Quit", 1);
	inputManager::getInstance()->addCommand("RotRight", 0x12);
	inputManager::getInstance()->addCommand("RotLeft", 0x10);
	inputManager::getInstance()->keyboard = keyboard;
	FrameListener listener;
	
	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create("Green", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	material->getTechnique(0)->getPass(0)->setLightingEnabled(true);
	material->getTechnique(0)->getPass(0)->setDiffuse(0.0, 1.0, 0.0, 1.0);
	material->load();
	
	std::unique_ptr<SpinningCube> cube(new SpinningCube());
	cube->addToScene(sceneMgr, 40);
	cube->setMaterial(material);
	
	Ogre::Light *light = sceneMgr->createLight("Light1");
	light->setPosition(50, 50, 50);
	
	root->addFrameListener(&listener);
	root->addFrameListener(cube.get());
	
	root->startRendering();
	
	return 0;
}
