#include "contextgenericdeclaration.h"


ContextGenericDeclaration::ContextGenericDeclaration(QObject *parent):
  ContextEntityElement(parent)
{
}



/**
 * @brief ContextGenericDeclaration::createElement Create the new generic element
 * @param elementNameWord Generic word in the text
 * @param elementName     Generic name
 * @param pos             Word position in the text
 * @param type            Generic type
 * @param defaultValue    Generic defualt value
 */
void ContextGenericDeclaration::createElement(VP_Word *elementNameWord, QString elementName, QPoint pos, QString type, QString defaultValue)
{
  m_elementList << new VP_Generic(elementName, type, defaultValue, pos);
}
