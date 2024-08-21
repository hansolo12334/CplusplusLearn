#include<QtWidgets/QtWidgets>

#include<QPushButton>
#include<QLabel>
#include<QListView>
#include<QFrame>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QDialogButtonBox>
#include<QMessageBox>

#include<QComboBox>
#include<QTableView>
#include<QStandardItemModel>


#include<regex>

#include"mysqlDataBase.hpp"



class interFace : public QMainWindow
{
Q_OBJECT
public:
  interFace(QWidget *parent=nullptr);
  ~interFace();

private:
  DataBase m_db;

  QString m_table_name;

  QFrame m_frame;
  QFrame m_frame1;
  QFrame switch_frame;

  QTableView m_table;
  QStandardItemModel m_model;

  QLabel m_lable1;
  QLabel m_lable2;

  QPushButton m_bt1;
  QPushButton m_bt2;

  QComboBox m_comboBx;
  QLabel m_combbx_lable;

  QPushButton m_refrashBt;
  QLabel m_refrashLb;

  QListView m_listv1;
  QListView m_listv2;
  
  QHBoxLayout hblt1;
  QHBoxLayout hblt2;

  QVBoxLayout vblt1;
  QVBoxLayout vblt2;
  QVBoxLayout vblt3;
  QVBoxLayout vblt4;
  QVBoxLayout vblt5;

  QPushButton b1;
  QPushButton b2;
  
  QVector<QLabel *> switch_labels;
  bool m_first_init = true;
  // private:
  // void refresh_data();
private slots:
  void refresh_data();
  void connect_to_database();
  void insert_data();
};