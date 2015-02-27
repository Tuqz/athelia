#include <vector>
#include <string>

#pragma once

namespace Lua {
	class Function {
		std::vector<Type> args;
		Type ret = NIL;
		std::string name;
	};
}
