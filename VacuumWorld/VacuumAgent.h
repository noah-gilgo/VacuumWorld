#pragma once

#include <stdio.h>
#include <array>
#include <exception>

/*
	Creator: Noah Gilgo
	Date: 5/28/2022

	This is my first attempt at creating an intelligent agent. The agent is a direct implementation of the "vacuum world" agent referenced in Chapter 2 of 'Artificial
	Intelligence, A Modern Approach (Fourth Edition) by Stuart Russell and Peter Norvig. It is a simple reflex agent operating in a fully observable, single-agent,
	non-deterministic, episodic, static, discrete, and known task environment. The environment is an std::array containing 2 bools, which reflect if the current member of
	the array is "clean". Since the agent is omniscient of its task environment, the terms 'percept' and 'task environment' are used interchangeably in documentation.

	This agent is as bare-bones as they come, which is why I view it as a good way to get a hang of the basics of agents as well as it being an excellent foray into the
	world of artificial intelligence.
*/

// TODO: Incorporate a performance measure for the VacuumAgent to track how "rationally" it behaves.


class VacuumAgent {
public:
	VacuumAgent() {}; // Constructor for the VacuumAgent object. The C++ compiler gets very angry at me when I don't include the curly brackets.
	
	/*
		Randomly makes the members of the percept "dirty" (sets them to false).

		@param probability_of_dirty Sets the probability of a given member being set to "dirty" (1.0 has a 100% chance of making the member dirty, .5 has a 50% chance, etc.) 
	*/
	void dirtyfy(double probability_of_dirty) {
		std::array<bool, 2> rand_world = { randomBool(probability_of_dirty), randomBool(probability_of_dirty) };
		if (vacuum_world[0] & (!rand_world[0])) {
			vacuum_world[0] = false;
		}
		if (vacuum_world[1] & (!rand_world[1])) {
			vacuum_world[1] = false;
		}
	}

	/*
		Sets the percept for the VacuumAgent. If the vacuum_world parameter is null, the function returns an error message.

		@param vacuum_world An std::array of bools with length 2, the percept being viewed by the VacuumAgent.
	*/
	void set_percept(std::array<bool, 2> vacuum_world) {
		try {
			this->vacuum_world = vacuum_world;
			this->location = 0;
			return;
		}
		catch (std::exception e) {
			printf("ERROR: Task environment provided in set_percept function empty. Please initialize a full std::array<bool, 2>.");
		}
	}

	/*
		The agent function for VacuumAgent. If the current member is "dirty" (false), then the agent performs "suck", converting the member to clean. Otherwise, if the location
		of the agent is set to 0 (corresponding to the left member of the percept), then the agent moves right. Otherwise, if the location is set to 1, the agent moves left.
		If the percept of the agent has not been set to a task environment (vacuum_world == null), the function returns an error message.
	*/
	void agent_function() { // agent function.
		try {
			if (!vacuum_world[location]) { suck(); return; }
			else if (location == 0) { right(); return; }
			else if (location == 1) { left(); return; }
		}
		catch (std::exception e) {
			printf("ERROR: Please provide the agent with an environment to analyze.");
		}
	}

private:
	int location; // Stores the index of the square currently occupied by the agent.
	std::array<bool, 2> vacuum_world; // Stores the percept of the agent.

	void suck() { // sets the Boolean value in vacuum_world at index = location to true.
		vacuum_world[location] = true;
		printf("%d - Suck\n", location);
	}

	void left() { // sets the location to 0 (to point to the left member of vacuum_world)
		location -= 1;
		printf("%d - Left\n", location);
	}

	void right() { // sets the location to 1 (to point to the right member of vacuum_world)
		location += 1;
		printf("%d - Right\n", location);
	}

	/*
		Generates and returns either true or false Boolean values, randomly. Parameter value should be between 1.0 and 0.0.

		@param probability_of_true Double that represents the odds of false being returned. (ex. .75 has a 75% chance of returning false, .25 has a 25% chance, etc.)
		@return Either true or false.
	*/
	bool randomBool(double probability_of_true) {
		if ((probability_of_true < 0.0) ^ (probability_of_true > 1.0)) {
			printf("Invalid parameter value for probability function. Value must be between 1.0 and 0.0.");
		}
		else {
			return rand() > (RAND_MAX / (1.0 / probability_of_true));
		}
	}
};