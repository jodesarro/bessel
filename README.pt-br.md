# Funções de Bessel <img src="https://github.com/jodesarro/bessel-library/blob/master/cyl-j0.gif" height=30px>

<p align="right"><a href="https://github.com/jodesarro/bessel-library/blob/master/README.md">Read this in english</a></p>

Uma biblioteca em C++ com rotinas para calcular as funções de Bessel para argumentos reais ou complexos.

## Como usar

A bibliotea está em estilo *header-only* (apenas cabeçalho), ou seja, não é necessário compilá-la separadamente, você só precisa incluir o arquivo *bessel-library.hpp* no seu projeto.
Veja <a href="https://github.com/jodesarro/bessel-library/blob/master/usage-example.cpp">usage-example.cpp</a> como exemplo de uso.

## Recursos

Recursos disponíveis
- Função cilíndrica de Bessel de ordem zero para argumentos reais e compexos, *J*<sub>0</sub>(*z*);
  - `bessel::cyl_j0(z)`

Recursos em desenvolvimento
- Função cilíndrica de Bessel de ordem inteira para argumentos reais e compexos, *J<sub>n</sub>*(*z*);

## Accuracy

A biblioteca foi construída para obter (sem garantias) dígitos de precisão suficientes para os tipos `float` (seis digitos), `double` (quinze digitos) e `long double` (dezenove digitos) no compilador *MinGW-W64-builds-4.3.5*.

#### *J*<sub>0</sub>(*z*)

Para o tipo `long double`, a função `bessel::cyl_j0(z)` não atinge precisão suficiente somente quando <nobr>5 ≤ Re{*z*} ≤ 20</nobr>, onde Re{*z*} é a parte real do argumento *z*.

Para <nobr>Re{*z*} > 20</nobr>, `bessel::cyl_j0(z)` depende fortemente da precisão das funções `std::sin(z)` e `std::cos(z)`.

## Licensing

Este projeto está protegido sob a licensa <a href="https://github.com/jodesarro/bessel-library/blob/master/LICENSE">MIT License</a> e tem [@jodesarro]( https://github.com/jodesarro ) como seu principal autor.
