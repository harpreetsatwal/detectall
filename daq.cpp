/*
 * daq.cpp
 *
 *  Created on: 6 Jan 2016
 *      Author: harpreet
 */

#include "daq.h"
/*
Data acquisition class.
How to acquire data and issues related to it.
*/

void daq::task ( void )
{
	int *ptr = m_poOutBuf->start_writing();
	int write_index = m_poOutBuf->get_write_index();
	int value = write_index * 99;
	if ( ptr )
	{
		*ptr = value;
		m_poOutBuf->end_writing();

		LOG (INFO) <<" writing index = "
				<< write_index << " value = " << value;
	}
	else
	{
		LOG (INFO) << "buffer not available: sleep for 2 secs";
		sleep (2);
	}
}

void daq::initBuf ( doubleBuffer<int> &oOutBuf )
{
	m_poInBuf = &oOutBuf;
	m_poOutBuf = &oOutBuf;
}
