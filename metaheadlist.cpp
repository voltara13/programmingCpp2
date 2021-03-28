#include "metaheadlist.h"
//Конструктор элемента дерева каталога
metaheadList::metaheadList(metahead item) : item(std::move(item)) {}
//Функция добавления элемента в дерево каталога
metaheadList* metaheadList::add(const metahead& item, metaheadList *head)
{
	//Создаём новый элемент дерева каталога
	metaheadList* const new_item = new metaheadList(item);
	//Создаём вспомогательный указатель
	metaheadList* ptr = head;
	//Если "голова" дерева каталога указывает на nullptr, то возвращаем новый элемент
	if (head == nullptr) return new_item;
	//Обходим всё дерево
    while (true)
    {
    	//Идём в конец уровня
        while (ptr->next) ptr = ptr->next;
    	//Если новый пункт меню ниже данного пункта меню, то спускаемся вниз
        if (new_item->item.get_num_level() > ptr->item.get_num_level())
        {
        	//Если существует дочерняя ветка, то переходим к ней
            if (ptr->sub_next) ptr = ptr->sub_next;
        	//Иначе создаём новую дочернюю ветку
            else
            {
                new_item->parent = ptr;
                ptr->sub_next = new_item;
                break;
            }    
        }
    	//Иначе добавляем новый элемент в конец ветки
        else
        {
            ptr->next = new_item;
            break;
        }
    }
	//Возвращаем голову дерева каталога
    return head;
}
