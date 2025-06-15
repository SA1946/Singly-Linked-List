#include<iostream>
#include<string>
#include<conio.h>
#include<windows.h>
#include <cstdlib>
#include <cctype> // For toupper()/tolower()
#include <fstream> // For file operations
#include <sstream> // For string stream operations
using namespace std;

struct NodeType{
	float data;
	NodeType *next;
	NodeType(float value){
		data = value; 
		next = nullptr;
	}
};

class SinglyLinkedList{
	private:
		NodeType* plist; // Head pointer
	public:
		void underLine(){
			cout<<"\n\n\n\n";	
		}
		
		//--------initialize---------
		void initialize(){
			plist = nullptr;
			cout<<"\n\tSingly Linked List initialized.\1\3\n";
		}
		
		//--------getNode---------
		NodeType* getNode(){
			struct NodeType *p;
			p = (struct NodeType*)malloc(sizeof(struct NodeType));		
			return p;
		}
		
		//--------freeNode---------
		void freeNode(NodeType* node){
			if(node != nullptr){
			 free(node);
			}
		}
		
		//--------createList---------
		void createList(){
			again:
			NodeType *p , *ptr;
			float datafloat;
			string num;
			cout<<"\n\tEnter number of node: "; cin>>num;
			int n  = stoi(num);// Convert string to int for switch
			if(n <= 0){
				cout<<"\n\tPlease enter any key to try again... \1\1";
				getch();
				system("cls");
				goto again;
			} 
			
			//Clear if existing list
        	while (plist != nullptr) {
            	NodeType* temp = plist;
            	plist = plist->next;
            	freeNode(temp);
        	}	
        	cout<<"\nEnter data for node: \n";
        	for(int i=1 ; i<=n ; i++){
        		cout<<"Node "<<(i) <<": ";cin>>datafloat;
        		p=getNode();
				p->data = datafloat;
				p->next = nullptr;		
				if(plist == nullptr){
					plist = p;
					ptr = p;	
				}
				else{		
					ptr->next = p; 
					ptr = p;
				}
			}
			cout<<"List create successfully \1\3\n";
		}
		
		//--------Traverse or display the list---------
		void traverse(){
			if(plist == nullptr){
				cout<<"\n\tYour list is empty.\n";
				return;
			}
			cout<<"\n\tSingly Linked List: ";
			NodeType *ptr = plist;
			while(ptr != nullptr){
				cout<<ptr->data;
				if(ptr->next != nullptr){
					cout<<" -> ";
				}
				ptr = ptr->next;
			}
			cout<<" -> NULL \n";			
		}
		
		//--------countNodes---------
		int countNode(){
			int count = 0;
			NodeType* ptr = plist;
			while(ptr != nullptr){
				count++;	         
			 ptr = ptr->next;
			}
			return count;
		} 
		
		//--------searchPosition---------
		void searchPosition(){
			float value , position = 1 ; 
			NodeType *ptr = plist;
			cout<<"\n\tEnter value of node to search: ";cin>>value;
			while(ptr != nullptr){
				if(ptr->data == value){	
					cout<<"\n\tValue:" <<value<<" found at position :"<<position;
					cout<<"\n\tAddress :" <<ptr<<endl;
					return;
				}else{	
				ptr = ptr->next;	
				}
				position++;
			}
				cout<<"\nValue:"<<value<<" not found in list \1\1\n" ;
		}
		
		//--------searchValue---------
		void searchValue(){
			float value;
			NodeType *ptr = plist;
			cout<<"\n\tEnter value to search: ";cin>>value;
			while(ptr != nullptr){
				if(ptr->data == value){
					cout<<"\n\tNode with value: "<<value<<" found...";
					cout<<"\n\tNode address:"<<ptr;
					cout<<"\n\tNode data: "<<ptr->data<<endl;
					return;	
				}		
				ptr = ptr->next;
			}
				cout<<"\nValue:"<<value<<" not found in list \1\1\n" ;
		}
		
