/*This program is build as the Registration System by Group 18. 
  This program allow a user (student) to see the list of subject from previous semester,
  check their CGPA and GPA, register or add the courses, remove some of the registered courses
  and check the total unit for previous, current or both semester */
#include<iostream>
#include "Register.h"
using namespace std;


//main program
int main(){
	
//	string name, subjectName, code, subject, ikan ="dhushdia";
	string name,        //Name of student
		   subjectName, //Name of subject/course
		   code,        //Subject code 
		   subject,     //Subject code to add/register course
		   fileName;	//Hold the filename
	int num,            //Used for input(choices)
		matric,         //Matric number of student
		unit,           //Unit of previous subject/course
		sem,            //Previous semester 
		semesterChoice, //Choices to check total unit based on semester
		option;         //Choices from the main menu
	double grade;       //Grade of subject taken from previous semester
	char ch;            //Used for input(choices)
	
	//Instance of class
	Register obj, prevSem;

	cout << "Enter the file name: ";
	getline(cin,fileName);
	//Read the content in the file
	ifstream StudentFile(fileName);
	StudentFile.clear();
	StudentFile.seekg(0,ios::beg);
	
	//Input the name and matric of a student
	getline(StudentFile,name,'\t');
	StudentFile >> matric;
	StudentFile.ignore();
	
	//Input subject/course taken from previous semester
	while(!StudentFile.eof())
	{
		getline(StudentFile,subjectName,'\t');
		getline(StudentFile,code,'\t');
		StudentFile >> unit;
		StudentFile >> sem;
		StudentFile >> grade;
		StudentFile.ignore();
		
		prevSem.appendPrevSem(subjectName, code, unit, sem, grade);
	}
	
	//Close the file
	StudentFile.close(); 

	
	while(option!=9)
	{ 
	    // Display main menu for registration system
		cout<<"#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#"<<endl;
		cout<<"|"<<setw(38)<<"UNIVERSITI SAINS MALAYSIA"<<setw(15)<<"|"<<endl;
		cout<<"|"<<setw(36)<<"REGISTRAITION SYSTEM"<<setw(17)<<"|"<<endl;
		cout<<"#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#"<<endl;
		
		cout<<"|Name of student: " << name <<setw(16)<<"|"<<endl;
		cout<<"|Matric: " << matric <<setw(39)<<"|"<< endl;
		cout<<"#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#"<<endl;
		cout<<"|1.List of subjects taken in previous semesters"<<setw(7)<<"|"<<endl;
		cout<<"|2.CGPA and GPA of student"<<setw(28)<<"|"<<endl;
		cout<<"|3.Course registration (Order Pick)"<<setw(19)<<"|"<<endl;
		cout<<"|4.Course registration (Code Input)"<<setw(19)<<"|"<<endl;
		cout<<"|5.Remove course"<<setw(38)<<"|"<<endl;
		cout<<"|6.Total unit"<<setw(41)<<"|"<<endl;
		cout<<"|7.Submit"<<setw(45)<<"|"<<endl;
		cout<<"|8.Exit and cancel registration"<<setw(23)<<"|"<<endl;
		cout<<"#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#"<<endl;
		
		
		//Input user(student) choice based on main menu
		cout<<"Please enter any option from the menu: ";
		cin>>option;
		
		//Input validation for choices based on main menu
		while(option<1||option>9)
		{
			cout<<"Error please input the number of the available option.\n";
			cout<<"Please enter any option from the menu: ";
			cin>>option;
		}
		cout << endl;
		
		//Selection based on the choices made by user(student)
		if(option==1)
		{
			prevSem.displayPrevSem(); //Display list subjects taken from previous semester
			
			cin.ignore();
			cout << "\nPress enter to continue";
			cin.get();
		}
		else if(option==2)
		{
			prevSem.cal_CGPA();	
			prevSem.get_CGPA();
			cout << "\nEnter semester to find the GPA (1,2,3...): ";
			cin >> num;
			
			prevSem.cal_GPA(num); //Calculate the GPA either semester 1 or 2
			
			cin.ignore();
			cout << "Press enter to continue";
			cin.get();
	
		}
		else if(option==3)
		{
			
			obj.displayAllList(); //Display available subjects that can be registered
			
			//Input for registering the course by entering a number based on menu
			cout << "\nChoose a subject to register (0,1,2...): ";
			cin >> num;
			
			while(num != 0)
			{
				if (obj.findTruth2(num))
				{
					cout << "You already register this course! ";
					cout << "\nEnter a number to register course (0,1,2...): ";
					cin >> num;
				}
				else
				{
					//Register the course entered into list of registered course
					obj.registerSubject_number(num); 
					//Display the current registered course
					obj.displayRegistration();
					
					cout << "\nChoose a subject to register: ";
					cin >> num;
				}
			}
			
		
		}
		else if(option==4)
		{			
			
			obj.displayList(); //Display available subjects that can be registered
			
			//Input for registering the course by entering subject code
			cout << "\nEnter subject code to add to the list (E.g. CPC151): ";
			cin >> subject;
			
			while(subject != "0")
			{
				if (obj.findTruth1(subject))
				{
					cout << "You already register this course! ";
					cout << "\nEnter subject code to add to the list (E.g. CPC151): ";
					cin >> subject;
				}
				else
				{
					//Function to register the course entered into list of registered course
					obj.registerSubject_code(subject); 
					//Function to display the current registered course
					obj.displayRegistration();
					
					cout << "\nEnter subject code to add to the list (E.g. CPC151): ";
					cin >> subject;
				}
			}	
		}
		else if(option==5)
		{
			do
			{
				//Display the current registered course
				obj.displayRegistration();
				
				//Input to remove particular course from the registered courses
				cout << "Enter number to delete from the list: ";
				cin >> num;
				
				//Function to remove/delete particular course
				obj.deleteNode(num);
				obj.displayRegistration();
				
				//Input to ask user(student) whether want to remove another course or not
				cout << "\nDo you want to remove another subject? (y/n): ";
				cin >> ch; 
			}
			while(ch=='y' || ch=='Y');
		
		}
		else if(option==6) 
		{
			do
			{
		
				cout<<"(1)previous semester total unit"<<endl
					<<"(2)current semester total unit"<<endl
					<<"(3)total unit for both semester"<<endl;
				cout<<"Choose the number above:";
				cin>>semesterChoice;
				cout<<endl;
				
				//Input validation
				while(semesterChoice<1||semesterChoice>3)
				{
					cout << "Error choose only the available option.\n"
						 <<"Choose the number above:";
					cin >> semesterChoice;
					cout << endl;
				
				}
				
				//Selection to check total unit either previous or current or both semester
				if(semesterChoice==1)
				{
					cout << "Total unit for previous sem:" << prevSem.totalUnit() << endl;
				}
				else if(semesterChoice==2)
				{
					cout << "Total unit for current sem:" << obj.totalUnit() << endl;
				}
				else if(semesterChoice==3)
				{
					cout << "Total unit for both previous and current semester:"
						 << (prevSem.totalUnit()+obj.totalUnit()) << endl;
				}		
				
				cout << "Do you want to continue to see the other total unit?(y/n):";
				cin >> ch;
			}while(ch=='y' || ch=='Y');
		}
		else if(option==7)
		{
			cout << "Registration pending for the following subjects\n";
			obj.displayRegistration();
			cout << "\nConfirm submission? (y/n): ";
			cin >> ch;
			
			if (ch == 'y')
			{
				//Function to update the registered course to new file 
				obj.submit(prevSem, name, fileName, matric); 
			
				cout << "====================================================\n";
				cout << "Your registration is completed.\n"
					 <<"Thank you."<<endl;
				cout << "====================================================" << endl;	  
				break;			
			}
			
		}
		else if(option==8)
		{
			cout << "====================================================\n";
			cout << "Your registration is cancelled.\n"
				 <<"Try again." << endl;
			cout << "====================================================" << endl;	  
			break;
		}

	}
	
	
	return 0;
}




