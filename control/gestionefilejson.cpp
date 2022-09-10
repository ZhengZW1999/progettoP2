#include "gestionefilejson.h"

QJsonDocument* gestioneFileJSon::getJSONFileModelData(const QString& path){
    if(path.isNull()){return new QJsonDocument(); }

    QString fileData;
    QFile file;

    file.setFileName(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    fileData = file.readAll();
    file.close();

    //Controllo validità documento
    QJsonDocument* doc = new QJsonDocument(QJsonDocument::fromJson(fileData.toLocal8Bit()));
    QJsonObject dataObj = doc->object();
    if(!dataObj.contains("Dati dei modelli") || !dataObj.contains("Modelli") || !dataObj.contains("Tessuti")){
        delete doc;
        return new QJsonDocument();
    }
    return doc;
}

QString gestioneFileJSon::selectJSONFileDialog(){
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter("JSON File (*.json)");
    QString fileName;
    if (dialog.exec())
        fileName = dialog.selectedFiles().at(0);
    return fileName;
}

QJsonDocument *gestioneFileJSon::getJSONFileVenditeData(const QString &path)
{
    if(path.isNull()) return new QJsonDocument();

    QString fileData;
    QFile file;

    file.setFileName(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    fileData = file.readAll();
    file.close();

    //Controllo validità documento
    QJsonDocument* doc = new QJsonDocument(QJsonDocument::fromJson(fileData.toLocal8Bit()));
    QJsonObject dataObj = doc->object();
    if(!dataObj.contains("Dati delle vendite")){
        delete doc;
        return new QJsonDocument();
    }
    return doc;
}

QStringList* gestioneFileJSon::getModellList(QJsonDocument* data){
    QStringList* listaModelli = new QStringList;
    QJsonObject dataObj = data->object();
    QJsonArray materialiArray = dataObj["Modelli"].toArray();
    for(const QJsonValue& value : materialiArray) {
        listaModelli->append(value.toString());
    }
    return listaModelli;
}

QStringList *gestioneFileJSon::getTessutiList(QJsonDocument *data)
{
    QStringList* listaTessuti = new QStringList;
    QJsonObject dataObj = data->object();
    QJsonArray materialiArray = dataObj["Tessuti"].toArray();
    for(const QJsonValue& value : materialiArray) {
        listaTessuti->append(value.toString());
    }
    return listaTessuti;
}

std::list<datiModelli*> gestioneFileJSon::getDM(QJsonDocument* data){
    std::list<datiModelli*> lista;
    QJsonObject dataObj = data->object();
    QJsonArray records = dataObj["Dati dei modelli"].toArray();
    for(const QJsonValue& record : records){
        datiModelli* dm = new datiModelli(
                record.toObject().value("Materiale").toString(),
                record.toObject().value("Tessuto").toString(),
                record.toObject().value("Quantita' Tessuto Usato").toInt(),
                record.toObject().value("Costo Tessuto Per MQ").toInt(),
                record.toObject().value("Costo Base").toInt(),
                record.toObject().value("Costo Lavaggio").toInt(),
                record.toObject().value("Prezzo Vendita").toInt(),
                record.toObject().value("Produzione Giornaliera").toInt());
        lista.push_back(dm);
    }
    return lista;
}

std::list<datiVendite *> gestioneFileJSon::getDV(QJsonDocument *data)
{
    std::list<datiVendite*> lista;
    QJsonObject dataObj = data->object();
    QJsonArray records = dataObj["Dati delle vendite"].toArray();
    for(const QJsonValue& record : records){
        datiVendite* dv = new datiVendite(
                record.toObject().value("Pezzi Prodotti").toInt(),
                record.toObject().value("Pezzi Venduti").toInt(),
                QDate::fromString(record.toObject().value("Mese").toString(),"dd/MM/yyyy"));
        lista.push_back(dv);
    }
    return lista;
}

bool gestioneFileJSon::saveAdminModel(const QJsonDocument& doc, const QString& path){
    if(path.isNull() || path.isEmpty()) return false;
    QFile file(path);
    if(file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate)){
        file.write(doc.toJson());
        file.close();
        return true;
    }
    return false;
}


