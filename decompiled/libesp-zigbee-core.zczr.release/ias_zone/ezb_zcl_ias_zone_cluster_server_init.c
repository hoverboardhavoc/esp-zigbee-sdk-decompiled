/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> ezb_zcl_ias_zone_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_ias_zone_cluster_server_init(uint8_t ep_id)

{
  undefined3 in_register_00002029;
  void *pvVar1;
  int iVar2;
  zcl_attr_desc_t *pzVar3;
  ias_zone_srv_zone_ctx_t *piVar4;
  undefined2 uStack_2e;
  int iStack_2c;
  nwk_addr_ref_t cie_addr_ref;
  ezb_extaddr_t cie_address;
  zcl_cluster_template_t template;
  
  memcpy((void *)((int)&cie_address.field_0 + 4),&_LANCHOR0,0x14);
  pvVar1 = calloc(1,0x14);
  if (pvVar1 != (void *)0x0) goto _L0;
  do {
    pvVar1 = (void *)__assert_func(0,0,0,0);
_L0:
    iVar2 = ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),0x500,1,0xeff0,0x131b);
    *(void **)(iVar2 + 8) = pvVar1;
    iVar2 = zcl_cluster_template_add((undefined1 *)((int)&cie_address.field_0 + 4));
  } while (iVar2 != 0);
  pzVar3 = ias_zone_srv_get_attr_desc(ep_id,0x10);
                    /* WARNING: Load size is inaccurate */
  iStack_2c = *pzVar3->data_p;
  cie_address.field_0.u64._0_4_ = *(int *)((int)pzVar3->data_p + 4);
  if ((cie_address.field_0.u64._0_4_ - (uint)(iStack_2c == 0) == -1) &&
     (0xfffffffd < iStack_2c - 1U)) {
    pzVar3 = ias_zone_srv_get_attr_desc(ep_id,0);
                    /* WARNING: Load size is inaccurate */
    if (*pzVar3->data_p == '\x01') {
      piVar4 = ias_zone_srv_get_zone_ctx(ep_id);
      uStack_2e = 0xffff;
      piVar4->cie_ieee_addr_is_set = true;
      nwk_address_by_extended(&stack0xffffffd4,1,&uStack_2e);
    }
    else {
      log_write("ZCL_IAS_ZONE","CIE address restored, but zone state is not enrolled");
    }
  }
  return;
}

