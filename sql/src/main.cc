#include"interFace.hpp"


int main(int argc,char **argv)
{
  QApplication a{argc,argv};

  interFace iface;

  iface.resize(800, 600);

  iface.show();

  return a.exec();
}