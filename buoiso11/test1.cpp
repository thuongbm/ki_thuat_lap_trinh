#include<stdio.h>
#include<stdbool.h>
#include <math.h>

typedef struct {
    int hour;
    int minute;
    int second;
} Time;

typedef struct {
    int year;
    int month;
    int day;
} Date;

//Ham nhap
void inputTime(Time *t, int hour, int minute, int second){
    t->hour = hour;
    t->minute = minute;
    t->second = second;
}
//Ham hien thi
void displayTime(Time t){
    printf("%02d:%02d:%02d\n", t.hour,t.minute,t.second);
}
//Ham cong thoi gian
void updateTime(Time *t, int addHour, int addMinute, int addSecond){
  
    t->second += addSecond;
    t->minute += t->second/60;
    t->second %= 60;

    t->minute += addMinute;
    t->hour += t->minute/60;
    t->minute %= 60;

    t->hour += addHour;
    t->hour %=24;
}

//Ham kiem tra hop le
bool isvalidTime(Time t){
    return  (t.hour >= 0 && t.hour < 24) &&  
            (t.minute >= 0 && t.minute < 60) &&
            (t.second >= 0 && t.second < 60);
}

//Ham nhap ngay
void inputDate(Date *d, int day, int month, int year){
    d->day = day;
    d->month = month;
    d->year = year;
}

//Ham hien thi
void displayDate(Date d){
    printf("%02d/%02d/%02d\n", d.day,d.month,d.year);
}

//Ham kiem tra nam nhuan
bool isgapYear(int year){
    if ((year % 4 == 0) && (year % 100 != 0)) return true;
    if(year % 400 == 0) return true;
    return false;
}

//lay ra ngay trong thang
int dayOfMonth(int m, int y)
{
    int a[] = {1,3,5,7,8,10,12};
    for(int i = 0; i < 7; i++)
    {
        if(m == a[i]) return 31;
    }
    if(m == 2)
    {
        if(isgapYear(y)) return 29;
        return 28;
    }
    return 30;
}

//Ham kiem tra hop le
bool isValid(Date d)
{
    if(d.day < 0 || d.day > dayOfMonth(d.month, d.year)
    || d.month < 0 || d.month > 12 
    || d.year < 0 || d.year > 9999) return false;
    return true;
}

//ham cong ngay
void addDate(Date *d, int addDay, int addMonth, int addYear)
{
    d->day += addDay;
    d->month += addMonth + d->day/dayOfMonth(d->month, d->year);
    d->day %= dayOfMonth(d->month, d->year);

    d->year += addYear + d->month/12;
    d->month %= 11;
}

//doi date sang day
int dateToDay(Date d)
{
    int res = 0;
    for(int i = 0; i < d.year; i++)
    {
        if(isgapYear(d.year)) res += 366;
        else res += 365;
    }
    for(int i = 0; i < d.month; i++)
    {
        res += dayOfMonth(d.month, d.year);
    }
    return res + d.day;
}

//tinh so ngay khoang cach
int dateDif(Date d1, Date d2)
{
    int a = dateToDay(d1);
    int b = dateToDay(d2);
    return abs(a-b);
}


int main(){
    Time t;
    inputTime(&t, 10,9,40);
    if (isvalidTime(t)){
        displayTime(t);
        updateTime(&t, 1,2,20);
        displayTime(t);
    }else {
        printf("Nhap thoi gian khong hop le!");
    }
    
    Date day1, day2;
    inputDate(&day1, 30, 07, 2005);
    displayDate(day1);
    addDate(&day1, 10, 4, 1);
    printf("sau khi them ngay: ");
    displayDate(day1);
    inputDate(&day2, 20, 6, 2024);
    printf("khoang cach giua 2 ngay: %d\n", dateDif(day1, day2));
}




