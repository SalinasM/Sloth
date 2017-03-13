#include "Sloth.h"

using namespace Sloth;
using namespace BWAPI;

void SlothModule::onStart(){

	// Hello World!
	Broodwar->sendText("I am Sloth...");
	Broodwar->sendText("Version 0.1");

	// Print the map name.
	// BWAPI returns std::string when retrieving a string, don't forget to add .c_str() when printing!
	Broodwar << "The map is " << Broodwar->mapName() << "!" << std::endl;

	// Enable the UserInput flag, which allows us to control the bot and type messages.
	Broodwar->enableFlag(Flag::UserInput);

	// Uncomment the following line and the bot will know about everything through the fog of war (cheat).
	//Broodwar->enableFlag(Flag::CompleteMapInformation);

	// Set the command optimization level so that common commands can be grouped
	// and reduce the bot's APM (Actions Per Minute).
	Broodwar->setCommandOptimizationLevel(2);

	// Check if this is a replay
	if (Broodwar->isReplay())
	{

		// Announce the players in the replay
		Broodwar << "The following players are in this replay:" << std::endl;

		// Iterate all the players in the game using a std:: iterator
		Playerset players = Broodwar->getPlayers();
		for (auto p : players)
		{
			// Only print the player if they are not an observer
			if (!p->isObserver())
				Broodwar << p->getName() << ", playing as " << p->getRace() << std::endl;
		}

	}
	else // if this is not a replay
	{
		// Retrieve you and your enemy's races. enemy() will just return the first enemy.
		// If you wish to deal with multiple enemies then you must use enemies().
		if (Broodwar->enemy()) // First make sure there is an enemy
			Broodwar << "The matchup is " << Broodwar->self()->getRace() << " vs " << Broodwar->enemy()->getRace() << std::endl;
	}


}

void SlothModule::onEnd(bool isWinner){
	if (isWinner){
		//log win here!
	}
	else{

		//log loss here...
	}

}

void SlothModule::onFrame(){
	_botCommander.update();
}

void SlothModule::onSendText(std::string text){

}

void SlothModule::onReceiveText(BWAPI::Player player, std::string text){

}

void SlothModule::onPlayerLeft(BWAPI::Player player){

}

void SlothModule::onNukeDetect(BWAPI::Position target){

}

void SlothModule::onUnitDiscover(BWAPI::Unit unit){

}

void SlothModule::onUnitEvade(BWAPI::Unit unit){

}

void SlothModule::onUnitShow(BWAPI::Unit unit){

}

void SlothModule::onUnitHide(BWAPI::Unit unit){

}

void SlothModule::onUnitCreate(BWAPI::Unit unit){

}

void SlothModule::onUnitDestroy(BWAPI::Unit unit){

}

void SlothModule::onUnitMorph(BWAPI::Unit unit){

}

void SlothModule::onUnitRenegade(BWAPI::Unit unit){

}

void SlothModule::onSaveGame(std::string gameName){

}

void SlothModule::onUnitComplete(BWAPI::Unit unit){

}