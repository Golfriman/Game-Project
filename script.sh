#!/bin/bash
if ps | grep (название файла, который запускается); then
	echo "duplicate"
else
	(название файла, который запускается) &
fi
exit

