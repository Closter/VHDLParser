#include "vp_port.h"

VP_Port::VP_Port(QString name, t_direction direction, QString type, QString defaultValue, QPoint pos):
  VP_EntityElements(name, type, defaultValue, pos)
{
  m_direction = direction;
}
