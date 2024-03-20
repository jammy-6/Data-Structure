#include <bits/stdc++.h>
using namespace std;

class Record
{
public:
  Record(string record)
  {
    sscanf(record.data(),
           "%d-%d-%d %d:%d:%d",
           &year,
           &month,
           &day,
           &hour,
           &minute,
           &second);
  }
  bool operator<(const Record& r)
  {
    if (year != r.year)
      return year < r.year;
    if (month != r.month)
      return month < r.month;
    if (day != r.day)
      return day < r.day;
    if (hour != r.hour)
      return hour < r.hour;
    if (minute != r.minute)
      return minute < r.minute;
    return second < r.second;
  }
  uint64_t countSecond(const Record& c)
  {
    if (c.day > day) {
      return c.second + c.minute * 60 + c.hour * 60 * 60 + 24 * 60 * 60 -
             hour * 60 * 60 - minute * 60 - second;
    } else {
      return c.second + c.minute * 60 + c.hour * 60 * 60 - hour * 60 * 60 -
             minute * 60 - second;
    }
  }

private:
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
};

int
main()
{
  // 请在此输入您的代码
  string record;
  vector<Record> data;
  while (getline(cin, record)) {
    data.push_back(record);
  }
  sort(data.begin(), data.end());
  // std::cout<<data.size()<<std::endl;
  int ans = 0;
  for (int i = 0; i < data.size(); i += 2) {
    ans += data[i].countSecond(data[i + 1]);
  }
  std::cout << ans << std::endl;
  return 0;
}