		//--------Sort---------
		void sort(){
			NodeType *p , *ptr;
			float temp; 
			bool checked = false;
			if(plist == nullptr || plist->next == nullptr){
				cout<<"\n\tList is empty or has only one element...\n";
				return;
			}
			for( p=plist ; p!= NULL ; p=p->next){
				for( ptr=p->next ; ptr!=NULL ; ptr=ptr->next){
					if( p->data > ptr->data){
						temp=p->data;
						p->data = ptr->data;
						ptr->data = temp;
						checked = true;
					}
				}
			}
			if(checked){
				cout<<"\n\tList sorted successfully...\n"	;
			}
		}
		
		//--------deleteNode---------
		void deleteNode(){
			int pos , ch , i=1;
			NodeType *p1 , *p2 , *p3 , *ptr;
			if(plist == nullptr){
				cout<<"\nList is empty...";
				return;
			}else{	
				cout <<"\n=======================Delete Mode=============================" << endl;
				cout<<"\t1.  Beginning\n";
				cout<<"\n\t2.  End\n";
				cout<<"\n\t3.  Position after nodePtr\n";
				cout << "===============================================================" << endl;
				cout << "\tPlease choose one option: ";cin>>ch;
				switch(ch){
					case 1:
						cout<<"\n\tDelete at the beginning(NodeP1)\n";
						p1 = plist ; 
						plist = plist->next;
						freeNode(p1);
					break;
					case 2:
						cout<<"\n\tDelete at the end(NodeP2)\n";
						p2 = plist;
						while(p2->next != NULL){
							ptr=p2;
							p2 = p2->next;
						}
						ptr->next = p2->next;
						freeNode(p2);
					break;
					case 3:
						cout<<"\n\tDelete at the position(NodeP3)\n";
						int count;
						count = countNode();
						cout<<"\n\tEnter position u want delete: ";cin>>pos;
						if(pos > count) {cout<<"\n\tInvalid position\n"<<count;}
						else{
							p3 = plist;
							while(i<pos){
								ptr = p3;
								p3 = p3->next;
								i++;
							}
							ptr->next = p3->next;
							freeNode(p3);
						}
					break;	
				}
			}
		}
		
		//--------insert()---------
		void insert(){
			NodeType *p , *ptr;
			char ch; 
			int count , i , pos ;
			float value;
			cout<<"\n\tPlease Enter value to insert: ";cin>>value;
					p = getNode();
					p->data = value;
					p->next=nullptr;
			if(plist == nullptr){
					plist=p;
			}
			else{
				do{
					cout<<"\n\tClick any key to continues this mode\n";
					getch();
					system("cls");
					cout <<"\n=======================Insert Mode=============================" << endl;
					cout<<" \tB.  Beginning\n";
					cout<<"\n\tE.  End\n";
					cout<<"\n\tA.  Position after nodePtr\n";
					cout<<"\n\tD.  Exit program\n";
					cout << "\n===============================================================" << endl;
					cout << "\n\tPlease choose one option: ";
					
					ch = getch();
					ch=toupper(ch);
					if(ch == 'B'){
						cout<<"\n\n\tInsert at beginning(NodeP1)\n";
						p->next = plist;
						plist = p ;
					}
					else if(ch == 'E'){
						cout<<"\n\n\tInsert at end(NodeP2)\n";
						ptr = plist;
						while(ptr->next != nullptr){
							ptr=ptr->next;
						}
							ptr->next=p;
					}
					else if(ch == 'A'){
						cout<<"\n\n\tInsert after node ptr(NodeP3)\n";
						count = countNode();
						cout<<"\n\tEnter position: " ;cin>>pos;
						if(pos > count){
							cout<<"\n\tInvalid position...\n";
						}else{
							i=1;
							ptr=plist;
							while(i<pos){
								ptr = ptr->next;
								i++;
							}
							p->next = ptr->next;
							ptr->next=p;
						}
					}
					else if(ch == 'D'){
						continue;
					}	
					else{
						cout<<"\n\n\tYour choice is wrong...\n";
					}
				}while(ch!='D');
			}
		}
		
