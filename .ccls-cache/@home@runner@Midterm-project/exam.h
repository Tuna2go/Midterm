#include "menu.h"
#include "student.h"
#include <iostream>
using namespace std;

class Quiz{
  private:
    int score;
  public:
    void quizone();
};

void quizone(){
  char question[][100] = {"Question 1",
                          "Question 2",
                          "Question 3",
                          "Question 4",
                          "Question 5",};
  char option[][100] = {"A.Question 1A", "B.Question 1B", "C.Question 1C",
                        "A.Question 2A", "B.Question 2B", "C.Question 2C",
                        "A.Question 3A", "B.Question 3B", "C.Question 3C",
                        "A.Question 4A", "B.Question 4B", "C.Question 4C",
                        "A.Question 5A", "B.Question 5B", "C.Question 5C",};
  char answer[5] = {'A','B','C','B','A'};

  int Totalquestion = sizeof(question)/sizeof(question[0]);
  char Choice;

  for(int i=0;i<Totalquestion;i++){
    cout<<question[i]<<endl;;
    for(int j= (i*3);j<(i*3)+3;j++){
      cout<<option[j]<<endl;
    }
  }
}