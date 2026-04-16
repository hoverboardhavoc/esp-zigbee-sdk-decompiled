/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_find_next_ready_report
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_reporting_info_t * zcl_reporting_find_next_ready_report(zcl_reporting_info_t *curr_info)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  uVar1 = milli_timer_get_now();
  iVar2 = core_globals_get();
  puVar3 = *(undefined4 **)(iVar2 + 0xd98);
  while( true ) {
    piVar4 = puVar3 + -1;
    if (piVar4 == (int *)0xfffffffc) {
      return (zcl_reporting_info_t *)0x0;
    }
    if ((((piVar4 != (int *)0x0) && (iVar2 = *piVar4, (*(byte *)(iVar2 + 9) & 0xf) == 3)) &&
        (*(uint *)(iVar2 + 0xc) < uVar1)) &&
       (((*(uint8_t *)(iVar2 + 1) == curr_info->ep_id &&
         (*(uint16_t *)(iVar2 + 4) == curr_info->cluster_id)) &&
        ((*(uint16_t *)(iVar2 + 2) == curr_info->profile_id &&
         (*(uint16_t *)(iVar2 + 0x30) == curr_info->manuf_code)))))) break;
    puVar3 = (undefined4 *)*puVar3;
  }
  *(byte *)(iVar2 + 9) = *(byte *)(iVar2 + 9) & 0xf0 | 4;
  return (zcl_reporting_info_t *)*piVar4;
}

