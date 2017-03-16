#pragma once
#include "Common.h"

//==========================================================================================
// Author: Marcelo Salinas
// Date: 3/16/17
//
// Description:
// BotCommander is a high level manager for the game flow. It handles the update function
// handed down by the game. From update it gives control to the various different managers
// that handle specific parts of the game. It also builds a list of all available units and
// categorizes them into lists available for each manager through their get function. It
// then prints those lists' values onto the screen for debugging.
//==========================================================================================
namespace Sloth{

	class BotCommander{

		BWAPI::Unitset validUnits;
		BWAPI::Unitset fightingUnits;
		BWAPI::Unitset cargoUnits;
		BWAPI::Unitset scoutingUnits;
        BWAPI::Unitset workers;
        BWAPI::Unitset overlords;

	public:
		BotCommander();

		void update();

		void handleUnitAssignments();
		void setValidUnits();
		void setFightingUnits();
		void setCargoUnits();
		void setScoutingUnits();
        void setWorkers();
        void setOverlords();
        void printUnitLists();

		bool isVaildUnit(BWAPI::Unit unit);
		bool isFightingUnit(BWAPI::Unit unit);
		bool isCargoUnit(BWAPI::Unit unit);
		bool isScoutingUnit(BWAPI::Unit unit);
        
	};
}
