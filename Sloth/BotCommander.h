#pragma once
#include "Common.h"

namespace Sloth{

	class BotCommander{

		BWAPI::Unitset validUnits;
		BWAPI::Unitset fightingUnits;
		BWAPI::Unitset cargoUnits;
		BWAPI::Unitset scoutingUnits;

		bool scoutSet;
		bool isAssigned() const;

	public:
		BotCommander();
        
		void update();

		void handleUnitAssignments();
		void setValidUnits();
		void setFightingUnits();
		void setCargoUnits();
		void setScoutingUnits();
		bool isVaildUnit(BWAPI::Unit unit);
		bool isFightingUnit(BWAPI::Unit unit);
		bool isCargoUnit(BWAPI::Unit unit);
		bool isScoutingUnit(BWAPI::Unit unit);

		BWAPI::Unit getClosestWorker(BWAPI::Position position);
	};
}
