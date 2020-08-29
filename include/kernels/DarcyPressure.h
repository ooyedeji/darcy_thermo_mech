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

  // References to be set from Material system

  /// The permeability. Note that this is declared as a \p MaterialProperty. This means that if
  /// calculation of this property in the producing \p Material depends on non-linear variables, the
  /// derivative information will be lost here in the consumer and the non-linear solve will suffer
  const ADMaterialProperty<Real> & _permeability;

  /// The viscosity. This is declared as an \p ADMaterialProperty, meaning any derivative
  /// information coming from the producing \p Material will be preserved and the integrity of the
  /// non-linear solve will be likewise preserved
  const ADMaterialProperty<Real> & _viscosity;
};