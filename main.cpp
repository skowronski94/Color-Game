#include <QApplication>
#include <cstdlib>
#include <ctime>
#include "window.h"

int main(int argc, char **argv)
{
 srand(time(NULL));
 QApplication app (argc, argv);

 Window window;
 window.show();

 return app.exec();
}


