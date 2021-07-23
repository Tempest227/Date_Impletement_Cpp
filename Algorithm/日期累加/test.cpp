# include <iostream>

static int dayArr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int GetMonthDay(int year, int month)
{
    if (month == 2 && 
        ((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0)))
    {
        return 29;
    }
    return dayArr[month];
}
int main()
{
    int m = 0;
    int addDay = 0;
    int year, month, day;
    
    std::cin >> m;
    
    while(m > 0)
    {
        std::cin >> year;
        std::cin >> month;
        std::cin >> day;
        std::cin >> addDay;
        day += addDay;
        while(day > GetMonthDay(year, month))
        {
            day -= GetMonthDay(year, month);
            month++;
            if (month > 12)
            {
                year++;
                month = 1;
            }
        }
        printf("%04d-%02d-%02d\n", year, month, day);
        m--;
    }
    return 0;
}