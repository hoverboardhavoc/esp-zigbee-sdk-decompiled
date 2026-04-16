/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_simple_desc_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_simple_desc_rsp_wrapper(ezb_zdo_simple_desc_req_result_t *result,void *user_ctx)

{
  ezb_zdp_simple_desc_rsp_field_t *peVar1;
  uint uVar2;
  size_t __nmemb;
  code *pcVar3;
  ushort local_30;
  uint16_t uStack_2e;
  esp_zb_af_simple_desc_1_1_t simple_desc;
  
                    /* WARNING: Load size is inaccurate */
  pcVar3 = *user_ctx;
  if (pcVar3 != (code *)0x0) {
    if (result->error == 0) {
      peVar1 = result->rsp;
      if (peVar1 == (ezb_zdp_simple_desc_rsp_field_t *)0x0) {
        __assert_func(0,0,0,0);
      }
      simple_desc.app_device_id._0_1_ = (peVar1->desc).app_output_cluster_count;
      _local_30 = CONCAT22((peVar1->desc).app_profile_id,(ushort)(peVar1->desc).ep_id);
      uVar2._0_2_ = (peVar1->desc).app_device_id;
      uVar2._2_1_ = (peVar1->desc).field_0x6;
      uVar2._3_1_ = (peVar1->desc).app_input_cluster_count;
      __nmemb = (uint)(peVar1->desc).app_input_cluster_count + (uint)(byte)simple_desc.app_device_id
      ;
      simple_desc._0_4_ = uVar2 & 0xff0fffff;
      simple_desc._5_3_ = 0;
      simple_desc._8_4_ = calloc(__nmemb,2);
      if ((void *)simple_desc._8_4_ != (void *)0x0) {
        memcpy((void *)simple_desc._8_4_,(peVar1->desc).app_cluster_list,__nmemb * 2);
      }
      (*pcVar3)(peVar1->status,&local_30,*(undefined4 *)((int)user_ctx + 4));
      if (simple_desc._8_4_ != 0) {
        free((void *)simple_desc._8_4_);
      }
    }
    else {
      (*pcVar3)(0x85,0,*(undefined4 *)((int)user_ctx + 4));
    }
  }
  free(user_ctx);
  return;
}

