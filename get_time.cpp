# include <iostream>
# include <ctime>

using namespace std;

float GetCurrentTime(){

   // current date/time based on current system
   time_t now = time(0);
   tm *ltm = localtime(&now);

    return ltm->tm_sec;
   }
   
    int main(){
      cout << GetCurrentTime() << endl;
   }
   