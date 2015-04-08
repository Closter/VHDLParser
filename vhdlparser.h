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

  int nbWordsToSkipComments();


  static QList<QString> m_specialChar; ///< The string list of special character

  QList<Word*> m_wordList;

  // VHDL structure management
  //--------------------------
  QList<VP_Library*> m_libraryList;

  //--------------------------

};

#endif // VHDLPARSER_H
