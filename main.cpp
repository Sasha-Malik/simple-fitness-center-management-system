//  main.cpp
//  assignment1
//
//  Created by Sasha Malik on 09/02/2022.
#include <iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;

// login is a global variable which tells that the user has logged in successfully, 1 is for admins and 2 is for members
int Login;
// memberID stores the ID of the user currently logged in
int MemberID;

//id is generated
int generateID()
    {
    
     srand(time(0));
     return rand()% 9000+1000;
    
    }

// names are converted to lower case
string Lower( string x)
{
    // len holds the length of the string
    int len = x.length();
    
    for (int i = 0; i < len; i++) {
  
        x[i] = tolower(x[i]);
        
    }
    
    return x;
}

//template for the class
template< typename t, typename v>
class Admin{
private:
    v AdminID;
    t First_Name;
    t Last_Name;
    t Username;
    t Password;
    
public:
    
    // an empty constructor
    Admin()
    {
        
    }
    //constructor overloading for the first admin
    Admin(string FName, string LName , string UName, string Pass)
    {
        AdminID = 1;
        First_Name = FName;
        Last_Name = LName;
        Username = UName;
        Password = Pass;
        
    }

    void registerAdmin()
    {
        cout<<"Enter first name:";
        cin>>First_Name;
        cout<<"Enter last name:";
        cin>>Last_Name;
        
        // generates the adminID
        AdminID = generateID();
        Username = Lower(First_Name) + to_string(AdminID);
        Password = Lower(Last_Name)  + to_string(AdminID);
    }
    
    void display(){
        
        cout<<endl<<"\n AdminID: "<<AdminID<<"\n FirstName: "<<First_Name<<"\n Last Name: "<<Last_Name<<"\n Username: "<<Username<<"\n Password: "<<Password<<endl;
    }
    
    // get funtions for the various data members
    int getAdminID()
    {
        return AdminID;
    }
    
    string getFName()
    {
        return First_Name;
    }
    
    string getLName()
    {
        return Last_Name;
    }

    string getUsername()
    {
        return Username;
    }
    
    string getPassword()
    {
        return Password;
    }
    
};




// templates for the class
template< typename t, typename v>
class Member{
    
    private:
        v MemberID;
        t First_Name;
        t Last_Name;
        t Username;
        t Password;
    
    
    public:
    
        void registerMember()
        {
            cout<<"Enter first name:";
            cin>>First_Name;
            cout<<"Enter last name:";
            cin>>Last_Name;
            //generates MemberID
            MemberID = generateID();
            //useraname and password are generated
            Username = Lower(First_Name) + to_string(MemberID);
            Password = Lower(Last_Name)  + to_string(MemberID);
        }
    
        void display(){
        
            cout<<endl<<"\n MemberID: "<<MemberID<<"\n FirstName: "<<First_Name<<"\n Last Name: "<<Last_Name<<"\n Username: "<<Username<<"\n Password: "<<Password<<endl;
        }
    
    
        // gettter functions for data members
        int getID()
        {
            return MemberID;
        }
    
        string getFName()
        {
            return First_Name;
        }
    
        string getLName()
        {
            return Last_Name;
        }
    
        string getUsername()
        {
            return Username;
        }
        
        string getPassword()
        {
            return Password;
        }
        
       
    
};

// templates for the class
template< typename t, typename v>
class FitnessClass{
    
    private:
        v ClassID;
        t ClassName;
        t ClassDate;
        t ClassTime;
        v MaximumCapacity;
        v RoomNumber;
        //initially the list of members has a size zero which is updated later when entering details of the class
        v *ListOfMembers = new v[0];
    // vacancy holds the number of members in the list
        v Vacancy;
    public:
    

        
        void SetFitnessClass()
    {
            
            cout<<"\nEnter class ID : ";
            cin>>ClassID;
            cout<<"\n Enter Class name : ";
            cin>>ClassName;
            cout<<"\n Enter Class date : ";
            cin>>ClassDate;
            cout<<"\n Enter Class time : ";
            cin>>ClassTime;
            cout<<"\n Enter Maximum capacity : ";
            cin>>MaximumCapacity;
            cout<<"\n Enter Room number : ";
            cin>>RoomNumber;
            
            //vacancy shows the number of members in the list of members
            Vacancy = 0;
            
            // the list of members is dynamically allocated with the size as the maximum number of members
            v* temp = new v [MaximumCapacity];
            ListOfMembers = temp;
            temp = NULL;
            
            
        }
    
    
        void display()
    {
            cout<<"\n Class ID : "<<ClassID<<"\n Class Name : "<<ClassName<<"\n Class Date : "<<ClassDate<<"\n Class Time : "<<ClassTime
            /* <<"\n Maximum Capacity : "<<MaximumCapacity*/
            <<"\n Room number : "<<RoomNumber<<endl;
            
    }
    
    
    // gettter functions for data members
    v getID()
    {
        return ClassID;
    }
    t getClassName()
    {
        return ClassName;
    }
    t getClassDate()
    {
        return ClassDate;
    }
    t getClassTime()
    {
        return ClassTime;
    }
    v getMaximumCapacity()
    {
        return MaximumCapacity;
    }
    v getRoomNumber()
    {
        return RoomNumber;
    }
    v getVacancy()
    {
        return Vacancy;
    }
      
    
    
