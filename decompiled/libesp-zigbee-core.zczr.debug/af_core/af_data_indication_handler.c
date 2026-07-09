/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_data_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void af_data_indication_handler(int param_1)

{
  short sVar1;
  
  if ((param_1 == 0) || (*(char *)(param_1 + 7) == -1)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_core.c",0x72,
                  "af_data_indication_handler","ind && ind->addr_info.dst_ep != 0xFFU");
  }
  else {
    sVar1 = *(short *)(param_1 + 10);
    if ((sVar1 != 0x104) && (sVar1 != -0x3fa2)) {
      if (sVar1 == 0) {
        zdo_indication_handler();
      }
      goto _L0;
    }
  }
  zcl_indication_handler(param_1);
_L0:
  zmsg_free(*(undefined4 *)(param_1 + 0x10));
  return;
}

