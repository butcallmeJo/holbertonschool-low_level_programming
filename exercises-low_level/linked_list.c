#include <stdlib.h>

typedef struct Student {
  char *first_name;
  char *last_name;
  int birthdate_month;
  int birthdate_day;
  int birthdate_year;
  char *address;
  struct Student *next;
} Student;

int main(void) {
  Student bill = {"Bill", "Big Deal", 3, 24, 1992, "34 Main St.", NULL};
  Student john = {"John", "Doe", 9, 14, 1976, "46 Market St.", &bill};
  Student mark = {"Mark", "Prince", 5, 12, 1812, "5 California St.", &john};
}
