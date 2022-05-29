#!/bin/bash
folder_bin=$1
folder_obj=$2
echo " on a $folder_bin et $folder_obj";
if [ ! -d "$folder_bin" ];
then echo "Le sous dossier : $folder_bin n'existe pas, impossible de compiler le pilote (mauvaise emplacement du dossier).";
else
if [ ! -d "$folder_obj" ];
then mkdir $folder_obj
else rmdir $folder_obj;
fi
fi

