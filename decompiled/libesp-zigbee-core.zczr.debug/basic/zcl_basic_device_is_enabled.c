/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> basic.o -> zcl_basic_device_is_enabled
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_basic_device_is_enabled(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zcl_get_attr_desc(0,1,0x12,0);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else if (**(char **)(iVar1 + 8) == '\0') {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

