#!/usr/bin/env sh
QMK_V=0.7.13
FIRMWARE_FOLDER=qmk_firmware
QMK_REPO=https://github.com/qmk/qmk_firmware

function die() { echo $@ && exit 1; }

function initialize() {
  # TODO: maybe move this to be within docker?
  cd "$(dirname "$0")"
  git clone $QMK_REPO --depth 1 --branch $QMK_V $FIRMWARE_FOLDER || echo "already cloned"
  cd $FIRMWARE_FOLDER
  git checkout $QMK_V || die "Need version $QMK_V -- probably: rm $FIRMWARE_FOLDER"
  echo "Found qmk_firmware repo with version $QMK_V"
  make git-submodule
  git clean -f
  cd ..
  docker build -t qmkf .
}

function build_kb() {
  echo "Building $1"
  cp --parents -r keyboards/*/* $FIRMWARE_FOLDER/
  if [ "$1" = "hhkb" ]; then
    #docker run -e MIDI_ENABLE=yes -e keymap=milhhkb -e subproject="" -e keyboard=hhkb --rm -v $(pwd):/qmk:rw qmkf
    #MIDI_ENABLE=yes keymap=milhhkb keyboard=hhkb make
    #sudo dfu-programmer atmega32u4 erase
    #sudo dfu-programmer atmega32u4 flash hhkb_milhhkb.hex

    docker run -it \
      -e MIDI_ENABLE=yes \
      -e keymap=milhhkb \
      --privileged  \
      -v `pwd`/qmk_firmware:/qmk \
      -v /dev:/dev \
      qmkf make hhkb:dfu
  fi

  if [ "$1" = "iris" ]; then
    docker run -it \
      -e MIDI_ENABLE=yes \
      -e keymap=miliris_qwert  \
      --privileged  \
      -v `pwd`/qmk_firmware:/qmk \
      -v /dev:/dev \
      qmkf make iris/rev2:avrdude
  fi

  if [ "$1" = "atreus" ]; then
    docker run -it \
      -e MIDI_ENABLE=yes \
      -e keymap=milatreus \
      --privileged  \
      -v `pwd`/qmk_firmware:/qmk \
      -v /dev:/dev \
      qmkf make atreus:milatreus:avrdude
  fi

  if [ "$1" = "conv" ]; then
    docker run -it \
      -e MIDI_ENABLE=yes \
      -e keymap=milconv \
      --privileged  \
      -v `pwd`/qmk_firmware:/qmk \
      -v /dev:/dev \
      qmkf make converter/usb_usb:milconv:dfu
  fi

  if [ "$1" = "shell" ]; then
    docker run -it \
      --privileged  \
      -v `pwd`/qmk_firmware:/qmk \
      -v /dev:/dev \
      qmkf sh
  fi
}

initialize
build_kb $@
