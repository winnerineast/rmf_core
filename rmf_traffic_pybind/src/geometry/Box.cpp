#include <pybind11/pybind11.h>
#include <rmf_traffic/geometry/Box.hpp>

namespace py = pybind11;

PYBIND11_MODULE(py_rmf_traffic, m) {
    py::class_<rmf_traffic::geometry::Box>(m, "Box")
        .def(py::init<double, double>());
}
