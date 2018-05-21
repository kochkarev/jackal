#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

class Exception {
public:
	virtual const char *what() const = 0;
private:
	int str_num;
	int sym_num;
}

class LexerException : public Exception {
public:
	LexerException(int strnum, int symnum) : str_num(strnum), sym_num(symnum) {}
	const std::string what() const noexcept {
		std::string tmp = "Lexical error in line: ";
		tmp += std::to_string(str_num);
		tmp += " , symbol number: ";
		tmp += std::to_string(sym_num);
		return tmp;
	}
};

#endif