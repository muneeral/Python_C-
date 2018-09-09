#include "include.h"


PyObject* some_function1(PyObject* self, PyObject* args) {
	__int64 input_value;
	if (!PyArg_ParseTuple(args, "L", &input_value)) {
		goto error;
	}
error:
	return PyLong_FromLongLong(input_value + 1);
}

PyObject* some_function2(PyObject* self, PyObject* args) {
	__int64 input_value;
	if (!PyArg_ParseTuple(args, "L", &input_value)) {
		goto error;
	}
error:
	return PyLong_FromLongLong(input_value + 2);
}

PyObject* some_function3(PyObject* self, PyObject* args) {
	printf("Hello from C++");
	return args;
}


PyMethodDef SpamMethods[]{
	{"add_one", (PyCFunction)some_function1, METH_VARARGS, 0},
	{"add_two", (PyCFunction)some_function2, METH_VARARGS, 0},
	{"add_hello", (PyCFunction)some_function3, METH_VARARGS, 0},
	{0,0,0,0}
};

static struct PyModuleDef spammodule = {
	PyModuleDef_HEAD_INIT,
	"spam",   /* name of module */
	"My Wonderful module spam", /* module documentation, may be NULL */
	-1,       /* size of per-interpreter state of the module,
				 or -1 if the module keeps state in global variables. */
	SpamMethods
};

PyMODINIT_FUNC
PyInit_spam(void)
{
	return PyModule_Create(&spammodule);
}