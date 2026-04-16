/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_device_simple_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_device_simple_desc_init(af_ep_desc_t *ep_desc)

{
  af_ep_config_t *paVar1;
  af_simple_desc_t *paVar2;
  uint16_t *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  zcl_cluster_desc_t *in_a5;
  zcl_cluster_desc_t *pzVar7;
  
  if (ep_desc == (af_ep_desc_t *)0x0) {
    iVar5 = 2;
  }
  else {
    paVar1 = ep_desc->ep_config;
    if (paVar1 == (af_ep_config_t *)0x0) {
      __assert_func("//build/esp-zigbee/src/core/af/af_desc.c",0x29a,"af_device_simple_desc_init",
                    "ep_desc->ep_config");
      goto _L0;
    }
    paVar2 = (af_simple_desc_t *)calloc(1,0x10);
    ep_desc->simple_desc = paVar2;
    if (paVar2 == (af_simple_desc_t *)0x0) {
      iVar5 = 1;
    }
    else {
      paVar2->ep_id = paVar1->ep_id;
      ep_desc->simple_desc->app_profile_id = paVar1->app_profile_id;
      ep_desc->simple_desc->app_device_id = paVar1->app_device_id;
      ep_desc->simple_desc->field_0x6 =
           ep_desc->simple_desc->field_0x6 & 0xf0 | (byte)*(undefined2 *)&paVar1->field_0x6 & 0xf;
      ep_desc->simple_desc->field_0x6 = ep_desc->simple_desc->field_0x6 & 0xf;
      ep_desc->simple_desc->app_input_cluster_count = '\0';
      ep_desc->simple_desc->app_output_cluster_count = '\0';
      for (in_a5 = ep_desc->cluster_list; in_a5 != (zcl_cluster_desc_t *)0x0; in_a5 = in_a5->next) {
        if (in_a5->role_mask == '\x01') {
_L0:
          ep_desc->simple_desc->app_input_cluster_count =
               ep_desc->simple_desc->app_input_cluster_count + '\x01';
        }
        else {
          if (in_a5->role_mask != '\x02') {
            __assert_func("//build/esp-zigbee/src/core/af/af_desc.c",0x2ad,
                          "af_device_simple_desc_init",&_LC2);
            break;
          }
          ep_desc->simple_desc->app_output_cluster_count =
               ep_desc->simple_desc->app_output_cluster_count + '\x01';
        }
      }
      paVar2 = ep_desc->simple_desc;
      iVar5 = (uint)paVar2->app_input_cluster_count + (uint)paVar2->app_output_cluster_count;
      if (iVar5 != 0) {
        puVar3 = (uint16_t *)calloc(1,iVar5 * 2);
        paVar2->app_cluster_list = puVar3;
        if (ep_desc->simple_desc->app_cluster_list == (uint16_t *)0x0) {
          iVar5 = 1;
          goto _L0;
        }
        uVar6 = (uint)ep_desc->simple_desc->app_input_cluster_count;
        uVar4 = 0;
        for (pzVar7 = ep_desc->cluster_list; pzVar7 != (zcl_cluster_desc_t *)0x0;
            pzVar7 = pzVar7->next) {
          if (pzVar7->role_mask == '\x01') {
            ep_desc->simple_desc->app_cluster_list[uVar4] = pzVar7->cluster_id;
            uVar4 = uVar4 + 1 & 0xffff;
          }
          else {
            if (pzVar7->role_mask != '\x02') {
              __assert_func("//build/esp-zigbee/src/core/af/af_desc.c",700,
                            "af_device_simple_desc_init",&_LC2);
              break;
            }
            ep_desc->simple_desc->app_cluster_list[uVar6] = pzVar7->cluster_id;
            uVar6 = uVar6 + 1 & 0xffff;
          }
        }
      }
      af_add_simple_desc(ep_desc->simple_desc);
      iVar5 = 0;
    }
  }
_L0:
  if (ep_desc->ep_config != (af_ep_config_t *)0x0) {
    mm_free();
    ep_desc->ep_config = (af_ep_config_t *)0x0;
  }
  if (((iVar5 != 0) && (ep_desc != (af_ep_desc_t *)0x0)) &&
     (ep_desc->simple_desc != (af_simple_desc_t *)0x0)) {
    if (ep_desc->simple_desc->app_cluster_list != (uint16_t *)0x0) {
      mm_free();
      ep_desc->simple_desc->app_cluster_list = (uint16_t *)0x0;
    }
    mm_free(ep_desc->simple_desc);
    ep_desc->simple_desc = (af_simple_desc_t *)0x0;
  }
  return iVar5;
}

