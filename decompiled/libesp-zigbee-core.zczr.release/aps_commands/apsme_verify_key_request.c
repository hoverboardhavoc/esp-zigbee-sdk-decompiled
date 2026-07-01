/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> apsme_verify_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t apsme_verify_key_request(apsme_verify_key_req_t *req)

{
  ezb_err_t eVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  int iVar3;
  zmsg_t *msg;
  undefined4 *puVar4;
  undefined4 local_30;
  uint8_t hash [16];
  
  eVar1 = 2;
  if (req != (apsme_verify_key_req_t *)0x0) {
    _Var2 = ezb_eui64_is_invalid(&req->dst_address);
    eVar1 = 2;
    if (CONCAT31(extraout_var,_Var2) == 0) {
      iVar3 = aps_secur_is_tc();
      if ((iVar3 == 0) &&
         ((iVar3 = aps_secur_is_centralized(), iVar3 != 0 || (req->key_type == '\x04')))) {
        iVar3 = aps_secur_is_addr_tc(req);
        if ((iVar3 == 0) || (eVar1 = 0x3a6, req->key_type != '\x03')) {
          iVar3 = aps_secur_get_key_pair_by_addr(req);
          eVar1 = 0x3ad;
          if (iVar3 != 0) {
            msg = (zmsg_t *)zmsg_alloc(0x2f);
            eVar1 = 1;
            if (msg != (zmsg_t *)0x0) {
              aps_frame_append_cmd_hdr(0,1,0,0);
              zmsg_append_u8(msg,'\x0f');
              eVar1 = 0x3aa;
              zmsg_append_u8(msg,req->key_type);
              puVar4 = (undefined4 *)nwk_get_extended_address();
              local_30 = *puVar4;
              hash._0_4_ = puVar4[1];
              zmsg_append_bytes(msg,8,&local_30);
              if (req->key_type == '\x04') {
                aps_secur_key_pair_get_hash(iVar3,&local_30);
                zmsg_append_bytes(msg,0x10,&local_30);
                eVar1 = aps_send_cmd(msg,&req->dst_address);
                if (eVar1 == 0) {
                  return 0;
                }
              }
              zmsg_free(msg);
            }
          }
        }
      }
      else {
        eVar1 = 0x3a3;
      }
    }
  }
  return eVar1;
}

