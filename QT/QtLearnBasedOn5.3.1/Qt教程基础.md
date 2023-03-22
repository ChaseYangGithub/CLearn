* 传智教育 – C++学院

* **Qt5  **教程：视频链接：[链接](https://www.bilibili.com/video/BV1g4411H78N?p=1&spm_id_from=pageDriver&vd_source=54d6f5e269c668b7d2e2c71481a13789)

* 代码基于Qt 5.3
* 基于黑马课程文档添加修改 ，仅用于个人学习！

* **GitHub**:[CLearn](https://github.com/ChaseYangGithub/CLearn)

# 1  Qt概述

## 1.1 什么是Qt

Qt是一个**跨平台**的C++**图形用户界面应用程序框架**。它为应用程序开发者提供建立艺术级图形界面所需的所有功能。它是完全面向对象的，很容易扩展，并且允许真正的组件编程。

## 1.2 Qt的发展史

1991年 Qt最早由奇趣科技开发

1996年 进入商业领域，它也是目前流行的Linux桌面环境KDE的基础

2008年 奇趣科技被诺基亚公司收购，Qt称为诺基亚旗下的编程语言

2012年 Qt又被Digia公司收购

2014年4月 跨平台的集成开发环境Qt Creator3.1.0发布，同年5月20日配发了Qt5.3正式版，至此Qt实现了对iOS、Android、WP等各平台的全面支持。

当前Qt最新版本为 5.5.0

## 1.3 支持的平台

*  Windows – XP、Vista、Win7、Win8、Win2008、Win10

*  Uinux/X11 – Linux、Sun Solaris、HP-UX、Compaq Tru64 UNIX、IBM AIX、SGI IRIX、FreeBSD、BSD/OS、和其他很多X11平台

*  Macintosh – Mac OS X

*  Embedded – 有帧缓冲支持的嵌入式Linux平台，Windows CE

## 1.4 Qt版本

Qt按照不同的版本发行，分为商业版和开源版

*  商业版

为商业软件提供开发，他们提供传统商业软件发行版，并且提供在商业有效期内的免费升级和技术支持服务。

*  开源的LGPL版本：

为了开发自有而设计的开放源码软件，它提供了和商业版本同样的功能，在GNU通用公共许可下，它是免费的。

## 1.5 Qt的安装

### Linux Host

·    [Qt 5.5.0 for Linux 32-bit (535 MB)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-linux-x86-5.5.0.run) [  (info)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-linux-x86-5.5.0.run.mirrorlist)

·    [Qt 5.5.0 for Linux 64-bit (532 MB)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-linux-x64-5.5.0-2.run) [  (info)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-linux-x64-5.5.0-2.run.mirrorlist)

·    [Qt 5.5.0 for Android (Linux 64-bit, 605 MB)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-linux-x64-android-5.5.0-2.run) [  (info)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-linux-x64-android-5.5.0-2.run.mirrorlist)

·    [Qt 5.5.0 for Android (Linux 32-bit, 608 MB)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-linux-x86-android-5.5.0.run) [  (info)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-linux-x86-android-5.5.0.run.mirrorlist)

### OS X Host

·    [Qt 5.5.0 for Mac (588 MB)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-mac-x64-clang-5.5.0.dmg) [  (info)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-mac-x64-clang-5.5.0.dmg.mirrorlist)

·    [Qt 5.5.0 for Android (Mac, 652 MB)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-mac-x64-android-5.5.0.dmg) [  (info)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-mac-x64-android-5.5.0.dmg.mirrorlist)

·    [Qt 5.5.0 for Android and iOS (Mac, 1.7 GB)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-mac-x64-android-ios-5.5.0.dmg) [  (info)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-mac-x64-android-ios-5.5.0.dmg.mirrorlist)

### Windows Host

·    [Qt 5.5.0 for Windows 64-bit (VS 2013, 650 MB)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-windows-x86-msvc2013_64-5.5.0.exe) [  (info)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-windows-x86-msvc2013_64-5.5.0.exe.mirrorlist)

·    [Qt 5.5.0 for Windows 32-bit (VS 2013, 633 MB)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-windows-x86-msvc2013-5.5.0.exe) [  (info)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-windows-x86-msvc2013-5.5.0.exe.mirrorlist)

·    [Qt 5.5.0 for Windows 32-bit (VS 2012, 587 MB)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-windows-x86-msvc2012-5.5.0.exe) [  (info)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-windows-x86-msvc2012-5.5.0.exe.mirrorlist)

·    [Qt 5.5.0 for Windows 32-bit (VS 2010, 585 MB)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-windows-x86-msvc2010-5.5.0.exe) [  (info)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-windows-x86-msvc2010-5.5.0.exe.mirrorlist)

·    [Qt 5.5.0 for Windows 32-bit (MinGW 4.9.2, 959 MB)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-windows-x86-mingw492-5.5.0.exe) [  (info)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-windows-x86-mingw492-5.5.0.exe.mirrorlist)



·    [Qt 5.5.0 for Android (Windows 32-bit, 1.0 GB)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-windows-x86-android-5.5.0.exe) [  (info)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-windows-x86-android-5.5.0.exe.mirrorlist)

·    [Qt 5.5.0 for Windows RT 32-bit (621 MB)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-windows-x86-winrt-5.5.0.exe) [  (info)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-windows-x86-winrt-5.5.0.exe.mirrorlist)

 

Qt对不同的平台提供了不同版本的安装包，可根据实际情况自行下载安装，本文档使用[Qt 5.5.0 for Windows 32-bit (MinGW 4.9.2, 959 MB)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-windows-x86-mingw492-5.5.0.exe) [  (info)](http://download.qt.io/official_releases/qt/5.5/5.5.0/qt-opensource-windows-x86-mingw492-5.5.0.exe.mirrorlist) 版本就行讲解。

MinGW32 --> Minimalist GNU for Windows 32

## 1.6 Qt的优点

*  跨平台，几乎支持所有的平台

*  接口简单，容易上手，学习QT框架对学习其他框架有参考意义。

*  一定程度上简化了内存回收机制 

*  开发效率高，能够快速的构建应用程序。

*  有很好的社区氛围，市场份额在缓慢上升。

*  可以进行嵌入式开发。

# 2  创建Qt项目

## 2.1 使用向导创建

打开Qt Creator 界面选择 New Project或者选择菜单栏 【文件】-【新建文件或项目】菜单项

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033292.jpg)

弹出New Project对话框，选择Qt Widgets Application， 

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033293.jpg)

选择【Choose】按钮，弹出如下对话框

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033294.jpg)

设置项目名称和路径，按照向导进行下一步，

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033295.jpg)

选择编译套件

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033296.jpg)

向导会默认添加一个继承自CMainWindow的类，可以在此修改类的名字和基类。继续下一步

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033297.jpg)

即可创建出一个Qt桌面程序。

## 2.2   手动创建

添加一个空项目

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033298.jpg)

选择【choose】进行下一步。设置项目名称和路径 —> 选择编译套件 --> 修改类信息 --> 完成（步骤同上），生成一个空项目。在空项目中添加文件：在项目名称上单击鼠标右键弹出右键菜单，选择【添加新文件】

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033299.jpg)

弹出新建文件对话框

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033300.jpg)

在此对话框中选择要添加的类或者文件，根据向导完成文件的添加。



## 2.3 文件介绍

### 2.3.1 `main.cpp`

```C++
#include "mywidget.h"//自己写的类
#include <QApplication>//包含一个应用程序的头文件

//main程序入口 argc 命令函变量的数据 argv 命令行变量的数组
int main(int argc, char *argv[])
{
    //对象 a 应用程序对象，在Qt中 有且只有一个
    QApplication a(argc, argv);
    //窗口对象  myWidget父类是Widget
    myWidget w;
    //show方法 窗口对象，默认不会显示 必须调用show方法才会显示
    w.show();
    //让应用程序对象进入消息循环状态，类似while(true)
    //当代码阻塞到这行，后面所有代码不执行
    return a.exec();
}

```



### 2.3.2   .pro文件

在使用Qt向导生成的应用程序.pro文件格式如下：



    properties
    #-------------------------------------------------
    #
    
    # Project created by QtCreator 2023-02-28T10:30:19
    
    #
    #-------------------------------------------------
    
    QT       += core gui#Qt包含的模块
    
    greaterThan(QT_MAJOR_VERSION, 4): QT += widgets#在4版本以上包含widgets模块
    
    TARGET = 01firstProject #目标  即生成的exe文件
    TEMPLATE = app #模板 应用程序模板 Application


​    
​    SOURCES += main.cpp\    #源文件
​            mywidget.cpp
​    
​    HEADERS  += mywidget.h#头文件
​     #窗口设计文件
​    
​    FORMS  += mainwindow.ui


**.pro**就是工程文件(project)，它是qmake自动生成的用于生产makefile的配置文件。.pro文件的写法如下：

* 注释

  ​	从“#”开始，到这一行结束。

* 模板变量告诉qmake为这个应用程序生成哪种makefile。下面是可供使用的选择：**TEMPLATE** = app
  *  app -建立一个应用程序的makefile。这是默认值，所以如果模板没有被指定，这个将被使用。
  * lib - 建立一个库的makefile。
  * vcapp - 建立一个应用程序的VisualStudio项目文件。
  * vclib - 建立一个库的VisualStudio项目文件。
  * subdirs -这是一个特殊的模板，它可以创建一个能够进入特定目录并且为一个项目文件生成makefile并且为它调用make的makefile。

* #指定生成的应用程序名： 

  **TARGET** = QtDemo

* #工程中包含的头文件

  **HEADERS** += include/painter.h

* #工程中包含的.ui设计文件

  **FORMS** += forms/painter.ui

* #工程中包含的源文件

  **SOURCES** += sources/main.cpp sources/painter.cpp

* #工程中包含的资源文件

  **RESOURCES** += qrc/painter.qrc

* **greaterThan(QT_MAJOR_VERSION, 4): QT += widgets**

  **这条语句的含义是，如果QT_MAJOR_VERSION大于4（也就是当前使用的Qt5及更高版本）需要增加widgets模块。如果项目仅需支持Qt5，也可以直接添加“QT += widgets”一句。不过为了保持代码兼容，最好还是按照QtCreator生成的语句编写。**

* #配置信息

  CONFIG用来告诉qmake关于应用程序的配置信息。

  CONFIG += c++11  //使用c++11的特性

  在这里使用“+=”，是因为我们添加我们的配置选项到任何一个已经存在中。这样做比使用“=”那样替换已经指定的所有选项更安全。







### 2.3.3命名规范及快捷键

* 命名规范
  * 类名 	首字母大写，单词和单词之间首字母大写
  * 函数名 变量名称 首字母小写，单词和单词之间首字母大写

* 快捷键
  * 注释 	`ctrl +/`
  * 运行   `ctrl+r`
  * 编译  `ctrl+b`
  * 字体缩放 `ctrl+鼠标滚轮`
  * 查找 `ctrl+f`
  * 整行移动  `ctrl+shift+方向键`
  * 帮助文档  `F1`
  * 自动对齐 `ctrl+i`
  * 同名.h文件和.cpp文件切换 `F4`





# 3 第一个小程序

## 3.1  QButton的创建

  ```C++
#include "mywidget.h"
#include<QPushButton>//按钮控件的头文件
#include<QDebug>//用于控制台输出
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)//初始化列表，相关知识点见C++核心4.2.6
{
    //方式1
    //创建一个按钮
    QPushButton *btn=new QPushButton();//不能用局部变量空间太小
    //btn->show();//show是以顶层方式弹出窗口控件
    //让btn对象依赖在myWidget中
    btn->setParent(this);
    //显示文本
    btn->setText("第一个按钮");

    //方式2 按照控件大小来创建窗口
    QPushButton* btn2=new QPushButton("第二个按钮",this);
    //移动btn2按钮
    btn2->move(100,100);//宽 高。坐标原点在左上角
    //按钮重置大小
    btn2->resize(100,100);
    //重置窗口大小--用户对于窗口可拖拽改变大小
    resize(600,400);//宽 高
    //设置固定的窗口大小
    setFixedSize(600,400);
    //设置窗口标题
    setWindowTitle("第一个窗口");


}

myWidget::~myWidget()
{
    qDebug()<<"自动析构";
}

  ```

## 3.2 对象模型（对象树）

* 我的按钮控件  .cpp

```C++
#include "mypushbutton.h"
#include<QDebug>//用于控制台调试
MyPushButton::MyPushButton(QWidget *parent) :
    QPushButton(parent)
{
    qDebug()<<"我的按钮类构造函数";
}

MyPushButton::~MyPushButton(){
    qDebug()<<"我的按钮类析构函数";


}

```

* .h

```C++
  #ifndef MYPUSHBUTTON_H
  #define MYPUSHBUTTON_H
  
  #include<QPushButton>
  class myPushButton : public QPushButton
  {
      Q_OBJECT
  public:
      explicit myPushButton(QWidget *parent = 0);
      ~myPushButton();
  
  signals:
  
  public slots:
  
  };
  
  #endif // MYPUSHBUTTON_H
  
```

* `mywidge.cpp`中添加代码

```C++
//我的按钮控件--测试对象模型自动销毁
    //创建自己的对象
    MyPushButton *myPush=new MyPushButton();
    myPush->setText("我自己的按钮");
    myPush->move(300,0);
    myPush->setParent(this);
```

* 当创建的对象在堆区时，如果指定的父亲是Object类或者其子类派生下来的类，可以不用管理内存的释放，将对象放进对象数中
* 一定程度上简化了回收机制

![image-20230228201344952](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102081.png)

## 3.3Qt窗口坐标系

![image-20230228202618183](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102082.png)





# 4   信号和槽机制

​		信号槽是 Qt 框架引以为豪的机制之一。所谓信号槽，实际就是观察者模式。**当某个事件发生之后**，比如，按钮检测到自己被点击了一下，**它就会发出一个信号（signal）**。这种发出是没有目的的，类似广播。**如果有对象对这个信号感兴趣，它就会使用连接（connect）函数**，意思是，**将想要处理的信号和自己的一个函数（称为槽（slot））绑定来处理这个信号**。也就是说，**当信号发出时，被连接的槽函数会自动被回调**。这就类似观察者模式：当发生了感兴趣的事件，某一个操作就会被自动触发。（这里提一句，Qt 的信号槽使用了额外的处理来实现，并不是 GoF 经典的观察者模式的实现方式。）

## 4.1 信号和槽

