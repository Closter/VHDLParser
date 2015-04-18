#include "vp_generic.h"

VP_Generic::VP_Generic(QString name, QString type, QString defaultValue, QPoint pos) :
  VP_AbstractDeclaration(name, pos)
{
  m_type = type;
  m_defaultValue = defaultValue;
}
