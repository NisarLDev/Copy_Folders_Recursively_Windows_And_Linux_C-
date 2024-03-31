#include <filesystem>
#include <iostream>
#include <string>
#include <system_error>


int main(){
         using namespace std;
         string route;
         string destination;
         cout << "Directory path. Enter the location of the origin without quotes.: " << endl;
         cout << "To copy the files to linux, write the path without quotation marks, not singles and not doubles." << endl;
         // Taking string input using getline() 
         getline(cin, route); 
         // Displaying string 
         cout << "The location of the origin is : "; 
         cout << route << endl;  
         cout << "Directory path. Enter the location of the destination.: " << endl;
         // Taking string input using getline()
         getline(cin, destination);
         cout << "The location of the destination is : ";
         cout << destination << endl;   
         const std::filesystem::path from{route}, to{destination};
 
    try
    {
      	std::filesystem::copy(from, to); // throws: files do not exist
    }
    catch (std::filesystem::filesystem_error const& ex)
    {
        std::cout << "what():  " << ex.what() << '\n'
                  << "path1(): " << ex.path1() << '\n'
                  << "path2(): " << ex.path2() << '\n'
                  << "code().value():    " << ex.code().value() << '\n'
                  << "code().message():  " << ex.code().message() << '\n'
                  << "code().category(): " << ex.code().category().name() << '\n';
    }
             cout << "----------------------------" << endl;
             cout << "    Operation completed.    " << endl;
             cout << "----------------------------" << endl;
//     All functions have non-throwing equivalents
//     std::error_code ec;
//     std::filesystem::copy_file(from, to, ec); // does not throw
//     std::cout << "Non-throwing form sets error_code: " << ec.message() << '\n';
       return 0;
}