* `mywidge.cpp`中添加代码

  ```C++
  //点击按钮关闭窗口
  
      //参数 信号的发送者 发送的信号 信号接收者 处理的槽函数
      //clicked点击时 close操作为关闭窗口
      connect(myPush,&MyPushButton::clicked,this,&myWidget::close);
      connect(myPush,&QPushButton::clicked,this,&myWidget::close);
  ```



* connect()函数最常用的一般形式：

  **connect(sender, signal, receiver, slot);**

* 参数：
  * sender：发出信号的对象
  * signal：发送对象发出的信号
  * receiver：接收信号的对象
  * slot：接收对象在接收到信号之后所需要调用的函数

  ​	**信号槽要求信号和槽的参数一致，所谓一致，是参数类型一致。如果不一致，允许的情况是，槽函数的参数可以比信号的少，即便如此，槽函数存在的那些参数的顺序也必须和信号的前面几个一致起来。这是因为，你可以在槽函数中选择忽略信号传来的数据（也就是槽函数的参数比信号的少），但是不能说信号根本没有这个数据，你就要在槽函数中使用（就是槽函数的参数比信号的多，这是不允许的）。**



## 4.2 自定义信号槽

​	使用connect()可以让我们连接系统提供的信号和槽。但是，Qt 的信号槽机制并不仅仅是使用系统提供的那部分，还会允许我们自己设计自己的信号和槽。

* 案例是学生和老师在上课，下课铃响了老师饿了，学生请老师吃饭

* 老师创建自定义信号饿了`teacher.h`

```C++
#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = 0);

signals:
        //自定义信号写到signals下
        //返回值为void，只需要声明，不需要实现，可以有参数,可以重载
        void  hungry();
public slots:

};

#endif // TEACHER_H

```

* 学生定义槽函数请老师吃饭

```C++
#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = 0);

signals:

public slots:
    //早期槽函数必须写到public slots，Qt5之后高级版本可以写在public或者全局下
    //返回值void 需要声明 也需要实现
    //可以有参数，可以发生重载
    void treat();
};

#endif // STUDENT_H

```

```C++
#include "student.h"
#include<QDebug>
Student::Student(QObject *parent) :
    QObject(parent)
{

}
//槽函数请老师吃饭
void Student::treat()
{
    qDebug()<<"请老师吃饭";
}

```

* 窗口类创建对象`widget.h` `widget.cpp`

```C++
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "teacher.h"
#include "student.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Teacher *t;
    Student *s;

    //下课
   void classIsOver();
};

#endif // WIDGET_H

```

```C++
#include "widget.h"
#include "ui_widget.h"

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
    connect(t,&Teacher::hungry,s,&Student::treat);
    //调用下课函数
    classIsOver();
}
//下课后触发老师饿了信号
void Widget::classIsOver(){
    emit t->hungry();//emit调用
}

Widget::~Widget()
{
    delete ui;
}

```



### 4.2.1 自定义信号的重载

* hungry函数的重载，教师指定要吃什么菜
* 注意相关知识点  函数指针

```C++
  //重载版本
    void hungry(QString foodName);//Qt中使用Qstring表示string
```

```C++
    //重载
    void treat(Qstring foodName);
```

```C++
//重载版本
void Student::treat(QString foodName){
    //qDebug()<<"请老师吃饭，老师要吃"<<foodName;
     //输出的字符串有"
    //将QString ->char*  先转化成QByteArray再转化成char*
    qDebug()<<"请老师吃饭，老师要吃"<<foodName.toUtf8().data();
}

```

```C++
    //连接带参数 信号和槽
    //函数指针指向函数地址
    void (Teacher::*teacherSignal)(QString)=&Teacher::hungry;
    void (Student::*studentSlot)(QString)=&Student::treat;
    connect(t,teacherSignal,s,studentSlot);
    classIsOver();
//下课后触发老师饿了信号
void Widget::classIsOver(){
//    emit t->hungry();//emit调用
    emit t->hungry("宫保鸡丁");
}

```

### 4.2.3 信号连结信号

* 点击下课按钮之后才会触发饿了信号

```C++
    //点击下课按钮之后才触发
    QPushButton *p=new QPushButton("下课",this);
    this->resize(600,400);
    p->move(200,100);
    setWindowTitle("请客吃饭");
    //点击按钮触发槽函数
    connect(p,&QPushButton::clicked,this,&Widget::classIsOver);
```

* 点击按钮信号触发另一个信号

```C++
 //点击信号触发新的信号
    void (Teacher::*teacherSignal2)(void)=&Teacher::hungry;//无参的信号
    void (Student::*studentSlot2)(void)=&Student::treat;//无参槽函数
    connect(t,teacherSignal2,s,studentSlot2);
    //信号连结信号
    connect(p,&QPushButton::clicked,t,teacherSignal2);

```

* 断开信号

```C++
    //断开信号
    disconnect(t,teacherSignal2,s,studentSlot2);
```

### 4.2.4 信号槽的更多用法

* 一个信号可以连接多个槽函数

  如果是这种情况，这些槽会一个接一个的被调用，但是它们的**调用顺序是不确定的**。

* 多个信号可以连接同一个槽函数

  只要任意一个信号发出，这个槽就会被调用。

* 信号可以连接信号

  当第一个信号发出时，第二个信号被发出。除此之外，这种信号-信号的形式和信号-槽的形式没有什么区别。

* 槽可以被取消链接

  这种情况并不经常出现，因为当一个对象delete之后，Qt自动取消所有连接到这个对象上面的槽。

* 信号和槽函数的参数必须一一对应
* 信号和槽函数的参数个数，是不是要一致？
  
  * 信号的参数个数可以多于槽函数的参数个数，但是要按照顺序对应

### 4.2.5 Qt4连接信号和槽

```C++
//Qt4版本连接
    //Qt4信号槽 连接无参版本
    connect(t,SIGNAL(hungry()),s,SLOT(treat()));//无参
    //优点：参数直观 缺点：类型不做检测
    //Qt5支持Qt4的写法
    connect(t,SIGNAL(hungry(QString)),s,SLOT(treat(QString)));//有参
```



### 4.2.6 自定义信号槽需要注意的事项

*  **发送者和接收者都需要是QObject的子类（当然，槽函数是全局函数、Lambda 表达式等无需接收者的时候除外）；**
*  **使用 signals 标记信号函数，信号是一个函数声明，返回 void，不需要实现函数代码；**
*  **槽函数是普通的成员函数，作为成员函数，会受到 public、private、protected 的影响；**
*  **使用 emit 在恰当的位置发送信号；**
*  **使用QObject::connect()函数连接信号和槽。**
*  **任何成员函数、static 函数、全局函数和 Lambda 表达式都可以作为槽函数**

## 4.3 Lambda表达式

C++11中的Lambda表达式**用于定义并创建匿名的函数对象**，以简化编程工作。首先看一下Lambda表达式的基本构成：

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033301.jpg)

**[函数对象参数]** **(操作符重载函数参数)** mutable或exception ->返回值{函数体}

 

① 函数对象参数；

[]，标识一个**Lambda的开始**，这部分必须存在，**不能省略**。函数对象参数是传递给编译器自动生成的函数对象类的构造函数的。函数对象参数只能使用那些到定义Lambda为止时Lambda所在作用范围内可见的局部变量（包括Lambda所在类的this）。函数对象参数有以下形式：

*  空。没有使用任何函数对象参数。

* =。函数体内可以使用Lambda所在作用范围内所有可见的局部变量（包括Lambda所在类的this），并且是**值传递方式**（相当于编译器自动为我们按值传递了所有局部变量）。

* &。函数体内可以使用Lambda所在作用范围内所有可见的局部变量（包括Lambda所在类的this），并且是**引用传递方式**（相当于编译器自动为我们按引用传递了所有局部变量）。

* this。函数体内可以使用Lambda所在类中的成员变量。

* a。将a按值进行传递。按值进行传递时，函数体内不能修改传递进来的a的拷贝，因为默认情况下函数是const的。要修改传递进来的a的拷贝，可以添加mutable修饰符。

* &a。将a按引用进行传递。

* a, &b。将a按值进行传递，b按引用进行传递。

* =，&a, &b。除a和b按引用进行传递外，其他参数都按值进行传递。

* &, a, b。除a和b按值进行传递外，其他参数都按引用进行传递。

```C++
// Lambda表达式
    [=](){
        p->setText("aaaaa");
    }();//不加()是函数声明 加上之后才是函数调用
```



② 操作符重载函数参数；

标识重载的()操作符的参数，没有参数时，这部分可以省略。参数可以通过按值（如：(a,b)）和按引用（如：(&a,&b)）两种方式进行传递。

③ 可修改标示符；

mutable声明，这部分可以省略。按值传递函数对象参数时，加上mutable修饰符后，可以修改按值传递进来的拷贝（注意是能修改拷贝，而不是值本身）。

```C++
 //mutable关键字用于修饰值传递的变量，修改的是拷贝的数据而不是原数据
    QPushButton *myBtn=new QPushButton(this);
    myBtn->setText("myBtn");
    QPushButton *myBtn2=new QPushButton(this);
    myBtn2->setText("myBtn2");
    myBtn2->move(100,150);
    int m=10;
    //此处代码报错要再pro文件中添加 CONFIG+=c++11
    connect(myBtn,&QPushButton::clicked,this,[m]()mutable{m=10+100;qDebug()<<m;});
    connect(myBtn2,&QPushButton::clicked,this,[=](){qDebug()<<m;});
    qDebug()<<m;
```



④ 错误抛出标示符；

exception声明，这部分也可以省略。exception声明用于指定函数抛出的异常，如抛出整数类型的异常，可以使用throw(int)

⑤ 函数返回值；

->返回值类型，标识函数返回值的类型，当返回值为void，或者函数体中只有一处return的地方（此时编译器可以自动推断出返回值类型）时，这部分可以省略。

```C++
    int ret=[]()->int{return 1000;}();
    qDebug()<<"ret="<<ret;
```



⑥ 是函数体；

  {}，标识函数的实现，这部分不能省略，但函数体可以为空。



```C++
     //利用lambda表达式实现点击按钮 关闭窗口
    QPushButton *btn=new QPushButton(this);
    btn->setText("关闭");
    btn->setParent(this);
    connect(btn,&QPushButton::clicked,this,[=](){
        this->close();//关闭窗口
//      emit t->hungry("宫保鸡丁");//可以添加类似的语句
        s->treat("w1w1");
    });
```



## 4.4 总结

* 利用一个按钮实现在页面中开关另一个页面

```C++
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
```









# 5 Qt窗口系统

## 5.1 Qt窗口坐标体系

### 坐标体系

以左上角为原点，X向右增加，Y向下增加。

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033302.jpg)

对于嵌套窗口，其坐标是**相对于父窗口**来说的。

## 5.2 QWidget

所有窗口及窗口控件都是从QWidget直接或间接派生出来的。

### 5.2.1 对象模型

在Qt中创建对象的时候会提供一个Parent对象指针，下面来解释这个parent到底是干什么的。

*  QObject是以对象树的形式组织起来的。

*  当你创建一个QObject对象时，会看到QObject的构造函数接收一个QObject指针作为参数，这个参数就是 parent，也就是父对象指针。

这相当于，**在创建QObject对象时，可以提供一个其父对象，我们创建的这个QObject对象会自动添加到其父对象的children()列表。**

* **当父对象析构的时候，这个列表中的所有对象也会被析构。（注意，这里的父对象并不是继承意义上的父类！）**

这种机制在 GUI 程序设计中相当有用。例如，一个按钮有一个QShortcut（快捷键）对象作为其子对象。当我们删除按钮的时候，这个快捷键理应被删除。这是合理的。

* QWidget是能够在屏幕上显示的一切组件的父类。

  * **QWidget****继承自QObject，因此也继承了这种对象树关系。一个孩子自动地成为父组件的一个子组件**。因此，它会显示在父组件的坐标系统中，被父组件的边界剪裁。例如，当用户关闭一个对话框的时候，应用程序将其删除，那么，我们希望属于这个对话框的按钮、图标等应该一起被删除。事实就是如此，因为这些都是对话框的子组件。

  * 当然，**我们也可以自己删除子对象，它们会自动从其父对象列表中删除。**比如，当我们删除了一个工具栏时，其所在的主窗口会自动将该工具栏从其子对象列表中删除，并且自动调整屏幕显示。

Qt 引入对象树的概念，在一定程度上解决了内存问题。

*  当一个QObject对象在堆上创建的时候，Qt 会同时为其创建一个对象树。不过，对象树中对象的顺序是没有定义的。这意味着，销毁这些对象的顺序也是未定义的。

*  任何对象树中的 QObject对象 delete 的时候，如果这个对象有 parent，则自动将其从 parent 的children()列表中删除；如果有孩子，则自动 delete 每一个孩子。Qt 保证没有QObject会被 delete 两次，这是由析构顺序决定的。

如果QObject在栈上创建，Qt 保持同样的行为。正常情况下，这也不会发生什么问题。来看下下面的代码片段：

{

  QWidget window;

  QPushButton quit("Quit", &window);

}

作为父组件的 window 和作为子组件的 quit 都是QObject的子类（事实上，它们都是QWidget的子类，而QWidget是QObject的子类）。这段代码是正确的，quit 的析构函数不会被调用两次，因为标准 C++要求，**局部对象的析构顺序应该按照其创建顺序的相反过程**。因此，这段代码在超出作用域时，会先调用 quit 的析构函数，将其从父对象 window 的子对象列表中删除，然后才会再调用 window 的析构函数。

但是，如果我们使用下面的代码：

{

  QPushButton quit("Quit");

  QWidget window;

  quit.setParent(&window);

}

情况又有所不同，析构顺序就有了问题。我们看到，在上面的代码中，作为父对象的 window 会首先被析构，因为它是最后一个创建的对象。在析构过程中，它会调用子对象列表中每一个对象的析构函数，也就是说， quit 此时就被析构了。然后，代码继续执行，在 window 析构之后，quit 也会被析构，因为 quit 也是一个局部变量，在超出作用域的时候当然也需要析构。但是，这时候已经是第二次调用 quit 的析构函数了，C++ 不允许调用两次析构函数，因此，程序崩溃了。

由此我们看到，Qt 的对象树机制虽然帮助我们在一定程度上解决了内存问题，但是也引入了一些值得注意的事情。这些细节在今后的开发过程中很可能时不时跳出来烦扰一下，所以，我们最好从开始就养成良好习惯，在 Qt 中，尽量在构造的时候就指定 parent 对象，并且大胆在堆上创建。

## 5.3 QMainWindow

