	 #include <iostream>
#include<fstream>
#include<cstdlib>
#include <stdio.h>
#include<string>
#include<windows.h>

using namespace std;
/*
PROCESS:
Enter your TDL file name:
Enter number of categories:
Enter category name:
Enter task:
What next? Enter a number according to the following:
==============
1 - ADD NEW FILE
2 - UPDATE FILE
3 - DELETE FILE
4 - VIEW CONTENT OF FILE
5 - QUIT
---------------
If 3 was chosen
	-Enter category name:
	-Enter task:
	-What next? Enter a number according to the following:
*/


void newTDL();
void MTDL();


int main()
{
	system ("color 3");
    HANDLE colors=GetStdHandle(STD_OUTPUT_HANDLE);
    string text;
    int b=2;  
	  
	cout<<" ====================================================================================================================================================================== \n";
    cout<<" ====================================================================================================================================================================== \n\n";
	cout<<"                                                        SSSSSSS+  SSSSSS+ SS+  SS+ SSSSSSS+ SSS+   SSS+  SSSSS+  \n";    
    cout<<"                                                        SS+----+ SS+----+ SS¦  SS¦ SS+----+ SSSS+ SSSS¦ SS+--SS+ \n";
    cout<<"                                                        SSSSSSS+ SS¦      SSSSSSS¦ SSSSS+   SS+SSSS+SS¦ SSSSSSS¦ \n";
    cout<<"                                                        +----SS¦ SS¦      SS+--SS¦ SS+--+   SS¦+SS++SS¦ SS+--SS¦ \n";
    cout<<"                                                        SSSSSSS¦ +SSSSSS+ SS¦  SS¦ SSSSSSS+ SS¦ +-+ SS¦ SS¦  SS¦ \n";
    cout<<"                                                        +------+  +-----+ +-+  +-+ +------+ +-+     +-+ +-+  +-+ \n\n";
	cout<<"       	                                                             TO - DO  LIST  CONSOLE PROGRAM 	   	         \n\n";
	cout<<" ====================================================================================================================================================================== \n";
    cout<<" ====================================================================================================================================================================== \n\n\n\n";  
    cout<<"                                                            WELCOME TO SCHEMA! ENTER YOUR PREFERRED OPTION:      " << endl << endl;
	cout<<" ----------------------------------------------------------------------------------------------------------------------------------------------------------------------  \n\n";
	cout<<"                                                                  ENTER 1 to Input a New To-Do List      \n\n";
	cout<<"                                                                ENTER 2 to Modify Existing To-Do List  \n\n";
	cout<<"                                                                        ENTER 3 to Exit SCHEMA                \n\n\n\n";

	int choice, x;
	cout <<"                                                                              CHOICE: ";
	cin >> choice;
	

	cout << endl;
	
	if (choice == 1)
	{
		newTDL();
 		
	}
	if (choice == 2)
	{
		MTDL();
	}
	if (choice == 3)
	{
		cout << "                                                                  ----- YOU HAVE EXITED SCHEMA -----";
		return EXIT_SUCCESS;
	}
	if ((choice >= 4) || (choice == 0))
	{
		cout << "\n\n" << "       YOU HAVE ENTERED A WRONG OPTION. PLEASE TRY AGAIN: " << "\n\n";
		main ();
}

	
	return 0;
}

