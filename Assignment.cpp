#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "SystemUser.h"
#include "Assignment.h"
#include "Classroom.h"
#include "typeEffect.h"
////////implementing Assignment functions////////
Assignment::Assignment()
{
    totalQuestions= 0;
}
int Assignment::getTotalQuestions()
{
    return totalQuestions;
}
void Assignment::setTotalQuestions()
{
    cout<<"Enter the total number of questions: ";
    cin>>totalQuestions;
}
void Assignment::OpenFile(fstream &file)
{
    if(userCourse == "Object Oriented Programming")
        file.open("oop.txt", ios ::in |ios::app);
    else if(userCourse == "Artificial Intelligence")
        file.open("ai.txt",ios ::in | ios::app);
    else if(userCourse == "Data Structures")
        file.open("dsa.txt", ios ::in |ios::app);
    else if(userCourse == "Big Data Analytics")
        file.open("bdata.txt", ios ::in |ios::app);
    else if(userCourse == "Programming Fundamentals")
        file.open("pf.txt", ios ::in | ios::app);
  else 
    cout<< "\n [ERROR] Unable to open file. No course found.";
}
fstream Assignment::ReadQuestionsFile()
{
    fstream file;
    string line,extra;
    s= 0;
    OpenFile(file);
    while(getline(file, line)) 
        {
            if(line.find("Descriptive") != string ::npos)
            // process the question and answer
            {
                getline(file, subjective[s], '`');
                //cout<<TF[j]<<endl;
                getline(file, subjective_answers[s], '\n');
                s++;
            }   
        }
    file.close();
    return file;  
}

void Assignment::viewQuestions()  
{
    string line;
    fstream questions = ReadQuestionsFile();
    OpenFile(questions);
    m=t=0;
    while(getline(questions, line))
    {
      if(line == "Descriptive")
        cout<<subjective[s++]<<endl<<endl;
    }
    ReadQuestionsFile().close();
    //system_menu.displayMenu(); 
}


void Assignment::UploadAssignment()   
{
    string filePath;
    cout<<"Enter file name: ";
    cin>>filePath;
    ifstream assignmentFile(filePath);
    if (assignmentFile.is_open())
    {
      
        typeEffect("Assignment uploaded successfully!\n",100);
        assignmentFile.close();
    }
    else
    {
        cout << "Unable to open the file for uploading the assignment.\n";
    }
}



void Assignment::AccessAssignment() 
{
   
    ifstream studentData("classlist.txt");
    if (studentData.is_open())
    {
        
        getline(studentData, userCourse, ';');
        getline(studentData, userName, ';');
    
        string courseFile= userCourse + ".txt";
        
        cout<<endl;
        ifstream assignmentFile(courseFile);
        if (assignmentFile.is_open())
        {
            cout << "Assignment Questions:\n";
            string line;
            while (getline(assignmentFile, line))
            {
                cout << line << endl;
            }
            assignmentFile.close();

                cin.ignore();
                cout << "Submit your answers:\n";
               
                getline(cin, userAnswer, '\n');
         
                typeEffect("\nAnswers submitted successfully!\n",100);
            }
        
        else
        {
            cout << "\nUnable to open the file for accessing the assignment."  << courseFile << " Could not be accessed.\n";
        }
    }
    else
    {
        cout << "Unable to open the student data file.\n";
    }
}
void Assignment::CalculateScore()
{
    string keyWords[] = {
        "Machine Learning", "Neural Networks", "Deep Learning", "Natural Language Processing",
        "Expert Systems", "Decision Trees", "Reinforcement Learning", "Computer Vision",
        "Intelligent Agents", "Hadoop", "MapReduce", "Data Mining", "Data Warehousing",
        "Data Processing", "Predictive Analysis", "Machine Learning", "Clustering", "Arrays",
        "Linked Lists", "Stacks", "Queues", "Graphs", "Linked Lists",
        "Sorting Algorithms", "Classes", "Objects", "Inheritance", "Polymorphism",
        "Encapsulation", "Abstraction", "Method Overriding", "Constructors", "Destructors",
        "Programming", "Variables", "Control Structures", "Functions", "Loops",
        "Conditional Statements", "Arrays", "Pointers", "Input/Output", "Data Types",
        };
  
    int number_ofWords= 0, character= 0, userScore= 0;
    // for loop to check for length i.e number of words
    // \0 is the null value where string ends
    for( character= 0; userAnswer[character]>'\0'; character++)
    {
      if (userAnswer[character]== ' ')
        number_ofWords++;
    }
    userScore= number_ofWords + 1; // marks on number of words
    for(const string& key:keyWords)
    {
        if(userAnswer.find(key) != string::npos)
        {
            userScore+= 5; // add 5 points each time keyword occurs in answer
        }
    }
    // write record in a file
    fstream file_out("records.txt", ios:: app);
    if(!file_out.is_open())
    {
         cout<<"Failed to open the file."<<endl;
    }
    file_out<<userName<<";"<<userCourse<<";"<<userScore<<"\n";
  
    typeEffect("\nRecord saved successfully!",100);
    cout<<endl;
    file_out.close();
}

void Assignment::DisplayResult()
{

  
    ifstream recordsFile("records.txt", ios::in);
    if (recordsFile.is_open())
    {
        string fileLine;
        string studentData,fileUsername,marks;
        while (getline(recordsFile, studentData))
        {
            stringstream stream(studentData);    
            getline(stream, fileUsername, ';');
            getline(stream, subjectName, ';');
            getline(stream, marks);  
            //if (fileUsername == userName)
           // {
                cout<<"Username: "<<fileUsername<<", Subject: "<<subjectName<<", Marks: "<<marks<<endl;
                
            //}     
        }
        recordsFile.close();
    }
    else
    {
        cout << "Unable to open the records file.\n";
    }
 
}
