#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>

using namespace std;

main()
 {
 string command = "";
 string task = "";
 time_t start = 0;
 time_t end = 0;
 time_t total = 0;

 while(command != "exit")
 {
   cout << "enter command:";
   cin >> command;

   if(command == "begin")
   {
     cout << "enter name task:";
     cin >> task;
     start = time(NULL);
     cout << "task tracking: " << task << endl;
   }
   
 }
 
cout << "program completed";
  
 }
