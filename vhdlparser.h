#ifndef VHDLPARSER_H
#define VHDLPARSER_H

#include "Parser/abstractparser.h"
#include "Parser/word.h"

#include "Elements/vp_library.h"



#define VP_VHDL_SX_SEP_CAR_REGEXP       "(\\-\\-|\\.|:|;|,|<=|:=|=>|\\(|\\)|=|/=|>|<|>=|=<|\\+|\\-|\\*|/|\\*\\*|&)"
#define VP_VHDL_SX_SEP_CAR_1CAR_REGEXP  "(\\.|:|;|,|\\(|\\)|=|>|<|\\+|\\-|\\*|/|&)"
#define VP_VHDL_SX_SEP_CAR_2CAR_REGEXP  "(\\-\\-|<=|:=|=>|/=|>=|=<|\\*\\*)"




/**
 * @brief The VHDLParser class contains a VHDL module's structural representation.
 *
 */
class VHDLParser : public AbstractParser
{
  Q_OBJECT
public:

  explicit VHDLParser(QObject *parent = 0);

  void parse(QString strToParse);


private:

  QList<Word*> lookForWords(QString wordToFind);

  QList<VP_Library*> lookForLibrarys();


  static QList<QString> m_specialChar; ///< The string list of special character

  QList<Word*> m_wordList;

};

#endif // VHDLPARSER_H
