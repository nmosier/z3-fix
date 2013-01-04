/*++
Copyright (c) 2013 Microsoft Corporation

Module Name:

    rcf.cpp

Abstract:

    Testing RCF module

Author:

    Leonardo (leonardo) 2013-01-04

Notes:

--*/
#include"realclosure.h"

static void tst1() {
    unsynch_mpq_manager qm;
    rcmanager m(qm);
    scoped_rcnumeral a(m);
    a = 10;
    std::cout << sym_pp(a) << std::endl;
    scoped_rcnumeral eps(m);
    m.mk_infinitesimal("eps", eps);
    std::cout << sym_pp(eps) << std::endl;
    std::cout << interval_pp(a) << std::endl;
    std::cout << interval_pp(eps) << std::endl;
    mpq aux;
    qm.set(aux, 1, 3);
    m.set(a, aux);
    std::cout << interval_pp(a) << std::endl;
    std::cout << decimal_pp(eps, 4) << std::endl;
    std::cout << decimal_pp(a) << std::endl;
}

void tst_rcf() {
    tst1();
}
