#include "interFace.hpp"
#include <qdebug.h>

interFace::interFace(QWidget *parent)
    : QMainWindow(parent)
{
  
  b1.setText("<");
  b2.setText(">");
  hblt2.addWidget(&b1);
  for (int i = 0; i < 5; i++)
  {
    QLabel *l1 = new QLabel();
    switch_labels.push_back(l1);
    l1->setText(QString::number(i+1));
    hblt2.addWidget(l1);
  }
  hblt2.addWidget(&b2);
  switch_frame.setLayout(&hblt2);

  vblt1.addWidget(&m_lable1);
  vblt1.addWidget(&m_bt1);

  vblt2.addWidget(&m_lable2);
  vblt2.addWidget(&m_bt2);

  vblt4.addWidget(&m_combbx_lable);
  vblt4.addWidget(&m_comboBx);

  vblt5.addWidget(&m_refrashLb);
  vblt5.addWidget(&m_refrashBt);

  hblt1.addLayout(&vblt1);
  hblt1.addLayout(&vblt2);
  hblt1.addLayout(&vblt4);
  hblt1.addLayout(&vblt5);

  m_frame1.setLayout(&hblt1);

  vblt3.addWidget(&switch_frame);
  vblt3.addWidget(&m_table);
  vblt3.addWidget(&m_frame1);

 

  m_bt1.setText("插入");
  m_bt2.setText("连接数据库");
  m_lable1.setText("xxxxxxx");
  m_lable2.setText("ssssss");
  m_combbx_lable.setText("选择表");
  // m_refrashLb.setText("刷新数据");
  m_refrashBt.setText("刷新数据");

  m_frame.setLayout(&vblt3);

  this->setCentralWidget(&m_frame);

  connect(&m_bt1, SIGNAL(clicked()), this, SLOT(insert_data()));
  connect(&m_bt2, SIGNAL(clicked()), this, SLOT(connect_to_database()));
  connect(&m_refrashBt, SIGNAL(clicked()), this, SLOT(refresh_data()));


  m_model.setHorizontalHeaderLabels({"id", "name", "password", "email"});

  m_table.setModel(&m_model);
  m_table.resizeColumnsToContents();
  // m_table.resizeRowsToContents();
  m_table.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  m_table.setShowGrid(true); // 显示网格线
}

interFace::~interFace()
{
  for (int i = 0; i < switch_labels.size();i++){
    if(switch_labels[i] == nullptr){
      delete switch_labels[i];
      switch_labels[i] = nullptr;
    }
    
  }
}

