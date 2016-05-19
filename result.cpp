/*
 * result.cpp
 *
 *  Created on: 6 Jan 2016
 *      Author: harpreet
 */
#include "result.h"

void result::task ( void )
{
	int value;
	int *ptr = m_poInBuf->start_reading();
	int read_index = m_poInBuf->get_read_index();

	if ( ptr )
	{
		value = *ptr;
		m_poInBuf->end_reading();

		LOG (INFO) << " reading index = " <<
				read_index << " value = " << value << endl;
	}
	else
	{
		LOG (INFO) << " buffer not available: sleep for 2 secs" << endl;
		sleep (2);
	}

}

void result::initBuf ( doubleBuffer<int> &oInBuf)
{
	m_poInBuf = &oInBuf;
	m_poOutBuf = &oInBuf;
}
