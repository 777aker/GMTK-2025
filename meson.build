project('choop', 'cpp', version : '0.1.0', default_options : ['cpp_std=c++20'])

boost_dep = dependency('boost')
glut_dep = dependency('glut')
glfw_dep = dependency('glfw3')

choop_sources = [
    'window/window.cpp',
    'window/shader.cpp',
    'window/loadtexbmp.cpp',
    'ui/button.cpp',
    'ui/number_field.cpp',
    'pieces/bishop.cpp',
    'pieces/king.cpp',
    'pieces/knight.cpp',
    'pieces/pawn.cpp',
    'pieces/piece.cpp',
    'pieces/queen.cpp',
    'pieces/rook.cpp',
    'main/board.cpp',
    'main/main.cpp',
    'main/stockfish.cpp'
]

executable('choop',
    sources : choop_sources,
    dependencies: [boost_dep, glut_dep, glfw_dep],
    link_args : ['-lglfw', '-lGLU', '-lGL', '-lm'])