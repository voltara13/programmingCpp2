#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	const metadata data("data.txt");
    add_menu_item(data.head_list);
}

void MainWindow::add_menu_item(metaheadList *ptr, QMenu *menu) const
{
	if (ptr->item.get_status() != 2)
	{
        if (ptr->sub_next)
        {
            auto* const new_menu = new QMenu(ptr->item.get_name());
            new_menu->setEnabled(ptr->item.get_status() != 1);
            add_menu_item(ptr->sub_next, new_menu);
        	
            if (menu) 
                menu->addMenu(new_menu);
            else 
                menuBar()->addMenu(new_menu);
        }
        else
        {
            if (menu) 
                add_menu_action(menu, ptr->item);
            else 
                add_menu_action(menuBar(), ptr->item);
        }
	}
	if (ptr->next)
        add_menu_item(ptr->next, menu);
}

void MainWindow::add_menu_action(QWidget* menu, const metahead& item) const
{
	const auto name = item.get_name();
	const auto name_method = item.get_name_method();
    const char* member = nullptr;
    auto* const new_action = new QAction(name);
	
    if (item.get_status()) 
        new_action->setEnabled(false);

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

    connect(new_action, SIGNAL(triggered()), this, member);
	
    menu->addAction(new_action);
}

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