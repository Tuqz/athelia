#ifndef GAMESYSTEM_H_INCLUDED
#define GAMESYSTEM_H_INCLUDED

/*!
    * \brief    "GameSystem" handles the base of Ogre3D, including Ogre::Root. It also handles utility functions such as shutting down the game.
    * \author   Jacob843
    * \author   Tuqz
    * \version  0.0.1a
*/

class GameSystem{
public:
    int quitGame();
    std::unique_ptr<Ogre::Root> root; //This should be private with some level of control over what accesses it
    Ogre::SceneNode* sceneCamera;
private:
    bool shuttingDown = false;
}; extern GameSystem gamesystem;

#endif // GAMESYSTEM_H_INCLUDED
