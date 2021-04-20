#include <Python.h>
#include "etr.h"
#include "ssr.h"
#include "itr.h"
#include "vntr.h"

PyObject *test(PyObject *self, PyObject *args, PyObject *kwargs) {
	return Py_BuildValue("s", "hello");
}

static PyMethodDef module_methods[] = {
	{"test", (PyCFunction)test, METH_VARARGS | METH_KEYWORDS, NULL},
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef module_stripy = {
	PyModuleDef_HEAD_INIT,
	"stripy",
	"A python package for short tandem repeat identification",
	-1,
	module_methods,
};

static PyObject *strit_module_init(void) {
	PyObject *module;
	module = PyModule_Create(&module_stripy);

	if (module == NULL) {
		return NULL;
	}

	//TRE
	if (PyType_Ready(&stripy_ETRType) < 0) {
		return NULL;
	}
	Py_INCREF((PyObject *)&stripy_ETRType);
	PyModule_AddObject(module, "ETR", (PyObject *)&stripy_ETRType);

	//SSR
	if (PyType_Ready(&stripy_SSRMinerType) < 0) {
		return NULL;
	}
	Py_INCREF((PyObject *)&stripy_SSRMinerType);
	PyModule_AddObject(module, "SSRMiner", (PyObject *)&stripy_SSRMinerType);

	//VNTR
	if (PyType_Ready(&stripy_VNTRMinerType) < 0) {
		return NULL;
	}
	Py_INCREF((PyObject *)&stripy_VNTRMinerType);
	PyModule_AddObject(module, "VNTRMiner", (PyObject *)&stripy_VNTRMinerType);

	//ITR
	if (PyType_Ready(&stripy_ITRType) < 0) {
		return NULL;
	}
	Py_INCREF((PyObject *)&stripy_ITRType);
	PyModule_AddObject(module, "ITR", (PyObject *)&stripy_ITRType);

	if (PyType_Ready(&stripy_ITRMinerType) < 0) {
		return NULL;
	}
	Py_INCREF((PyObject *)&stripy_ITRMinerType);
	PyModule_AddObject(module, "ITRMiner", (PyObject *)&stripy_ITRMinerType);

	return module;
}

PyMODINIT_FUNC PyInit_stripy() {
	return strit_module_init();
}
