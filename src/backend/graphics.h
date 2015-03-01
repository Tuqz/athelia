#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <memory>

#include "OGRE/Ogre.h"
#include "cube.h"
#include "gamesystem.h"

/*!
    * \brief    The "graphicsHandler" class handles anything related to graphics.
    * \details  Ogre3D is currently our graphics engine. In this class, functions exist to initialize the engine, check on variables, or control the movement of nodes.
    * \author   Jacob843
    * \author   Tuqz
    * \version  0.0.1a
*/

class graphicsHandler{
public:
    //Initializations and creations
    /** \brief Initializes Ogre graphics
     *
     * \param   std::string renderSystem
     * \param
     * \return
     *
     */
    int initGraphics(std::string renderSystem, std::string windowTitle, bool fullScreen = false, std::string videoMode = "800 x 600 @ 32-bit colour", std::string pluginsFile = "", std::string resourcesFile = "", std::string logFile = "debug.log");

    Ogre::SceneManager* createSceneManager(std::string managerName="DefaultSceneManager");

    //Utility
    //Check private variables. May be used later for debugging

    /** \brief  Checks if current render window is null.
     *
     * \returns -1 on a null render window
     *
     */
    int checkRenderWindow();

    /** \brief Checks if the current scene manager is null.
     *
     * \returns -1 on a null scene manager
     *
     */
    int checkSceneManager();

    //Get defaults related to graphics

    /** \brief Grabs the current Ogre SceneManager in use by the game
     *
     * \return  Ogre::SceneManager*
     *
     */
    Ogre::SceneManager* getActiveSceneManager();

    /** \brief Grabs the current Ogre RenderWindow used by the game
     *
     * \return Ogre::RenderWindow*
     *
     */
    Ogre::RenderWindow* getCurrentWindow();

    //Movement of Ogre Elements
    Ogre::Vector3 translateNode(Ogre::Vector3 pos, float x, float y, float z);
private:
    Ogre::RenderSystem *renderer;
    Ogre::RenderWindow *window;
    Ogre::SceneManager *sceneMgr;
}; extern graphicsHandler graphics;

#endif // GRAPHICS_H_INCLUDED
