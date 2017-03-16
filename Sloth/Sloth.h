//Remember not to use "Broodwar" in any global class constructor!
#pragma once
#include "Common.h"
#include "BotCommander.h"

//==========================================================================================
// Author: Marcelo Salinas
// Date: 3/16/17
//
// Description:
// Sloth is a bot that will play Starcraft: Broodwar (henceforth known as BW).
// This class handles a majority of the high level BW calls but the important ones used are
// onStart(), onEnd() and onFrame().
//
// onStart() handles initial setup of game, and displays certain things like map name and
// version number to the chat
//
// onEnd() logs win or loss to a file
//
// onFrame() is the most important function because it calls BotCommander which implements
// update() and handles the actual gameplay
//==========================================================================================
namespace Sloth{

	class SlothModule : public BWAPI::AIModule
	{

		BotCommander botCommander;
	public:
		// Virtual functions for callbacks, leave these as they are.
		virtual void onStart();
		virtual void onEnd(bool isWinner);
		virtual void onFrame();
		virtual void onSendText(std::string text);
		virtual void onReceiveText(BWAPI::Player player, std::string text);
		virtual void onPlayerLeft(BWAPI::Player player);
		virtual void onNukeDetect(BWAPI::Position target);
		virtual void onUnitDiscover(BWAPI::Unit unit);
		virtual void onUnitEvade(BWAPI::Unit unit);
		virtual void onUnitShow(BWAPI::Unit unit);
		virtual void onUnitHide(BWAPI::Unit unit);
		virtual void onUnitCreate(BWAPI::Unit unit);
		virtual void onUnitDestroy(BWAPI::Unit unit);
		virtual void onUnitMorph(BWAPI::Unit unit);
		virtual void onUnitRenegade(BWAPI::Unit unit);
		virtual void onSaveGame(std::string gameName);
		virtual void onUnitComplete(BWAPI::Unit unit);
		// Everything below this line is safe to modify.

	};
}
