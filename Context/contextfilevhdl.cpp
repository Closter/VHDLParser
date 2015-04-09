#include "contextfilevhdl.h"

#include "VHDL_Syntaxe.h"

#include "Context/contextarchitecture.h"
#include "Context/contextentitydeclaration.h"
#include "Context/contextlibdeclaration.h"
#include "Context/contextlibuse.h"
#include "Context/contextpackagebody.h"
#include "Context/contextpackagedeclaration.h"


QList<QString> ContextFileVHDL::m_keywordList = QList<QString>()
    << VP_VHDL_SX_KEYWORD_LIBRARY
    << VP_VHDL_SX_KEYWORD_USE
    << VP_VHDL_SX_KEYWORD_ENTITY
    << VP_VHDL_SX_KEYWORD_PACKAGE
    << VP_VHDL_SX_KEYWORD_BODY
    << VP_VHDL_SX_KEYWORD_ARCHITECTURE;


ContextFileVHDL::ContextFileVHDL(VP_Word *startingWord, VP_Word *endingWord, QObject *parent):
  AbstractContext(startingWord, endingWord, parent)
{
}



/**
 * @brief ContextFileVHDL::analyze Extract all sub context.
 * For a VHDL file, the existing context are :
 * - Library declaration
 * - Library usage
 * - Entity declaration
 * - Package declaration
 * - Architecture declaration
 * - Package body
 *
 * @param firstWord Pointer to the first word to analyze
 */
void ContextFileVHDL::analyze(VP_Word *firstWord)
{
  VP_Word *w = firstWord; // Start from this word

  while((w != NULL) && (w->nextWord() != NULL))
  {
    if(w->getText().compare(VP_VHDL_SX_KEYWORD_LIBRARY, Qt::CaseInsensitive) == 0)  // It's a library declaration
    {
      m_subContextList << new ContextLibDeclaration()
    }
    else if(w->getText().compare(VP_VHDL_SX_KEYWORD_USE, Qt::CaseInsensitive) == 0)  // It's a library use declaration
    {

    }
    else if(w->getText().compare(VP_VHDL_SX_KEYWORD_ENTITY, Qt::CaseInsensitive) == 0)  // It's a entity declaration
    {

    }
    else if(w->getText().compare(VP_VHDL_SX_KEYWORD_PACKAGE, Qt::CaseInsensitive) == 0)  // It's something around package
    {
      if(w->nextWord() != NULL) // a word exists after
      {
        if(w->nextWord()->getText().compare(VP_VHDL_SX_KEYWORD_BODY, Qt::CaseInsensitive) == 0) // It's a package body
        {

        }
        else // It's a package declaration
        {

        }
      }
    }
    else if(w->getText().compare(VP_VHDL_SX_KEYWORD_ARCHITECTURE, Qt::CaseInsensitive) == 0)  // It's a entity architecture
    {

    }

  };

}