    // to update the details of the class
    void updateID(v id)
    {
        ClassID = id;
        
    }
    void updateName(t name)
    {
        ClassName = name;
    }
    void updateDate(t date)
    {
        ClassDate = date;
    }
    void updateTime(t time)
    {
        ClassTime = time;
    }
    void updateCapacity(v capacity)
    {
        MaximumCapacity = capacity;
    }
    void updateNumber(v number)
    {
        RoomNumber = number;
    }
   
    //updating the list of memebers
    void setList(v MemberID)
    {
        
        //adds new member to the end of the list
        ListOfMembers[Vacancy] = MemberID;
        
        // increases the number of members by q
        Vacancy = Vacancy + 1;
        
        cout<<"List of members : ";
        for (int i =0; i < Vacancy; i++)
            cout<<ListOfMembers[i];
    }
    
    // deleting a member from the list
    void deleteList(v MemberID)
    {
     
        v* temp = new v [MaximumCapacity];
        int k = 0;
        
        //list of members except the member to be deleted is copied to the new list
        
        for(int i = 0 ; i < Vacancy ; i++ )
        {
            
            if(ListOfMembers[i] != MemberID)
            {
                temp[k] = ListOfMembers[i];
                //k helps iterate the new list
                k++;
            }
            
        }
        //old pointer is made to point to the new list
        ListOfMembers = temp;
        temp = NULL;
        
        //number of members is reduced by one now
        Vacancy = Vacancy - 1;
        
        cout<<endl<<"Member delted form the list! ";
        
        cout<<"List of members : ";
        for (int i =0; i < Vacancy; i++)
            cout<<ListOfMembers[i];
    }
    
  
};





// registers an admin, the size contains the number of admins
void RegisterAdmin(int& size, Admin < string ,int> * ptr1[])
{
    
  
    // the number of admins in the list increases
    size = size + 1;
    
    // new object is initialized and is registered
    ptr1[size-1]= new Admin<string,int>;
    ptr1[size-1]->registerAdmin();
    
    cout<<endl<<"Admin registered successfully! ";
    
    for (int i =0; i<size ; i++)
    ptr1[i]->display();

}

// registers a member, the size contains the number of members
void RegisterMember(int& Msize, Member < string ,int> * ptr2[])
{
    
    // the number of members in the list increases
    Msize = Msize + 1;
    
    // new object is initialized and is registered
    ptr2[Msize-1] = new Member<string, int>;
    ptr2[Msize-1]->registerMember();

    
    cout<<endl<<"Member registered successfully! ";
    
    for (int i =0; i<Msize ; i++)
    ptr2[i]->display();
    

    
}

void AddFitnessClass(int &Csize, FitnessClass<string, int> * ptr3[])
{
    
    cout<<endl<<"Fitness class added successfully! ";
    Csize = Csize + 1;
    
    //new object of fitness class is creted
    ptr3[Csize-1] = new FitnessClass< string , int>;
    ptr3[Csize-1]->SetFitnessClass();
    
    
    for (int i = 0; i < Csize ; i++)
        ptr3[i]->display();
    
    
}


void DeleteFitnessClass(int &Csize, FitnessClass<string, int> *ptr3[])
{
    
    int ID;
    cout<<"\n Enter Class ID of class to be deleted : ";
    cin>>ID;
    
    
    for(int i = 0; i < Csize ; i++)
        
        //if the id to be deleted matches then in place of the class the last class is copied there
        if ( ptr3[i]->getID() == ID )
        {
            ptr3[i]=ptr3[Csize-1];

        }
    
    //the last class is deleted as the pointer is made to point to null
    ptr3[Csize-1]=NULL;
    
    // the number of classes decreases
    Csize = Csize - 1 ;
    
    cout<<endl<<"Fitness class deleted successfully! ";
    
    for (int i = 0; i < Csize ; i++)
    ptr3[i]->display();
    

    
}


