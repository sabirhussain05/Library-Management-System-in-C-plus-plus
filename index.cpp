/*LIBRARY MANAGEMENT SYSTEM
ZAIN ASGHAR 19011519-062
ALI HASSAN CHEEMA 19011519-067
*/
#include<windows.h>
#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include <iomanip>
using namespace std;
using std::ostream;
 using std::istream;
 void loading()
 {
 	cout<<"\n\n\n\n\n\n\n\n";
 	cout<<"\t\t\t\t\t\tPlease Wait....."<<endl;
 	cout<<"\t\t\t\tLoading ";
 	char x=219;
 	for (int i=0;i<30;i++)
 	{
 		
 		cout<<x;
 		if(i<10)
 		Sleep(250);
 		if(i>=10 && i<20)
 		Sleep(150);
 		if(i>=20 && i<35)
 		Sleep(25);
	}
	 
 }
class Library{
	private:
	string libraryname[1];
	string librarylocation[1];
	int no_of_members[1];
	int total_books[1];
	int sitting_capacity[1];
	int change;
	 public:
	 	
	 	int temp;
	 	void increasemembers(){
	ifstream in;	
	in.open("librarydata.txt");
	 int i=0;
	in>>libraryname[i]>>librarylocation[i]>>total_books[i]>>sitting_capacity[i]>>no_of_members[i];
	in.close();
	ofstream out;
	out.open("librarydata.txt");
	no_of_members[i]++;
	out<<libraryname[i]<<" "<<librarylocation[i]<<" "<<total_books[i]<<" "<<sitting_capacity[i]<<" "<<no_of_members[i];
	cout<<"New member Has Been Added Successfully.."<<endl;	
	}	
	void decreasebooks()
	{
	ifstream in;	
	in.open("librarydata.txt");
	int i=0;
	in>>libraryname[i]>>librarylocation[i]>>total_books[i]>>sitting_capacity[i]>>no_of_members[i];
	in.close();
	ofstream out;
	out.open("librarydata.txt");
	total_books[i]--;
	out<<libraryname[i]<<" "<<librarylocation[i]<<" "<<total_books[i]<<" "<<sitting_capacity[i]<<" "<<no_of_members[i];	
	}
	void increasebooks()
		{
		ifstream in;	
	in.open("librarydata.txt");
	int i=0;
	in>>libraryname[i]>>librarylocation[i]>>total_books[i]>>sitting_capacity[i]>>no_of_members[i];
	in.close();
	ofstream out;
	out.open("librarydata.txt");
	total_books[i]++;
	out<<libraryname[i]<<" "<<librarylocation[i]<<" "<<total_books[i]<<" "<<sitting_capacity[i]<<" "<<no_of_members[i];
	out.close();
		}
};
class  book  {
	private:
 string category ; 
 string availabilitystatus ; 
 string name ; 
  float price ;
  string author;
  int quantity;
  book(string name=" ", string author=" ", int quantity=0, string availablitystatus=" ", float price=0, string category=" "){
	this->name = name;
	this->author = author;
	this->quantity = quantity;
	this->availabilitystatus = availabilitystatus;
	this->price = price;
	this->category = category;
	}
	~book();     
};
class Login{
	private:
	string username;
	string password;
	public:
	librarianlogin()
	{
		string name;
		string pass;
		int flag;
		n:
	{
		//system("color 0");
			cout<<"\t\t\t\t\t\t  .:WELCOME TO:.\n";
	cout<<"\t\t\t\t __      __   _____   _____    _____   _____   __    __\n";
	cout<<"\t\t\t\t|  |    |  | |  _  | |  _  |  |  _  | |  _  |  \\ \\  / /\n";
	cout<<"\t\t\t\t|  |    |  | | |_| | | |_| |  | |_| | | |_| |   \\ \\/ /\n";
	cout<<"\t\t\t\t|  |    |  | |  _ <  |  _ <   |  _  | |  _ <     |  | \n";
	cout<<"\t\t\t\t|  |__  |  | | |_| | | / \\ \\  | | | | | / \\ \\    |  | \n";
	cout<<"\t\t\t\t|_____| |__| |_____| |/   \\_\\ |_| |_| |/   \\_\\   |__|\n";
	cout<<"\n\t\t\t\t\t\t.:MANAGEMENT SYSTEM:.\n\n\n";
	}
		
		cout<<"\t\t\tPlease Enter Username:";
		cin>>name;
		cout<<"\t\t\tplease Enter Password:";
		cin>>pass;
		ifstream in;
		in.open("logindata.txt");
		while(!(in.eof()))
		{
			in>>username>>password;
			if(name==username&&pass==password)
			{
				system("CLS");
				cout<<"\t\t\t\t\t\tWelcome Mr."<<name<<endl<<endl;
				flag=1;
			}
		}
		if(flag!=1)
		{
			cout<<endl<<endl<<"\t\tAdministrator Verification Failed, Press Any key to login Again."<<endl;
			system("PAUSE");	
			system("CLS");
			goto n;	
		}
		in.close();
	}	
};
class Member{
		private:
		Library li;
		public:
		string mname;
		string maddress;
		string mno;
		string stat;
		string mid;
		
