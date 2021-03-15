#include <QModelIndex>
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

	connect(ui->pushButton_add, &QPushButton::clicked, this, &AdressBook::addEntry);
	connect(ui->pushButton_remove, &QPushButton::clicked, this, &AdressBook::removeCurrentEntry);
}

AdressBook::~AdressBook()
{
	delete ui;
}

//public slots:

void AdressBook::addEntry()
{
	Entry entry;
	entry.firstName = "Имя";
	entry.secondName = "Фамилия";

	m_model->insertRow(m_entries.count());
	m_model->setData(m_model->index(m_entries.count()), entry.fullName());

	m_entries.append(entry);
}

void AdressBook::removeCurrentEntry()
{
	QModelIndex currentIndex = ui->listView->currentIndex();

	if (currentIndex.isValid()) {
		m_model->removeRow(currentIndex.row());
		m_entries.removeAt(currentIndex.row());
	}
}
