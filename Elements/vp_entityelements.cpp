#include "vp_entityelements.h"

VP_EntityElements::VP_EntityElements(QString name, QString type, QString defaultValue, QPoint pos) :
  VP_AbstractDeclaration(name, pos)
{
  m_type = type;
  m_defaultValue = defaultValue;
}
