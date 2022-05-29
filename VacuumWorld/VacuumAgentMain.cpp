#include <stdio.h>
#include <array>
#include <random>
#include "VacuumAgent.h"

/*
	Creator: Noah Gilgo
	Date: 5/28/2022
*/

int main() {
	VacuumAgent agent; // Initializes the agent
	std::array<bool, 2> vacuum_world{true, true}; // Initializes the task environment
	double probability_of_dirty = .1; // Sets the percent chance that the dirtyfy function will set a given member of the task environment to "dirty" when called.

	agent.set_percept(vacuum_world); // Sets the agents percept on the task environment.

	for (int i = 0; i < 100; i++) {
		agent.dirtyfy(probability_of_dirty); // Either "dirtyfys" or leaves clean the members of the task environment depending on the value of probability_of_dirty.
		agent.agent_function(); // Performs the agent function. The current location of the agent and the action it takes are printed to console.
	}
}
