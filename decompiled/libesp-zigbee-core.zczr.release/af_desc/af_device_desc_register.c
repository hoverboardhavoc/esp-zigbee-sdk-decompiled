/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_device_desc_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_device_desc_register(af_device_desc_t *dev_desc)

{
  ushort uVar1;
  af_device_desc_t *dev_desc_00;
  int iVar2;
  af_ep_desc_t *paVar3;
  zcl_cluster_desc_t *pzVar4;
  ezb_err_t eVar5;
  af_simple_desc_t *paVar6;
  int iVar7;
  uint16_t *puVar8;
  uint uVar9;
  af_ep_config_t *paVar10;
  byte bVar11;
  zcl_cluster_desc_t *pzVar12;
  undefined1 auStack_38 [4];
  af_ep_config_t ep_config;
  
  if (dev_desc == (af_device_desc_t *)0x0) {
    return 3;
  }
  iVar2 = core_globals_get();
  *(af_device_desc_t **)(iVar2 + 0xd04) = dev_desc;
  iVar2 = core_globals_get();
  dev_desc_00 = *(af_device_desc_t **)(iVar2 + 0xd04);
  auStack_38[0] = 0xf2;
  auStack_38[1] = 0;
  auStack_38._2_2_ = 0xa1e0;
  ep_config.ep_id = '`';
  ep_config._1_1_ = 0;
  ep_config.app_profile_id = 0;
  if (dev_desc_00 == (af_device_desc_t *)0x0) {
    paVar3 = (af_ep_desc_t *)0x0;
    iVar2 = 3;
    pzVar4 = (zcl_cluster_desc_t *)0x0;
  }
  else {
    paVar3 = af_create_endpoint_desc((af_ep_config_t *)auStack_38);
    pzVar4 = (zcl_cluster_desc_t *)zcl_create_cluster_desc(0x21,2,0);
    eVar5 = af_endpoint_add_cluster_desc(paVar3,pzVar4);
    if (eVar5 == 0) {
      eVar5 = af_device_add_endpoint_desc(dev_desc_00,paVar3);
      pzVar4 = (zcl_cluster_desc_t *)0x0;
      if (eVar5 == 0) {
        paVar3 = (af_ep_desc_t *)0x0;
        iVar2 = 0;
        goto _L0;
      }
    }
    iVar2 = 2;
  }
_L0:
  zcl_free_cluster_desc(pzVar4);
  af_free_endpoint_desc(paVar3);
  if (iVar2 == 0) {
    iVar2 = core_globals_get();
    if (*(undefined4 **)(iVar2 + 0xd04) != (undefined4 *)0x0) {
      paVar3 = (af_ep_desc_t *)**(undefined4 **)(iVar2 + 0xd04);
      bVar11 = 0;
_L0:
      if (paVar3 == (af_ep_desc_t *)0x0) {
        zcl_reporting_start();
        return 0;
      }
      af_ep_desc_init(paVar3);
      paVar10 = paVar3->ep_config;
      if (paVar10 != (af_ep_config_t *)0x0) goto _L0;
_L259:
      __assert_func(0,0,0,0);
_L0:
      paVar6 = (af_simple_desc_t *)calloc(1,0x10);
      paVar3->simple_desc = paVar6;
      if (paVar6 != (af_simple_desc_t *)0x0) goto _L0;
      goto _L0;
    }
_L0:
    iVar2 = 2;
_L0:
    iVar7 = core_globals_get();
    *(undefined4 *)(iVar7 + 0xd04) = 0;
  }
  return iVar2;
_L0:
  paVar6->ep_id = paVar10->ep_id;
  paVar6->app_profile_id = paVar10->app_profile_id;
  paVar6->app_device_id = paVar10->app_device_id;
  uVar1 = *(ushort *)&paVar10->field_0x6;
  paVar6->app_output_cluster_count = '\0';
  *(ushort *)&paVar6->field_0x6 = uVar1 & 0xf;
  pzVar12 = paVar3->cluster_list;
  for (pzVar4 = pzVar12; pzVar4 != (zcl_cluster_desc_t *)0x0; pzVar4 = pzVar4->next) {
    if (pzVar4->role_mask == '\x01') {
      paVar6->app_input_cluster_count = paVar6->app_input_cluster_count + '\x01';
    }
    else {
      if (pzVar4->role_mask != '\x02') goto _L259;
      paVar6->app_output_cluster_count = paVar6->app_output_cluster_count + '\x01';
    }
  }
  paVar10 = (af_ep_config_t *)(uint)paVar6->app_input_cluster_count;
  if (&paVar10->ep_id + paVar6->app_output_cluster_count == (uint8_t *)0x0) {
_L0:
    af_add_simple_desc(paVar6);
    iVar2 = 0;
  }
  else {
    puVar8 = (uint16_t *)calloc(1,(int)(&paVar10->ep_id + paVar6->app_output_cluster_count) * 2);
    paVar6->app_cluster_list = puVar8;
    uVar9 = 0;
    if (puVar8 != (uint16_t *)0x0) {
      do {
        if (pzVar12 == (zcl_cluster_desc_t *)0x0) goto _L0;
        if (pzVar12->role_mask == '\x01') {
          puVar8[uVar9] = pzVar12->cluster_id;
          uVar9 = uVar9 + 1 & 0xffff;
        }
        else {
          if (pzVar12->role_mask != '\x02') goto _L259;
          puVar8[(int)paVar10] = pzVar12->cluster_id;
          paVar10 = (af_ep_config_t *)((uint)&paVar10->field_0x1 & 0xffff);
        }
        pzVar12 = pzVar12->next;
      } while( true );
    }
_L0:
    iVar2 = 1;
  }
  if (paVar3->ep_config != (af_ep_config_t *)0x0) {
    mm_free();
    paVar3->ep_config = (af_ep_config_t *)0x0;
  }
  if (iVar2 != 0) {
    paVar6 = paVar3->simple_desc;
    if (paVar6 != (af_simple_desc_t *)0x0) {
      if (paVar6->app_cluster_list != (uint16_t *)0x0) {
        mm_free();
        paVar6 = paVar3->simple_desc;
        paVar6->app_cluster_list = (uint16_t *)0x0;
      }
      mm_free(paVar6);
      paVar3->simple_desc = (af_simple_desc_t *)0x0;
    }
    goto _L0;
  }
  iVar2 = af_ep_reporting_info_init(paVar3);
  if (iVar2 != 0) goto _L0;
  if (s_ep_num_on_dev <= bVar11) goto _L0;
  paVar3 = paVar3->next;
  bVar11 = bVar11 + 1;
  goto _L0;
}

