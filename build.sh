# rm -rf build_dir
# mkdir build_dir
cd build_dir
# cmake -DCMAKE_BUILD_TYPE=Release -DETISS_BUILD_MANUAL_DOC=ON -DCMAKE_INSTALL_PREFIX:PATH=build_dir/installed ..
# cmake -DCMAKE_BUILD_TYPE=Debug -DETISS_BUILD_MANUAL_DOC=ON -DCMAKE_INSTALL_PREFIX:PATH=build_dir/installed ..
make -j4
