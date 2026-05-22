/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  puVar3 = *(undefined4 **)(iVar2 + 0xd34);
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

