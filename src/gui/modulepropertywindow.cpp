#include <iostream>
#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "modulepropertywindow.h"

ModulePropertyDialog::ModulePropertyDialog(QWidget* parent, Module* modl) : QDialog(parent)
{
    module = modl;

    nameLabel = new QLabel("Module Name");
    nameEdit = new QLineEdit(module->name().c_str());
    nameLabel->setBuddy(nameEdit);

    saveButton = new QPushButton("Save");
    cancelButton = new QPushButton("Cancel");

    connect(cancelButton, SIGNAL(clicked()),this, SLOT(close()));
    connect(saveButton, SIGNAL(clicked()),this, SLOT(saveData()));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(cancelButton);

    QHBoxLayout *nameLayout = new QHBoxLayout;
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(nameEdit);

    QVBoxLayout *portsLayout = new QVBoxLayout;
    QLabel* portsLabel = new QLabel("Ports");
    portsLayout->addWidget(portsLabel);
    Module::PortCollection ports = module->ports();
    foreach (Port p, ports) {
        QLabel* port = new QLabel(p.name().c_str());
        portsLayout->addWidget(port);
    }

    QVBoxLayout *netsLayout = new QVBoxLayout;
    QLabel* netsLabel = new QLabel("Nets");
    netsLayout->addWidget(netsLabel);
//    Module::NetCollection nets = module->nets();
//    foreach (Net n, nets) {
//        QLabel* netName = new QLabel(n.name().c_str());
//        netsLayout->addWidget(netName);
//    }

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(nameLayout);
    mainLayout->addLayout(portsLayout);
    mainLayout->addLayout(netsLayout);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    setWindowTitle("Module Properties");
}

void
ModulePropertyDialog::saveData()
{
    QString name = nameEdit->text();

    close();
}