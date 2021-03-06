/*++
Copyright (c) 2006 Microsoft Corporation

Module Name:

    dyn_ack_params.h

Abstract:

    <abstract>

Author:

    Leonardo de Moura (leonardo) 2007-05-18.

Revision History:

--*/
#pragma once

#include "util/params.h"

enum class dyn_ack_strategy {
    DACK_DISABLED,
    DACK_ROOT, // congruence is the root of the conflict
    DACK_CR    // congruence used during conflict resolution
};

struct dyn_ack_params {
    dyn_ack_strategy m_dack = dyn_ack_strategy::DACK_ROOT;
    bool             m_dack_eq = false;
    double           m_dack_factor = 0.1;
    unsigned         m_dack_threshold = 10;
    unsigned         m_dack_gc = 2000;
    double           m_dack_gc_inv_decay = 0.8;

public:
    dyn_ack_params(params_ref const & p = params_ref()) {
        updt_params(p);
    }

    void updt_params(params_ref const & _p);

    void display(std::ostream & out) const;
};