QMainWindow是一个为用户提供主窗口程序的类，包含一个菜单栏（menu bar）、多个工具栏(tool bars)、多个锚接部件(dock widgets)、一个状态栏(status bar)及一个中心部件(central widget)，是许多应用程序的基础，如文本编辑器，图片编辑器等。

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033303.gif)

### 5.3.1 菜单栏

一个主窗口最多只有一个菜单栏。位于主窗口顶部、主窗口标题栏下面。

```C++
#include "mainwindow.h"
#include<QMenuBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    resize(600,400);

    //在程序中，菜单栏最多只能有一个
    //菜单栏创建
    QMenuBar *bar=menuBar();
    //将菜单栏放入到窗口中 //只有一个的用set有多个的用add
    setMenuBar(bar);

    // 创建菜单
   QMenu *fileMenu= bar->addMenu("文件");
   QMenu *editMenu= bar->addMenu("编辑");
   QMenu *toolMenu= bar->addMenu("工具");
   //创建菜单项
   fileMenu->addAction("新建");
   //添加分隔线
   fileMenu->addSeparator();
   fileMenu->addAction("打开");
}

MainWindow::~MainWindow()
{

}

```



### 5.3.2 工具栏

主窗口的工具栏上可以有多个工具条，通常采用一个菜单对应一个工具条的的方式，也可根据需要进行工具条的划分。

* 直接调用QMainWindow类的addToolBar（）函数获取主窗口的工具条对象，每增加一个工具条都需要调用一次该函数。

* 插入属于工具条的动作，即在工具条上添加操作。

通过QToolBar类的addAction函数添加。

* 工具条是一个可移动的窗口，它的停靠区域由QToolBar的allowAreas决定，包括：
  * Qt::LeftToolBarArea   停靠在左侧

  * Qt::RightToolBarArea   停靠在右侧

  *  	 Qt::TopToolBarArea    停靠在顶部
  
  *  Qt::BottomToolBarArea   停靠在底部
  
  *  Qt::AllToolBarAreas   以上四个位置都可停靠

**使用setAllowedAreas（）函数指定停靠区域：**

setAllowedAreas（Qt::LeftToolBarArea | Qt::RightToolBarArea）

**使用setMoveable（）函数设定工具栏的可移动性：**

​	setMoveable（false）//工具条不可移动, 只能停靠在初始化的位置上

```C++
//工具栏 可以有多个 注意包含头文件QToolBar
   QToolBar *toolBar=new QToolBar(this);
   //添加工具栏  同时可以设置设置工具栏默认位置
//   addToolBar(toolBar);
   addToolBar(Qt::LeftToolBarArea,toolBar);
    //只允许左右停靠
   toolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);
   //设置浮动
   toolBar->setFloatable(false);
   //设置移动--总开关
   toolBar->setMovable(false);

   //工具栏设置内容
    toolBar->addAction(newAction);
    toolBar->addSeparator();//添加分割线
    toolBar->addAction(fileAction);
    //添加控件
    QPushButton *btn =new QPushButton("aa",this);
    toolBar->addWidget(btn);
```



### 5.3.3 状态栏

*  派生自QWidget类，使用方法与QWidget类似，QStatusBar类常用成员函数：

//添加小部件

void addWidget(QWidget * widget, int stretch = 0)

//插入小部件

int insertWidget(int index, QWidget * widget, int stretch = 0)

//删除小部件

void removeWidget(QWidget * widget)

```C++
//状态栏 最多只能有一个 注意添加头文件
   QStatusBar *stBar=  statusBar();
   //设置到窗口中
   setStatusBar(stBar);
   //放标签控件  注意添加头文件
   QLabel *label=new QLabel("提示信息",this);
   stBar->addWidget(label);
   QLabel *label2=new QLabel("提示信息右侧",this);
   stBar->addPermanentWidget(label2);

   //铆接部件（浮动窗口）可以有多个
   QDockWidget *dockWidget=new QDockWidget("浮动窗口",this);
   addDockWidget(Qt::BottomDockWidgetArea,dockWidget);//设置浮动位置--下面
   //设置后期停靠区域 只允许上下
   dockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);

   //设置中心位置 只能有一个
   QTextEdit *edit=new QTextEdit(this);
   setCentralWidget(edit);//设置核心
```



## 5.4 资源文件

### 5.4.1基本布局设计

* 菜单栏编辑

  ![image-20230306115233591](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102083.png)

  

  * 菜单菜单项不能用中文

    * 因为在创建菜单项XX时自动创建对应action XX类
    * 修改显示可以在下方的text属性值设置显示内容

    ![image-20230306115344295](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102084.png)

    

  * 右键菜单项可以添加分隔符

    ![image-20230306115824986](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102085.png)

    

  * 默认提供一个工具栏，一个状态栏

    ![image-20230306120010527](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102086.png)

  

  * 可以使用拖拽的方式将工具栏与菜单项绑定

    ![image-20230306120225672](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102088.png)

    

  * 铆接部件也可以拖拽创建

    * 通过右侧`QdockWidgrt`
    * 属性设置停靠范围
      ![image-20230306120639700](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102089.png)

### 5.4.2 代码添加菜单项图标

* 绝对路径方式（不推荐）

```C++
//可以通过ui找到ui文件中所有的控件
    //设置新建的图标资源--注意路径中不要有中文 --绝对路径方式
    ui->actionNew->setIcon(QIcon("C:/Users/yangc/Desktop/image/4.jpg"));
```

* 相对路径方式
  * 首先将所需文件拖拽到项目文件下

  * 其次按照`5.4.3`步骤创建资源文件

  * 之后设置图片

      ```C++
        //使用Qt资源：":+前缀名+文件名"
    ui->actionNew->setIcon(QIcon(":/image/1.jpg"));
        ui->actionOpen->setIcon(QIcon(":/image/2.jpg"));
    ```
    
    

### 5.4.3 添加资源

Qt 资源系统是一个跨平台的资源机制，用于将程序运行时所需要的资源以二进制的形式存储于可执行文件内部。如果你的程序需要加载特定的资源（图标、文本翻译等），那么，将其放置在资源文件中，就再也不需要担心这些文件的丢失。也就是说，如果你将资源以资源文件形式存储，它是会编译到可执行文件内部。

使用 Qt Creator 可以很方便地创建资源文件。我们可以在工程上点右键，选择“添加新文件…”，可以在 Qt 分类下找到“Qt 资源文件”：

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033304.jpg)

点击“选择…”按钮，打开“新建 Qt 资源文件”对话框。在这里我们输入资源文件的名字和路径：

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033305.gif)

点击下一步，选择所需要的版本控制系统，然后直接选择完成。我们可以在 Qt Creator 的左侧文件列表中看到“资源文件”一项，也就是我们新创建的资源文件：

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033306.gif)

右侧的编辑区有个“添加”，我们首先需要添加前缀，比如我们将前缀取名为 images。然后选中这个前缀，继续点击添加文件，可以找到我们所需添加的文件。这里，我们选择 document-open.png 文件。当我们完成操作之后，Qt Creator 应该是这样子的：

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033306.gif)

接下来，我们还可以添加另外的前缀或者另外的文件。这取决于你的需要。当我们添加完成之后，我们可以像前面一章讲解的那样，通过使用 : 开头的路径来找到这个文件。比如，我们的前缀是 /images，文件是 document-open.png，那么就可以使用:/images/document-open.png找到这个文件。

这么做带来的一个问题是，如果以后我们要更改文件名，比如将 docuemnt-open.png 改成 docopen.png，那么，所有使用了这个名字的路径都需要修改。所以，更好的办法是，我们给这个文件去一个“别名”，以后就以这个别名来引用这个文件。具体做法是，选中这个文件，添加别名信息：

![img](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302281033307.gif)

这样，我们可以直接使用:/images/doc-open引用到这个资源，无需关心图片的真实文件名。

如果我们使用文本编辑器打开 res.qrc 文件，就会看到一下内容： 

```C++
<RCC>

    <qresource prefix="/images">

      <file alias="doc-open">document-open.png</file>

    </qresource>

    <qresource prefix="/images/fr" lang="fr">

      <file alias="doc-open">document-open-fr.png</file>

    </qresource>

</RCC>
```

我们可以对比一下，看看 Qt Creator 帮我们生成的是怎样的 qrc 文件。当我们编译工程之后，我们可以在构建目录中找到 qrc_res.cpp 文件，这就是 Qt 将我们的资源编译成了 C++ 代码。


## 5.5 对话框QDialog

### 5.5.1 基本概念

​	对话框是 GUI 程序中不可或缺的组成部分。很多不能或者不适合放入主窗口的功能组件都必须放在对话框中设置。对话框通常会是一个顶层窗口，出现在程序最上层，用于实现短期任务或者简洁的用户交互。

​	Qt 中使用QDialog类实现对话框。就像主窗口一样，我们通常会设计一个类继承QDialog。QDialog（及其子类，以及所有Qt::Dialog类型的类）的对于其 parent 指针都有额外的解释：**如果 parent 为 NULL，则该对话框会作为一个顶层窗口，否则则作为其父组件的子对话框（此时，其默认出现的位置是 parent 的中心）。顶层窗口与非顶层窗口的区别在于，顶层窗口在任务栏会有自己的位置，而非顶层窗口则会共享其父组件的位置。**

**对话框分为模态对话框和非模态对话框。**

* 模态对话框，就是会阻塞同一应用程序中其它窗口的输入。

  模态对话框很常见，比如“打开文件”功能。你可以尝试一下记事本的打开文件，当打开文件对话框出现时，我们是不能对除此对话框之外的窗口部分进行操作的。

* 与此相反的是非模态对话框，例如查找对话框，我们可以在显示着查找对话框的同时，继续对记事本的内容进行编辑。

### 5.5.2 自定义消息框

​	Qt 支持模态对话框和非模态对话框。

​	模态与非模态的实现：

*  使用QDialog::exec()实现应用程序级别的模态对话框

*  使用QDialog::open()实现窗口级别的模态对话框

*  使用QDialog::show()实现非模态对话框。

#### 模态对话框

*  Qt 有两种级别的模态对话框：

* 应用程序级别的模态

  当该种模态的对话框出现时，用户必须首先对对话框进行交互，直到关闭对话框，然后才能访问程序中其他的窗口。

* 窗口级别的模态

  该模态仅仅阻塞与对话框关联的窗口，但是依然允许用户与程序中其它窗口交互。窗口级别的模态尤其适用于多窗口模式。

一般默认是应用程序级别的模态。

​	在下面的示例中，我们调用了exec()将对话框显示出来，因此这就是一个模态对话框。当对话框出现时，我们不能与主窗口进行任何交互，直到我们关闭了该对话框。

```C++
void MainWindow::open()

{

    QDialog dialog;

   dialog.setWindowTitle(tr("Hello, dialog!"));

dialog.exec();

}
```



#### 非模态对话框

下面我们试着将exec()修改为show()，看看非模态对话框：

```C++
void MainWindow::open()

{

  QDialog dialog(this);

  dialog.setWindowTitle(tr("Hello, dialog!"));

  dialog.show();

}
```

​	是不是事与愿违？对话框竟然一闪而过！这是因为，**show()函数不会阻塞当前线程，对话框会显示出来，然后函数立即返回，代码继续执行。**注意，dialog 是建立在栈上的，show()函数返回，MainWindow::open()函数结束，dialog 超出作用域被析构，因此对话框消失了。知道了原因就好改了，我们将 dialog 改成堆上建立，当然就没有这个问题了：

```C++
void MainWindow::open()

{

  QDialog *dialog = new QDialog;

  dialog->setWindowTitle(tr("Hello, dialog!"));

  dialog->show();

}
```

​	你足够细心，应该发现上面的代码是有问题的：dialog 存在内存泄露！dialog 使用 new 在堆上分配空间，却一直没有 delete。解决方案也很简单：将 MainWindow 的指针赋给 dialog 即可。还记得我们前面说过的 Qt 的对象系统吗？

​	不过，这样做有一个问题：如果我们的对话框不是在一个界面类中出现呢？由于QWidget的 parent 必须是QWidget指针，那就限制了我们不能将一个普通的 C++ 类指针传给 Qt 对话框。另外，如果对内存占用有严格限制的话，当我们将主窗口作为 parent 时，主窗口不关闭，对话框就不会被销毁，所以会一直占用内存。在这种情景下，我们可以设置 dialog 的WindowAttribute：

```C++
void MainWindow::open()

{

  QDialog *dialog = new QDialog;

  **dialog->setAttribute(Qt::WA_DeleteOnClose);**

  dialog->setWindowTitle(tr("Hello, dialog!"));

  dialog->show();

}
```

**setAttribute()**: 函数设置对话框关闭时，自动销毁对话框。

* 个人代码-对话框

```C++
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>//对话框
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //点击新建按钮弹出对话框
    connect(ui->actionNew,&QAction::triggered,[=]{//当前版本下注意添加 CONFIG+=c++11
        //对话框两种分类
        //非模态对话框（可以对其他窗口进行操作）模态（不可以对其他窗口进行操作）

        //模态方式创建
//        QDialog dlg(this);
//        dlg.exec();//模态方式创建
//        dlg.resize(200,100);
//        qDebug()<<"模态对话框信息";//不会显示，因为模态方式创建阻塞后面的代码

        //非模态方式创建
//        QDialog dlg2(this);//使用这种方式创建后show()函数不阻塞，对话框显示，但是函数会立即返回代码继续执行
        QDialog *dlg2 =new QDialog(this);
        dlg2->resize(200,100);
        dlg2-> show();
        //如果一直点击新建取消但不停止窗口，一直新建对象，可能会导致内存泄漏
        dlg2->setAttribute(Qt::WA_DeleteOnClose);//关闭窗口时删除属性
        qDebug()<<"非模态对话框信息";

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

```

### 5.5.3 标准对话框

​	所谓标准对话框，是 Qt 内置的一系列对话框，用于简化开发。事实上，有很多对话框都是通用的，比如打开文件、设置颜色、打印设置等。这些对话框在所有程序中几乎相同，因此没有必要在每一个程序中都自己实现这么一个对话框。

Qt 的内置对话框大致分为以下几类：

* QColorDialog：    选择颜色；

  ```C++
          //颜色对话框
          QColor color=QColorDialog::getColor(QColor(255,0,0));
          qDebug()<<color.red()<<" "<<color.blue()<<" "<<color.green();
  ```

  

  ![image-20230306173854996](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102090.png)

* QFileDialog：    选择文件或者目录；

  

  

  ![image-20230306211518272](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102091.png)

  ```C++
             //文件对话框 打开文件 父类 操作名 默认路径 过滤文件格式
            QString str=QFileDialog::getOpenFileName(this,"打开","C:\\Users\\yangc\\Desktop\\image","*.jpg");
            qDebug()<<str;//如果取消返回空字符串，选中文件返回文件路径
  ```

  

