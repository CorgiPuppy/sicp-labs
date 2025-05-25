#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Lazy {
    bool evaluated;
    double value;
    double (*thunk)(void* args);
    void* args;
} Lazy;

double force(Lazy* lazy) {
    if (!lazy->evaluated && lazy->thunk != NULL) {
        lazy->value = lazy->thunk(lazy->args);
        lazy->evaluated = true;
    }
    return lazy->value;
}

Lazy make_lazy(double (*thunk)(void*), void* args) {
    return (Lazy){.evaluated = false, .thunk = thunk, .args = args};
}

typedef struct PumpParams {
    double flow_rate;
    double efficiency;
    double pressure;
} PumpParams;

double rotary_pump_impl(void* args) {
    PumpParams* p = (PumpParams*)args;
    double result = p->flow_rate * p->efficiency;
    free(p);
    return result;
}

double piston_pump_impl(void* args) {
    PumpParams* p = (PumpParams*)args;
    double result = p->flow_rate * p->efficiency * (1 - 0.1*p->pressure);
    free(p);
    return result;
}

typedef Lazy (*pump_func)(PumpParams);

static Lazy rotary_wrapper(PumpParams p) {
    PumpParams* params = malloc(sizeof(PumpParams));
    *params = p;
    return make_lazy(rotary_pump_impl, params);
}

static Lazy piston_wrapper(PumpParams p) {
    PumpParams* params = malloc(sizeof(PumpParams));
    *params = p;
    return make_lazy(piston_pump_impl, params);
}

pump_func make_pump(bool is_rotary) {
    return is_rotary ? rotary_wrapper : piston_wrapper;
}

double simulate(pump_func pump, PumpParams params, int steps, double acc) {
    if (steps <= 0) return acc;
    
    Lazy result = pump(params);
    double current = force(&result);
    
    return simulate(pump, 
                  (PumpParams){.flow_rate = params.flow_rate,
                              .efficiency = params.efficiency,
                              .pressure = params.pressure * 0.9},
                  steps - 1,
                  acc + current);
}

int main() {
    pump_func rotary_pump = make_pump(true);

    PumpParams params = {
        .flow_rate = 10.0,
        .efficiency = 0.85,
        .pressure = 1.0
    };

    double total = simulate(rotary_pump, params, 10, 0.0);
    printf("Total pumped: %.2f units\n", total);

    return 0;
}
