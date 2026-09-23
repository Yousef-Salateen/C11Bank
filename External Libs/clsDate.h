#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <string>
#include "clsString.h"
#include "clsInputValidate.h"

class clsDate
{
private:
    short _day, _month, _year;

public:
    clsDate(short day, short month, short year)
    {
        this->setDay(day);
        this->setMonth(month);
        this->setYear(year);

        if (!this->IsValidDate())
        {
            *this = clsDate();
            return;
        }
    }

    void setDay(short day)
    {
        if (!clsDate::IsValidDay(day, this->month(), this->year())) return;
        _day = day;
    }

    void setMonth(short month)
    {
        if (!clsDate::IsValidMonth(month)) return;

        _month = month;

        if (!this->IsValidDay()) setDay(this->DaysInMonth());
    }

    void setYear(short year)
    {
        _year = year;
        if (!this->IsValidDay()) setDay(this->DaysInMonth());
    }

    short day() const
    {
        return _day;
    }

    short month() const
    {
        return _month;
    }

    short year() const
    {
        return _year;
    }

    static bool IsLeapYear(short year)
    {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }

    bool IsLeapYear() const
    {
        return IsLeapYear(year());
    }

    static short DaysInYear(short year)
    {
        return IsLeapYear(year) ? 366 : 365;
    }

    short DaysInYear() const
    {
        return DaysInYear(year());
    }

    static short HoursInYear(short year)
    {
        return DaysInYear(year) * 24;
    }

    short HoursInYear() const
    {
        return HoursInYear(year());
    }

    static int MinutesInYear(short year)
    {
        return HoursInYear(year) * 60;
    }

    int MinutesInYear() const
    {
        return MinutesInYear(year());
    }

    static int SecondsInYear(short year)
    {
        return MinutesInYear(year) * 60;
    }

    int SecondsInYear() const
    {
        return SecondsInYear(year());
    }

    static short DaysInMonth(short month, short year)
    {
        if (month > 12 || month < 0) return 0;

        short Days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : Days[month - 1];
    }

    short DaysInMonth() const
    {
        return DaysInMonth(month(), year());
    }

    static short HoursInMonth(short month, short year)
    {
        return DaysInMonth(month, year) * 24;
    }

    short HoursInMonth() const
    {
        return HoursInMonth(month(), year());
    }

    static int MinutesInMonth(short month, short year)
    {
        return HoursInMonth(month, year) * 60;
    }

    int MinutesInMonth() const
    {
        return MinutesInMonth(month(), year());
    }

    static int SecondsInMonth(short month, short year)
    {
        return MinutesInMonth(month, year) * 60;
    }

    int SecondsInMonth() const
    {
        return SecondsInMonth(month(), year());
    }

    static short DayOrderInWeek(short day, short month, short year)
    {
        short a, y, m;

        a = (14 - month) / 12;
        y = year - a;
        m = month + 12 * a - 2;

        return (day + y + y / 4 - y / 100 + y / 400 + ((31 * m) / 12)) % 7;
    }

    short DayOrderInWeek() const
    {
        return DayOrderInWeek(day(), month(), year());
    }

