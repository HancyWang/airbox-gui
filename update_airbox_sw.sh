#! /bin/bash

#PATH=/home/book/Desktop/tisdk/sources/meta-ros/scripts:/home/book/Desktop/tisdk/sources/meta-browser/scripts:/home/book/Desktop/tisdk/sources/oe-core/scripts:/home/book/Desktop/tisdk/sources/bitbake/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/book/Desktop/tisdk/sources/bitbake/bin:/home/book/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin

#export PATH
#echo $PATH

#read NULL
#1.copy "airbox_ui" and "xxx.qm" to tisdk imgage
echo "STEP 1:copy \"airbox_ui\" and \"xxx.qm\" to fresca-base-image success"
cp /home/book/Desktop/airbox_software/build-airbox-gui-ti-Release/bin/airbox_gui    /home/book/Desktop/tisdk/sources/meta-custom/recipes-core/images/fresca-base-image/

sudo /home/book/qt5.11.3_arm/bin/lrelease /home/book/Desktop/airbox_software/airbox-gui/chinese.ts -qm /home/book/Desktop/airbox_software/airbox-gui/chinese.qm
sudo /home/book/qt5.11.3_arm/bin/lrelease /home/book/Desktop/airbox_software/airbox-gui/spanish.ts -qm /home/book/Desktop/airbox_software/airbox-gui/spanish.qm
sudo /home/book/qt5.11.3_arm/bin/lrelease /home/book/Desktop/airbox_software/airbox-gui/japanese.ts -qm /home/book/Desktop/airbox_software/airbox-gui/japanese.qm

cp /home/book/Desktop/airbox_software/airbox-gui/chinese.qm 	/home/book/Desktop/tisdk/sources/meta-custom/recipes-core/images/fresca-base-image/
cp /home/book/Desktop/airbox_software/airbox-gui/japanese.qm 	/home/book/Desktop/tisdk/sources/meta-custom/recipes-core/images/fresca-base-image/
cp /home/book/Desktop/airbox_software/airbox-gui/spanish.qm 	/home/book/Desktop/tisdk/sources/meta-custom/recipes-core/images/fresca-base-image/

if [[ $? == 0 ]]; then
	echo "STEP 1 done"
else
	echo "STEP 1 fail"
	exit
fi
echo " "

#echo "PATH=$PATH"

#2. clean all images and rebuild
echo "STEP 2:clean all images then rebuild"
cd /home/book/Desktop/tisdk/build
. conf/setenv

echo "------------------start clean fresca-base-image fresca-base-image-swu-------------"
#MACHINE=am335x-evm bitbake-layers show-layers

/home/book/Desktop/tisdk/sources/bitbake/bin/bitbake -c cleanall fresca-base-image fresca-base-image-swu


echo "------------------start bitbake fresca-base-image fresca-base-image-swu-------------"
/home/book/Desktop/tisdk/sources/bitbake/bin/bitbake fresca-base-image fresca-base-image-swu

echo "STEP 2 done"
echo " "



echo "STEP 3:copy the builded .swu file to SD card"
#3.copy the builded .swu file to SD card

#creat a tmp file to store the dir
TMP_STORE_FILE=/tmp/tmp_file_$$.txt

echo "List all directories in your SD card:"
ls /media/book | tee $TMP_STORE_FILE

echo "-----------------------------------------------"

#ls /media/book > $TMP_STORE_FILE

#If directory count 
DIR_QTY=`cat $TMP_STORE_FILE  |wc -l`
DIR_NAME=`cat $TMP_STORE_FILE`


TARGET_SWU_FILE=`ls /home/book/Desktop/tisdk/build/arago-tmp-external-arm-toolchain/deploy/images/am335x-evm/fresca-base-image-swu-am335x-evm-*.swu`
#function: cp .swu file to SD card
function cp_swu_file_2_sd_card()
{
	cp $TARGET_SWU_FILE /media/book/$DIR_NAME
}



if [ $DIR_QTY -gt 1 ]; then
	echo "Error:Please insert a right SD car"
elif [ $DIR_QTY -eq 1 ]; then
	echo "start to cp $TARGET_SWU_FILE to SD card"
	cp_swu_file_2_sd_card
	if [[ $? == 0 ]]; then
		echo "copy success"
	fi
elif [ $DIR_QTY -eq 0 ]; then
	echo "Please insert your SD card!"
	exit	
fi

rm $TMP_STORE_FILE

echo "STEP 3 done"
echo "Finish, you can update your airbox now!"


