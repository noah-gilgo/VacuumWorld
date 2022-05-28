#include <stdio.h>
#include <array>

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
		this->vacuum_world = vacuum_world;
		return;
	}

private:
	std::array<bool, 2> vacuum_world;
};