    static std::string NameOfDayShort(short DayOrder)
    {
        std::string NamesOfDay[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

        return NamesOfDay[DayOrder];
    }

    std::string NameOfDayShort() const
    {
        return NameOfDayShort(this->DayOrderInWeek());
    }

    static std::string NameOfMonthShort(short MonthOrder)
    {
        std::string Names[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug",
        "Sep","Oct","Nov","Dec" };

        return Names[MonthOrder];
    }

    std::string NameOfMonthShort() const
    {
        return NameOfMonthShort(month() - 1);
    }

    static void PrintMonthCalender(short month, short year)
    {
        short MonthDays = DaysInMonth(month, year);

        std::cout << "\n____________" << NameOfMonthShort(month - 1) << "____________\n";
        std::cout << "Sun Mon Tue Wed Thu Fri Sat" << std::endl;

        short CurrentDay = DayOrderInWeek(1, month, year);

        for (short i = 0; i < CurrentDay; i++)
        {
            std::cout << "    ";
        }

        for (short i = 1; i <= MonthDays; i++)
        {
            std::cout << std::left << std::setw(2) << i << "  ";
            if (++CurrentDay % 7 == 0)
            {
                CurrentDay = 0;
                std::cout << "\n";
            }
        }

        std::cout << "\n___________________________\n";
    }

    void PrintMonthCalender() const
    {
        PrintMonthCalender(month(), year());
    }

    static void PrintYearCalender(short year)
    {
        for (short i = 1; i <= 12; i++)
        {
            PrintMonthCalender(i, year);
        }
    }

    void PrintYearCalender() const
    {
        PrintYearCalender(year());
    }

    static short DaysSpentFromYear(short day, short month, short year)
    {

        if (day > DaysInMonth(month, year))
        {
            return -1;
        }

        short DaysSpent = 0;
        for (short i = 1; i < month; i++)
        {
            DaysSpent += DaysInMonth(i, year);
        }

        DaysSpent += day;

        return DaysSpent;
    }

    short DaysSpentFromYear() const
    {
        return DaysSpentFromYear(day(), month(), year());
    }

    static bool IsLeapYear(const clsDate& date)
    {
        return date.IsLeapYear();
    }

    static short DaysInYear(const clsDate& date)
    {
        return date.DaysInYear();
    }

    static short HoursInYear(const clsDate& date)
    {
        return date.HoursInYear();
    }

    static int MinutesInYear(const clsDate& date)
    {
        return date.MinutesInYear();
    }

    static int SecondsInYear(const clsDate& date)
    {
        return date.SecondsInYear();
    }

    static short DaysInMonth(const clsDate& date)
    {
        return date.DaysInMonth();
    }

    static short HoursInMonth(const clsDate& date)
    {
        return date.HoursInMonth();
    }

    static int MinutesInMonth(const clsDate& date)
    {
        return date.MinutesInMonth();
    }

    static int SecondsInMonth(const clsDate& date)
    {
        return date.SecondsInMonth();
    }

    static short DayOrderInWeek(const clsDate& date)
    {
        return date.DayOrderInWeek();
    }

    static std::string NameOfDayShort(const clsDate& date)
    {
        return date.NameOfDayShort();
    }

    static std::string NameOfMonthShort(const clsDate& date)
    {
        return date.NameOfMonthShort();
    }

    static void PrintMonthCalender(const clsDate& date)
    {
        date.PrintMonthCalender();
    }

    static void PrintYearCalender(const clsDate& date)
    {
        date.PrintYearCalender();
    }

    static short DaysSpentFromYear(const clsDate& date)
    {
        return date.DaysSpentFromYear();
    }

    static clsDate DayInfo(short DayOrderInYear, short year)
    {
        clsDate date;

        date.setYear(year);
        date.setMonth(1);

        short MonthDays;
        while (DayOrderInYear > (MonthDays = DaysInMonth(date)))
        {
            DayOrderInYear -= MonthDays;
            date.setMonth(date.month() + 1);
        }

        date.setDay(DayOrderInYear);

        return date;
    }

    void DayInfo()
    {
        *this = DayInfo(this->DaysSpentFromYear(), year());
    }

    clsDate(short DayOrderInYear, short year)
    {
        clsDate date = clsDate::DayInfo(DayOrderInYear, year);

        if (date.IsValidDate())
            *this = date;
        else
            *this = clsDate();
    }

    static clsDate AddDays(short days, clsDate date)
    {
        short SpentDays = days + DaysSpentFromYear(date);
        short YearDays;

        while (SpentDays > (YearDays = DaysInYear(date)))
        {
            date.setYear(date.year() + 1);
            SpentDays -= YearDays;
        }

        date = DayInfo(SpentDays, date.year());

        return date;
    }

    void AddDays(short days)
    {
        *this = AddDays(days, *this);
    }

    static bool IsDate1BeforeDate2(const clsDate& date1, const clsDate& date2)
    {
        return (date1.year() < date2.year()) ? true : ((date1.year() == date2.year()) ? ((date1.month() < date2.month()) ? true :
            ((date1.month() == date2.month()) ? (date1.day() < date2.day()) : false)) : false);
    }

    bool IsDateBeforeDate2(const clsDate& date2) const
    {
        return IsDate1BeforeDate2(*this, date2);
    }

    static bool IsDate1EqualDate2(const clsDate& date1, const clsDate& date2)
    {
        return (date1.year() == date2.year()) ? ((date1.month() == date2.month()) ? (date1.day() == date2.day()) : false) : false;

    }

    bool IsDateEqualDate2(const clsDate& date2) const
    {
        return IsDate1EqualDate2(*this, date2);
    }

    static bool IsLastDayInMonth(const clsDate& date)
    {
        return date.day() == DaysInMonth(date);
    }

    bool IsLastDayInMonth() const
    {
        return IsLastDayInMonth(*this);
    }

    static clsDate IncreaseDateBy1Day(clsDate date)
    {
        if (IsLastDayInMonth(date))
        {
            date.setDay(1);
            if (date.month() == 12)
            {
                date.setMonth(1);
                date.setYear(date.year() + 1);
            }
            else
            {
                date.setMonth(date.month() + 1);
            }
        }
        else
        {
            date.setDay(date.day() + 1);
        }

        return date;
    }

    void IncreaseDateBy1Day()
    {
        *this = IncreaseDateBy1Day(*this);
    }

    static void SwapDates(clsDate& date1, clsDate& date2)
    {
        clsDate temp = date1;
        date1 = date2;
        date2 = temp;
    }

    void SwapDates(clsDate& date2)
    {
        SwapDates(*this, date2);
    }

    static int DayDiffBetweenDate(clsDate date1, clsDate date2, bool CountCurrentDay = false)
    {
        int DaysDiff = 0;
        short SwapFlag = 1;

        if (!IsDate1BeforeDate2(date1, date2))
        {
            SwapDates(date1, date2);
            SwapFlag = -1;
        }

        while (!IsDate1EqualDate2(date1, date2))
        {
            DaysDiff++;
            date1 = IncreaseDateBy1Day(date1);
        }

        return SwapFlag * (CountCurrentDay ? ++DaysDiff : DaysDiff);
    }

    int DayDiffBetweenDate(const clsDate& date2, bool CountCurrentDay = false)
    {
        return DayDiffBetweenDate(*this, date2, CountCurrentDay);
    }

    static clsDate GetSystemDate()
    {
        return clsDate();
    }

    static std::string GetSystemDateTimeString()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        short Day, Month, Year, Hour, Minute, Second;

        Year = now->tm_year + 1900;
        Month = now->tm_mon + 1;
        Day = now->tm_mday;
        Hour = now->tm_hour;
        Minute = now->tm_min;
        Second = now->tm_sec;

        return (std::to_string(Day) + "/" + std::to_string(Month) + "/"
            + std::to_string(Year) + " - "
            + std::to_string(Hour) + ":" + std::to_string(Minute)
            + ":" + std::to_string(Second));
    }

