#pragma once
#include "Movable.h"

class GameObject:public Movable
{
protected:
public:
    GameObject();
    void SetEnabled(bool enable, float x, float y);
    void SetEnabled(bool enable);
    bool IsEnable() const;
private:
    bool enable;
};