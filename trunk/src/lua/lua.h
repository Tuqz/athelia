#include <lua.hpp>
#include <string>
#include <vector>

namespace Lua {
	class LuaInterface {
		public:
			lua_State* state;
			std::vector<luaL_Reg> libs;
			LuaInterface();
			LuaInterface(std::vector<luaL_Reg> libraries);
			~LuaInterface();
			std::string run_file(std::string filename);
		private:
			void loadlibs();
	};
}
