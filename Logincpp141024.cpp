
#include <fstream>
#include <iostream>
#include<vector>
#include <string>


using namespace std;

struct usersrc // made struct to store user emails that is entered 
{
	string email;

};

struct userdata // made a struct to store the allowed users to login in 
{
	vector<usersrc>users; // a vector yo store the above usersrc and alled it users 

	void userfile(const string& filename) // function is made giving it a const string and calling it filename 
	{
		ifstream file(filename);// need to access the file in my folder 
		string line; // string line 
		while (getline(file,line)) // while we getline from my file 
		{
			users.push_back({line}); // in my users struct add the data of the whole line by line also initlizing it 
		}
	}

	bool validuser(const string& email) // fuction made to check if enterd email exist in my file 
	{
		for ( auto& usersrc:users) // userscr can access my users struck 
		{
			if (usersrc.email == email) 
			{
				return true;
			}
		}
		return false;
	}

};


int main()
{
	userdata userloginemail; // calling struct called it userloginemails 

	userloginemail.userfile("userlogin.txt"); // userloginemail opens my userfile fuction to get access from my file 

	string uemail; // string uemail
	int trys = 0; // int trys for keeping track of num of trys 

	while (trys<3)// while the try is < then 3 
	{
		cout << " Please Enter Your Email" << endl; //show
		cin >> uemail; // get user enterd email

		if (userloginemail.validuser(uemail)) // if the userloginemail is same as my emails in my file then 
		{
			cout << " Welcome " << uemail << " , You are Logged-in" << endl; // show
			break;

		}
		else
		{
			cout << " Invalid Email .... Please Try Again : " << endl; // show if to in file
			trys++;// add 1 to trys to keep track 
		}

	}

	if (trys==3) // if the number of trys is equal to 3 
	{
		cout << " Failed To Login After 3 Trys" << endl; // show
		exit(0);// and exit the app 
	}
	return 0;
  
}

