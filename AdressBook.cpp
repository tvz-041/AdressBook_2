#include <QDebug>
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
	connect(ui->listView->selectionModel(), &QItemSelectionModel::currentChanged, this, &AdressBook::loadCurrentEntry);
	connect(m_entryEditWidget, &AdressBookEntry::propertiesChanged, this, &AdressBook::saveCurrentEntry);
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
	QModelIndex current = ui->listView->currentIndex();

	if (current.isValid()) {
		m_model->removeRow(current.row());
		m_entries.removeAt(current.row());
	}
}

void AdressBook::loadCurrentEntry(const QModelIndex &current)
{
	if (current.isValid()) {
		m_entryEditWidget->fromEntry(m_entries[current.row()]);
	}
}

void AdressBook::saveCurrentEntry(const Entry &entry)
{
	QModelIndex current = ui->listView->currentIndex();

	if (current.isValid()) {
		m_model->setData(current, entry.fullName());
		m_entries[current.row()] = entry;
	}
}
