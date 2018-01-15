# Глобальная минимизация многомерной функции

Пространство поиска заполняется равномерной сеткой, а затем из каждого узла этой сетки запускаются три разных алгоритма поиска локального минимума. Все локальные минимумы сравниваются между собой и из них выбирается глобальный.

## Виды сеток:
* Sobol

## Алгоритмы локальной минимизации:
1. BFGS
2. Hessian Free
3. Nesterov

Статус сборки для worldfly/minimization/develop: ![alt text](https://travis-ci.org/worldfly/minimization.svg?branch=develop)

## Инструкция по возможной сборке проекта на Windows

В одном из вариантов сборки проекта на Windows предполагается наличие следующих утилит:
* Утилита cmake
* Утилита make
* Компилятор MinGW x64 (желательно последней версии) с поддержкой posix threads

Рассмотрим самый быстрый процесс установки всего необходимого для сборки и запуска проекта в данном варианте. Для этого понадобится только утилита msys2, которую можно скачать с официального сайта http://www.msys2.org/.

После установки msys2 необходимо открыть терминал cmd.exe и запустить msys2 командой:

    C:\msys64\msys2_shell.cmd -mingw64

Затем необходимо выполнить обновление баз данных пакетов:

    pacman -Syu

После успешного завершения данной команды может потребоваться закрытие окна терминала msys2 с последующим повторным открытием командой: 

    C:\msys64\msys2_shell.cmd -mingw64

Далее необходимо запустить полное обновление всех пакетов командой: 

    pacman -Su

И установить требуемые для сборки проекта утилиты командой:

    pacman -S mingw-w64-x86_64-gcc make mingw-w64-x86_64-cmake

Процесс установки и обновления всех пакетов завершен. Чтобы собрать проект и запустить, можно выполнить скрипт compile.bat в директории проекта.