* QFontDialog：    选择字体；

  ![image-20230306213541095](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102092.png)

```C++
 //字体对话框
        bool flag;
        //打开字体 标志  默认字体及字体大小
       QFont qFont=QFontDialog::getFont(&flag,QFont("华文彩云",36));
       qDebug()<<"字体："<<qFont.family().toUtf8().data()//string类型转化为char*
              <<"字号："<<qFont.pointSize()
             <<"加粗："<<qFont.bold()
               <<"斜体："<<qFont.italic();
```



*  QInputDialog：    允许用户输入一个值，并将其值返回；
*  QMessageBox：    模态对话框，用于显示信息、询问问题等；
*  QPageSetupDialog：  为打印机提供纸张相关的选项；
*  QPrintDialog：    打印机配置；
*  QPrintPreviewDialog：打印预览；
*  QProgressDialog：  显示操作过程。

**整体代码与`5.5.4`消息对话框的放在一起**



### 5.5.4 消息对话框

QMessageBox用于显示消息提示。我们一般会使用其提供的几个 static 函数：

* 显示关于对话框。

  void about(QWidget * parent, const QString & title, const QString & text)

  这是一个最简单的对话框，其标题是 title，内容是 text，父窗口是 parent。对话框只有一个 OK 按钮。

* 显示关于 Qt 对话框。该对话框用于显示有关 Qt 的信息。

  void aboutQt(QWidget * parent, const QString & title = QString())： 

* 显示严重错误对话框。

  StandardButton critical(QWidget * parent, const QString & title, const QString & text, StandardButtons buttons = Ok,StandardButton defaultButton = NoButton)：

  这个对话框将显示一个红色的错误符号。我们可以通过 buttons 参数指明其显示的按钮。默认情况下只有一个 Ok 按钮，我们可以使用StandardButtons类型指定多种按钮。

* 与QMessageBox::critical()类似，不同之处在于这个对话框提供一个普通信息图标。

  StandardButton information(QWidget * parent, const QString & title, const QString & text, StandardButtons buttons = Ok,StandardButton defaultButton = NoButton)

* 与QMessageBox::critical()类似，不同之处在于这个对话框提供一个问号图标，并且其显示的按钮是“是”和“否”。

  StandardButton question(QWidget * parent,const QString & title, const QString & text, StandardButtons buttons = StandardButtons( Yes | No ), StandardButton defaultButton = NoButton) 

* 与QMessageBox::critical()类似，不同之处在于这个对话框提供一个黄色叹号图标。

  StandardButton warning(QWidget * parent, const QString & title, const QString & text, StandardButtons buttons = Ok,StandardButton defaultButton = NoButton)



```C++
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>//对话框
#include<QDebug>
#include<QMessageBox>//消息对话框
#include<QColorDialog>//颜色对话框
#include<QFileDialog>//文件对话框
#include<QFontDialog>//字体对话框

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //自定义对话框
    //点击新建按钮弹出对话框
    connect(ui->actionNew,&QAction::triggered,[=]{//当前版本下注意添加 CONFIG+=c++11
        //对话框两种分类
        //非模态对话框（可以对其他窗口进行操作）模态（不可以对其他窗口进行操作）

        //模态方式创建
//        QDialog dlg(this);
//        dlg.exec();//模态方式创建
//        dlg.resize(200,100);
//        qDebug()<<"模态对话框信息";//不会显示，因为模态方式创建阻塞后面的代码

        //非模态方式创建
//        QDialog dlg2(this);//使用这种方式创建后show()函数不阻塞，对话框显示，但是函数会立即返回代码继续执行
//        QDialog *dlg2 =new QDialog(this);
//        dlg2->resize(200,100);
//        dlg2-> show();
//        //如果一直点击新建取消但不停止窗口，一直新建对象，可能会导致内存泄漏
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);//关闭窗口时删除属性
//        qDebug()<<"非模态对话框信息";


        //消息对话框
        //错误对话框
//        QMessageBox::critical(this,"critical","错误消息");

        //消息对话框
//        QMessageBox::information(this,"information","消息提示");

        //提问对话框 父类 标题 内容 选项 默认关联值
//        QMessageBox::question(this,"question","提问对话框",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel);
        //判定用户选择的选项
//        if(QMessageBox::Save==QMessageBox::question(this,"question","提问对话框",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel)){
//            qDebug()<<"选择的是save";
//        }else{
//            qDebug()<<"选择的是cancel";
//        }

        //警告对话框
//        QMessageBox::warning(this,"warning","警告信息");

//        //颜色对话框
//        QColor color=QColorDialog::getColor(QColor(255,0,0));
//        qDebug()<<color.red()<<" "<<color.blue()<<" "<<color.green();

//        //文件对话框 打开文件 父类 操作名 默认路径 过滤文件格式
//        QString str=QFileDialog::getOpenFileName(this,"打开","C:\\Users\\yangc\\Desktop\\image","*.jpg");
//        qDebug()<<str;//如果取消返回空字符串，选中文件返回文件路径

        //字体对话框
        bool flag;
        //打开字体 标志  默认字体及字体大小
       QFont qFont=QFontDialog::getFont(&flag,QFont("华文彩云",36));
       qDebug()<<"字体："<<qFont.family().toUtf8().data()//string类型转化为char*
              <<"字号："<<qFont.pointSize()
             <<"加粗："<<qFont.bold()
               <<"斜体："<<qFont.italic();


    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

```



### 视频未涉及--标准文件对话框

​	QFileDialog，也就是文件对话框。在本节中，我们将尝试编写一个简单的文本文件编辑器，我们将使用QFileDialog来打开一个文本文件，并将修改过的文件保存到硬盘。

​	首先，我们需要创建一个带有文本编辑功能的窗口。借用我们前面的程序代码，应该可以很方便地完成：

```C++
openAction = new QAction(QIcon(":/images/file-open"),

 tr("&Open..."), this);

openAction->setShortcuts(QKeySequence::Open);

openAction->setStatusTip(tr("Open an existing file"));

saveAction = new QAction(QIcon(":/images/file-save"), 

tr("&Save..."), this);

saveAction->setShortcuts(QKeySequence::Save);

saveAction->setStatusTip(tr("Save a new file"));

QMenu *file = menuBar()->addMenu(tr("&File"));

file->addAction(openAction);

file->addAction(saveAction);
QToolBar *toolBar = addToolBar(tr("&File"));

toolBar->addAction(openAction);

toolBar->addAction(saveAction);

textEdit = new QTextEdit(this);

setCentralWidget(textEdit);
```

​	我们在菜单和工具栏添加了两个动作：打开和保存。接下来是一个QTextEdit类，这个类用于显示富文本文件。也就是说，它不仅仅用于显示文本，还可以显示图片、表格等等。不过，我们现在只用它显示纯文本文件。QMainWindow有一个setCentralWidget()函数，可以将一个组件作为窗口的中心组件，放在窗口中央显示区。显然，在一个文本编辑器中，文本编辑区就是这个中心组件，因此我们将QTextEdit作为这种组件。

​	我们使用connect()函数，为这两个QAction对象添加响应的动作：

```c++
connect(openAction, &QAction::triggered, 

this, &MainWindow::openFile);

connect(saveAction, &QAction::triggered, 

this, &MainWindow::saveFile);
```

下面是最主要的openFile()和saveFile()这两个函数的代码：

```C++
//打开文件

void MainWindow::openFile()

{

  QString path = QFileDialog::getOpenFileName(this,

        tr("Open File"), ".", tr("Text Files(*.txt)"));

  if(!path.isEmpty()) 

{

    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) 

{

      QMessageBox::warning(this, tr("Read File"),

             tr("Cannot open file:\n%1").arg(path));

      return;

    }

    QTextStream in(&file);

    textEdit->setText(in.readAll());

    file.close();

  } 

else 

{

    QMessageBox::warning(this, tr("Path"),

               tr("You did not select any file."));

   }

}

 

//保存文件

void MainWindow::saveFile()

{

  QString path = QFileDialog::getSaveFileName(this,

        tr("Open File"), ".", tr("Text Files(*.txt)"));

  if(!path.isEmpty()) 

{

    QFile file(path);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) 

{

      QMessageBox::warning(this, tr("Write File"),

             tr("Cannot open file:\n%1").arg(path));

      return;

    }

    QTextStream out(&file);

    out << textEdit->toPlainText();

    file.close();

  } 

else 

{

   QMessageBox::warning(this, tr("Path"),

              tr("You did not select any file."));

  }

}C++
```

​	在openFile()函数中，我们使用QFileDialog::getOpenFileName()来获取需要打开的文件的路径。这个函数原型如下：

​	QString getOpenFileName(QWidget * parent = 0,const QString & caption = QString(),const QString & dir = QString(),const QString & filter = QString(),QString * selectedFilter = 0,Options options = 0)

不过注意，它的所有参数都是可选的，因此在一定程度上说，这个函数也是简单的。这六个参数分别是：

*  parent：父窗口。

Qt 的标准对话框提供静态函数，用于返回一个模态对话框；

*  caption：对话框标题；

*  dir：对话框打开时的默认目录

*  “.” 代表程序运行目录

*  “/” 代表当前盘符的根目录（特指 Windows 平台；Linux 平台当然就是根目录），这个参数也可以是平台相关的，比如“C:\\”等；

*  filter：过滤器。

  我们使用文件对话框可以浏览很多类型的文件，但是，很多时候我们仅希望打开特定类型的文件。比如，文本编辑器希望打开文本文件，图片浏览器希望打开图片文件。**过滤器就是用于过滤特定的后缀名**。如果我们使用“Image Files(*.jpg *.png)”，则只能显示后缀名是 jpg 或者 png 的文件。**如果需要多个过滤器，使用“;;”分割**，比如“JPEG Files(*.jpg);;PNG Files(*.png)”；

*  selectedFilter：默认选择的过滤器；

* options：对话框的一些参数设定

  比如只显示文件夹等等，它的取值是enum QFileDialog::Option，每个选项可以使用 | 运算组合起来。

**QFileDialog::getOpenFileName()****返回值是选择的文件路径。**我们将其赋值给 path。通过判断 path 是否为空，可以确定用户是否选择了某一文件。只有当用户选择了一个文件时，我们才执行下面的操作。

   在saveFile()中使用的QFileDialog::getSaveFileName()也是类似的。使用这种静态函数，在 Windows、Mac OS 上面都是直接调用本地对话框，但是 Linux 上则是QFileDialog自己的模拟。这暗示了，如果你不使用这些静态函数，而是直接使用QFileDialog进行设置，那么得到的对话框很可能与系统对话框的外观不一致。这一点是需要注意的。



## 5.6 登录窗口布局

* 对应项目 5_7_1_layout

### 5.6.1基本实现登录窗口

* 用户名使用标签Label
* 信息输入使用Line Edit
* 密码同上
* 按钮使用Push Button

![image-20230306220110005](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102093.png)

但是此种情况下运行程序所有部件都在固定位置，因此需要布局

### 5.6.2 布局

* 使用widgret绑定Label和Line Edit 然后把使用水平布局

* 同样的操作重复

* 最后整体垂直布局（下图是外部再次添加窗口的垂直布局，之后是直接窗口的整体垂直布局）

  ![image-20230306220918832](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102094.png)

  ![image-20230306222452963](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102095.png)

* 在直接窗口整体布局的情况下，使用Spaces调节水平和垂直布局

  * 可以设置为Z自动，也可以设置为固定值

    ![image-20230306222851184](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102096.png)

*  调整各个widget为固定大小（同上）

* 调整每行垂直间距（同上）

* 使用属性修改标题

* 设置固定大小

  * 通过设置最大宽高最小宽高为指定值固定大小

* 觉得窗口间隙不合适可以调节

  ![image-20230306224912226](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102097.png)

* 设置密码为不可见 修改为password

  * No Echo是不可见

  * PassowrdEchoOnEdit是编辑账号时密码不可见

    ![image-20230306225244858](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102098.png)

## 5.7 常用控件

​	Qt为我们应用程序界面开发提供的一系列的控件，下面我们介绍两种最常用的两种，所有控件的使用方法我们都可以通过帮助文档获取。

* 对应5_7_QControl	

### 5.7.1 按钮组

* Push Button

* Tool Button

  * 显示图片

    * 注意，在添加资源之后要先点击构建资源才能正确的显示
    * 可以选择只显示图片或者显示图片和文字
    * autoRaise：鼠标悬浮后浮起图标
    * 添加图片返回按钮可以取消选中图片

    ![image-20230309222501418](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102099.png)

    ![image-20230309222916876](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102533.png)

    
    
  * Radio Button

    * 显示圆角符号，一般用于单选按钮

    * 相同属性放进Group Box容器中

    * 实现默认勾选

      * ui界面方式：将对应属性的checked勾上

      * 代码方式:

        ```C++
        ui->rBtnMan->setChecked(true);//rBtnMan为对应单选按钮的类
        ```

    * 实现监控用户勾选

      ```
          //选中女后 打印信息
          connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){//注意包含lambda表达式
              qDebug()<<"选中了女";
          });
      ```

  * Check Button

    * 多选按钮

      ```C++
          //多选按钮 选中变化 2选中 1是半选（可以理解为子项目没有选完） 0未选中
          connect(ui->checkBox_3,&QCheckBox::stateChanged,[=](int state){
              qDebug()<<state;
          });
      ```

  * Command Link Button

    * 连接按钮

  * Dialog Button Box 

    * 选中 取消按钮组合，等价于两个普通按钮

### 5.7.2 TreeWidget

* 用于创建树形菜单

* 对应项目5_7_2_QTreeWidget
* 创建widget项目
* 添加TreeWidget控件
* 添加水平头
  * `setHeaderlabels`
  * 使用`QStringList()`匿名函数对象拼接
* 添加顶层节点
* 追加子节点

