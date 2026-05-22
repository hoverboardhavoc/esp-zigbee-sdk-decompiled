/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_nwk_addr_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_nwk_addr_rsp_wrapper(ezb_zdo_nwk_addr_req_result_t *result,void *user_ctx)

{
  uint8_t *puVar1;
  void *pvVar2;
  ezb_zdp_address_rsp_field_t *peVar3;
  code *pcVar4;
  undefined4 local_30;
  esp_zb_zdo_nwk_addr_rsp_t nwk_addr_rsp;
  
                    /* WARNING: Load size is inaccurate */
  pcVar4 = *user_ctx;
  if (pcVar4 == (code *)0x0) goto _L0;
  if (result->error != 0) {
    (*pcVar4)(0x85,0,*(undefined4 *)((int)user_ctx + 4));
    goto _L0;
  }
  if (result->rsp == (ezb_zdp_address_rsp_field_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                  ,0xea,"esp_zb_zdo_nwk_addr_rsp_wrapper","result->rsp");
_L0:
    puVar1 = (uint8_t *)calloc(1,8);
    nwk_addr_rsp._8_4_ = puVar1;
    if (puVar1 != (uint8_t *)0x0) {
      peVar3 = result->rsp;
      *puVar1 = peVar3->start_index;
      puVar1[1] = peVar3->num_assoc_dev;
      puVar1[2] = result->rsp->num_assoc_dev;
      pvVar2 = calloc((uint)result->rsp->num_assoc_dev,2);
      *(void **)(puVar1 + 4) = pvVar2;
      if (*(void **)(nwk_addr_rsp._8_4_ + 4) != (void *)0x0) {
        memcpy(*(void **)(nwk_addr_rsp._8_4_ + 4),result->rsp->nwk_addr_assoc_dev_list,
               (uint)result->rsp->num_assoc_dev << 1);
      }
    }
  }
  else {
    nwk_addr_rsp.nwk_addr = 0;
    nwk_addr_rsp._10_2_ = 0;
    peVar3 = result->rsp;
    local_30 = *(undefined4 *)&(peVar3->ieee_addr_remote_dev).field_0;
    nwk_addr_rsp.ieee_addr._0_4_ = *(undefined4 *)((int)&(peVar3->ieee_addr_remote_dev).field_0 + 4)
    ;
    nwk_addr_rsp.ieee_addr[6] = '\0';
    nwk_addr_rsp.ieee_addr[7] = '\0';
    nwk_addr_rsp.ieee_addr._4_2_ = peVar3->nwk_addr_remote_dev;
    if (peVar3->num_assoc_dev != '\0') goto _L0;
  }
  (*pcVar4)(result->rsp->status,&local_30,*(undefined4 *)((int)user_ctx + 4));
  if (nwk_addr_rsp._8_4_ != 0) {
    if (*(void **)(nwk_addr_rsp._8_4_ + 4) != (void *)0x0) {
      free(*(void **)(nwk_addr_rsp._8_4_ + 4));
    }
    free((void *)nwk_addr_rsp._8_4_);
  }
_L0:
  free(user_ctx);
  return;
}

