#include "metaheadlist.h"
//����������� �������� ������ ��������
metaheadList::metaheadList(metahead item) : item(std::move(item)) {}
//������� ���������� �������� � ������ ��������
metaheadList* metaheadList::add(const metahead& item, metaheadList *head)
{
	//������ ����� ������� ������ ��������
	metaheadList* const new_item = new metaheadList(item);
	//������ ��������������� ���������
	metaheadList* ptr = head;
	//���� "������" ������ �������� ��������� �� nullptr, �� ���������� ����� �������
	if (head == nullptr) return new_item;
	//������� �� ������
    while (true)
    {
    	//��� � ����� ������
        while (ptr->next) ptr = ptr->next;
    	//���� ����� ����� ���� ���� ������� ������ ����, �� ���������� ����
        if (new_item->item.get_num_level() > ptr->item.get_num_level())
        {
        	//���� ���������� �������� �����, �� ��������� � ���
            if (ptr->sub_next) ptr = ptr->sub_next;
        	//����� ������ ����� �������� �����
            else
            {
                new_item->parent = ptr;
                ptr->sub_next = new_item;
                break;
            }    
        }
    	//����� ��������� ����� ������� � ����� �����
        else
        {
            ptr->next = new_item;
            break;
        }
    }
	//���������� ������ ������ ��������
    return head;
}
