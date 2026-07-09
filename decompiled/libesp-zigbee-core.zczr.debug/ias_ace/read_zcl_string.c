/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> read_zcl_string
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 read_zcl_string(int param_1,int param_2,byte *param_3,uint param_4)

{
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == (byte *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0xc5,
                  "read_zcl_string","payload && offset && string");
  }
  else {
    af_read_le8();
    if (*param_3 < param_4) {
      af_read_bytes(param_1,param_2,param_3 + 1);
      return 0;
    }
  }
  return 0x87;
}

