/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> basic.o -> zcl_basic_device_is_enabled
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool zcl_basic_device_is_enabled(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = zcl_get_attr_desc(0,1,0x12,0);
  if (iVar2 == 0) {
    bVar1 = true;
  }
  else {
    bVar1 = **(char **)(iVar2 + 8) != '\0';
  }
  return bVar1;
}

