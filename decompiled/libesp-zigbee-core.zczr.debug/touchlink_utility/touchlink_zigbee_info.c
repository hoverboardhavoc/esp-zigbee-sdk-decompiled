/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_zigbee_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t touchlink_zigbee_info(void)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = nwk_is_device_zc();
  if (iVar2 == 0) {
    iVar2 = nwk_is_device_zr();
    if (iVar2 != 0) {
      uVar1 = 1;
      goto _L0;
    }
    iVar2 = nwk_is_device_zed();
    if (iVar2 != 0) {
      uVar1 = 2;
      goto _L0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink_utility.c",0xca,
                  "touchlink_zigbee_info",&_L0);
  }
  uVar1 = 0;
_L0:
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0x9ee) != '\0') {
    uVar1 = uVar1 | 4;
  }
  return uVar1;
}

