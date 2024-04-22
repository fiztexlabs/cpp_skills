#include <QDebug>
#include <QFileInfo>
#include <QDateTime>
#include <conio.h>
 
int main(int argc, char *argv[]) {

  if (argc != 2) {
      qWarning("Usage: file_times file");
      return 1;
  }
 
  QString filename = argv[1];
 
  // Создаем объект класса QFileInfo. В качестве параметра используем имя файла из аргумента командной строки
  QFileInfo fileinfo(filename);
 
  // Определяем дату и время последнего чтения файла
  QDateTime last_rea = fileinfo.lastRead();
 
  // Определяем дату и время последнего изменения файла
  QDateTime last_mod = fileinfo.lastModified();
 
  qInfo() << "Last read: " << last_rea.toString() << Qt::endl;
  qInfo() << "Last modified: " << last_mod.toString() << Qt::endl;
}