#include <lua.hpp>

extern "C" {
static const luaL_Reg libathelia[] = {
	{NULL, NULL} //sentinel - for lua's sake?
};

int luaopen_libathelia(lua_State *state) {
	luaL_newlibtable(state, libathelia);
	luaL_setfuncs(state, libathelia, 0);
	return 1;
}
}
