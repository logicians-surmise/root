#include "pythonizables.h"


//===========================================================================
pyzables::NakedBuffers::NakedBuffers(int size, double valx, double valy) : m_size(size) {
    m_Xbuf = new double[size];
    m_Ybuf = new double[size];

    for (int i=0; i<size; ++i) {
        m_Xbuf[i] = valx*i;
        m_Ybuf[i] = valy*i;
    }
}

pyzables::NakedBuffers::~NakedBuffers() {
    delete[] m_Xbuf;
    delete[] m_Ybuf;
}

int pyzables::NakedBuffers::GetN() { return m_size; }

double* pyzables::NakedBuffers::GetX() { return m_Xbuf; }
double* pyzables::NakedBuffers::GetY() { return m_Ybuf; }


//===========================================================================
pyzables::MyBase::~MyBase() {}
pyzables::MyDerived::~MyDerived() {}

pyzables::MyBase* pyzables::GimeDerived() {
   return new MyDerived();
}


//===========================================================================
int pyzables::Countable::sInstances = 0;
pyzables::SharedCountable_t pyzables::mine =
    pyzables::SharedCountable_t(new pyzables::Countable);

void pyzables::renew_mine() { mine = std::shared_ptr<Countable>(new Countable); }

pyzables::SharedCountable_t pyzables::gime_mine() { return mine; }
pyzables::SharedCountable_t* pyzables::gime_mine_ptr() { return &mine; }
pyzables::SharedCountable_t& pyzables::gime_mine_ref() { return mine; }

unsigned int pyzables::pass_mine_sp(std::shared_ptr<Countable> ptr) { return ptr->m_check; }
unsigned int pyzables::pass_mine_sp_ref(std::shared_ptr<Countable>& ptr) { return ptr->m_check; }
unsigned int pyzables::pass_mine_sp_ptr(std::shared_ptr<Countable>* ptr) { return (*ptr)->m_check; }

unsigned int pyzables::pass_mine_rp(Countable c) { return c.m_check; }
unsigned int pyzables::pass_mine_rp_ref(const Countable& c) { return c.m_check; }
unsigned int pyzables::pass_mine_rp_ptr(const Countable* c) { return c->m_check; }
