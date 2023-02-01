#include<iostream>
using namespace std;
//�������﷨��
//virtual ~����() {}
//���������﷨��
//virtual ~����() = 0; 
//����::~����() {}


class Animal {
public:
	Animal() {
		cout << "Animal���캯������" << endl;
	}
	virtual void speak() = 0;

	//������������virtual�ؼ��֣��������������
	//virtual ~Animal()
	//{
	//	cout << "Animal�������������ã�" << endl;


	virtual ~Animal() = 0;
};
//��������ʵ�֣�����Ҫ��
Animal::~Animal() {
	cout << "Animal�������������ã�" << endl;
}
//�Ͱ�����ͨ���麯������һ���������˴���������������Ҳ��һ�������ࡣ���ܹ���ʵ������
class Cat : public Animal {
public:
	Cat(string name){
		cout << "Cat���캯�����ã�" << endl;
		m_Name = new string(name);
	}
	virtual void speak(){
		cout << *m_Name << "Сè��˵��!" << endl;
	}
	~Cat(){
		cout << "Cat������������!" << endl;
		if (this->m_Name != NULL) {
			delete m_Name;
			m_Name = NULL;
		}
	}
public:
	string* m_Name;
};

void test75()
{
	Animal* animal = new Cat("Tom");
	animal->speak(); 
	//ͨ������ָ��ȥ�ͷţ��ᵼ�����������������ɾ�������ڴ�й©
	//��ô���������������һ������������
	//���������������������ͨ������ָ���ͷ��������
	delete animal;
}

