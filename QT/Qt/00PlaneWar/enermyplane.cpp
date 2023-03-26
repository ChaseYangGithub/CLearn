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
