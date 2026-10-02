#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

// 三角形题目类
class TriangleItem {
private:
    int m_id;           // 题目编号
    int m_sideA;        // 三角形边长A
    int m_sideB;        // 三角形边长B
    int m_sideC;        // 三角形边长C
    int m_userAnswer;   // 用户答案
    int m_correctAnswer;// 正确答案
    int m_score;        // 分数

public:
    // 初始化（无参）
    TriangleItem() {
        m_id = 0; m_sideA = 0; m_sideB = 0; m_sideC = 0;
        m_userAnswer = 0; m_correctAnswer = 0; m_score = 0;
    }

    // 初始化（带参）
    TriangleItem(int id, int a, int b, int c) {
        m_id = id; m_sideA = a; m_sideB = b; m_sideC = c;
        m_userAnswer = 0; m_correctAnswer = 0; m_score = 0;
    }

    // 修改
    void set(int id, int a, int b, int c) {
        m_id = id; m_sideA = a; m_sideB = b; m_sideC = c;
    }

    // 获取
    int getId() { return m_id; }
    int getSideA() { return m_sideA; }
    int getSideB() { return m_sideB; }
    int getSideC() { return m_sideC; }
    int getScore() { return m_score; }

    // 输出
    void printTri() {
        cout << "题目编号：" << m_id << endl;
        cout << "三角形的三边分别为：" << m_sideA << "，" << m_sideB << "，" << m_sideC << endl;
    }

    // 判断是否为三角形
    bool isTriangle() {
        return (m_sideA + m_sideB > m_sideC && m_sideA + m_sideC > m_sideB && m_sideB + m_sideC > m_sideA);
    }

    // 计算周长
    int calPerimeter() {
        if (!isTriangle()) return 0;
        return m_sideA + m_sideB + m_sideC;
    }

    // 计算面积
    float calArea() {
        if (!isTriangle()) return 0.0;
        float p = (m_sideA + m_sideB + m_sideC) / 2.0; // 半周长
        return sqrt(p * (p - m_sideA) * (p - m_sideB) * (p - m_sideC)); // 海伦公式
    }

    // 用户答案评分
    void answerQuestion() {
        m_correctAnswer = calArea();
        cout << "请输入三角形的面积：";
        cin >> m_userAnswer;

        if (m_userAnswer == m_correctAnswer) {
            m_score = 10;
            cout << "回答正确！得10分。" << endl;
        }
        else {
            m_score = 0;
            cout << "回答错误！正确答案是：" << m_correctAnswer << "，得0分。" << endl;
        }
    }
};

// 题库类
class QuestionBank {
private:
    string m_name;               // 题库名称
    int m_num;                   // 题目数量
    int m_totalScore;            // 总分
    double m_avgScore;           // 平均分
    vector<TriangleItem> m_questions; // 包含的所有题目

public:
    // 初始化
    QuestionBank(string name) {
        m_name = name;
        m_num = 0;
        m_totalScore = 0;
        m_avgScore = 0.0;
    }

    // 修改
    void setName(string name) {
        m_name = name;
    }

    // 获取
    string getName() { return m_name; }
    int getNum() { return m_num; }
    int getTotalScore() { return m_totalScore; }
    double getAvgScore() { return m_avgScore; }

    // 输出
    void printBank() {
        cout << "题库名称：" << m_name << endl;
        cout << "题目数量：" << m_num << endl;
        cout << "总分：" << m_totalScore << endl;
        cout << "平均分：" << m_avgScore << endl;
    }

    // 添加题目
    void addQuestion(TriangleItem question) {
        m_questions.push_back(question);
        m_num++;
    }

    // 删除题目
    void removeQuestion(int id) {
        for (int i = 0; i < m_questions.size(); i++) {
            if (m_questions[i].getId() == id) {
                m_questions.erase(m_questions.begin() + i);
                m_num--;
                return;
            }
        }
    }

    // 查询所有题目
    void queryAllQuestion() {
        for (int i = 0; i < m_questions.size(); i++) {
            m_questions[i].printTri();
        }
    }

    // 用户开始答题
    void startAnswer() {
        for (int i = 0; i < m_questions.size(); i++) {
            cout << "第 " << i + 1 << " 题：" << endl;
            m_questions[i].answerQuestion();
        }
    }

    // 计算总分和平均分
    void calTotalAndAvgScore() {
        m_totalScore = 0;
        for (int i = 0; i < m_questions.size(); i++) {
            m_totalScore += m_questions[i].getScore();
        }
        if (m_num > 0) {
            m_avgScore = (double)m_totalScore / m_num;
        }
        else {
            m_avgScore = 0.0;
        }
    }
};

int main() {

    QuestionBank myBank("几何图形题库"); // 创建题库

    // 添加题目
    myBank.addQuestion(TriangleItem(1, 3, 4, 5));   // 面积是6
    myBank.addQuestion(TriangleItem(2, 6, 8, 10));  // 面积是24
    myBank.addQuestion(TriangleItem(3, 5, 5, 6));   // 面积是12

    // 查询题目
    myBank.queryAllQuestion();

    // 开始答题
    myBank.startAnswer();

    // 统计成绩并输出
    myBank.calTotalAndAvgScore();
    myBank.printBank();

    // 删除一个题目并再次查看
    myBank.removeQuestion(2);
    myBank.queryAllQuestion();
    myBank.calTotalAndAvgScore();

    return 0;
}