#include <iostream>
#include <string>
using namespace std;

int main()
{
	string swap_case;
    cout<<"Enter the string: ";
    getline(cin, swap_case);
	for(int i=0;swap_case[i]!='\0';i++)
	{
		if (swap_case[i]>=65 && swap_case[i]<=90 )          //checking for uppercase characters
			swap_case[i] = swap_case[i] + 32;          //converting uppercase to lowercase
		else if (swap_case[i]>=97 && swap_case[i]<=122 )
		    swap_case[i] = swap_case[i] - 32;              //converting lowercase to uppercase  
	}
	

	cout<<"\n The converted string: "<<swap_case;
return 0;
}
