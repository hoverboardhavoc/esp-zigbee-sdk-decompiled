/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_packet_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_reporting_packet_confirm_handler(zcl_packet_cnf_t *info,void *ctx)

{
  int *unaff_s0;
  int iVar1;
  
  if ((info != (zcl_packet_cnf_t *)0x0) && (ctx == (void *)0x0)) {
    iVar1 = core_globals_get();
    iVar1 = *(int *)(iVar1 + 0xd98);
    while (unaff_s0 = (int *)(iVar1 + -4), unaff_s0 != (int *)0xfffffffc) {
      if ((unaff_s0 != (int *)0x0) && (iVar1 = *unaff_s0, (*(byte *)(iVar1 + 9) & 0xf) == 4)) {
        *(byte *)(iVar1 + 9) = *(byte *)(iVar1 + 9) & 0xf0 | 1;
        process_attr_report((zcl_reporting_info_t *)*unaff_s0);
      }
_L0:
      iVar1 = unaff_s0[1];
    }
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/zcl/zcl_reporting.c",0x2a5,
                "zcl_reporting_packet_confirm_handler","info && ctx == ((void *)0)");
  goto _L0;
}

