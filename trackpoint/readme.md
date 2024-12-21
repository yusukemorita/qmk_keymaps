# Trackpoint test firmware

A minimal qmk firmware to test trackpoint modules, with no keys.

## Compile locally

Reference the steps in `.github/workflows/build_trackpoint.yml` for setting up qmk locally.

```
qmk compile -kb trackpoint --keymap default
```

lint
```
qmk lint -kb trackpoint
```

## Reference

- [IBM Trackpoint demonstration](https://github.com/qmk/qmk_firmware/tree/master/keyboards/handwired/trackpoint): example implementation of IBM Trackpoint integration in QMK
