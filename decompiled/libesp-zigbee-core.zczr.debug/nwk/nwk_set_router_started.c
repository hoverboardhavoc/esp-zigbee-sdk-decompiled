/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_set_router_started
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_set_router_started(uint param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != 1) || (iVar1 = nwk_is_device_zczr(), iVar1 != 0)) {
    iVar1 = core_globals_get();
    *(byte *)(iVar1 + 0xb18) = *(byte *)(iVar1 + 0xb18) & 0xfd | (byte)((param_1 & 1) << 1);
    return iVar1 + 0x1000;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_internal.h",0x23,
                        "nwk_set_router_started","started == 0 || nwk_is_device_zczr()");
  if (iVar1 == 0xffff) {
    iVar1 = 1;
  }
  else {
    if ((iVar1 == 0xfffd) && (iVar2 = core_globals_get(), *(char *)(iVar2 + 0x9ee) != '\0')) {
      return 1;
    }
    if ((iVar1 == 0xfffc) && (iVar2 = nwk_is_device_zczr(), iVar2 != 0)) {
      iVar1 = 1;
    }
    else if (iVar1 == 0xfffb) {
      iVar1 = nwk_is_device_zr();
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = core_globals_get();
        if (*(char *)(iVar1 + 0x9ee) == '\0') {
          iVar1 = 1;
        }
        else {
          iVar1 = 0;
        }
      }
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}

