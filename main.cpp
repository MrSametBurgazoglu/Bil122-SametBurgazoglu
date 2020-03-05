#include <iostream>
#include <string>

using namespace std;

class Complex{
    private:
    double real;
    double unreal;


    public:
    Complex():real(0),unreal(0){}

    Complex(int a):real(a),unreal(0){}

    Complex(double a):real(a), unreal(0){}

    Complex(string metin){
    cout <<"deneme"<<endl;
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
        real /= sayi.get_real();
        unreal /= sayi.get_unreal();
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
