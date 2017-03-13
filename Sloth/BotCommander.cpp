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

	}
}

void BotCommander::setFightingUnits(){
	for (auto & unit : BWAPI::Broodwar->self()->getUnits()){
		
	}
}

void BotCommander::setScoutingUnits(){

}

bool BotCommander::isVaildUnit(BWAPI::Unit unit){
	//if unit doesn't exist return false
	if (!unit){ return false; }

	//if unit is not done or doesn't exist, doesn't have a positive hp, and is not a real unit with a real position on map then skip
	if (unit->isCompleted()
		&& unit->getHitPoints() > 0
		&& unit->exists()
		&& unit->getType() != BWAPI::UnitTypes::Unknown
		&& unit->getPosition().x != BWAPI::Positions::Unknown.x
		&& unit->getPosition().y != BWAPI::Positions::Unknown.y)
	{ return true; }
	
	return false;
}

bool BotCommander::isFightingUnit(BWAPI::Unit unit){
	//if unit doesn't exist
	if (!unit){ return false; }

	//if unit is a building, worker or overlord then skip
	if (unit->getType().isWorker || unit->getType().isBuilding || unit->getType() != BWAPI::UnitTypes::Zerg_Overlord)
	{ return false; }

	if (unit->canAttack() || unit->getType() == BWAPI::UnitTypes::Zerg_Defiler)
	{ return true; }
	
	return false;
}

//zerg scouting should only be done with overlords and a worker in special occasions
bool BotCommander::isScoutingUnit(BWAPI::Unit unit){
	//if unit doesn't exist
	if (!unit){ return false; }

	if (unit->getType() == BWAPI::UnitTypes::Zerg_Overlord){
		return true;
	}

	return false;
}

BWAPI::Unit BotCommander::getClosestWorker(BWAPI::Position position){

}