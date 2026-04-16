/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_packet_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_reporting_packet_confirm_handler(zcl_packet_cnf_t *info,void *ctx)

{
  int *piVar1;
  int iVar2;
  zcl_reporting_info_t *info_00;
  
  if ((info == (zcl_packet_cnf_t *)0x0) || (ctx != (void *)0x0)) {
    __assert_func(0,0,0,0);
  }
  iVar2 = core_globals_get();
  for (piVar1 = *(int **)(iVar2 + 0xd98); piVar1 + -1 != (undefined4 *)0xfffffffc;
      piVar1 = (int *)*piVar1) {
    info_00 = (zcl_reporting_info_t *)piVar1[-1];
    if ((info_00->field_0x9 & 0xf) == 4) {
      info_00->field_0x9 = info_00->field_0x9 & 0xf0 | 1;
      process_attr_report(info_00);
    }
  }
  return;
}

