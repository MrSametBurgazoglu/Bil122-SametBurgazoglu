#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Complex{
    private:
    double real;
    double unreal;
    string clean_spaces(string &metin){//metindeki boşlukları temizle
        string temp = metin;
        int a;
        while((a = temp.find(" ")) != -1){
            temp.erase(a);
        }
        return temp;
    }

    public:
    Complex():real(0),unreal(0){}//default constructor

    Complex(int a):real(a),unreal(0){}//conversation constructor

    Complex(double a):real(a), unreal(0){}//double için conversation constructor

    explicit Complex(string metin){//metin için constructor

		metin = clean_spaces(metin);//metindeki boşlukları temizle
        int uzunluk = metin.length();//metnin uzunluğunu al
        int fp = metin.find("+");//ilk + nın yerini bul
        int fe = metin.find("-");//ilk - nin yerini bul
        int fe2 = metin.find("-", fe+1);//ikinci - nin yerini bul
        int sayi = metin.find("i");// i karakterinin yerini bul
		string a;//temp için karakter oluştur
		string b;//temp için karakter oluştur
        if(sayi == -1){//sadece real sayı var ise
			real = stoi(metin, nullptr, 10);
			unreal = 0;
        }
		else if(fe == -1 && fp == -1){//içinde + veya - yok ise
			if(metin == "i"){
				real = 0;
				unreal = 1;
				}
			else{
				a = metin.substr(0,uzunluk-1);
				unreal = stoi(a, nullptr, 10);
			}
		}
		else if(fe >= 0 && fe2 == -1  && fp == -1){//içinde sadece 1 tane - var ise
			a = metin.substr(0,fe);
			b = metin.substr(fe,uzunluk-fe-1);
			if(a == ""){
				real = 0;
			}
			else{
				real = stoi(a, nullptr, 10);
			}
			if(b == ""){
				unreal = 1;
			}
			else if(b == "-"){
				unreal = -1;
			}
			else{
				unreal = stoi(b, nullptr, 10);
			}
		}
		else if(fe >= 0 && fe2 >=0 && fe != fe2){//içinde 2 tane - var ise
			a = metin.substr(0,fe2);
			b = metin.substr(fe2,uzunluk-fe2-1);
			real = stoi(a, nullptr, 10);
			if(b == ""){
				unreal = 1;
			}
			else if(b == "-"){
				unreal = -1;
			}
			else{
				unreal = stoi(b, nullptr, 10);
			}
		}
		else if(fp > 0){//içinde 1 tane + var ise
			if(fe == -1){//içinde - yok ise
				a = metin.substr(0,fp);
				b = metin.substr(fp+1, uzunluk-fp-2);
				real = stoi(a, nullptr, 10);
				if(b == ""){
					unreal = 1;
				}
				else{
					unreal = stoi(b, nullptr, 10);
				}
			}
			else if(fe >= 0){//içinde - var ise
				a = metin.substr(0,fp);
				b = metin.substr(fp+1, uzunluk-fp-2);
				if(fp>sayi){
					real = stoi(a, nullptr, 10);
					unreal = stoi(b, nullptr, 10);
				}
				else{
					real = stoi(a, nullptr, 10);
					unreal = stoi(b, nullptr, 10);
				}
			}
		}
		else{
			real = 0;
			unreal = 0;
		}
		
    }

    Complex(int a, int b):real(a),unreal(b){}

    void set_real(const int &sayi){real = sayi;}

    void set_unreal(const int &sayi){unreal = sayi;}

    int get_real (void) const{return real;}

    int get_unreal (void) const{return unreal;}

    void add(Complex &sayi){
        real += sayi.get_real();
        unreal += sayi.get_unreal();
    }
    void substract(Complex &sayi){
        real -= sayi.get_real();
        unreal -= sayi.get_unreal();
    }
    void divide(Complex &sayi){
        int temp = (real * sayi.get_real()) - (unreal * sayi.get_unreal());
        unreal = (real * sayi.get_unreal()) + (sayi.get_real() * unreal);
		real = temp;
    }
    void print(void){
        cout << real;//real kısmı yazdır
        if(unreal >= 0){cout <<"+";}//unreal kısım pozitif ise + ekle
        cout << unreal <<"i" << endl;//unreal kısmı yazdır
    }

};
void karmasik_sayi_sirala(vector <Complex> &liste){
	auto len = liste.size();
	int a[len][3];
	int b = 0;
	int real = liste[0].get_real();
	int unreal = liste[1].get_unreal();
	for(int i = 0; i < len; ++i){
		a[i][0] = i;
		a[i][1] = liste[i].get_real();
		a[i][2] = liste[i].get_unreal();
	}
	bool tamam;
	int temp[3];
	do{
		tamam = true;
		for(int i = 0; i < len-1; ++i){
			if(a[i][1] < a[i+1][1]){
				temp[0] = a[i][0];
				temp[1] = a[i][1];
				temp[2] = a[i][2];
				a[i][0] = a[i+1][0];
				a[i][1] = a[i+1][1];
				a[i][2] = a[i+1][2];
				a[i+1][0] = temp[0];
				a[i+1][1] = temp[1];
				a[i+1][2] = temp[2];
				tamam = false;
			}
			else if(a[i][1] == a[i+1][1] && a[i][2] < a[i+1][2]){
				temp[0] = a[i][0];
				temp[1] = a[i][1];
				temp[2] = a[i][2];
				a[i][0] = a[i+1][0];
				a[i][1] = a[i+1][1];
				a[i][2] = a[i+1][2];
				a[i+1][0] = temp[0];
				a[i+1][1] = temp[1];
				a[i+1][2] = temp[2];
				tamam = false;
			}
		}
	}while(tamam == false);
	for(int i = 0; i<len; ++i){
		liste[a[i][0]].print();
	}
}
int main()
{
    Complex complex_sayi1;
    Complex complex_sayi2(5);
    Complex complex_sayi3(-2, 6);
    Complex complex_sayi4(5.0);
    Complex complex_sayi5("0");
    Complex complex_sayi6("3+2i");
    Complex complex_sayi7("-3+2i");
    Complex complex_sayi8("-3-2i");
    Complex complex_sayi9("-2i");
    Complex complex_sayi10("i");
    Complex complex_sayi11("3+i");
    Complex complex_sayi12("3-i");
    Complex complex_sayi13("-3-i");
    Complex complex_sayi14("-i");
	
	vector<Complex> karmasiksayilist;
	karmasiksayilist.push_back(complex_sayi1);
	karmasiksayilist.push_back(complex_sayi2);
	karmasiksayilist.push_back(complex_sayi3);
	karmasiksayilist.push_back(complex_sayi4);
	karmasiksayilist.push_back(complex_sayi5);
	karmasiksayilist.push_back(complex_sayi6);
	karmasiksayilist.push_back(complex_sayi7);
	karmasiksayilist.push_back(complex_sayi8);
	karmasiksayilist.push_back(complex_sayi9);
	karmasiksayilist.push_back(complex_sayi10);
	
	cout << "Siralama basaliyor"<< endl;
	karmasik_sayi_sirala(karmasiksayilist);
	cout << "Siralama bitti"<< endl;
	
    complex_sayi1.print();
    complex_sayi1.set_real(7);
    complex_sayi1.set_unreal(9);
    complex_sayi1.print();
    complex_sayi1.add(complex_sayi2);
    complex_sayi1.print();
    complex_sayi1.substract(complex_sayi4);
    complex_sayi1.print();
    complex_sayi1.divide(complex_sayi3);
    complex_sayi1.print();
	
    return 0;
}
