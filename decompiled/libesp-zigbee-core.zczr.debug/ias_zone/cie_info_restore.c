/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> cie_info_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void cie_info_restore(uint8_t ep_id)

{
  zcl_attr_desc_t *pzVar1;
  ias_zone_srv_zone_ctx_t *piVar2;
  int iVar3;
  int iVar4;
  ezb_extaddr_t cie_address;
  
  pzVar1 = ias_zone_srv_get_attr_desc(ep_id,0x10);
                    /* WARNING: Load size is inaccurate */
  iVar4 = *pzVar1->data_p;
  iVar3 = *(int *)((int)pzVar1->data_p + 4);
  if ((iVar4 != 0 || iVar3 != 0) && ((iVar4 != -1 || (iVar3 != -1)))) {
    pzVar1 = ias_zone_srv_get_attr_desc(ep_id,0);
                    /* WARNING: Load size is inaccurate */
    if (*pzVar1->data_p == '\x01') {
      piVar2 = ias_zone_srv_get_zone_ctx(ep_id);
      piVar2->cie_ieee_addr_is_set = true;
    }
    else {
      log_write(1,"ZCL_IAS_ZONE","CIE address restored, but zone state is not enrolled");
    }
  }
  return;
}

