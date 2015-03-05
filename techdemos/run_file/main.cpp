#include <luaState.h>

int main() {
	Lua::LuaState state;
	state.loadLibrary(Lua::BASE);
	state.runFile("test.lua");
	return 0;
}
