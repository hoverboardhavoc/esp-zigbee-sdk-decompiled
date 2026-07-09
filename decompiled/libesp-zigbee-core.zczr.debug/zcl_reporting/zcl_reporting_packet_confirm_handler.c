/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_packet_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_reporting_packet_confirm_handler(int param_1,int param_2)

{
  int *unaff_s0;
  int iVar1;
  
  if ((param_1 != 0) && (param_2 == 0)) {
    iVar1 = core_globals_get();
    iVar1 = *(int *)(iVar1 + 0xd34);
    while (unaff_s0 = (int *)(iVar1 + -4), unaff_s0 != (int *)0xfffffffc) {
      if ((unaff_s0 != (int *)0x0) && (iVar1 = *unaff_s0, (*(byte *)(iVar1 + 9) & 0xf) == 4)) {
        *(byte *)(iVar1 + 9) = *(byte *)(iVar1 + 9) & 0xf0 | 1;
        process_attr_report(*unaff_s0);
      }
_L0:
      iVar1 = unaff_s0[1];
    }
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_reporting.c",0x2a5,
                "zcl_reporting_packet_confirm_handler","info && ctx == ((void *)0)");
  goto _L0;
}

