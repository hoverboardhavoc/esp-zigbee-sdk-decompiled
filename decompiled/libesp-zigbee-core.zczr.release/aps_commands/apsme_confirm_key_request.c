/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> apsme_confirm_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t apsme_confirm_key_request(apsme_confirm_key_req_t *req)

{
  ezb_err_t eVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  int iVar3;
  zmsg_t *msg;
  undefined1 nwk_secured;
  
  eVar1 = 2;
  if (req != (apsme_confirm_key_req_t *)0x0) {
    _Var2 = ezb_eui64_is_invalid(&req->dst_address);
    eVar1 = 2;
    if (CONCAT31(extraout_var,_Var2) == 0) {
      if (req->key_type == '\x03') {
        iVar3 = aps_secur_is_addr_tc(req);
        if (iVar3 != 0) {
          return 0x3a6;
        }
      }
      else if (req->key_type == '\x04') {
        iVar3 = aps_secur_is_tc();
        if (iVar3 == 0) {
          return 0x3a3;
        }
        msg = (zmsg_t *)zmsg_alloc(0x3c);
        if (msg == (zmsg_t *)0x0) {
          return 1;
        }
        aps_frame_append_cmd_hdr(0,1,1,0);
        zmsg_append_u8(msg,'\x10');
        zmsg_append_u8(msg,req->status);
        zmsg_append_u8(msg,req->key_type);
        nwk_secured = 0xe8;
        zmsg_append_bytes(msg,8);
        eVar1 = aps_send_cmd(msg,&req->dst_address,(_Bool)nwk_secured);
        if (eVar1 == 0) {
          return 0;
        }
        zmsg_free(msg);
        return eVar1;
      }
      eVar1 = 0x3aa;
    }
  }
  return eVar1;
}

