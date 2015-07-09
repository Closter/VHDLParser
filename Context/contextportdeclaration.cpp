#include "contextportdeclaration.h"

#include "VHDL_Syntaxe.h"

ContextPortDeclaration::ContextPortDeclaration(QObject *parent) :
  ContextEntityElement(parent)
{
}



/**
 * @brief ContextPortDeclaration::createElement Create the new port element.
 * @param elementNameWord Generic word in the text
 * @param elementName     Generic name
 * @param pos             Word position in the text
 * @param type            Generic type
 * @param defaultValue    Generic defualt value
 */
void ContextPortDeclaration::createElement(VP_Word *elementNameWord, QString elementName, QPoint pos, QString type, QString defaultValue)
{
  // Have to get port's direction
  //-----------------------------
  VP_Port::t_direction direction = VP_Port::VP_unknow;

  VP_Word *wDirection = elementNameWord->nextWord(2, true); // Go to the direction word
  if(wDirection != NULL)
  {
    QString directionText = wDirection->getText();

    if(directionText.compare(VP_VHDL_SX_KEYWORD_IN, Qt::CaseInsensitive) == 0)  // input port
      direction = VP_Port::VP_in;
    else if(directionText.compare(VP_VHDL_SX_KEYWORD_OUT, Qt::CaseInsensitive) == 0)  // Output port
      direction = VP_Port::VP_out;
    else if(directionText.compare(VP_VHDL_SX_KEYWORD_INOUT, Qt::CaseInsensitive) == 0)  // Input/output port
      direction = VP_Port::VP_inout;
  }
  //-----------------------------

  m_elementList << new VP_Port(elementName, direction, type, defaultValue, pos);
}
