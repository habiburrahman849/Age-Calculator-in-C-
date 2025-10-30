#include <iostream>
#include <graphics.h>

using namespace std;

struct Age {
  int years;
  int months;
  int weeks;
  int days;
  int hours;
  int minutes;
  int seconds;
};

Age calculateAge(int birthYear, int birthMonth, int birthDay) {
  time_t now = time(0);
  tm *ltm = localtime(&now);

  Age age;
  age.years = ltm->tm_year - birthYear + 1;
  age.months = ltm->tm_mon - birthMonth + 1;
  age.weeks = age.months * 4;
  age.days = age.weeks * 7;
  age.hours = age.days * 24;
  age.minutes = age.hours * 60;
  age.seconds = age.minutes * 60;

  return age;
}

void drawAgePieChart(Age age) {
  initwindow(600, 400);

  // Calculate the percentage of each age unit.
  float yearsPercent = (float)age.years / age.years;
  float monthsPercent = (float)age.months / age.months;
  float weeksPercent = (float)age.weeks / age.weeks;
  float daysPercent = (float)age.days / age.days;
  float hoursPercent = (float)age.hours / age.hours;
  float minutesPercent = (float)age.minutes / age.minutes;
  float secondsPercent = (float)age.seconds / age.seconds;

  // Draw the pie chart slices.
  setfillstyle(SOLID_FILL, YELLOW);
  pieslice(300, 200, 100, 0, 360 * yearsPercent);
  setfillstyle(SOLID_FILL, GREEN);
  pieslice(300, 200, 100, 360 * yearsPercent, 360 * (yearsPercent + monthsPercent));
  setfillstyle(SOLID_FILL, BLUE);
  pieslice(300, 200, 100, 360 * (yearsPercent + monthsPercent), 360 * (yearsPercent + monthsPercent + weeksPercent));
  setfillstyle(SOLID_FILL, RED);
  pieslice(300, 200, 100, 360 * (yearsPercent + monthsPercent + weeksPercent), 360 * (yearsPercent + monthsPercent + weeksPercent + daysPercent));
  setfillstyle(SOLID_FILL, BLACK);
  pieslice(300, 200, 100, 360 * (yearsPercent + monthsPercent + weeksPercent + daysPercent), 360 * (yearsPercent + monthsPercent + weeksPercent + daysPercent + hoursPercent));
  setfillstyle(SOLID_FILL, WHITE);
  pieslice(300, 200, 100, 360 * (yearsPercent + monthsPercent + weeksPercent + daysPercent + hoursPercent), 360);

  // Draw the pie chart label.
  outtextxy(300, 200, "Age Pie Chart");

  // Wait for the user to press a key before closing the window.
  getch();
  closegraph();
}

int main() {
  // Get the user's birth date.
  int birthYear, birthMonth, birthDay;
  cout << "Enter your birth year: ";
  cin >> birthYear;
  cout << "Enter your birth month: ";
  cin >> birthMonth;
  cout << "Enter your birth day: ";
  cin >> birthDay;

  // Calculate the user's age.
  Age age = calculateAge(birthYear, birthMonth, birthDay);

  // Draw the age pie chart.
  drawAgePieChart(age);

  return 0;
}

