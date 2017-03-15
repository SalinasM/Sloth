#pragma once
#include "Common.h"

namespace Sloth{
    
    class WorkerManager{
        
        BWAPI::Unitset workers;
        
    public:
        
        WorkerManager();
        
        BWAPI::Unit getAvailableWorker();
        void getIdleWorkers();
        void sendToMine();
        
    };
}
