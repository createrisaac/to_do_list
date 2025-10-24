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
        file<< "\nName of the task : " <<arr[i].name;
        file<<"\n Due date :" <<arr[i].date;
        file<<"\n Status :" <<arr[i].status;
    }
}
else{
    file<<"The file is empty.";

}
file.close();
}

void loadtask(){
    assaignment task;
    ifstream file("to-do-list.txt");
    if(file.is_open()){
        while (file>>task.name>>task.date>>task.status)//extraction of three variables from the file
        {
            arr.push_back(task);
        }
        file.close();
         cout << arr.size() ;
    }
    else{
        cout<<"The file's not opened.";
    }
}

void deleteinfo(){
    if(arr.empty()){
        cout <<"there is nothing to delete.";
    }
    int index;
    displayall();
    cout<<"\nEnter what you want to delete.\n";
    cin>>index;

    if(index<1 || index>arr.size()){
        cout<<"Invalid option.\n";
    }
    arr.erase(arr.begin() + (index-1));
    cout <<"detail successfully deleted.\n";
}

void update(){
    if(arr.empty()){
        cout<<"No files to update.";
    }
    int index;
    displayall();

    cout<<"Enter what you want to update.\n";
    cin>>index;
    if(index<1 || index>arr.size()){
        cout<<"Invalid option";
    }
    assaignment &task = arr[index-1];
    int choice;
    cout<<"1. Edit name.\n";
    cout<<"2. Edit date.\n";
    cout<<"3. Edit status.\n";
    cout<<"4. Edit all.\n";
    cout <<"Enter your choice.\n";
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"Enter name to be edited.\n";
        cin>>task.name;
        break;
    case 2:
        cout<<"ENter date to be edited.\n";
        cin>>task.date;
    case 3:
        cout<<"ENter status to be edited.\n";
        cin>>task.status;
    case 4:
        cout<<"Enter name to be edited.\n";
        cin>>task.name;
        cout<<"ENter date to be edited.\n";
        cin>>task.date;
        cout<<"ENter status to be edited.\n";
        cin>>task.status;
        break;
    default:
    cout<<"Invalid option.\n";
        break;
    }
}

int main()
{   int choice;
    do{
    cout <<"\nHere the task below you can do in this to-do-list.\n";
    cout <<"1. Add task.\n";
    cout <<"2. Display the task till yet.\n";
    cout <<"3. Store tasks in file.\n";
    cout <<"4. Delete task.\n";
    cout <<"5. Update the existing task.\n";
    cout <<"6. Exit.\n";


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
    else if(choice == 4)
    {
        deleteinfo();
    }
    else if(choice == 5)
    {
        update();
    }
    else{
        cout<<"You choose to exit."<<endl;
    }
}   while (choice != 6);




}