#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n,i=0,s,p,k;
	int numOfLine=0;
	int linetodelet=0 ;
    ifstream fin;  
	ofstream fout;
    string fName,line;
	string max ;
	string notNeedW,replacment;
	string arr[10000]; //asuming that there is no file has a 10000 line
	string arrayOfStrings[1000];//asuming that there is no line has a 1000 word
	string arrayStrings[1000]; //asuming that there is no line has a 1000 word

	do
	{

		system("color a");
		system("cls");

		cout<<"----------- welcome to our  text processor application -----------"<<endl;
		cout<<"----------- Abd-Alkhaleq Aljonide  &&  Moawya Natsheh  -----------"<<endl;
		cout<<endl;
		//print the menu
    cout<<"1-enter file name.\n"
		<<"2-print contents.\n"
		<<"3-count lines.\n"
        <<"4-find longest word.\n"
		<<"5-replace word.\n"
		<<"6-delet line\n"
        <<"7-save file.\n"
		<<"8-save as a newer file.\n"
		<<"9-exit.\n"
        <<endl;

	cout<<"choose your choice : ";
    cin>>n;

    switch(n)
	{
        case 1:
        cout << "Enter File name to open : ";
        cin >> fName;

		fin.open( fName.c_str() );

		//test if the file exist
		if (!fin)
		{
			cout<<"file not exist "<<endl;
			return 1;
		}

		//read file component and store it in the arr aray 
		i=0;
		numOfLine=0;

        while(fin)                        
		{
            getline(fin,line);                                                 
            arr[i]=line;
            numOfLine++;
			i++;

        }
        break;

        case 2:
        for(int t=0;t<numOfLine;t++)
		    cout<<arr[t]<<endl;
		
		break;

        case 3:
        cout<<"Number line of file = "<<numOfLine-1<<endl;
        break;

        case 4:
        int counterSpace;
        max=" ";
        for(int o=0;o<numOfLine;o++)
		{
		    counterSpace=0;

			//find number of spaces
			for( p=0;p<(arr[o].size());p++)
				if(arr[o].find(' ',p)==p) 
					counterSpace++;

			//cut the line text to words and store the words in arrayStrings array
			for(s=0;s<counterSpace+1;s++)
			{
				arrayStrings[s]=arr[o].substr(0,arr[o].find(' '));
				arr[o]=arr[o].substr(arr[o].find(' ')+1,arr[o].size());
				if(arrayStrings[s].size()>max.size())
					max=arrayStrings[s];
			}

			//restore the coumponent of arrayStrings array to arr array after delete any of it's coumponent 
			arr[o]="";
			for( k=0;k<counterSpace+1;k++)
				arr[o]+=arrayStrings[k]+" ";

        }

        cout<<"The maximum value is : "<<max<<endl;
        break;

        case 5:
        cout<<"Enter the word that you want to replace : ";
        cin>>notNeedW;
        cout<<"Enter the word that you want to replace instead : ";
        cin>>replacment;
		
	    int counterOfSpace;

        for(int h=0;h<numOfLine;h++)
		{

			//find number of spaces
			counterOfSpace=0;
			for( p=0;p<(arr[h].size());p++)
				if(arr[h].find(' ',p)==p) 
					counterOfSpace++;

			//cut the line text to words and store the words in arrayStrings array		
			for( s=0;s<=counterOfSpace;s++)
			{
				arrayOfStrings[s]=arr[h].substr(0,arr[h].find(' '));
				arr[h]=arr[h].substr(arr[h].find(' ')+1,arr[h].size());
		
				if(arrayOfStrings[s]==notNeedW)
					arrayOfStrings[s]=replacment;
			}

			//restore the coumponent of arrayStrings array to arr array after delete any of it's coumponent 
			arr[h]="";
			for( k=0;k<counterOfSpace+1;k++)
				arr[h]+=arrayOfStrings[k]+" ";
		}
		
        break;

		case 6:

			cout<<"Enter the line number that you want to delete : ";
			cin>>linetodelet;
			arr[linetodelet-1]="";

			//after delete the line , we will reformat the arr array 
			for(int y=linetodelet-1;y<numOfLine-1;y++)
			swap(arr[y],arr[y+1]);

			// the number of lines will decrease by one
			if(linetodelet<=numOfLine-1)
			numOfLine--;

			break;

        case 7:
        fout.open( fName.c_str() );

        for(int u=0;u<numOfLine;u++)
            fout<<arr[u]<<endl; 
        
		fout.close();
        break;

        case 8:
        
        string otherFile;
		ofstream fou;

        cout<<"Enter the name of the other file that you want : ";
        cin>>otherFile;
        
        fou.open( otherFile.c_str() );

		//to print the arr array component in the file
        for(int r=0;r<numOfLine;r++)
            fou<<arr[r]<<endl;

		   fou.close();
           break;
           

    }
		fin.close();
       system("pause");

	}while(n!=9);
      
    return 0;
}
