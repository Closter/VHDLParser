#include "vhdlparser.h"

#define VP_VHDL_SX_SEP_CAR_COMMENTARY         "--"
#define VP_VHDL_SX_SEP_CAR_DOT                "."
#define VP_VHDL_SX_SEP_CAR_COLON              ":"
#define VP_VHDL_SX_SEP_CAR_SEMICOLON          ";"
#define VP_VHDL_SX_SEP_CAR_COMMA              ","
#define VP_VHDL_SX_SEP_CAR_SIGNAL_ASSIGNEMENT "<="
#define VP_VHDL_SX_SEP_CAR_VAR_ASSIGNEMENT    ":="
#define VP_VHDL_SX_SEP_CAR_PORT_ASSIGNEMENT   "=>"
#define VP_VHDL_SX_SEP_CAR_OPEN_BRACKET       "("
#define VP_VHDL_SX_SEP_CAR_CLOSE_BRACKET      ")"
#define VP_VHDL_SX_SEP_CAR_COMPARE_EQUAL      "="
#define VP_VHDL_SX_SEP_CAR_COMPARE_UNEQUAL    "/="
#define VP_VHDL_SX_SEP_CAR_COMPARE_MORE       ">"
#define VP_VHDL_SX_SEP_CAR_COMPARE_LESS       "<"
#define VP_VHDL_SX_SEP_CAR_COMPARE_MORE_EQUAL ">="
#define VP_VHDL_SX_SEP_CAR_COMPARE_EQUAL_LESS "=<"
#define VP_VHDL_SX_SEP_CAR_OPERATOR_PLUS      "+"
#define VP_VHDL_SX_SEP_CAR_OPERATOR_MINUS     "-"
#define VP_VHDL_SX_SEP_CAR_OPERATOR_MULTIPLY  "*"
#define VP_VHDL_SX_SEP_CAR_OPERATOR_DIVIDE    "/"
#define VP_VHDL_SX_SEP_CAR_OPERATOR_EXPO      "**"
#define VP_VHDL_SX_SEP_CAR_OPERATOR_CONCAT    "&"


// list of keyword
QList<QString> VHDLParser::m_specialChar = QList<QString>()
    << VP_VHDL_SX_SEP_CAR_COMMENTARY        
    << VP_VHDL_SX_SEP_CAR_DOT               
    << VP_VHDL_SX_SEP_CAR_COLON             
    << VP_VHDL_SX_SEP_CAR_SEMICOLON         
    << VP_VHDL_SX_SEP_CAR_COMMA             
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
    << VP_VHDL_SX_SEP_CAR_OPERATOR_CONCAT;


VHDLParser::VHDLParser(QObject *parent) :
  AbstractParser(parent)
{
  // Construct the list of keyword
  foreach(QString str, m_specialChar)
    addKeyWord(str);

  addLineCommentId(VP_VHDL_SX_SEP_CAR_COMMENTARY);

}



/**
 * @brief VHDLParser::parse Parse a string as a VHDL structure
 * @param strToParse  String to parse
 */
void VHDLParser::parse(QString strToParse)
{
  // Extract the word list from this string
  m_wordList = AbstractParser::parse(strToParse);

  // Look for libraries
  //-------------------
  m_libraryList = lookForLibrarys();
  //-------------------

}


/**
 * @brief VHDLParser::lookForLibrarys Search for all library declared in the word list
 * @return Teh list of founded library
 */
QList<VP_Library *> VHDLParser::lookForLibrarys()
{
  QList<VP_Library*> libList;

  QList<Word*> libKeyWordList = lookForWords(VP_LIBRARY_LIB_KEYWORD); // Start to look for library declaration
  QList<Word*> useKeyWordList = lookForWords(VP_LIBRARY_USE_KEYWORD); // And look for use declaration

  // Create a list of library string name
  //-------------------------------------
  QList<QString> libStrList;

  foreach(Word *lib, libKeyWordList)
  {
    if(lib->nextWord() != NULL)
      libStrList << lib->nextWord()->getText();  // The library name is the word after "Library" keyword
  }
  //-------------------------------------

  // Create a list of library use name
  //----------------------------------
  QList<QString> useStrList;

  foreach(Word *use, useKeyWordList)
  {
    // Check for correct use formation
    if(use->nextWord(VP_LIBRARY_USE_ENDLINE_IX) != NULL)  // Enough word
    {
      if((use->nextWord(VP_LIBRARY_USE_DOT1_IX)->getText() == VP_VHDL_SX_SEP_CAR_DOT) &&  // First dot detected
         (use->nextWord(VP_LIBRARY_USE_DOT2_IX)->getText() == VP_VHDL_SX_SEP_CAR_DOT) &&  // second dot detected
         (use->nextWord(VP_LIBRARY_USE_ENDLINE_IX)->getText() == VP_VHDL_SX_SEP_CAR_SEMICOLON)) // End of line detected
      {
        useStrList << use->nextWord(VP_LIBRARY_USE_LIB_WORD_IX)->getText(); // The library name is the word after "use" keyword
      }
    }
  }
  //----------------------------------

  // Each use declaration should refere to a library declaration
  foreach(QString use, useStrList)
  {
    foreach(QString lib, libStrList)
    {
      if(use.compare(lib, Qt::CaseInsensitive) == 0)  // The use declaration refers to the library declaration
      {
        // Get index of each element
        int ixOfLib = libStrList.indexOf(lib);
        int ixOfUse = useStrList.indexOf(use);
        Word *libWord = libKeyWordList[ixOfLib]->nextWord();
        Word *useWord = useKeyWordList[ixOfUse];

        // Create corresponding library and add to the lib list
        libList << new VP_Library(QPoint(libWord->getLine(), libWord->getColumn()),
                                  QPoint(useWord->nextWord(VP_LIBRARY_USE_LIB_WORD_IX)->getLine(), useWord->nextWord(VP_LIBRARY_USE_LIB_WORD_IX)->getColumn()),
                                  useWord->nextWord(VP_LIBRARY_USE_LIB_WORD_IX)->getText(),
                                  useWord->nextWord(VP_LIBRARY_USE_PKG_WORD_IX)->getText(),
                                  useWord->nextWord(VP_LIBRARY_USE_PKG_USE_IX)->getText());
      }
    }
  }

  return libList;
}




/**
 * @brief VHDLParser::lookForWords Search the word wordToFind in the existing list of word.
 * The search is unsensitive to the case.
 * @param wordToFind The word to find
 * @param lookInComments True to look into comments, otherwise False;
 * @return A list of pointer to the words founded in the list
 */
QList<Word *> VHDLParser::lookForWords(QString wordToFind, bool lookInComments)
{
  QList<Word *> list;

  foreach(Word *w, m_wordList)
  {
    bool lookAtThisWord = true;
    if(!lookInComments && w->isComment())  // Don't look in comment
      lookAtThisWord = false;

    if((w->getText().compare(wordToFind, Qt::CaseInsensitive) == 0) && // What we are looking for
       lookAtThisWord)  // Should we look at it ?
    {
      list.append(w);
    }
  }

  return list;

}


