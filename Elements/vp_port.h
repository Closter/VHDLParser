#ifndef VP_PORT_H
#define VP_PORT_H

#include "vp_entityelements.h"


class VP_Port : public VP_EntityElements
{
public:

  typedef enum{
    VP_unknow,
    VP_in,
    VP_out,
    VP_inout
  }t_direction;

  VP_Port(QString name, t_direction direction, QString type, QString defaultValue, QPoint pos = QPoint());


  // Accessors
  //----------
  t_direction getDirection()
  {
    return m_direction;
  }

  //----------

private:


  t_direction m_direction;  ///< Port's direction

};

#endif // VP_PORT_H
