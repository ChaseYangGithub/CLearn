#ifndef MYARRAY
#define MYARRAY
/*
* ���Զ��������������Լ��Զ����������͵����ݽ��д洢 T 
* �������е����ݴ洢������  T *
* ���캯���п��Դ������������  capacity
* �ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
* �ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
* ����ͨ���±�ķ�ʽ���������е�Ԫ��	����	[]
* ���Ի�ȡ�����е�ǰԪ�ظ�������������� size  
*/

//�Զ���������
template<class T>
class MyArray {
public:
	//���캯��
	MyArray(int capacity);
	//��������
	MyArray(const MyArray& arr);
	//����=������ ��ֹǳ����
	MyArray& operator=(const MyArray& arr);
	//����[] �������� ��ֹԽ��
	T& operator[](int index);
	//β�巨
	void pushBack(const T&t);
	//βɾ��
	void popBack();
	//��ȡ��������
	int getCapacity();
	//��ȡ�����С
	int getSize();
	//����
	~MyArray();
private:
	T* address;//ָ��洢���ݵ���ʵ�ռ�
	int capacity;//����
	int size;//��ǰ��С
};
#endif