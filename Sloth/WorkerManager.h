#pragma once
#include "Common.h"
#include "BotCommander.h"

//==========================================================================================
// Author: Marcelo Salinas
// Date: 3/16/17
//
// Description:
// WorkerManager handles every worker unit in the game under the AI's control. It has an
// instance of the botCommander to get it's worker list. WorkerManager takes care of sending
// idle workers to mine, giving a worker to ProductionManager, and giving an available
// worker to Scouter.
//==========================================================================================
namespace Sloth{
    
    class WorkerManager{
        
        BotCommander botCommander;
        BWAPI::Unitset workers;
        
        void getWorkers();
        
    public:
        
        WorkerManager();
        void update();
        void sendToMine();
        BWAPI::Unit getClosestWorker(BWAPI::Position position);
        
    };
}
