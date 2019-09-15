F_CPU = 16000000
EXTRAFLAGS=-flto 
MIDI_ENABLE = yes
MOUSEKEY_ENABLE = no
CONSOLE_ENABLE = no

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
