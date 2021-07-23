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
    int year, month = 0, day = 0;
    
    int n = 0;
    while(std::cin >> year >> n)
    {
        day += n;
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
        day = 0;
        month = 1;
    }
    
    return 0;
}