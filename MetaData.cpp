#include "metadata.h"

metadata::metadata(const QString& file_name) : file_name_(file_name)
{
    read_heads_file();
}

void metadata::add_head(QString buffer)
{
	const metahead head(buffer);
    head_list = metaheadList::add(head, head_list);
}

void metadata::read_heads_file()
{
    QString buffer;
    const QString path = ":/" + file_name_;
    QFile file(path);

    if (file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QTextStream buffer_stream(&file);
        while (!buffer_stream.atEnd())
            add_head(buffer_stream.readLine());
    }

    file.close();
}
