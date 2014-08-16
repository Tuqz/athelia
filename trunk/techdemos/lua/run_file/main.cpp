#include <lua.h>

int main() {
	Lua::LuaInterface interface;
	interface.run_file("hello.lua");
	return 0;
}
