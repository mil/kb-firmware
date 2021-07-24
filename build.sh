#!/usr/bin/env sh
set -x 
QMK_V=0.13.25
FIRMWARE_FOLDER=qmk_firmware
QMK_REPO=https://github.com/qmk/qmk_firmware

die() { echo $@ && exit 1; }

initialize() {
  cd "$(dirname "$0")"
  git clone $QMK_REPO --depth 1 --branch $QMK_V $FIRMWARE_FOLDER || echo "already cloned"
  cd $FIRMWARE_FOLDER
  git checkout $QMK_V || die "Need version $QMK_V -- probably: rm $FIRMWARE_FOLDER"
  echo "Found qmk_firmware repo with version $QMK_V"
  make git-submodule
  git clean -f
  cd ..
}

maketask() {
  cd $FIRMWARE_FOLDER/
  doas ./util/docker_build.sh "$1"
}

build_kb() {
  echo "Building $1"
  cp --parents -r keyboards/*/* $FIRMWARE_FOLDER/

  if [ "$1" = "hhkb" ]; then
    maketask hhkb:milhhkb:dfu
  elif [ "$1" = "iris" ]; then
    maketask iris/rev2:miliris_qwert:avrdude
  elif [ "$1" = "atreus" ]; then
    maketask atreus:milatreus:avrdude
  elif [ "$1" = "conv" ]; then
    maketask converter/usb_usb:milconv:dfu
  elif [ "$1" = "ploopy" ]; then
    maketask ploopyco/trackball_mini/rev1_002:milploopy:flash
  fi
}

initialize
build_kb $@
