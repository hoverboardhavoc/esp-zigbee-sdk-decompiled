/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_info_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_reporting_info_add(zcl_reporting_info_t *info)

{
  int iVar1;
  int *piVar2;
  ezb_err_t eVar3;
  
  if (info == (zcl_reporting_info_t *)0x0) {
    eVar3 = 2;
  }
  else {
    iVar1 = af_get_ep_desc(info->ep_id);
    if (iVar1 == 0) {
      eVar3 = 5;
    }
    else {
      piVar2 = (int *)calloc(1,8);
      if (piVar2 == (int *)0x0) {
        eVar3 = 1;
      }
      else {
        info->next = *(zcl_reporting_info_s **)(iVar1 + 8);
        *(zcl_reporting_info_t **)(iVar1 + 8) = info;
        *piVar2 = (int)info;
        if (info->direction == '\0') {
          info->field_0x9 =
               (byte)((*(uint *)&info->cluster_role >> 0xc & 0xf | 1) << 4) | info->field_0x9 & 0xf;
          *(byte *)(*piVar2 + 9) = *(byte *)(*piVar2 + 9) & 0xf0 | 1;
        }
        piVar2[1] = (int)(piVar2 + 1);
        iVar1 = core_globals_get();
        piVar2[1] = *(int *)(iVar1 + 0xd34);
        *(int **)(iVar1 + 0xd34) = piVar2 + 1;
        eVar3 = zcl_reporting_store_reporting_info((zcl_reporting_info_t *)*piVar2);
      }
    }
  }
  return eVar3;
}

