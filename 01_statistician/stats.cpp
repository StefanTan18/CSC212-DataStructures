// FILE: stats.cpp
// CLASS IMPLEMENTED: statistician  (See stats.h for documentation.)

#include <iostream>
#include "stats.h"
using namespace std;

namespace main_savitch_2C
{
    statistician::statistician()
    {
        reset();
    }

    void statistician::next(double r)
    {
        if (m_count == 0) {
            m_tinyest = r;
            m_largest = r;
        }
        else {
            if (r < m_tinyest) {
                m_tinyest = r;
            }
            else if (r > m_largest) {
                m_largest = r;
            }
        }
        m_count++;
        m_total += r;
    }

    void statistician::reset()
    {
        m_count = 0;
        m_total = 0;
    }

    int statistician::length() const
    {
        return m_count;
    }

    double statistician::sum() const
    {
        return m_total;
    }

    double statistician::mean() const
    {
        assert(length() > 0);   // Makes sure statistician is not empty
        return sum()/length();
    }

    double statistician::minimum() const
    {
        assert(length() > 0);   // Makes sure statistician is not empty
        return m_tinyest;
    }

    double statistician::maximum() const
    {
        assert(length() > 0);   // Makes sure statistician is not empty
        return m_largest;
    }

    statistician operator +(const statistician& s1, const statistician& s2)
    {
        // Returns the other statistician object if one of them is empty
        if (s1.length() == 0) {
            return s2;
        }
        if (s2.length() == 0) {
            return s1;
        }
        statistician result;
        result.m_count = s1.length() + s2.length();
        result.m_total = s1.sum() + s2.sum();
        if (s1.minimum() < s2.minimum()) {
            result.m_tinyest = s1.minimum();
        }
        else {
            result.m_tinyest = s2.minimum();
        }
        if (s1.maximum() > s2.maximum()) {
            result.m_largest = s1.maximum();
        }
        else {
            result.m_largest = s2.maximum();
        }
        return result;
    }

    statistician operator *(double scale, const statistician& s)
    {
        if (s.length() == 0) {
            return s;
        }
        statistician result;
        result.m_count = s.length();
        result.m_total = scale * s.sum();
        if (scale >= 0) {
            result.m_tinyest = scale * s.minimum();
            result.m_largest = scale * s.maximum();
        }
        else {
            result.m_tinyest = scale * s.maximum();
            result.m_largest = scale * s.minimum();
        }
        return result;
    }

    bool operator ==(const statistician& s1, const statistician& s2) 
    {
        if (s1.length() == 0 && s2.length() == 0) {
            return true;
        }
        else if (s1.length() == 0 || s2.length() == 0) {
            return false;
        }
        return
        (s1.length() == s2.length())
        &&
        (s1.sum() == s2.sum())
        &&
        (s1.minimum() == s2.minimum())
        &&
        (s1.maximum() == s2.maximum());
    }

}