    clsDate()
    {
        time_t t = time(0);
        tm* CurrentDay = localtime(&t);

        _year = (CurrentDay->tm_year + 1900);
        _month = (CurrentDay->tm_mon + 1);
        _day = (CurrentDay->tm_mday);
    }

    static int AgeInDays(const clsDate& DateOfBirth)
    {
        return DayDiffBetweenDate(DateOfBirth, GetSystemDate());
    }

    int AgeInDays() const
    {
        return AgeInDays(*this);
    }

    static clsDate IncreaseDateByXDays(short days, clsDate date)
    {
        for (short i = 0; i < days; i++)
        {
            date = IncreaseDateBy1Day(date);
        }

        return date;
    }

    void IncreaseDateByXDays(short days)
    {
        *this = IncreaseDateByXDays(days, *this);
    }

    static clsDate IncreaseDateBy1Week(clsDate date)
    {
        date = IncreaseDateByXDays(7, date);

        return date;
    }

    void IncreaseDateBy1Week()
    {
        *this = IncreaseDateBy1Week(*this);
    }

    static clsDate IncreaseDateByXWeeks(short weeks, clsDate date)
    {
        for (short i = 0; i < weeks; i++)
        {
            date = IncreaseDateBy1Week(date);
        }

        return date;
    }

    void IncreaseDateByXWeeks(short weeks)
    {
        *this = IncreaseDateByXWeeks(weeks, *this);
    }

