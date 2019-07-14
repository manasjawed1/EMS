#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>
#include<Wincon.h>
#include <dos.h>
#include <dir.h>




using namespace std;


// Defining datatypes (structures).
struct Student {
    string name,password,department;
    double gpa;
    double total_courses;
    vector<string>courses_enrolled;
};

struct Instructor {
    string name,password,department;
    vector<string>my_courses;
};

struct Courses {
    string name, instructor_name,department;
    double capacity,enrolled_students;
};







int main()
{  // changing color of the console window and the text!!





    // Defining vectors of type structures we have defined.
    vector <Instructor> all_instructors;
    vector <string> temp_instructors;

    vector <Student> all_students;
    vector <string> temp_students;

    vector <Courses> all_courses;
    vector <string> temp_courses;


    // first, open the file, make temp structure, pushback structure into vector.

    // Using getline function to extract info from the file line by line, and putting into a temp vector. One line is one element. //

    // UPDATING all_instructors vector from file: all_instructors:
   {
        ifstream in_instructor;
        string str;
        in_instructor.open("all_instructors.txt");
        while (getline(in_instructor,str))
        {

            temp_instructors.push_back(str);

        }

        for (unsigned int i=0; i<temp_instructors.size(); i=i+4)
        {
           Instructor temp;
           temp.name= temp_instructors[i];
           temp.password= temp_instructors[i + 1];
           temp.department= temp_instructors[i + 2];

           // the string containing all courses separated by spaces is temp_instructors[i+2].
           istringstream buf(temp_instructors[i+3]);
           for(string word; buf >> word; )
           {
               temp.my_courses.push_back(word);
           }

           all_instructors.push_back(temp);
        }

    }
{
     ifstream in_student;
        string str1;
        in_student.open("all_students.txt");
        while (getline(in_student,str1))
        {

            temp_students.push_back(str1);

        }

        for (unsigned int i=0; i<temp_students.size(); i=i+6)
        {
           Student temp;
           temp.name= temp_students[i];
           temp.password= temp_students[i + 1];
           temp.department= temp_students[i + 2];
           temp.gpa = atof(temp_students[i + 3].c_str());
           temp.total_courses = atof(temp_students[i + 4].c_str());

           istringstream buf(temp_students[i+5]);
           for(string word; buf >> word; )
           {
               temp.courses_enrolled.push_back(word);
           }

           all_students.push_back(temp);
        }
}

{
        ifstream in_courses;
        string str;
        in_courses.open("all_courses.txt");
        while (getline(in_courses,str))
        {

            temp_courses.push_back(str);

        }

        for (unsigned int i=0; i<temp_courses.size(); i=i+5)
        {
           Courses temp;
           temp.name= temp_courses[i];
           temp.instructor_name= temp_courses[i + 1];
           temp.department= temp_courses[i + 2];
           temp.capacity= atof(temp_courses[i+3].c_str());
           temp.enrolled_students=atof(temp_courses[i+4].c_str());
           all_courses.push_back(temp);

        }


}

    string user_choice;
    do
    {
        system("CLS");
        cout << "$$$$$$  Welcome to Zambeel  $$$$$$ \n \n";
        cout << "Please select from the following list" << endl; // selection menu
        cout << "1) Sign in \n";
        cout << "2) Register \n";
        cout << "3) Exit \n";
        cout << "Your choice: "; cin >> user_choice;

        if(user_choice=="2") // REGISTER
        {
            string choice;

            {
                system("CLS");
                cout << "Are you a: \n";
                cout << "1) Student 2) Instructor \n(Press any other key to go back)\n";
                cout << "Your choice: "; cin >> choice; cout << endl;
                system("CLS");
                if (choice=="1")  // FOT STUDENT
                    {
                        Student temp;
                        cout << "Please enter your name: ";
                        cin >> temp.name; cout << endl;
                        cout << "Please enter your password: ";
                        cin >> temp.password; cout << endl;
                        cout << "Please enter your department: ";
                        cin >> temp.department; cout << endl;
                        cout << "Please enter your GPA (must be a number): ";
                        cin >> temp.gpa; cout << endl;

                        if(temp.gpa<0 || temp.gpa>4)
                        {
                            while (temp.gpa<0 || temp.gpa>4)
                            {
                                cout << "GPA must be between 0 and 4! Please input again: ";
                                cin >> temp.gpa;
                            }
                        }

                        temp.courses_enrolled.push_back("Empty.");
                        all_students.push_back(temp);
                        cout << "Your data has been stored! You will be returned to the main page." << endl << endl;
                        Sleep(3000);
                        system("CLS");

                    }
                 if (choice=="2") // FOR INSTRUCTOR
                    {
                        Instructor temp;
                        cout << "Please enter your name: ";
                        cin >> temp.name; cout << endl;
                        cout << "Please enter your password: ";
                        cin >> temp.password; cout << endl;
                        cout << "Please enter your department: ";
                        cin >> temp.department; cout << endl;
                        temp.my_courses.push_back("Empty.");
                        all_instructors.push_back(temp);
                        cout << "Your data has been stored! You will be returned to the main page." << endl << endl;
                        Sleep(3000);
                        system("CLS");

                    }

            }

        }

        if(user_choice=="1") // LOGIN
        {
            string choice;

            {
                system("CLS");
                cout << "Are you a: \n";
                cout << "1) Student 2) Instructor \n(Press any other key to go back)\n";
                cout << "Your choice: "; cin >> choice; cout << endl;
                system("CLS");
                if(choice=="2") // INSTRUCTOR LOGIN
                {
                    cout << "Please enter your name: ";
                    string temp_name; cin >> temp_name; cout << endl;
                    cout << "Please enter your password: ";
                    string temp_pass; cin >> temp_pass; cout << endl;
                    system("CLS");
                    int login_status=0;
                    for (unsigned int i=0; i<all_instructors.size(); i++)
                    {

                        if (all_instructors[i].name==temp_name && all_instructors[i].password==temp_pass)
                        {
                            login_status=1;
                            string option;
                            cout << "Login successful! \n";
                            cout << "Loading... " << temp_name << "! \n";
                            Sleep(2000);
                            system("CLS");
                            string check;
                            do
                            {
                            cout << "Please select from the following options: \n \n";
                            cout << "1) Students enrolled \n";
                            cout << "2) My courses \n";
                            cout << "3) Log out \n";
                            cout << "Your choice: "; cin >> option; cout << endl;
                            system ("CLS");

                            if (option=="2")
                            {
                                // Displaying name of courses saved in the my_courses vector of the particular all_instructors element.

                                cout << "Your courses are: \n";

                                for(unsigned int j=0; j<all_instructors[i].my_courses.size(); j++)
                                {
                                    cout << j+1 << ") " << all_instructors[i].my_courses[j] << endl;
                                }
                                cout << endl;
                                do
                                {
                                cout << "Press 1 to add a course, and 2 to drop a course. \nPress 3 to go back: \n";
                                cout << "Your choice: "; cin >> check; cout << endl;
                                system("CLS");

                                if (check=="1")
                                {
                                    system("CLS");
                                    cout << "Please enter the name of the new course: ";
                                    string new_course; cin >> new_course; cout << endl;

                                    if (all_instructors[i].my_courses[0]=="Empty.")
                                    {
                                        all_instructors[i].my_courses[0]=new_course;
                                    }
                                    else
                                    {
                                        all_instructors[i].my_courses.push_back(new_course);
                                    }
                                    Courses tempc;
                                    tempc.name=new_course;
                                    tempc.instructor_name=all_instructors[i].name;
                                    tempc.department=all_instructors[i].department;

                                    cout << "Enter the cap for this class: "; double capacity; cin >> capacity; cout << endl;
                                    tempc.capacity=capacity;

                                    all_courses.push_back(tempc);
                                    system ("CLS");

                                    cout << "Course '" << new_course << "' has been added! \n";
                                    cout << "Your courses are now: " << endl;
                                    for (unsigned int c=0; c<all_instructors[i].my_courses.size(); c++)
                                    {
                                        cout << c+1 << ") " << all_instructors[i].my_courses[c] << endl;
                                    }
                                    cout << endl;

                                }

                                if(check=="2")
                                {
                                    cout << "Please enter the number of the course you wish to drop: ";
                                    int d_course; cin >> d_course; cout << endl;
                                    for (unsigned int z=0; z<all_courses.size(); z++)
                                    {
                                        if (all_courses[z].name==all_instructors[i].my_courses[d_course-1])
                                        {
                                            if(all_courses[z].enrolled_students==0)
                                            {
                                                all_courses.erase(all_courses.begin()+z);
                                                all_instructors[i].my_courses.erase(all_instructors[i].my_courses.begin()+(d_course-1));
                                                system("CLS");
                                                cout << "The course has been dropped! \n";

                                            }

                                            else
                                            {
                                                cout << "Error: You can not drop a course while it has students enrolled! \n";
                                            }
                                        }
                                    }
                                }

                            }
                            while (check!="3");
                            }

                            if (option=="1")
                            {
                                for (unsigned int c=0; c<all_instructors[i].my_courses.size(); c++)
                                {
                                    cout << all_instructors[i].my_courses[c] << ": ";
                                    for(unsigned int s=0; s<all_students.size(); s++)
                                    {
                                        for (unsigned int a=0; a<all_students[s].courses_enrolled.size(); a++)
                                        {
                                            if (all_students[s].courses_enrolled[a]==all_instructors[i].my_courses[c])
                                            {
                                                cout << all_students[s].name << " ";
                                            }
                                        }
                                    }
                                    cout << endl;
                                }
                            }

                        }
                        while (option!="3");
                        }
                    }
                    if (login_status==0)
                    {
                        cout << "Incorrect username and/or password! You will be returned to the main screen. \n";
                        Sleep(3000);
                        system("CLS");
                    }
                }
                if (choice == "1") //STUDENT LOGIN
                {
                    cout << "Please enter your name: ";
                    string temp_name; cin >> temp_name; cout << endl;
                    cout << "Please enter your password: ";
                    string temp_pass; cin >> temp_pass; cout << endl;
                    system("CLS");
                    int login_status = 0;
                    for (unsigned int i=0; i<all_students.size(); i++)
                    {
                        if (all_students[i].name==temp_name && all_students[i].password==temp_pass)
                        {
                            string option;
                            cout << "Success! \n";
                            cout << endl;
                            cout << "Loading... " << temp_name << "! \n";
                            Sleep(2000);
                            system("CLS");
                            do
                            {
                            login_status=1;
                            cout << "Please select from the following options: \n \n";
                            cout << "1) My info \n";
                            cout << "2) My courses and add/drop \n";
                            cout << "3) Log out \n";
                            cout << "Your choice: "; cin >> option; cout << endl;
                            if (option == "1")
                            {
                               cout << "Your username is: " << all_students[i].name << endl;
                               cout << "Your password is: " << all_students[i].password << endl;
                               cout << "Your department is: " << all_students[i].department << endl;
                               cout << "Your GPA is: " << all_students[i].gpa << endl << endl;
                            }
                            else if (option == "2") //showing courses, giving option to add/drop
                            {
                               cout << "Courses you are currently enrolled in are: " << endl;
                               for (unsigned int c=0; c<all_students[i].courses_enrolled.size(); c++)
                               {
                                   cout << c+1 << ") '" << all_students[i].courses_enrolled[c] << "' by instructor ";
                                   for (unsigned int a=0; a<all_courses.size(); a++)
                                   {
                                       if (all_courses[a].name==all_students[i].courses_enrolled[c])
                                       {
                                           cout << "'" << all_courses[a].instructor_name << "' ";
                                       }
                                   }
                                   cout << endl;
                               }
                               cout << endl;
                               cout << "1) Add courses \n";
                               cout << "2) Drop courses \n";
                               cout << "Any other key to go back.\n";
                               cout << "Your choice: "; string s_option; cin>>s_option; cout << endl;

                               if (s_option=="1")
                               {

                               cout << "Which courses would you like to add? \n";
                               //Displaying all courses instructor wise
                               for (unsigned int a=0; a<all_instructors.size(); a++)
                               {
                                   cout << a+1 << ")" << all_instructors[a].name << ": ";
                                   for (unsigned int b=0; b<all_instructors[a].my_courses.size(); b++)
                                   {
                                       cout << b+1 << ") " << all_instructors[a].my_courses[b] << " ";
                                   }
                                   cout << endl;
                               }
                               cout << endl;

                               cout << "Enter the number of the instructor you want: ";
                               int temp_a = 0; cin >> temp_a; cout << endl;
                               cout << "Enter the number of the course you want: ";
                               int temp_b = 0; cin >> temp_b; cout << endl;

                               for (unsigned int in=0; in<all_courses.size(); in++)
                               {
                                   if(all_courses[in].name==all_instructors[temp_a-1].my_courses[temp_b-1])
                                   {
                                       if (all_courses[in].enrolled_students<all_courses[in].capacity)
                                       {
                                           if (all_students[i].courses_enrolled[0]=="Empty.")
                                            {
                                                all_students[i].courses_enrolled[0]=all_instructors[temp_a-1].my_courses[temp_b-1];
                                                cout << "Course '" << all_instructors[temp_a-1].my_courses[temp_b-1] << "' added successfully! " << endl;
                                            }
                                           else
                                            {
                                                all_students[i].courses_enrolled.push_back(all_instructors[temp_a-1].my_courses[temp_b-1]);
                                                cout << "Course '" << all_instructors[temp_a-1].my_courses[temp_b-1] << "' added successfully! " << endl;
                                            }
                                            all_courses[in].enrolled_students=all_courses[in].enrolled_students+1;
                                       }
                                       else
                                       {
                                           cout << "Course has no seats available! \n";
                                       }
                                   }
                               }
                               }

                               else if(s_option=="2")
                               {
                                    cout << "Enter the number of the course you want to drop: ";
                                    int d_course; cin >> d_course; cout << endl;
                                    //reducing number of students enrolled in that course
                                    for(unsigned int b=0; b<all_courses.size(); b++)
                                    {
                                        if (all_courses[b].name==all_students[i].courses_enrolled[d_course-1])
                                        {
                                            all_courses[b].enrolled_students=all_courses[b].enrolled_students-1;
                                        }
                                    }
                                    all_students[i].courses_enrolled.erase(all_students[i].courses_enrolled.begin()+(d_course-1));
                                    system("CLS");
                                    cout << "Course dropped! Your courses are now: \n";
                                    for (unsigned int c=0; c<all_students[i].courses_enrolled.size(); c++)
                               {
                                   cout << c+1 << ") '" << all_students[i].courses_enrolled[c] << "' by instructor ";
                                   for (unsigned int a=0; a<all_courses.size(); a++)
                                   {
                                       if (all_courses[a].name==all_students[i].courses_enrolled[c])
                                       {
                                           cout << "'" << all_courses[a].instructor_name << "' ";
                                       }
                                   }
                                   cout << endl;
                               }

                               }

                               else
                               {
                                   system("CLS");
                               }
                            }
                            else if((option!="1") || (option!="2") || (option!="3"))
                            {
                                system("CLS");
                            }
                            }
                            while(option!="3");

                        }
                    }
                    if (login_status==0)
                    {
                        cout << "Invalid username and/or password! You will be returned to the main screen. \n";
                        Sleep(3000);
                    }

                }
        }

        }
        }

    while (user_choice!="3");

    // saving all_instructors vector to all_instructors file:
    {
        ofstream out_instructor;
        out_instructor.open("all_instructors.txt");
        for(unsigned int i=0; i<all_instructors.size(); i++)
        {
            out_instructor << all_instructors[i].name << '\n' << all_instructors[i].password << '\n' << all_instructors[i].department << '\n';

            if (all_instructors[i].my_courses.size()==0)
            {
                out_instructor << "Empty." << endl;
            }

            else
            {
                for (unsigned int j=0; j<all_instructors[i].my_courses.size(); j++)
                {
                    out_instructor << all_instructors[i].my_courses[j] << " ";
                }
                out_instructor << endl;
            }
        }
    }

     // saving all_students vector to all_students file:

    {
        ofstream out_student;
        out_student.open("all_students.txt");
        for(unsigned int i=0; i<all_students.size(); i++)
        {
            out_student << all_students[i].name << '\n' << all_students[i].password << '\n' << all_students[i].department << '\n' << all_students[i].gpa << '\n';
            out_student << all_students[i].total_courses << '\n';

            if (all_students[i].courses_enrolled.size()==0)
            {
                out_student << "Empty." << endl;
            }

            else
            {
                for (unsigned int j=0; j<all_students[i].courses_enrolled.size(); j++)
                {
                    out_student << all_students[i].courses_enrolled[j] << " ";
                }
                out_student << endl;
            }
        }
    }

    {
        ofstream out_courses;
        out_courses.open("all_courses.txt");
        for(unsigned int i=0; i<all_courses.size(); i++)
        {
            out_courses << all_courses[i].name << '\n' << all_courses[i].instructor_name << '\n' << all_courses[i].department << '\n' << all_courses[i].capacity << '\n';
            out_courses << all_courses[i].enrolled_students << '\n';
        }
    }
}



