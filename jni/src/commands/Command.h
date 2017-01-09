/**
 * Command.h
 *
 * Description: Abstract class to utilize the command pattern for character
 * input.
 */

#ifndef SWORD_FIGHTER_COMMAND_H
#define SWORD_FIGHTER_COMMAND_H

class Command {
	public:
		virtual ~Command() {}
		virtual void execute() = 0;
};

#endif //SWORD_FIGHTER_COMMAND_H
