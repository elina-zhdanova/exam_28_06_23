FROM ubuntu:18.04
ENV TZ=Europe/Moscow
LABEL maintainer="Zhdanova Elina"
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone  
      RUN apt-get update  
      RUN apt-get install qt5-default -y  
      RUN apt-get install qtbase5-dev -y  
      RUN apt-get install qt5-qmake  
      RUN apt-get install build-essential -y 


WORKDIR /labs-elina-zhdanova
COPY . /labs-elina-zhdanova

RUN qmake mySer.pro && make
CMD ["./mySer","param"]
