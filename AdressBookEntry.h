#ifndef ADRESSBOOKENTRY_H
#define ADRESSBOOKENTRY_H

#include <QWidget>

struct Entry;

QT_BEGIN_NAMESPACE
namespace Ui { class AdressBookEntry; }
QT_END_NAMESPACE

class AdressBookEntry : public QWidget
{
	Q_OBJECT

public:
	AdressBookEntry(QWidget *parent = nullptr);
	~AdressBookEntry();

	void fromEntry(const Entry &entry);
	Entry toEntry() const;

	void fromJson(const QJsonObject &properties);
	QJsonObject toJson() const;

signals:
	void propertiesChanged(const Entry &entry);

public slots:
	void save();

private slots:
	void markUnsavedChanges();

private:
	Ui::AdressBookEntry *ui;
	bool m_hasUnsavedChanges;
};
#endif // ADRESSBOOKENTRY_H
