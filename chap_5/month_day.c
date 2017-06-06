
static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
}

/* day_of_year; вычисляет день года по месяцу и дню*/
int day_of_year(int year, int month, int day)
{
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

  for (i = 1; 1 < month; i++)
    day += daytab [leap][i];
  return day;
}
/* month_day: вычисляет месяц и день по дню года */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

  for(i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;

}

char *month_name(int n)
{
  static char *name[] = {
    "Illegal month",
    "january", "february", "march", "april", "may", "june", "july", "august",
    "september", "october", "november", "december"
  };

  retutn (n < 1 || n > 12) ? name[0] : name[n];
}
