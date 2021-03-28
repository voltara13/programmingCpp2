#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "metadata.h"

#include <QMainWindow>
#include <QMenuBar>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
private:
    Q_OBJECT
    QMessageBox msg_box_; //Диалоговое окно, которое показывает какой метод вызвался
    void add_menu_item(metaheadList*, QMenu* menu = nullptr) const;
    void add_menu_action(QWidget*, const metahead&) const;

public:
    MainWindow(QWidget* parent = nullptr);

public slots:
    void slot_file();
    void slot_save();
    void slot_load();
    void slot_save_as();
    void slot_about();
    void slot_help();
};
#endif // MAINWINDOW_H
