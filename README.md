# vt_paltab
This repository contains three palette-related tools for VTxx Famiclones: `paltab`, `vt32pal`, and `vt369pal`.

## paltab
`paltab` converts various `.tab` palette files (found in EmuVT and PIC32VT) to RGB888 triplets.

For best results, files should consist of the first 65,536 bytes (64KiB) of the original `.tab` files.
Pre-trimmed input files are included in the `in_tab` directory.

The original `.tab` files use 4 bytes per color, with the last byte of each group being unused.

### Usage
`paltab infile outfile`

## vt32pal
`vt32pal` generates the RGB444 palette used on VT32 machines.

Two versions are available: a normal one, and a "blue cast removal" version
that is intended to match real hardware.

### Usage
`vt32pal_normal outfile` or `vt32pal_bluecastremoval outfile`, depending on version.

## vt369pal
`vt369pal` generates the RGB555 palette used on VT369 machines.

### Usage
`vt369pal outfile`

## Dealing With the Output
Each program outputs a file with RGB triplets (3 bytes per color).

[Binxelview](https://github.com/bbbradsmith/binxelview/releases) can be used to
view the files using the following settings:

- Preset: 24bpp
- Width: 16 (non-VT369) or 32 (VT369)
- Height: 16 (non-VT369) or 32 (VT369)

## License
Unlicense; see `LICENSE` file for more information.
