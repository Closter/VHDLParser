#include "contextfilevhdl.h"

#include "VHDL_Syntaxe.h"

#include "Context/contextarchitecture.h"
#include "Context/contextentitydeclaration.h"
#include "Context/contextlibrary.h"
#include "Context/contextpackagebody.h"
#include "Context/contextpackagedeclaration.h"


QList<QString> ContextFileVHDL::m_keywordList = QList<QString>()
    << VP_VHDL_SX_KEYWORD_LIBRARY
    << VP_VHDL_SX_KEYWORD_USE
    << VP_VHDL_SX_KEYWORD_ENTITY
    << VP_VHDL_SX_KEYWORD_PACKAGE
    << VP_VHDL_SX_KEYWORD_BODY
    << VP_VHDL_SX_KEYWORD_ARCHITECTURE;


ContextFileVHDL::ContextFileVHDL(QObject *parent):
  AbstractContext(parent)
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
 *
 * @return The next word after this context to continue analyze
 */
VP_Word* ContextFileVHDL::analyze(VP_Word *firstWord)
{
  VP_Word *w = firstWord; // Start from this word

  while((w != NULL) && (w->nextWord() != NULL))
  {
    // It's a library declaration
    if(w->getText().compare(VP_VHDL_SX_KEYWORD_LIBRARY, Qt::CaseInsensitive) == 0)
    {
      w = newSubContext(new ContextLibrary(this), static_cast<VP_Word*>(w));  // Create this subcontext
    }
    // It's a entity declaration
    else if(w->getText().compare(VP_VHDL_SX_KEYWORD_ENTITY, Qt::CaseInsensitive) == 0)
    {
      w = newSubContext(new ContextEntityDeclaration(this), static_cast<VP_Word*>(w));
    }
    // It's something around package
    else if(w->getText().compare(VP_VHDL_SX_KEYWORD_PACKAGE, Qt::CaseInsensitive) == 0)
    {
      // It's a package body
      if(w->nextWord()->getText().compare(VP_VHDL_SX_KEYWORD_BODY, Qt::CaseInsensitive) == 0)
      {
        w = newSubContext(new ContextPackageBody(this), static_cast<VP_Word*>(w->nextWord(2)));
      }
      // It's a package declaration
      else
      {
        w = newSubContext(new ContextPackageDeclaration(this), static_cast<VP_Word*>(w->nextWord()));
      }
    }
    // It's a entity architecture
    else if(w->getText().compare(VP_VHDL_SX_KEYWORD_ARCHITECTURE, Qt::CaseInsensitive) == 0)
    {
      w = newSubContext(new ContextArchitEcture(this), static_cast<VP_Word*>(w));
    }

  };

  return w; // The end of a VHDL file context is the end of a file
}




