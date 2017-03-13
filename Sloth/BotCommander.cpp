#include "Common.h"
#include "BotCommander.h"

using namespace Sloth;

BotCommander::BotCommander() : scoutSet(false){}

BotCommander::~BotCommander(){}

void BotCommander::update(){
	//call all lower level managers
	
}

void BotCommander::handleUnitAssignments(){
	//assign units to different lists
	validUnits.clear();
	fightingUnits.clear();
	scoutingUnits.clear();

	setValidUnits();

	setFightingUnits();
	setScoutingUnits();

}

void BotCommander::setValidUnits(){

	//run through all units and check if they're not dead or some unknown etc
	for (auto & unit : BWAPI::Broodwar->self()->getUnits()){
		if (!unit){
			return;
		}

		if (unit->isCompleted()
			&& unit->getHitPoints() > 0
			&& unit->exists()
			&& unit->getType() != BWAPI::UnitTypes::Unknown
			&& unit->getPosition().x != BWAPI::Positions::Unknown.x
			&& unit->getPosition().y != BWAPI::Positions::Unknown.y)
		{
			validUnits.insert(unit);
		}else{
			return;
		}

	}
}

void BotCommander::setFightingUnits(){

}

void BotCommander::setScoutingUnits(){

}

BWAPI::Unit BotCommander::getClosestWorker(BWAPI::Position position){

}