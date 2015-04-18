#include "contextgenericdeclaration.h"

#include "VHDL_Syntaxe.h"


ContextGenericDeclaration::ContextGenericDeclaration(QObject *parent):
  AbstractContext(parent)
{
}


VP_Word* ContextGenericDeclaration::analyze(VP_Word *firstWord)
{
  // Check for the correct keyword
  if(firstWord->getText().compare(VP_VHDL_SX_KEYWORD_GENERIC, Qt::CaseInsensitive) != 0)
  {
    return firstWord; // This word is not keyword for generic declaration
  }

  VP_Word *currentWord = firstWord->nextWord(2, true); // The next word is open parse, the second is the first parameter

  while((currentWord != NULL) &&  // More word to analyze
        (currentWord->getText() != VP_VHDL_SX_SEP_CAR_CLOSE_BRACKET)) // Close bracket means end of generic declaration
  {
    currentWord = newGeneric(currentWord);  // Extract this generic parameter
  }

  currentWord = lastWordOfThisContext(currentWord); // Go to the end of this context

  if(currentWord != NULL) // More word to analyze
    currentWord = currentWord->nextWord(true);

  return currentWord; // Next analyze will start from here
}


/**
 * @brief ContextGenericDeclaration::newGeneric Extract and create the new generic parameter
 * @param genericName Start at the name of the generic parameter.
 * @return The first word next to the generic declaration.
 */
VP_Word* ContextGenericDeclaration::newGeneric(VP_Word *genericNameWord)
{
  QString genericName = genericNameWord->getText();
  QPoint position = genericNameWord->getPos();

  // Get the type
  //-------------
  VP_Word *currentWord = genericNameWord->nextWord(2, true);  // Go to the type declaration

  if(currentWord == NULL)
    return NULL;  // End of text to analyze

  QString genericType = currentWord->getText();

  currentWord = currentWord->nextWord(true); // Look for default value
  //-------------

  // Get the default value
  //----------------------
  QString genericValue = QString();
  if(currentWord->getText() == VP_VHDL_SX_SEP_CAR_GEN_ASSIGNEMENT)
  {
    currentWord = currentWord->nextWord(true); // Go to next word

    if(currentWord != NULL)
    {
      genericValue = currentWord->getText(); // Get the default value

      currentWord = currentWord->nextWord(true);
    }
  }
  else  // no default value assignement
  {
    currentWord = currentWord->nextWord(true);
  }
  //----------------------

  // Create the generic parameter
  m_genericList << new VP_Generic(genericName, genericType, genericValue, position);

  // Check for end of declarations
  if(currentWord != NULL)
  {
    if(currentWord->getText() == VP_VHDL_SX_SEP_CAR_SEMICOLON)  // There will be a new declaration
      currentWord = currentWord->nextWord(true);  // Go on this new declaration
  }

  return currentWord;
}
