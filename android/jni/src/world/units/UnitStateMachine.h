/**
 * UnitStateMachine.h
 *
 * description: Encapsulate all necessary Unit states into one object
 */

#ifndef SWORD_FIGHTER_UNITSTATEMACHINE_H
#define SWORD_FIGHTER_UNITSTATEMACHINE_H

#include "world/units/UnitState.h"
#include <typeinfo>

template<class unit_type>
class UnitStateMachine {
	private:
		unit_type* owner;
		UnitState<unit_type>* current_state;
		UnitState<unit_type>* previous_state;
		UnitState<unit_type>* global_state;
	public:
		UnitStateMachine(unit_type* o) :
			owner(o),
			current_state(0),
			previous_state(0),
			global_state(0)
		{}

		void changeState(UnitState<unit_type>* new_state)
		{
			assert(new_state && "Trying to change to a null state");
			previous_state = current_state;
			current_state->exit(owner);
			current_state = new_state;
			current_state->enter(owner);
		}

		void revertState(UnitState<unit_type>* new_state)
		{
			changeState(previous_state);
		}

		void setCurrentUnitState(UnitState<unit_type>* s)
		{
			current_state = s;
		}

		void setPreviousUnitState(UnitState<unit_type>* s)
		{
			previous_state = s;
		}
		void setGlobalUnitState(UnitState<unit_type>* s)
		{
			global_state = s;
		}

		UnitState<unit_type>* currentState()
		{
			return current_state;
		}

		UnitState<unit_type>* globalState()
		{
			return global_state;
		}

		UnitState<unit_type>* previousState()
		{
			return previous_state;
		}

		bool isInState(const UnitState<unit_type>& st) const
		{
			return typeid(*current_state) == typeid(st);
		}

		void update() const
		{
			if(global_state) {
				global_state->execute(owner);
			}

			if(current_state) {
				current_state->execute(owner);
			}
		}
};

#endif //SWORD_FIGHTER_UNITSTATEMACHINE_H