void updateClassDetails( int &Csize , FitnessClass< string , int>* ptr3[])
{   int ID;
    cout<<"\n Enter Class ID to be updated: ";
    cin>>ID;
    
    //which data member to be updated
    string Dtype;
    cout<<"\n Enter Data type to be updated: (name/date/time/capacity/room) ";
    cin>>Dtype;
    
    
    cout<<"Enter new value: ";
    string a;
    int b;
    
    for (int i = 0; i < Csize ; i++)
        
        if (ptr3[i]->getID() == ID){
            
            // if data type is name then string member will be used
            if (Dtype == "name")
            {
                cin>>a;
                ptr3[i]->updateName(a);
            }
            // if data type is date then string member will be used
            else if (Dtype == "date")
            {
                cin>>a;
                ptr3[i]->updateDate(a);
            }
            // if data type is time then string member will be used
            else if (Dtype == "time")
            {
                cin>>a;
                ptr3[i]->updateTime(a);
            }
            // if data type is capacity then int member (b) will be used
            else if (Dtype == "capacity")
            {
                cin>>b;
                ptr3[i]->updateCapacity(b);
            }
            // if data type is room number then int member (b) will be used
            else if (Dtype == "room")
            {
                cin>>b;
                ptr3[i]->updateNumber(b);
            }
        }
        
    cout<<endl<<"Fitness class updated successfully! ";
}


void bookAClass( int Csize, FitnessClass<string , int>* ptr3[])
{
    
    int ID;
    cout<<"\n Enter Class ID for booking : ";
    cin>>ID;
    
    for (int i = 0; i< Csize; i++)
    {
        // if the id matches then the member is added to the list of that class
        if(ptr3[i]->getID() == ID)
        
            ptr3[i]->setList(MemberID);
            
    }
    cout<<endl<<"Class booked! ";
    
}

void viewClassesWithVacancies(int Csize, FitnessClass<string , int>* ptr3[])
{
    
    
    for(int i = 0; i< Csize ; i++)
    {
        //if the class does not reach its max capacity then it is displayed
        if(ptr3[i]->getVacancy() <= ptr3[i]->getMaximumCapacity())
            ptr3[i]->display();
        
    }

    
}

void cancelBooking(int Csize, FitnessClass<string , int>* ptr3[])
{
    int ID;
    cout<<"\n Enter Class ID for booking : ";
    cin>>ID;
    
    for (int i = 0; i< Csize; i++)
    
        if(ptr3[i]->getID() == ID)
            
            //member is removed from the list
            ptr3[i]->deleteList(MemberID);
            
    cout<<endl<<"Booking canceled! ";
    
}

void login(int size, Admin<string,int>* ptr1[] )
{
    
    string username, password;
    
    // at first it says not logged in
    Login = 0;
    
    int check = 0;
    // the user keeps loging in till the details are correct
    while (check != 1)
    {
        cout<<"\n Enter username: ";
        cin>>username;
        cout<<"\n Enter password: ";
        cin>> password;
        
        
        for (int i=0; i< size; i++)
        
            if( username == ptr1[i]->getUsername() && password == ptr1[i]->getPassword() )
            {
                cout<<"\nLogin Successful";
                
                // login is a global variable which tells that the user has logged in successfully, 1 is for admins and 2 is for members
                Login=1;
                check =1;
                
            }
            
        
        
        if (check != 1)
        cout<<"\n Invalid credentials!  Login again :"<<endl;
        
    }
    
}



void login(int size, Member<string,int>* ptr2[] )
{
    
    string username, password;
    // at first it says not logged in
    Login = 0;
    
    int check = 0;
    
    // the user keeps loging in till the details are correct
    while (check != 1)
    {
        cout<<"\n Enter username: ";
        cin>>username;
        cout<<"\n Enter password: ";
        cin>> password;
        
        for (int i=0; i< size; i++)
        
            if( username == ptr2[i]->getUsername() && password == ptr2[i]->getPassword() )
            {
                cout<<"\n Login Successful";
                
                // login is a global variable which tells that the user has logged in successfully, 2 is for members
                Login=2;
                check = 1;
                
                // memberID stores the ID of the user currently logged in
                MemberID = ptr2[i]->getID();
            }
                 
        if (check != 1)
        cout<<"\n Invalid credentials!  Login again :"<<endl;
        
    }
  
}

