
FROM ubuntu:18.04
RUN apt-get update -y && \
    apt-get upgrade -y

RUN apt-get install -y cmake
RUN apt-get install -y g++
RUN apt-get install -y build-essential


RUN apt-get install -y openmpi-bin openmpi-doc libopenmpi-dev
RUN apt-get install -y libx11-dev
ENV DEBIAN_FRONTEND noninteractive
RUN apt-get install  -y tk8.5-dev
RUN apt-get update -y


RUN apt-get install  -y libxmu-dev
RUN apt-get install  -y libqt4-dev
RUN apt-get install  -y wget

RUN wget -O OCE-0.9.0.tar.gz https://github.com/tpaviot/oce/archive/OCE-0.9.0.tar.gz

# not sure why this is not being found #ftgl-dev
RUN apt-get install  -y libftgl-dev 

RUN tar -xzvf OCE-0.9.0.tar.gz
RUN cd oce-OCE-0.9.0 && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    make install


ENV CASROOT=/usr/local/share/oce-0.9.0
ENV export CSF_GraphicShr=/usr/local/lib/libTKOpenGl.so
ENV export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
ENV export CSF_MDTVFontDirectory=$CASROOT/src/FontMFT
ENV CSF_LANGUAGE=us
ENV MMGT_CLEAR=1
ENV CSF_EXCEPTION_PROMPT=1
ENV CSF_SHMessage=$CASROOT/src/SHMessage
ENV CSF_MDTVTexturesDirectory=$CASROOT/src/Textures
ENV CSF_XSMessage=$CASROOT/src/XSMessage
ENV CSF_StandardDefaults=$CASROOT/src/StdResource
ENV CSF_PluginDefaults=$CASROOT/src/StdResource
ENV CSF_XCAFDefaults=$CASROOT/src/StdResource
ENV CSF_StandardLiteDefaults=$CASROOT/src/StdResource
ENV CSF_UnitsLexicon=$CASROOT/src/UnitsAPI/Lexi_Expr.dat
ENV CSF_UnitsDefinition=$CASROOT/src/UnitsAPI/Units.dat
ENV CSF_IGESDefaults=$CASROOT/src/XSTEPResource
ENV CSF_STEPDefaults=$CASROOT/src/XSTEPResource
ENV CSF_XmlOcafResource=$CASROOT/src/XmlOcafResource
ENV CSF_MIGRATION_TYPES=$CASROOT/src/StdResource/MigrationSheet.txt





COPY src/ mccad/src/
COPY CMakeLists.txt mccad/CMakeLists.txt 

# RUN rm -rf build
RUN mkdir mccad/build && \
    cd mccad/build && \
    cmake .. && \
    make && \
    make install
