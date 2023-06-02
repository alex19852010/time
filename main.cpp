#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>

using namespace std;

double calcTime(time_t start, time_t end)
{
  return difftime(end, start) / 3600;
}

main()
 {
 string command = "";
 string current_task = "";
 time_t start = 0;
 time_t end = 0;
 time_t total = 0;

 while(command != "exit")
 {
   cout << "введите команду:";
   cin >> command;

   if(command == "begin")
   {

    if(current_task != "")
     {
      end = time(NULL);
      double time_spent = calcTime(start,end);
      total += (time_t)time_spent;
      cout << "задача " << current_task << " завершена за " << time_spent << " часов" << endl;
     }

     cout << "введите название задачи:";
     cin >> current_task;
     start = time(NULL);
     cout << "отслеживание задачи " << current_task << " начато" << endl;
   }

     else if(command == "end")
      {
        if(current_task != "")
        {
          end = time(NULL);
          double time_spent = calcTime(start, end);
          total += (time_t)time_spent;
          cout << "задача " << current_task << " завершена за " << time_spent << " часов" << endl;
          current_task = "";
        }

      }

        else if (command == "status")
        {
          if(current_task != "")
           {
             cout << "currently tracking task: " << current_task << endl;
           }

           cout << "total spent on all tasks: " << total << " second" << endl;
          
        }
   
 }
 
cout << "программа завершена.";

return 0;
  
 }
