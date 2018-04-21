echo "deb http://http.kali.org/kali kali-rolling main contrib non-free
deb-src http://http.kali.org/kali kali-rolling main contrib non-free" > /etc/apt/sources.list
git clone http://github.com/dodonut/codes ~/Downloads/codes
apt-get update
dpkg -i ~/Downloads/*.deb
apt --fix-broken install -y
dpkg -i ~/Downloads/*.deb
