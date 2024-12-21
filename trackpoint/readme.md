# Trackpoint test firmware

A minimal qmk firmware to test trackpoint modules, with no keys.

## Compile locally

Reference the steps in `.github/workflows/build_trackpoint.yml` for setting up qmk locally.

compile
```
qmk compile -kb trackpoint --keymap default
```

lint
```
qmk lint -kb trackpoint
```

## Reference

- [PS/2 Mouse Support](https://docs.qmk.fm/features/ps2_mouse): official QMK docs on PS/2 mouse support
- [IBM Trackpoint demonstration](https://github.com/qmk/qmk_firmware/tree/master/keyboards/handwired/trackpoint): example implementation of IBM Trackpoint integration in QMK
- [How to integrate a trackpoint in a mechanical keyboard](https://github.com/alonswartz/trackpoint): detailed instructions about hardware (and TMK firmware)
