#!/bin/bash
#
# This script is called from VDR to mount/unmount/eject
# the sources for MP3 play and/or image sources,
#
# argument 1: wanted action, one of mount,unmount,eject,status
# argument 2: mountpoint to act on
#
# mount,unmount,eject must return 0 if succeeded, 1 if failed
# status must return 0 if device is mounted, 1 if not
#
# ok -> changed mount to not abort, if eject -t did fail, e.g. for a usb storage device

action="$1"
path="$2"

case "$action" in
mount)
  eject -t "$path"  &>/dev/null      # close the tray, but not do/print anything if that fails
  mount "$path" || exit 1            # mount it
  ;;
unmount)
  umount "$path" || exit 1           # unmount it
  ;;
eject)
  eject "$path" || exit 1         # eject disk
  ;;
status)
  cat /proc/mounts | grep -q "$path" # check if mounted
  if [ $? -ne 0 ]; then              # not mounted ...
    exit 1
  fi
esac

exit 0
