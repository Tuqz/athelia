#include "lua.h"

namespace Lua {
	LuaInterface::LuaInterface() {
		state = luaL_newstate();
		libs.push_back({"base", luaopen_base}); //Load all base libraries
		loadlibs();
	}

	LuaInterface::LuaInterface(std::vector<luaL_Reg> libraries) {
		state = luaL_newstate();
		libs = libraries;
		loadlibs();
	}

	LuaInterface::~LuaInterface() {
		lua_close(state);
	}

	std::string LuaInterface::run_file(std::string filename) {
		bool result = luaL_dofile(state, filename.c_str());
		if(result) {
			return lua_tostring(state, -1);
		} else {
			return "";
		}
	}

	void LuaInterface::loadlibs() {
		for(int i = 0; i < libs.size(); ++i) {
			libs[i].func(state);
			lua_settop(state, 0);
		}
	}
}
