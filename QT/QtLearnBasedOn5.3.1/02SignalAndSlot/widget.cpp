#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QDebug>
#include<QWidget>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建一个老师对象
    this->t=new Teacher(this);
    //创建一个学生对象
    this->s=new Student(this);
    //老师饿了学生请客的连接
//    connect(t,&Teacher::hungry,s,&Student::treat);
//    //调用下课函数
//    classIsOver();

    //连接带参数 信号和槽
    //函数指针指向函数地址
    void (Teacher::*teacherSignal)(QString)=&Teacher::hungry;
    void (Student::*studentSlot)(QString)=&Student::treat;
    connect(t,teacherSignal,s,studentSlot);
//    classIsOver();

    //点击下课按钮之后才触发
    QPushButton *p=new QPushButton("下课",this);
    this->resize(600,400);
    p->move(200,100);
    setWindowTitle("请客吃饭");
    //点击按钮触发槽函数
//    connect(p,&QPushButton::clicked,this,&Widget::classIsOver);

    //点击信号触发新的信号
    void (Teacher::*teacherSignal2)(void)=&Teacher::hungry;//无参的信号
    void (Student::*studentSlot2)(void)=&Student::treat;//无参槽函数
    connect(t,teacherSignal2,s,studentSlot2);
    //信号连结信号
    connect(p,&QPushButton::clicked,t,teacherSignal2);

    //断开信号
//    disconnect(t,teacherSignal2,s,studentSlot2);


    //Qt4版本连接
    //Qt4信号槽 连接无参版本
    connect(t,SIGNAL(hungry()),s,SLOT(treat()));//无参
    //优点：参数直观 缺点：类型不做检测
    //Qt5支持Qt4的写法
    connect(t,SIGNAL(hungry(QString)),s,SLOT(treat(QString)));//有参


//    // Lambda表达式
//    [=](){
//        p->setText("aaaaa");
//    }();//不加()是函数声明 加上之后才是函数调用

    //mutable关键字用于修饰值传递的变量，修改的是拷贝的数据而不是原数据
//    QPushButton *myBtn=new QPushButton(this);
//    myBtn->setText("myBtn");
//    QPushButton *myBtn2=new QPushButton(this);
//    myBtn2->setText("myBtn2");
//    myBtn2->move(100,150);
//    int m=10;
//    //此处代码报错要再pro文件中添加 CONFIG+=c++11
//    connect(myBtn,&QPushButton::clicked,this,[m]()mutable{m=10+100;qDebug()<<m;});
//    connect(myBtn2,&QPushButton::clicked,this,[=](){qDebug()<<m;});
//    qDebug()<<m;

//    int ret=[]()->int{return 1000;}();
//    qDebug()<<"ret="<<ret;

        //利用lambda表达式实现点击按钮 关闭窗口
//    QPushButton *btn=new QPushButton(this);
//    btn->setText("关闭");
//    btn->setParent(this);
//    connect(btn,&QPushButton::clicked,this,[=](){
//        this->close();//关闭窗口
////      emit t->hungry("宫保鸡丁");//可以添加类似的语句
//        s->treat("w1w1");
//    });


    //实现一个按钮实现打开和关闭令一个窗口
    QPushButton *test=new QPushButton("打开",this);
    test->move(100,0);
    //注意包含QWidget
    QWidget *w2=new QWidget();
    connect(test,&QPushButton::clicked,[=](){
        if(test->text()=="打开"){
            w2->show();
            w2->setWindowTitle("窗口2");
           test->setText("关闭");
        }else{
            w2->close();
            test->setText("打开");
        }

    });
}
//下课后触发老师饿了信号
void Widget::classIsOver(){
//    emit t->hungry();//emit调用
    emit t->hungry("宫保鸡丁");
}

Widget::~Widget()
{
    delete ui;
}
