#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include "AdressBookEntry.h"

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

	AdressBookEntry entry;

	entry.fromJson(loadJsonFromFile("AdressBookEntry.json"));
	QObject::connect(&entry, &AdressBookEntry::propertiesChanged, &saveAdressBookEntryPropertiesToFile);

	entry.show();

	return a.exec();
}
