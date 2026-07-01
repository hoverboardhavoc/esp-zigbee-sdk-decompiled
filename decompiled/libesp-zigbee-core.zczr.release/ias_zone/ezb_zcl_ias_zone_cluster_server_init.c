/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
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
  undefined1 auStack_24 [4];
  zcl_cluster_template_t template;
  
  memcpy(auStack_24,&_LANCHOR0,0x14);
  pvVar1 = calloc(1,0x14);
  if (pvVar1 != (void *)0x0) goto _L0;
  do {
    pvVar1 = (void *)__assert_func(0,0,0,0);
_L0:
    iVar2 = ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),0x500,1,0xeff0,0x131b);
    *(void **)(iVar2 + 8) = pvVar1;
    iVar2 = zcl_cluster_template_add(auStack_24);
  } while (iVar2 != 0);
  pzVar3 = ias_zone_srv_get_attr_desc(ep_id,0x10);
                    /* WARNING: Load size is inaccurate */
  iVar2 = *pzVar3->data_p;
  if ((*(int *)((int)pzVar3->data_p + 4) + 1U != (uint)(iVar2 == 0)) || (iVar2 - 1U < 0xfffffffe)) {
    pzVar3 = ias_zone_srv_get_attr_desc(ep_id,0);
                    /* WARNING: Load size is inaccurate */
    if (*pzVar3->data_p == '\x01') {
      piVar4 = ias_zone_srv_get_zone_ctx(ep_id);
      piVar4->cie_ieee_addr_is_set = true;
    }
    else {
      log_write("ZCL_IAS_ZONE","CIE address restored, but zone state is not enrolled");
    }
  }
  return;
}