void newTDL()
{
	ofstream collectionoffiles;
	collectionoffiles.open("Collection of Existing Files", ios::app);
	
	ofstream op;
	string filename1;
	

	cout << endl;
	cout << "                                                                 Enter Your New TDL File Name: "; 
	cin>>filename1;
	
	//NEW=================================================================================================================================================================================
	
	ifstream checks;
	checks.open("Collection of Existing Files");
	
	string lines;
	while(getline(checks, lines))
	{
		if (filename1 == lines)
		{
			cout << endl;
				cout << "                                                                       FILE ALREADY EXISTED " << endl;
					int pick;
			cout<<"===================================================================================================================================================================== \n";
			cout <<"                                                                   ENTER 1 To GO BACK FROM THE START" << endl;
			cout <<"                                                                    --------------OR--------------" << endl;
			cout <<"                                                                      ENTER 2 TO EXIT THE PROGRAM" << endl;
			cout<<"===================================================================================================================================================================== \n";
			cout <<"               ENTER DECISION: " ;
			cin >> pick;
			cout<<"===================================================================================================================================================================== \n";

			
				if (pick == 1)
				{
					main();
				}
				if(pick == 2)
				{
					cout << "                                                                -----YOU HAVE LEFT THE PROGRAM-----";
					return;
				}		
		}
	}
	//NEW=================================================================================================================================================================================
	
	
	collectionoffiles << filename1 << endl;
	collectionoffiles.close();
	
		op.open(filename1.c_str(), ios::in|ios::out|ios::app);
		int numofcateg;
		
		cout << "                                                                    Enter Number Of Categories: ";
		cin >> numofcateg;
		string category[numofcateg];
		cout << endl;
		cout<<" ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";

	
	for (int c = 0; c < numofcateg; c++ )
	{
		
		cout << endl;
		cout << "                                                             ENTER NAME FOR #" << c+1 << " CATEGORY: ";
		cin >> category[c];
		
        op << "========================================================================================================================================================================= \n";
		op << "     CATEGORY" << " #" <<c+1  << "-" << category[c];
		op << endl;
      

		
		int numoftask;
		cout << "                                                             Enter Number Of Task: ";
		cin >> numoftask;
		
		string task[numoftask];

		
		for (int t = 0; t < numoftask; t++)
		{
			cout << "                                                             Enter Task #" << t+1 << ": ";
			cin >> task[t];
			
			op << "     Task #" << t+1 << ": "<<task[t];
			op << endl;

			
		}
	}	

	
    op.close();

	
		int numacc;
		cout<<"======================================================================================================================================================================== \n";
		cout << endl;
		cout << "	                                                         Choose One Of The Following Steps" << endl;
		cout<<" "<<endl;
		cout << "	                                                        1 - ADD NEW SET OF CATEGORY AND TASK " << endl;
		cout << "	                                                        2 - UPDATE FILE CONTENT " << endl;
		cout << "                                                                3 - DELETE FILE CONTENT " << endl;
		cout << "                                                                4 - VIEW FILE CONTENT " << endl;
		cout << "	                                                        5 - VIEW EXISTING FILE NAMES" << endl;
		cout << "	                                                        6 - QUIT " << endl<<endl;
		cout<<"======================================================================================================================================================================== \n";
		cout << "	                                                       Enter A Number According To The Following: ";
		cin >> numacc;
		cout << endl;
		cout<<"======================================================================================================================================================================== \n";

		
		if (numacc == 1) // ADD NEW SET OF TASK AND CATEGORIES
		{
			int numofcat;
			
			ofstream collectionoffiles;
			collectionoffiles.open("Collection of Existing Files", ios::app);
	
			ofstream anf;
			string newfilename;
			cout << "                                                               ENTER A NEW FILE NAME: ";
			cin >> newfilename;
			
				
	//NEW=================================================================================================================================================================================
	
	ifstream checks;
	checks.open("Collection of Existing Files");
	
	string lines;
	while(getline(checks, lines))
	{
		if (newfilename == lines)
		{
			cout << endl;
				cout << "                                                                       FILE ALREADY EXISTED " << endl;
					int pick;
			cout<<"===================================================================================================================================================================== \n";
			cout <<"                                                                   ENTER 1 To GO BACK FROM THE START" << endl;
			cout <<"                                                                    --------------OR--------------" << endl;
			cout <<"                                                                      ENTER 2 TO EXIT THE PROGRAM" << endl;
			cout<<"===================================================================================================================================================================== \n";
			cout <<"               ENTER DECISION: " ;
			cin >> pick;
			cout<<"===================================================================================================================================================================== \n";

			
				if (pick == 1)
				{
					main();
				}
				if(pick == 2)
				{
					cout << "                                                                -----YOU HAVE LEFT THE PROGRAM-----";
					return;
				}		
		}
	}
	//NEW=================================================================================================================================================================================
	
			
			collectionoffiles << newfilename << endl;
			collectionoffiles.close();
				
			anf.open(newfilename.c_str(), ios::in|ios::out|ios::app);
			cout << "                                                               Enter Number Of Categories: ";
			cin >> numofcat;
			cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";


			
			string cat[numofcat];
				
				for (int a = 0; a < numofcat; a++ )
				{
					cout << endl;	
					cout << "                                                            ENTER NAME FOR #" << a+1 << " CATEGORY: ";
					cin >> cat[a];
		
					anf << "     CATEGORY-" << cat[a] << ":";
					anf << endl;
		
					int numoftas;
					cout << "                                                            Enter Number Of Task: ";
					cin >> numoftas;
		
					string task[numoftas];
		
					for (int b = 0; b < numoftas; b++)
					{
					cout << "                                                            Enter Task #" << b+1 << ": ";
					cin >> task[b];
					anf << task[b];
					anf << endl;	

					}
	
				}
				cout << endl;
				int pick;
			cout<<"===================================================================================================================================================================== \n";
			cout <<"                                                                   ENTER 1 To GO BACK FROM THE START" << endl;
			cout <<"                                                                    --------------OR--------------" << endl;
			cout <<"                                                                      ENTER 2 TO EXIT THE PROGRAM" << endl;
			cout<<"===================================================================================================================================================================== \n";
			cout <<"               ENTER DECISION: " ;
			cin >> pick;
			cout<<"===================================================================================================================================================================== \n";

			
				if (pick == 1)
				{
					main();
				}
				if(pick == 2)
				{
					cout << "                                                                -----YOU HAVE LEFT THE PROGRAM-----";
					return;
				}
			
		}
		if (numacc == 2) // UPDATE
		{
				int nofc;

			ofstream efile;
			string exfile;
			cout << "                                                    NOTE: Update will remove the first content and replace it with a new set of TDL." << endl;
			cout << "                                                    Enter An Existing File To Update: ";
			cin >> exfile;
			efile.open(exfile.c_str(),ios::out);
			
			
			if (efile.fail())
			{
				cout << "                                                              EXISTING FILE FAILED TO OPEN"<< endl;
				cout << endl; 
				
				int fails;
				cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";
				cout << "                                                                 ENTER 1 TO THE START    " << endl;
				cout << "                                                                          OR             " << endl;
				cout << "                                                              ENTER 0 TO EXIT THE PROGRAM" << endl;
				cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";
				cout << "                                                                  ENTER NUMBER: ";
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------ \n";

				cin >> fails;
				cout << endl;
					if (fails == 1)
					{
						main();
					}
					if (fails == 0)
					{
						cout << "                                                      -----YOU HAVE LEFT THE PROGRAM-----";
                        return;
					}
					if ((fails != 1) && (fails != 0))
					{
						return;
					}
			}
			
			
			
			cout << "                                                                ENTER NUMBER OF CATEGORY: ";
			cin >> nofc;		
			string category[nofc];
			efile << endl;
			efile << "    -----UPDATED SET OF CATEGORIES AND TASK-----" << endl;		
				for (int f = 0; f < nofc; f++ )
				{
					
					cout << endl;	
					cout << "                                                        ENTER NAME FOR #" << f+1 << " CATEGORY: ";
					cin >> category[f];
		
					efile << "    CATEGORY - " << category[f] << ":";
					efile << endl;
		
					int noft;
					cout << "                                                        Enter Number Of Task: ";
					cin >> noft;
		
				
					string task[noft];
		
					for (int q = 0; q < noft; q++)
					{
					cout << "                                                        Enter Task #" << q+1 << ": ";
					cin >> task[q];
					efile << "     Task #" << q+1 << ": "<<task[q] << endl;;
					}
				}
			efile << "    -----UPDATED SET OF CATEGORIES AND TASK-----" << endl;
			efile << endl;
		
				
		cout << endl;
				int pick;
			cout<<"===================================================================================================================================================================== \n";		
			cout <<"                                                               ENTER 1 To GO BACK FROM THE START" << endl;
			cout <<"                                                                 --------------OR--------------" << endl;
			cout <<"                                                                  ENTER 2 TO EXIT THE PROGRAM" << endl;
			cout<<"===================================================================================================================================================================== \n";
			cout <<"                                                                      ENTER DECISION: " ;
			cin >> pick;
			cout<<"=====================================================================================================================================================================\n";

			
				if (pick == 1)
				{
					main();
				}
				if (pick == 2)
				{
					cout << "                                                          -----YOU HAVE LEFT THE PROGRAM-----";
				}	
		}
		if (numacc == 3) // DELETE FILE CONTENT
		{
			ofstream delfileco;
			string deltfile;
			int oot;
			cout << "                                                Enter File That You Want To Delete It's Content: ";
			cin >>deltfile;
			delfileco.open(deltfile.c_str());
			cout << endl;
			cout<<"==================================================================================================================================================================== \n";
			cout <<"                                                                   ENTER 1 TO VIEW A DELETED FILE"<< endl;
 			cout <<"                                                                       ---------OR---------"<< endl;
 			cout <<"                                                                   ENTER 2 TO GO BACK FROM THE START"<< endl;
 			cout<<"==================================================================================================================================================================== \n";

 			cout <<"                                                                      ENTER DECISION: ";
 			cin >> oot;

 			if (oot == 1)
 			{
 				  ifstream delfileco;
		 			string viewfilename;
				 	cout << endl;
					  cout << "                                                        Enter The File Name You Want To View: ";
					  cin >> viewfilename;
					  cout << endl;
		  
		 	 delfileco.open(viewfilename.c_str());
		 
		 		if (delfileco.fail( ))
					{
						string x = "                                                              -----Opening Failed----- ";
							cout << x << endl;
							
					}
 						string line;
				while (getline(delfileco, line))
					{
						 cout << line << endl;	
					}	
		 	cout << "                                                                  ----- FILE CONTENT DELETED SUCCESFULLY -----" << endl;
		 	cout << endl;
		 	
		 					 	int hence;
			cout<<"===================================================================================================================================================================== \n";
		    cout << "                                                                         ENTER 1 TO  RETURN TO THE START" << endl;
		    cout << "                                                                           -------------OR-------------" << endl;
		    cout << "                                                                           ENTER 2 TO EXIT THE PROGRAM" << endl;
			cout<<"===================================================================================================================================================================== \n";
			cout << "                                                                              ENTER YOUR CHOICE: ";
				 	cin >> hence;
				 	
				 	cout << endl;
				 	cout << endl;

			if (hence == 1)
			{
				main();
			}
			if (hence == 2)
			{
				cout << "                                                                    -----YOU HAVE LEFT THE PROGRAM-----";
                return;
			}
			}
			if(oot == 2)
			{
				 main();
			}
		}
		if (numacc == 4) // VIEW CONTENT OF FILE
		{
			    ifstream vf;
		 		string viewfilename;
		 		cout << endl;
		 		cout << "                                                             Enter The File Name You Want To View: ";
				cin >> viewfilename;
				cout << endl;
				cout << "   The Content of the file " << viewfilename << " are: " << endl;
               
		  
				  vf.open(viewfilename.c_str());
		 
		 										if (vf.fail( ))
													{
													cout <<                                                                        "Input file opening failed. " << endl << endl;
													int qwe;
			cout<<"==================================================================================================================================================================== \n";
		    cout << "                                                                   ENTER 1 TO  RETURN TO THE START" << endl;
			cout << "                                                                     -------------OR-------------" << endl;
		    cout << "                                                                     ENTER 2 TO EXIT THE PROGRAM" << endl;
		    cout<<"==================================================================================================================================================================== \n";
		    cout << "                                                                       ENTER YOUR CHOICE: ";
		                                        	cin >> qwe;
		                                            	cout << endl;
		                                            	cout << endl;

			                                        	if (qwe == 1)
				                                        {
				                                    	main();
			                                        	}
			                                        	if (qwe == 2)
			                                        	{
			cout << "                                                                   -----YOU HAVE LEFT THE PROGRAM-----";
                                                              return;
			                                        	}
													}
				string line;
			
				while (getline(vf, line))
				{		
				 cout << line << endl;	
				}	
				
			 vf.close();
		 
			 	int hence;
			cout<<"==================================================================================================================================================================== \n";
			cout << "                                                                     ENTER 1 TO  RETURN TO THE START" << endl;
			cout << "                                                                      -------------OR-------------" << endl;
			cout << "                                                                       ENTER 2 TO EXIT THE PROGRAM" << endl;
			cout<<"==================================================================================================================================================================== \n";
			cout << "                                                                        ENTER YOUR CHOICE: ";
			cin >> hence;
			cout << endl;
			cout << endl;

				if (hence == 1)
				{
					main();
				}
				if (hence == 2)
				{
					cout << "                                                              -----YOU HAVE LEFT THE PROGRAM-----";
                    return;
				}
                
		}
		if (numacc == 5)// view all names of existing file 
		{
			int l;
			ifstream views;
			string lines;
			views.open("Collection of Existing Files");
			cout << "     NOTE: Identical Names are Considered One (Exluding-Casesenssitive)" << endl;
			cout << "     	   -This function will only show the First 100 file names that u had created" << endl << endl;;
				cout << "     Below are the Existing files:     " << endl;
			cout << "     ";
			


			while (getline(views, lines))
		
			{
			
			
				cout << l+1 <<")" <<lines << ", ";
				l++;
				
				if ((l ==10) || (l == 20) ||(l == 30) ||(l == 40) ||(l == 50) ||(l == 60)||(l == 70)||(l == 80)||(l == 90)||(l == 100))
				{
					cout << endl;
					cout << "     ";						
				 }
				 if((l > 99))
		    	 {
				 	break;
				 	
				 }
			
			}
			
		
				cout << endl;
				cout << endl;
				int pick;
			cout<<"==================================================================================================================================================================== \n";		
			cout <<"                                                                   ENTER 1 To GO BACK FROM THE START" << endl;
			cout <<"                                                                     --------------OR--------------" << endl;
			cout <<"                                                                      ENTER 2 TO EXIT THE PROGRAM" << endl;
			cout<<"==================================================================================================================================================================== \n";
			cout <<"                                                                             ENTER DECISION: " ;
			cin >> pick;
			cout<<"==================================================================================================================================================================== \n";

			
				if (pick == 1)
				{
					main();
				}
				if(pick == 2)
				{
					cout << "                                                                  -----YOU HAVE LEFT THE PROGRAM-----";
					return;
				}
				
			
		}
		if (numacc == 6) //QUIT
		{
			cout << endl;
			cout << "                                                                          -----YOU HAVE LEFT THE PROGRAM----- ";
		}


cout << endl;
cout << endl;
	
}