    static clsDate IncreaseDateBy1Month(clsDate date)
    {
        if (date.month() == 12)
        {
            date.setMonth(1);
            date.setYear(date.year() + 1);
        }
        else
        {
            date.setMonth(date.month() + 1);
        }

        return date;
    }

    void IncreaseDateBy1Month()
    {
        *this = IncreaseDateBy1Month(*this);
    }

    static clsDate IncreaseDateByXMonth(short months, clsDate date)
    {
        for (short i = 0; i < months; i++)
        {
            date = IncreaseDateBy1Month(date);
        }

        return date;
    }

    void IncreaseDateByXMonth(short months)
    {
        *this = IncreaseDateByXMonth(months, *this);
    }

    static clsDate IncreaseDateBy1Year(clsDate date)
    {
        date.setYear(date.year() + 1);
        return date;
    }

    void IncreaseDateBy1Year()
    {
        *this = IncreaseDateBy1Year(*this);
    }

    static clsDate IncreaseDateByXYears(short years, clsDate date)
    {
        date.setYear(date.year() + years);
        return date;
    }

    void IncreaseDateByXYears(short years)
    {
        *this = IncreaseDateByXYears(years, *this);
    }

    static clsDate IncreaseDateBy1Decade(clsDate date)
    {
        date = IncreaseDateByXYears(10, date);
        return date;
    }

    void IncreaseDateBy1Decade()
    {
        *this = IncreaseDateBy1Decade(*this);
    }

    static clsDate IncreaseDateByXDecades(short decades, clsDate date)
    {
        date = IncreaseDateByXYears(decades * 10, date);
        return date;
    }

    void IncreaseDateByXDecades(short years)
    {
        *this = IncreaseDateByXDecades(years, *this);
    }

    static clsDate IncreaseDateBy1Century(clsDate date)
    {
        date.setYear(date.year() + 100);
        return date;
    }

    void IncreaseDateBy1Century()
    {
        *this = IncreaseDateBy1Century(*this);
    }

    static clsDate IncreaseDateBy1Millenia(clsDate date)
    {
        date.setYear(date.year() + 1000);
        return date;
    }

    void IncreaseDateBy1Millenia()
    {
        *this = IncreaseDateBy1Millenia(*this);
    }

    static clsDate DecreaseDateBy1Day(clsDate date)
    {
        if (date.day() == 1)
        {
            if (date.month() == 1)
            {
                date.setDay(31);
                date.setMonth(12);
                date.setYear(date.year() - 1);
            }
            else
            {
                date.setMonth(date.month() - 1);
                date.setDay(date.DaysInMonth());
            }
        }
        else
        {
            date.setDay(date.day() - 1);
        }

        return date;
    }

    void DecreaseDateBy1Day()
    {
        *this = DecreaseDateBy1Day(*this);
    }

    static clsDate DecreaseDateByXDays(short days, clsDate date)
    {
        for (short i = 0; i < days; i++)
        {
            date = DecreaseDateBy1Day(date);
        }

        return date;
    }

    void DecreaseDateByXDays(short days)
    {
        *this = DecreaseDateByXDays(days, *this);
    }

    static clsDate DecreaseDateBy1Week(clsDate date)
    {
        date = DecreaseDateByXDays(7, date);

        return date;
    }

    void DecreaseDateBy1Week()
    {
        *this = DecreaseDateBy1Week(*this);
    }

    static clsDate DecreaseDateByXWeeks(short weeks, clsDate date)
    {
        for (short i = 0; i < weeks; i++)
        {
            date = DecreaseDateBy1Week(date);
        }

        return date;
    }

    void DecreaseDateByXWeeks(short weeks)
    {
        *this = DecreaseDateByXWeeks(weeks, *this);
    }

    static clsDate DecreaseDateBy1Month(clsDate date)
    {
        if (date.month() == 1)
        {
            date.setMonth(12);
            date.setYear(date.year() - 1);
        }
        else
        {
            date.setMonth(date.month() - 1);
        }

        return date;
    }

    void DecreaseDateBy1Month()
    {
        *this = DecreaseDateBy1Month(*this);
    }

