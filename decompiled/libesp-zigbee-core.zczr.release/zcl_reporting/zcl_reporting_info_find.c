/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_info_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_reporting_info_t *
zcl_reporting_info_find
          (uint8_t ep_id,uint16_t cluster_id,uint8_t role,uint16_t attr_id,uint16_t manuf_code)

{
  undefined3 in_register_00002029;
  int iVar1;
  zcl_reporting_info_t *pzVar2;
  undefined2 in_register_0000202e;
  undefined2 in_register_00002036;
  undefined2 in_register_0000203a;
  int *piVar3;
  
  iVar1 = core_globals_get();
  piVar3 = *(int **)(iVar1 + 0xd34);
  while( true ) {
    if (piVar3 + -1 == (undefined4 *)0xfffffffc) {
      return (zcl_reporting_info_t *)0x0;
    }
    pzVar2 = (zcl_reporting_info_t *)piVar3[-1];
    if (((((uint)pzVar2->ep_id == CONCAT31(in_register_00002029,ep_id)) &&
         ((uint)pzVar2->cluster_id == CONCAT22(in_register_0000202e,cluster_id))) &&
        ((role & pzVar2->cluster_role) != 0)) &&
       (((uint)pzVar2->attr_id == CONCAT22(in_register_00002036,attr_id) &&
        ((uint)pzVar2->manuf_code == CONCAT22(in_register_0000203a,manuf_code))))) break;
    piVar3 = (int *)*piVar3;
  }
  return pzVar2;
}