// quit program saves every detail to the various files
void quitProgram(int size, Admin < string ,int> * ptr1[],  int Msize, Member<string, int>* ptr2[]    ,int Csize, FitnessClass<string, int>*ptr3 [])
    {
        //opening first file for admin
        ofstream f1;
        f1.open("AdminsTable.txt", ios::out);

        for(int i = 0 ; i < size ; i++)
        {
            f1<<ptr1[i]->getAdminID()<<","<<ptr1[i]->getFName()<<","<<ptr1[i]->getLName()<<","<<ptr1[i]->getUsername()<<","<<ptr1[i]->getPassword();
            f1<<endl;
        }
        //closing the file
        f1.close();

    
    
        ofstream f2;
        f2.open("MembersTable.txt", ios::out);

        for(int i = 0 ; i < Msize ; i++)
        {
            f2<<ptr2[i]->getID()<<","<<ptr2[i]->getFName()<<","<<ptr2[i]->getLName()<<","<<ptr2[i]->getUsername()<<","<<ptr2[i]->getPassword();
            f2<<endl;
        }

        f2.close();


        ofstream f3;
        f3.open("FitnessClassesTable.txt", ios::out);
    
        for(int i = 0 ; i < Csize ; i++)
        {
            f3<<ptr3[i]->getID()<<","<<ptr3[i]->getClassName()<<","<<ptr3[i]->getClassDate()<<","<<ptr3[i]->getClassTime()<<","<<ptr3[i]->getMaximumCapacity()<<","<<ptr3[i]->getRoomNumber();
            f3<<endl;
        }
    
        f3.close();
    

    cout<<endl<<"Data saved to the files successfully! ";
}

int main(){
    
    cout<<"Welcome to the Fitness management system! "<<endl;
  // since there is initially one admin
    int size=1;
    
    // array of pointers of size 100
    Admin< string , int >* ptr1[100];
    
    //making all pointers point to NULL
    for(int i =0; i < 100; i++ )
        ptr1[i]=NULL;
    
    // initializing the first object
    
    ptr1[0] = new Admin<string,int> ("admin","admin", "admin1","admin1");
    
    
    // pointers for member
    int Msize = 0;
    Member< string, int>* ptr2[100];

    //making all pointers point to NULL
    for(int i =0; i < 100; i++ )
        ptr2[i]=NULL;

    // pointers for classes
    int Csize = 0;
    FitnessClass<string, int>* ptr3[100];
    
    //making all pointers point to NULL
    for(int i =0; i < 100; i++ )
        ptr3[i]=NULL;
    
    
    string ch ;
    
    int  choice;
    while (ch != "no")
    {
        string memberType;
        cout<<"Please enter the category of your accoount (member/admin) :";
        cin>>memberType;
        
        // checks which function to call depending on user type, calls the same function but with
        if (memberType == "admin" )
            login(size, ptr1);
        
        else if (memberType == "member")
            login(Msize, ptr2);
        
        string answer;
        
        while (answer != "no" && Login == 1){
            
        // if logged in as admin
        if(Login == 1)
        {
            cout<<"\n The list of available operations for admins: ";
            cout<<"\n 1) Register a new admin \n 2) Register a new member \n 3) add a fitness class \n 4) delete a fitness class \n 5) update the details of a fitness class \n 6) display the class with vacancies \n 7) quit the program \n Enter choice: ";
            cin>>choice;
        
            if (choice == 1)
                RegisterAdmin(size, ptr1);
        
            else if (choice == 2)
                RegisterMember(Msize, ptr2);
            
            else if (choice == 3)
                AddFitnessClass(Csize , ptr3);
            
            else if (choice == 4)
                DeleteFitnessClass(Csize , ptr3);
                
            else if (choice == 5)
                updateClassDetails(Csize , ptr3);
            
            else if (choice == 6)
                viewClassesWithVacancies(Csize, ptr3);
            
            else if (choice == 7)
            {
                // if user exits the program data is saved in the files
                quitProgram(size , ptr1,   Msize, ptr2,  Csize, ptr3  );
                exit(0);
            }
        }
    
            // to continue doing stuff in admin
            cout<<"\n do you want to continue in admin? (enter no to login again): ";
            cin>>answer;
        }
        
        
        string answer2;
        
        // if logged in as member
        while (answer2 != "no" && Login == 2){
         if (Login == 2)
        {
        
            cout<<"\n The list of available operations for members: ";
            cout<<"\n 1) Book a class \n 2) Veiw class with vacancies \n 3) Cancel booking \n 4) Quit program \n Enter choice: ";
            cin>>choice;
            
            
            if (choice == 1)
            {
                bookAClass(Csize, ptr3);
                
            }
            else if (choice ==2)
            {
                viewClassesWithVacancies(Csize, ptr3);
                
            }
            
            else if (choice == 3)
            {
                cancelBooking(Csize , ptr3);
                
            }
            else if(choice == 4)
            {
                // if user exits the program data is saved in the files
                quitProgram(size , ptr1,   Msize, ptr2,  Csize, ptr3  );
                exit(0);
            }
   
        }
            // to continue doing stuff in member
            cout<<"\n do you want to continue in member? (enter no to login again): ";
            cin>>answer2;
        
        }
        
        
        // to return to main meneu and login  again
        cout<<"\n Do you want to go back to login menu?? (enter no to exit program):";
        cin>>ch;
        // if user exits the program data is saved in the files
        if (ch == "no")
            quitProgram(size , ptr1,   Msize, ptr2,  Csize, ptr3  );
        
    }
    
    
    return 0;
}
