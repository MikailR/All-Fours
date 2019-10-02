#!/bin/bash

make

if [ "$1" = "-wi" ]; then
  ./allfours
else
  ./allfours < input
fi
