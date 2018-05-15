dpkg --add-architecture i386
apt-get update
apt-get install -y libc6:i386 libncurses5:i386 libstdc++6:i386
apt-get install -y gcc-multilib g++-multilib
apt-get install -y binutils
apt-get install -y socat nasm
apt-get install -y vim

wget https://github.com/downloads/0vercl0k/rp/rp-lin-x86
chmod +x rp-lin-x86
mv rp-lin-x86 /usr/local/bin

wget https://github.com/downloads/0vercl0k/rp/rp-lin-x64
chmod +x rp-lin-x64
mv rp-lin-x64 /usr/local/bin

git clone https://github.com/longld/peda.git ~/peda
echo "source ~/peda/peda.py" >> ~/.gdbinit

git config --global user.email "01ssrmikururudevice01@gmail.com"
git config --global user.name "happynote3966"

