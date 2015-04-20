#ifndef CONTEXTGENERICDECLARATION_H
#define CONTEXTGENERICDECLARATION_H

#include "contextentityelement.h"

#include "Elements/vp_generic.h"

/**
 * @brief The ContextGenericDeclaration class describe entity's generic
 * parameters declaration.
 */
class ContextGenericDeclaration : public ContextEntityElement
{
public:
  ContextGenericDeclaration(QObject *parent = 0);

private:
  virtual void createElement(VP_Word *elementNameWord, QString elementName, QPoint pos, QString type, QString defaultValue);

};

#endif // CONTEXTGENERICDECLARATION_H
