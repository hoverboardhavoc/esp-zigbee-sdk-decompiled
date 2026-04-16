/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
        info->next = *(zcl_reporting_info_s **)(iVar1 + 0x10);
        *(zcl_reporting_info_t **)(iVar1 + 0x10) = info;
        *piVar2 = (int)info;
        if (info->direction == '\0') {
          info->field_0x9 =
               (byte)((*(uint *)&info->cluster_role >> 0xc & 0xf | 1) << 4) | info->field_0x9 & 0xf;
          *(byte *)(*piVar2 + 9) = *(byte *)(*piVar2 + 9) & 0xf0 | 1;
        }
        piVar2[1] = (int)(piVar2 + 1);
        iVar1 = core_globals_get();
        piVar2[1] = *(int *)(iVar1 + 0xd98);
        *(int **)(iVar1 + 0xd98) = piVar2 + 1;
        eVar3 = zcl_reporting_store_reporting_info((zcl_reporting_info_t *)*piVar2);
      }
    }
  }
  return eVar3;
}

