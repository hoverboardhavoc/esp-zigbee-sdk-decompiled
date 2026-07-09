/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_attr_desc_set_manuf_code
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_attr_desc_set_manuf_code(int param_1,undefined2 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_desc.c",0xbb,
                  "zcl_attr_desc_set_manuf_code","attr_desc");
  }
  else {
    iVar1 = af_device_desc_is_registered();
    if (iVar1 == 0) {
      *(undefined2 *)(param_1 + 4) = param_2;
      return 0;
    }
  }
  return 3;
}

