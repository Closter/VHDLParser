#include "vp_abstractdeclaration.h"

VP_AbstractDeclaration::VP_AbstractDeclaration(QString name, QPoint declarationPos)
{
  m_name = name;
  m_declarationPos = declarationPos;
}

VP_AbstractDeclaration::~VP_AbstractDeclaration()
{

}