    static clsDate DecreaseDateByXMonth(short months, clsDate date)
    {
        for (short i = 0; i < months; i++)
        {
            date = DecreaseDateBy1Month(date);
        }

        return date;
    }

    void DecreaseDateByXMonth(short months)
    {
        *this = DecreaseDateByXMonth(months, *this);
    }

    static clsDate DecreaseDateBy1Year(clsDate date)
    {
        date.setYear(date.year() - 1);
        return date;
    }

    void DecreaseDateBy1Year()
    {
        *this = DecreaseDateBy1Year(*this);
    }

    static clsDate DecreaseDateByXYears(short years, clsDate date)
    {
        date.setYear(date.year() - years);
        return date;
    }

    void DecreaseDateByXYears(short years)
    {
        *this = DecreaseDateByXYears(years, *this);
    }

    static clsDate DecreaseDateBy1Decade(clsDate date)
    {
        date = IncreaseDateByXYears(10, date);
        return date;
    }

    void DecreaseDateBy1Decade()
    {
        *this = DecreaseDateBy1Decade(*this);
    }

    static clsDate DecreaseDateByXDecades(short decades, clsDate date)
    {
        date = DecreaseDateByXYears(decades * 10, date);
        return date;
    }

    void DecreaseDateByXDecades(short decades)
    {
        *this = DecreaseDateByXDecades(decades, *this);
    }

    static clsDate DecreaseDateBy1Century(clsDate date)
    {
        date.setYear(date.year() - 100);
        return date;
    }

    void DecreaseDateBy1Century()
    {
        *this = DecreaseDateBy1Century(*this);
    }

    static clsDate DecreaseDateBy1Millenia(clsDate date)
    {
        date.setYear(date.year() - 1000);
        return date;
    }

    void DecreaseDateBy1Millenia()
    {
        *this = DecreaseDateBy1Millenia(*this);
    }

    static bool IsEndOfWeek(const clsDate& date)
    {
        return date.DayOrderInWeek() == 6;
    }

    bool IsEndOfWeek() const
    {
        return IsEndOfWeek(*this);
    }

    static bool IsWeekEnd(const clsDate& date)
    {
        short DayOrder = date.DayOrderInWeek();
        return DayOrder == 5 || DayOrder == 6;
    }

    bool IsWeekEnd() const
    {
        return IsWeekEnd(*this);
    }

    static bool IsBusinessDay(const clsDate& date)
    {
        return !date.IsWeekEnd();
    }

    bool IsBusinessDay() const
    {
        return IsBusinessDay(*this);
    }

    static short DaysUntilEndOfWeek(const clsDate& date)
    {
        return 6 - date.DayOrderInWeek();
    }

    short DaysUntilEndOfWeek() const
    {
        return DaysUntilEndOfWeek(*this);
    }

    static short DaysUntilEndOfMonth(const clsDate& date)
    {
        return date.DaysInMonth() - date.day();
    }

    short DaysUntilEndOfMonth() const
    {
        return DaysUntilEndOfMonth(*this);
    }

    static short DaysUntilEndOfYear(const clsDate& date)
    {
        return date.DaysInYear() - date.DaysSpentFromYear();
    }

    short DaysUntilEndOfYear() const
    {
        return DaysUntilEndOfYear(*this);
    }

    static short VacationDays(clsDate From, clsDate To)
    {
        short Vacation = 0;

        while (From.IsDateBeforeDate2(To))
        {
            if (From.IsBusinessDay())
            {
                Vacation++;
            }
            From.IncreaseDateBy1Day();
        }

        return Vacation;
    }

    short VacationDaysUntil(const clsDate& date)
    {
        return VacationDays(*this, date);
    }

    static clsDate ReturnDay(clsDate From, short days)
    {
        while (From.IsWeekEnd())
        {
            From.IncreaseDateBy1Day();
        }

        while (days > 0)
        {
            if (From.IsBusinessDay())
                days--;
            From.IncreaseDateBy1Day();
        }

        while (From.IsWeekEnd())
        {
            From.IncreaseDateBy1Day();
        }

        return From;
    }

    void DayOfReturn(short days)
    {
        *this = ReturnDay(*this, days);
    }