```C++
#include "widget.h"
#include "ui_widget.h"
#include<QTreeWidget>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //treeWidget

    //设置水平头
    ui->treeWidget
            ->setHeaderLabels(QStringList()<<"英雄"<<"英雄简介");//匿名对象的使用

    //添加顶层节点
    QTreeWidgetItem *liItem=new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem *minItem=new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem *zhiItem=new QTreeWidgetItem(QStringList()<<"智力");
    //加载顶层节点
    ui->treeWidget->addTopLevelItem(liItem);
    ui->treeWidget->addTopLevelItem(minItem);
    ui->treeWidget->addTopLevelItem(zhiItem);

    //追加子节点
    QStringList heroL1;
    heroL1<<"纳兰容若"<<"字性德，天才诗人";
    QTreeWidgetItem *l1=new QTreeWidgetItem(heroL1);
    liItem->addChild(l1);
    QStringList heroL2;
    heroL2<<"仓央嘉措"<<"26代达赖喇叭 转世灵童";
    QTreeWidgetItem *l2=new QTreeWidgetItem(heroL2);
    liItem->addChild(l2);
    QStringList heroM1;
    heroM1<<"东方不败"<<"红颜薄命 ";
    QTreeWidgetItem *M1=new QTreeWidgetItem(heroM1);
    minItem->addChild(M1);

}

Widget::~Widget()
{
    delete ui;
}

```

### 5.7.3 TableWidget

* 用于创建表格

* 对应5_7_3_QTableWidget

* 创建widget项目

* 添加`tableWidget`控件

  ```C++
  #include "widget.h"
  #include "ui_widget.h"
  #include<QTableWidget>
  Widget::Widget(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::Widget)
  {
      ui->setupUi(this);
      //TableWidget控件
  
      //设置列数
      ui->tableWidget->setColumnCount(3);
      //设置水平表头
      ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");
      //设置行数
      ui->tableWidget->setRowCount(5);
      //设置正文
  //    ui->tableWidget->setItem(0,0,new QTableWidgetItem("亚瑟"));
      //姓名
      QStringList nameList;
      nameList<<"亚瑟"<<"赵云"<<"妲己"<<"杨玉环"<<"嵇康";
  //性别
      QList<QString> sexList;
      sexList<<"男"<<"男"<<"女"<<"女"<<"男";
  
  
      for(int i=0;i<5;i++){
          int j=0;
          ui->tableWidget->setItem(i,j++,new QTableWidgetItem(nameList[i]));
          ui->tableWidget->setItem(i,j++,new QTableWidgetItem(sexList[i]));
          //int 转QString
          ui->tableWidget->setItem(i,j++,new QTableWidgetItem(QString::number(i+15)));
      }
  
  
  }
  
  Widget::~Widget()
  {
      delete ui;
  }
  
  ```






### 5.7.4 其他控件

#### Scroll Area

* 滚动栏

#### Tool Box

* currentItemText用于修改显示名称
* 右键当前对象可以添加页
* 在每个页面下可以放入不同的控件

#### Tab Widget

* 网页
* currentTabText用于修改显示名称 
* 右键当前对象可以添加页

#### Stacked Widget

* 可以在内部放置其他容器 可以在放置的容器间自由切换

  * 这种切换需要外部按钮来实现

    ```C++
     //设置默认定位
    ui->stackedWidget->setCurrentIndex(0);//设置当前索引值    
    //按钮1
        connect(ui->stacked1,&QPushButton::clicked,[=](){//CONFIG+=c++11
            ui->stackedWidget->setCurrentIndex(0);//设置当前索引值
    
        });
    ```

#### Combo Box

* 下拉框
* 也可以点击按钮选中指定下拉框

```C++
    //下拉框
    ui->comboBox->addItem("皮卡");
    ui->comboBox->addItem("房车");
    ui->comboBox->addItem("SUV");
    ui->comboBox->addItem("轿车");
    //点击按钮选中皮卡
    connect(ui->btn_combo1,&QPushButton::clicked,[=](){
        ui->comboBox->setCurrentIndex(0);
        ui->comboBox->setCurrentText("皮卡");//当前内容要有才行
    });
```

#### Plant Text Edit

* 仅支持普通多行输入
* 不支持斜体在内的输入

#### Spin Box

* 简单数字加减

#### 滑动条

* Horizontal Scroll Bar
* Vertial Scroll Bar
* Horizontal Slider
  * 可以随着其他控件的改变而滑动改变，需要自己封装



#### 显示图片

* 可以使用QLabel的成员函数setPixmap设置图片
* 也可以显示动图

```C++
    //Label添加图片
    ui->label_movie->setPixmap(QPixmap(":/image/1.jpg"));
    //添加动图
    QMovie *movie=new QMovie(":/image/gif1.gif");
    ui->label_movie_2->setMovie(movie);
    //播放动图
    movie->start();
```



#### Progress Bar

* 进度条显示



### 5.7.5 自定义控件封装

#### 封装简单控件

* 新建Qt设计师界面类

* 选择Widget窗口

* 设置名称SmallWidget

  ![image-20230314170334309](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102100.png)

* 绑定计数SpinBox与拖拽条Slider

  * 创建对应控件
  * 设置垂直布局
  * 调整大小

* 将SMallWidget显示到Widget窗口中

  * Widget主页面新建Widget窗口

  * 提升窗口

  * 设置全局包含后，下次提升可以直接提升为当前的全局包含

  * 注意Widget界面对应提升窗口多大，显示的内容窗口就多大

    ![image-20230314165237310](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102101.png)

    ![image-20230314165414818](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102102.png)

  

  

