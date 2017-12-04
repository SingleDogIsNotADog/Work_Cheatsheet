#! /bin/bash

# usage: $ sh build.sh [rebuild | clear]

clear()
{
	if [ ! -d tmp_build ]; then
		return
	fi

	cd tmp_build
	make clean
	cd ..
	rm -rf tmp_build
}

if [ "$1" = "rebuild" ]; then
	clear
elif [ "$1" = "clear" ]; then
	clear
	exit
fi

mkdir -p tmp_build
cd tmp_build

cmake -DCMAKE_BUILD_TYPE=debug ..
time make -j8
