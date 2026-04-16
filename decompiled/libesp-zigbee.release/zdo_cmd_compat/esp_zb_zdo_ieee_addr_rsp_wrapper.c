/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_ieee_addr_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_ieee_addr_rsp_wrapper(ezb_zdo_ieee_addr_req_result_t *result,void *user_ctx)

{
  byte bVar1;
  uint8_t uVar2;
  ezb_zdp_address_rsp_field_t *peVar3;
  uint8_t *puVar4;
  void *__dest;
  uint __nmemb;
  code *pcVar5;
  undefined4 local_30;
  esp_zb_zdo_ieee_addr_rsp_t ieee_addr_rsp;
  
                    /* WARNING: Load size is inaccurate */
  pcVar5 = *user_ctx;
  if (pcVar5 != (code *)0x0) {
    if (result->error == 0) {
      peVar3 = result->rsp;
      if (peVar3 == (ezb_zdp_address_rsp_field_t *)0x0) {
        __assert_func(0,0,0,0);
      }
      local_30 = 0;
      ieee_addr_rsp.ieee_addr[0] = '\0';
      ieee_addr_rsp.ieee_addr[1] = '\0';
      ieee_addr_rsp.ieee_addr[2] = '\0';
      ieee_addr_rsp.ieee_addr[3] = '\0';
      ieee_addr_rsp.ieee_addr[4] = '\0';
      ieee_addr_rsp.ieee_addr[5] = '\0';
      ieee_addr_rsp.ieee_addr[6] = '\0';
      ieee_addr_rsp.ieee_addr[7] = '\0';
      ieee_addr_rsp.nwk_addr = 0;
      ieee_addr_rsp._10_2_ = 0;
      memcpy(&local_30,&peVar3->ieee_addr_remote_dev,8);
      bVar1 = peVar3->num_assoc_dev;
      __nmemb = (uint)bVar1;
      ieee_addr_rsp.ieee_addr._4_2_ = peVar3->nwk_addr_remote_dev;
      if (__nmemb != 0) {
        puVar4 = (uint8_t *)calloc(1,8);
        ieee_addr_rsp._8_4_ = puVar4;
        if (puVar4 != (uint8_t *)0x0) {
          uVar2 = peVar3->start_index;
          puVar4[1] = bVar1;
          *puVar4 = uVar2;
          puVar4[2] = bVar1;
          __dest = calloc(__nmemb,2);
          *(void **)(puVar4 + 4) = __dest;
          if (__dest != (void *)0x0) {
            memcpy(__dest,peVar3->nwk_addr_assoc_dev_list,__nmemb << 1);
          }
        }
      }
      (*pcVar5)(peVar3->status,&local_30,*(undefined4 *)((int)user_ctx + 4));
      if (ieee_addr_rsp._8_4_ != 0) {
        if (*(void **)(ieee_addr_rsp._8_4_ + 4) != (void *)0x0) {
          free(*(void **)(ieee_addr_rsp._8_4_ + 4));
        }
        free((void *)ieee_addr_rsp._8_4_);
      }
    }
    else if (result->error == 7) {
      (*pcVar5)(0x85,0,*(undefined4 *)((int)user_ctx + 4));
    }
  }
  free(user_ctx);
  return;
}

