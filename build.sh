#!/usr/bin/env sh
QMK_V=0.7.13
FIRMWARE_FOLDER=qmk_firmware
QMK_REPO=https://github.com/qmk/qmk_firmware

die() { echo $@ && exit 1; }

initialize() {
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

maketask() {
  docker run -it \
    -e MIDI_ENABLE=yes \
    -e keymap=$KEYMAP \
    --privileged  \
    -v `pwd`/qmk_firmware:/qmk \
    -v /dev:/dev \
    qmkf make $TASK
}

build_kb() {
  echo "Building $1"
  cp --parents -r keyboards/*/* $FIRMWARE_FOLDER/

  if [ "$1" = "hhkb" ]; then
    KEYMAP=milhhkb
    TASK=hhkb:dfu
    maketask
  fi

  if [ "$1" = "iris" ]; then
    KEYMAP=miliris_qwert
    TASK=iris/rev2:avrdude
    maketask
  fi

  if [ "$1" = "atreus" ]; then
    KEYMAP=milatreus
    TASK=atreus:milatreus:avrdude
    maketask
  fi

  if [ "$1" = "conv" ]; then
    KEYMAP=milconv
    TASK=converter/usb_usb:milconv:dfu
    maketask
  fi

  if [ "$1" = "ploopy" ]; then
    KEYMAP=milploopy
    TASK=ploopyco/trackball_mini
    maketask
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
