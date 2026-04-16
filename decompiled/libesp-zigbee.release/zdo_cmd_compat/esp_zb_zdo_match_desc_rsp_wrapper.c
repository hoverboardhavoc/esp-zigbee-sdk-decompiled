/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_match_desc_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_match_desc_rsp_wrapper(ezb_zdo_match_desc_req_result_t *result,void *user_ctx)

{
  ezb_zdp_status_t eVar1;
  ezb_shortaddr_t eVar2;
  uint8_t uVar3;
  ezb_zdp_match_desc_rsp_field_t *peVar4;
  
                    /* WARNING: Load size is inaccurate */
  if ((*(char *)((int)user_ctx + 9) != '\0') || (*user_ctx == (code *)0x0)) goto _L0;
  peVar4 = result->rsp;
  if (peVar4 == (ezb_zdp_match_desc_rsp_field_t *)0x0) {
    eVar1 = 0x85;
_L0:
    uVar3 = 0xff;
    eVar2 = 0xffff;
  }
  else {
    eVar1 = peVar4->status;
    if (peVar4->match_length == '\0') goto _L0;
    eVar2 = peVar4->nwk_addr_of_interest;
    uVar3 = *peVar4->match_list;
  }
  (**user_ctx)(eVar1,eVar2,uVar3,*(undefined4 *)((int)user_ctx + 4));
_L0:
  *(undefined1 *)((int)user_ctx + 9) = 1;
  if ((*(char *)((int)user_ctx + 8) != '\0') &&
     (result->rsp != (ezb_zdp_match_desc_rsp_field_t *)0x0)) {
    return;
  }
  free(user_ctx);
  return;
}

