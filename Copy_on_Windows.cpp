#include <iostream>
#include <direct.h> //mkdir
#include <string>

using namespace std;

void copy_folder(string route, string destination)
{
   /* Extract the name of the folder you want to copy. */
   size_t needle = route.rfind("\\"); 
   if (needle != string::npos)
   {
     /* Modify the destination by adding the name of the folder to copy */ 
     destination = destination + "\\" + route.substr(needle+1);       
   } 
   
   /* Create the empty folder on the destination */
   mkdir(destination.c_str());
   
   /* String to create the command: xcopy route destination */
   string a_string;
   a_string = "xcopy " + route + " " + destination + " /H /S";
   
   /* Run the command */
   system(a_string.c_str());
}

void init()
{
  cout << "Directory path. Enter the location of the origin.: " << endl;
  string route;
  getline(cin, route);
  cout << "Directory path. Enter the location of the destination.: " << endl;
  string destination;
  getline(cin, destination);
  copy_folder(route, destination);
  if (!copy_folder)
     cout << "Operation carried out successfully." << endl;
  else
     cout << "Impossible create folder " << endl;
  init();
}

int main(int argc, char *argv[])
{
 init();
 system("PAUSE");
 return 0;
};
