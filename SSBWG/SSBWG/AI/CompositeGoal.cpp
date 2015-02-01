#include "CompositeGoal.h"

template <class EntityClass>
void AI::CompositeGoal<EntityClass>::terminateSubgoals()
{
	if( subGoals.size() == 0 &&  subGoals.top()->isActive() )
	{
		subGoals.top()->terminate();
	}
}
				
template <class EntityClass>
AI::GoalStatus AI::CompositeGoal<EntityClass>::processSubgoals()
{
	while( subGoals.size() != 0 && 
			(subGoals.top()->isComplete() || subGoals.top()->hasFailed()) )
	{
		subGoals.top()->terminate();
		subGoals.pop();
	}
	if( subGoals.size() != 0 )
	{
		statusOfSubgoals =  subGoals.top()->process();
					
		if( statusOfSubgoals == completed && subGoals.size() > 1 )
		{
			return active;
		}
		else
		{
			return statusOfSubgoals;
		}
	}
	else
	{
		return completed;
	}
}
	
template <class EntityClass>
AI::CompositeGoal<EntityClass>::CompositeGoal(EntityClass* owner)
	: Goal(owner),
	statusOfSubgoals(inactive)
{
}
		
// remove all of the subgoals
template <class EntityClass>
void AI::CompositeGoal<EntityClass>::removeAllSubgoals()
{
	subGoals.top()->terminate();
	while(!subGoals.empty())
	{
		delete subGoals.top();
		subGoals.pop();
	}
}
						
// add a subgoal to the front of the subgoals
template <class EntityClass>
void AI::CompositeGoal<EntityClass>::addSubgoal( Goal<EntityClass>* goal )
{
	subGoals.push( goal );
}
		
// Process goals
template <class EntityClass>
AI::GoalStatus AI::CompositeGoal<EntityClass>::process()
{
	activateIfInactive();
	status = processSubgoals();
	return status;
}
		
// Terminate the function
template <class EntityClass>
void AI::CompositeGoal<EntityClass>::terminate()
{
	terminateSubgoals();
}

template <class EntityClass>
AI::CompositeGoal<EntityClass>::~CompositeGoal()
{
	while(!subGoals.empty())
	{
		delete subGoals.top();
		subGoals.pop();
	}
}