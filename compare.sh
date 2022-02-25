#!/bin/bash

./md | head -n -1 > resultat.txt
diff -y -W 180 r.txt resultat.txt
