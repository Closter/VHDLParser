#include "contextentitydeclaration.h"

#include "VHDL_Syntaxe.h"

#include "contextgenericdeclaration.h"

ContextEntityDeclaration::ContextEntityDeclaration( QObject *parent):
  AbstractContext(parent)
{
  m_entity = NULL;

  m_contextKeywordList << VP_VHDL_SX_KEYWORD_ENTITY
                       << VP_VHDL_SX_KEYWORD_IS
                       << VP_VHDL_SX_KEYWORD_END
                       << VP_VHDL_SX_KEYWORD_GENERIC
                       << VP_VHDL_SX_KEYWORD_PORT;
}


/**
 * @brief ContextEntityDeclaration::analyze
 * @param firstWord Pointer to the first word to analyze
 */
VP_Word* ContextEntityDeclaration::analyze(VP_Word *firstWord)
{
  VP_Word *currentWord = firstWord;

  if(firstWord->getText().compare(VP_VHDL_SX_KEYWORD_ENTITY, Qt::CaseInsensitive) == 0) // Check the entity keyword
  {
    // The entity name is the next word
    if(currentWord->nextWord(false) != NULL)
    {
      currentWord = currentWord->nextWord(false);
      QString entityName = currentWord->getText();

      delete m_entity;

      m_entity = new VP_Entity(entityName, QPoint(firstWord->getLine(), firstWord->getColumn()), this); // Create the entity

      if(currentWord->nextWord(false) != NULL) // Go to is declaration
      {
        currentWord = currentWord->nextWord(false);

        if(currentWord->getText().compare(VP_VHDL_SX_KEYWORD_IS, Qt::CaseInsensitive) == 0) // Check for "is" keyword
        {
          currentWord = currentWord->nextWord(false);
          findSubContext(currentWord);
        }
      }
    }
  }

  return currentWord;
}


/**
 * @brief findSubContext Look for all entity's sub-context
 * @param firstWord The first word to start analyzis
 * @return The next word to the end of all sub-context.
 */
VP_Word *ContextEntityDeclaration::findSubContext(VP_Word *firstWord)
{
  VP_Word *currentWord = firstWord;

  while(currentWord != NULL)
  {
    if(currentWord->isKeyword())
    {
      // Check for generics declaration
      if(currentWord->getText().compare(VP_VHDL_SX_KEYWORD_GENERIC, Qt::CaseInsensitive) == 0)
      {
        currentWord = newSubContext(new ContextGenericDeclaration(this), currentWord);
      }
      // Check for ports declaration
      else if(currentWord->getText().compare(VP_VHDL_SX_KEYWORD_PORT, Qt::CaseInsensitive) == 0)
      {
        // TODO New port
      }
      // Check for end of entity
      else if(currentWord->getText().compare(VP_VHDL_SX_KEYWORD_END, Qt::CaseInsensitive) == 0)
      {
        currentWord = lastWordOfThisContext(currentWord->nextWord(false));  // Go to the start of another new context
        break;
      }
      else
      {
        currentWord = currentWord->nextWord(false); // Go to next non-comment word
      }
    }
    else
    {
      currentWord = currentWord->nextWord(false); // Go to next non-comment word
    }
  }

  return currentWord;
}
