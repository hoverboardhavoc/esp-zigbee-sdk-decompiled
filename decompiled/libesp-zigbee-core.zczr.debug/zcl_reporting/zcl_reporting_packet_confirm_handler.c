/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
    iVar1 = *(int *)(iVar1 + 0xd34);
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
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_reporting.c",0x2a5,
                "zcl_reporting_packet_confirm_handler","info && ctx == ((void *)0)");
  goto _L0;
}