* 绑定Spin信号与Slider信号

  * 在smallwidget.cpp中建立连接
  * 相关知识点：[函数指针](https://www.runoob.com/w3cnote/cpp-func-pointer.html)

  ```C++
  #include "smallwidget.h"
  #include "ui_smallwidget.h"
  #include<QSpinBox>
  #include<QSlider>
  SmallWidget::SmallWidget(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::SmallWidget)
  {
      ui->setupUi(this);
      //QSpinBox移动 QSlider跟着移动
      //函数指针： 返回值 作用域 指针名称 参数类型
      void(QSpinBox::*spSignal)(int)=&QSpinBox::valueChanged;
      connect(ui->spinBox,spSignal,ui->horizontalSlider,&QSlider::setValue);
      //QSlider滑动，QSpinBox跟着改变
      connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
  }
  
  SmallWidget::~SmallWidget()
  {
      delete ui;
  }
  
  ```





#### 设置数值

* 自定义槽函数，按钮

  * 设置按钮显示当前数值
  * 设置当前数值为指定值

* SmallWidget提供公开方法`setNum()`

  * .h声明
  * .cpp实现

  ```C++
  //设置数值为指定值
  void SmallWidget::setNum(int num){
      ui->spinBox->setValue(num);
  }
  //获取值
  int SmallWidget::getNum(){
      return ui->spinBox->value();
  }
  ```



* 在主窗口中建立连接

  * 连接中找到子控件类名

    ![image-20230314205812137](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102103.png)

  * 找到对应函数

  ```C++
  #include "widget.h"
  #include "ui_widget.h"
  #include<QDebug>
  Widget::Widget(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::Widget)
  {
      ui->setupUi(this);
      //建立连接显示当前值
      connect(ui->btn_showNum,&QPushButton::clicked,[=](){//CONFIG+=c++11
              //此时对应子控件类名为Widget
         qDebug()<< ui->widget->getNum();
      });
      //建立连接设置为指定值
      int num=50;
      connect(ui->btn_setHalfNum,&QPushButton::clicked,[=](){//CONFIG+=c++11
              //此时对应子控件类名为Widget
          ui->widget->setNum(num);
      });
  }
  Widget::~Widget()
  {
      delete ui;
  }
  
  ```

  



# 6 Qt消息机制和事件

## 6.1 事件

* enterEvent 是鼠标在某个区域内触发，例如在按钮上 在文本框内等等

### 自定义鼠标事件

* 在按钮范围内控制台输出信息进入按钮

* 自定义槽函数

  * 由于没有UI，所以创建C++类即可，基类设置为QWidget

    

*   同上操作`自定义控件封装`

  * 提升类
  * 注意提升的类要与自定义类一致（注意修改创建类的父类为提升类的类型）
  * 此处父类为QPushButton

* 鼠标点击释放移动事件

  * 鼠标左键打印，右键忽略 `e->button()==Qt::LeftButton` 
  * 鼠标移动这种组合按钮，只左键

* 鼠标追踪

  * 设置鼠标追踪后，如果没有判断语句，只要鼠标移动就可以捕捉

  ```C++
  #include "mypushbutton.h"
  #include<QDebug>
  #include<QMouseEvent>
  myPushButton::myPushButton(QWidget *parent) :
      QPushButton(parent)
  {
      //设置鼠标追踪状态
      setMouseTracking(true);//只要鼠标移动就可以捕捉
  }
  //鼠标进入事件
  void myPushButton::enterEvent(QEvent *) {
      qDebug()<<"鼠标进入";
  }
  
  //鼠标离开事件
  void myPushButton::leaveEvent(QEvent *){
      qDebug()<<"鼠标离开";
  }
  //鼠标点击事件
  void myPushButton::mousePressEvent(QMouseEvent *e){
      if(e->button()==Qt::LeftButton){//仅左键
          //%1 %2为对应参数位置，arg为每一个参数（arg为其静态方法，返回对应指针）
          //windowPos是整个窗口的位置，直接x y是当前控件对应的相对位置 GlobalX是屏幕分辨率的位置
          QString str=QString("鼠标点击x=%1 y=%2").arg(e->windowPos().x()).arg(e->y());
          qDebug()<<str;
      }
  }
  
  //鼠标释放事件
  void myPushButton::mouseReleaseEvent(QMouseEvent *e){
      QString str=QString("鼠标释放x=%1  y=%2").arg(e->globalX()).arg(e->y());
      qDebug()<<str;
  }
  
  //鼠标移动事件
  void myPushButton::mouseMoveEvent(QMouseEvent *e){
      if(e->buttons()&Qt::LeftButton){//在多按键操作中必须使用&判断枚举值
          QString str=QString("鼠标移动x=%1 y=%2").arg(e->x(),e->windowPos().y());
          qDebug()<<str;
      }
  }
  
  ```

### 计时器

* 简单计时器·`timerEvent`

  * 添加label控件，在主界面重写定时器事件

  * 设置时间变化函数

    ```C++
    #include "widget.h"
    #include "ui_widget.h"
    #include<QTime>
    Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget)
    {
        ui->setupUi(this);
    
        //启动定时器
        startTimer(1000);//参数 时间间隔，单位毫秒
    }
    
    //重写定时器事件
    void Widget::timerEvent(QTimerEvent *){
        static int num=1;
        ui->label_time->setText(QString::number(num++));
    }
    Widget::~Widget()
    {
        delete ui;
    }
    
    ```

* 多个计时器使用`timeId`区分`timerEvent`

  * 添加类成员变量id1 id2

  * 通过判断id区分计时器

    ```C++
    #include "widget.h"
    #include "ui_widget.h"
    #include<QTime>
    Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget)
    {
        ui->setupUi(this);
    
        //启动定时器
        id1= startTimer(1000);//参数 时间间隔，单位毫秒
        id2=startTimer(2000);//参数 时间间隔，单位毫秒
    }
    
    //重写定时器事件
    void Widget::timerEvent(QTimerEvent *e){
        if(e->timerId()==id1){
             static int num=1;
             //1
             ui->label_time->setText(QString::number(num++));
        }
       if(e->timerId()==id2){
    
        static int num2=1;
        //2
        ui->label_time2->setText(QString::number(num2++));
       }
    
    }
    Widget::~Widget()
    {
        delete ui;
    }
    
    ```

* 使用`QTimer`实现定时器

  ```C++
  //定时器的第二种方式QTimer
      QTimer *timer=new QTimer(this);
      //启动定时器
      timer->start(500);
      connect(timer,&QTimer::timeout,[=](){
          static int num4=1;
          //每500毫秒加一
          ui->label_time3->setText(QString::number(num4++));
      });
  ```

* 设置按钮暂停时间

  ```C++
  //按钮暂停
      connect(ui->btn_pause,&QPushButton::clicked,[=](){
          static bool flag=false;
          if(!flag){
              timer->stop();
              flag=true;
          }else{
              timer->start();
              flag=false;
          }
  
      });
  ```

* timer实现自动移动

  ```C++
      //定时器自动实现移动
      QTimer *timer=new QTimer(this);
      //启动定时器
      timer->start(500);
      connect(timer,&QTimer::timeout,[=](){
          posx+=20;
          update();
      });
  ```

  

## 6.2 event（）事件分发器

事件对象创建完毕后，Qt 将这个事件对象传递给QObject的event()函数。event()函数并不直接处理事件，而是将这些事件对象按照它们不同的类型，分发给不同的事件处理器（event handler）。

如上所述，**event()函数主要用于事件的分发**。所以，如果你希望在事件分发之前做一些操作，就可以重写这个event()函数了。我们重写了它的event()函数，这个函数有一个QEvent对象作为参数，也就是需要转发的事件对象。函数返回值是 bool 类型。

*  **如果传入的事件已被识别并且处理，则需要返回 true，否则返回 false。如果返回值是 true，那么 Qt 会认为这个事件已经处理完毕，不会再将这个事件发送给其它对象，而是会继续处理事件队列中的下一事件。**
*  **在event()函数中，调用事件对象的accept()和ignore()函数是没有作用的，不会影响到事件的传播**。
*  也可以做事件的拦截



### 事件拦截

```C++
//通过event事件分发器 拦截鼠标按下事件
bool myPushButton::event(QEvent *e){
    //如果是鼠标的按下事件，在event事件分发中做拦截操作
    if(e->type()==QEvent::MouseButtonPress){
        QString str=QString("拦截鼠标按下");
        //类型转化
        QMouseEvent *ev=static_cast<QMouseEvent *>(e);
        QString str2=QString("Event鼠标点击x=%1 y=%2").arg(ev->windowPos().x()).arg(ev->y());
        qDebug()<<str;
        qDebug()<<str2;
        //返回true代表自己处理
        return true;
    }
    //其他事件交给父类处理
    return QPushButton::event(e);
}

```



**event()函数中实际是通过事件处理器来响应一个具体的事件。这相当于event()函数将具体事件的处理“委托”给具体的事件处理器。而这些事件处理器是 protected virtual 的，因此，我们重写了某一个事件处理器，即可让 Qt 调用我们自己实现的版本。**

由此可以见，event()是一个集中处理不同类型的事件的地方。如果你不想重写一大堆事件处理器，就可以重写这个event()函数，通过QEvent::type()判断不同的事件。鉴于重写event()函数需要十分小心注意父类的同名函数的调用，一不留神就可能出现问题，所以一般还是建议只重写事件处理器（当然，也必须记得是不是应该调用父类的同名处理器）。这其实暗示了event()函数的另外一个作用：屏蔽掉某些不需要的事件处理器。

## 6.3 事件过滤器

有时候，对象需要查看、甚至要拦截发送到另外对象的事件。例如，对话框可能想要拦截按键事件，不让别的组件接收到；或者要修改回车键的默认处理。

通过前面的章节，我们已经知道，Qt 创建了QEvent事件对象之后，会调用QObject的event()函数处理事件的分发。显然，我们可以在event()函数中实现拦截的操作。由于event()函数是 protected 的，因此，需要继承已有类。如果组件很多，就需要重写很多个event()函数。这当然相当麻烦，更不用说重写event()函数还得小心一堆问题。好在 Qt 提供了另外一种机制来达到这一目的：事件过滤器。

 ```C++
 //myPushButton安装事件过滤器
    //安装事件过滤器
    ui->pushButton->installEventFilter(this);
    //重写eventfilter事件
    
    

//重写事件过滤器的事件
bool Widget::eventFilter(QObject *obj, QEvent *e){
    //控件判断
    if(obj==ui->pushButton){
        if(e->type()==QEvent::MouseButtonPress){
            //类型转化
            QMouseEvent *ev=static_cast<QMouseEvent *>(e);
            QString str2=QString("事件过滤器 鼠标点击x=%1 y=%2").arg(ev->windowPos().x()).arg(ev->y());
            qDebug()<<str2;
            //返回true代表自己处理
            return true;
        }
    }
    //其他默认处理
    return QWidget::eventFilter(obj,e);

}
 ```



事件过滤器的强大之处在于，我们可以为整个应用程序添加一个事件过滤器。记得，installEventFilter()函数是QObject的函数，QApplication或者QCoreApplication对象都是QObject的子类，因此，我们可以向QApplication或者QCoreApplication添加事件过滤器。**这种全局的事件过滤器将会在所有其它特性对象的事件过滤器之前调用。尽管很强大，但这种行为会严重降低整个应用程序的事件分发效率。**因此，除非是不得不使用的情况，否则的话我们不应该这么做。

**注意，**

**事件过滤器和被安装过滤器的组件必须在同一线程，否则，过滤器将不起作用。另外，如果在安装过滤器之后，这两个组件到了不同的线程，那么，只有等到二者重新回到同一线程的时候过滤器才会有效。**



# 7 绘图和绘图设备

## 7.1QPainter

### 7.1.1 绘图事件

* 创建画家事件类

* 注意要想使用绘画要在头文件中添加画家类

* 实例化画家对象

  ```C++
  #include "widget.h"
  #include "ui_widget.h"
  #include<QPainter>//画家类
  Widget::Widget(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::Widget)
  {
      ui->setupUi(this);
  
  }
  //绘图事件
  void Widget::paintEvent(QPaintEvent* ){
      //实例化画家对象
      QPainter painter(this);//this指定绘图设备
      //设置画笔
      QPen pen(QColor(126,23,123));
      //设置画笔宽度
      pen.setWidth(3);
      //设置画笔风格
      pen.setStyle(Qt::DotLine);
      //使用画笔
      painter.setPen(pen);
  
      //设置笔刷
      QBrush brush(QColor(120,203,123));
      //笔刷风格
      brush.setStyle(Qt::Dense1Pattern);
      //画家使用笔刷
      painter.setBrush(brush);
  
  
      //画线
      painter.drawLine(QPoint(0,0),QPoint(100,100));
      //画圆 椭圆
      painter.drawEllipse(QPoint(100,100),60,60);
      //矩形
      painter.drawRect(200,100,300,200);
      //文字
      painter.drawText(QRect(200,400,200,300),"生存还是毁灭");
  }
  
  Widget::~Widget()
  {
      delete ui;
  
  }
  
  ```

  

### 7.1.2绘图事件高级设置

   ```C++
    //绘图高级事件
    QPainter painter(this);
    //    painter.drawEllipse(QPoint(100,50),50,50);
    //    //设置抗锯齿能力 增加抗锯齿效率低点
    //    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    //    painter.drawEllipse(QPoint(200,50),50,50);

    //画矩形
    painter.drawRect(QRect(20,20,50,50));
    //移动画家
    painter.translate(100,0);
    //保存画家状态
    painter.save();
    painter.drawRect(QRect(20,20,50,50));
    painter.translate(100,0);
    //还原画家状态
    painter.restore();
    painter.drawRect(QRect(20,20,50,50));
   ```

### 7.1.3手动调用绘图事件

* 添加资源图片

  

* 点击按钮移动图片

  * 设置对象属性posx
  * 建立连接
  * 检测超出屏幕判断

  ```
       //利用画家直接画资源图片
      QPainter painter(this);
      //设置超出屏幕从0开始
      if(posx>this->width()){
          posx=0;
      }
      painter.drawPixmap(posx,10,QPixmap(":/image/4.jpg"));
  ```

  ```C++
  Widget::Widget(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::Widget)
  {
      ui->setupUi(this);
      //点击按钮移动图片
      connect(ui->pushButton,&QPushButton::clicked,[=](){
          //如果需要手动调用绘图事件，使用update更新
          posx+=20;
          update();
      });
  
  }
  ```

  

## 7.2绘图设备

![image-20230315161539181](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303220102104.png)

### 7.2.1 Pixmap绘图设备

```C++
    ui->setupUi(this);
    //Pixmap绘图设备  专门为平台做了显示的优化
    QPixmap pix(1000,1000);//宽高
    //填充背景
    pix.fill(Qt::white);
    //声明画家
    QPainter painter(&pix);
    painter.setPen(QPen(Qt::green));
    painter.drawEllipse(QPoint(100,100),100,100);
 
    //保存-- 此时画出来窗口是没有东西的但是保存文件是存在的
    pix.save("D:\\CodingSpace\\Qt\\QtLearnBasedOn5.3.1\\7_2_QPaintDevice\\pix.png");
```



### 7.2.2 QImage作为绘图设备

```C++
 //QImage作为绘图设备
    //宽高 格式
    QImage img(300,300,QImage::Format_RGB32);
    img.fill(Qt::blue);
    QPainter painter(&img);
    painter.setPen(QPen(Qt::black));
    painter.drawEllipse(QPoint(100,100),100,100);
    img.save("D:\\CodingSpace\\Qt\\QtLearnBasedOn5.3.1\\7_2_QPaintDevice\\img.png");
```

```C++
//窗口绘图事件
void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    //利用QImage对像素进行修改
    QImage img;
    //加载图片
    img.load(":/image/3.jpg");
    //修改像素点
    for(int i=50;i<100;i++){
        for(int j=50;j<100;j++){
            //像素点
            QRgb value=qRgb(255,0,0);
            img.setPixel(i,j,value);
        }
    }

    //显示图片
    painter.drawImage(0,0,img);
}
```

### 7.2.3  QPicture作为绘图设备

```C++
//QPicture作为绘图设备 可以记录和重现绘图指令
    QPicture pic;
    QPainter painter;
    //指定绘图设备，开始画
    painter.begin(&pic);
    painter.setPen(QPen(Qt::cyan));
    painter.drawEllipse(QPoint(100,100),100,100);
    //结束绘画
    painter.end();
    //保存 格式名称随便
    pic.save("D:\\CodingSpace\\Qt\\QtLearnBasedOn5.3.1\\7_2_QPaintDevice\\pic.zt");

```

* 重现绘图指令  窗口绘图事件中实现

```c++
    QPainter painter(this);
    //重现绘图指令
    QPicture pic;
    pic.load("D:\\CodingSpace\\Qt\\QtLearnBasedOn5.3.1\\7_2_QPaintDevice\\pic.zt");
    painter.drawPicture(0,0,pic);
```



# 8 文件系统

### 8.1 QFile文件读写操作

* 以一个案例引入文件系统的读写操作

* 设置ui界面
  * 单行文本与按钮水平布局
  * 新建多行文本
  * 整体垂直布局
  
* 设计代码

  * 使用文件对话框需要`QFileDialog`
  * 包含头文件
  * 建立连接
  * 打开文件将路径输入到单行文本中

* 将文件内容输入到多行文本中

  * 文件读取分为只读、只写、读写等操作
  * 只读又分为全部读取、单行读取等方式
  * 读取文件默认UTF-8格式
  * 最后要关闭文件

* 进行写操作

  * 打开文件
  * 最佳方式写文件
  * 输入数据
  * 关闭文件

  ```C++
  #include "widget.h"
  #include "ui_widget.h"
  #include<QFileDialog>//文件对话框
  #include<QLineEdit>//不包含·智能·提示不提示
  #include<QFile>//Qt文件读取
  #include<QTextCodec>//编码格式 在Qt6中没有了
  Widget::Widget(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::Widget)
  {
      ui->setupUi(this);
      //点击选取文件，弹出文件对话框
      connect(ui->pushButton,&QPushButton::clicked,[=](){//CONFIG+=c++11
          //默认路径是当前项目的构建路径而不是项目文件所在路径！
          QString path=QFileDialog::getOpenFileName(this,"打开文件","../8_1_QtFile/葬花吟.txt");
          //将路径输入到单行文本框中
          ui->lineEdit->setText(path);
          //多行文本放入文本编辑框中
          //编码格式类
  //        QTextCodec *codec= QTextCodec::codecForName("gbk");
          QFile file(path);//参数就是文件读取路径  注意默认格式 UTF-8
          //设置打开方式
          file.open(QIODevice::ReadOnly);
          //读取文件
          QByteArray array=file.readAll();
  //        QByteArray array;
  //        //按行读取
  //        while(!file.atEnd()){
  //             array+=file.readLine();
  //        }
          //将读取数据放入textEdit中
          ui->textEdit->setText(array);//默认方式
          //先转码再读取
  //        ui->textEdit->setText(codec->toUnicode(array));
          //关闭文件
          file.close();
  
          //文件写操作
          file.open(QIODevice::Append);//追加方式写操作
          file.write("\n山一重，水一重，");
          file.close();
  
      });
  }
  
  Widget::~Widget()
  {
      delete ui;
  }
  
  ```

  

### 8.2 QFileInfo类

* 存储文件操作的信息

  * suffix() 文件格式 

  ```C++
  //文件信息类
          QFileInfo info(path);//文件路径
          qDebug()<<"大小："<<info.size()
                 <<"文件名称:"<<info.fileName()
                <<"文件路径："<<info.filePath()
               <<"文件类型："<<info.suffix();
          //文件日期  注意包含QDataTime
          qDebug()<<"创建日期："<<info.created().toString("yyyy/MM/dd hh:mm:ss");
  ```



# 9  翻转图片项目

* 每次反转图片，其上下左右都翻转
* 当所有图片是一面时游戏胜利



## 9.1资源文件

* 图片资源
  * 从网上下载的各种图片-未处理
  * 设计简单图片按钮--忽略
  * 开始 返回 关卡图片 图片反转图片 背景图片 icon图标 

* 音频资源



## 9.2 主场景

### 9.2.1 主场景配置

* 设置窗口为固定大小（游戏图片固定）

* 设置图标

* 设置窗口标题

  ```C++
      //配置主要大小
      //设置固定窗口大小
      this->setFixedSize(600,1020);
      //设置icon图标
      this->setWindowIcon(QPixmap(":/image/tuzi.jpg"));
      //设置应用标题
      this->setWindowTitle("图片翻转");
  ```

  

* 主界面菜单

  * 退出

    ```C++
        //退出按钮的实现
        connect(ui->actionLoginOut,&QAction::triggered,[=](){//CONFIG+=c++11
            this->close();
        });
    ```

* 移除自带的工具栏与状态栏



### 9.2.2 设置背景图片

* 重写主窗口的paintEvent()事件，添加背景图片

  ```C++
  //重写paintEvent事件 绘图
  void MainScene::paintEvent(QPaintEvent *){
      //创建画家，指定绘图设备
      QPainter painter(this);
      //创建QPixmap对象
      QPixmap pix;
      //加载图片
      pix.load(":/image/background.png");
      //绘制背景图 设置为this.width可能会拉伸图片注意
      painter.drawPixmap(0,0,this->width(),this->height(),pix);
  
      //绘制背景图标
      pix.load(":/image/title.png");
      //图片缩放
      pix= pix.scaled(pix.width()*0.6,pix.height()*0.6);
      painter.drawPixmap(10,30,pix);//后面画的图层在上面
  
  }
  ```

  

### 9.2.3 创建开始按钮

* 由于Qt中没有自带的实现按钮移动后者切换的效果，需要自己封装
  
* `Start`和`Back`按钮都是动态效果，但是一个没有图片切换一个有
  
* 创建`MyPushButton`类，继承`QPushButton` 

  * 构造函数参数为默认显示图片路径 和按下后显示图片

  ```C++
     //构造函数  默认图片 按下后显示的图片(不一定有)
      MyPushButton(QString nomalImage,QString secondImage=" ");
  
      //成员属性保存图片默认显示路径及按下后显示路径
      QString nomalImagePath;
      QString secondImagePath;
  ```

* 实现构造函数

  ```C++
  #include "mypushbutton.h"
  #include<QPushButton>
  #include<QDebug>
  
  
  //默认图片 第二个图片(不一定有)  构造函数中有默认值，声明中则没有
  MyPushButton::MyPushButton(QString nomalImage,QString secondImage){
      //设置成员属性值为指定路径
      this->nomalImagePath=nomalImage;
      this->secondImagePath=secondImage;
  
      QPixmap pix;
      //加载默认显示推按
      bool show =pix.load(nomalImage);
      //图片加载失败，结束程序
      if(!show){
          qDebug()<<"图片加载失败";
          return;
      }
      //设置图片为固定大小
      this->setFixedSize(pix.width(),pix.height());
      //设置不规则图片样式   css
      this->setStyleSheet("QPushButton{border:0px;}");
      //设置图标
      this->setIcon(pix);
      //设置图标大小
      this->setIconSize(QSize(pix.width(),pix.height()));
  }
  
  ```

  

* 主场景中使用自定义按钮
  * 包含头文件
  * 创建按钮
  * 放到主屏幕中
  * 移动位置
  * 建立连接

```C++
//开始按钮
    MyPushButton *startBtn=new MyPushButton(":/image/start.png");
    //将按钮放入到当前窗口中
    startBtn->setParent(this);
    //移动按钮到中间偏下位置
    startBtn->move(QPoint(this->window()->width()*0.5-startBtn->width()*0.5,this->window()->height()*0.6));

    //开始按钮连接
    connect(startBtn,&QPushButton::clicked,[=](){
        qDebug()<<"开始按钮被点击了";
        //按钮弹跳效果
        
    });
```



* 实现弹跳效果函数--自定义按钮的成员函数

  ```C++
  //弹跳函数--向下
  void MyPushButton::bounceDown(){
      //创建动画对象 对象是谁 那种特效
      QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
      //设置动画间隔
      animation->setDuration(200);
      //起始位置
      animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
      //结束位置
      animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
      //设置弹跳曲线--类似球落地反向
      animation->setEasingCurve(QEasingCurve::OutBounce);
      //执行动画
      animation->start();
  }
  
  //弹跳函数--向上
  void MyPushButton::bounceUp(){
      //创建动画对象 对象是谁 那种特效
      QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
      //设置动画间隔
      animation->setDuration(200);
      //起始位置
      animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
      //结束位置
      animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
      //设置弹跳曲线--类似球落地反向
      animation->setEasingCurve(QEasingCurve::OutBounce);
      //执行动画
      animation->start();
  }
  ```



## 9.3 选择关卡场景

###  9.3.1 选择关卡场景基本配置

* 创建选择关卡类`ChooseLevelScene` 继承主窗口

*  在主场景头文件中新建属性关卡类指针，默认值为NULL

  ```C++
      //关卡场景
      ChooseLevelScene *chooseLevelScene=NULL;
  ```

* 在主场景中实例化选择关卡场景

  ```C++
      //实例化选择关卡场景--放在开始按钮信号前
       chooseLevelScene =new ChooseLevelScene;
  ```

* 在点击开始按钮后隐藏当前界面，显示选择关卡界面

  * 由于直接进入看不到按钮效果，添加延时

  ```C++
  //        QTimer ::singleShot(500,this,[=]{}); 5.3不支持这种写法
          //延时到选择关卡场景
          QTimer* t = new QTimer(this);
          connect(t,&QTimer::timeout,[=](){
              t->stop();//停止计时
              t->deleteLater();//删除对象
              //显示选择关卡场景
              chooseLevelScene->show();
              //隐藏自身
              this->hide();
          });
          t->start(50);//开始计时
  ```

  

* 使用代码实现菜单栏

  * 创建开始菜单
  * 创建菜单
  * 退出程序

  ```C++
      //选择关卡代码实现菜单栏
      QMenuBar *bar=menuBar();
      //只有一个的用set有多个的用add
      setMenuBar(bar);
      //创建开始菜单
      QMenu *startMenu=  bar->addMenu("菜单");
      //创建退出的菜单项
      QAction *quitAction= startMenu->addAction("退出");
      //点击退出
      connect(quitAction,&QAction::triggered,[=](){
          this->close();
      });
  ```

  

*  重写绘图事件

  ```C++
  //重写绘图事件
  void ChooseLevelScene::paintEvent(QPaintEvent *){
      //创建画家
      QPainter painter(this);
      //创建QPixmap对象
      QPixmap pix;
      //加载背景图片
      pix.load(":/image/background2.png");
      //绘制背景图片
      painter.drawPixmap(0,0,this->width(),this->height(),pix);
      //绘制背景图标
      pix.load(":/image/title.png");
      //图片缩放
      pix= pix.scaled(pix.width()*0.6,pix.height()*0.6);
      painter.drawPixmap(10,30,pix);//后面画的图层在上面
  }
  ```

 

*  返回按钮

  * 使用自定义的按钮类实现

  ```C++
      //使用自定义按钮实现返回按钮
      //返回按钮的两个图片
      QString img1=":/image/Back.png";
      QString img2=":/image/Back2.png";
      MyPushButton *backBtn=new MyPushButton(img1,img2);
  
      //将按钮显示到窗口中
      backBtn->setParent(this);
      //移动到右下角
      backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());
  ```

* 点击按钮--基本实现

   ```C++
      //点击按钮返回
      connect(backBtn,&QPushButton::clicked,[=](){
          qDebug()<<"点击返回按钮";
      });
   ```

  

 

### 9.3.2 返回按钮的图片切换

* `myPushButton`重写鼠标按下 释放事件 实现切换图片

  ```C++
  //鼠标点击按键
  void MyPushButton::mousePressEvent(QMouseEvent *e){
      qDebug()<<"鼠标点击事件";
  
      //如果第二张图片不为空切换图片
      if(this->secondImagePath!=" "){
          QPixmap pix;
          //加载默认显示图片
          bool show =pix.load(this->secondImagePath);
          //图片加载失败，结束程序
          if(!show){
              qDebug()<<"图片加载失败";
              return;
          }
          //设置图片为固定大小
          this->setFixedSize(pix.width()*0.5,pix.height()*0.5);
          //设置不规则图片样式   css
          this->setStyleSheet("QPushButton{border:0px;}");
          //设置图标
          this->setIcon(pix);
          //设置图标大小
          this->setIconSize(QSize(pix.width()*0.5,pix.height()*0.5));
      }
         //父类执行其他内容
      return QPushButton::mousePressEvent(e);
  }
  
  //鼠标释放事件
  void MyPushButton::mouseReleaseEvent(QMouseEvent *e){
      //如果第二张图片不为空切换图片
      if(this->secondImagePath!=" "){
          QPixmap pix;
          //加载默认显示图片
          bool show =pix.load(this->nomalImagePath);
          //图片加载失败，结束程序
          if(!show){
              qDebug()<<"图片加载失败";
              return;
          }
          //设置图片为固定大小
          this->setFixedSize(pix.width()*0.5,pix.height()*0.5);
          //设置不规则图片样式   css
          this->setStyleSheet("QPushButton{border:0px;}");
          //设置图标
          this->setIcon(pix);
          //设置图标大小
          this->setIconSize(QSize(pix.width()*0.5,pix.height()*0.5));
  
      }
      //父类执行其他内容
       return QPushButton::mouseReleaseEvent(e);
  }
  ```

  

### 9.3.3 开始按钮与返回按钮切换

* 选择关卡页面创建自定义信号`chooseSceneBack()`

  * 点击返回按钮后触发自定义信号

  * 添加延时操作

    ```C++
        //点击按钮返回
        connect(backBtn,&QPushButton::clicked,[=](){
            //        qDebug()<<"点击返回按钮";
            //延时操作
            QTimer *timer=new QTimer(this);
            //延时信号检测
            connect(timer,&QTimer::timeout,[=](){
                //停止计时
                timer->stop();
                //销毁计时器
                timer->deleteLater();
                //告诉主场景，返回信号。主场景监听返回信号
                emit this->chooseSceneBack();
            });
            //启动计时器
            timer->start(50);
        });
    ```

    

  * 在主窗口监听返回按钮的信号

    ```C++
        //监听选择关卡的返回按钮的信号
        connect(chooseLevelScene,&ChooseLevelScene::chooseSceneBack,[=](){
            //显示当前页面，隐藏关卡页面
            this->show();
            chooseLevelScene->hide();
        });
    ```

    

### 9.3.4 创建选择关卡场景

* for循环创建按钮
  * 由于自定义按钮的大小不一定合适，需要重新设置大大小
* 使用QLabel显示图片上的文字
  * 有偏移量则不居中
  * 无偏移量则设置居中
  * 注意使用控件遮住后需要设置鼠标穿透才能触发下面的点击按钮
* 使用QFont设置字体属性

```C++
  //创建选择关卡的按钮
    for(int i=0;i<20;i++){
        MyPushButton *menuBtn =new MyPushButton(":/image/bill.png");
        menuBtn->setParent(this);
        //设置图片为固定大小
        menuBtn->setFixedSize(this->width()*0.15,this->height()*0.15);
        //设置图标大小
        menuBtn->setIconSize(QSize( menuBtn->width(),menuBtn->width()));
        //移动按钮到指定位置
        menuBtn->move(i%4*120+80,i/4*120+130);
        //使用QLabel显示图片上的文字
        QLabel *label=new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(i%4*120+80,i/4*120+130);
        //监控每个按钮的点击事件
        connect(menuBtn,&QPushButton::clicked,[=](){
            qDebug()<<"选择关卡："<<i+1;
        });
        //设置文字居中
        //如果此处设置剧中，上面移动则不需要偏移
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        //设置字体
        QFont ft;
        ft.setPointSize(12);//设置字体大小
        ft.setBold(true);//加粗
        ft.setFamily("幼圆");//设置字体
        label->setFont(ft);

        //设置鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

```



### 9.3.5 创建翻转图片场景

* 创建场景文件`GameScene`
  * 继承主窗口
  
  * 在关卡选择界面.h文件中声明对象
  
    ```c++
     //具体关卡场景
        GameScene *gameScene=NULL;
    ```
  

* 在每个关卡的监听点击按钮中设置进入游戏关卡操作

```C++
//进入游戏场景
            gameScene=new GameScene(i+1);
            gameScene->show();//显示具体关卡界面
            this->hide();//隐藏选择关卡界面

```

* 创建具体关卡构造函数

  * 不同关卡内容不同传递不同参数
  * 设置固定大小
  * 设置icon和标题
  * 设置菜单栏
  * 退出

  ```C++
  GameScene::GameScene(int levelNum){
      this->levelIndex=levelNum;
  //    QString str=QString("游戏关卡：%1").arg(levelNum);
  //    qDebug()<<str;
  
      //初始化游戏场景
      //设置固定大小
      this->setFixedSize(600,1020);
      //设置icon 每一关图片不一样
      this->setWindowIcon(QPixmap(QString(":/image/level (%1).png").arg(this->levelIndex)));
      //设置标题
      this->setWindowTitle(QString("翻转图片第%1关").arg(this->levelIndex));
  
      //选择关卡代码实现菜单栏
      QMenuBar *bar=menuBar();
      //只有一个的用set有多个的用add
      setMenuBar(bar);
      //创建开始菜单
      QMenu *startMenu=  bar->addMenu("菜单");
      //创建退出的菜单项
      QAction *quitAction= startMenu->addAction("退出");
  
      //点击退出
      connect(quitAction,&QAction::triggered,[=](){
          this->close();
      });
  }
  ```

  

* 重写`paintEvent`事件

  * 绘制背景

    ```C++
    //重写paintEvent事件
    void GameScene::paintEvent(QPaintEvent *){
        //创建画家
        QPainter painter(this);
        //创建Pixmap对象
        QPixmap pix;
        //加载背景图片
        pix.load(":/image/background3.jpg");
        //绘制背景图片
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
        //绘制背景图标
        pix.load(":/image/title.png");
        //图片缩放
        pix= pix.scaled(pix.width()*0.6,pix.height()*0.6);
        painter.drawPixmap(10,30,pix);//后面画的图层在上面
    
    }
    ```

* 返回按钮

  * 触发自定义信号，返回的界面是关卡界面
  * 声明自定义槽信号
  * 创建返回按钮并触发时钟信号
  * 关卡选择界面建立连接接收信号
    * 注意要放在创建的信号槽内，因为不放在内部对象不知道是具体哪个关卡的

  ```C++
      //使用自定义按钮实现返回按钮
      //返回按钮的两个图片
      QString img1=":/image/Back.png";
      QString img2=":/image/Back2.png";
      MyPushButton *backBtn=new MyPushButton(img1,img2);
  
      //将按钮显示到窗口中
      backBtn->setParent(this);
      //移动到右下角
      backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());
  
      //点击按钮返回
      connect(backBtn,&QPushButton::clicked,[=](){
                  qDebug()<<"具体关卡点击返回按钮";
          //延时操作
          QTimer *timer=new QTimer(this);
          //延时信号检测
          connect(timer,&QTimer::timeout,[=](){
              //停止计时
              timer->stop();
              //销毁计时器
              timer->deleteLater();
              //告诉关卡场景，返回信号。关卡场景监听返回信号
                qDebug()<<"发出信号！";
              emit this->chooseSceneBack();;
          });
          //启动计时器
          timer->start(50);
      });
  ```

  ```C++
              //监听具体关卡信号--每个关卡不一样，所以放到场景创建后
              connect(gameScene,&GameScene::chooseSceneBack,[=](){
                  qDebug()<<"检测信号！";
                  //显示当前页面，删除关卡页面
                  this->show();
                  delete gameScene;
                  gameScene=NULL;
              });
  ```

  

## 9.4 具体关卡场景

### 9.4.1 显示选择的关卡号

* 使用`QLabel `实现

```C++
//实现显示关卡号
    QLabel *label=new QLabel(this);//也可先无参然后setParent this
    //设置字体和大小
    QFont ft;
    ft.setPointSize(22);//字体大小
    ft.setFamily("幼圆");
    ft.setBold(true);//加粗
    //设置字体
    label->setFont(ft);
    //设置内容
    label->setText(QString("Level:%1").arg(this->levelIndex));
//    //移动位置
//    label->move(20,this->height()-label->height());
    //设置大小 位置 宽高
    label->setGeometry(20,this->height()-50,200,50);
```

### 9.4.2 创建金币类背景图片

```C++
  //设置默认背景--后面修改了代码
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            //绘制背景图片
            QPixmap pix=QPixmap(":/image/backPure3.png");
            //图片缩放
//            pix.scaled(pix.width()*0.1,pix.height()*0.1);
            QLabel *label=new QLabel(this);
            label->setPixmap(pix);
            //设置大小 位置 宽高
            label->setGeometry(0,0,pix.width()*0.5,pix.height()*0.5);
            //设置缩放填充图片
            label->setScaledContents(true);
            label->move(100+i*70,j*70+300);
        }
    }


```



### 9.4.3 金币类的封装

#### 创建金币类

* `MyImage`继承`QPushButton`

* 自定义构造函数

  * 读取图片

  * 设置固定大小

  * 设置无边框

    ```C++
    //参数代表的是传入的图片的路径
    MyImage::MyImage(QString btnImg){
        QPixmap pix;
        //图片加载失败
        if(!pix.load(btnImg)){
            qDebug()<<QString("图片%1加载失败").arg(btnImg);
            return;
        }
        int size=100;
        //重置大小--图片不一致缩小到固定宽度
        pix=pix.scaled(size,pix.height()/(pix.width()/size));
        //设置固定大小--对上面图片截图
        this->setFixedSize(60,60);
        //设置不规则图形无边框
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图片
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    ```

    

* 游戏关卡创建金币类

  * 设置移动参数

    ```C++
     //设置默认背景
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                //绘制背景图片
                QPixmap pix=QPixmap(":/image/backPure3.png");
                //图片缩放
    //            pix.scaled(pix.width()*0.1,pix.height()*0.1);
                QLabel *label=new QLabel(this);
                label->setPixmap(pix);
                //设置大小 位置 宽高
                label->setGeometry(0,0,pix.width()*0.5,pix.height()*0.5);
                //设置缩放填充图片
                label->setScaledContents(true);
                label->move(80+i*100,j*100+330);
    
                //创建图片
                MyImage *image=new MyImage(QString(":/image/level (%1).png").arg(this->levelIndex));
                image->setParent(this);
                image->move(115+i*100,j*100+345);
            }
        }
       //设置下方图片
        QLabel *label2=new QLabel(this);
        QPixmap pix2=QPixmap(QString(":/image/level (%1).png").arg(this->levelIndex));
        pix2=pix2.scaled(200,pix2.height()/(pix2.width()/200));
        label2->setPixmap(pix2);
        //设置大小 位置 宽高
        label2->setGeometry(0,0,pix2.width(),pix2.height());
        label2->move(200,800);
    
    }
    
    ```

    

#### 关卡数据

* 创建了一个单独的类来存放每一关的数据。
* 全部是类似二维数据

### 9.4.4 初始化每个关卡

* 在关卡`gameScene`中创建二维数组维护每个关卡的具体数据

* 在对应`gameScene.cpp`中初始化二维数组的数据 

  ```C++
      //初始化每关的数据
      dataConfig *config;
      for(int i=0;i<4;i++){
          for(int j=0;j<4;j++){
              this->gameArray[i][j]=config->mData[this->levelIndex][i][j];
          }
      }
  ```

* 修改设置默认背景中创建图片代码，根据二维数组数据修改显示图片

  ```C++
              //创建图片
              //设置关卡图片数据
              QString str;
              if(this->gameArray[i][j]==1){//1是翻转后图片
                  str=QString(":/image/level (%1).png").arg(this->levelIndex);
              }else{//翻转前图片
  
                  str= QString(":/image/tuzi.jpg");
              }
              MyImage *image=new MyImage(str);
              image->setParent(this);
              image->move(115+i*100,j*100+345);
  ```

* 如果此处使用`dataconfig`报错，检查pro文件是否引入文件



### 9.4.5 金币翻转特效

* `MyImage`设置属性值记录图片状态

  * x y坐标

  * 正反面

    ```C++
        //图片属性
        int x;//x坐标
        int y;//y坐标
    		int level;
        bool flag;//正反面
    ```

    

* 在具体关卡页面赋值

  ```C++
              //金币属性赋值
              image->x=y;
              image->y=j;
  						image->level=this->levelIndex;//存储对应图片位序
              image->flag=this->gameArray[i][j];//1 正面 0反面
  ```

  

* `MyImage`设置创建改变flag的方法

  * 创建两个计时器用于图片翻转

    ```C++
        //改变标志的方法
        void changeFlag();
        QTimer *timer1;//正面的计时器
        QTimer *timer2;//反面的计时器
        int min=1;//最小值
        int max=8;//最大值
    ```

* 构造函数初始化计时器

* 改变图片标志的方法

  * 如果正面，启动计时器，翻转反面
  * 如果反面，启动计时器，翻转正面

  ```C++
  //改变图片标志的方法
  void MyImage::changeFlag(){
      //如果是正面，翻成反面
      if(this->flag){
          //开始正面翻转反面的定时器
          timer1->start(30);
          //        qDebug()<<"触发正面到反面计时";
          this->flag=false;
  
      }
      //如果是反面，翻成正面
      else{
          //开始正面翻转反面的定时器
          timer2->start(30);
          //        qDebug()<<"触发反面到正面计时";
          this->flag=true;
      }
  }
  ```

  

* 监听信号放在构造函数中

  ```c++
   //初始化定时器对象
      timer1=new QTimer(this);
      timer2=new QTimer(this);
      //监听正面翻转反面的信号 并翻转图片
      connect(timer1,&QTimer::timeout,[=](){
          QPixmap pix;
          QString str;
          //由于开始没有对应资源，使用的自定义图片没有翻转过程，图片不匹配
          if(this->min==1){//1是正面图片
              str=QString(":/image/level (%1).png").arg(this->level);
              this->min++;
          }else if(this->min==8){//翻转后图片
              str= QString(":/image/tuzi.jpg");
              this->min++;
          }else{//翻转过程图片
              str=QString(":/image/Coin000%1.png").arg(this->min++);
          }
          pix.load(str);
          //触发监听
          qDebug()<<"接受到正面到反面翻转信号";
          //设置图片属性
          //由于在外部设置了缩放填充图片及其他图片设置，此处不需要调整参数
  //        this->setFixedSize(pix.width(),pix.height());
  //        this->setStyleSheet("QPushButton{border:0px;}");
          this->setIcon(pix);
  //        this->setIconSize(QSize(pix.width(),pix.height()));
          //翻转完成重置数据
          if(this->min>this->max){
              this->min=1;
              timer1->stop();
          }
          pix.load(str);
      });
      //监听反面翻转正面的信号 并翻转图片
      connect(timer2,&QTimer::timeout,[=](){
          QPixmap pix;
          QString str;
          //由于开始没有对应资源，使用的自定义图片没有翻转过程，图片不匹配
          if(this->max==8){//1是翻转前图片
              str= QString(":/image/tuzi.jpg");
              this->max--;
          }else if(this->max==1){//翻转后图片
              str=QString(":/image/level (%1).png").arg(this->level);
              this->max--;
          }else{//翻转过程图片
              str=QString(":/image/Coin000%1.png").arg(this->max--);
          }
          pix.load(str);
          //触发监听
          //        qDebug()<<"接受到正面到反面翻转信号";
          //设置图片属性
          //由于在外部设置了缩放填充图片及其他图片设置，此处不需要调整参数
          //        this->setFixedSize(pix.width(),pix.height());
          this->setStyleSheet("QPushButton{border:0px;}");
          this->setIcon(pix);
          //        this->setIconSize(QSize(pix.width(),pix.height()));
          //翻转完成重置数据
          if(this->min>this->max){
              this->max=8;
              timer2->stop();
          }
          pix.load(str);
      });
  ```

* 在关卡场景中建立金币连接

  * 先初步连接测试代码
  * 修改数组数据

  ```C++
              //点击金币，进行翻转
              connect(image,&MyImage::clicked,[=](){
                  image->changeFlag();
                 //修改数据，便于后续操作
                  this->gameArray[i][j]=this->gameArray[i][j]==1?0:1;
              });
  ```

* `myImage`添加标志运行标志位，用于保证动画运行

  * 默认不执行

    ```C++
     bool isAnimation=false;//执行动画标志位
    ```

  * 运行正反面翻转动画时改为true

  * 监听信号停止时改为false

  * 在`changeFlag`方法中增加判断该标志位，false执行true不执行

    ```C++
    /改变图片标志的方法
    void MyImage::changeFlag(){
        if(!this->isAnimation){//动画没有正在执行
            //如果是正面，翻成反面
            if(this->flag){
                //开始正面翻转反面的定时器
                timer1->start(30);
                //        qDebug()<<"触发正面到反面计时";
                isAnimation=true;//执行动画标志位
                this->flag=false;
    
            }
            //如果是反面，翻成正面
            else{
                //开始正面翻转反面的定时器
                timer2->start(30);
                //        qDebug()<<"触发反面到正面计时";
                isAnimation=true;//执行动画标志位
                this->flag=true;
            }
        }
    
    }
    
    ```

* 当然，也可以重写`myImage`的鼠标按下事件，如果标志位为false执行，否则返回

  ```C++
  //根据标志位判断鼠标按下事件是否有效--与在changeFlag中判断等价
  void MyImage::mousePressEvent(QMouseEvent *e){
      if(this->isAnimation){
          qDebug()<<"鼠标按下事件拦截多次点击信号";
          return;
      }else{//执行父类的操作
          QPushButton::mousePressEvent(e);
      }
  }
  ```

### 9.4.6 翻转周围

* 在关卡场景中添加二维数组维护按钮数据

  ```C++
      //关卡中所有按钮指针
      MyImage *imagePoint[4][4];
  ```

* 在运行关卡配置时存储相关数据

  * 修改周围数据注意不要越界

  * 使用QTimer的singleShot实现延迟操作--注意版本

  * 可以选择使用`MyImage`对象的x y增加可读性

    ```C++
    //图片放到图片二维数组指针中，便于后期维护
                this->imagePoint[i][j]=image;
                //点击金币，进行翻转
                connect(image,&MyImage::clicked,[=](){
                    image->changeFlag();
                    //修改数据，便于后续操作
                    this->gameArray[i][j]=this->gameArray[i][j]==1?0:1;
                    //周围翻转,延时
                    //        QTimer ::singleShot(500,this,[=]{}); 5.3不支持这种写法
                    //延时
                    QTimer* t = new QTimer(this);
                    connect(t,&QTimer::timeout,[=](){
                        //下
                        if(i+1<=3){
                            this->imagePoint[i+1][j]->changeFlag();
                            this->gameArray[i+1][j]=this->gameArray[i+1][j]==1?0:1;
                        }
                        //右
                        if(j+1<=3){
                            this->imagePoint[i][j+1]->changeFlag();
                            this->gameArray[i][j+1]=this->gameArray[i][j+1]==1?0:1;
                        }
                        //上
                        if(i-1>=0){
                            this->imagePoint[i-1][j]->changeFlag();
                            this->gameArray[i-1][j]=this->gameArray[i-1][j]==1?0:1;
                        }
                        //左
                        if(j-1>=0){
                            this->imagePoint[i][j-1]->changeFlag();
                            this->gameArray[i][j-1]=this->gameArray[i][j-1]==1?0:1;
                        }
                        t->stop();//停止计时
                        t->deleteLater();//删除对象
                    });
                    t->start(300);//开始计时
                });
    ```

### 9.4.7 判断胜利并禁用按钮

* 个人添加函数判断金币正反面数组中含有0即为失败

  * 可以设置x y上限为文件下二维数组的行列数 便于后期修改地图

  ```C++
  //判断是否胜利
  bool GameScene::isWin(){
      for(int x=0;x<4;x++){
          for(int y=0;y<4;y++){
              if(this->gameArray[x][y]==0){
                  return false;
              }
          }
      }
      return true;
  }
  ```

* 胜利弹出图标，响应音乐，禁用按钮

  * 代码放在翻转周围图片的计时器里

    ```C++
                        //翻转完成判断是否胜利--注意要放在计时器内部，因为放在外部会导致先执行判断
                        if(this->isWin()){
                            qDebug()<<"胜利";
                        }
    ```

* 禁用按钮

  * 在MyImage中添加属性`win`一旦赢得关卡设置true

  * 修改鼠标点击事件

    ```C++
    //根据标志位判断鼠标按下事件是否有效--与在changeFlag中判断等价
    void MyImage::mousePressEvent(QMouseEvent *e){
        if(this->isAnimation||this->win){//同时判断是否赢了--但是有问题，其他按键可以触发图片切换
            qDebug()<<"鼠标按下事件拦截多次点击信号";
            return;
        }else{//执行父类的操作
            QPushButton::mousePressEvent(e);
        }
    }
    ```

### 9.4.8 胜利图片显示

* 方式类似开始按钮，显示图片在界面外，在赢了之后采用移动方式将图片拉下来

  * 基本设置--代码放在设置背景前

    ```C++
        //设置胜利图片
        QLabel *winLabel=new QLabel;
        QPixmap pixWin;
        pixWin.load(":/image/LevelCompletedDialogBg.png");//设置图片
        winLabel->setGeometry(0,0,pixWin.width(),pixWin.height());//设置位置及大小
        winLabel->setPixmap(pixWin);
        winLabel->setParent(this);
        winLabel->move((this->width()-pixWin.width())*0.5,-pixWin.height());//移动到水平居中，垂直在界面外
    ```

  * 赢得比赛后移动位置到界面外，使用动画

    ```C++
                            //移动胜利图片
                            QPropertyAnimation *animation=new QPropertyAnimation(winLabel,"geometry");//看Qt助手介绍
                            //设置时间间隔
                            animation->setDuration(1000);
                            //设置开始值
                            animation->setStartValue(QRect((this->width()-pixWin.width())*0.5,0,winLabel->width(),winLabel->height()));
                            //设置结束位置
                            animation->setEndValue(QRect((this->width()-pixWin.width())*0.5,200,winLabel->width(),winLabel->height()));
                            //设置缓和曲线
                            animation->setEasingCurve(QEasingCurve::OutBounce);
                            //开始动画
                            animation->start();
    ```

### 9.4.9 BUG解决及音效

* 禁用按钮失效

  * 自定义按钮设置禁用属性为false

  * 每次翻转图片开局设置所有禁用

  * 结束翻转后再解开禁用

    ```C++
                    //禁用所有按钮
                    for(int a=0;a<4;a++){
                        for(int b=0;b<4;b++){
                            this->imagePoint[a][b]->enable=true;
                        }
                    }
    ```

* 使用QSound设置音效

  * 根据Qt助手添加`QT += multimedia`

  * 引用文件资源

  * play音效

  * 主场景音效

  * 其他音效类似

    ```C++
    //主场景开始音效
    QSound *startSound=new QSound(":/img/TapButtonSound.wav");
    //设置无限循环
    startSound.setLoop(-1);
    //开始按钮点击后音效
    startSound->play();
    
    ```



### 9.4.10 设置位置一致

* 使用`setGeometry`设置为当前窗口位置

  * 以主场景为案例 下面是位置
  * 进入设置为当前位置
  * 返回时设置为对应页面当前位置

  ```C++
          connect(t,&QTimer::timeout,[=](){
              t->stop();//停止计时
              t->deleteLater();//删除对象
              
              //设置为当前场景位置
              chooseLevelScene->setGeometry(this->geometry());
              
              //显示选择关卡场景
              chooseLevelScene->show();
              //隐藏自身
              this->hide();
  
          });
  
  
  
  
      //监听选择关卡的返回按钮的信号
      connect(chooseLevelScene,&ChooseLevelScene::chooseSceneBack,[=](){
          //设置为当前场景位置
          this->setGeometry(chooseLevelScene->geometry());
          //显示当前页面，隐藏关卡页面
          this->show();
          chooseLevelScene->hide();
      });
  ```



## 项目打包

* 程序先修改为`release`版本

* 完成之后先运行

* 到项目的release版本`build`文件复制exe程序到任意空文件夹中中运行cmd程序

  * 低版本要找到Qt自带的命令行工具运行

  * 并且切换到对应文件目录下

  * 示例  文件名`9_TurnOverGame.exe`

    ```C++
    C:\Users\yangc\Desktop\conin>windeployqt 9_TurnOverGame.exe
    ```

* 使用HM NIS Edit将上述文件打包成安装包[教程实例](https://blog.csdn.net/zhichaosong/article/details/106275151)

  * 编译中如果有错误记得删除报错行再次编译
  * 不要有中文路径或者名称，会报错

## 注意事项

* 资源过多会报错
  * 建立多个资源文件解决问题