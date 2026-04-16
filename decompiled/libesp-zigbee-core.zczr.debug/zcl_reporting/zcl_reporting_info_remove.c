/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_info_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_reporting_info_remove(zcl_reporting_info_t *info)

{
  undefined4 *puVar1;
  int *piVar2;
  ezb_err_t eVar3;
  int iVar4;
  
  eVar3 = zcl_reporting_stop();
  if (eVar3 == 0) {
    iVar4 = core_globals_get();
    puVar1 = *(undefined4 **)(iVar4 + 0xd98);
    if (puVar1 != (undefined4 *)0x0) {
      for (; piVar2 = puVar1 + -1, piVar2 != (int *)0xfffffffc; puVar1 = (undefined4 *)*puVar1) {
        if (((((piVar2 != (int *)0x0) && (iVar4 = *piVar2, *(uint8_t *)(iVar4 + 1) == info->ep_id))
             && (*(uint16_t *)(iVar4 + 4) == info->cluster_id)) &&
            (((*(byte *)(iVar4 + 8) & info->cluster_role) != 0 &&
             (*(uint16_t *)(iVar4 + 6) == info->attr_id)))) &&
           (*(uint16_t *)(iVar4 + 0x30) == info->manuf_code)) {
          iVar4 = core_globals_get();
          list_remove_node(iVar4 + 0xd98,puVar1);
          break;
        }
      }
      if ((piVar2 != (int *)0xfffffffc) && (piVar2 != (int *)0x0)) {
        mm_free(piVar2);
        zcl_reporting_remove_stored_reporting_info(info);
      }
    }
    eVar3 = zcl_reporting_start();
    if (eVar3 != 0) {
      eVar3 = -1;
    }
  }
  else {
    eVar3 = -1;
  }
  return eVar3;
}

