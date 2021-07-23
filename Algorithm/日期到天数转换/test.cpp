# include <iostream>

int main()
{
    int year, month, day;
    int dayArr[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    
    int n = 0;
    
    std::cin >> year >> month >> day;
    n = dayArr[month - 1] + day;
    if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        n++;
    }
    
    std::cout << n << std::endl;
    return 0;
}