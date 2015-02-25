#include <cube.h>
#include <memory>
#include "patch.h"
#include "OGRE/Ogre.h"
#include "OIS/OISMouse.h"
#include "OIS/OISKeyboard.h"
#include "OIS/OISInputManager.h"
#include <iostream>

namespace boost{
    void throw_exception(std::exception const &e){
    }
}

class Controller : public Ogre::FrameListener {
private:
	std::vector<std::function<bool(OIS::KeyCode)>> callbacks; //Callbacks return true, unless the program needs to stop, when they return false
	std::set<OIS::KeyCode> codes;
	OIS::Keyboard *keyboard;
public:
	Controller(OIS::Keyboard *kb) : keyboard(kb) {}
	void addCallback(std::function<bool(OIS::KeyCode)> callback) {
		callbacks.push_back(callback);
	}

	void addKey(OIS::KeyCode code) {
		codes.insert(code);
	}

	bool frameRenderingQueued(const Ogre::FrameEvent &evt) {
		bool result = true;
		for(auto it = codes.begin(); it != codes.end(); ++it) {
			if(keyboard->isKeyDown(*it)) {
				std::cout<<*it<<std::endl;
				for(auto f_it = callbacks.begin(); f_it != callbacks.end(); ++f_it) {
					result = result && (*f_it)(*it);
				}
			}
		}
		return result;
	}
};

int main() {
	std::unique_ptr<Ogre::Root> root(new Ogre::Root("", "", "cube.log")); //Don't use plugins.cfg, resources.cfg and write the logs to cube.log
	root->loadPlugin("../../plugins/RenderSystem_GL");
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
	list.insert(std::make_pair("WINDOW", patch::to_string(windowHandle)));
	OIS::InputManager *inputMgr = OIS::InputManager::createInputSystem(list);
	OIS::Keyboard* keyboard = (OIS::Keyboard *)(inputMgr->createInputObject(OIS::OISKeyboard, false));

	Controller controller(keyboard);
	controller.addCallback([] (OIS::KeyCode code) {
		return (code != OIS::KC_ESCAPE);
	});
	controller.addKey(OIS::KC_ESCAPE);

	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create("Green", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	material->getTechnique(0)->getPass(0)->setLightingEnabled(true);
	material->getTechnique(0)->getPass(0)->setDiffuse(0.0, 1.0, 0.0, 1.0);
	material->load();

	std::unique_ptr<Cube> cube(new Cube());
	cube->addToScene(sceneMgr, 40);
	cube->setMaterial(material);

	Ogre::Light *light = sceneMgr->createLight("Light1");
	light->setPosition(50, 50, 50);

	root->addFrameListener(&controller);

	root->startRendering();

	return 0;
}
