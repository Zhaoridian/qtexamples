#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(2);
    addRoot("root", "one");
    addRoot("root", "two");
    addRoot("root", "three");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::addRoot(QString name, QString description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0, name);
    itm->setText(1, description);
//    ui->treeWidget->addTopLevelItem(itm);
    addChild(itm, "child", "one");
    addChild(itm, "child", "two");
}

void Dialog::addChild(QTreeWidgetItem *parent, QString name, QString description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0, name);
    itm->setText(1, description);
    parent->addChild(itm);
}
