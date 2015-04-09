#ifndef VHDLPARSER_H
#define VHDLPARSER_H

#include "Parser/abstractparser.h"
#include "Elements/vp_word.h"

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


  // Structure accessors
  //--------------------
  QList<VP_Library*> getLibraryList()
  {
    return m_libraryList;
  }

  //--------------------


private:

  QList<VP_Library*> lookForLibrarys();


  QList<Word*> lookForWords(QString wordToFind, bool lookInComments = false);
  bool isVHDLKeyword(Word *w);

  int nbWordsToSkipComments();


  static QList<QString> m_specialCharVHDL;  ///< The string list of special character
  static QList<QString> m_keywordList;      ///< VHDL Keywords

  QList<VP_Word*> m_wordList;

  // VHDL structure management
  //--------------------------
  QList<VP_Library*> m_libraryList;

  //--------------------------

};

#endif // VHDLPARSER_H
