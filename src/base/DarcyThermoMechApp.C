#include "DarcyThermoMechApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
DarcyThermoMechApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

DarcyThermoMechApp::DarcyThermoMechApp(InputParameters parameters) : MooseApp(parameters)
{
  DarcyThermoMechApp::registerAll(_factory, _action_factory, _syntax);
}

DarcyThermoMechApp::~DarcyThermoMechApp() {}

void
DarcyThermoMechApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"DarcyThermoMechApp"});
  Registry::registerActionsTo(af, {"DarcyThermoMechApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
DarcyThermoMechApp::registerApps()
{
  registerApp(DarcyThermoMechApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
DarcyThermoMechApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  DarcyThermoMechApp::registerAll(f, af, s);
}
extern "C" void
DarcyThermoMechApp__registerApps()
{
  DarcyThermoMechApp::registerApps();
}
