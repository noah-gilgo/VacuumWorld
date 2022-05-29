#include <stdio.h>
#include <array>
#include <random>
#include "VacuumAgent.h"

VacuumAgent agent;

int main() {
	std::array<bool, 2> vacuum_world{true, true};

	agent.set_percept(vacuum_world);

	for (int i = 0; i < 100; i++) {
		agent.dirtyfy();
		agent.agent_function();
	}
}
