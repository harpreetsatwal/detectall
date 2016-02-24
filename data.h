#ifndef __DATA_H__
#define __DATA_H__
#include <iostream>
#include <mutex>

using namespace std;

/*
Data acquisition class.
How to acquire data and issues related to it.
*/
#if 0
struct data
{
    private:
    unsigned int uData;
    unsigned int uTimeStamp;
    bool bChecked;
    
    public:
    
    bool isChecked (void);
    unsigned int getTimeStamp (void);
    unsigned int getData (void);
    
    void setChecked (void);
    void setTimeStamp (unsigned int);
    void setData (unsigned int);
};
#endif

#define MAX_BUFFER_SIZE 2

template <typename T> class doubleBuffer
{

private:
    T m_buf[MAX_BUFFER_SIZE];
    bool m_data_valid [MAX_BUFFER_SIZE];
    bool m_write_busy;
    unsigned int m_read_idx, m_write_idx;
    mutex m_mutex;

public:
	doubleBuffer()
	{
        m_write_busy = false;
        m_read_idx = 0;
        m_write_idx = 0;

        for ( int indx = 0; indx < MAX_BUFFER_SIZE; indx++ )
        	m_data_valid[indx] = false;
    }

    ~doubleBuffer() { }

    // The writer thread using this class must call
    // start_writing() at the start of its iteration
    // before doing anything else to get the pointer
    // to the current write buffer.
    T * start_writing(void)
    {
        lock_guard<mutex> lock(m_mutex);

        //m_write_idx = 1 - m_read_idx;

        if ( !m_data_valid [m_write_idx] )
        {
            //m_write_busy = true;
        	return &m_buf[m_write_idx];
        }
        else
        {
        	return 0;
        }
    }
    // The writer thread must call end_writing()
    // as the last thing it does
    // to release the write busy flag.
    void end_writing(void)
    {
        lock_guard<mutex> lock(m_mutex);

        //m_write_busy = false;

        // data is now valid to read
        m_data_valid [m_write_idx] = true;
        // move to next buffer
        m_write_idx = 1 - m_write_idx;
    }

    // The reader thread must call start_reading()
    // at the start of its iteration to get the pointer
    // to the current read buffer.
    // If the write thread is not active at this time,
    // the read buffer pointer will be set to the
    // (previous) write buffer - so the reader gets the latest data.
    // If the write buffer is busy, the read pointer is not changed.
    // In this case the read buffer may contain stale data,
    // it is up to the user to deal with this case.
    T * start_reading(void)
    {
        lock_guard<mutex> lock(m_mutex);

        //if (!m_write_busy) {
        //    m_read_idx = m_write_idx;
        //}

        if ( m_data_valid [m_read_idx] )
            return &m_buf[m_read_idx];
        else
        	return 0;
    }
    // The reader thread must call end_reading()
    // at the end of its iteration.
    void end_reading(void)
    {
        lock_guard<mutex> lock(m_mutex);
        m_data_valid [m_read_idx] = false;
        //m_read_idx = m_write_idx;
        // move to next buffer
        m_read_idx = 1 - m_read_idx;
    }

    unsigned int get_write_index(void)
    {
        return m_write_idx;
    }


    unsigned int get_read_index(void)
    {
        return m_read_idx;
    }
};
#endif
