* 项目复现
* 项目资源来自黑马程序员飞机大战
* 文档来源于黑马程序员飞机大战_Qt制作添加修改
* 只用于个人技术学习
* [GitHub](https://github.com/ChaseYangGithub/CLearn/tree/main/QT)
* Build:`CMake`
* 编译器：`MinGW`  
* Qt:`Qt 5.15`

# 飞机大战_Qt制作

## 1 项目简介

飞机大战是我们大家所熟知的一款小游戏，本教程就是教大家如何制作一款自己的飞机大战

首先我们看一下效果图

![1579054835199](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955199.png)



玩家控制一架小飞机，然后自动发射子弹，如果子弹打到了飞下来的敌机，则射杀敌机，并且有爆炸的特效



接下来再说明一下案例的需求，也就是我们需要实现的内容

* 滚动的背景地图
* 飞机的制作和控制
* 子弹的制作和射击
* 敌机的制作
* 碰撞检测
* 爆炸效果
* 音效添加





## 2 创建项目



创建项目步骤如下：

* 打开Qt
* 按照向导创建项目
* 项目名称位置填写
* 类信息加入
* 完成创建 

### 2.1 按照向导创建项目

#### 2.1.1 新建项目

点击菜单 中的文件 -> 新建文件或项目  或者 在首页面中点击New Project

![1579055732914](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955201.png)



#### 2.1.2 选择模板

模板选择 Application -> Qt Widget Application 

![1579055789551](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955202.png)



#### 2.1.3 项目名称和位置

给项目起个名称以及选中项目要保存的地方

​	![1579055932131](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955203.png)

这一步选择后在Kits 构建套件中直接点击下一步即可



#### 2.1.4 类信息

基类选择 `QWidget`

类名也就是我们第一个窗口场景的名称，这里我起名为 `MainScene` 代表游戏中的主场景

取消创建界面中的内容

![1579056123655](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955204.png)



#### 2.1.5 完成创建

![1579056156582](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955205.png)

在汇总页面中点击完成，我们就迈开了项目的第一步！



## 3 设置主场景

​	

主场景设置的步骤如下：

* 添加配置文件，保存游戏中所有配置数据
* 初始化主场景窗口大小、标题



### 3.1 配置文件添加

* 创建新的头文件为` config.h `主要记录程序中所有的配置数据，方便后期修改

  * 注意使用`CMake`的情况下要在对应`CMakeLists.txt`文件中添加对应文件

    ```C++
    set(PROJECT_SOURCES
            main.cpp
            mainscene.cpp
            mainscene.h
            config.h #游戏标题等主体配置数据
    )
    ```

    

* 添加窗口宽度、高度的配置信息，依据背景图大小进行设置

```C++
#ifndef CONFIG_H
#define CONFIG_H
//游戏配置数据
#define GAME_WIDTH 512 //界面宽度
#define GAME_HEIGHT 768//界面高度
#define GAME_TITLE "飞机大战 v1.0"//标题

#endif // CONFIG_H
```



### 3.2  主场景基本设置

* 在`mainScene.h`中添加新的成员函数`initScene `用来初始化游戏场景
  * Alter+Enter选择添加定义创建对应函数实现

```C++
 void  initScene();
```

* 在`mainScene.cpp`中实现如下代码

```C++
void MainScene::initScene()
{
    //初始化窗口大小
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);
}

```



* 在构造函数`MainScene`中调用该函数` initScene`

```C++
MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    //调用初始化场景函数
    this->initScene();
}

```



测试运行效果如图：

![1578880130909](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955206.png)





## 4 资源导入

在主场景中其实还有一个配置项没有实现，也就是窗口左上角的那个图标资源

那么接下来我们将游戏中的资源进行导入并且设置游戏图标

资源导入步骤

* 生成`qrc`文件
* 项目同级目录下创建res文件夹并将资源粘贴过来
  * 个人将图片和声音放到两个文件夹
  * ![image-20230323215113309](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303262156432.png)
  * ![image-20230323215021119](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303262156434.png)
  * 在`Qt5.15` `CMake`编译下将资源放到两个`qrc`文件下内存不会超，此时4.4-4.6操作不需要
* 编辑`qrc`，加入前缀和文件
  * 在`CMakeLists`中添加文件
* 利用`qrc`生成二进制文件 `rcc`
* `rcc`文件放入到debug同级目录下
* 注册二进制文件
* 添加图标资源



### 4.1 `qrc`文件生成

右键项目，点击添加新文件

![1578880880183](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955207.png)

选择Qt  ->  Qt Resource File

![1578880980265](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955208.png)



资源文件起名 如：res

![1578881130444](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955210.png)

生成`res.qrc`文件

![1578881157321](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955211.png)





### 4.2 创建res文件夹

项目的同级目录下创建文件夹res，并将准备好的资源粘贴进去

![1578881356937](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955212.png)



### 4.3  编辑`qrc`文件

右键`qrc`文件，选中Open in Editor



![1578881449758](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955213.png)



添加前缀为  ''/''

![1578881587795](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955214.png)

添加文件 将res下所有文件选中即可

![1578881673974](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955215.png)



### 4.4 `qrc`生成 `rcc`二进制文件

由于资源过大，会提示错误：

![1578881817399](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955216.png)

这个错误也就是“编译器的堆空间不足”。

由于资源文件`qrc`过大，超出分配的内存范围

因此我们需要利用二进制资源，而生成二进制资源就需要我们刚刚的`qrc`文件

利用`cmd`打开终端，定位到`res.qrc`的目录下，输入命令  

```C++
rcc -binary .\res.qrc -o plane.rcc
```



![1578882121775](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955217.png)







### 4.5 复制rcc文件

将生成好的rcc文件，放入到debug同级目录中一份

![1578883214153](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955218.png)



### 4.6 注册二进制文件

在`config.h`中追加配置数据

```C++
#define GAME_RES_PATH  "./plane.rcc" //rcc文件路径
```



在`main.cpp`中修改代码

```C++
#include "mainscene.h"
#include <QApplication>
#include <QResource>
#include "config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //注册外部的二进制资源文件
    QResource::registerResource(GAME_RES_PATH);

    MainScene w;
    w.show();

    return a.exec();
}
```



此时，`qrc`文件已经没用了，删除即可！

最简单的删除方式就是 .pro工程文件中删除代码,与工程无瓜葛

```C++
删除以下代码：
RESOURCES += \
    res.qrc
```



### 4.7 添加图标资源

配置文件`config.h`中追加代码

虚拟资源路径语法如下： 

> " :  +  前缀名  + 文件路径 "

```C++
#define GAME_ICON ":/res/img/app.ico" //游戏图标
```



在`mainScene.cpp`的 `initScene`函数中追加代码：

```C++
    //设置图标资源
    setWindowIcon(QIcon( GAME_ICON));  //加头文件 #include <QIcon>
```



运行测试：

![1578883495010](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955219.png)





## 5 地图滚动

步骤：

* 创建地图文件和类
* 添加成员函数和成员属性
	 实现成员函数	
* 游戏运行调用定时器
* 启动定时器，监听定时器信号实现游戏循环
  * 计算游戏内元素坐标
  * 绘制到屏幕中



### 5.1 创建地图文件和类

​	右键项目，添加新文件

![1578885212013](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955220.png)

选择C++ ->  C++ Class

![1578885246311](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955221.png)

修改类名为map，点击下一步，直到创建完毕

![1578885297694](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955222.png)

至此，地图Map的文件和类创建完毕



### 5.2 地图的成员函数和成员属性

在`map.h`中添加如下代码

```C++
#ifndef MAP_H
#define MAP_H
#include <QPixmap>//绘图设备
//地图类
class Map{

public:
    //构造函数
    Map();
    //地图滚动坐标计算
    void mapPosition();
public:
    //地图图片对象
    QPixmap map1;
    QPixmap map2;
    //地图Y轴坐标
    int map1_posY;
    int map2_posY;
    //地图滚动幅度
    int map_scroll_speed;

};

#endif // MAP_H
```



### 5.3  实现成员函数

​	在`config.h`中添加新的配置数据

```C++
/**********  地图配置数据 **********/
#define MAP_PATH  ":/res/img_bg_level_1.jpg" //地图图片路径
#define MAP_SCROLL_SPEED 2  //地图滚动速度
```



在`map.cpp`中实现成员函数

```CPP
#include "map.h"
#include "config.h" //配置文件
//构造函数
Map::Map()
{
    //初始化加载地图对象
    map1.load(MAP_PATH);
    map2.load(MAP_PATH);
    //设置地图初始坐标
    map1_posY=-GAME_HEIGHT;
    map2_posY=0;
    //设置地图加载速度
    map_scroll_speed=MAP_SCROLL_SPEED;

}
//地图滚动坐标计算
void Map::mapPosition(){
    //处理第一张图片滚动
    map1_posY+=MAP_SCROLL_SPEED;//向下移动
    if(map1_posY>=0){//如果全部移动到了界面 重置位置
        map1_posY=-GAME_HEIGHT;
    }
     //处理第二张图片滚动
    map2_posY+=MAP_SCROLL_SPE	ED;//向下移动
    if(map2_posY>=GAME_HEIGHT){//如果全部移动到了界面外 重置位置
        map2_posY=0;
    }

}
```



### 5.4 定时器添加

在`mainScene.h`中添加新的定时器对象

```C++
 QTimer m_timer;//定时器用于地图运动
```



在 `config.h`中添加 屏幕刷新间隔

```C++
#define GAME_RATE  10   //刷新间隔，帧率 单位毫秒
```



在`MainScene.cpp`的`initScene`中追加代码

```C++
    //定时器设置
    m_Timer.setIntervalGAME_RATE);
```



### 5.5  启动定时器实现地图滚动



在`MainScene.h`中添加新的成员函数以及成员对象

```C++
    //启动游戏  用于启动定时器对象
    void playGame();
    //更新坐标
    void updatePosition();
    //绘图事件
    void paintEvent(QPaintEvent *event);

		Map map;//地图对象 注意包含头文件
```



在`MainScene.cpp`中实现成员函数

```C++
//启动游戏 用于启动计时器对象
void MainScene::playGame()
{
    //启动定时器
    m_timer.start();

    //监听计时器 用于刷新地图
    connect(&m_timer,&QTimer::timeout,this,[=](){
        //更新游戏中元素的坐标
        updatePosition();
        //重新绘制图片
        update();
    });
}
//更新坐标
void MainScene::updatePosition()
{
    //更新地图坐标
    map.mapPosition();
}

//绘图事件
void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,map.map1_posY,map.map1);
    painter.drawPixmap(0,map.map2_posY,map.map2);
}
```



* 测试运行游戏，实现地图滚动
  * 如果地图滚动有空白，可能图片重置位置不对



## 6 英雄飞机

步骤如下：

* 创建英雄文件和类
* 添加成员函数和成员属性
* 实现成员函数
* 创建飞机对象并显示
* 拖拽飞机

### 6.1 创建英雄文件和类

创建`HeroPlane`类以及生成对应的文件

和创建地图的步骤一样，这里就不在详细截图了

创建好后生成`HeroPlane.h ` 和 `HeroPlane.cpp`两个文件

![1578897213261](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955223.png)



### 6.2 飞机的成员函数和成员属性

在`HeroPlane.h`中添加代码

```C++
#ifndef HEROPLANE_H
#define HEROPLANE_H

#include<QPixmap>
#include<QRect>

class HeroPlane
{
public:
    HeroPlane();
    //发射子弹
    void shoot();
    //设置飞机位置
    void setPosition(int x,int y);
public:
    //飞机资源对象
    QPixmap m_plane;
    //飞机坐标
    int x;
    int y;

    //飞机的矩形边框，用于碰撞检测
    QRect m_rect;
};

#endif // HEROPLANE_H

```



### 6.3 成员函数实现

这里飞机有个发射子弹的成员函数，由于我们还没有做子弹

因此这个成员函数先写成空实现即可



在`config.h`中追加飞机配置参数

```C++
//飞机配置数据
#define HERO_PATH ":/res/img/hero2.png"//英雄飞机
```



`heroPlane.cpp`中实现成员函数代码：

```C++
#include "heroplane.h"
#include "config.h"
HeroPlane::HeroPlane()
{
    //初始化飞机图片资源
    m_plane.load(HERO_PATH);

    //初始化坐标
    x=GAME_WIDTH*0.5-m_plane.width()*0.5;
    y=GAME_HEIGHT-m_plane.height()-20;

    //初始化矩形框
    m_rect.setWidth(m_plane.width());
    m_rect.setHeight(m_plane.height());
    m_rect.moveTo(x,y);
}
//
void HeroPlane::shoot()
{

}

//设置飞机位置，包括碰撞检测框
void HeroPlane::setPosition(int x, int y)
{
    this->x=x;
    this->y=y;
    m_rect.moveTo(x,y);
}

```



### 6.4 创建飞机对象并显示

在`MainScene.h`中追加新的成员属性

```C++
    //飞机对象
    HeroPlane hero;
```



在`MainScene.cpp`的`paintEvent`中追加代码

```C++
//绘制英雄
painter.drawPixmap(hero.x,hero.x,hero.m_Plane);
```



测试飞机显示到屏幕中

![1578899252575](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955224.png)



### 6.5 拖拽飞机

在`MainScene.h` 中添加鼠标移动事件

```C++
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);
```



重写鼠标移动事件

```C++
void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    //记录鼠标坐标
    int x=event->x()-hero.m_rect.width()*0.5;//鼠标位置减去碰撞检测矩形位置的一半
    int y=event->y()-hero.m_rect.height()*0.5;//鼠标位置减去碰撞检测矩形位置的一半

    //边界检测
    if(x<=0){
        x=0;
    }
    if(x>GAME_WIDTH-hero.m_rect.width()){
        x=GAME_WIDTH-hero.m_rect.width();
    }
    if(y<=0){
        y=0;
    }
    if(y>=GAME_HEIGHT-hero.m_rect.height()){
        y=GAME_HEIGHT-hero.m_rect.height();
    }
    hero.setPosition(x,y);
}
```



测试飞机可以拖拽

![1578899706981](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955225.png)



## 7 子弹制作

制作步骤如下：

* 创建子弹文件和类
* 添加子弹类中的成员函数和成员属性
* 实现成员函数
* 测试子弹



### 7.1 创建子弹文件和类

创建Bullet类以及生成对应的文件

创建好后生成`bullet.h ` 和 `bullet.cpp`两个文件

![1578908416427](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955226.png)



### 7.2 子弹的成员函数和成员属性

在`Bullet.h`中添加代码

* 无论是将子弹对象创建在栈区还是在堆区，一直创建过于消耗资源
  * 此处创建一堆子弹在屏幕外，设置为闲置状态，使用时显示出来，在离开屏幕时再次恢复闲置状态

```C++
#ifndef BULLET_H
#define BULLET_H
#include<QPixmap>

class Bullet
{
public:
    Bullet();
    //更新子弹坐标
    void updatePosition();
public:
    QPixmap bullet;//子弹资源对象
    //子弹坐标
    int x;
    int y;
    int speed;//子弹移动速度
    bool free;//子弹是否闲置
    QRect rect;//子弹矩形碰撞检测狂
};

#endif // BULLET_H

```



### 7.3 子弹类成员函数实现

在`config.h`中追加子弹配置信息

```C++
/**********  子弹配置数据 **********/
#define BULLET_PATH ":/res/bullet_11.png"   //子弹图片路径
#define BULLET_SPEED 5  //子弹移动速度
```



在`bullet.cpp`中实现成员函数，代码如下：

```C++
#include "bullet.h"
#include"config.h"//配置文件
Bullet::Bullet()
{
    // 加载子弹资源
    bullet.load(BULLET_PATH);
    //子弹坐标，初始位置可以随意设置，后续会重置
    x=GAME_WIDTH*0.5-bullet.width()*0.5;
    y=GAME_HEIGHT;
    //子弹状态--默认为true;
    free=true;
    //子弹速度
    speed=BULLET_SPEED;

    //子弹矩形框
    rect.setWidth(bullet.width());
    rect.setHeight(bullet.height());
    rect.moveTo(x,y);
}

//更新子弹坐标
void Bullet::updatePosition()
{
    //如果子弹处于闲置状态，不需要进行坐标计算 直接返回
    if(free){
        return;
    }
    //子弹向上移动
    y-=speed;
    rect.moveTo(x,y);
    // //如果在界面外，设置为闲置
    if(y<=-rect.height()){
        free=true;
    }
}

```



### 7.4 测试子弹

子弹本身应该由飞机发射，测试阶段我们写一段辅助代码，看看效果即可

测试过后，这些代码可以删除掉

在`MainScene.h`中添加测试代码

```C++
    //测试子弹代码
    Bullet temp_bullet;
```

在`MainScene.cpp`中的`updatePosition`里添加测试代码

```C++
    //测试子弹代码
    temp_bullet.m_Free = false;
    temp_bullet.updatePosition();
```

在`MainScene.cpp`中的`paintEvent`里添加测试代码

```C++
    //测试子弹代码
    painter.drawPixmap(temp_bullet.m_X,temp_bullet.m_Y,temp_bullet.m_Bullet);
```



运行程序，此时会有一发子弹从屏幕中射出

![1578910452249](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955227.png)



测试完毕后，测试代码删除或注释即可



## 8 玩家发射子弹

玩家发射子弹制作步骤如下：

* 英雄飞机添加新的成员属性
* 实现发射成员函数
* 主场景控制子弹发射



### 8.1 飞机添加新成员属性

在`config.h`中添加新的配置数据

```C++
#define BULLET_NUM 30   //弹匣中子弹数目
#define BULLET_INTERVAL 20//子弹发射间隔
```



在`HeroPlane.h`中新增成员属性如下：

```C++
    //弹匣
    Bullet bullets[BULLET_NUM];
    //发射间隔记录
    int  record;
```



### 8.2  成员函数补充

在构造函数` HeroPlane `中初始化发生间隔记录

```C++
    //初始化发射间隔记录
    recorder = 0;
```



之前在英雄飞机类中预留的一个shoot函数我们进行实现，代码如下：

```C++
//射击实现
void HeroPlane::shoot()
{
    //累计时间间隔记录变量
    record++;
    //判断记录数字，如果没有到达发射间隔，直接return
    if(record<BULLET_INTERVAL){
        return;
    }
    //到达发射时间处理
    //重置发射时间记录
    record=0;
    //发射子弹
    for(int i=0;i<BULLET_NUM;i++){
        //如果是空闲的子弹进行发射
        if(bullets[i].free){
            //将子弹的空闲状态改为假
            bullets[i].free=false;
            //设置发射的子弹坐标
            bullets[i].x=x+m_rect.width()*0.5-10;//飞机位置+飞机宽度一半+初始位置
            bullets[i].y=y-25;
            break;
        }
    }
}
```





### 8.3 主场景中实现发射子弹

在`MainScene.cpp`的`updatePosition`成员函数中追加如下代码

```C++
   //发射子弹
    hero.shoot();
    //计算子弹坐标
    for(int i=0;i<BULLET_NUM;i++){
        //如果子弹为非空闲状态，计算发射位置
        if(!hero.bullets[i].free){
            hero.bullets[i].updatePosition();
        }
    }
```



在`MainScene.cpp`的`paintEvent`成员函数中追加如下代码：

```C++
   //绘制子弹
    for(int i=0;i<BULLET_NUM;i++){
        //如果子弹状态为false计算发射位置
        if(!hero.bullets[i].free){
            painter.drawPixmap(hero.bullets[i].x,hero.bullets[i].y,hero.bullets[i].bullet);
        }
    }
```



测试运行，玩家可以发射子弹

![1578964608240](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955229.png)



## 9 敌机制作

敌机制作与子弹制作原理类似，也是每隔一定的时间让敌机出场

制作步骤如下：

- 创建敌机文件和类
- 添加敌机类中的成员函数和成员属性
- 实现成员函数
- 敌机出场
- 测试敌机



### 9.1 创建敌机文件和类

创`EnemyPlane`类以及生成对应的文件

创建好后生成`enemyPlane.h  `和 `enemyPlane.cpp`两个文件

![1578967018506](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955230.png)



### 9.2 敌机成员函数和成员属性

在`enemyPlane.h`中添加如下代码：

```C++
#ifndef ENERMYPLANE_H
#define ENERMYPLANE_H

#include<QPixmap>
#include<QRect>
class EnermyPlane
{
public:
    EnermyPlane();
    //更新坐标
    void updatePosition();
public:
    //低级资源对象
    QPixmap enermy;
    //位置
    int x;
    int y;

    //敌机的边距检测
    QRect rect;
    //状态，与子弹类似
    bool free;
    //速度
    int speed;
};

#endif // ENERMYPLANE_H

```



### 9.3 敌机成员函数实现



在`config.h`中追加敌机配置信息

```C++
//敌机配置数据
#define ENERMY_PATH ":/res/img/img-plane_6.png" //敌机路径
#define ENERMY_SPEED 5  //敌机飞行速度
#define ENERMY_NUM 20   //敌机总量
#define ENERMY_INTERVAL 30  //敌机出场间隔
```





在`enemyPlane.cpp`中实现成员函数，代码如下：

```C++
#include "enermyplane.h"
#include "config.h"
EnermyPlane::EnermyPlane()
{
    //敌机资源加载
    enermy.load(ENERMY_PATH);
    //敌机位置
    x=0;
    y=0;
    //敌机状态
    free=true;
    //敌机速度
    speed=ENERMY_SPEED;
    //敌机矩形
    rect.setWidth(enermy.width());
    rect.setHeight(enermy.height());
    rect.moveTo(x,y);
}

void EnermyPlane::updatePosition()
{
    //空闲状态不计算坐标
    if(free){
        return;
    }
    y+=speed;
    rect.moveTo(x,y);
    //离开屏幕或者被击毁设置为true
    if(y>=GAME_HEIGHT){
        free=true;
    }
}
```



### 9.4  敌机出场

在`MainScene.h`中追加敌机出场的成员函数

在`MainScene.h`中追加敌机数组 和 敌机出场间隔记录 的成员属性

```C++
    //敌机出现
    void enermyToScene();
    EnermyPlane enermys[ENERMY_NUM];//敌机数组
    int record;//敌机出现间隔
```



初始化间隔记录属性,在`MainScene.cpp`的` initScene `成员函数中追加

```C++
   m_recorder = 0;
```



实现成员函数`enemyToScene `

```C++
//敌机出现
void MainScene::enermyToScene()
{
    record++;
    //如果没到达间隔时间（record*timer.interval) 直接返回
    if(record<ENERMY_INTERVAL){
        return;
    }
    //到达重置间隔
    record=0;
    //敌机出现
    for(int i=0;i<ENERMY_NUM;i++){
        if(enermys[i].free){//如果为空闲
            //敌机的空闲状态改为false
            enermys[i].free=false;
            //设置坐标
            enermys[i].x=rand()%(GAME_WIDTH-enermys[i].rect.width());
            enermys[i].y=-enermys[i].rect.height();
            break;
        }

    }

}
```



在`PlayGame`成员函数的timeout信号发送时候，槽函数中首先追加`enemyToScene `

```C++
        //敌机出场
        enemyToScene();
```

![1578970348979](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955231.png)



更新敌机坐标，在`updatePosition`成员函数中追加代码

```C++
    //计算敌机坐标
    for(int i=0;i<ENERMY_NUM;i++){
        if(enermys[i].free==false){
            enermys[i].updatePosition();
        }
    }
```



绘制敌机，在`paintEvent`成员函数中追加绘制敌机代码

```C++
    //绘制敌机
    for(int i=0;i<ENERMY_NUM;i++){
        if(!enermys[i].free){
            painter.drawPixmap(enermys[i].x,enermys[i].y,enermys[i].enermy);
        }
    }
```



添加随机数种子

在`MainScene.cpp`中 `initScene `成员函数里添加随机数种子

```C++
    //随机数种子
    srand((unsigned int)time(NULL));  //头文件  #include <ctime>
```



运行测试敌机出场效果

![1578972273502](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955232.png)





## 10 碰撞检测

实现碰撞检测步骤如下：

* 添加并实现碰撞检测成员函数
* 调用并测试函数



### 10.1 添加并实现碰撞检测函数

在`MainScene.h`中添加新的成员函数  

```C++
void collisionDetection();
```



在`MainScene.cpp`中实现该成员函数

```C++
//碰撞检测
void MainScene::collisionDetection()
{
    //实现方式，遍历所有飞机和子弹，如果发生碰撞，释放为free
    //遍历所有非空闲飞机
    for(int i=0;i<ENERMY_NUM;i++){
        if(enermys[i].free){
            //空闲飞机进入下一次循环
            continue;
        }
        //遍历所有非空闲的子弹
        for(int j=0;j<BULLET_NUM;j++){
            if(hero.bullets[j].free){
                continue;
            }
            //如果相交，发生碰撞 同时变为空闲状态
            if(enermys[i].rect.intersects(hero.bullets[j].rect)){
                enermys[i].free=true;
                hero.bullets[j].free=true;
            }
        }
    }
}
```

  

### 10.2 调用并测试函数

在`MainScene.cpp`中 `playGame`成员函数里，追加碰撞检测代码

![1578982679306](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955233.png)

运行查看效果，子弹和敌机碰撞后会同时消失



## 11 爆炸效果

爆炸效果功能实现步骤如下：

* 创建爆炸文件和类
* 添加爆炸类中的成员函数和成员属性
* 实现成员函数
* 调用并测试效果



### 11.1 创建爆炸文件和类

创建Bomb类以及生成对应的文件

创建好后生成`bomb.h  `和 `bomb.cpp`两个文件

![1578983159726](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955234.png)

### 11.2 爆炸成员函数和成员属性

在`config.h`中加入爆炸配置数据

```C++
#define BOMB_PATH  ":/res/bomb-%1.png"   //爆炸资源图片
#define BOMB_NUM  20     //爆炸数量
#define BOMB_MAX  7      //爆炸图片最大索引
#define BOMB_INTERVAL 20   //爆炸切图时间间隔
```



在`bomb.h`中添加如下代码：

```C++
#ifndef BOMB_H
#define BOMB_H
#include <QPixmap>
#include<QVector>

class Bomb
{
public:
    Bomb();
    //更新信息
    void updateInfo();
public:
    //爆炸资源数组
    QVector<QPixmap> pix;
    //爆炸位置
    int x;
    int y;
    //爆炸状态
    bool free;
    //爆炸切图的时间间隔
    int record;
    //爆炸时加载图片的下标
    int index;
};


#endif // BOMB_H

```



### 11.3 实现成员函数

```C++
#include "bomb.h"
#include "config.h"
Bomb::Bomb()
{
    //初始化爆炸图片数组
    for(int i=0;i<BOMB_NUM;i++){
        pix.push_back(QPixmap(QString(BOMB_PATH).arg(i)));
    }
    //初始化坐标
    x=0;
    y=0;
    //初始化空闲状态
    free=true;
    //当前播放图片下标
    index=0;
    //爆炸间隔记录
    record=0;
}
//爆炸信息
void Bomb::updateInfo()
{
    //空闲状态
    if(free){
        return;
    }
    record++;
    if(record<BOMB_INTERVAL){
        //爆炸时间间隔没到返回
        return;
    }
    //重置状态
    record=0;
    //切换爆炸播放图
    index++;
    //图片播放完毕，重置下标
    if(index>BOMB_MAX-1){
        index=0;
        free=true;
    }

}

```



### 11.4 加入爆炸数组

在`MainScene.h`中加入爆炸数组 成员属性

```C++
    //爆炸数组
    Bomb m_bombs[BOMB_NUM];
```



在碰撞检测成员函数中，当发生碰撞时，设置爆炸对象的信息

```C++
                //播放爆炸效果
                for(int k=0;k<BOMB_NUM;k++){
                    if(bombs[k].free){
                        //爆炸状态设置为非空闲
                        bombs[k].free=false;
                        //更新坐标
                        bombs[k].x=enermys[i].x;
                        bombs[k].y=enermys[i].y;
                        break;
                    }
                }
```







在 `MainScene.cpp`的**`updatePosition`**中追加代码

```C++
 //计算爆炸坐标
    for(int i=0;i<BOMB_NUM;i++){
        if(bombs[i].free==false){
            bombs[i].updateInfo();
        }
    }
```



在 `MainScene.cpp`的**`paintEvent`** 中追加绘制爆炸代码

```C++
  //绘制爆炸图片
    for(int i=0;i<BOMB_NUM;i++){
        if(bombs[i].free==false){
            painter.drawPixmap(bombs[i].x,bombs[i].y,bombs[i].pix[bombs[i].index]);
        }
    }
```



测试，实现爆炸效果

![1578989134611](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955235.png)





## 12 音效添加

音效添加步骤如下：

* 添加多媒体模块
* 播放音效



### 12.1 添加多媒体模块

在工程文件`planeWar.pro `中修改代码

```C++
QT  += core gui multimedia
```

![1578989320903](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303231955236.png)

**CMake方式**

* 在配置文件中修改添加

  * ​	找到对应版本包

  * 链接包和项目

  * 当前版本   **`Qt5.15 ` `cmake VERSION 3.5`**

  * ```cmake
    #添加包Qt5::Multimedia
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets  Multimedia)
    
    #添加引用链接Qt5::Multimedia
    target_link_libraries(00PlaneWar PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt5::Multimedia)
    
    ```

    



### 12.2 播放音效

在`config.h`中 添加音效的配置路径

```C++
//音效配置
#define SOUND_BACKGROUND ":/res/sounds/bg.wav"//背景音乐
#define SOUND_BOMB ":/res/sounds/bomb.wav"//爆炸音乐
```



> 注： `QSound`使用时候要包含头文件` #include \<QSound>`



在`PlayGame`中添加背景音乐

```C++
    //启动背景音乐
    QSound::play(SOUND_BACKGROUND);
```

![image-20230326212959243](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303262156435.png)

在爆炸时候添加爆炸音效

```C++
	//播放音效
	QSound::play(SOUND_BOMB);
```

![image-20230326212928890](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202303262156436.png)

测试音效





## 13 打包发布

1. 程序先修改为`release`版本

2. 完成之后先运行

3. 到项目的release版本`build`文件复制exe程序到任意空文件夹中中运行cmd程序

   * 低版本要找到Qt自带的命令行工具运行

   * 并且切换到对应文件目录下

   * 示例  文件名`9_TurnOverGame.exe`

     ```C++
     C:\Users\yangc\Desktop\conin>windeployqt 9_TurnOverGame.exe
     ```

4. 使用HM NIS Edit将上述文件打包成安装包[教程实例](https://blog.csdn.net/zhichaosong/article/details/106275151)

   * 编译中如果有错误记得删除报错行再次编译
   * 不要有中文路径或者名称，会报错

5. 启动 HM NIS EDIT 软件，在软件中选择: 文件->新建脚本向导， 接下来跟着向导操作.

6. 为了让安装包安装软件也有快捷方式图标，在生成的脚本里。进行修改：

   ```c
   CreateShortCut "$DESKTOP\飞机大战.lnk" "$INSTDIR\PlaneWar.exe"
   CreateShortCut "$DESKTOP\飞机大战.lnk" "$INSTDIR\PlaneWar.exe" "" "$INSTDIR\app.ico"
   ```

7. 点击菜单栏的 `NSIS` ，然后选择编译，在桌面生成安装包.





至此本案例实现完毕！



> Qt以及打包软件的 安装包 
>
> 链接：https://pan.baidu.com/s/19Vcxv1oAIDk2Ool-9bWfDg 
> 提取码：6kmf