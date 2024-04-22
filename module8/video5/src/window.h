#pragma once
 
#include <QWidget>
 
class Window : public QWidget {
    
  protected:
    void keyPressEvent(QKeyEvent * e);
    
  public:
    Window(QWidget *parent = 0);
};