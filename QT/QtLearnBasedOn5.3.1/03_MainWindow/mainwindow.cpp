#include "mainwindow.h"
#include<QMenuBar>//菜单栏
#include<QToolBar>//工具栏
#include<QPushButton>
#include<QStatusBar>//状态栏
#include<QLabel> //标签控件
#include<QDockWidget>//窗口
#include<QTextEdit> //中心部件
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    resize(600,400);

    //在程序中，菜单栏最多只能有一个
    //菜单栏创建
    QMenuBar *bar=menuBar();
    //将菜单栏放入到窗口中
    setMenuBar(bar);

    // 创建菜单
   QMenu *fileMenu= bar->addMenu("文件");
   QMenu *editMenu= bar->addMenu("编辑");
   QMenu *toolMenu= bar->addMenu("工具");
   //创建菜单项 可以选择接收指针
   QAction *newAction= fileMenu->addAction("新建");
   //添加分隔线
   fileMenu->addSeparator();
   QAction *fileAction=fileMenu->addAction("打开");

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
    //添加控件 注意添加头文件
    QPushButton *btn =new QPushButton("aa",this);
    toolBar->addWidget(btn);

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

}

MainWindow::~MainWindow()
{

}
