/*
Biblioteca tem como objetivo mover o motor de passo para frente (direita ou horario)
a partir do envio de sinal para os bits de 1/4 de passo do primeiro para o últimoa partir 
das funcões desenvolvidas na classe StepperMotor.
*/

#include "pico/stdlib.h"
#include "FwrdSM.h"

ForwardStepperMotor::ForwardStepperMotor(int in1, int in2, int in3, int in4)
    : StepperMotor<int>(in1, in2, in3, in4) {}

void ForwardStepperMotor::move(int steps, int delayTime) {
    for (int i = 0; i < steps; ++i) {
        setStep(1, 0, 0, 0);
        setStep(0, 1, 0, 0);
        setStep(0, 0, 1, 0);
        setStep(0, 0, 0, 1);
        updateLastStep(i % 4);  // Atualiza o passo de acordo com o passo atual
        sleep_ms(delayTime);
    }
}

int ForwardStepperMotor::getLastStep() const {
    return lastStep;
}