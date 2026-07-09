/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_is_device_in_bcast_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte nwk_is_device_in_bcast_group(int param_1)

{
  byte bVar1;
  int iVar2;
  
  if (param_1 != 0xffff) {
    if (param_1 == 0xfffd) {
      iVar2 = core_globals_get();
      bVar1 = *(byte *)(iVar2 + 0x9ee);
    }
    else if (param_1 == 0xfffc) {
      bVar1 = nwk_is_device_zczr();
    }
    else if ((param_1 == 0xfffb) && (iVar2 = nwk_is_device_zr(), iVar2 != 0)) {
      iVar2 = core_globals_get();
      bVar1 = *(byte *)(iVar2 + 0x9ee) ^ 1;
    }
    else {
      bVar1 = 0;
    }
    return bVar1 & 1;
  }
  return 1;
}

