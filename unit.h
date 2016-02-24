/*
 * thread.h
 *
 *  Created on: 6 Jan 2016
 *      Author: harpreet
 */

#ifndef UNIT_H__
#define UNIT_H__
#include <iostream>
#include <thread>
#include <unistd.h>
#include <assert.h>

#include "data.h"

using namespace std;

class unit
{


    public:

    virtual void task ( void ) = 0;
    void worker ( void )
    {
    	while ( 1 )
    	{
    		//sleep ( 1 );
    		task();
    	}
    }
    thread createThread() {
        return thread([=] { worker(); });
    }

};


#endif /* UNIT_H__ */
