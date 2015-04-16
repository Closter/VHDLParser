#include "vp_entity.h"

VP_Entity::VP_Entity(QString name, QPoint posDeclaration, QObject *parent) :
  QObject(parent)
{
  m_posDeclaration  = posDeclaration;

  m_name      = name;
}
