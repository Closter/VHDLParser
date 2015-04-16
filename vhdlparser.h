#ifndef VHDLPARSER_H
#define VHDLPARSER_H

#include "Parser/abstractparser.h"
#include "Elements/vp_word.h"

#include "Context/contextfilevhdl.h"



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

  bool isVHDLKeyword(Word *w);

  int nbWordsToSkipComments();


  static QList<QString> m_specialCharVHDL;  ///< The string list of special character
  static QList<QString> m_keywordList;      ///< VHDL Keywords

  QList<VP_Word*> m_wordList;

  // VHDL structure management
  //--------------------------
  ContextFileVHDL *m_fileContext;

  //--------------------------

};

#endif // VHDLPARSER_H
