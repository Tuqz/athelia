#include "window.h"

#include <iostream>
#include <OGRE/OgreException.h>

int main(int argc, char* argv[]) {
  window app;

  try {
    app.run();
  } catch(Ogre::Exception& e) {
    std::cerr<<"An error has happened: "<<e.getFullDescription().c_str() <<std::endl;
  }
  return 0;
}
