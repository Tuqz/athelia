#include <string>
#include <lua.hpp>

#pragma once
namespace Lua {
	enum Library {
		BASE,
		IO
	};
	
	class LuaState {
	private:
		lua_State *state;
	public:
		~LuaState();
		LuaState();
		int runFile(std::string filename);
		void loadLibrary(Library library);
	};
}
