#include <iostream>
#include <string>

using namespace std;

class Complex{
    private:
    double real;
    double unreal;
    string clean_spaces(string &metin){
        string temp = metin;
        int a;
        while((a = temp.find(" ")) != -1){
            temp.erase(a);
        }
        return temp;
    }

    public:
    Complex():real(0),unreal(0){}

    Complex(int a):real(a),unreal(0){}

    Complex(double a):real(a), unreal(0){}

    explicit Complex(string metin){

        int uzunluk = metin.length();
        int fp = metin.find("+");
        int fe = metin.find("-");
        int fe2 = uzunluk-metin.rfind("-");
        int sayi = metin.find("i");
        int sayi2 = (fp > sayi) ? fp: sayi;
        int sayi3 = (fe > sayi) ? fe: sayi;
		string a;
		string b;
        if(sayi == -1){//sadece real sayı var ise
			cout <<metin<<endl;
			real = stoi(metin);
        }
		else if(fe == -1 && fp == -1){//içinde + veya - yok ise
			a = metin.substr(0,uzunluk-1);
			unreal = stoi(a);
		}
		else if(fe == fe2 && fp == -1){//içinde sadece 1 tane - var ise
			a = metin.substr(0,fe);
			b = metin.substr(fe,uzunluk-fe);
			real = stoi(a);
			unreal = stoi(b);
		}
		else if(fe >= 0 && fe2 <= uzunluk && fe != fe2){//içinde 2 tane - var ise
			a = metin.substr(fe2,uzunluk-fe2);
			b = metin.substr(0,fe2);
		}
		else if(fp > 0){//içinde 1 tane + var ise
			if(fe == -1 && fe2 > uzunluk){//içinde - yok ise
				a = metin.substr(0,fp);
				b = metin.substr(fp, uzunluk-fp);
			}
			else if(fe >= 0){//içinde - var ise
				a = metin.substr(0,fe);
				b = metin.substr(fe-1, uzunluk-fe+1);
				if(fp>sayi){
					real = stoi(a);
					unreal = stoi(b);
				}
				else{
					real = stoi(b);
					unreal = stoi(a);
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
        real = (real * sayi.get_real()) - (unreal * sayi.get_unreal());
        unreal = (real * sayi.get_unreal()) + (sayi.get_real() * unreal);
    }
    void print(void){
        cout << real;
        if(unreal >= 0){cout <<"+";}
        cout << unreal <<"i" << endl;
    }

};

int main()
{
    cout << "Hello world!" << endl;
    Complex complex_sayi1;
    Complex complex_sayi2(5);
    Complex complex_sayi3(-2, 6);
    Complex complex_sayi4(5.0);
    Complex complex_sayi5("0");
    Complex complex_sayi6("3+2i");
    Complex complex_sayi7("-3+2i");
    Complex complex_sayi8("-3-2i");
    Complex complex_sayi9("-i");
    Complex complex_sayi10("i");
    Complex complex_sayi11("3+i");

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
