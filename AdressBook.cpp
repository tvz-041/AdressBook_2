#include <QStringListModel>

#include "AdressBookEntry.h"

#include "AdressBook.h"
#include "ui_AdressBook.h"

AdressBook::AdressBook(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::AdressBook)
{
	ui->setupUi(this);

	m_entryEditWidget = new AdressBookEntry(this);
	ui->centralwidget->layout()->addWidget(m_entryEditWidget);

	m_model = new QStringListModel(this);
	ui->listView->setModel(m_model);
}

AdressBook::~AdressBook()
{
	delete ui;
}
