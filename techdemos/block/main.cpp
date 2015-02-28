#include <iostream>
#include <string>

#include "patch.h"
#include "debug.h"
#include "graphics.h"
#include "input.h"

inputHandler inputMgr;

int main() {
    std::string cRenderSystem;

    if(getDebugSetting() == true){
        cRenderSystem = "../../plugins/RenderSystem_GL_d";
    } else {
        cRenderSystem = "../../plugins/RenderSystem_GL";
    }
    graphics.initGraphics(cRenderSystem, "Athelia", false);

    Ogre::SceneManager *sceneMgr = graphics.getActiveSceneManager();
    Ogre::RenderWindow *window = graphics.getCurrentWindow();

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

	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create("Green", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	material->getTechnique(0)->getPass(0)->setLightingEnabled(true);
	material->getTechnique(0)->getPass(0)->setDiffuse(0.0, 1.0, 0.0, 1.0);
	material->load();

	std::unique_ptr<Cube> cube(new Cube());
	cube->addToScene(sceneMgr, 40);
	cube->setMaterial(material);

	Ogre::Light *light = sceneMgr->createLight("Light1");
	light->setPosition(50, 50, 50);

    inputMgr.setupInputs();

	gamesystem.root->startRendering();

	return 0;
}
