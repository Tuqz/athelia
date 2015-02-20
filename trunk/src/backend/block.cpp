#include "block.h"

std::vector<int> Block::unused;

void Block::setId() {
	static int i = 0;
	if(unused.size()) {
		id = unused[0];
		unused.erase(unused.begin());
	} else {
		id = i;
		++i;
	}
}

Block::Block(const Ogre::Vector3 &position) : pos(position) {}
