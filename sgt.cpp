#include "stdafx.h"
#include "sgt.h"


// Construction _________________________________________________________________
// Construction par défaut : les deux extrémités se trouvent à l'origine
sgt::sgt(void)
    :p1(0,0)
    ,p2(0,0)
{ }

// Constuction à partir de deux points
sgt::sgt(const pt p3, const pt p4)
    :p1(p3)
    ,p2(p4)
{ }

// L'opérateur d'affectation implicite et le constructeur de copie implicite
// conviennent : on ne les code pas explicitement.
sgt::sgt(const sgt& s2)
    :p1(s2.get_p1())
    ,p2(s2.get_p2())
{ }

// Opérations ___________________________________________________________________
// Renvoie vrai si le segment d'appel et l'argument sont égaux : leurs premières
// extrémités sont égales et leurs secondes extrémités sont égales.
bool sgt::operator==(const sgt& s2) const
{
    return ((p1 == s2.get_p1()) && (p2 == s2.get_p2()));
}

// Renvoie la longueur du segment (distance euclidienne entre ses extrémités)
const double sgt::length(void) const
{
    return sqrt((this->get_x1()-this->get_x2())*(this->get_x1()-this->get_x2()) + 
                (this->get_y1()-this->get_y2())*(this->get_y1()-this->get_y2()));
}

// Translation du segment de (dx,dy)
void sgt::offset(const double dx, const double dy)
{
    this->set_p1(pt(this->get_x1()+dx, this->get_y1()+dy));
    this->set_p2(pt(this->get_x2()+dx, this->get_y2()+dy));
}

// Renvoie le point milieu du segment.
const pt sgt::centerPt(void) const
{
    return pt((this->get_x1() + this->get_x2())/2.0, (this->get_y1() + this->get_y2())/2.0);
}

// Renvoie un point situé sur segment et le plus proche du point argument
const pt sgt::closerTO(const pt& p1) const
{
    pt p0;
    double a = (this->get_x1()-this->get_x2())/(this->get_y1()-this->get_y2());
    //double b = 
    return p0;
}