//int main(){
//	
//	string name, subjectName, code, subject, choice;
//	int num, matric, unit, sem,semesterChoice,option;
//	double grade;
//	char ch;
//	Register obj, prevSem;
//
//	ifstream StudentFile("ali.txt");
//	StudentFile.clear();
//	StudentFile.seekg(0,ios::beg);
//	
//	getline(StudentFile,name,'\t');
//	StudentFile >> matric;
//	StudentFile.ignore();
//	
//	while(!StudentFile.eof())
//	{
//		getline(StudentFile,subjectName,'\t');
//		getline(StudentFile,code,'\t');
//		StudentFile >> unit;
//		StudentFile >> sem;
//		StudentFile >> grade;
//		StudentFile.ignore();
//		
//		prevSem.appendNode(subjectName, code, unit, sem, grade);
//	}
//	StudentFile.close(); //Close the file
//	
//	while(option!=7)
//	{
//		cout<<"#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#"<<endl;
//		cout<<"|"<<setw(38)<<"UNIVERSTI SAINS MALAYSIA"<<setw(15)<<"|"<<endl;
//		cout<<"|"<<setw(36)<<"REGISTRAITION SYSTEM"<<setw(17)<<"|"<<endl;
//		cout<<"#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#"<<endl;
//		
//		cout<<"|Name of student: " << name <<setw(16)<<"|"<<endl;
//		cout<<"|Matric: " << matric <<setw(39)<<"|"<< endl;
//		cout<<"#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#"<<endl;
//		cout<<"|1.List of subjects taken in previous semesters"<<setw(7)<<"|"<<endl;
//		cout<<"|2.CGPA and GPA of student"<<setw(28)<<"|"<<endl;
//		cout<<"|3.Course registration"<<setw(32)<<"|"<<endl;
//		cout<<"|4.Add course"<<setw(41)<<"|"<<endl;
//		cout<<"|5.Remove course"<<setw(38)<<"|"<<endl;
//		cout<<"|6.Total unit"<<setw(41)<<"|"<<endl;
//		cout<<"|7.Exit program"<<setw(39)<<"|"<<endl;
//		cout<<"#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#"<<endl<<endl;
//		
//		
//		
//		cout<<"Please enter any option from the menu:";
//		cin>>option;
//		
//		if(option==1)
//			prevSem.displayPrevSem();
//		else if(option==2)
//		{
//			prevSem.cal_CGPA();	
//			prevSem.get_CGPA();
//			cout << "\nEnter semester to find the GPA(1/2): ";
//			cin >> num;
//			prevSem.cal_GPA(num);
//	
//		}
//		else if(option==3)
//		{
//			obj.displayAllList();
//		
//			do
//			{
//				cout << "\nChoose a subject to register: ";
//				cin >> num;
//				obj.sortSubject(num);
//				obj.displayCurrent();
//				
//				cout << "Do you want to register another course? (y/n): ";
//				cin >> ch;
//			
//			}while(ch=='y' || ch=='Y');
//		
//		}
//		else if(option==4)
//		{
//
////			cout<<"Test: " << endl;
////			obj.displayCurrent();
//	    	obj.displayAllList();
//	    	
//			//adding subject
//			do
//			{
//				cout << "Enter subject code to add to the list (E.g. CPC152): ";
//				cin >> subject;
//				obj.insertAdd(subject);
//				obj.displayCurrent();
//				
//				cout << "\nDo you want to add another subject? (y/n): ";
//				cin >> choice; 
//				
////				while (choice!="y" || choice!="Y" || choice!="n")
////				{
////					cout << "Invalid input. Please try again. Do you want to add another subject? (y/n): ";
////					cin >> choice;
////				}
//			}while(choice == "y" || choice == "Y");
//			//obj.displayCurrent();
//		}
//		else if(option==5)
//		{
//			do
//			{
//				
//				obj.displayCurrent();
//				cout << "Enter number to delete from the list: ";
//				cin >> num;
//				obj.deleteNode(num);
//				obj.displayCurrent();
//				
//				cout << "\nDo you want to remove another subject? (y/n): ";
//				cin >> ch; 
//			}
//			while(ch=='y');
//		
//		}
//		else if(option==6)
//		{
//			do
//			{
//		
//				cout<<"(1)previous semester total unit"<<endl
//					<<"(2)current semester total unit"<<endl
//					<<"(3)total unit for both semester"<<endl;
//				cout<<"Choose the number above:";
//				cin>>semesterChoice;
//				if(semesterChoice==1)
//				{
//					cout<<"Total unit for previous sem:"<<prevSem.totalUnit()<<endl;
//				}
//				else if(semesterChoice==2)
//				{
//					cout<<"Total unit for current sem:"<<obj.totalUnit()<<endl;
//				}
//				else if(semesterChoice==3)
//				{
//					cout<<"Total unit for both previous and current semester:"
//						<<(prevSem.totalUnit()+obj.totalUnit())<<endl;
//				}		
//				
//				cout<<"Do you want to continue to see the other total unit?(y/n):";
//				cin>>ch;
//			}while(ch=='y');
//		}
//	
//	
//	
//	}
////new code
////	prevSem.cal_CGPA();	
////	prevSem.get_CGPA();
////	
////	cout << "\nEnter semester to find the GPA: ";
////	cin >> num;
////	prevSem.cal_GPA(num);
////end of new code
//	
//	//registering subject
////	cout << "Course Registration\n";
////	obj.displayAllList();
////	
////	for(int i=0; i<4; i++){
////		cout << "\nChoose a subject to register: ";
////		cin >> num;
////		obj.insertNode(num);
////		obj.displayCurrent();
////	}
////	
//	//removing subject
//
//	
////	while(ch == 'y'){
////		cout << "Enter number to delete from the list: ";
////		cin >> num;
////		obj.deleteNode(num);
////		obj.displayCurrent();
////		
////		cout << "\nDo you want to remove another subject? (y/n): ";
////		cin >> ch; 
////	}
////	
//	//calculate unit
////	cout<<"Do you want to see the total unit for the courses?(y/n):";
////	cin>>ch;
////	while (ch=='y')
////	{
////		
////		cout<<"(1)previous semester total unit"<<endl
////			<<"(2)current semester total unit"<<endl
////			<<"(3)total unit for both semester"<<endl;
////		cout<<"Choose the number above:";
////		cin>>semesterChoice;
////		if(semesterChoice==1)
////		{
////			cout<<"Total unit for previous sem:"<<prevSem.totalUnit()<<endl;
////		}
////		else if(semesterChoice==2)
////		{
////			cout<<"Total unit for current sem:"<<obj.totalUnit()<<endl;
////		}
////		else if(semesterChoice==3)
////		{
////			cout<<"Total unit for both previous and current semester:"
////				<<(prevSem.totalUnit()+obj.totalUnit())<<endl;
////		}		
////		
////		cout<<"Do you want to continue to see the other option?(y/n):";
////		cin>>ch;
////	}
//	
//	return 0;
//}
