/*
 * result.h
 *
 *  Created on: 6 Jan 2016
 *      Author: harpreet
 */

#ifndef RESULT_H_
#define RESULT_H_
#include "unit.h"

class result : public unit
{
    private:
    bool bResultsAvailable;
    doubleBuffer<int> *m_poInBuf;
    doubleBuffer<int> *m_poOutBuf;

    public:
    void task ( void );
    void initBuf ( doubleBuffer<int> &oInBuf);
};



#endif /* RESULT_H_ */
