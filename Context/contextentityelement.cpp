#include "contextentityelement.h"

#include "VHDL_Syntaxe.h"


ContextEntityElement::ContextEntityElement(QObject *parent):
  AbstractContext(parent)
{
}


VP_Word* ContextEntityElement::analyze(VP_Word *firstWord)
{

  VP_Word *currentWord = firstWord->nextWord(2, true); // The next word is open parse, the second is the first parameter

  while((currentWord != NULL) &&  // More word to analyze
        (currentWord->getText() != VP_VHDL_SX_SEP_CAR_CLOSE_BRACKET)) // Close bracket means end of generic declaration
  {
    currentWord = extractElement(currentWord);  // Extract this generic parameter
  }

  currentWord = lastWordOfThisContext(currentWord); // Go to the end of this context

  if(currentWord != NULL) // More word to analyze
    currentWord = currentWord->nextWord(true);

  return currentWord; // Next analyze will start from here
}


/**
 * @brief ContextGenericDeclaration::newElement Extract and create the new generic parameter or port
 * @param elementNameWord Start at the name of the element.
 * @return The first word next to the element declaration.
 */
VP_Word* ContextEntityElement::extractElement(VP_Word *elementNameWord)
{
  QString elementName = elementNameWord->getText();
  QPoint position = elementNameWord->getPos();

  // Get the type
  //-------------
  VP_Word *currentWord = elementNameWord->nextWord(2, true);  // Go to the type declaration
  if(currentWord->isKeyword())  // Not the type declaration (port direction declaration),
    currentWord = currentWord->nextWord(true);   // go after

  if(currentWord == NULL)
    return NULL;  // End of text to analyze

  // The type could be composed with brackets
  //-----------------------------------------
  QString elementType;
  while((currentWord->getText() != VP_VHDL_SX_SEP_CAR_SEMICOLON) &&
        (currentWord->getText() != VP_VHDL_SX_SEP_CAR_ELEMENT_DEF_VALUE))
  {
    elementType.append(currentWord->getText());  // Add this
    currentWord = currentWord->nextWord(true);
  }
  //-----------------------------------------

  //-------------

  // Get the default value
  //----------------------
  QString elementValue = QString();
  if(currentWord->getText() == VP_VHDL_SX_SEP_CAR_ELEMENT_DEF_VALUE)
  {
    currentWord = currentWord->nextWord(true); // Go to next word

    if(currentWord != NULL)
    {
      elementValue = currentWord->getText(); // Get the default value

      currentWord = currentWord->nextWord(true);
    }
  }
  //----------------------

  // Create the element
  createElement(elementNameWord, elementName, position, elementType, elementValue);

  // Check for end of declarations
  if(currentWord != NULL)
  {
    if(currentWord->getText() == VP_VHDL_SX_SEP_CAR_SEMICOLON)  // There will be a new declaration
      currentWord = currentWord->nextWord(true);  // Go on this new declaration
  }

  return currentWord;
}



