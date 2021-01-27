#pragma once
#include <iostream>
#include <string>

template<typename T>
class Bit_Interpretation {
	T value;
	void print_byte(short);
	void print_hex(short);
	void print_octal(short);
public:
	void print_bit_interpetation();
	void print_hex_interpretation();
	void print_octal_interpretation();
	void print_all_interpretations();
	Bit_Interpretation(T argument) {
		value = argument;
	}
	void change_value(T value) {
		this->value = value;
	}
};

template<typename T>
void Bit_Interpretation<T>::print_byte(short byte) {
	std::string tmp{}, end_string{};
	while (byte) {
		tmp += std::to_string(byte % 2);
		byte /= 2;
	}

	if (tmp.length() < 8) {
		int number_of_zeros = 8 - tmp.length();
		for (int i = 0; i < number_of_zeros; i++)
			tmp += "0";
	}

	for (int i = tmp.length() - 1; i > -1; i--) {
		end_string += tmp[i];
		end_string += " ";
	}
	std::cout << end_string << std::endl;
}

template<typename T>
void Bit_Interpretation<T>::print_hex(short byte){
	std::string tmp{}, end_string{};
	short tmp_value;
	while (byte) {
		switch (tmp_value = byte % 16){
		case 15:
			tmp += "F";
			break;
		case 14:
			tmp += "E";
			break;
		case 13:
			tmp += "D";
			break;
		case 12:
			tmp += "C";
			break;
		case 11:
			tmp += "B";
			break;
		case 10:
			tmp += "A";
			break;
		default:
			tmp += std::to_string(tmp_value);
			break;
		}
		byte /= 16;
	}

	if (tmp.length() < 2) {
		int number_of_zeros = 2 - tmp.length();
		for (int i = 0; i < number_of_zeros; i++)
			tmp += "0";
	}

	for (int i = tmp.length() - 1; i > -1; i--) {
		end_string += tmp[i];
		end_string += " ";
	}
	std::cout << end_string << std::endl;
}

template<typename T>
inline void Bit_Interpretation<T>::print_octal(short byte){
	std::string tmp{}, end_string{};
	while (byte) {
		tmp += std::to_string(byte % 8);
		byte /= 8;
	}

	if (tmp.length() < 4) {
		int number_of_zeros = 4 - tmp.length();
		for (int i = 0; i < number_of_zeros; i++)
			tmp += "0";
	}

	for (int i = tmp.length() - 1; i > -1; i--) {
		end_string += tmp[i];
		end_string += " ";
	}
	std::cout << end_string << std::endl;
}

template<typename T>
void Bit_Interpretation<T>::print_bit_interpetation() {
	T *pointer = &value;
	unsigned char* byte_pointer = reinterpret_cast<unsigned char*>(pointer);
	std::cout << "   7 6 5 4 3 2 1 0" << std::endl << std::endl;
	for (int i = sizeof(T) - 1; i > -1; i--) {
		std::cout << i << "  ";
		print_byte(static_cast<short>(*(byte_pointer + i)));
	}
}

template<typename T>
void Bit_Interpretation<T>::print_hex_interpretation(){
	T *pointer = &value;
	unsigned char* byte_pointer = reinterpret_cast<unsigned char*>(pointer);
	std::cout << "   1 0" << std::endl << std::endl;
	for (int i = sizeof(T) - 1; i > -1; i--) {
		std::cout << i << "  ";
		print_hex(static_cast<short>(*(byte_pointer + i)));
	}
}

template<typename T>
void Bit_Interpretation<T>::print_octal_interpretation(){
	T *pointer = &value;
	unsigned char* byte_pointer = reinterpret_cast<unsigned char*>(pointer);
	std::cout << "   3 2 1 0" << std::endl << std::endl;
	for (int i = sizeof(T) - 1; i > -1; i--) {
		std::cout << i << "  ";
		print_octal(static_cast<short>(*(byte_pointer + i)));
	}
}

template<typename T>
inline void Bit_Interpretation<T>::print_all_interpretations(){
	print_bit_interpetation();
	print_octal_interpretation();
	print_hex_interpretation();
}
