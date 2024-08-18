#include<QtWidgets/QtWidgets>

#include<QPushButton>
#include<QLabel>
#include<QListView>
#include<QFrame>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QDialogButtonBox>
#include<QMessageBox>

#include<QTableView>
#include<QStandardItemModel>


#include"mysqlDataBase.hpp"



class interFace : public QMainWindow
{
Q_OBJECT
public:
  interFace(QWidget *parent=nullptr);
  ~interFace();

private:
  DataBase m_db;

  QFrame m_frame;
  QFrame m_frame1;

  QTableView m_table;
  QStandardItemModel m_model;

  QLabel m_lable1;
  QLabel m_lable2;

  QPushButton m_bt1;
  QPushButton m_bt2;

  QListView m_listv1;
  QListView m_listv2;
  
  QHBoxLayout hblt1;
  QVBoxLayout vblt1;
  QVBoxLayout vblt2;
  QVBoxLayout vblt3;

private:
  void refresh_data();
private slots:
  void connect_to_database();
};