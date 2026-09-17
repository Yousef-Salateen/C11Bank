#pragma once
#include "clsDate.h"

class clsPeriod
{
private:
	clsDate _start, _end;
public:

    clsPeriod()
    {
        _start = clsDate();
        _end = clsDate();
    }

    clsPeriod(const clsDate& start, const clsDate& end)
    {
        this->setStart(start);
        this->setEnd(end);

        if (start.IsDateAfterDate2(end)) clsDate::SwapDates(this->_start, this->_end);
    }

    clsDate start() const
    {
        return _start;
    }

    clsDate end() const
    {
        return _end;
    }

    void setStart(const clsDate& start)
    {
        _start = start;
    }

    void setEnd(const clsDate& end)
    {
        _end = end;
    }

    static bool IsPeriodOverlap(const clsPeriod& period1, const clsPeriod& period2)
    {
        clsDate::enDateComparsion Start1End2 = clsDate::CompareDates(period1.start(), period2.end());
        clsDate::enDateComparsion End1Start2 = clsDate::CompareDates(period1.end(), period2.start());

        return !(End1Start2 == clsDate::enDateComparsion::Before || Start1End2 == clsDate::enDateComparsion::After);
    }

    bool IsPeriodOverlap(const clsPeriod& period2) const
    {
        return IsPeriodOverlap(*this, period2);
    }

    static short PeriodLengthInDays(const clsPeriod& period, bool IncludeEndDate = false)
    {
        return clsDate::DayDiffBetweenDate(period.start(), period.end(), IncludeEndDate);
    }

    short PeriodLengthInDays(bool IncludeEndDate = false) const
    {
        return PeriodLengthInDays(*this, IncludeEndDate);
    }

    static bool IsDateWithinPeriod(const clsDate& date, const clsPeriod& period)
    {
        return !(date.CompareDates(period.start()) == clsDate::enDateComparsion::Before || date.CompareDates(period.end()) == clsDate::enDateComparsion::After);
    }

    bool IsDateWithinPeriod(const clsDate& date) const
    {
        return IsDateWithinPeriod(date, *this);
    }

    static short OverlapDays(clsPeriod period1, clsPeriod period2)
    {
        if (!period1.IsPeriodOverlap(period2)) return 0;

        short Period1Length = period1.PeriodLengthInDays();
        short Period2Length = period2.PeriodLengthInDays();
        short days = 0;

        if (Period1Length < Period2Length)
        {
            while (clsDate::IsDate1BeforeDate2(period1.start(), period1.end()))
            {
                if (period2.IsDateWithinPeriod(period1.start()))
                {
                    days++;
                }
                period1.setStart(clsDate::IncreaseDateBy1Day(period1.start()));
            }
        }
        else
        {
            while (clsDate::IsDate1BeforeDate2(period2.start(), period2.end()))
            {
                if (period1.IsDateWithinPeriod(period2.start()))
                {
                    days++;
                }
                period2.setStart(clsDate::IncreaseDateBy1Day(period2.start()));
            }
        }
        return days;
    }

    short OverlapDays(const clsPeriod& period) const
    {
        return OverlapDays(*this, period);
    }

    static clsPeriod ReadPeriod()
    {
        clsPeriod period;

        std::cout << "Start of date: \n";
        period.setStart(clsDate::ReadDate());
        std::cout << std::endl;

        std::cout << "End of date: \n";
        period.setEnd(clsDate::ReadDate());
        std::cout << std::endl;

        return period;

    }
};