/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> apsme_verify_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t apsme_verify_key_request(apsme_verify_key_req_t *req)

{
  int iVar1;
  zmsg_t *msg;
  ezb_err_t eVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_30;
  uint8_t hash [16];
  
  if (req == (apsme_verify_key_req_t *)0x0) {
    eVar2 = 2;
    msg = (zmsg_t *)0x0;
  }
  else {
    iVar3 = *(int *)&(req->dst_address).field_0;
    iVar1 = *(int *)((int)&(req->dst_address).field_0 + 4);
    if (iVar3 == 0 && iVar1 == 0) {
      msg = (zmsg_t *)0x0;
      eVar2 = 2;
    }
    else if ((iVar3 == -1) && (iVar1 == -1)) {
      msg = (zmsg_t *)0x0;
      eVar2 = 2;
    }
    else {
      iVar3 = aps_secur_is_tc();
      if (iVar3 == 0) {
        iVar3 = aps_secur_is_centralized();
        if ((iVar3 == 0) && (req->key_type != '\x04')) {
          msg = (zmsg_t *)0x0;
          eVar2 = 0x3a3;
        }
        else {
          iVar3 = aps_secur_is_addr_tc(req);
          if ((iVar3 == 0) || (req->key_type != '\x03')) {
            iVar3 = aps_secur_get_key_pair_by_addr(req);
            if (iVar3 == 0) {
              eVar2 = 0x3ad;
              msg = (zmsg_t *)0x0;
            }
            else {
              msg = (zmsg_t *)zmsg_alloc(0x2f);
              if (msg == (zmsg_t *)0x0) {
                eVar2 = 1;
              }
              else {
                aps_frame_append_cmd_hdr(0,1,0,0);
                local_30._0_1_ = 0xf;
                zmsg_append_bytes(msg,1,&local_30);
                local_30 = CONCAT31(local_30._1_3_,req->key_type);
                zmsg_append_bytes(msg,1,&local_30);
                puVar4 = (undefined4 *)nwk_get_extended_address();
                local_30 = *puVar4;
                hash._0_4_ = puVar4[1];
                zmsg_append_bytes(msg,8,&local_30);
                if (req->key_type == '\x04') {
                  aps_secur_key_pair_get_hash(iVar3,&local_30);
                  zmsg_append_bytes(msg,0x10,&local_30);
                  eVar2 = aps_send_cmd(msg,&req->dst_address,true);
                  if (eVar2 == 0) {
                    return 0;
                  }
                }
                else {
                  eVar2 = 0x3aa;
                }
              }
            }
          }
          else {
            msg = (zmsg_t *)0x0;
            eVar2 = 0x3a6;
          }
        }
      }
      else {
        msg = (zmsg_t *)0x0;
        eVar2 = 0x3a3;
      }
    }
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return eVar2;
}