void MTDL()
{
			int accc;
		cout << endl;			
		cout<<"========================================================================================================================================================================= \n";
		cout << "	                                                                Choose One Of The Following Steps" << endl;
		cout << "	                                                                   1 - ADD NEW SET OF CATEGORY AND TASK " << endl;
		cout << "	                                                                   2 - UPDATE FILE CONTENT " << endl;
		cout << "	                                                                   3 - DELETE FILE CONTENT " << endl;
		cout << "	                                                                   4 - VIEW FILE CONTENT " << endl;
		cout << "	                                                                   5 - VIEW EXISTING FILE NAMES " << endl;
		cout << "	                                                                   6 - QUIT " << endl<<endl;
		cout<<"========================================================================================================================================================================= \n";
		cout << "                                                            	  Enter A Number According To The Following: ";
		cin >> accc;
		cout<<"========================================================================================================================================================================= \n";

		cout << endl;
		
		if (accc == 1) //  1 - ADD NEW SET OF TASK AND CATEGORIES
		{
					int numofcat;
			
			ofstream collectionoffiles;
			collectionoffiles.open("Collection of Existing Files", ios::app);
	
			ofstream anf;
			string newfilename;
			cout << "                                                               ENTER A NEW FILE NAME: ";
			cin >> newfilename;
			
				
	//NEW=================================================================================================================================================================================
	
	ifstream checks;
	checks.open("Collection of Existing Files");
	
	string lines;
	while(getline(checks, lines))
	{
		if (newfilename == lines)
		{
			cout << endl;
				cout << "                                                                       FILE ALREADY EXISTED " << endl;
					int pick;
			cout<<"===================================================================================================================================================================== \n";
			cout <<"                                                                   ENTER 1 To GO BACK FROM THE START" << endl;
			cout <<"                                                                    --------------OR--------------" << endl;
			cout <<"                                                                      ENTER 2 TO EXIT THE PROGRAM" << endl;
			cout<<"===================================================================================================================================================================== \n";
			cout <<"               ENTER DECISION: " ;
			cin >> pick;
			cout<<"===================================================================================================================================================================== \n";

			
				if (pick == 1)
				{
					main();
				}
				if(pick == 2)
				{
					cout << "                                                                -----YOU HAVE LEFT THE PROGRAM-----";
					return;
				}		
		}
	}
	//NEW=================================================================================================================================================================================
	
			
			collectionoffiles << newfilename << endl;
			collectionoffiles.close();
				
			anf.open(newfilename.c_str(), ios::in|ios::out|ios::app);
			cout << "                                                               Enter Number Of Categories: ";
			cin >> numofcat;
			cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";


			
			string cat[numofcat];
				
				for (int a = 0; a < numofcat; a++ )
				{
					cout << endl;	
					cout << "                                                            ENTER NAME FOR #" << a+1 << " CATEGORY: ";
					cin >> cat[a];
		
					anf << "     CATEGORY-" << cat[a] << ":";
					anf << endl;
		
					int numoftas;
					cout << "                                                            Enter Number Of Task: ";
					cin >> numoftas;
		
					string task[numoftas];
		
					for (int b = 0; b < numoftas; b++)
					{
					cout << "                                                            Enter Task #" << b+1 << ": ";
					cin >> task[b];
					anf << task[b];
					anf << endl;	

					}
	
				}
				cout << endl;
				int pick;
			cout<<"===================================================================================================================================================================== \n";
			cout <<"                                                                   ENTER 1 To GO BACK FROM THE START" << endl;
			cout <<"                                                                    --------------OR--------------" << endl;
			cout <<"                                                                      ENTER 2 TO EXIT THE PROGRAM" << endl;
			cout<<"===================================================================================================================================================================== \n";
			cout <<"               ENTER DECISION: " ;
			cin >> pick;
			cout<<"===================================================================================================================================================================== \n";

			
				if (pick == 1)
				{
					main();
				}
				if(pick == 2)
				{
					cout << "                                                                -----YOU HAVE LEFT THE PROGRAM-----";
					return;
				}
		}
		if (accc == 2)// UPDATE 
		{
				int nofc;

			ofstream efile;
			string exfile;
			cout << "                                                    NOTE: Update will remove the first content and replace it with a new set of TDL." << endl;
			cout << "                                                    Enter An Existing File To Update: ";
			cin >> exfile;
			efile.open(exfile.c_str(),ios::out);
			
			
			if (efile.fail())
			{
				cout << "                                                              EXISTING FILE FAILED TO OPEN"<< endl;
				cout << endl; 
				
				int fails;
				cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";
				cout << "                                                                 ENTER 1 TO THE START    " << endl;
				cout << "                                                                          OR             " << endl;
				cout << "                                                              ENTER 0 TO EXIT THE PROGRAM" << endl;
				cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";
				cout << "                                                                  ENTER NUMBER: ";
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------ \n";

				cin >> fails;
				cout << endl;
					if (fails == 1)
					{
						main();
					}
					if (fails == 0)
					{
						cout << "                                                      -----YOU HAVE LEFT THE PROGRAM-----";
                        return;
					}
					if ((fails != 1) && (fails != 0))
					{
						return;
					}
			}
			
			
			
			cout << "                                                                ENTER NUMBER OF CATEGORY: ";
			cin >> nofc;		
			string category[nofc];
			efile << endl;
			efile << "    -----UPDATED SET OF CATEGORIES AND TASK-----" << endl;		
				for (int f = 0; f < nofc; f++ )
				{
					
					cout << endl;	
					cout << "                                                        ENTER NAME FOR #" << f+1 << " CATEGORY: ";
					cin >> category[f];
		
					efile << "    CATEGORY - " << category[f] << ":";
					efile << endl;
		
					int noft;
					cout << "                                                        Enter Number Of Task: ";
					cin >> noft;
		
				
					string task[noft];
		
					for (int q = 0; q < noft; q++)
					{
					cout << "                                                        Enter Task #" << q+1 << ": ";
					cin >> task[q];
					efile << "     Task #" << q+1 << ": "<<task[q] << endl;;
					}
				}
			efile << "    -----UPDATED SET OF CATEGORIES AND TASK-----" << endl;
			efile << endl;
		
				
		cout << endl;
				int pick;
			cout<<"===================================================================================================================================================================== \n";		
			cout <<"                                                               ENTER 1 To GO BACK FROM THE START" << endl;
			cout <<"                                                                 --------------OR--------------" << endl;
			cout <<"                                                                  ENTER 2 TO EXIT THE PROGRAM" << endl;
			cout<<"===================================================================================================================================================================== \n";
			cout <<"                                                                      ENTER DECISION: " ;
			cin >> pick;
			cout<<"=====================================================================================================================================================================\n";

			
				if (pick == 1)
				{
					main();
				}
				if (pick == 2)
				{
					cout << "                                                          -----YOU HAVE LEFT THE PROGRAM-----";
				}	
		}
		if (accc == 3) // DELETE FILE CONTENT
		{
			ofstream delfileco;
			string deltfile;
			int oot;
			cout << "                                                                 Enter File That You Want To Delete It's Content: ";
			cin >> deltfile;
			delfileco.open(deltfile.c_str());
			cout << endl;
			cout<<"==================================================================================================================================================================== \n";
			cout <<"                                                                        ENTER 1 TO VIEW A DELETED FILE"<< endl;
 			cout <<"                                                                              ---------OR---------"<< endl;
 			cout <<"                                                                       ENTER 2 TO GO BACK FROM THE START"<< endl;
 			cout<<"==================================================================================================================================================================== \n";

 			cout <<"                                                                              ENTER DECISION: ";
 			cin >> oot;
 			cout<<"==================================================================================================================================================================== \n";

 			if (oot == 1)
 			{
 				  ifstream delfileco;
		 			string viewfilename;
				 	cout << endl;
					  cout << "                                                      Enter The File Name You Want To View: ";
					  cin >> viewfilename;
					  cout << endl;
		  
		 	 delfileco.open(viewfilename.c_str());
		 
		 		if (delfileco.fail( ))
					{
						string x = "                                                                     -----Opening Failed----- ";
							cout << x << endl;
							
					}
 						string line;
				while (getline(delfileco, line))
					{
						 cout << line << endl;	
					}	
		 	cout << "                                                                     ----- FILE CONTENT DELETED SUCCESFULLY -----" << endl;
		 	cout << endl;
		 	
		 					 	int hence;
		 	cout<<"===================================================================================================================================================================== \n";
			cout << "                                                                           ENTER 1 TO  RETURN TO THE START" << endl;
			cout << "                                                                            -------------OR-------------" << endl;
			cout << "                                                                            ENTER 2 TO EXIT THE PROGRAM" << endl;
			cout<<"==================================================================================================================================================================== \n";
			cout << "                                                                               ENTER YOUR CHOICE: ";
				 	cin >> hence;
			cout<<"==================================================================================================================================================================== \n";
				 	cout << endl;
				 	cout << endl;

			if (hence == 1)
			{
				main();
			}
			if (hence == 2)
			{
				cout << "                                                                       -----YOU HAVE LEFT THE PROGRAM-----";
                return;
			}
			}
			if(oot == 2)
			{
				 main();
			}
		}
		if (accc == 4) // veiew file content
		{
		 ifstream vf;
		 		string viewfilename;
		 		cout << endl;
		 		cout << "                                                             Enter The File Name You Want To View: ";
				cin >> viewfilename;
				cout << endl;
				cout << "   The Content of the file " << viewfilename << " are: " << endl;
               
		  
				  vf.open(viewfilename.c_str());
		 
		 										if (vf.fail( ))
													{
													cout <<                                                                        "Input file opening failed. " << endl << endl;
													int qwe;
			cout<<"==================================================================================================================================================================== \n";
		    cout << "                                                                   ENTER 1 TO  RETURN TO THE START" << endl;
			cout << "                                                                     -------------OR-------------" << endl;
		    cout << "                                                                     ENTER 2 TO EXIT THE PROGRAM" << endl;
		    cout<<"==================================================================================================================================================================== \n";
		    cout << "                                                                       ENTER YOUR CHOICE: ";
		                                        	cin >> qwe;
		                                            	cout << endl;
		                                            	cout << endl;

			                                        	if (qwe == 1)
				                                        {
				                                    	main();
			                                        	}
			                                        	if (qwe == 2)
			                                        	{
			cout << "                                                                   -----YOU HAVE LEFT THE PROGRAM-----";
                                                              return;
			                                        	}
													}
				string line;
			
				while (getline(vf, line))
				{		
				 cout << line << endl;	
				}	
				
			 vf.close();
		 
			 	int hence;
			cout<<"==================================================================================================================================================================== \n";
			cout << "                                                                     ENTER 1 TO  RETURN TO THE START" << endl;
			cout << "                                                                      -------------OR-------------" << endl;
			cout << "                                                                       ENTER 2 TO EXIT THE PROGRAM" << endl;
			cout<<"==================================================================================================================================================================== \n";
			cout << "                                                                        ENTER YOUR CHOICE: ";
			cin >> hence;
			cout << endl;
			cout << endl;

				if (hence == 1)
				{
					main();
				}
				if (hence == 2)
				{
					cout << "                                                              -----YOU HAVE LEFT THE PROGRAM-----";
                    return;
				}
                
		}
		if (accc == 5)// view all names of existing file
		{
				int l = 0;
			ifstream views;
			string lines;
			views.open("Collection of Existing Files");
			cout << "     NOTE: Identical Names are Considered One (Exluding-Casesenssitive)" << endl;
			cout << "     	   -This function will only show the First 100 file names that u had created" << endl << endl;;
				cout << "     Below are the Existing files:     " << endl;
			cout << "     ";
			
	

			while (getline(views, lines))
		
			{
		
			
				cout << l+1 <<")" <<lines << ", ";
				l++;
				
				if ((l ==10) || (l == 20) ||(l == 30) ||(l == 40) ||(l == 50) ||(l == 60)||(l == 70)||(l == 80)||(l == 90)||(l == 100))
				{
					cout << endl;
					cout << "     ";						
				 }
				 if((l > 99))
		    	 {
				 	break;
				 	
				 }
			
			}
			
		
				cout << endl;
				cout << endl;
				int pick;
			cout<<"===================================================================================================================================================================== \n";		
			cout <<"                                                               ENTER 1 To GO BACK FROM THE START" << endl;
			cout <<"                                                                --------------OR--------------" << endl;
			cout <<"                                                                  ENTER 2 TO EXIT THE PROGRAM" << endl;
			cout<<"===================================================================================================================================================================== \n";
			cout <<"                                                                    ENTER DECISION: " ;
			cin >> pick;
			cout<<"===================================================================================================================================================================== \n";

			
				if (pick == 1)
				{
					main();
				}
				if(pick == 2)
				{     
					cout << "                                                               -----YOU HAVE LEFT THE PROGRAM-----";
					return;
				}
				
			
		}
		if (accc == 6)//QUIT
		{
			cout << "                                                                       -----YOU HAVE LEFT THE PROGRAM----- ";
			return;
		}



}
