/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_device_desc_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: ep_config */
/* WARNING: Unknown calling convention */

ezb_err_t af_device_desc_register(af_device_desc_t *dev_desc)

{
  af_ep_desc_t *paVar1;
  zcl_cluster_desc_t *cluster_desc;
  ezb_err_t eVar2;
  int iVar3;
  uint16_t *puVar4;
  zcl_cluster_desc_t *pzVar5;
  uint uVar6;
  af_device_desc_t *dev_desc_00;
  zcl_cluster_desc_t *pzVar7;
  byte bVar8;
  undefined1 auStack_28 [4];
  af_ep_config_t ep_config;
  
  if (dev_desc == (af_device_desc_t *)0x0) {
    return 3;
  }
  iVar3 = core_globals_get();
  *(af_device_desc_t **)(iVar3 + 0xca0) = dev_desc;
  iVar3 = core_globals_get();
  auStack_28[0] = 0xf2;
  auStack_28[1] = 0;
  auStack_28._2_2_ = 0xa1e0;
  dev_desc_00 = *(af_device_desc_t **)(iVar3 + 0xca0);
  ep_config.ep_id = '`';
  ep_config._1_1_ = 0;
  ep_config.app_profile_id = 0;
  iVar3 = nwk_is_device_zczr();
  if ((iVar3 != 0) && (dev_desc_00 != (af_device_desc_t *)0x0)) {
    paVar1 = af_create_endpoint_desc((af_ep_config_t *)auStack_28);
    cluster_desc = (zcl_cluster_desc_t *)zcl_create_cluster_desc(0x21,2,0);
    eVar2 = af_endpoint_add_cluster_desc(paVar1,cluster_desc);
    if (eVar2 != 0) goto _L0;
    eVar2 = af_device_add_endpoint_desc(dev_desc_00,paVar1);
    if (eVar2 != 0) {
      cluster_desc = (zcl_cluster_desc_t *)0x0;
      goto _L0;
    }
  }
  cluster_desc = (zcl_cluster_desc_t *)0x0;
  paVar1 = (af_ep_desc_t *)0x0;
_L0:
  zcl_free_cluster_desc(cluster_desc);
  af_free_endpoint_desc(paVar1);
  iVar3 = core_globals_get();
  if (*(undefined4 **)(iVar3 + 0xca0) == (undefined4 *)0x0) {
_L0:
    eVar2 = 2;
_L0:
    iVar3 = core_globals_get();
    *(undefined4 *)(iVar3 + 0xca0) = 0;
  }
  else {
    bVar8 = 0;
    for (paVar1 = (af_ep_desc_t *)**(undefined4 **)(iVar3 + 0xca0); paVar1 != (af_ep_desc_t *)0x0;
        paVar1 = paVar1->next) {
      af_ep_desc_init(paVar1);
      pzVar7 = paVar1->cluster_list;
      for (pzVar5 = pzVar7; pzVar5 != (zcl_cluster_desc_t *)0x0; pzVar5 = pzVar5->next) {
        if (pzVar5->role_mask == '\x01') {
          (paVar1->simple_desc).app_input_cluster_count =
               (paVar1->simple_desc).app_input_cluster_count + '\x01';
        }
        else {
          if (pzVar5->role_mask != '\x02') goto _L0;
          (paVar1->simple_desc).app_output_cluster_count =
               (paVar1->simple_desc).app_output_cluster_count + '\x01';
        }
      }
      cluster_desc = (zcl_cluster_desc_t *)(uint)(paVar1->simple_desc).app_input_cluster_count;
      iVar3 = (int)&cluster_desc->cluster_id + (uint)(paVar1->simple_desc).app_output_cluster_count;
      if (iVar3 != 0) {
_L0:
        puVar4 = (uint16_t *)calloc(1,iVar3 << 1);
        (paVar1->simple_desc).app_cluster_list = puVar4;
        if (puVar4 != (uint16_t *)0x0) {
          uVar6 = 0;
          do {
            if (pzVar7 == (zcl_cluster_desc_t *)0x0) goto _L0;
            if (pzVar7->role_mask == '\x01') {
              puVar4[uVar6] = pzVar7->cluster_id;
              uVar6 = uVar6 + 1 & 0xffff;
            }
            else {
              if (pzVar7->role_mask != '\x02') goto _L0;
              puVar4[(int)cluster_desc] = pzVar7->cluster_id;
              cluster_desc = (zcl_cluster_desc_t *)
                             ((uint)((int)&cluster_desc->cluster_id + 1) & 0xffff);
            }
            pzVar7 = pzVar7->next;
          } while( true );
        }
        eVar2 = 1;
        goto _L0;
      }
_L0:
      af_add_simple_desc(&paVar1->simple_desc);
      eVar2 = af_ep_reporting_info_init(paVar1);
      if (eVar2 != 0) goto _L0;
      if (s_ep_num_on_dev <= bVar8) goto _L0;
      bVar8 = bVar8 + 1;
      cluster_desc = (zcl_cluster_desc_t *)0x0;
    }
    zcl_reporting_start();
    eVar2 = 0;
  }
  return eVar2;
_L0:
  iVar3 = __assert_func(0,0,0,0);
  goto _L0;
}

