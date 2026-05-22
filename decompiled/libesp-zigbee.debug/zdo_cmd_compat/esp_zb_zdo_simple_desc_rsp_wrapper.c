/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_simple_desc_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_simple_desc_rsp_wrapper(ezb_zdo_simple_desc_req_result_t *result,void *user_ctx)

{
  uint uVar1;
  size_t __nmemb;
  void *pvVar2;
  ezb_zdp_simple_desc_rsp_field_t *peVar3;
  code *pcVar4;
  ushort local_30;
  uint16_t uStack_2e;
  esp_zb_af_simple_desc_1_1_t simple_desc;
  
                    /* WARNING: Load size is inaccurate */
  pcVar4 = *user_ctx;
  if (pcVar4 != (code *)0x0) {
    pvVar2 = user_ctx;
    if (result->error == 0) {
      if (result->rsp != (ezb_zdp_simple_desc_rsp_field_t *)0x0) {
        simple_desc.app_output_cluster_count = '\0';
        simple_desc._9_3_ = 0;
        peVar3 = result->rsp;
        _local_30 = CONCAT22((peVar3->desc).app_profile_id,(ushort)(peVar3->desc).ep_id);
        uVar1._0_2_ = (peVar3->desc).app_device_id;
        uVar1._2_1_ = (peVar3->desc).field_0x6;
        uVar1._3_1_ = (peVar3->desc).app_input_cluster_count;
        simple_desc._0_4_ = uVar1 & 0xff0fffff;
        simple_desc.app_device_id._0_1_ = (peVar3->desc).app_output_cluster_count;
        simple_desc._5_3_ = 0;
        __nmemb = (uint)(peVar3->desc).app_input_cluster_count +
                  (uint)(byte)simple_desc.app_device_id;
        simple_desc._8_4_ = calloc(__nmemb,2);
        if ((void *)simple_desc._8_4_ != (void *)0x0) {
          memcpy((void *)simple_desc._8_4_,(result->rsp->desc).app_cluster_list,__nmemb * 2);
        }
        (*pcVar4)(result->rsp->status,&local_30,*(undefined4 *)((int)user_ctx + 4));
        if (simple_desc._8_4_ != 0) {
          free((void *)simple_desc._8_4_);
        }
        goto _L0;
      }
      pvVar2 = (void *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                                     ,0x140,"esp_zb_zdo_simple_desc_rsp_wrapper","result->rsp");
    }
    (*pcVar4)(0x85,0,*(undefined4 *)((int)pvVar2 + 4));
  }
_L0:
  free(user_ctx);
  return;
}

