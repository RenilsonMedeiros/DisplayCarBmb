# Painel do Veículo Baja - Equipe BMB

<img src="https://img.shields.io/badge/BMB-Bem%20Vindo-%2300b1ff"> ![GitHub](https://img.shields.io/github/license/RenilsonMedeiros/DisplayCarBmb?color=%2300b1ff&style=flat)
![GitHub top language](https://img.shields.io/github/languages/top/RenilsonMedeiros/DisplayCarBmb?color=%2300b1ff&style=flat)
![YouTube Video Views](https://img.shields.io/youtube/views/_Dg29awgiN8?style=social) <img src="https://img.shields.io/badge/Follow%20@bumbameubaja-1k-black?style=social&logo=instagram">

* [Interface](#Interface)

## Interface
<p align="center">
  <img src="https://github.com/RenilsonMedeiros/DisplayCarBmb/blob/main/src/toReadme/painelBaja.png">
</p>

:car: A interface contém todos os dados mais importantes ao piloto durante a corrida na competição: **velocidade**, **rotação do motor**,**nível de combustível** e alguns avisos relacionado a temperatura da CVT, carga da bateria e outros.

:car: Para alguns valores desses parâmetros existe uma imagem que representa o seu nível nos medidores, no diretório [src](https://github.com/RenilsonMedeiros/DisplayCarBmb/tree/main/src) tem todas as pastas que contém essas imagens, por exemplo, na pasta [velocimetro](https://github.com/RenilsonMedeiros/DisplayCarBmb/tree/main/src/Velocimetro) contém as imagens referente ao medidor de velocidade.

:car: O Arduino Uno é responsável por mapear os dados obtidos pelos sensores e mudar as imagens. Elas, por sua vez, ficam armazenadas no display [Nextion](https://pt.aliexpress.com/item/32506009338.html?src=google&albch=shopping&acnt=768-202-3196&isdl=y&aff_short_key=UneMJZVf&slnk=&plac=&mtctp=&albbt=Google_7_shopping&aff_platform=google&&isSmbAutoCall=false&needSmbHouyi=false&albcp=11863430619&albag=120632188052&trgt=1073690845846&crea=pt32506009338&netw=u&device=c&albpg=1073690845846&albpd=pt32506009338&gclid=CjwKCAjwu5CDBhB9EiwA0w6sLQFMIDNWWHwQ6eoalUnVkqpPblk0WW1vb_gjGMTeEn72_E3sRUVmdRoCxI4QAvD_BwE&gclsrc=aw.ds) e renderizadas por ele.

<p align="center">
  <img alt="Renderização das imagens" src="https://github.com/RenilsonMedeiros/DisplayCarBmb/blob/main/src/toReadme/painelBajaGif.gif">
</p>
