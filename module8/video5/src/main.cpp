#include <QApplication>
#include "window.h"
 
int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Window mywindow;
  
  mywindow.resize(250, 150);
  mywindow.setWindowTitle("Click");
  mywindow.show();
 
  return app.exec();
}