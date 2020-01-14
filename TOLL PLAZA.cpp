#include<iostream>
#include<fstream>
#include<windows.h>
#include<conio.h>
using namespace std;
void gotoxy(int x,int y)
{
	COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
class Tollplaza
{
    char veh_no[20];
    int veh_type;
    int journey_type;
    int date[3];
    int time[3];   
    public:
    int charges;
    int toll_charges;       
    void get()
    {
	vehicle:
       	gotoxy(56,2);
       	cout<<"!!============!!";
       	gotoxy(56,3);
       	cout<<"   TOLL PLAZA";
       	gotoxy(56,4);
       	cout<<"________________";
       	gotoxy(25,15);
       	cout<<"Enter Vehicle No. :";
       	cin>>veh_no;
       	system("CLS");
       	gotoxy(56,2);
       	cout<<"!!============!!";
       	gotoxy(56,3);
       	cout<<"   TOLL PLAZA";
       	gotoxy(56,4);
       	cout<<"________________";
       	gotoxy(25,10);
        cout<<"Select Vehicle Category : "<<endl<<"1. Two Wheeler"<<endl<<"2. Four Wheeler"<<endl<<"3. Ten Wheeler"<<endl<<"4. Government Vehicle"<<endl;
        cin>>veh_type;
        cout<<"Enter the Choice :";
		system("CLS");    
        switch(veh_type)
        { 
		    case 1: { 
			            charges=20;
                        break;
			        }
            case 2: { 
			            charges=50;
				        break;
				}
            case 3: { 
			            charges=100; 
						break;
					}
            case 4: { 
			            charges=0;
                        gotoxy(25,10);
                        system("color 1C");
                        cout<<"GOVERNMENT VEHICLE are FREE";
                        getch();
                        system("CLS");
                        goto vehicle;
					    break;
					}
                    default: 
					{ 
					    cout<<"\n Invalid Input......Please Choose Again\n\n";
                        goto vehicle;
						break;
					}
        }
        journey:
        cout<<"Select type of journey :"<<endl<<"1. One Way"<<endl<<"2. Two Way"<<endl;
        cin>>journey_type;
        if(journey_type==1)
        {
        	switch(veh_type)
        	{
        		case 1:
        			{
        			    system("color 5E");
				        toll_charges=20;
                        break;
					}
					case 2:
						{
						    system("color 3F");
					        toll_charges=50;
					        break;
						}
						case 3:
					    {
					    	system("color 3B");
					    	toll_charges=100; 
						    break;
						}
						default:
						{
					        cout<<"\n Invalid Input......Please Choose Again\n\n";
                            goto journey;
						    break;	
						}
			}
		}
		else(journey_type==2);
		{
			switch(veh_type)
			{
				case 1:
					{
						 system("color 5E");
						toll_charges=30;
						break;
					}
					 case 2:
					 	{
					 		system("color 3F");
					 		toll_charges=90;
					        break;
						 }
						 case 3:
						 	{
						 		system("color 3B");
						 		toll_charges=180; 
						        break;
							 }
							 default:
							 	{
							 		cout<<"\nInvalid Input......Please Choose Again\n\n";
                                    goto journey;
						            break;
								 }
			}
		}
		date:	      
	    cout<<"Date [DD] :";
        cin>>date[0];
        cout<<"Month [MM] :";
        cin>>date[1];
        cout<<"Year [YYYY] :";
        cin>>date[2];
        if(date[0]<=0 || date[0]>31 || date[1]<=0 || date[1]>12 || date[2]<=0 || date[2]<999 || date[2]>9999 )
        {
        	 cout<<"\nInvalid Input......Please Enter Again\n\n";     
			 goto date; 
		}
		time:      
        cout<<"Hours [HH] :";
        cin>>time[0];
        cout<<"Minutes [MM] :";
        cin>>time[1];
        cout<<"Seconds [SS] :";
        cin>>time[2];
        if(time[0]>23 || time[1]>60 || time[2]>60)
        {
        	cout<<"\nInvalid Input......Please Enter Again\n\n";
            goto time; 
		}
		system("CLS");
    }
    int prepare_file();
    int file();
    void show();
    void t_entry();
}
V[50];
int Tollplaza::file()
{
	ofstream filout;
    filout.open("tollplaza_binary.dat",ios::app|ios::binary);
    filout.write((char *)this,sizeof(*this));
    filout.close();
    return(0);
}
int Tollplaza::prepare_file()
{
	ofstream filout;
    filout.open("tollplaza_summary_sheet.txt",ios::app|ios::binary);
    filout<<"\nVehicle Number : "<<veh_no;
    switch(veh_type)
    {
    	case 1:
    		{
    			filout<<"Vehicle Type : Two Wheeler \n"<<endl;
                break;
			}
			case 2:
				{
					filout<<"\nVehicle Type : Four Wheeler";
					break;
				}
				 case 3:
				 	{
				 		filout<<"\nVehicle Type : Ten Wheeler"; 
						break;
					 }
					 case 4:
					 	{
					 		filout<<"\nVehicle Type : GOVERNMENT VEHICLE";
						    break;
						 }
	}
	switch(journey_type)
	{
		case 1: 
		{ filout<<"\nType of journey : One Way";
		 break;
	    }
	    case 2:
	    	{
	    		filout<<"\nType of journey : Two Way";
				break;
			}
	}
	filout<<"\nDate : "<<date[0]<<"/"<<date[1]<<"/"<<date[3];
    filout<<"\nTime : "<<time[0]<<":"<<time[1]<<":"<<time[3]<<endl<<endl;
    filout<<"\nCharges : "<<charges;
    filout<<"\nTotal Charges : "<<toll_charges;
    filout.close();
    return(0);	
}
void Tollplaza::show()
{
	cout<<"\nVehicle Number : "<<veh_no<<endl;
    switch(veh_type)
    {
    	case 1:
    		{
    			cout<<"Vehicle Type : Two Wheeler \n"<<endl;
                break;
			}
			case 2:
				{
					cout<<"\nVehicle Type : Four Wheeler";
				    break;
				}
				case 3:
					{
						cout<<"\nVehicle Type : Ten Wheeler"; 
						break;
					}
					case 4:
						{
							cout<<"\nVehicle Type : GOVERNMENT VEHICLE";
					        break;
						}
	}
	switch(journey_type)
	{
		 case 1:
		 	{
		 		cout<<"\nType of journey : One Way";
				break;
			 }
			 case 2:
			 	{
			 		cout<<"\nType of journey : Two Way";
				    break;
				 }
	}
	cout<<"\nDate : "<<date[0]<<"/"<<date[1]<<"/"<<date[3];
    cout<<"\nTime : "<<time[0]<<":"<<time[1]<<":"<<time[3]<<endl<<endl;
    cout<<"\nCharges :"<<charges;
    cout<<"\nTotal Charges :"<<toll_charges;
    cout<<"\n\t\t\t\t\tThankyou For Paying Toll Tax"<<endl;
    cout<<"\n\t\t\t\t\t We Wish You a Safe Journey"<<endl;
    getch();
    cout<<"Press Enter to continue!!";
    system("CLS");
}
void Tollplaza::t_entry()
{
	ifstream filin;
	filin.open("tollplaza_binary.dat",ios::in|ios::binary);
	if(!filin)
	  cout<<endl<<"!!!!!!!No Data Found!!!!!!!!"<<endl;
	else
	{
		filin.read((char*)this,sizeof(*this));
		while(!filin.eof())
		{
		    show();
		    filin.read((char*)this,sizeof(*this));
	    }
	
    }
    filin.close();
}
void clear_data()
{
	ofstream filin;
	filin.open("tollplaza_binary.dat");
	filin<<"";
	filin.close();
	gotoxy(25,10);
	system("color 30");
	cout<<"!!!!!!!!!All Data Cleared!!!!!!!!!"<<endl;
	getch();
	system("CLS");
}
int main()
{
	int c;
    for(int i=0;i>=0;i++)
     {
 	system("color f1");
 	{
 	 gotoxy(15,5);
     cout<<"                   ********   **    *     *        ******   *         **     *******     **";
     gotoxy(15,6);
     cout<<"                      **     *  *   *     *        **    *  *        *  *        **     *  *";
     gotoxy(15,7);
     cout<<"                      **    *    *  *     *        ******   *       *    *     **      *    *";
     gotoxy(15,8);
     cout<<"                      **     *  *   *     *        **       *      ** ** **   **      ** ** **";
     gotoxy(15,9);
     cout<<"                      **      **    ***** *****    **       ***** *        * ******* *        *";
	 }
     gotoxy(25,14);
     cout<<"Press enter to Continue!!!";
     getch();
     system("CLS");
     entry:
     gotoxy(56,2);
     cout<<"!!============!!";
     gotoxy(56,3);
     cout<<" TOLL PLAZA";
     gotoxy(56,4);
     cout<<"________________";
     gotoxy(25,10);
     cout<<"1. New Vehicle Entry.";
     gotoxy(25,11);
     cout<<"2. Show Vehicles Entry Up to Now.";
     gotoxy(25,12);
     cout<<"3. Clear All Data.";
     gotoxy(25,13);
     cout<<"4. Exit.";
     gotoxy(25,16);
     cout<<"Enter your choice :"<<endl;
     gotoxy(45,16);
     cin>>c;
     system("CLS");
     switch(c)
     {
	 case 1:
	 	{
	 		 V[i].get();
             V[i].file();
             V[i].prepare_file();
             V[i].show();
             break;
		 }
		  case 2:
		  	{
		  		system("color 1c");
				gotoxy(25,10); 
				cout<<"ALL DATA UPTO NOW : "<<endl;
            	int j=0;
            	while(j!=i+1)
            	{
            		 ++j;
            		 V[j].t_entry();
				}
				break;
			  }
			  case 3:
			  	{
			  		clear_data();
					break;
				  }
				   case 4: exit(0);
				   default:
				   	{
				   		cout<<"\n Invalid Input......Please Choose Again \n\n";
                        goto entry;
						break;
					   }
        }
  }
}


