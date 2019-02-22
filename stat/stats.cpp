// Provided by:   ____________Mingzhi Xu__________
// Email Address: ____________mxu000@citymail.cuny.edu________
// FILE: stats.cpp

#include <assert.h>
#include "stats.h"
namespace main_savitch_2C
{
    statistician::statistician()
    {
        count = 0;
        total = 0;
        tinyest = 0;
        largest = 0;
    }
    void statistician::next(double r)
    {
        count++;
        if(count == 1)
        {
            tinyest = r;
            largest = r;
        }
        else
        {
            if(r < tinyest)
            {
                tinyest = r;
            }
            if(r > largest)
            {
                largest = r;
            }
        }
        total += r;
    }
    void statistician::reset()
    {
        count = 0;
        total = 0;
        tinyest = 0;
        largest = 0;
    }
    int statistician::length() const
    {
        return count;
    }
    double statistician::sum() const
    {
        return total;
    }
    double statistician::mean() const
    {
        assert(length() > 0);
        return total / count;
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
        if (s1.length( ) == 0)  return s2;
        if (s2.length( ) == 0)  return s1;
        statistician s3;
        s3.count = s1.length() + s2.length();
        s3.total = s1.sum() + s2.sum();
        double s1min, s1max, s2min, s2max;
        s1min = s1.minimum();
        s1max = s1.maximum();
        s2min = s2.minimum();
        s2max = s2.maximum();
        if(s1min < s2min) { s3.tinyest = s1min; }
        else { s3.tinyest = s2min; }
        if(s1max > s2max) { s3.largest = s1max; }
        else { s3.largest = s2max; }
        return s3;
    }
    statistician operator *(double scale, const statistician& s)
    {
        if(s.length() == 0) return s;
        statistician t;
        t.count = s.length();
        t.total = s.sum() * scale;
        int tiny = s.minimum() * scale;
        int large = s.maximum() * scale;
        if(tiny > large)
        {
            t.tinyest = large;
            t.largest = tiny;
        }
        else
        {
            t.tinyest = tiny;
            t.largest = large;
        }
        return t;
    }
    bool operator ==(const statistician& s1, const statistician& s2)
    {
        if(s1.length() == 0 && s2.length() == 0) return true;
        if(s1.length() != s2.length()) return false;
        if((s1.mean() == s2.mean()) && (s1.sum() == s2.sum()) && (s1.minimum() == s2.minimum()) && (s1.maximum() == s2.maximum())) return true;
        else return false;
    }
}
