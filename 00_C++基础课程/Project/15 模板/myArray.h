#ifndef MYARRAY
#define MYARRAY
/*
* 可以对内置数据类型以及自定义数据类型的数据进行存储 T 
* 将数组中的数据存储到堆区  T *
* 构造函数中可以传入数组的容量  capacity
* 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
* 提供尾插法和尾删法对数组中的数据进行增加和删除
* 可以通过下标的方式访问数组中的元素	重载	[]
* 可以获取数组中当前元素个数和数组的容量 size  
*/

//自定义数组类
template<class T>
class MyArray {
public:
	//构造函数
	MyArray(int capacity);
	//拷贝构造
	MyArray(const MyArray& arr);
	//重载=操作符 防止浅拷贝
	MyArray& operator=(const MyArray& arr);
	//重载[] 返回数据 防止越界
	T& operator[](int index);
	//尾插法
	void pushBack(const T&t);
	//尾删法
	void popBack();
	//获取数组容量
	int getCapacity();
	//获取数组大小
	int getSize();
	//析构
	~MyArray();
private:
	T* address;//指向存储数据的真实空间
	int capacity;//容量
	int size;//当前大小
};
#endif