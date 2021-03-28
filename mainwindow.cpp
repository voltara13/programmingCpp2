#include "mainwindow.h"
//Конструктор главного окна
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    metadata data; //Создаём мета-объект
    add_menu_item(data.head_list); //Создаём меню
}
//Рекурсивная функция создания меню
void MainWindow::add_menu_item(metaheadList *ptr, QMenu *menu) const
{
    //Если статус пункта меню не равен двум, то меню будет видно
	if (ptr->item.get_status() != 2)
	{
        //Если существует подпункт меню, то проходим по подпунктам
        if (ptr->sub_next)
        {
            //Так как у данного пункта существуют подпункты, то данный пункт есть подменю или меню
            auto* const new_menu = new QMenu(ptr->item.get_name());
            new_menu->setEnabled(ptr->item.get_status() != 1);
            add_menu_item(ptr->sub_next, new_menu);
            //Если данный пункт есть подменю, то он добавляется как пункт своего меню-родителя
            if (menu) 
                menu->addMenu(new_menu);
            //Иначе он добавляется в главное меню всего окна
            else 
                menuBar()->addMenu(new_menu);
        }
        //Иначе добавляем данный пункт в меню
        else
        {
            //Если данный пункт есть подпункт, то он добавляется как пункт своего меню-родителя
            if (menu) 
                add_menu_action(menu, ptr->item);
            //Иначе он добавляется в главное меню всего окна
            else 
                add_menu_action(menuBar(), ptr->item);
        }
	}
    //Если следующий пункт существует, то рекурсивно переходим ко следующему пункту
	if (ptr->next)
        add_menu_item(ptr->next, menu);
}
//Функция связывания метода с пунктом меню
void MainWindow::add_menu_action(QWidget* menu, const metahead& item) const
{
    //Создаём пункт меню
	const auto name = item.get_name();
	const auto name_method = item.get_name_method();
    const char* member = nullptr;
    auto* const new_action = new QAction(name);
    //Если статус пункта не равен нулю, то пункт не доступен
    if (item.get_status()) 
        new_action->setEnabled(false);
    //Связываем имя метода с самим методом
    if (name_method == "slot_file")
        member = SLOT(slot_file());
    else if (name_method == "slot_save")
        member = SLOT(slot_save());
    else if (name_method == "slot_load")
        member = SLOT(slot_load());
    else if (name_method == "slot_save_as")
        member = SLOT(slot_save_as());
    else if (name_method == "slot_about")
        member = SLOT(slot_about());
    else if (name_method == "slot_help")
        member = SLOT(slot_help());
    //Связываем пункт меню с методом
    connect(new_action, SIGNAL(triggered()), this, member);
    //Добавляем пункт в меню
    menu->addAction(new_action);
}

//Методы пунктов

void MainWindow::slot_file()
{
    msg_box_.setText("Вызван метод 'slot_file'");
    msg_box_.exec();
}

void MainWindow::slot_save()
{
    msg_box_.setText("Вызван метод 'slot_save'");
    msg_box_.exec();
}

void MainWindow::slot_load()
{
    msg_box_.setText("Вызван метод 'slot_load'");
    msg_box_.exec();
}

void MainWindow::slot_save_as()
{
    msg_box_.setText("Вызван метод 'slot_save_as'");
    msg_box_.exec();
}

void MainWindow::slot_about()
{
    msg_box_.setText("Вызван метод 'slot_about'");
    msg_box_.exec();
}

void MainWindow::slot_help()
{
    msg_box_.setText("Вызван метод 'slot_help'");
    msg_box_.exec();
}
