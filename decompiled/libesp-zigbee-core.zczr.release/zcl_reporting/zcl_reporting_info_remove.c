/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_info_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_reporting_info_remove(zcl_reporting_info_t *info)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  ezb_err_t eVar4;
  
  zcl_reporting_stop();
  iVar3 = core_globals_get();
  piVar1 = *(int **)(iVar3 + 0xd34);
  if (piVar1 != (int *)0x0) {
    for (; piVar2 = piVar1 + -1, piVar2 != (int *)0xfffffffc; piVar1 = (int *)*piVar1) {
      iVar3 = *piVar2;
      if ((((*(uint8_t *)(iVar3 + 1) == info->ep_id) &&
           (*(uint16_t *)(iVar3 + 4) == info->cluster_id)) &&
          ((*(byte *)(iVar3 + 8) & info->cluster_role) != 0)) &&
         ((*(uint16_t *)(iVar3 + 6) == info->attr_id &&
          (*(uint16_t *)(iVar3 + 0x30) == info->manuf_code)))) {
        iVar3 = core_globals_get();
        list_remove_node(iVar3 + 0xd34,piVar1);
        mm_free(piVar2);
        zcl_reporting_remove_stored_reporting_info(info);
        break;
      }
    }
  }
  eVar4 = zcl_reporting_start();
  return -(uint)(eVar4 != 0);
}

