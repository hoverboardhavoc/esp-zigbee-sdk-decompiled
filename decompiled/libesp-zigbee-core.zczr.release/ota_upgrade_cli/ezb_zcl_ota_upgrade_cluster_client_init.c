/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ezb_zcl_ota_upgrade_cluster_client_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: template */
/* WARNING: Unknown calling convention */

void ezb_zcl_ota_upgrade_cluster_client_init(uint8_t ep_id)

{
  undefined4 *unaff_s0;
  zcl_attr_desc_t *pzVar1;
  int iVar2;
  uint16_t attr_id;
  undefined1 auStack_24 [4];
  zcl_cluster_template_t template;
  
  memcpy(auStack_24,&_LANCHOR0,0x14);
  pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,attr_id);
  if (pzVar1 != (zcl_attr_desc_t *)0x0) {
    unaff_s0 = (undefined4 *)calloc(1,0x48);
    pzVar1->data_p = unaff_s0;
    if (unaff_s0 != (undefined4 *)0x0) {
      *(undefined2 *)((int)unaff_s0 + 0x32) = 0;
      *(undefined1 *)(unaff_s0 + 0xc) = 0x30;
      unaff_s0[10] = 0;
      unaff_s0[0xb] = 0;
      milli_timer_init(unaff_s0 + 0xe,ota_upgrade_downloading_rsp_timeout,unaff_s0);
      pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,0);
      if (pzVar1 != (zcl_attr_desc_t *)0x0) goto _L0;
    }
  }
  do {
    do {
      do {
        do {
          do {
            pzVar1 = (zcl_attr_desc_t *)__assert_func(0,0,0,0);
_L0:
            *unaff_s0 = pzVar1->data_p;
            pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,1);
          } while (pzVar1 == (zcl_attr_desc_t *)0x0);
          unaff_s0[1] = pzVar1->data_p;
          pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,2);
          if (pzVar1 != (zcl_attr_desc_t *)0x0) {
            pzVar1 = (zcl_attr_desc_t *)pzVar1->data_p;
          }
          unaff_s0[2] = pzVar1;
          pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,3);
          if (pzVar1 != (zcl_attr_desc_t *)0x0) {
            pzVar1 = (zcl_attr_desc_t *)pzVar1->data_p;
          }
          unaff_s0[3] = pzVar1;
          pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,4);
          if (pzVar1 != (zcl_attr_desc_t *)0x0) {
            pzVar1 = (zcl_attr_desc_t *)pzVar1->data_p;
          }
          unaff_s0[4] = pzVar1;
          pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,5);
          if (pzVar1 != (zcl_attr_desc_t *)0x0) {
            pzVar1 = (zcl_attr_desc_t *)pzVar1->data_p;
          }
          unaff_s0[5] = pzVar1;
          pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,6);
        } while (pzVar1 == (zcl_attr_desc_t *)0x0);
        unaff_s0[6] = pzVar1->data_p;
        pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,7);
      } while (pzVar1 == (zcl_attr_desc_t *)0x0);
      unaff_s0[7] = pzVar1->data_p;
      pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,8);
    } while (pzVar1 == (zcl_attr_desc_t *)0x0);
    unaff_s0[8] = pzVar1->data_p;
    pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,9);
    if (pzVar1 != (zcl_attr_desc_t *)0x0) {
      pzVar1 = (zcl_attr_desc_t *)pzVar1->data_p;
    }
    unaff_s0[9] = pzVar1;
    iVar2 = zcl_cluster_template_add(auStack_24);
  } while (iVar2 != 0);
  return;
}

