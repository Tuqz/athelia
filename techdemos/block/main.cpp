#include <iostream>
#include <string>

#include "patch.h"
#include "debug.h"
#include "graphics.h"
#include "input.h"

namespace boost{
    void throw_exception(std::exception const &e){
    }
}

Ogre::Vector3 moveNode(Ogre::Vector3 pos, float x, float y, float z);

class Controller : public Ogre::FrameListener {
private:
	std::vector<std::function<bool(OIS::KeyCode)>> callbacks; //Callbacks return true, unless the program needs to stop, when they return false
	std::set<OIS::KeyCode> codes;
	OIS::Keyboard *keyboard;
	OIS::Mouse *mouse;

	Ogre::Real mRotate = 0.13;
public:
	Controller(OIS::Keyboard *kb, OIS::Mouse *ms) : keyboard(kb), mouse(ms) {}

    bool mouseMoved(const OIS::MouseEvent &evt){
        //mouse stuff
        gamesystem.sceneCamera->yaw(Ogre::Degree(-mRotate * evt.state.X.rel), Ogre::Node::TS_WORLD);
        gamesystem.sceneCamera->pitch(Ogre::Degree(-mRotate * evt.state.Y.rel), Ogre::Node::TS_LOCAL);
        return true;
    }

	bool frameRenderingQueued(const Ogre::FrameEvent &evt) { //This means that input is dependent on graphics
		bool result = true;
        keyboard->capture();
        if(keyboard->isKeyDown(OIS::KC_ESCAPE))
            gamesystem.quitGame();
        if(keyboard->isKeyDown(OIS::KC_UP)){
            gamesystem.sceneCamera->translate(0, 0, -.25);
        }
        if(keyboard->isKeyDown(OIS::KC_DOWN)){
            gamesystem.sceneCamera->translate(0, 0, .25);
        }
        if(keyboard->isKeyDown(OIS::KC_LEFT)){
            gamesystem.sceneCamera->translate(-.25, 0, 0);
        }
        if(keyboard->isKeyDown(OIS::KC_RIGHT)){
            gamesystem.sceneCamera->translate(.25, 0, 0);
        }
		return result;
	}
};

int main() {
    std::string cRenderSystem;
    if(getDebugSetting() == true){
        cRenderSystem = "../../plugins/RenderSystem_GL_d";
    } else {
        cRenderSystem = "../../plugins/RenderSystem_GL";
    }
    graphics.initGraphics(cRenderSystem, "Athelia", false);
/*
    gamesystem.sceneCamera = sceneMgr->createSceneNode("sceneCamera");

    //Check if bad node

    if(gamesystem.sceneCamera == NULL)
        return 1;

    Ogre::Camera *camera = sceneMgr->createCamera("Camera");

	camera->setPosition(Ogre::Vector3(0, 0, 80));
	camera->lookAt(Ogre::Vector3(0, 0, -300)); //Put the camera at (0, 0, 80), and look back toward (0, 0, -300)
	camera->setNearClipDistance(5);

	Ogre::Viewport *view = window->addViewport(camera);
	view->setBackgroundColour(Ogre::ColourValue(0.0, 0.1, 0.9));
	camera->setAspectRatio(view->getActualWidth() / view->getActualHeight()); //Create a viewport with a blue-ish background and give it the aspect ratio of the window

    //Add camera to sceneCamera node
    gamesystem.sceneCamera->attachObject(camera);

	OIS::ParamList list;
	size_t windowHandle = 0;
	window->getCustomAttribute("WINDOW", &windowHandle);
	list.insert(std::make_pair("WINDOW", patch::to_string(windowHandle)));
	OIS::InputManager *inputMgr = OIS::InputManager::createInputSystem(list);
	OIS::Keyboard* keyboard = (OIS::Keyboard *)(inputMgr->createInputObject(OIS::OISKeyboard, false));

	Controller controller(keyboard, mouse);

	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create("Green", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	material->getTechnique(0)->getPass(0)->setLightingEnabled(true);
	material->getTechnique(0)->getPass(0)->setDiffuse(0.0, 1.0, 0.0, 1.0);
	material->load();

	std::unique_ptr<Cube> cube(new Cube());
	cube->addToScene(sceneMgr, 40);
	cube->setMaterial(material);

	Ogre::Light *light = sceneMgr->createLight("Light1");
	light->setPosition(50, 50, 50);

    gamesystem.root->addFrameListener(&controller);

	gamesystem.root->startRendering();
*/
	return 0;
}
