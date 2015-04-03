#include "vhdlparser.h"

#include <QFileInfo>


VHDLParser::VHDLParser(QObject *parent) :
  QObject(parent)
{
}

/**
 * @brief VHDLParser::analyzeFile Analyze a VHDL file to extract module's structure
 * @param file Pointer to an existing file to analyze
 * @return True if analyze goes on, else False
 */
bool VHDLParser::analyzeFile(QFile *file)
{
  // Does the file exists
  if(!file->exists())
  {
    qDebug("%s file does not exists", file->fileName().toStdString().c_str());
    return false;
  }

  // Read all file
  //--------------
  if(file->open(QIODevice::ReadOnly | QIODevice::Text))
    return false;

  QByteArray fileContent = file->readAll();

  file->close();
  //--------------

  return true;
}
