/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  undefined2 uStack_1a;
  int iStack_18;
  nwk_addr_ref_t cie_addr_ref;
  ezb_extaddr_t cie_address;
  
  pzVar1 = ias_zone_srv_get_attr_desc(ep_id,0x10);
                    /* WARNING: Load size is inaccurate */
  iStack_18 = *pzVar1->data_p;
  cie_address.field_0.u64._0_4_ = *(int *)((int)pzVar1->data_p + 4);
  if ((iStack_18 == 0 && cie_address.field_0.u64._0_4_ == 0) ||
     ((iStack_18 == -1 && (cie_address.field_0.u64._0_4_ == -1)))) {
    pzVar1 = ias_zone_srv_get_attr_desc(ep_id,0);
                    /* WARNING: Load size is inaccurate */
    if (*pzVar1->data_p == '\x01') {
      piVar2 = ias_zone_srv_get_zone_ctx(ep_id);
      piVar2->cie_ieee_addr_is_set = true;
      uStack_1a = 0xffff;
      nwk_address_by_extended(&stack0xffffffe8,1,&uStack_1a);
    }
    else {
      log_write(1,"ZCL_IAS_ZONE","CIE address restored, but zone state is not enrolled");
    }
  }
  return;
}

