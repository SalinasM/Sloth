#pragma once
#include "Common.h"

namespace Sloth{

	class BotCommander{

		BWAPI::Unitset validUnits;
		BWAPI::Unitset fightingUnits;
		BWAPI::Unitset scoutingUnits;

		bool scoutSet;
		bool isAssigned() const;

	public:
		BotCommander();
		~BotCommander();

		void update();

		void handleUnitAssignments();
		void setValidUnits();
		void setFightingUnits();
		void setScoutingUnits();

		BWAPI::Unit getClosestWorker(BWAPI::Position position);
	};
}