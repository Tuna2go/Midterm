#ifndef student_h
#define student_h
#include "sorting.h"

#include <iostream>
using namespace std;

class Student{
private:
  int score,expected_score,pointqone,pointqtwo,pointqthree;
  float anxiety;
  string name;
  string Quiz1,Quiz2,Quiz3;
  bool Depression = false;
  bool veryDepressed = false;

public:
  void print_info();
  void student_info(string, int=0);
  void check_status();
  void too_depressed();
  int quiz_one();
  int quiz_two();
  int quiz_three();
  void increase_s12();
  void increase_s3();
  void showresult();
  void anxietyfromgrade();
  void sorting();

Student(); //constructor
~Student(); //destructor 
};
void Student::sorting(){
  int a[3]= {pointqone, pointqtwo,pointqthree};
  int size=sizeof(a)/sizeof(a[0]);
  bubble(a,size);
  printsort(a,size);
}
void Student::showresult(){
  cout<<"Score for Quiz 1: "<<pointqone<<"/5"<<endl;
  cout<<"Score for Quiz 2: "<<pointqtwo<<"/5"<<endl;
  cout<<"Score for Quiz 3: "<<pointqthree<<"/8"<<endl;
  int Totalscore=pointqone+pointqtwo+pointqthree;
  cout<<"Your expected score is "<<expected_score<<"/100"<<endl;
  cout<<"Total score for all three quiz is "<<Totalscore<<"/18 or "<<score<<"/100"<<endl;
  anxietyfromgrade();
}
void Student::anxietyfromgrade(){
  if(expected_score/2>score){
    anxiety+=10;
  }
  else if(expected_score>score){
    anxiety+=3;
  }
}
void Student::too_depressed(){
  if(anxiety>9){
    veryDepressed=true;
    cout<<"You are too depressed to continue"<<endl;
    exit(1);
  }
  else veryDepressed=false;
}
void Student::increase_s12(){
  score+=6;
}
void Student::increase_s3(){
  score+=5;
}
Student::Student(){
  anxiety=0;
  score=0;
}
void Student::student_info(string a, int b){
  name = a;
  expected_score = b;
}

Student::~Student(){
  cout << name <<" left the school." << endl;
}
void Student::print_info(){
  cout<<"----------------------------"<<endl;
  cout<<"Name:"<<name<<endl;
  cout<<"Expected score:"<<expected_score<<"/100"<<endl;
  cout<<"Anxiety Level:"<<anxiety<<"/10"<<endl;
  cout<<"Current score:"<<score<<"/100"<<endl;
  check_status();
  if(Depression == true) cout << "Status:Depressed"<<endl;
  else cout<<"Status:Normal"<<endl;
  cout<<"----------------------------"<<endl;
}
void Student::check_status(){
  if(anxiety < 10 && anxiety >= 7) {Depression = true;}
  else {Depression = false;}
}
////////////////////////////
//////QUIZ FUNCTION/////////
////////////////////////////

int Student::quiz_one(){
  char question[][100] = {"Question 1: what is 20/4? ",
                          "Question 2: What is 3000/42?",
                          "Question 3: What is 42 x 3?",
                          "Question 4: What is 52/5?",
                          "Question 5: What is sqrt of 25?"};
  char option[][100] = {"A.5", "B.10", "C.25",
                        "A.72.56", "B.71.43", "C.77.32",
                        "A.130", "B.196", "C.126",
                        "A.10.2", "B.10.4", "C.10.1",
                        "A.5", "B.3", "C.4"};
  char answer[5] = {'A','B','C','B','A'};

  int Totalquestion = sizeof(question)/sizeof(question[0]);
  char Choice;
  for(int i=0;i<Totalquestion;i++){
    cout<<question[i]<<endl;;
    for(int j= (i*3);j<(i*3)+3;j++){
      cout<<option[j]<<endl;
    }
    cout<<"Your choice:"<<endl;
    cin>> Choice;
    Choice=toupper(Choice);
    if(Choice==answer[i]){
      pointqone++;
      increase_s12();
    }
  }
  cout<<"Quiz 1 score:"<<pointqone<<"/5"<<endl;
  cout<<"Current score:"<<score<<"/100"<<endl;
  
  return 0;
}

