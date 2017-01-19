/**
 * Wearable.h
 *
 * Description: Class of items that are wearable
 */

#ifndef SWORD_FIGHTER_WEARABLE_H
#define SWORD_FIGHTER_WEARABLE_H

#include "oxygine-framework.h"

#include "items/Item.h"
#include "core_components/DrawableObj.h"
#include "core_components/res.h"

using namespace oxygine;

DECLARE_SMART(Wearable, spWearable);

class Wearable : public Item {
	private:
		float buff_val;
	public:
		enum ItemEffect {
			HEALTH_BUFF,
			DAMAGE_BUFF,
			SPEED_BUFF
		};

		ItemEffect effect_type;

		Wearable();
		float getBuff();
		void setBuff(float);
		int getBuffType();
		void setBuffType(ItemEffect);
};

#endif //SWORD_FIGHTER_WEARABLE_H
