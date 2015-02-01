#include "Goal.h"

template <class EntityClass>
AI::Goal<EntityClass>::Goal(EntityClass* owner)

{
	owner = owner;
	status = inactive;
}

// activates the goal
template <class EntityClass>
void AI::Goal<EntityClass>::activate()
{
	status = active;
}

// processes the goal
template <class EntityClass>
AI::GoalStatus AI::Goal<EntityClass>::process()
{
	return status;
}
		
// terminates the goal's processes
template <class EntityClass>
void AI::Goal<EntityClass>::terminate()
{
}
		
// returns true if the goal is completed
template <class EntityClass>
bool AI::Goal<EntityClass>::isComplete() const
{
	return status == completed;
}
		
// returns true if the goal is active
template <class EntityClass>
bool AI::Goal<EntityClass>::isActive() const
{
	return status == active;
}
		
// returns true if the goal is inactive
template <class EntityClass>
bool AI::Goal<EntityClass>::isInactive() const
{
	return status == inactive;
}
		
// returns true if the goal has failed
template <class EntityClass>
bool AI::Goal<EntityClass>::hasFailed() const
{
	return status == failed;
}
		
// if the goal is inactive, the goal gets activated
template <class EntityClass>
void AI::Goal<EntityClass>::activateIfInactive()
{
	if( status == inactive )
	{
		activate();
	}
}
				
// if the goal has failed, reactive it
template <class EntityClass>
void AI::Goal<EntityClass>::reactivateIfFailed()
{
	if( hasFailed() )
	{
			status = inactive;
	}
}