#include <ctime>
#include <iostream>

int main()
{
  std::tm time_in = { 0, 0, 0, // second, minute, hour
      4, 0, 2023 - 1900 }; // 1-based day, 0-based month, year since 1900

  std::time_t time_temp = std::mktime(&time_in);

  // Note: Return value of localtime is not threadsafe, because it might be
  // (and will be) reused in subsequent calls to std::localtime!
  const std::tm * time_out = std::localtime(&time_temp);

  //Sunday == 0, Monday == 1, and so on ...
  std::cout << "Today is this day of the week: " << time_out->tm_wday << "\n";
  std::cout << "(Sunday is 0, Monday is 1, and so on...)\n";

  return 0;
}
