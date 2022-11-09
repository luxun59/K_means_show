#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

using namespace std;

struct NODE_INFO {
    double x;
    double y;
    int type;
    int classification;

    NODE_INFO()  //默认构造函数
    {
        x = 0;
        y = 0;
        type = 0;
        classification = 0;
    }

    NODE_INFO(double m_x,double m_y)  //构造函数
    {
        x = m_x;
        y = m_y;
        type = 0;
        classification = 0;
    }

    NODE_INFO(double m_x,double m_y,int m_type)  //构造函数
    {
        x = m_x;
        y = m_y;
        type = m_type;
        classification = 0;
    }

    NODE_INFO(double m_x,double m_y,int m_type,int m_classification)  //构造函数
    {
        x = m_x;
        y = m_y;
        type = m_type;
        classification = m_classification;
    }


    void set(NODE_INFO* s1,NODE_INFO* s2)//赋值函数
    {
        s1->x = s2->x;
        s1->y = s2->y;
        s1->type = s2->type;
        s1->classification = s2->classification;
    }

    void operator=(const NODE_INFO& s)//重载运算符
    {
        set(this,(NODE_INFO*)&s);
    }

    //重载+号
    friend NODE_INFO operator+(const NODE_INFO& s1,const NODE_INFO& s2 )//重载运算符
    {
        return NODE_INFO(s1.x+s2.x,s1.y+s2.y,s1.type);
    }

    //重载除法
    friend NODE_INFO operator/(const NODE_INFO& s,const int m )//重载运算符
    {
        return NODE_INFO(s.x/m,s.y/m,s.type);
    }

    //重载乘法
    friend NODE_INFO operator*(const NODE_INFO& s,const int m )//重载运算符
    {
        return NODE_INFO(s.x*m,s.y*m,s.type);
    }

    //重载相等比较
    friend bool operator==(const NODE_INFO& s1,const NODE_INFO& s2)//重载运算符
    {
        if(s1.x==s2.x && s1.y == s2.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    friend ostream& operator << (ostream &Out, const NODE_INFO &S)
    {
        Out << "{"<<"x:" << S.x << " " << "y:" << S.y<<"Type:"<<S.type<<"}";
        return Out;
    }


    NODE_INFO(const NODE_INFO& s)//复制构造函数
    {
        *this = s;
    }



};



#endif // NODE_H
