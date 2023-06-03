#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>
#include<vector>

using namespace std;

double calcTime(time_t start, time_t end)
{
  return difftime(end, start) / 3600;
}

main()
 {
 string command = "";
 string current_task = "";
 string task = "";
 time_t start = 0;
 time_t end = 0;
 time_t total = 0;
 vector < pair <string, double> > vec;


 while(command != "exit")
 {
   cout << "введите команду:";
   cin >> command;

   if(command == "begin")
   {

     cout << "введите название задачи:";
     cin >> task;

     if(current_task == task)
      {
      end = time(NULL);
      double time_spent = calcTime(start,end);
      total += (time_t)time_spent;
      cout << "задача " << current_task << " завершена за " << time_spent << " часов" << endl;
      vec.push_back(make_pair(current_task, time_spent));
      }
     
     else
      {
        start = time(NULL);
        current_task = task;
        cout << "отслеживание задачи " << current_task << " начато" << endl;
      }

     
   }

     else if(command == "end")
      {
        if(current_task != "")
        {
          end = time(NULL);
          double time_spent = calcTime(start, end);
          total += (time_t)time_spent;
          vec.push_back(make_pair(current_task, time_spent));
          cout << "задача " << current_task << " завершена за " << time_spent << " часов" << endl;
          current_task = "";
        }

      }

        else if (command == "status")
        {
         for(int i = 0; i < vec.size(); i ++)
          {
            cout << vec[i].first << " " << vec[i].second << endl;
          }
        }
   
 }
 
cout << "программа завершена.";

return 0;
  
 }