/////////////////////////////QUIZ TWO/////////////////////////////

int Student::quiz_two(){
  char question[][100] = {"Question 1: How long has Ayutthaya been prosperous?",
                          "Question 2: How is Bangkok's historic center called?",
                          "Question 3: How old is the history of Bangkok?",
                          "Question 4: What was the Thonburi Kingdom?",
                          "Question 5: How long did the Ayutthaya kingdom last for?"};
  char option[][100] = {"A.415", "B.416", "C.417",
                        "A.The Rattanekosin building", "B.The Rattanekosin island", "C.The Rattanekosin land",
                        "A.Late 16th Century", "B.Late 15th Century", "C.Late 10th Century",
                        "A.It was a Siamese Kingdom", "B.It was a South Indian Kingdom", "C.It was a Aryan Kingdom",
                        "A.From 1200 to 1767", "B.From 1350 to 1767", "C.From 1230 to 1250"};
  char answer[5] = {'C','B','A','A','B'};

  int Totalquestion = sizeof(question)/sizeof(question[0]);
  char Choice;

  for(int i=0;i<Totalquestion;i++){
    cout<<question[i]<<endl;;
    for(int j= (i*3);j<(i*3)+3;j++){
      cout<<option[j]<<endl;
    }
    cout<<"Your choice:"<<endl;
    cin>> Choice;
    Choice=toupper(Choice);
    if(Choice==answer[i]){
      pointqtwo++;
      increase_s12();
    }
  }
  cout<<"Quiz 2 score:"<<pointqtwo<<"/5"<<endl;
  cout<<"Current score:"<<score<<"/100"<<endl;
  
  return 0;
}

////////////////////QUIZ THREE/////////////////////////

int Student::quiz_three(){
  char question[][1000] = {"Question 1: Funny, lives in a pineapple under the sea, pet named Gary, works at the Krusty Krab",
                          "Question 2: Spongebob Squarepant's pet, lazy, eats a lot",
                          "Question 3: Owns the Krusty Krab, loves money",
                          "Question 4: Space Squirrel from Spongebob Squarepants, from Texas",
                          "Question 5: Spongebob's next door neighbor, lives in a tiki",
                          "Question 6: Likes Minnie Mouse, dog named Pluto, goes to a clubhouse everyday",
                          "Question 7: Likes Mickey Mouse, best friends with Daisy Duck",
                          "Question 8: Likes the color pink, doesn't talk a lot"};
  char option[][1000] = {"A.Spongebob", "B.Squidward", "C.Patrick",
                        "A.Misses Puff", "B.Sheldon", "Gary",
                        "A.Mr.Krabs", "B.Squidward", "C.Peter",
                        "A.Patross", "B.Mathrew", "C.Sandy",
                        "A.Squidward", "B.Patrick", "C.Mary"
                        "A.Goofy", "B.Mickey Mouse", "C.Donald Duck",
                        "A.Donald duck", "B.Minnie Mouse", "C.Space Pirate",
                        "A.Pink Panther", "B.Big nose", "C.Supreme Thanos"};
  char answer[8] = {'A','C','A','C','A','B','B','A'};

  int Totalquestion = sizeof(question)/sizeof(question[0]);
  char Choice;

  for(int i=0;i<Totalquestion;i++){
    cout<<question[i]<<endl;;
    for(int j= (i*3);j<(i*3)+3;j++){
      cout<<option[j]<<endl;
    }
    cout<<"Your choice:"<<endl;
    cin>> Choice;
    Choice=toupper(Choice);
    if(Choice==answer[i]){
      pointqthree++;
      increase_s3();
    }
  }
  cout<<"Quiz 2 score:"<<pointqthree<<"/8"<<endl;
  cout<<"Current score:"<<score<<"/100"<<endl;
  
  return 0;
}

#endif