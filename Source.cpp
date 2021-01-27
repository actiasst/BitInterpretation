#include <iostream>
#include "Bit_Interpretation.h"

using namespace std;

class Test_Class {
public:
	int a;
	int b;
	int c;
	Test_Class() {};
	Test_Class(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
};

int main() {

	//Bit_Interpretation<int> test{2'451'718'823};
	//test.print_bit_interpetation();
	
	//Bit_Interpretation<bool> test2{true};
	//test2.print_bit_interpetation();
	
	//Bit_Interpretation<float> test3{03.27f};
	//test3.print_bit_interpetation();

	//Bit_Interpretation<unsigned char> test4{15};
	//test4.print_bit_interpetation();

	//Test_Class test{ 1,3,5 };
	//Bit_Interpretation<Test_Class> test5{ test };
	//test5.print_bit_interpetation();

	Bit_Interpretation<int> test6{768};
	//test6.print_hex_interpretation();
	test6.print_octal_interpretation();
	system("pause");
}