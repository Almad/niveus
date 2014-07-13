#include <boost/python.hpp>
#include "lib.hpp"

namespace bp = boost::python;

BOOST_PYTHON_MODULE(mypy)
{
  bp::def("myfn", &myfn);
}
