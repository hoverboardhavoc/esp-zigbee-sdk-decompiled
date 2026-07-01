/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> apsme_confirm_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t apsme_confirm_key_request(apsme_confirm_key_req_t *req)

{
  int iVar1;
  zmsg_t *msg;
  ezb_err_t eVar2;
  int iVar3;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (req == (apsme_confirm_key_req_t *)0x0) {
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
      if (req->key_type == '\x03') {
        iVar3 = aps_secur_is_addr_tc(req);
        if (iVar3 != 0) {
          msg = (zmsg_t *)0x0;
          eVar2 = 0x3a6;
          goto _L0;
        }
      }
      else if (req->key_type == '\x04') {
        iVar3 = aps_secur_is_tc();
        if (iVar3 == 0) {
          msg = (zmsg_t *)0x0;
          eVar2 = 0x3a3;
        }
        else {
          msg = (zmsg_t *)zmsg_alloc(0x3c);
          if (msg == (zmsg_t *)0x0) {
            eVar2 = 1;
          }
          else {
            aps_frame_append_cmd_hdr(0,1,0);
            uStack_18._0_1_ = 0x10;
            zmsg_append_bytes(msg,1,&uStack_18);
            uStack_18._0_1_ = req->status;
            zmsg_append_bytes(msg,1,&uStack_18);
            uStack_18 = CONCAT31(uStack_18._1_3_,req->key_type);
            zmsg_append_bytes(msg,1,&uStack_18);
            uStack_18 = *(undefined4 *)&(req->dst_address).field_0;
            uStack_14 = *(undefined4 *)((int)&(req->dst_address).field_0 + 4);
            zmsg_append_bytes(msg,8,&uStack_18);
            eVar2 = aps_send_cmd(msg,&req->dst_address);
            if (eVar2 == 0) {
              return 0;
            }
          }
        }
        goto _L0;
      }
      msg = (zmsg_t *)0x0;
      eVar2 = 0x3aa;
    }
  }
_L0:
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return eVar2;
}

