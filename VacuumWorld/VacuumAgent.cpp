#include <stdio.h>
#include <array>
#include <exception>

/*
	Creator: Noah Gilgo
	Date: 5/28/2022

	This is my first attempt at creating an intelligent agent. The agent is a direct implementation of the "vacuum world" agent referenced in Chapter 2 of 'Artificial 
	Intelligence, A Modern Approach (Fourth Edition) by Stuart Russell and Peter Norvig. It is a simple reflex agent operating in a fully observable, single-agent,
	non-deterministic, episodic, static, discrete, and known task environment. The environment is an std::array containing 2 bools, which reflect if the current member of 
	the array is "clean".

	This agent is as bare-bones as they come, which is why I view it as a good way to get a hang of the basics of agents as well as it being an excellent foray into the 
	world of artificial intelligence.
*/

class VacuumAgent {
public:
	VacuumAgent(); // Initializer

	/*
		Sets the percept for the VacuumAgent. 

		@param vacuum_world An std::array of bools with length 2, the percept being viewed by the VacuumAgent.
		@return void.
	*/
	void set_percept(std::array<bool, 2> vacuum_world) {
		try {
			this->vacuum_world = vacuum_world;
			this->location = 0;
			return;
		}
		catch (std::exception e) {
			printf("ERROR: Please provide the agent with an environment to analyze.");
		}
	}

	void suck() { // sets the Boolean value in vacuum_world at index = location to true.
		try {
			!vacuum_world[location];
		} catch (std::exception e) {
			printf("ERROR: Please provide the agent with an environment to analyze.");
		}
	}

	void left() { // sets the location to 0 (to point to the left member of vacuum_world)
		location -= 1;
	}

	void right() { // sets the location to 1 (to point to the right member of vacuum_world)
		location += 1;
	}

	void agent_function() { // agent function.
		try {
			if (!vacuum_world[location]) { suck(); }
			else if (location == 0) { right(); }
			else if (location == 1) { left(); }
		}
		catch (std::exception e) {
			printf("ERROR: Please provide the agent with an environment to analyze.");
		}
	}

private:
	std::array<bool, 2> vacuum_world; // Stores the percept of the agent.
	int location; // Stores the index of the square currently occupied by the agent.

};