		//--------writeToFile---------
		void writeToFile(){
		    string filename;
		    cout << "\n\tEnter filename to save: ";
		    cin.ignore();
		    getline(cin, filename); 
		    
			//ofstream file(filename + ".bin", ios::binary | ios::app); this method clean
		    ofstream file;
		    file.open(filename+".bin" , ios::app | ios::binary);
		    //if u want .txt just change .bin to .txt
		    if (!file.is_open()) {
		        cout << "\n\tError: Could not open file for writing!\n";
		        return;
		    }
		    
		    if (plist == nullptr) {
		        cout << "\n\tList is empty. Nothing to write to file.\n";
		        file.close();
		        return;
		    }
		    
		    // write each data value
		    NodeType* ptr = plist;
		    while (ptr != nullptr) {
		        file.write((char*)&ptr->data, sizeof(ptr->data));
		        ptr = ptr->next;
		    }
		    
		    file.close();
		    cout << "\n\tList successfully written to binary file :" << filename << ".bin\n";
		}
		
		//--------readFromFile---------
		void readFromFile(){
			
		    string filename;
		    cout << "\n\tEnter filename to read from (e.g., data): ";
		    cin.ignore();
		    getline(cin, filename); 
		    
		    ifstream file(filename + ".bin", ios::binary | ios::in);
		    if (!file.is_open()) {
		        cout << "\n\tError: Could not open file for reading!\n";
		        return;
		    }
		    
		    // Clear existing list
		    while (plist != nullptr) {
		        NodeType* temp = plist;
		        plist = plist->next;
		        freeNode(temp);
		    }
		        
		    // Read data value , rebuild the list
		    NodeType* lastNode = nullptr;
		        float value;
		        while(file.read((char*)&value, sizeof(value))) {
		            NodeType* newNode = getNode();
		            newNode->data = value;
		            newNode->next = nullptr;
		            
		            if (plist == nullptr) {
		                plist = newNode;
		                lastNode = newNode;
		            } else {
		                lastNode->next = newNode;
		                lastNode = newNode;
		            }
		        }
		    file.close();
		    cout << "\n\tList successfully loaded from binary file: " << filename << ".bin\n";
		    traverse();
}
					
		//--------displayMenu---------
		void displayMenu(){
			underLine();
		cout << "\n==================== LINKED LIST OPERATIONS ==================" << endl;
        cout << "\t\t1.  Initialize List" << endl;
        cout << "\t\t2.  Create List (Input n nodes)" << endl;
        cout << "\t\t3.  Traverse List" << endl;
        cout << "\t\t4.  Count Nodes" << endl;
        cout << "\t\t5.  Search Position of Value" << endl;
        cout << "\t\t6.  Search Node by Value" << endl;
        cout << "\t\t7.  Sort List" << endl;
        cout << "\t\t8.  Delete Node" << endl;
        cout << "\t\t9.  Insert Node" << endl;
        cout << "\t\t10. Write List to File" << endl;
        cout << "\t\t11. Read List from File" << endl;
        cout << "\t\t12. Exit" << endl;
        cout << "===============================================================" << endl;
        cout << "\tEnter your choice: ";
		}
		
		void runMenu(){
			int value , position , count, choice;
			string input;
			char enterCls;
			
			do{
				displayMenu();
				cin>>input;
				
				choice = stoi(input);// Convert string to int for switch
				switch(choice){
					case 1:
						initialize();
						break;
					case 2:
						createList();
						break;
					case 3:
						traverse();
						break;
					case 4:
						cout <<"\n\tTotal nodes in the list: " << countNode() << endl;
						break;
					case 5:
						searchPosition();
						break; 
					case 6:
						searchValue();
						break;
					case 7:
						sort();
						break;
					case 8:
						deleteNode();
						break;
					case 9:
						insert();
						break;
					case 10:
						writeToFile();
						break;
					case 11:
						readFromFile();
						break;
					case 12:
						cout<<"\n\tExiting program, thank you...\1\3\n";	
						break;
					default:
						cout <<"\n\tWe didn't have this option\1\1\n";
						break;		
				}
				cout<<"\nPress Enter to continue...";
				
				enterCls = getch();
				system("cls");
			}while(enterCls == 13);
		}
};

int main(){
	SinglyLinkedList SLL;
	SLL.runMenu();
	
	return 0;
}