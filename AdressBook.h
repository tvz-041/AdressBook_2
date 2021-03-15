#ifndef ADRESSBOOK_H
#define ADRESSBOOK_H

#include <QMainWindow>

#include "Entry.h"

class QStringListModel;

class AdressBookEntry;

namespace Ui {
	class AdressBook;
}

class AdressBook : public QMainWindow
{
	Q_OBJECT

public:
	explicit AdressBook(QWidget *parent = nullptr);
	~AdressBook();

public slots:
	void addEntry();
	void removeCurrentEntry();

private:
	Ui::AdressBook *ui;

	AdressBookEntry *m_entryEditWidget = nullptr;

	QStringListModel *m_model = nullptr;
	QList<Entry> m_entries;
};

#endif // ADRESSBOOK_H
