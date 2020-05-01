#pragma once

#include <iostream>

class CSum {
public:
	CSum() {
		std::cout << "CSum::CSum()" << std::endl;
		m_nSum = 13;
	}
	virtual ~CSum() {
		std::cout << "CSum::~CSum()" << std::endl;
	}

	int Inc(int i){
		std::cout << "CSum::Inc()" << std::endl;
		m_nSum += i;
		return m_nSum;
	}
private:
	int m_nSum;	
};
// https://3dgen.github.io/cppwasm-book/en/ch4-techniques/ch4-03-export-obj.html
struct Sum;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_KEEPALIVE
#endif
int Simple_Sum(int a, int b) {
	return a + b;
}

#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_KEEPALIVE
#endif
struct Sum* Sum_New() {
	CSum *obj = new CSum();
	return (struct Sum*)obj;
};
#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_KEEPALIVE
#endif
void Sum_Delete(struct Sum* sum) {
	CSum *obj = (CSum*)sum;
	delete obj;
}
#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_KEEPALIVE
#endif
int Sum_Inc(struct Sum* sum, int i) {
	CSum *obj = (CSum*)sum;
	return obj->Inc(i);
}

#ifdef __cplusplus
}
#endif