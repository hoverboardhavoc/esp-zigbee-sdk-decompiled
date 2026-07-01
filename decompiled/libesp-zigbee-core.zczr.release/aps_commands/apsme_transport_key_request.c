/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> apsme_transport_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t apsme_transport_key_request(apsme_transport_key_req_t *req)

{
  uint uVar1;
  uint uVar2;
  ezb_extaddr_t *eui64;
  undefined4 uVar3;
  _Bool _Var4;
  undefined3 extraout_var;
  int iVar6;
  zmsg_t *msg;
  int *piVar7;
  char *pcVar8;
  undefined3 extraout_var_00;
  undefined4 uVar9;
  int iVar10;
  _Bool is_ack_required;
  int iVar11;
  undefined1 uStack_59;
  undefined1 uStack_58;
  char cStack_57;
  aps_cmd_hdr_t aps_hdr;
  aps_cmd_transport_key_t cmd_pl;
  int iVar5;
  
  _Var4 = ezb_eui64_is_invalid(&req->tunnel_address);
  iVar5 = CONCAT31(extraout_var,_Var4);
  uVar1 = *(uint *)&(req->dst_address).field_0;
  uVar2 = *(uint *)((int)&(req->dst_address).field_0 + 4);
  if (iVar5 == 0) {
    if (uVar1 == 0 && uVar2 == 0) {
      return 2;
    }
    iVar11 = 0;
    if ((uVar1 == 0xffffffff) && (uVar2 == 0xffffffff)) goto _L0;
_L0:
    iVar6 = 0x2f;
    iVar10 = 0xd;
  }
  else {
    if ((uVar1 != 0xffffffff) || (uVar2 != 0xffffffff)) {
      iVar11 = iVar5;
      if (uVar1 == 0 && uVar2 == 0) {
        return 2;
      }
      goto _L0;
    }
_L0:
    iVar11 = 0;
    iVar6 = 0x27;
    iVar10 = 0;
  }
  msg = (zmsg_t *)zmsg_alloc(iVar6 + iVar10);
  if (msg == (zmsg_t *)0x0) {
    return 1;
  }
  memset(&aps_hdr.aps_cntr,0,0x21);
  aps_hdr.fcf = req->key_type;
  if (aps_hdr.fcf == '\x03') {
    memcpy(&aps_hdr.aps_cntr,&req->field_2,0x10);
    uVar9 = 0x18;
    uVar3 = 0x1a;
  }
  else if (aps_hdr.fcf == '\x04') {
    memcpy(&aps_hdr.aps_cntr,&req->field_2,0x10);
    nwk_get_extended_address();
    uVar9 = 0x18;
    uVar3 = 0x21;
  }
  else {
    iVar6 = 2;
    if (aps_hdr.fcf != '\x01') goto _L0;
    memcpy(&aps_hdr.aps_cntr,&req->field_2,0x10);
    aps_secur_get_tc_address();
    uVar9 = 0x10;
    uVar3 = 0x22;
  }
  aps_frame_append_cmd_hdr
            (msg,(uVar1 & uVar2) == 0xffffffff,iVar11,(uVar1 & uVar2) != 0xffffffff,uVar9);
  zmsg_append_u8(msg,'\x05');
  zmsg_append_bytes(msg,uVar3,&aps_hdr);
  if (iVar5 == 0) {
    iVar6 = aps_process_transmit_security(req,msg);
    if (iVar6 != 0) goto _L0;
    piVar7 = (int *)nwk_get_extended_address();
    if ((*(int *)&(req->tunnel_address).field_0 != *piVar7) ||
       (*(int *)((int)&(req->tunnel_address).field_0 + 4) != piVar7[1])) {
      uStack_58 = 1;
      pcVar8 = (char *)core_globals_get();
      cStack_57 = *pcVar8;
      *pcVar8 = cStack_57 + '\x01';
      zmsg_prepend_bytes(msg,8,req);
      uStack_59 = 0xe;
      zmsg_prepend_bytes(msg,1,&uStack_59);
      zmsg_prepend_bytes(msg,2,&uStack_58);
      req = (apsme_transport_key_req_t *)&req->tunnel_address;
      goto _L0;
    }
    iVar6 = aps_relay_cmd(msg,&req->dst_address);
  }
  else {
    if (req->key_type == '\x01') {
      eui64 = &(req->field_2).nwk.parent_address;
      _Var4 = ezb_eui64_is_invalid(eui64);
      if (CONCAT31(extraout_var_00,_Var4) == 0) {
        req = (apsme_transport_key_req_t *)eui64;
      }
    }
_L0:
    iVar6 = aps_send_cmd(msg,&req->dst_address);
  }
  if (iVar6 == 0) {
    return 0;
  }
_L0:
  zmsg_free(msg);
  return iVar6;
}

