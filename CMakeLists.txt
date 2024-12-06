# Mínima versão requerida do CMake
cmake_minimum_required(VERSION 3.22.1)

# Nome do projeto
project(BlocksProject)

# Configuração do padrão de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adicionar todos os arquivos .cpp automaticamente
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(Blocks ${SOURCES})

# Adicionar o diretório dos arquivos .h para incluir
include_directories(src)

# Especificar o caminho da bibliotecas
link_directories(/usr/local/lib)

# Ligar bibliotecas ao projeto
target_link_libraries(Blocks
    raylib
    GL
    m
    pthread
    dl
    rt
    X11
)
