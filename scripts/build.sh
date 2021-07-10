#!/usr/bin/env ash

rm -rf bin

PLATFORM=${TARGET:-i686-elf}

find src -name "*.s" -print0 | while IFS= read -r -d $'\0' file; do
    CURRENT_DIR=$(dirname $file | sed s/src/bin/)
    mkdir -p $CURRENT_DIR
    $PLATFORM-as $file -o $CURRENT_DIR/$(basename $file .s).o -I lib
done

find src -name "*.c" -print0 | while IFS= read -r -d $'\0' file; do
    CURRENT_DIR=$(dirname $file | sed s/src/bin/)
    mkdir -p $CURRENT_DIR
    $PLATFORM-gcc -I src/kernel -I lib/ -c $file -o $CURRENT_DIR/$(basename $file .c).o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
done

$PLATFORM-gcc -T linker.ld -o bin/buildos.bin -ffreestanding -O2 -nostdlib $(find bin -name "*.o") -lgcc

if grub-file --is-x86-multiboot bin/buildos.bin; then
  echo multiboot confirmed
else
  echo the file is not multiboot
fi
