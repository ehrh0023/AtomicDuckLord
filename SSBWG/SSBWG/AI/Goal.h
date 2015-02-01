#pragma once

namespace AI
{
	// possible goal statuses
	enum GoalStatus {inactive, active, completed, failed};

	template <class EntityClass>
	class Goal
	{
	protected:
		EntityClass* owner;
		GoalStatus status;

	public:
		virtual ~Goal() {}

		Goal(EntityClass* owner);

		// activates the goal
		virtual void activate();

		// processes the goal
		virtual GoalStatus process();
		
		// terminates the goal's processes
		virtual void terminate();
		
		// returns true if the goal is completed
		virtual bool isComplete() const;
		
		// returns true if the goal is active
		virtual bool isActive() const;
		
		// returns true if the goal is inactive
		virtual bool isInactive() const;
		
		// returns true if the goal has failed
		virtual bool hasFailed() const;
		
		// if the goal is inactive, the goal gets activated
		virtual void activateIfInactive();
				
		// if the goal has failed, reactive it
		virtual void reactivateIfFailed();
	};
}