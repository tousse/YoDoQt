#!/bin/bash
#Cmd : $1
#First_Param : $2

var_control=0

if [ $1 = "pass2" ]
then 	
	echo $2 | sudo -S -k gparted
fi

if [ $1 = "pass" ]
then	
	echo $2 | sudo -S -k apt install git
	echo $2 | sudo -S -k apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib \
     build-essential chrpath socat cpio python python3 python3-pip python3-pexpect \
     xz-utils debianutils iputils-ping libsdl1.2-dev xterm
	#echo "8%"
	#var_control=1
fi

if [ $1 = "88" ]
then 	
	echo "88"
	echo "Poky Download"
	#cd scripts
	rm -rf poky
	rm -rf meta-openembedded
	rm -rf meta-qt5
	rm -rf meta-raspberrypi
	git clone -b thud git://git.yoctoproject.org/poky.git poky
	#git clone -b thud git://git.yoctoproject.org/poky.git poky-thud4
	cd poky
	
	echo "25"
	echo "Poky OpenEmbedded"
	git clone -b thud git://git.openembedded.org/meta-openembedded
	echo "50"
	echo "Poky Qt5"
	git clone -b thud https://github.com/meta-qt5/meta-qt5
	echo "75"
	echo "Poky Raspberry"
	git clone -b thud git://git.yoctoproject.org/meta-raspberrypi
	echo "100" 
fi

if [ $1 = "25" ]
then 
	#cd scripts
	cd poky	
	rm -rf meta-openembedded
	rm -rf meta-qt5
	rm -rf meta-raspberrypi
	echo "Poky OpenEmbedded"
	git clone -b thud git://git.openembedded.org/meta-openembedded
	echo "50"
	echo "Poky Qt5"
	git clone -b thud https://github.com/meta-qt5/meta-qt5
	echo "75"
	echo "Poky Raspberry"
	git clone -b thud git://git.yoctoproject.org/meta-raspberrypi
	echo "100"
fi

if [ $1 = "50" ]
then 
	#cd scripts
	cd poky
	rm -rf meta-qt5
	rm -rf meta-raspberrypi
	echo "Poky Qt5"
	git clone -b thud https://github.com/meta-qt5/meta-qt5
	echo "75"
	echo "Poky Raspberry"
	git clone -b thud git://git.yoctoproject.org/meta-raspberrypi
	echo "100"
fi

if [ $1 = "75" ]
then 
	#cd scripts
	cd poky
	rm -rf meta-raspberrypi
	echo "Poky Raspberry"
	git clone -b thud git://git.yoctoproject.org/meta-raspberrypi
	echo "100"
fi

if [ $1 = "bitbake" ]
then 	
	cd poky
	source oe-init-build-env $2
	cd $2
	bitbake core-image-base
fi

if [ $1 = "sd" ]
then
#if=poky/rpi-tst/build/tmp/deploy/images/raspberrypi-cm3/core-image-minimal-raspberrypi-cm3.rpi-sdimg
sudo dd $2 of=/dev/sdc bs=1M
fi

if [ $1 = "kill" ]
then 

ps ax | grep $2 | cut -f1 -d" " - | xargs kill -9

ps ax | grep $2 | cut -f2 -d" " - | xargs kill -9
#ps ax | grep $2 | cut -f2 -d" " - | xargs kill -9


fi

#echo "$SOMEVAR"


