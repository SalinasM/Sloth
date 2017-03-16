#include "Common.h"
#include "WorkerManager.h"

using namespace Sloth;

//==========================================================================================
//Called by other functions to set up the workers vector for use in that function
//==========================================================================================
void WorkerManager::getWorkers(){
    workers = botCommander.workers;
}

//==========================================================================================
//Basic Constructor
//==========================================================================================
WorkerManager::WorkerManager(){
    getWorkers();
}

//==========================================================================================
//Called by other functions to send an idle worker, or a worker finished building something,
//to mine minerals or gas
//==========================================================================================
void WorkerManager::sendToMine(){
    getWorkers();
    
    // Look through all workers and if any are idle check if it is carrying a resource to
    //return otherwise find a mineral patch or refinery to harvest.
    for (auto & unit : workers){
        if(unit->isIdle()){
            if (u->isCarryingGas() || u->isCarryingMinerals())
            {
                u->returnCargo();
            }
            else if (!u->getPowerUp()) {
                // Harvest from the nearest mineral patch or gas refinery
                if (!u->gather( u->getClosestUnit( IsMineralField || IsRefinery )))
                {
                    // If the call fails, then print the last error message
                    Broodwar << Broodwar->getLastError() << std::endl;
                }
                
            }
        }
    }
}

//==========================================================================================
//Return the closest worker to target position
//==========================================================================================
BWAPI::Unit WorkerManager::getClosestWorker(BWAPI::Position position){
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
