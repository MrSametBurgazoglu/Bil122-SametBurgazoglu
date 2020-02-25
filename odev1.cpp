/*
*Developer:Samet Burgazoglu
*Name:odev1.cpp
*Time:25/02/2020
*Purpose:This software writes triangle, inverted triangle and diamond to console
*/
#include <iostream>

using namespace std;

int is_valid(int start, int finish, int value){// this function checks the validity of the value

    if(value >= start && finish >= value)// if value between start and finish
        return value % 2;// if it's single return 1 else return 0
    return 0;

}

void give_info(void){//this function writes about how to use this software
	cout << "1:Duz ucgen" << endl;
    cout << "2:Ters ucgen" << endl;
    cout << "3:Elmas" << endl;
    cout << "0:Cıkıs" << endl;
}

int get_value(int start, int finish){//this function takes value from console
    int devam = 0;
    int value = 0;
    while(devam != 3){//this loop takes value until the value is valid or the loop returns for 3rd time
        cout << "Lutfen gecerli bir deger girin" << endl;
        cin >> value;
        if(is_valid(start, finish, value))//check for invalid
			return value;
		else
			devam++;//if it is not invalid countinue to get value from console
    }
    return 0;
}


void write_star_line(int number, int row){//this function writes a line of shape
    int deger = (row-number)/2;//calculate how many space need to press
    for(int i = 0; i < deger; ++i)
        cout << " ";
    for(int i = 0; i < number; ++i)
        cout << "*";
    for(int i = 0; i < deger; ++i)
        cout << " ";
    cout << endl;//pass to newline
}

void duzUcgen(int deger){//this function writes a triangle to console by using write_star_line function
	for(int i = 1; i<=deger; i+=2){
		write_star_line(i, deger);
		}
	}

void tersUcgen(int deger){//this function writes a inverted triangle to console by using write_star_line function
	for(int i = deger; 0<i; i-=2){
		write_star_line(i, deger);
		}
	}

void elmas(int deger){//this function writes a diamond shape to console by using duzUcgen and tersUcgen functions
	duzUcgen(deger);
	tersUcgen(deger);
	}

int main()
{
    int start = 0, finish = 15, value = 0;//initialize  variables
    int mode = 0;//initialize mode variable
    give_info();//give info to user
    cin >> mode;//take mode
    if(mode == 1){
		start = 3;//set start
		value = get_value(start, finish);//get value
		if(value != 0)//if value is invalid
			duzUcgen(value);
		}
	else if(mode == 2){
		start = 3;//set start
		value = get_value(start, finish);//get value
		if(value != 0)//if value is invalid
			tersUcgen(value);
		}
	else if(mode == 3){
		start = 5;//set start
		value = get_value(start, finish);//get value
		if(value != 0)//if value is invalid
			elmas(value);
		}
    //NOTE:If the mod is not one of the values defined here, the software turn itself off
    return 0;
}
