/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_scan(int param_1,int param_2,char *param_3,undefined1 param_4)

{
  uint uVar1;
  
  if (param_2 - 1U < 2) {
    *(undefined1 *)(param_1 + 0x33) = param_4;
    *(undefined1 *)(param_1 + 0x32) = 0xff;
    *(uint *)(param_1 + 0x34) =
         *(uint *)(param_1 + 0x34) & 0x7ffffff | ((uint)param_3 >> 0x1b) << 0x1b;
    if ((uint)param_3 >> 0x1b != *(uint *)(param_1 + 0x18) >> 0x1b) {
      *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0xf8000000;
      goto _L0;
    }
  }
  else {
    param_3 = "mac_scan";
    param_1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x2ee,
                            "scan_op == MAC_OPERATION_ACTIVE_SCAN || scan_op == MAC_OPERATION_ED_SCAN"
                           );
  }
  uVar1 = *(uint *)(param_1 + 0x34) & 0xf8000000;
  *(uint *)(param_1 + 0x34) = uVar1 | (uint)param_3 & 0x7ffffff;
  *(uint *)(param_1 + 0x34) =
       uVar1 | (uint)param_3 & 0x7ffffff & *(uint *)(param_1 + 0x18) & 0x7ffffff;
_L0:
  mac_start_op();
  return;
}

