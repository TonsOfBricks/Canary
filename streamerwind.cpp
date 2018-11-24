#include "streamerwind.h"
#include "ui_streamerwind.h"
#include "canarygui.h"

#include <iostream>
#include <QString>
#include <mysql_connection.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

using namespace std;
using namespace sql;

streamerwind::streamerwind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::streamerwind)
{
    ui->setupUi(this);
    this->setWindowTitle("Canary");
    ui->user_name->setText("Welcome, " + name_return + " " + "[" + status_return + "]");
}

streamerwind::~streamerwind()
{
    delete ui;
}
