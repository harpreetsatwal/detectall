/*
 * detector1.h
 *
 *  Created on: 6 Jan 2016
 *      Author: harpreet
 */

#ifndef DETECTOR_H_
#define DETECTOR_H_
#include "unit.h"

class detector : public unit
{
    private:
    bool bdetection;
    doubleBuffer<int> *m_poInBuf;
    doubleBuffer<int> *m_poOutBuf;

    public:

    void task ( void );
    void initBuf ( doubleBuffer<int> &oInBuf, doubleBuffer<int> &oOutBuf);
};



#endif /* DETECTOR_H_ */
