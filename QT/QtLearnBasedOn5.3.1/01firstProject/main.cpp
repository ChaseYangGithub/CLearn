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
