#include "contextlibrary.h"



ContextLibrary::ContextLibrary(QObject *parent):
  AbstractContext(parent)
{
  m_contextKeywordList << VP_VHDL_SX_KEYWORD_LIBRARY
                       << VP_VHDL_SX_KEYWORD_USE
                       << VP_VHDL_SX_KEYWORD_ALL;
}


/**
 * @brief ContextLibDeclaration::analyze
 * @param firstWord Pointer to the first word to analyze
 */
VP_Word* ContextLibrary::analyze(VP_Word *firstWord)
{
  m_library.clear();

  // Find list of library declaration
  QList<VP_Word*> libKeyWordList = lookForWords(firstWord, VP_VHDL_SX_KEYWORD_LIBRARY);
  QList<VP_Word*> useKeyWordList = lookForWords(firstWord, VP_VHDL_SX_KEYWORD_USE);

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
        m_library << new VP_Library(QPoint(libWord->getLine(), libWord->getColumn()),
                                    QPoint(useWord->nextWord(VP_LIBRARY_USE_LIB_WORD_IX)->getLine(), useWord->nextWord(VP_LIBRARY_USE_LIB_WORD_IX)->getColumn()),
                                    useWord->nextWord(VP_LIBRARY_USE_LIB_WORD_IX)->getText(),
                                    useWord->nextWord(VP_LIBRARY_USE_PKG_WORD_IX)->getText(),
                                    useWord->nextWord(VP_LIBRARY_USE_PKG_USE_IX)->getText());
      }
    }
  }


  // Search the first word out of this context
  VP_Word *nextContextFirstWord = lastWordOfThisContext(firstWord)->nextWord();

  return nextContextFirstWord;
}
