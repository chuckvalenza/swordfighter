/**
 * UnitState.h
 *
 * Description: Unit state class template
 */

#ifndef SWORD_FIGHTER_UNITSTATE_H
#define SWORD_FIGHTER_UNITSTATE_H

template <class unit_type>
class UnitState {
	protected:
	public:
		virtual void enter(unit_type*) = 0;
		virtual void execute(unit_type*) = 0;
		virtual void exit(unit_type*) = 0;
		virtual ~UnitState() {}
};

#endif //SWORD_FIGHTER_UNITSTATE_H
