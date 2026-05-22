/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_find_next_ready_report
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
  zcl_reporting_info_t *pzVar3;
  int *piVar4;
  
  uVar1 = milli_timer_get_now();
  iVar2 = core_globals_get();
  piVar4 = *(int **)(iVar2 + 0xd34);
  while( true ) {
    if (piVar4 + -1 == (int *)0xfffffffc) {
      return (zcl_reporting_info_t *)0x0;
    }
    pzVar3 = (zcl_reporting_info_t *)piVar4[-1];
    if (((((pzVar3->field_0x9 & 0xf) == 3) && ((pzVar3->next_fire).val < uVar1)) &&
        (pzVar3->ep_id == curr_info->ep_id)) &&
       (((pzVar3->cluster_id == curr_info->cluster_id &&
         (pzVar3->profile_id == curr_info->profile_id)) &&
        (pzVar3->manuf_code == curr_info->manuf_code)))) break;
    piVar4 = (int *)*piVar4;
  }
  pzVar3->field_0x9 = pzVar3->field_0x9 & 0xf0 | 4;
  return pzVar3;
}

