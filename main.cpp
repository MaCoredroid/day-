#include <iostream>

using namespace std;
int monthly(int a,int b)
{
    switch(a)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
        if (b%400==0||(b%4==0&&b%100!=0))
            return 29;
        else
            return 28;
        break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    default:
        return 0;
    }
}




int main()
{
    int a,b,year,month,day;
    cin>>a>>b;
    year=a/10000;
    month=(int(a%10000))/100;
    day=a%100;
    b=b-(monthly(month,year)-day);
    month++;
    for(; month<=12; month++)
    {
        b=b-monthly(month,year);
    }
    year++;
    for(; b>0; year++ )
    {
        b-=365;

        if(year%400==0||(year%4==0&&year%100!=0))
            b--;
    }
    year--;
    if(b>=-31)
    {
        month=12;
        day=b+31;
    }
    else
    {
        for(month=12; b<0; month--)
        {
            b=b+monthly(month,year);
        }
        day=b;
        month++;
    }
    if(month>12)
    {
        year++;
        month=1;
    }
    for(int i=0; i<3; i++)
    {
        if(day>monthly(month,year))
        {
            month++;
            day-=monthly(month,year);
        }
    }
    if(year>9999)
        cout<<"out of limitation!";
    else if(year>999)
        cout<<10000*year+100*month+day;

    else if(year>99)
        cout<<'0'<<10000*year+100*month+day;
    else if(year>9)
        cout<<"00"<<10000*year+100*month+day;
    else if(year>0)
        cout<<"000"<<10000*year+100*month+day;


}
