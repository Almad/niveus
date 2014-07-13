
cd minimal/
rm -rf CMakeCache.txt CMakeFiles/ cmake_install.cmake *.so *.o && cmake ./ && make && python -c "import json; import mypy; print json.loads(mypy.myfn())"

