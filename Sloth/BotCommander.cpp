1#include "Common.h"
#include "BotCommander.h"

using namespace Sloth;

//==========================================================================================
//Basic constructor for BotCommander
//==========================================================================================
BotCommander::BotCommander() : scoutSet(false){}

//==========================================================================================
//High level controller for game flow
//==========================================================================================
void BotCommander::update(){
	//call all lower level managers
	handleUnitAssignments();
    printUnitLists();
}

//==========================================================================================
//Assign every unit to one of the classifying lists
//==========================================================================================
void BotCommander::handleUnitAssignments(){
	//assign units to different lists
	validUnits.clear();
	fightingUnits.clear();
	scoutingUnits.clear();
	workers.clear();
	overlords.clear();

	setValidUnits();
	setFightingUnits();
	setScoutingUnits();
	setCargoUnits();
	setWorkers();
	setOverlords();
}

//==========================================================================================
//Check every unit for validity and add it to list
//==========================================================================================
void BotCommander::setValidUnits(){

	//run through all units and check if they're not dead or some unknown etc
	for (auto & unit : BWAPI::Broodwar->self()->getUnits()){
        if(isVaildUnit(unit)){ validUnits.insert(unit); }
	}
}

//==========================================================================================
//Check every unit for fighting ability and add it to list
//==========================================================================================
void BotCommander::setFightingUnits(){
	for (auto & unit : BWAPI::Broodwar->self()->getUnits()){
		if(isFightingUnit(unit)){ fightingUnits.insert(unit); }
	}
}

//==========================================================================================
//Check every unit for scouting definition and add it to list
//==========================================================================================
void BotCommander::setScoutingUnits(){
    for (auto & unit : BWAPI::Broodwar->self()->getUnits()){
        if(isScoutingUnit(unit)){ scoutingUnits.insert(unit); }
    }
}

//==========================================================================================
//Check every unit for a cargo unit definition and add it to list
//==========================================================================================
void BotCommander::setCargoUnits(){
    for (auto & unit : BWAPI::Broodwar->self()->getUnits()){
        if(isCargoUnit(unit)){ scoutingUnits.insert(unit); }
    }
}

//==========================================================================================
//Check every unit and add the workers to list
//==========================================================================================
void BotCommander::setWorkers(){
    for (auto & unit : BWAPI::Broodwar->self()->getUnits()){
        if(unit->getType().isWorker()){ workers.insert(unit); }
    }
}

//==========================================================================================
//Check every unit and add the workers to list
//==========================================================================================
void BotCommander::setOverlords(){
    for (auto & unit : BWAPI::Broodwar->self()->getUnits()){
        if(unit->getType() == BWAPI::UnitTypes::Zerg_Overlord){ overlords.insert(unit); }
    }
}

//==========================================================================================
//print out unit count in all lists
//==========================================================================================
void BotCommander::printUnitLists(){
	//count for each vector list created
    int validCount = 0;
    int fightingCount = 0;
    int cargoCount = 0;
    int scoutCount = 0;
    int workerCount = 0;
	int overlordCount = 0;
    
    //count each vector
    for (auto & unit : validUnits)      { validCount++; }
    for (auto & unit : fightingUnits)   { fightingCount++; }
    for (auto & unit : scoutingUnits)   { scoutCount++; }
    for (auto & unit : workers)         { workerCount++; }
    for (auto & unit : overlords)       { overlordCount++; }
    for (auto & unit : cargoUnits)      { cargoCount++; }
    
    //display each count \x** is for color
    BWAPI::Broodwar->drawTextScreen(50, 30, "\x03%d Valid Units", validCount);
    BWAPI::Broodwar->drawTextScreen(50, 42, "\x03%d Fighting Units", fightingCount);
    BWAPI::Broodwar->drawTextScreen(50, 54, "\x03%d Scouting Units", scoutCount);
	BWAPI::Broodwar->drawTextScreen(50, 66, "\x03%d Workers", workerCount);
    BWAPI::Broodwar->drawTextScreen(50, 78, "\x03%d Overlords", overlordCount);
    BWAPI::Broodwar->drawTextScreen(50, 90, "\x03%d Cargo Units", cargoCount);
}

//==========================================================================================
//Test a unit for validity
//==========================================================================================
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

//==========================================================================================
//Test a unit for fighting ability
//==========================================================================================
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

//==========================================================================================
//Check if unit is a valid scout
//==========================================================================================
bool BotCommander::isScoutingUnit(BWAPI::Unit unit){
	//if unit doesn't exist
	if (!unit){ return false; }

    //zerg scouting should only be done with overlords and, in special occasions, a worker
    if (unit->getType() == BWAPI::UnitTypes::Zerg_Overlord){
		return true;
	}

	return false;
}

//==========================================================================================
//Check if unit is a valid cargo unit
//==========================================================================================
bool BotCommander::isCargoUnit(BWAPI::Unit unit){
    //if unit doesn't exist
    if (!unit){ return false; }
    
    //zerg scouting should only be done with overlords and, in special occasions, a worker
    if (unit->getType() == BWAPI::UnitTypes::Zerg_Overlord){
        return true;
    }
    
    return false;
}