    static bool IsDate1AfterDate2(const clsDate& date1, const clsDate& date2)
    {
        return !date1.IsDateBeforeDate2(date2) && !date1.IsDateEqualDate2(date2);
    }

    bool IsDateAfterDate2(const clsDate& date2) const
    {
        return IsDate1AfterDate2(*this, date2);
    }

    enum enDateComparsion { Before = -1, Equal = 0, After = 1 };

    static enDateComparsion CompareDates(const clsDate& date1, const clsDate& date2)
    {
        return date1 >date2 ? enDateComparsion::Before :
            date1 == date2 ? enDateComparsion::Equal : enDateComparsion::After;
    }

    enDateComparsion CompareDates(const clsDate& date2) const
    {
        return CompareDates(*this, date2);
    }

    static bool IsValidDay(short day, short month, short year)
    {
        return clsInputValidate::IsBetween<short>(day, 1, DaysInMonth(month, year));
    }

    static bool IsValidDay(const clsDate& date)
    {
        return IsValidDay(date.day(), date.month(), date.year());
    }

    bool IsValidDay() const
    {
        return IsValidDay(*this);
    }

    static bool IsValidMonth(short month)
    {
        return clsInputValidate::IsBetween<short>(month, 1, 12);
    }

    static bool IsValidMonth(const clsDate& date)
    {
        return IsValidMonth(date.month());
    }

    bool IsValidMonth() const
    {
        return IsValidMonth(*this);
    }

    static bool IsValidDate(const clsDate& date)
    {
        if (!date.IsValidMonth()) return false;
        if (!date.IsValidDay()) return false;

        return true;
    }

    bool IsValidDate() const
    {
        return IsValidDate(*this);
    }

    static std::string DateToString(const clsDate& date)
    {
        std::string DateString = "";

        DateString.append(std::to_string(date.day()) + "/");
        DateString.append(std::to_string(date.month()) + "/");
        DateString.append(std::to_string(date.year()));

        return DateString;
    }

    std::string DateToString() const
    {
        return DateToString(*this);
    }

    static clsDate StringToDate(const std::string& DateString)
    {
        std::vector <std::string> vDate = clsString::Split(DateString, "/");

        short day = stoi(vDate[0]);
        short month = stoi(vDate[1]);
        short year = stoi(vDate[2]);

        return clsDate(day, month, year);
    }

    clsDate(const std::string& DateString)
    {
        *this = StringToDate(DateString);
    }

    static std::string FormatDate(const clsDate& date, const std::string& Format = "dd/mm/yyyy")
    {
        std::string FormattedDate = "";

        FormattedDate = clsString::ReplaceWord(Format, "dd", std::to_string(date.day()));
        FormattedDate = clsString::ReplaceWord(FormattedDate, "mm", std::to_string(date.month()));
        FormattedDate = clsString::ReplaceWord(FormattedDate, "yyyy", std::to_string(date.year()));

        return FormattedDate;
    }

    std::string FormatDate(const std::string& Format = "dd/mm/yyyy") const
    {
        return FormatDate(*this, Format);
    }

    static clsDate ReadDate()
    {
        short day = clsInputValidate::Read<int>("day: ");
        short month = clsInputValidate::Read<int>("month: ");
        short year = clsInputValidate::Read<int>("year: ");

        return clsDate(day, month, year);
    }

    bool operator> (const clsDate& date) const
    {
        return this->IsDateAfterDate2(date);
    }

    bool operator< (const clsDate& date) const
    {
        return this->IsDateBeforeDate2(date);
    }

    bool operator== (const clsDate& date) const
    {
        return this->IsDateEqualDate2(date);
    }

    bool operator<= (const clsDate& date) const
    {
        return *this < date || *this == date;
    }

    bool operator>= (const clsDate& date) const
    {
        return *this > date || *this == date;
    }

    friend std::ostream& operator<< (std::ostream& stream, const clsDate& date)
    {
        stream << date.FormatDate();
        return stream;
    }

    friend std::istream& operator>> (std::istream& stream, clsDate& date)
    {
        short day, month, year;
        if (stream >> day >> month >> year)
        {
            date = clsDate(day, month, year);
        }
        return stream;
    }
};