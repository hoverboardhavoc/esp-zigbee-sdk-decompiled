/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> apsme_request_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t apsme_request_key_request(apsme_request_key_req_t *req)

{
  ezb_err_t eVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  zmsg_t *msg;
  undefined3 extraout_var_00;
  undefined1 nwk_secured;
  
  if (req == (apsme_request_key_req_t *)0x0) {
    return 2;
  }
  _Var2 = ezb_eui64_is_invalid(&req->dst_address);
  eVar1 = 2;
  if (CONCAT31(extraout_var,_Var2) != 0) {
    return 2;
  }
  msg = (zmsg_t *)zmsg_alloc(0x3c);
  if (msg == (zmsg_t *)0x0) {
    return 1;
  }
  nwk_secured = 1;
  aps_frame_append_cmd_hdr(0,0);
  zmsg_append_u8(msg,'\b');
  zmsg_append_u8(msg,req->key_type);
  if (req->key_type == '\x02') {
    _Var2 = ezb_eui64_is_invalid(&req->partner_address);
    if (CONCAT31(extraout_var_00,_Var2) != 0) goto _L0;
    nwk_secured = 0xe8;
    zmsg_append_bytes(msg,8);
  }
  else if (req->key_type != '\x04') goto _L0;
  eVar1 = aps_send_cmd(msg,&req->dst_address,(_Bool)nwk_secured);
  if (eVar1 == 0) {
    return 0;
  }
_L0:
  zmsg_free(msg);
  return eVar1;
}

