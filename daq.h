/*
 * daq.h
 *
 *  Created on: 6 Jan 2016
 *      Author: harpreet
 */

#ifndef DAQ_H_
#define DAQ_H_
#include "unit.h"

class daq : public unit
{
    private:
    bool bAcquired;

    doubleBuffer<int> *m_poInBuf;
    doubleBuffer<int> *m_poOutBuf;

    public:

    daq()
    {
    	bAcquired = false;
        //cout << "Data Acquisition started" << endl;
    }

    daq( unsigned int uValue, unsigned int uTime );

    void task ( void );

    void initBuf ( doubleBuffer<int> &oOutBuf );
};

#endif /* DAQ_H_ */
