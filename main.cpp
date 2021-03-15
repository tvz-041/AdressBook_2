#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include "AdressBook.h"

void saveJsonToFile(const QString &filename, const QJsonObject &json)
{
	QFile file(filename);

	if (file.open(QFile::WriteOnly)) {
		QJsonDocument document(json);
		file.write(document.toJson());
		file.close();
	}
}

QJsonObject loadJsonFromFile(const QString &filename)
{
	QJsonObject json;
	QFile file(filename);

	if (file.open(QFile::ReadOnly)) {
		QJsonDocument document = QJsonDocument::fromJson(file.readAll());
		json = document.object();
		file.close();
	}

	return json;
}

void saveAdressBookEntryPropertiesToFile(const QJsonObject &properties)
{
	saveJsonToFile("AdressBookEntry.json", properties);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	AdressBook adressBook;
	adressBook.show();

	return a.exec();
}
