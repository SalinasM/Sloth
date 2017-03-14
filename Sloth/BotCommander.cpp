#include "Common.h"
#include "BotCommander.h"

using namespace Sloth;

//-------------------------------------
//Basic Constructor
//-------------------------------------
BotCommander::BotCommander() : scoutSet(false){}

//-------------------------------------
//High level controller for game flow
//-------------------------------------
void BotCommander::update(){
	//call all lower level managers
	handleUnitAssignments();
}

//-------------------------------------
//Assign every unit to one of the classifying lists
//-------------------------------------
void BotCommander::handleUnitAssignments(){
	//assign units to different lists
	validUnits.clear();
	fightingUnits.clear();
	scoutingUnits.clear();

	setValidUnits();
	setFightingUnits();
	setScoutingUnits();
	setCargoUnits();
	setWorkers();
}

//-------------------------------------
//Check every unit for validity and add it to list
//-------------------------------------
void BotCommander::setValidUnits(){

	//run through all units and check if they're not dead or some unknown etc
	for (auto & unit : BWAPI::Broodwar->self()->getUnits()){
        if(isVaildUnit(unit)){ validUnits.insert(unit); }
	}
}

//-------------------------------------
//Check every unit for fighting ability and add it to list
//-------------------------------------
void BotCommander::setFightingUnits(){
	for (auto & unit : BWAPI::Broodwar->self()->getUnits()){
		if(isFightingUnit(unit)){ fightingUnits.insert(unit); }
	}
}

//-------------------------------------
//Check every unit for scouting definition and add it to list
//-------------------------------------
void BotCommander::setScoutingUnits(){
    for (auto & unit : BWAPI::Broodwar->self()->getUnits()){
        if(isScoutingUnit(unit)){ scoutingUnits.insert(unit); }
    }
}

//-------------------------------------
//Check every unit for a cargo unit definition and add it to list
//-------------------------------------
void BotCommander::setCargoUnits(){
    for (auto & unit : BWAPI::Broodwar->self()->getUnits()){
        if(isCargoUnit(unit)){ scoutingUnits.insert(unit); }
    }
}

//-------------------------------------
//Check every unit and add the workers to list
//-------------------------------------
void BotCommander::setWorkers(){
    for (auto & unit : BWAPI::Broodwar->self()->getUnits()){
        if(unit->getType().isWorker()){ workers.insert(unit); }
    }
}

void BotCommander::printUnitLists(){
    BWAPI::Broodwar->drawTextScreen(10, 5, "%cWorker Test", yellow);
}

//-------------------------------------
//Test a unit for validity
//-------------------------------------
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

//-------------------------------------
//Test a unit for fighting ability
//-------------------------------------
bool BotCommander::isFightingUnit(BWAPI::Unit unit){
	//if unit doesn't exist
	if (!unit){ return false; }

	//if unit is a building, worker or overlord then skip
	if (unit->getType().isWorker() || unit->getType().isBuilding() || unit->getType() != BWAPI::UnitTypes::Zerg_Overlord)
	{ return false; }

	if (unit->canAttack() || unit->getType() == BWAPI::UnitTypes::Zerg_Defiler)
	{ return true; }
	
	return false;
}

//-------------------------------------
//Check if unit is a valid scout
//-------------------------------------
bool BotCommander::isScoutingUnit(BWAPI::Unit unit){
	//if unit doesn't exist
	if (!unit){ return false; }

    //zerg scouting should only be done with overlords and, in special occasions, a worker
    if (unit->getType() == BWAPI::UnitTypes::Zerg_Overlord){
		return true;
	}

	return false;
}

//-------------------------------------
//Check if unit is a valid cargo unit
//-------------------------------------
bool BotCommander::isCargoUnit(BWAPI::Unit unit){
    //if unit doesn't exist
    if (!unit){ return false; }
    
    //zerg scouting should only be done with overlords and, in special occasions, a worker
    if (unit->getType() == BWAPI::UnitTypes::Zerg_Overlord){
        return true;
    }
    
    return false;
}

//-------------------------------------
//Return the closest worker to target position
//-------------------------------------
BWAPI::Unit BotCommander::getClosestWorker(BWAPI::Position position){
    BWAPI::Unit closestWorker = nullptr;
    double closestDistance = 1000000;
    
    //run through all valid units and check the workers for distance
    for (auto & unit : workers){
        double distance = unit->getDistance(position);
        if(!closestWorker || distance < closestDistance){
            closestWorker = unit;
            closestDistance = distance;
        }
    }
	return closestWorker;
}


