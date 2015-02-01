#pragma once
#include "Goal.h"
#include <stack>

namespace AI
{
	template <class EntityClass>
	class CompositeGoal : public Goal<EntityClass>
	{
		
	protected:
		std::stack<Goal<EntityClass>*> subGoals;
		GoalStatus statusOfSubgoals;

		void terminateSubgoals();
				
		GoalStatus processSubgoals();
	
	public:
		CompositeGoal(EntityClass* owner);
		
		// remove all of the subgoals
		void removeAllSubgoals();
						
		// add a subgoal to the front of the subgoals
		void addSubgoal( Goal<EntityClass>* goal );
		
		// Process goals
		GoalStatus process();
		
		// Terminate the function
		void terminate();

		virtual ~CompositeGoal();
	};
}