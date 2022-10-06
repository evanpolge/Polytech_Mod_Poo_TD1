#include "stdafx.h"
#include "rct.h"

// Teste si le rectangle est dans un état valide
bool rct::valid(void) const
{
    assert(this->w >= 0);
    assert(this->h >= 0);
    return true;
}

// Construction _________________________________________________________________
rct::rct(void) // Construction par défaut
    : pC(pt())
    , w(0)
    , h(0) 
{
    assert(valid());
}

rct::rct(const double x1, const double x2, const double y1, const double y2) // Créée un rectangle à partir des abscisses et ordonnées
    : pC((x2 + x1) / 2, (y2 + y1) / 2)
    , w(x2 - x1)
    , h(y2 - y1)
{
    assert(valid());
}

// Construction à partir de deux points absolument quelconques : le plus pe-
// tit rectangle qui contient les deux points.
rct::rct(const pt p1, const pt p2)
    : pC(p1.centerPt(p2))
    , w(fabs(p1.getX() - p2.getX()))
    , h(fabs(p1.getY() - p2.getY()))
{
    assert(valid());
}

// L'opérateur d'affectation implicite et le constructeur de copie implicite
// conviennent. On ne les code pas explicitement.
rct::rct(const rct &r2)
    : pC(r2.getCenterPt())
    , w(r2.getWidth())
    , h(r2.getHeight())
{
    assert(valid());
}


// Attributs dérivés ___________________________________________________________
// Renvoie l'abscisse du coté gauche
const double rct::x1(void) const
{
    assert(valid());
    return (this->pC.getX() - (this->getWidth() / 2));
}

// Renvoie l'abscisse du coté droit
const double rct::x2(void) const
{
    assert(valid());
    return (this->pC.getX() + (this->getWidth() / 2));
}

// Renvoie l'ordonnée du coté bas
const double rct::y1(void) const
{
    assert(valid());
    return (this->pC.getY() - (this->getHeight() / 2));
}

// Renvoie l'ordonnée du coté haut
const double rct::y2(void) const
{
    assert(valid());
    return (this->pC.getY() + (this->getHeight() / 2));
}

// Renvoie l'air du rectangle
double rct::area(void) const
{
    assert(valid());
    return (this->h * this->w);
}

// Renvoie le coin inférieur gauche
const pt rct::bottomLeft(void) const
{
    assert(valid());
    return pt((this->pC.getX() - (this->w / 2)), (this->pC.getY() - (this->h / 2)));
}

// Renvoie le coin supérieur droit
const pt rct::topRight(void) const
{
    assert(valid());
    return pt((this->pC.getX() + (this->w / 2)), (this->pC.getY() + (this->h / 2)));
}

// Renvoie le coin supérieur gauche
const pt rct::topLeft(void) const
{
    assert(valid());
    return pt((this->pC.getX() - (this->w / 2)), (this->pC.getY() + (this->h / 2)));
}

// Renvoie le coin inférieur droit
const pt rct::bottomRight(void) const
{
    assert(valid());
    return pt((this->pC.getX() + (this->w / 2)), (this->pC.getY() - (this->h / 2)));
}

// Prédicats ___________________________________________________________________
// Egalité de deux rectangles
bool rct::operator==(const rct &r2) const
{
    return EPSEQUAL(this->w, r2.w) && EPSEQUAL(this->h, r2.h) &&
           EPSEQUAL(this->pC.getX(), r2.pC.getX()) && EPSEQUAL(this->pC.getY(), r2.pC.getY());
}

// Renvoie vrai ssi le point argument est contenu dans le rectangle
bool rct::contains(const pt& p) const
{
    assert(valid());
    assert(p.getX() >= this->x1() && p.getX() <= this->x2());
    assert(p.getY() >= this->y1() && p.getY() <= this->y2());
    return true;
}

// Renvoie vrai ssi le rectangle argument est dans le rectangle 
bool rct::contains(const rct& c) const
{
    assert(valid());
    assert(c.x1() <= this->x2() && c.x2() <= this->x2());
    assert(c.x2() >= this->x1() && c.x1() >= this->x1());
    assert(c.y1() <= this->y2() && c.y2() <= this->y2());
    assert(c.y2() >= this->y1() && c.y1() >= this->y1());
    return true;
}


// Opérations __________________________________________________________________
// Translate (déplacement relatif) le rectangle de (dx, dy)
void rct::offset(const double dx, const double dy)
{
    this->pC.setX(this->pC.getX()+dx);
    this->pC.setY(this->pC.getY()+dy);
    assert(valid());
}

// Déformation du rectangle : la largeur est modifiée de px %, et la hauteur
// de py %, mais sans déplacement du centre. L'argument px (resp. py) peut
// être compris entre 0 et 1, ce qui correspond à une  réduction de largeur 
// (resp. hauteur), ou bien supérieur à 1, ce qui correspond à une augmenta-
// tion de largeur (resp. hauteur). Mais ils ne peuvent pas être négatifs.
void rct::inflate(const double px, const double py)
{
    assert(px >=0 && py >=0);
    if (px < 1)
        this->w = this->w*(1-px);
    else
        this->w = this->w*(px-1) + this->w;

    if (py < 1)
        this->h = this->h*(1-py);
    else
        this->h = this->h*(py-1) + this->h;
    
    assert(valid());
}


// Renvoie un point aléatoire contenu dans le rectangle
pt rct::randPt(void) const
{
    assert(valid());
    return pt(dRand(this->x1(), this->x2()), dRand(this->y1(), this->y2()));
}

// Renvoie un rectangle aléatoire contenu dans le rectangle
rct rct::randRct(void) const
{
    assert(valid());
    return rct( pt(dRand(this->x1(), this->x2()), dRand(this->y1(), this->y2()))
              , pt(dRand(this->x1(), this->x2()), dRand(this->y1(), this->y2())) );
}


// Flux_________________________________________________________________
ostream &operator<<(ostream &s, const rct &r)
{
    r.print(s);
    return s;
}

// Ecrit le rectangle dans le flux argument au format RCT[x1, x2]x[y1, y2]
void rct::print(ostream &s) const
{
    s << setiosflags(ios::fixed) << setprecision(2);
    s << "RCT[" << setw(8) << this->x1() << ", " << setw(8) << this->x2() << "]x["
      << setw(8) << this->y1() << ", " << setw(8) << this->y2() << "]";
}