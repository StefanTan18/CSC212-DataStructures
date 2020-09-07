// FILE: stats.cpp
// CLASS IMPLEMENTED: statistician  (See stats.h for documentation.)

#include <iostream>
#include <math.h>
#include "stats.h"
using namespace std;

namespace main_savitch_2C
{
    statistician::statistician()
    {
        count = 0;
        total = 0;
    }

    void statistician::next(double r)
    {
        if (count == 0) {
            tinyest = r;
            largest = r;
        }
        else {
            if (r < tinyest) {
                tinyest = r;
            }
            else if (r > largest) {
                largest = r;
            }
        }
        count++;
        total += r;
    }

    void statistician::reset()
    {
        //CODE HERE
        count = 0;
        total = 0;
        tinyest = 0;
        largest = 0;
    }

    double statistician::mean() const
    {
        assert(length() > 0);
        return sum()/length();
    }

    double statistician::minimum() const
    {
        assert(length() > 0);
        return tinyest;
    }

    double statistician::maximum() const
    {
        assert(length() > 0);
        return largest;
    }

    statistician operator +(const statistician& s1, const statistician& s2)
    {
        if (s1.length() == 0) {
            return s2;
        }
        if (s2.length() == 0) {
            return s1;
        }
        statistician result;
        result.count = s1.length() + s2.length();
        result.total = s1.sum() + s2.sum();
        if (s1.minimum() < s2.minimum()) {
            result.tinyest = s1.minimum();
        }
        else {
            result.tinyest = s2.minimum();
        }
        if (s1.maximum() > s2.maximum()) {
            result.largest = s1.maximum();
        }
        else {
            result.largest = s2.maximum();
        }
        return result;
    }

    statistician operator *(double scale, const statistician& s)
    {
        statistician result;
        result.count = s.length();
        result.total = scale * s.sum();
        if (scale >= 0) {
            result.tinyest = scale * s.minimum();
            result.largest = scale * s.maximum();
        }
        else {
            result.tinyest = scale * s.maximum();
            result.largest = scale * s.minimum();
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