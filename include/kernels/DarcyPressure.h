#pragma once

// Including the "ADKernel" Kernel here so we can extend it
#include "ADKernel.h"

/**
 * Computes the residual contribution: K / mu * grad_u * grad_phi.
 */
class DarcyPressure : public ADKernel
{
public:
  static InputParameters validParams();

  DarcyPressure(const InputParameters & parameters);

protected:
  /// ADKernel objects must override precomputeQpResidual
  virtual ADReal computeQpResidual() override;

  /// References to be set from input file
  const Real & _permeability;
  const Real & _viscosity;
};
