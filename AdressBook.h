#ifndef ADRESSBOOK_H
#define ADRESSBOOK_H

#include <QMainWindow>

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

private:
	Ui::AdressBook *ui;

	AdressBookEntry *m_entryEditWidget = nullptr;
};

#endif // ADRESSBOOK_H
