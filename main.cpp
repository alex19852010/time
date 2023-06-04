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
   cout << "enter command:";
   cin >> command;

   if(command == "begin")
   {

     cout << "enter name task:";
     cin >> task;


     if(current_task == task)
      {
        cout << "the task is already running" << endl;
      }

     else if(current_task != task && current_task != "")
      {
      end = time(NULL);
      double time_spent = calcTime(start,end);
      total += (time_t)time_spent;
      cout << "task " << current_task << " finished in " << time_spent << " hours" << endl;
      vec.push_back(make_pair(current_task, time_spent));
      start = time(NULL);
      current_task = task;
      cout << "tracking task " << current_task << " started" << endl;
      
      }
     
     else
      {
        start = time(NULL);
        current_task = task;
        cout << "tracking task " << current_task << " started" << endl;
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
          cout << "task " << current_task << " finished in " << time_spent << " hours" << endl;
          current_task = "";
      
        }

      }

        else if (command == "status")
        {
         for(int i = 0; i < vec.size(); i ++)
          {
            cout << vec[i].first << " " << vec[i].second << endl;
          }
          if(current_task != "")
          {
            cout << "task is running now: " << current_task << endl;
          }
        }
   
 }
 
cout << "program completed.";

return 0;
  
 }
