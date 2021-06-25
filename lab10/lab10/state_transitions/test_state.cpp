#include "process.hpp"

int main(){
    Process testProc;

    testProc.report(std::cout); // NEW

    testProc.admitted();

    testProc.report(std::cout); // READY

    testProc.exit();

    testProc.report(std::cout); // READY

    testProc.scheduler_dispatch();

    testProc.report(std::cout); // RUNNING

    testProc.interrupt();

    testProc.report(std::cout); // READY

    testProc.scheduler_dispatch();

    testProc.report(std::cout); // RUNNING

    testProc.exit();

    testProc.report(std::cout); // TERMINATED
    
    //

    Process testProc2;

    testProc2.report(std::cout); // NEW

    testProc2.admitted();

    testProc2.report(std::cout); // READY

    testProc2.exit();

    testProc2.report(std::cout); // READY

    testProc2.scheduler_dispatch();

    testProc2.report(std::cout); // RUNNING

    testProc2.interrupt();

    testProc2.report(std::cout); // READY

    testProc2.scheduler_dispatch();

    testProc2.report(std::cout); // RUNNING

    testProc2.exit();

    testProc2.report(std::cout); // TERMINATED

    return 0;
}
