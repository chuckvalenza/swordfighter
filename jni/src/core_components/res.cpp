/**
 * res.cpp
 *
 * Description: Load all resources from XMLs
 */

#include "core_components/res.h"

namespace res {
	Resources r;

	void load()
	{
		r.loadXML("xmls/enemies.xml");
		r.loadXML("xmls/player.xml");
		r.loadXML("xmls/ui.xml");
		r.loadXML("xmls/world.xml");
	}

	void free()
	{
		r.free();
	}
}