#include "luaState.h"

namespace Lua {
	LuaState::LuaState() {
		state = luaL_newstate();
	}
	
	int LuaState::runFile(std::string filename) {
		int status = luaL_loadfile(state, filename.c_str());
		if(status) {
			return status;
		}
		int result = lua_pcall(state, 0, LUA_MULTRET, 0);
		return result;
	}
	
	void LuaState::loadLibrary(Library library) {
		switch(library) {
			case BASE:
				luaL_requiref(state, "base", luaopen_base, 1);
			break;
			case IO:
				luaL_requiref(state, "io", luaopen_io, 1);
			break;
			default:
			break;
		}
	}
	
	LuaState::~LuaState() {
		lua_close(state);
	}
}
