#ifndef GAMESYSTEM_H_INCLUDED
#define GAMESYSTEM_H_INCLUDED

class GameSystem{
public:
    int quitGame();
    std::unique_ptr<Ogre::Root> root; //This should be private with some level of control over what accesses it
    Ogre::SceneNode* sceneCamera;
private:
    bool shuttingDown = false;
}; extern GameSystem gamesystem;

#endif // GAMESYSTEM_H_INCLUDED
