#include "vhdlparser.h"

#include "VHDL_Syntaxe.h"


// list of keyword
QList<QString> VHDLParser::m_specialCharVHDL = QList<QString>()
    << VP_VHDL_SX_SEP_CAR_COMMENTARY        
    << VP_VHDL_SX_SEP_CAR_SIGNAL_ASSIGNEMENT
    << VP_VHDL_SX_SEP_CAR_VAR_ASSIGNEMENT   
    << VP_VHDL_SX_SEP_CAR_PORT_ASSIGNEMENT  
    << VP_VHDL_SX_SEP_CAR_OPEN_BRACKET      
    << VP_VHDL_SX_SEP_CAR_CLOSE_BRACKET     
    << VP_VHDL_SX_SEP_CAR_COMPARE_EQUAL     
    << VP_VHDL_SX_SEP_CAR_COMPARE_UNEQUAL   
    << VP_VHDL_SX_SEP_CAR_COMPARE_MORE      
    << VP_VHDL_SX_SEP_CAR_COMPARE_LESS      
    << VP_VHDL_SX_SEP_CAR_COMPARE_MORE_EQUAL
    << VP_VHDL_SX_SEP_CAR_COMPARE_EQUAL_LESS
    << VP_VHDL_SX_SEP_CAR_OPERATOR_PLUS     
    << VP_VHDL_SX_SEP_CAR_OPERATOR_MINUS    
    << VP_VHDL_SX_SEP_CAR_OPERATOR_MULTIPLY 
    << VP_VHDL_SX_SEP_CAR_OPERATOR_DIVIDE   
    << VP_VHDL_SX_SEP_CAR_OPERATOR_EXPO     
    << VP_VHDL_SX_SEP_CAR_OPERATOR_CONCAT
    << VP_VHDL_SX_SEP_CAR_DOT
    << VP_VHDL_SX_SEP_CAR_COLON
    << VP_VHDL_SX_SEP_CAR_SEMICOLON
    << VP_VHDL_SX_SEP_CAR_COMMA;

QList<QString> VHDLParser::m_keywordList = QList<QString>()
    << VP_VHDL_SX_KEYWORD_LIBRARY
    << VP_VHDL_SX_KEYWORD_USE
    << VP_VHDL_SX_KEYWORD_ALL
    << VP_VHDL_SX_KEYWORD_ENTITY
    << VP_VHDL_SX_KEYWORD_PACKAGE
    << VP_VHDL_SX_KEYWORD_BODY
    << VP_VHDL_SX_KEYWORD_IS
    << VP_VHDL_SX_KEYWORD_END
    << VP_VHDL_SX_KEYWORD_IN
    << VP_VHDL_SX_KEYWORD_OUT
    << VP_VHDL_SX_KEYWORD_INOUT
    << VP_VHDL_SX_KEYWORD_TO
    << VP_VHDL_SX_KEYWORD_DOWNTO
    << VP_VHDL_SX_KEYWORD_ARCHITECTURE
    << VP_VHDL_SX_KEYWORD_OF
    << VP_VHDL_SX_KEYWORD_COMPONENT
    << VP_VHDL_SX_KEYWORD_GENERIC
    << VP_VHDL_SX_KEYWORD_PORT
    << VP_VHDL_SX_KEYWORD_MAP
    << VP_VHDL_SX_KEYWORD_CONSTANT
    << VP_VHDL_SX_KEYWORD_TYPE
    << VP_VHDL_SX_KEYWORD_ARRAY
    << VP_VHDL_SX_KEYWORD_SIGNAL
    << VP_VHDL_SX_KEYWORD_ALIAS
    << VP_VHDL_SX_KEYWORD_BEGIN;







VHDLParser::VHDLParser(QObject *parent) :
  AbstractParser(parent)
{
  // Construct the list of keyword
  foreach(QString str, m_specialCharVHDL)
    addKeyWord(str);

  addLineCommentId(VP_VHDL_SX_SEP_CAR_COMMENTARY);

  m_fileContext = NULL;

}



/**
 * @brief VHDLParser::parse Parse a string as a VHDL structure
 * @param strToParse  String to parse
 */
void VHDLParser::parse(QString strToParse)
{
  // Extract the word list from this string
  QList<Word*> wordList = AbstractParser::parse(strToParse);

  // Create the list of VHDL words
  //------------------------------
  m_wordList.clear();
  foreach(Word *w, wordList)
  {
    VP_Word *lastWord;
    if(m_wordList.count() == 0) // No word in this list
      lastWord = NULL;
    else
      lastWord = m_wordList.last();

    VP_Word *newWord = new VP_Word(w->getText(),
                                   w->getLine(),
                                   w->getColumn(),
                                   isVHDLKeyword(w),
                                   w->isEOL(),
                                   w->isComment(),
                                   lastWord);
    if(lastWord != NULL)  // Already at least one word
      m_wordList.last()->setNextWord(newWord);  // Construct the chained list

    m_wordList << newWord;
  }
  //------------------------------

  // Reinitialize
  delete m_fileContext;

  // Start content analyzis by context
  //----------------------------------
  m_fileContext = new ContextFileVHDL(this);
  m_fileContext->analyze(m_wordList.first());
  //----------------------------------

}


/**
 * @brief VHDLParser::isVHDLKeyword
 * @param w The word to analyze
 * @return True if this word is a VHDL Keyword.
 */
bool VHDLParser::isVHDLKeyword(Word *w)
{
  foreach(QString k, m_keywordList) // All VHDL keyword
  {
    if(w->getText().compare(k, Qt::CaseInsensitive) == 0) // Cas insensitive compare
      return true;  // Is a keyword
  }

  return false; // Not a keyword
}
