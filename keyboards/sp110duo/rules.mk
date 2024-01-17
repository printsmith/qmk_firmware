# Defs
VIA_ENABLE 				= yes
ENCODER_MAP_ENABLE 		= yes
CUSTOM_MATRIX 			= lite
SRC 					+= matrix.c
# Quantum Painter defs
QUANTUM_PAINTER_ENABLE 			= yes
QUANTUM_PAINTER_DRIVERS 		+= st7735_spi
#QUANTUM_PAINTER_LVGL_INTEGRATION = yes
SRC	+= graphics/qmk_logo.qgf.c
