#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

struct assaignment
{
    string name;
    string date;
    string status;
};

vector<assaignment> arr;
void addtask(){
    assaignment task;
    cout<<"Name of the task : ";
    cin>>task.name;
    cout<<" Due date :";
    cin>>task.date;
    cout<<" Status :";
    cin>>task.status;

    arr.push_back(task);
    cout<<"\nTask successfully added.\n";
}

void displayall(){
    for(int i=0;i<arr.size();i++){
        cout<<"\nHere the tasks info.";
        cout<< "\nName of the task : " <<arr[i].name;
        cout<<" \nDue date :" <<arr[i].date;
        cout<<" \nStatus :" <<arr[i].status;
    }
}
void storeinfo(){
    ofstream file("to-do-list.txt");
if(file.is_open()){
    for(int i=0;i<arr.size();i++){
        file<< "nName of the task : " <<arr[i].name;
        file<<"\n Due date :" <<arr[i].date;
        file<<"\n Status :" <<arr[i].status;
    }
}
else{
    file<<"The file is empty.";

}
file.close();
}

int main()
{   int choice;
    do{
    cout <<"\nHere the task below you can do in this to-do-list.\n";
    cout <<"1. Add task.\n";
    cout <<"2. Display the task till yet.\n";
    cout <<"3. Store tasks in file.\n";
    cout <<"4. Exit.\n";


    cout <<"Enter your choice : ";
    cin>>choice;

    
        if(choice == 1){
        addtask();
    }
    else if(choice == 2)
    {
        displayall();
    }
    else if(choice == 3)
    {
        storeinfo();
    }
    else{
        cout<<"You choose to exit."<<endl;
    }
}   while (choice != 4);




}