#include "metadata.h"
//Конструктор мета-объекта
metadata::metadata(QString file_name) : file_name_(std::move(file_name))
{
    read_heads_file(); //Считываем пункты из файла
}
//Функция добавления пункта в список пунктов
void metadata::add_head(const QString& buffer)
{
	const metahead head(buffer);
    head_list = metaheadList::add(head, head_list);
}
//Функция считывания пунктов из файла
void metadata::read_heads_file()
{
    QString buffer;
    const QString path = ":/" + file_name_;
    QFile file(path);
    //Если файл открылся, то считываем данные
    if (file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QTextStream buffer_stream(&file);
        while (!buffer_stream.atEnd())
            add_head(buffer_stream.readLine());
        //Закрываем файл
        file.close();
    }
}
