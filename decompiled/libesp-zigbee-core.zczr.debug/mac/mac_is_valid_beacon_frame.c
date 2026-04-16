/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_is_valid_beacon_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool mac_is_valid_beacon_frame(mac_frame_t *frame)

{
  ushort *puVar1;
  
  if (((frame->mhr).fcf & 7) != 0) {
    return false;
  }
  if ((frame->mpl).len < 4) {
    return false;
  }
  puVar1 = (ushort *)(frame->mpl).buf;
  if ((char)puVar1[1] != '\0') {
    return false;
  }
  if (*(char *)((int)puVar1 + 3) == '\0') {
    if ((*puVar1 & 0xfff) != 0xfff) {
      return false;
    }
    return true;
  }
  return false;
}

