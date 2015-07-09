#ifndef CONTEXTPORTDECLARATION_H
#define CONTEXTPORTDECLARATION_H

#include "contextentityelement.h"

#include "Elements/vp_port.h"


class ContextPortDeclaration : public ContextEntityElement
{
public:
  ContextPortDeclaration(QObject *parent = 0);

private:
  void createElement(VP_Word *elementNameWord, QString elementName, QPoint pos, QString type, QString defaultValue);

};

#endif // CONTEXTPORTDECLARATION_H
