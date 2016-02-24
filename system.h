#ifndef __SYSTEM_H__
#define __SYSTEM_H__
#include "daq.h"
#include "detector.h"
#include "result.h"


class system
{
    //private:
    daq aq;
    result res;
    detector detect;
    
    //public:
    //void create ( void );
};

/*
void system::create ( void )
{
    //cout << "task1 says: " << msg << endl;
	thread t1 ( task);
	//thread t2 ( res.task);
	//thread t3 ( detect.task);

	t1.join();
	//t2.join();
	//t3.join();
}*/
#endif