void interFace::connect_to_database()
{

  QDialog dlg;
  dlg.setWindowTitle("登陆");

  QFormLayout form(&dlg);

  dlg.setLayout(&form);

  QLabel lb1, lb2, lb3, lb4, lb5;
  QLineEdit ld1, ld2, ld3, ld4, ld5;

  lb1.setText("ip");
  lb2.setText("name");
  lb3.setText("password");
  lb4.setText("databaseName");
  lb5.setText("port");

  ld1.setText("localhost");
  ld2.setText("hansolo");
  ld3.setText("*******");
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

  connect(&qdgbx, &QDialogButtonBox::rejected, &dlg, &QDialog::reject);

  dlg.adjustSize();
  dlg.setMinimumSize(200, 100);

  while (dlg.exec() == QDialog::Accepted)
  {
    if (!m_db.connect(ld1.text().toStdString(), ld2.text().toStdString(), ld3.text().toStdString(), ld4.text().toStdString(), ld4.text().toInt()))
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
  
  if(m_first_init){

    auto table_names = m_db.getTablesStrings();
    if(table_names.size()<=0){
      return;
    }
    m_first_init = false;
    m_comboBx.clear();
    for (int i = 0; i < table_names.size(); i++)
    {
      m_comboBx.addItem(QString::fromStdString(table_names[i]));
    }
    if (m_comboBx.currentIndex() < 0)
    {
      return;
    }
  }

  m_table_name = m_comboBx.currentText();

  qDebug() << m_table_name;

  auto re = m_db.query(m_table_name.toStdString(),0,25);
  m_model.clear();

  QStringList headerLables;
  auto stringlabels = m_db.getTableFieldStrings(m_table_name.toStdString());
  for (int i = 0; i < stringlabels.size();i++){
    headerLables.append(QString::fromStdString(stringlabels[i]));
  }

  m_model.setHorizontalHeaderLabels(headerLables);
  for (int i = 0; i < re.size(); i++)
  {
    QList<QStandardItem *> lst;
    for (int j = 0; j < re[i].size(); j++)
    {
      lst.push_back(new QStandardItem(QString::fromStdString(re[i][j])));
    }
    m_model.appendRow(lst);
  }
  m_table.setModel(&m_model);
}

void interFace::insert_data()
{
  if (!m_db.checkState())
  {
    QMessageBox::warning(nullptr, "警告", "请先登陆");
    return;
  }

  QDialog dlg;
  dlg.setWindowTitle("插入数据");
  QFormLayout form(&dlg);

  dlg.setLayout(&form);

  QLabel lb1, lb2, lb3, lb4,lb1_check,lb2_check,lb3_check, lb4_check;

  lb1_check.setStyleSheet(QString("background-color: rgba(0, 244, 0);"));
  lb2_check.setStyleSheet(QString("background-color: rgba(0, 244, 0);"));
  lb3_check.setStyleSheet(QString("background-color: rgba(0, 244, 0);"));
  lb4_check.setStyleSheet(QString("background-color: rgba(0, 244, 0);"));

  QLineEdit ld1, ld2, ld3, ld4;
  QHBoxLayout h1, h2, h3, h4;

  lb1.setText("id");
  lb2.setText("name");
  lb3.setText("password");
  lb4.setText("email");

  

  h1.addWidget(&lb1);
  h1.addWidget(&ld1);
  h1.addWidget(&lb1_check);

  h2.addWidget(&lb2);
  h2.addWidget(&ld2);
  h2.addWidget(&lb2_check);

  h3.addWidget(&lb3);
  h3.addWidget(&ld3);
  h3.addWidget(&lb3_check);

  h4.addWidget(&lb4);
  h4.addWidget(&ld4);
  h4.addWidget(&lb4_check);
  

  form.addRow(&h1);
  form.addRow(&h2);
  form.addRow(&h3);  
  form.addRow(&h4);

  const char *id_esp = "^[0-9]*$";
  const char *name_esp = "^[a-zA-Z][a-zA-Z0-9]*$";
  const char *name_chs_esp = "^[\u4e00-\u9fa5]*$";
  const char *email_esp = "[a-zA-Z0-9._%+-]+@[a-zA-Z0-9]+\\.[a-zA-Z]{2,}";
  const char *passwd_esp = "^[a-zA-Z0-9][a-zA-Z0-9._!@#$%&]*$";
  
  std::regex id_rgx(id_esp);
  std::regex name_rgx(name_esp);
  std::regex name_rgx_chs(name_chs_esp);
  std::regex email_rgx(email_esp);
  std::regex passwd_rgx(passwd_esp);

  bool ld1_state = true;
  bool ld2_state = true;
  bool ld3_state = true;
  bool ld4_state = true;

  connect(&ld1, &QLineEdit::textChanged, this,
          [&]()
          {
            if (!std::regex_search(ld1.text().toStdString(), id_rgx))
            {
              // qDebug() << "wrong passwd syntex";
              ld1_state = false;
              lb1_check.setStyleSheet(QString("background-color: rgb(255, 0, 0);"));
            }
            else
            {
              ld1_state = true;
              lb1_check.setStyleSheet(QString("background-color: rgb(0, 255, 0);"));
            }
          });
  connect(&ld2, &QLineEdit::textChanged, this,
          [&]()
          { 
             if(!std::regex_search(ld2.text().toStdString(), name_rgx) &&!std::regex_search(ld2.text().toStdString(),name_rgx_chs))
             {
              //  qDebug() << "wrong passwd syntex";
               ld2_state = false;
               lb2_check.setStyleSheet(QString("background-color: rgb(255, 0, 0);"));
             } 
             else{
              ld2_state = true;
              lb2_check.setStyleSheet(QString("background-color: rgb(0, 255, 0);"));
             }
          });

  connect(&ld3, &QLineEdit::textChanged, this,
          [&]()
          { 
             if(!std::regex_search(ld3.text().toStdString(), passwd_rgx))
             {
              ld3_state = false;
              //  qDebug() << "wrong passwd syntex";
               lb3_check.setStyleSheet(QString("background-color: rgb(255, 0, 0);"));
             } 
             else{
              ld3_state = true;
              lb3_check.setStyleSheet(QString("background-color: rgb(0, 255, 0);"));
             }
          });
  connect(&ld4, &QLineEdit::textChanged, this,
          [&]()
          { 
             if(!std::regex_search(ld4.text().toStdString(), email_rgx))
             {
              ld4_state = false;
              //  qDebug() << "wrong email syntex";
               lb4_check.setStyleSheet(QString("background-color: rgb(255, 0, 0);"));
             } 
             else{
              ld4_state = true;
              lb4_check.setStyleSheet(QString("background-color: rgb(0, 255, 0);"));
             }
          });
  

  QDialogButtonBox qdgbx(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dlg);

  form.addRow(&qdgbx);

  connect(&qdgbx, &QDialogButtonBox::accepted, &dlg, &QDialog::accept);

  connect(&qdgbx, &QDialogButtonBox::rejected, &dlg, &QDialog::reject);

  while (dlg.exec() == QDialog::Accepted)
  {
    int id = ld1.text().toInt();
    std::string user_name = ld2.text().toStdString();
    std::string passwd = ld3.text().toStdString();
    std::string email = ld4.text().toStdString();

    if( !(ld1_state&&ld2_state&&ld3_state&&ld4_state)){
      QMessageBox::warning(nullptr, "警告", "输入有误");
      continue;
    }
    else{
      std::string order = "INSERT INTO user VALUES (" + std::to_string(id) + ",'" + user_name + "', '" + passwd + "' , '" + email + "')"; 

      qDebug() <<QString::fromStdString(order) ;
      if(!m_db.implement(order))
      {
        QMessageBox::warning(nullptr, "警告", "保存时发生错误");
      }
      else{
        refresh_data();
      }
      return;
    }
  }
}