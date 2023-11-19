// Hello.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main() {
    int number = 10;
    int* ptr = &number; // 获取变量 number 的地址并存储在指针 ptr 中

    string sa = "hello";

    string s = "hello";
    string* s1 = &s;

    string ss = "hello";
    string* ss1 = &ss;

    s = sa + "world";
    ss = sa + "world";
    std::cout << "添加字符串之后是否相等（字符串本身）:" << (s == ss) << std::endl;

    std::cout << "变量 number 的地址是：" << ptr << std::endl;
    std::cout << "变量 s 的地址是：" << s1 << std::endl;
    std::cout << "变量 ss 的地址是：" << ss1 << std::endl;
    std::cout << "是否相等:" << (*s1 == *ss1) << std::endl;

    return 0;
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
