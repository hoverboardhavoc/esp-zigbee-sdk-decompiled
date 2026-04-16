/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> apsme_transport_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t apsme_transport_key_request(apsme_transport_key_req_t *req)

{
  ezb_extaddr_t *eui64;
  int iVar1;
  undefined4 uVar2;
  _Bool _Var3;
  undefined3 extraout_var;
  zmsg_t *msg;
  int *piVar4;
  char *pcVar5;
  undefined3 extraout_var_00;
  undefined1 nwk_secured;
  undefined4 uVar6;
  undefined1 uStack_49;
  undefined1 uStack_48;
  char cStack_47;
  aps_cmd_hdr_t aps_hdr;
  aps_cmd_transport_key_t cmd_pl;
  
  if (req == (apsme_transport_key_req_t *)0x0) {
    return 2;
  }
  iVar1 = 2;
  if (*(int *)&(req->dst_address).field_0 == 0 &&
      *(int *)((int)&(req->dst_address).field_0 + 4) == 0) {
    return 2;
  }
  _Var3 = ezb_eui64_is_invalid(&req->tunnel_address);
  msg = (zmsg_t *)zmsg_alloc(0x3c);
  if (msg == (zmsg_t *)0x0) {
    return 1;
  }
  memset(&aps_hdr.aps_cntr,0,0x21);
  aps_hdr.fcf = req->key_type;
  if (aps_hdr.fcf == '\x03') {
    memcpy(&aps_hdr.aps_cntr,&req->field_2,0x10);
    uVar6 = 0x18;
    uVar2 = 0x1a;
  }
  else if (aps_hdr.fcf == '\x04') {
    memcpy(&aps_hdr.aps_cntr,&req->field_2,0x10);
    nwk_get_extended_address();
    uVar6 = 0x18;
    uVar2 = 0x21;
  }
  else {
    if (aps_hdr.fcf != '\x01') goto _L0;
    memcpy(&aps_hdr.aps_cntr,&req->field_2,0x10);
    aps_secur_get_tc_address();
    uVar6 = 0x10;
    uVar2 = 0x22;
  }
  aps_frame_append_cmd_hdr(msg,0,CONCAT31(extraout_var,_Var3),1,uVar6);
  zmsg_append_u8(msg,'\x05');
  nwk_secured = SUB41(&aps_hdr,0);
  zmsg_append_bytes(msg,uVar2);
  if (CONCAT31(extraout_var,_Var3) == 0) {
    iVar1 = aps_process_transmit_security(req,msg);
    if (iVar1 != 0) goto _L0;
    piVar4 = (int *)nwk_get_extended_address();
    if ((*piVar4 != *(int *)&(req->tunnel_address).field_0) ||
       (piVar4[1] != *(int *)((int)&(req->tunnel_address).field_0 + 4))) {
      uStack_48 = 1;
      pcVar5 = (char *)core_globals_get();
      cStack_47 = *pcVar5;
      *pcVar5 = cStack_47 + '\x01';
      zmsg_prepend_bytes(msg,8,req);
      uStack_49 = 0xe;
      zmsg_prepend_bytes(msg,1,&uStack_49);
      nwk_secured = SUB41(&uStack_48,0);
      zmsg_prepend_bytes(msg,2);
      req = (apsme_transport_key_req_t *)&req->tunnel_address;
      goto _L0;
    }
    iVar1 = aps_relay_cmd(msg,&req->dst_address);
  }
  else {
    if (req->key_type == '\x01') {
      eui64 = &(req->field_2).nwk.parent_address;
      _Var3 = ezb_eui64_is_invalid(eui64);
      if (CONCAT31(extraout_var_00,_Var3) == 0) {
        req = (apsme_transport_key_req_t *)eui64;
      }
    }
_L0:
    iVar1 = aps_send_cmd(msg,&req->dst_address,(_Bool)nwk_secured);
  }
  if (iVar1 == 0) {
    return 0;
  }
_L0:
  zmsg_free(msg);
  return iVar1;
}

