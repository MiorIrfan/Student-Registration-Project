#include <iostream>
#include<string>
#include<fstream>
#include<iomanip>
#ifndef REGISTER_H
#define REGISTER_H
using namespace std;
		
class Register
{
	private:
		struct listNode{
			string subjectName, code;
			int unit, semester=0;
			double grade=0.0;
			struct listNode *next;
		};
		
		double cgpa; //new code
		
		listNode *head;
		listNode *allSubjectsList;
		void appendSubjects(string, string, int);
		void set_subjectlist();
			
	public:
		Register();
//			{head=nullptr;
//			allSubjectsList=nullptr;
//			set_subjectlist();}
		~Register();
		
		void appendPrevSem(string, string, int, int, double);
		void deleteNode(int);
		void registerSubject_number(int);
		void registerSubject_code(string);
		void displayRegistration();
		void displayPrevSem();
		void displayAllList();
		void displayList();
		void cal_CGPA(); 
		void cal_GPA(int);
		void get_CGPA() const 
			{cout << "CGPA: " <<setprecision(2)<<fixed<<cgpa<<endl;}
			
		int totalUnit();
		bool findTruth1(string);
		bool findTruth2(int);
		void submit(const Register &obj, string, string, int);
		
};
#endif

//void Register::cal_CGPA()
//{
//	listNode *nodePtr = nullptr;
//	double totalGrade=0;
//	
//	nodePtr = head;
//	while(nodePtr)
//	{
//		totalGrade += (nodePtr->grade * nodePtr->unit);
//		nodePtr = nodePtr->next;		
//	}
//	cgpa = totalGrade/totalUnit();
//	
//}
//
//void Register::cal_GPA(int num)
//{
//	listNode *nodePtr = nullptr;
//	double totalGrade=0, totalUnit=0;
//	
//	nodePtr = head;
//	while(nodePtr)
//	{
//		if(nodePtr->semester == num)
//		{
//			totalGrade += (nodePtr->grade * nodePtr->unit);
//			totalUnit += nodePtr->unit;
//		}	
//		nodePtr = nodePtr->next;		
//	}
//	
//	if(totalGrade == 0)
//	{
//		cout << "No data for the particular semester.";
//	}
//	else
//		cout << "The GPA for semester " << num << " is: " << totalGrade/totalUnit;
//	cout<<endl;
//}
//
//
////member function 
//void Register::set_subjectlist(){
//	
////	appendSubjects("Fundamentals of Logic and Artificial Intelligence", "A", 4);
//// 	appendSubjects("Foundation and Programming for Data Analytics", "B", 4);
//// 	appendSubjects("Programming Methodology and Data Structures", "Ga", 3);
//// 	appendSubjects("Principles of Programming", "Ca", 3);
// 	appendSubjects("Fundamentals of Logic and Artificial Intelligence", "CPC151", 4);
// 	appendSubjects("Foundation and Programming for Data Analytics", "CPC152", 4);
// 	appendSubjects("Programming Methodology and Data Structures", "CPT113", 3);
// 	appendSubjects("Principles of Programming", "CPT111", 3);
// 	appendSubjects("Discrete Structures", "CPT112", 4);
// 	appendSubjects("Computer Organisation", "CST131", 3);
// 	appendSubjects("Penghayatan Etika dan Peradaban", "HFE224", 2);
// 	appendSubjects("Falsafah", "HFF225", 2);
// 	appendSubjects("Bahasa Malaysia IV", "LKM400", 2);
// 	appendSubjects("English", "LSP404", 2);
//// 	
//}
//
//
//void Register::appendNode(string x, string y, int num, int num2, double num3){
//	listNode *newNode, *nodePtr = nullptr;
//	
//	newNode = new listNode;
//	newNode->subjectName = x;
//	newNode->code = y;
//	newNode->unit = num;
//	newNode->semester = num2;
//	newNode->grade = num3;
//	newNode->next = nullptr;
//
//   // If there are no nodes in the list
//   // make newNode the first node
//   if (!head)
//      head = newNode;
//   else  // Otherwise, insert newNode at end
//   {
//      // Initialize nodePtr to head of list
//      nodePtr = head;
//
//      // Find the last node in the list
//      while (nodePtr->next)
//         nodePtr = nodePtr->next;
//
//      // Insert newNode as the last node
//      nodePtr->next = newNode;
//   }
//}
//
//void Register::appendSubjects(string x, string y, int num){
//	listNode *newNode, *nodePtr = nullptr, *prevNode = nullptr;
//	
//	newNode = new listNode;
//	
//	newNode->subjectName = x;
//	newNode->code = y;
//	newNode->unit = num;
//	newNode->next = nullptr;
//
//   if (!allSubjectsList)
//		allSubjectsList = newNode;
//   else
//   {
//      nodePtr = allSubjectsList;
//
//      while (nodePtr && nodePtr->code <= newNode->code)
//      {
//      	prevNode = nodePtr;
//      	nodePtr = nodePtr->next;
//	  }
//	  
//
//    	if(prevNode->next = nullptr)
//		{
//			allSubjectsList = newNode;
//			newNode->next = nodePtr;
//    	}
//		else
//		{
//			prevNode->next = newNode;
//			newNode->next = nodePtr;
//		}    
//		
//			
//   }
//}
//
//void Register::deleteNode(int num)
//{
//	listNode *nodePtr, *previousNode = nullptr;
//	int counter = 1;
//
//   // If the list is empty, do nothing.
//   if (!head)
//   	{
//   	  cout<<"No course have been registered."<<endl;
//      return;
//	}
//   // Determine if the first node is the one.
//   if (counter == num)
//   {
//      nodePtr = head->next;
//      delete head;
//      head = nodePtr;
//   }
//   else
//   {
//      nodePtr = head;
//
//	  while (nodePtr != nullptr && counter != num)
//      {  
//         previousNode = nodePtr;
//         nodePtr = nodePtr->next;
//         counter++;
//      }
//
//      if (nodePtr)
//      {
//         previousNode->next = nodePtr->next;
//         delete nodePtr;
//      }
//   }
//}
//
//void Register::displayAllList(){
//	
//	listNode *nodePtr = nullptr;
//	int counter=1;
//
//   nodePtr = allSubjectsList;
//   
//   while (nodePtr)
//   {
//      cout << counter << "> " << nodePtr->code << " ";
//      cout << nodePtr->subjectName << endl;
//      nodePtr = nodePtr->next;
//      counter++;
//   }
//   
//}
//	
//void Register::displayCurrent(){
//	listNode *nodePtr = nullptr;
//	
//	int counter=1;
//   nodePtr = head;
//   while (nodePtr)
//   {
//      cout << counter << ":- Subject code: " <<nodePtr->code << "  ";
//      cout << nodePtr->subjectName << " ";
//      cout << "Unit: " << nodePtr->unit << endl;
//      nodePtr = nodePtr->next;
//      counter++;
//   }
//}
//
//void Register::displayPrevSem(){
//	listNode *nodePtr = nullptr;
//	
//	int counter=1;
//   nodePtr = head;
//   while (nodePtr)
//   {
//   		cout << counter << ":- Subject : " <<nodePtr->subjectName << endl;
//    	cout << "Subject code: " <<nodePtr->code << "  ";
//   		cout << "Unit: " << nodePtr->unit << "  ";
//    	cout << "Semester: " << nodePtr->semester << "  ";
//    	cout << "Grade: " << fixed << setprecision(2) << nodePtr->grade << endl << endl;
//    	nodePtr = nodePtr->next;
//    	counter++;
//   }
//}
//
//
//
//void Register::insertAdd(string addSubject) 
//{
//	listNode *newNode,
//	         *nodePtr,
//	         *current,
//			 *previousNode = nullptr;
//			 
//	newNode = new listNode;
//	current = allSubjectsList;
//	
//	while (current!=nullptr) {
//		if (current->code == addSubject)
//		{
//			newNode->code = addSubject;
//			newNode->subjectName = current->subjectName;
//			newNode->unit = current->unit;
//			break;
//		}
//		current = current->next;
//	}
//	
//	if (!head)
//	{
//		head = newNode;
//		newNode->next = nullptr;
//	}
//	else
//	{
//		nodePtr = head;
//		previousNode = nullptr;
//		
//		while (nodePtr != nullptr && nodePtr->code < addSubject)
//		{
//			previousNode = nodePtr;
//			nodePtr = nodePtr->next;
//		}
//		
//		if (previousNode == nullptr)
//		{
//			head = newNode;
//			newNode->next = nodePtr;
//		}
//		else
//		{
//			previousNode->next = newNode;
//			newNode->next = nodePtr;
//		}
//	}
//}
//
////void Register::sortSubject()
////{
////	
////	listNode *previousNode = head,
////	         *nodePtr = head->next;
////	         
////	while (previousNode!=nullptr)
////	{
////		if(nodePtr->code < previousNode->code)
////		{
////			previousNode->next = nodePtr->next;
////			nodePtr->next = head;
////			head = nodePtr;
////			nodePtr = previousNode;
////		}
////		else
////		{
////			previousNode = nodePtr;
////			nodePtr = nodePtr->next;
////		}
////	}
////}
//
//void Register::sortSubject(int num)
//{
//	
//	listNode *newNode, *nodePtr = nullptr, *subjectNode=nullptr, *prevNode=nullptr;
//	int counter=1;
//	
//	newNode = new listNode;
//	
//	if(!head){
//		nodePtr = allSubjectsList;
//		while(nodePtr != nullptr && counter != num){
//			nodePtr = nodePtr->next;
//			counter++;
//		}
//			
////		newNode = nodePtr;	
//		newNode->subjectName = nodePtr->subjectName;
//		newNode->unit = nodePtr->unit;
//		newNode->code = nodePtr->code;
//		head = newNode;
//	}
//	else{
//		nodePtr = allSubjectsList;
//		subjectNode = head;
//		
////		while(subjectNode->next)
////			subjectNode=subjectNode->next;
//		
//		while(nodePtr != nullptr && counter != num){
//			nodePtr = nodePtr->next;
//			counter++;
//		}
//		
//		newNode->subjectName = nodePtr->subjectName;
//		newNode->unit = nodePtr->unit;
//		newNode->code = nodePtr->code;
//		
//		while (subjectNode != nullptr && subjectNode->code < nodePtr->code)
//	    {  
//	        prevNode = subjectNode;
//	        subjectNode = subjectNode->next;
//	    }
//		
//		
//	    if (prevNode == nullptr)
//    	{
//        	head = newNode;
//        	newNode->next = subjectNode;
//        }
//      	else  // Otherwise, insert it after the prev node
//      	{
//        	prevNode->next = newNode;
//        	newNode->next = subjectNode;
//      	}
////		subjectNode->next = newNode;
//	}
//}
//
//int Register::totalUnit()
//{
//	int total=0;
//	listNode*nodePtr=nullptr;
//	
//	if(!head)
//	{
//		cout<<"Current semester have not been registered."<<endl;
//	}
//	else
//	{
//		nodePtr=head;
//		while(nodePtr!=nullptr)
//		{
//			total+=nodePtr->unit;
//			nodePtr=nodePtr->next;
//		}	
//	}
//	
//	return total;	
//}
//
//Register::~Register(){
//	listNode *nodePtr, *nextNode = nullptr;
//
//   nodePtr = head;
//   while (nodePtr != nullptr)
//   {
//      nextNode = nodePtr->next;
//      delete nodePtr;
//      nodePtr = nextNode;
//   }
//   head = nullptr;
//}