			void addmember()
			{
				
				string name,address,status;
				string contact;
				cout<<"\t\tEnter Member name:";
				cin>>name;
				cout<<"\t\tEnter Member Contact Number:";
				cin>>contact;
				cout<<"\t\tEnter Member Status (Student or Teacher):";
				cin>>status;
				cout<<"\t\tEnter Member Address:";
				cin>>address;
				cout<<"\t\tEnter member ID (For Teacher ID And For Student Roll NO.):";
				cin>>mid;
				fstream out;
				out.open("memberinfo.txt",ios::app);
				out<<name<<" "<<contact<<" "<<status<<" "<<address<<" "<<mid<<"\n";
				out.close();
				li.increasemembers();			
			}
};
class FecultyMember: public Member{
	string fecultyid;	
};
class Student: public Member{
	int rollno;
};
int valid_date(int day, int mon, int year)    
{
    int is_valid = 1, is_leap = 0;
    if (year >= 1800 && year <= 9999) 
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
        {
            is_leap = 1;
        }
        if(mon >= 1 && mon <= 12)
        {

            if (mon == 2)
            {
                if (is_leap && day == 29) 
                {
                    is_valid = 1;
                }
                else if(day > 28) 
                {
                    is_valid = 0;
                }
            }
            else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) 
            {
                if (day > 30)
                {
                    is_valid = 0;
                }
            }
            else if(day > 31)
            {            
                is_valid = 0;
            }        
        }
        else
        {
            is_valid = 0;
        }
    }
    else
    {
        is_valid = 0;
    }
    return is_valid;
}
class Alert{
	private:
	int studentfine;
	public:
	string issuedate;
	string bookname;
	string returndate;
	char choice;
	int day_diff, mon_diff, year_diff;
	void finecalc()
	{
	int day1, mon1, year1,
        day2, mon2, year2;
    int day_diff, mon_diff, year_diff;         
	k:
    cout<<"\n\n\t\tEnter Issue date as mentioned above (MM DD YYYY): ";
    cin>>mon1>>day1>>year1;
    cout<<"\t\tEnter return date (MM DD YYYY): ";
    cin>>mon2>>day2>>year2;
    if(!valid_date(day1, mon1, year1))
    {
        cout<<"First date is invalid.\n";
		system("cls");
		goto k;        
    }
    if(!valid_date(day2, mon2, year2))
    {
        cout<<"Second date is invalid.\n";
        exit(0);
    }       
    if(day2 < day1)
    {      
        if (mon2 == 3)
        {
            if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) 
            {
                day2 += 29;
            }
            else
            {
                day2 += 28;
            }                        
        }
        else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12) 
        {
           day2 += 30; 
        }
        else
        {
           day2 += 31;
        }
        mon2 = mon2 - 1;
    }
    if (mon2 < mon1)
    {
        mon2 += 12;
        year2 -= 1;
    }       
    day_diff = day2 - day1;
    mon_diff = mon2 - mon1;
    year_diff = year2 - year1;
		studentfine=(year_diff*365+mon_diff*30+day_diff)*2-(14*2);
	cout<<"\t\tTotal fine for returnng the book late is:"<<studentfine<<endl;					
	}	
};
class Librarian{
	friend ostream &operator<<( ostream&, const Librarian & );
  	friend istream &operator>>( istream&, Librarian & );
	private:
	Library li;
	string adminname[25];
	string mobileno[25];
	string address[25];
	string name[25];
	string author[25];
	string id[25];	
	int choice,count,choice1;
	string quantity[25];
	string status[25];
	string category[25];
	float price[25];
	string bname;
	Login l1;
	Member m1;
	public:
void generalmenu()
	{
		
		system("cls");
		loading();
		system("cls");
		o:
		cout<<"\n\t\t\t\t\tFollowing are the options Available:"<<endl<<endl;
		cout<<"\t\t1.Update Book Info."<<endl;
		cout<<"\t\t2.Issue Book."<<endl;
		cout<<"\t\t3.Add Member."<<endl;
		cout<<"\t\t4.Return Book."<<endl;
		cout<<"\t\t0.Exit"<<endl<<endl;
		cout<<"\t\tChoose any of the Above.";
		cin>>choice;
		system("CLS");
		if (choice==1)
		{
			cout<<"\n\t\t\t\t     :Welcome to Book (Stock) Management Menu:"<<endl;
			updateinfo();
		}
		else if(choice==3)
		{
			cout<<"\n\t\t\t\tWelcome to Member Addition Menu:"<<endl<<endl<<endl;
			m1.addmember();
		}
		else if(choice==2)
		{
			issuebook();
		}
		else if (choice==4)
		{
			cout<<"\n\t\t\t\tWelcome to Book Return Menu:"<<endl<<endl<<endl;
			returnbook();
		}
		else if(choice==0)
		{
			system("CLS");
				cout<<"\n\n\t\t.:THANK YOU FOR USING OUR LIBRARY MANAGEMENT SYSTEM:.";
				cout<<"\n\t\t\t\t.:HAVE A GOOD DAY:.";
				exit(0);
		}
		else 
		{
			cout<<"\t\t\t\tOops..!Invalid Input..!"<<endl;
			system("pause");
			system("cls");
			goto o;
		}
	}
	void updateinfo()
	{
		if(choice==1)
		{
			p:
			cout<<"\t\t\t\t\tFollowing are the options Available:"<<endl;
			cout<<"\t\t1.Print All Books List."<<endl;
			cout<<"\t\t2.Search books by name."<<endl;
			cout<<"\t\t3.Delete Book Record."<<endl;
			cout<<"\t\t4.Add New Book."<<endl;
			cout<<"\t\t5.Change Quantity of Book."<<endl;
			cout<<"\t\t0.for Exit."<<endl;
			cout<<"\n\t\tChoose any of the above:";
			cin>>choice;
			if(choice==1)
			{
				system("cls");
				loading();
				system("cls");
				int i=0;
				ifstream in;
				in.open("bookdata.txt");
				cout<<"\t\tBook Name\tAuthor\tNo. of Copies\tcategory\tPrice"<<endl;
				while(!(in.eof()))
				{
					in>>name[i]>>author[i]>>quantity[i]>>status[i]>>category[i]>>price[i];
					if(status[i]=="y")
					cout<<"\t\t"<<name[i]<<"\t\t"<<author[i]<<"\t"<<quantity[i]<<"\t\t"<<category[i]<<"\t"<<price[i]<<endl;
					i++;
				}
				in.close();
			}
			else if(choice==2)
			{
				int i=0;
				int flage;
				cout<<"\t\tEnter Book name:";
				cin>>bname;
				ifstream in;
				in.open("bookdata.txt");
				while(!(in.eof()))
				{
					in>>name[i]>>author[i]>>quantity[i]>>status[i]>>category[i]>>price[i];
					if(bname==name[i])
					{
						cout<<"\t\tThe book is found @ index "<<i<<endl; 
						cout<<"\t\tThe Name Of The Book Is:"<<name[i]<<endl;
						cout<<"\t\tThe Author of this book is:"<<author[i]<<endl;
						cout<<"\t\tThe Copies avaliable of this book are:"<<quantity[i]<<endl;
						flage=1;
						break;	
					}	
				}
			if(flage!=1)
				{
					cout<<"\t\tThe Book Name you Entered is not in the Record"<<endl;
					goto p;
				}
				in.close();
			}
		else if(choice==5)
			{
				int flage;
				string quan;
				cout<<"\t\tEnter Book name:";
				cin>>bname;
				ifstream in;
				ofstream out;
			
				in.open("bookdata.txt");
				for(int i=0;i<=10;i++)
				{
					in>>name[i]>>author[i]>>quantity[i]>>status[i]>>category[i]>>price[i];
					if(bname==name[i])
					{
						cout<<"the bokk is found @ index "<<i<<endl; 
						cout<<"\t\t"<<name[i]<<" "<<author[i]<<" "<<quantity[i]<<endl;
						flage=1;
						cout<<"\t\tEnter quantity you want to change:";
						cin>>quan;
						quantity[i]=quan;
						cout<<"\t\tThe quantity has been changed successfully!"<<endl;
					}
				}
				out.open("bookdata.txt");
				for(int i=0;i<=10;i++)
				{
					out<<name[i]<<" "<<author[i]<<" "<<quantity[i]<<" "<<status[i]<<" "<<category[i]<<" "<<price[i]<<"\n";				
				}
				if(flage!=1)
				{
					cout<<"\t\tThe Book Name you Entered is not in the Record"<<endl;
					system("cls");
					goto p;
				}
				in.close();
				out.close();
			}
		else if(choice==3)
		{
			int flage;
			string stat;
			cout<<"\t\tEnter Book name:";
			cin>>bname;
			ifstream in;
			ofstream out;
			in.open("bookdata.txt");
			for(int i=0;i<=10;i++)
			{
				in>>name[i]>>author[i]>>quantity[i]>>status[i]>>category[i]>>price[i];
				if(bname==name[i])
				{
					cout<<"\t\tthe bokk is found @ index "<<i<<endl; 
					cout<<"\t\t"<<name[i]<<" "<<author[i]<<" "<<quantity[i]<<endl;
					flage=1;
					cout<<"\t\tEnter n To Delete:";
					cin>>stat;
					status[i]=stat;
					cout<<"\t\tThe Book has been removed successfully!"<<endl;
				}
			}
			out.open("bookdata.txt");
			for(int i=0;i<=10;i++)
			{
				out<<name[i]<<" "<<author[i]<<" "<<quantity[i]<<" "<<status[i]<<" "<<category[i]<<" "<<price[i]<<"\n";
				
			}
			if(flage!=1)
			{
				cout<<"\t\tThe Book Name you Entered is not in the Record"<<endl;
				system("cls");
				goto p;
			}
			in.close();
			out.close();
			li.decreasebooks();
		}
		else if(choice==4)
		{
			string authorname;
			string quan;
			string stat;
			string cat;
			float price;
			fstream out;
			out.open("bookdata.txt", ios::app);
			{
			cout<<"\t\tEnter New Book Name:";
			cin>>bname;
			cout<<"\t\tEnter Author Name:";
			cin>>authorname;
			cout<<"\t\tEnter its quantity:";
			cin>>quan;
			cout<<"\t\tEnter Status:";
			cin>>stat;
			cout<<"\t\tEnter Category:";
			cin>>cat;
			cout<<"\t\tEnter Price:";
			cin>>price;
			}
			out<<bname<<" "<<authorname<<" "<<quan<<" "<<stat<<" "<<cat<<" "<<price<<"\n";
			li.increasebooks();
			cout<<"\t\tThe book has been added to record Successfully."<<endl;
			out.close();
		}
		else if(choice==0)
		{
			system("CLS");
				cout<<"\n\n\t\t.:THANK YOU FOR USING OUR LIBRARY MANAGEMENT SYSTEM:.";
				cout<<"\n\t\t\t\t.:HAVE A GOOD DAY:.";
				exit(0);
		}
		else
		{
			cout<<"Oops..! Invalid Input..!"<<endl;
			system("pause");
			system("cls");
			goto p;
		}
		char choice;
			cout<<endl<<endl;
			cout<<"\t\tEnter y or Y to go back to Admin Menu."<<endl;
			cout<<"\t\tEnter n or N to stay on Book Update Menu."<<endl;
			cout<<"\t\tEnter 0 to Exit."<<endl;
			cout<<"\t\tPlease..choose Any of the above:";
			cin>>choice;
			if(choice=='y'||choice=='Y')
			{
			system("cls");
			generalmenu();
			goto p;
				
			}
		    if(choice=='n' || choice=='N')
			{
				system("CLS");
				goto p;
			}
			if(choice=='0')
			{
				system("CLS");
				cout<<"\n\n\t\t.:THANK YOU FOR USING OUR LIBRARY MANAGEMENT SYSTEM:.";
				cout<<"\n\t\t\t\t.:HAVE A GOOD DAY:.";
				exit(0);	
			}	
		}	
	}
	void issuebook()
	{l:
		
		int flage;
		string miname,meid,stat;
		int day,month,year;
		int change;
		cout<<"\n\t\t\t\tWelcome to Book Issue Menu:"<<endl<<endl<<endl;
		cout<<"\t\tEnter Member Name:";
		cin>>miname;
		cout<<"\t\tEnter member ID:";
		cin>>meid;
		cout<<"\t\tEnter member status:";
		cin>>stat;
		ifstream in;
		in.open("memberinfo.txt");
		for(int i=0;i<=25;i++)
		{
			in>>name[i]>>mobileno[i]>>status[i]>>address[i]>>id[i];
			if(miname==name[i]&&meid==id[i]&&stat==status[i])
			{
				cout<<"\t\tEnter Book Name Which Is To Be Issued:";
				cin>>bname;
				cout<<"\t\tEnter Issue date:"<<endl;
		cout<<"\t\tEnter Day:";
		cin>>day;
		cout<<"\t\tEnter month:";
		cin>>month;
		cout<<"\t\tEnter year:";
		cin>>year;
		int i=0;
				ifstream on;
				on.open("bookdata.txt");
				while(!(on.eof()))
				{
					on>>name[i]>>author[i]>>quantity[i]>>status[i]>>category[i]>>price[i];
					if(bname==name[i])
					{
						cout<<"\t\t"<<"The Book "<<bname<<" has Been Issued To: "<<miname<<" ID: "<<meid<<endl;
				change=1;
				i++;
				li.decreasebooks();
						flage=1;	
					}
				}
				fstream out;
				out.open("issuedata.txt",ios::app);
				out<<miname<<" "<<meid<<" "<<bname<<" "<<stat<<" "<<day<<" "<<month<<" "<<year<<"\n";
				out.close();
			char choice;
			cout<<"\n\nPress A to Issue Again..or N to go back to general menu:"<<endl;
			cin>>choice;
			if(choice=='A')
			{
				system("cls");
				goto l;
			}
			else if(choice=='N')
			{
				system("cls");
				generalmenu();
			}	
		in.close();
		on.close();
			}
		}
		if(flage!=1)
		{ k:
			char choice;
			cout<<"Member is not from the member list.."<<endl;
			cout<<"Press A to Enter Again..or N to go back to general menu:"<<endl;
			cin>>choice;
			if(choice=='A')
			{
				system("cls");
				goto l;
			}
			else if(choice=='N')
			{
				system("cls");
				generalmenu();
			}	
		}	
	}
	void returnbook()
	{m:
		Alert a22;
		char choice;
		int i=0,f;
		int flage;
		string miname,meid,stat;
		string day,month,year;
		string mname,mid,state;
		int mday,mmonth,myear;
		int change;
		cout<<"\t\tEnter Member Name:";
		cin>>mname;
		cout<<"\t\tEnter member ID:";
		cin>>mid;
		cout<<"\t\tEnter member status:";
		cin>>state;
		ifstream in;
				in.open("issuedata.txt");
				while(!(in.eof()))
				{
					in>>miname>>meid>>bname>>stat>>day>>month>>year;
					//i++;
					if(mname==miname&&mid==meid&&state==stat)
					{t:
						cout<<"\t\tThis Member: "<<mname<<" was issued Book: "<<bname<<" At date:"<<month<<"/"<<day<<"/"<<year<<endl;
						cout<<endl<<endl<<"\t\tEnter 'A' or 'a' if Book is Lost."<<endl;
						cout<<"\t\tEnter 'N' or 'n' if Book is damaged."<<endl;
						cout<<"\t\tEnter 'S' or 's' if Book is Returned."<<endl;
						cout<<"\t\tChoose any of the above:";
						cin>>choice;
						if (choice=='A'||choice=='a')
						{
							ifstream in;
							in.open("bookdata.txt");
						while(!(in.eof()))
						{
							in>>name[i]>>author[i]>>quantity[i]>>status[i]>>category[i]>>price[i];
							if(bname==name[i])
							{
								cout<<endl<<endl<<"\t\tThe Price of the book "<<name[i]<<" is:"<<price[i]<<endl;
								cout<<"\t\tEnter A or a if the amount equivalent to book price is recieved."<<endl;
								cout<<"\t\tEnter N or n if the amount is not recieved."<<endl;
								cout<<"\t\tChoose any of the above:";
								cin>>choice;
								if(choice=='A'||choice=='a')
								{
									cout<<"\t\tThe price of the book has been recieved!"<<endl;
								}
								if(choice=='N'||choice=='n')
								{
									cout<<"\t\tThe Book Price is to be paid.."<<endl;
									fstream on;
									on.open("pricereturn.txt",ios::app);
									{
										on<<mname<<" "<<mid<<" "<<price[i];
									}
									on.close();
								}
								break;
							}
						}
						in.close();
						}
						else if(choice=='N'||choice=='n')
						{
							float damage;
							a22.finecalc();
							damage=((price[i]/100)*15);
							
							cout<<"\t\tThe fine for damaging book is:"<<damage<<endl;
						}
						else if(choice=='S'||choice=='s')
						{
							if(state=="student")
							{
								a22.finecalc();
							}
							if(state=="teacher")
							{
								cout<<"\t\tThe book Has Been Returned.."<<endl;
							}	
						}	
					}
					break;
				}
				in.close();
			cout<<"\n\n\t\tPress A to Return Again..or N to go back to general menu:"<<endl;
			cin>>choice;
			if(choice=='A')
			{
				system("cls");
				goto m;
			}
			else if(choice=='N')
			{
				system("cls");
				generalmenu();
			}	
		if(flage!=1)
		{
			char choice;
			cout<<"\t\tMember is not from the member list.."<<endl;
			cout<<"\t\tPress A to Enter Again..or N to go back to general menu:"<<endl;
			cin>>choice;
			if(choice=='A')
			{
				system("cls");
				goto m;
			}
			else if(choice=='N')
			{
				system("cls");
				generalmenu();
			}	
	}
	li.increasebooks();
}		
};
ostream &operator<<( ostream &output, const Librarian &num )
 { output <<num.choice1;
 return output; 
 }
 istream &operator>>( istream &input, Librarian &num )
 {
 input >>num.choice1;
 }
int main()
{
	system("color 3f");
	Login l11;
	l11.librarianlogin();
	Librarian a1;
	a1.generalmenu();
	//loading();
}
