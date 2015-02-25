#include "debug.h"
#include <fstream>

bool getDebugSetting(){
    std::ifstream file;
    file.open("settings.txt");
    std::string buffer;
    file >> buffer;
    file.close();
    if(buffer == "debug")
        return true;
    else
        return false;
}
