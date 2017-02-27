/**
 * Terrain.cpp
 *
 * Description: Terrain tile utilizing flyweight pattern
 */

#include "Terrain.h"

Terrain::Terrain()
{

}

void Terrain::init(float ms, std::string tex_name)
{
	view = new Sprite;

	move_speed = ms;

	texture = new Sprite;
	texture->setResAnim(res::r.getResAnim(tex_name));
	texture->attachTo(view);
	view->setSize(texture->getSize());
}

float Terrain::getMoveSpeed()
{
	return move_speed;
}

void Terrain::redraw()
{
	if (getPosition() != next_pos) {
		setPosition(next_pos);
	}
}

void Terrain::update(const UpdateState&)
{

}
