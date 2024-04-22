#include <QPushButton>
#include <QApplication>
#include <QHBoxLayout>
#include <QKeyEvent>
#include "window.h"

void Window::keyPressEvent(QKeyEvent *e)
{
   if (e->key() == Qt::Key_Escape) {  
       qApp->quit();
   } 
}

Window::Window(QWidget *parent)
    : QWidget(parent)
{

    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->setSpacing(5);

    QPushButton *quitBtn = new QPushButton("Quit", this);
    hbox->addWidget(quitBtn, 0, Qt::AlignLeft | Qt::AlignTop);

    connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
}