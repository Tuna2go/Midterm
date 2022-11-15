#include "menu.h"
#include "student.h"
#include <iostream>
using namespace std;

// sorting left

int main(int argc, char* argv[]) {
  int i,a=(argc-1)/2;
  bool canbepick1 = true, canbepick2 = true, canbepick3 = true;
  int menu, pickquiz, pickstudent;
  Student *sp=new Student[a];
  for(i=1;i<argc;i+=2){
    sp->student_info(argv[i],atoi(argv[i+1]));
    sp++;
  }
  sp-=a;
  if(argc>3) {
    cout<<"which student would you like to control?"<<endl;
    for(int a=1;a<argc;a+=2){
        cout<<argv[a]<<endl;
    }
    cin>>pickstudent;
    }
  else pickstudent = 1;
  
  while(menu!=4){
    sp[pickstudent-1].too_depressed();
    print_menu();
    cin>>menu;
    if(menu>4){
      cout<<"Please choose between 1 to 4"<<endl;
    }
    switch (menu){
      case 1:
        sp[pickstudent-1].print_info();
      break;
      case 2:
        quiz_menu();
        cout<<"Choose your quiz"<<endl;
        cin>>pickquiz;
        if(pickquiz == 1 && canbepick1) {canbepick1 = false; sp[pickstudent-1].quiz_one();}
        else if(pickquiz == 2 && canbepick2) {canbepick2 = false; sp[pickstudent-1].quiz_two();}
        else if(pickquiz == 3 && canbepick3) {canbepick3 = false; sp[pickstudent-1].quiz_three();}
        else if(pickquiz > 3) {cout<<"Please pick the following quiz"<<endl;}
        else {cout<<"You already took that quiz"<<endl;}
      break;
      case 3:
        if(canbepick1 == false && canbepick2 == false && canbepick3 == false){
          sp[pickstudent-1].showresult();
          sp[pickstudent-1].sorting();
        }
        else cout<<"Please finish all the quiz before checking the result"<<endl;
      break;
      default: break;
    }
  }
  delete []sp;
}
