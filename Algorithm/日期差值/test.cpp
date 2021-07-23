# include <iostream>
class Date
{
    friend std::istream& operator>>(std::istream& in, Date& date);
public:
    int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			days[2] += 1;
		}

		return days[month];
	}
    Date(int year=0, int month=0, int day=0):_year(year),_month(month),_day(day)
    {}
    bool operator>(const Date& d)
    {
        if (_year > d._year)
        {
            return true;
        }
        else if (_year == d._year)
        {
            if (_month > d._month)
            {
                return true;
            }
            else if (_month == d._month)
            {
                if (_day > d._day)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool operator==(const Date& d)
    {
        return _year == d._year && _month == d._month && _day == d._day;
    }
    bool operator<(const Date& d)
    {
        return !((*this)>d || (*this)==d);
    }
    
    Date& operator++()
    {
        _day += 1;
        while (_day > GetMonthDay(_year, _month))
        {
            _day -= GetMonthDay(_year, _month);
            _month++;

            if (_month > 12)
            {
                _year++;
                _month = 1;
            }
        }
        return *this;
    }
    int operator-(const Date& d)
	{
		Date max = *this;
		Date min = d;
		int flag = 1;
		int n = 0;

		if (min > max)
		{
			max = d;
			min = *this;
			flag = -1;
		}

		while (min < max)
		{
			++min;
			n++;
		}
		
		return n * flag;
	}
private:
    int _year;
    int _month;
    int _day;
};
std::istream& operator>>(std::istream& in, Date& date)
{
    scanf("%4d%2d%2d", &date._year, &date._month, &date._day);
    return in;
}
int main()
{
    Date d1;
    Date d2;
    std::cin >> d1 >> d2;
    std::cout << abs(d1 - d2) + 1 <<std::endl;
    return 0;
}