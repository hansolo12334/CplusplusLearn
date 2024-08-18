#include"interFace.hpp"
#include<qdebug.h>


interFace::interFace(QWidget *parent)
 :QMainWindow(parent)
{

  vblt1.addWidget(&m_lable1);
  vblt1.addWidget(&m_bt1);

  vblt2.addWidget(&m_lable2);
  vblt2.addWidget(&m_bt2);

  
  hblt1.addLayout(&vblt1);
  hblt1.addLayout(&vblt2);

  
  m_frame1.setLayout(&hblt1);

  vblt3.addWidget(&m_table);
  vblt3.addWidget(&m_frame1);

  m_bt1.setText("插入");
  m_bt2.setText("连接数据库");
  m_lable1.setText("xxxxxxx");
  m_lable2.setText("ssssss");

  m_frame.setLayout(&vblt3);

  this->setCentralWidget(&m_frame);

  connect(&m_bt2, SIGNAL(clicked()), this, SLOT(connect_to_database()));

  m_model.setHorizontalHeaderLabels({"id", "name", "password", "email"});

  m_table.setModel(&m_model);
  m_table.resizeColumnsToContents();
  // m_table.resizeRowsToContents();
  m_table.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  m_table.setShowGrid(true); // 显示网格线
}

interFace::~interFace()
{

}

void interFace::connect_to_database()
{
  qDebug() << "111";
  QDialog dlg;
  dlg.setWindowTitle("登陆");

  QFormLayout form(&dlg);

  dlg.setLayout(&form);

  QLabel lb1, lb2, lb3, lb4,lb5;
  QLineEdit ld1, ld2, ld3, ld4,ld5;

  lb1.setText("ip");
  lb2.setText("name");
  lb3.setText("password");
  lb4.setText("databaseName");
  lb5.setText("port");

  ld1.setText("localhost");
  ld2.setText("hansolo");
  ld3.setText("********");
  ld4.setText("database_hansolo");
  ld5.setText("3306");

  ld3.setEchoMode(QLineEdit::Password);

  form.addRow(&lb1, &ld1);
  form.addRow(&lb2, &ld2);
  form.addRow(&lb3, &ld3);
  form.addRow(&lb4, &ld4);
  form.addRow(&lb5, &ld5);

  

  QDialogButtonBox qdgbx(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dlg);

  form.addRow(&qdgbx);

  connect(&qdgbx, &QDialogButtonBox::accepted, &dlg, &QDialog::accept);

  connect(&qdgbx, &QDialogButtonBox::rejected,  &dlg, &QDialog::reject);

  dlg.adjustSize();
  dlg.setMinimumSize(200, 100);


  while(dlg.exec() == QDialog::Accepted)
  {
    if(!m_db.connect(ld1.text().toStdString(), ld2.text().toStdString(), ld3.text().toStdString(), ld4.text().toStdString(), ld4.text().toInt())) 
    {
      QMessageBox::warning(&dlg, "警告", "填写错误");
    }
    else
    {
      QMessageBox::warning(&dlg, "提示", "登陆成功");
      refresh_data();
      return;
    }
  }
  return;
}

void interFace::refresh_data()
{
  
  auto re=m_db.query("user");
  for (int i = 0; i < re.size();i++)
  {
    QList<QStandardItem* > lst;
    for (int j = 0; j < re[i].size();j++)
    {
      lst.push_back(new QStandardItem(QString::fromStdString(re[i][j])));
    }
    m_model.appendRow(lst);
  }
  m_table.setModel(&m_model);
}