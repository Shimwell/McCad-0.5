

sudo mount -t vboxsf ubuntu15 /mnt/share
sudo apt-get install openmpi-bin openmpi-doc libopenmpi-dev
sudo apt-get install libx11-dev

install mcnp6 and 611
change plasma file name , subrouting start and end
make build CONFIG="gfortran openmpi"

sudo apt-get install tk8.5-dev
sudo apt-get install ftgl-dev
sudo apt-get install libxmu-dev
sudo apt-get install libqt4-dev
sudo apt-get install wget

sudo wget -O OCE-0.9.0.tar.gz https://github.com/tpaviot/oce/archive/OCE-0.9.0.tar.gz

sudo tar -xzvf OCE-0.9.0.tar.gz
cd oce-OCE-0.9.0
mkdir build
cd build
cmake ..
make
sudo make install

touch ~/.bashrc
echo "export CASROOT=/usr/local/share/oce-0.9.0" >> ~/.bashrc
echo "export export CSF_GraphicShr=/usr/local/lib/libTKOpenGl.so" >> ~/.bashrc
echo "export export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib" >> ~/.bashrc
echo "export export CSF_MDTVFontDirectory=$CASROOT/src/FontMFT" >> ~/.bashrc
echo "export CSF_LANGUAGE=us" >> ~/.bashrc
echo "export MMGT_CLEAR=1" >> ~/.bashrc
echo "export CSF_EXCEPTION_PROMPT=1" >> ~/.bashrc
echo "export CSF_SHMessage=$CASROOT/src/SHMessage" >> ~/.bashrc
echo "export CSF_MDTVTexturesDirectory=$CASROOT/src/Textures" >> ~/.bashrc
echo "export CSF_XSMessage=$CASROOT/src/XSMessage" >> ~/.bashrc
echo "export CSF_StandardDefaults=$CASROOT/src/StdResource" >> ~/.bashrc
echo "export CSF_PluginDefaults=$CASROOT/src/StdResource" >> ~/.bashrc
echo "export CSF_XCAFDefaults=$CASROOT/src/StdResource" >> ~/.bashrc
echo "export CSF_StandardLiteDefaults=$CASROOT/src/StdResource" >> ~/.bashrc
echo "export CSF_UnitsLexicon=$CASROOT/src/UnitsAPI/Lexi_Expr.dat" >> ~/.bashrc
echo "export CSF_UnitsDefinition=$CASROOT/src/UnitsAPI/Units.dat" >> ~/.bashrc
echo "export CSF_IGESDefaults=$CASROOT/src/XSTEPResource" >> ~/.bashrc
echo "export CSF_STEPDefaults=$CASROOT/src/XSTEPResource" >> ~/.bashrc
echo "export CSF_XmlOcafResource=$CASROOT/src/XmlOcafResource" >> ~/.bashrc
echo "export CSF_MIGRATION_TYPES=$CASROOT/src/StdResource/MigrationSheet.txt" >> ~/.bashrc

source ~/.bashrc

cd $HOME
git clone https://github.com/McCadKIT/McCad.git
#mkdir McCad
#cp -a /mnt/share/McCadTrunkD .
#cp McCadTrunkD McCad


cd McCad
mkdir build && cd build
cmake ..
cd ../../ 
#sudo find McCad -type -f -exec touch {} +
#sudo -type f -exec touch {} +
make
sudo make install

