make re
make clean
if [ $? == 0 ]
then
	./fdf $*
fi
