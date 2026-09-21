#include <iostream>
#include <cmath>
using namespace std;

class TriangleItem {
private:
    int m_sideA;
    int m_sideB;
    int m_sideC;

public:
    //初始化 (无参)
    TriangleItem() {
        m_sideA = 0; m_sideB = 0; m_sideC = 0;
    }

    //初始化 (带参)
    TriangleItem(int a, int b, int c) {
        m_sideA = a; m_sideB = b; m_sideC = c;
    }

    //修改
    void set(int a, int b, int c) {
        m_sideA = a; m_sideB = b; m_sideC = c;
    }

    //获取
    int getSideA() { return m_sideA; }
    int getSideB() { return m_sideB; }
    int getSideC() { return m_sideC; }

    //输出
    void printTri() {
        cout << "三角形的三边分别为: " << m_sideA << ", " << m_sideB << ", " << m_sideC << endl;
    }

    //判断是否为三角形
    bool isTriangle() {
        return (m_sideA + m_sideB > m_sideC && m_sideA + m_sideC > m_sideB && m_sideB + m_sideC > m_sideA);
    }

    //计算周长
    int calPerimeter() {
        if (!isTriangle()) return 0;
        return m_sideA + m_sideB + m_sideC;
    }

    //计算面积
    float calArea() {
        if (!isTriangle()) return 0.0;
        float p = (m_sideA + m_sideB + m_sideC) / 2.0;//半周长
        return sqrt(p * (p - m_sideA) * (p - m_sideB) * (p - m_sideC));//海伦公式
    }

    //判断类型
    void printType() {
        if (!isTriangle()) {
            cout << "不是三角形" << endl;
            return;
        }
        if (m_sideA == m_sideB && m_sideB == m_sideC) {
            cout << "等边三角形" << endl;
        }
        else if (m_sideA == m_sideB || m_sideA == m_sideC || m_sideB == m_sideC) {
            cout << "等腰三角形" << endl;
        }
        else {
            cout << "普通三角形" << endl;
        }
    }
};

int main() {
    TriangleItem t(3, 4, 5);
    t.printTri();
    t.printType();
    cout << "周长为: " << t.calPerimeter() << endl;
    cout << "面积为: " << t.calArea() << endl;

    return 0;
}