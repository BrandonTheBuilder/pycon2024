
import importlib
import warnings

STARTUP_FUNCTIONS=[]

def load_startup_functions():
    for func in STARTUP_FUNCTIONS:
        mod, sep, func = func.partition(":")
        if sep:
            try:
                module = importlib.import_module(mod)
                getattr(module, func)()
            except Exception as e:
                # TODO: Ignoring errors for now.
                warnings.warn(
                    "Startup function %s (%s:%s) not executed: %s"
                    % (mod, name, func, e),
                    stacklevel=1,
                )

        