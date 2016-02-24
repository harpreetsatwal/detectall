/*
 * detector1.cpp
 *
 *  Created on: 6 Jan 2016
 *      Author: harpreet
 */
#include "detector.h"

void detector::task ( void )
{
	int value;
	int *ptr = m_poInBuf->start_reading();
	int read_index = m_poInBuf->get_read_index();

	if ( ptr )
	{
		value = *ptr;
		m_poInBuf->end_reading();

		cout << __PRETTY_FUNCTION__<<":" <<" reading index = " <<
				read_index << " value = " << value << endl;
	}
	else
	{
		cout << __PRETTY_FUNCTION__<<": buffer not available: sleep for 2 secs" << endl;
		sleep (2);
	}

	ptr = m_poOutBuf->start_writing();
	int write_index = m_poOutBuf->get_write_index();
	if ( ptr )
	{
		*ptr = value;
		m_poOutBuf->end_writing();

		cout << __PRETTY_FUNCTION__<<":" <<" writing index = "
				<< write_index << " value = " << value << endl;
	}
	else
	{
		cout << __PRETTY_FUNCTION__<<": buffer not available: sleep for 2 secs" << endl;
		sleep (2);
	}

}

void detector::initBuf ( doubleBuffer<int> &oInBuf, doubleBuffer<int> &oOutBuf)
{
	m_poInBuf = &oInBuf;
	m_poOutBuf = &oOutBuf;
}
