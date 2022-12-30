#include <iostream>
using namespace std;

int main() {
   while (true != false) {
    valid:
     
    string raceOutCome;
      cout << "Please enter the race outcome (If User Types 'done', It'll exit the program) : ";
      cin >> raceOutCome;
      if(raceOutCome == "done") return 0;

      int numMembers = 0;      
      int scores[char(90)+1] = {};
      int counts[char(90)+1] = {};

      for (int x = 0; x < raceOutCome.length(); x++) {
            if(scores[raceOutCome[x]] == 0){
                numMembers++;
            }
            scores[raceOutCome[x]] = x + 1 + scores[raceOutCome[x]];
            counts[raceOutCome[x]]++;
      }

      for(int x = 0; x < (char(90) + 1); x++){
            if(counts[x]!= 0 && (counts[raceOutCome[0]] != counts[x])){
                cout << "(the teams are not equal) Please enter again: " << endl;
                goto valid;
            }
      }

      cout << "There are: " << numMembers << " teams." << endl;
      cout << "There are: " << counts[raceOutCome[0]] << " runners on each team." << endl;
     
      double average = (scores[raceOutCome[0]])/(counts[raceOutCome[0]] * 1.0);
      char win = raceOutCome[0];
      for(int x = char(65); x < (char(90) + 1); x++){
            if(scores[x]!=0){
                cout << "Average for team " << (char)(x) << " is: " << scores[x]/(counts[x] * 1.0) << endl;
                if(average > (scores[x])/(counts[x] * 1.0)){
                    average = (scores[x])/(counts[x] * 1.0);
                     win = x;
                }
            }
      }
      cout << "The team that won was " << win << "' with a score of: " << average << endl;
      cout << endl;
   }
   return 0;
}