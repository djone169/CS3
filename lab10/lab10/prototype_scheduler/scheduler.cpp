//
//  scheduler.cpp
//  lab10
//
#include <algorithm>
#include <set>
#include <ctime>
#include <cstdlib>
#include <queue>
#include "process.hpp"

class Scheduler{
private:
    Process* prototype;

    std::deque<Process*> all;
    std::queue<Process*> ready;
    std::set<Process*> waiting;

public:
    Scheduler(){
        prototype = new Process();
    }

    void report(std::ostream&);

    void create_process();
    void run(int);

};

void Scheduler::report(std::ostream &out){
    out << "\nReport: " << std::endl;
    for(Process *p : all){
        if(p != nullptr)
            out << "\t";
            p->report(out);
    }
    out << "End\n\n";
}

void Scheduler::create_process(){
    Process *temp = prototype->clone();
    temp->admitted();
    ready.push(temp);
    all.push_back(temp);
}

void Scheduler::run(int num){
    srand(time(nullptr));
    for(int i = 0; i < num; ++i){ // creates at least num process
        create_process();
    }

    report(std::cout);

    for(int i = 0; i < num; ++i){

        if(rand()%2 && !waiting.empty()){
            Process *p = *(waiting.begin());
            waiting.erase(waiting.begin());
            p->event_complete();
            ready.push(p);
            std::cout << "Process " << p->get_process_id() << " finished waiting" << std::endl;
        }

        Process *p = ready.front();
        ready.pop();
        p->scheduler_dispatch();
        p->report(std::cout);
        int opt = rand()%3;
        std::cout << "Operation: ";
        switch(opt){
            case 0:{// exit
                std::cout << "Exit\n";
                auto itr = std::find(all.begin(), all.end(), p);
                all.erase(itr);
                delete p;
                break;
            }
            case 1:{// event_wait
                std::cout << "Event Wait\n";
                p->event_wait();
                waiting.insert(p);
                break;
            }
            case 2:{// interrupt
                std::cout << "Interrupted\n";
                p->interrupt();
                ready.push(p);
                break;
            }
        }

        report(std::cout);
    }

}

int main(){
    Scheduler s;

    s.run(5);

    return 0;
}
