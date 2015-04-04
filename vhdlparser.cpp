#include "vhdlparser.h"


// list of keyword
QList<QString> VHDLParser::m_specialChar = QList<QString>() << QString("First");
//    << "--" <<"."   <<":"   <<";"   <<","   <<"<="  <<":="  <<"=>" <<"("
//    << ")"  << "="  << "/=" << ">"  << "<"  << ">=" << "=<" << "+"
//    << "-"  << "*"  << "/"  << "**" << "&";


VHDLParser::VHDLParser(QObject *parent) :
  AbstractParser(parent)
{
  // Construct the list of keyword
  foreach(QString str, m_specialChar)
    addKeyWord(str);

}



