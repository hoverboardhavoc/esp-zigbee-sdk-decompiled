/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> apsme_transport_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t apsme_transport_key_request(apsme_transport_key_req_t *req)

{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  char *pcVar7;
  zmsg_t *msg;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 uStack_48;
  char cStack_47;
  aps_cmd_hdr_t aps_hdr;
  aps_cmd_transport_key_t cmd_pl;
  
  iVar4 = *(int *)&(req->tunnel_address).field_0;
  iVar3 = *(int *)((int)&(req->tunnel_address).field_0 + 4);
  if (iVar4 == 0 && iVar3 == 0) {
    iVar4 = 1;
  }
  else {
    if ((iVar4 == -1) && (iVar3 == -1)) {
      iVar4 = 1;
    }
    else {
      iVar4 = 0;
    }
    if (req == (apsme_transport_key_req_t *)0x0) {
      iVar4 = 2;
      msg = (zmsg_t *)0x0;
      goto _L0;
    }
  }
  if (*(int *)&(req->dst_address).field_0 == 0 &&
      *(int *)((int)&(req->dst_address).field_0 + 4) == 0) {
    msg = (zmsg_t *)0x0;
    iVar4 = 2;
    goto _L0;
  }
  msg = (zmsg_t *)zmsg_alloc(0x3c);
  if (msg == (zmsg_t *)0x0) {
    iVar4 = 1;
    goto _L0;
  }
  cmd_pl._0_4_ = 0;
  cmd_pl.field_1._3_4_ = 0;
  cmd_pl.field_1._7_4_ = 0;
  cmd_pl.field_1._11_4_ = 0;
  cmd_pl.field_1._15_4_ = 0;
  cmd_pl.field_1._19_4_ = 0;
  cmd_pl.field_1._23_4_ = 0;
  cmd_pl.field_1._27_2_ = 0;
  bVar2 = req->key_type;
  _aps_hdr = (uint)bVar2;
  if (bVar2 == 3) {
    memcpy(&aps_hdr.aps_cntr,&req->field_2,0x10);
    puVar5 = (undefined4 *)((int)&req->field_2 + 0x10);
    uVar8 = *puVar5;
    puVar1 = (undefined4 *)((int)&req->field_2 + 0x14);
    uVar9 = *puVar1;
    cmd_pl.field_1.nwk.key[0xc] = (char)*(undefined2 *)puVar5;
    cmd_pl.field_1.nwk.key[0xd] = (char)((uint)uVar8 >> 8);
    cmd_pl.field_1.nwk.key[0xe] = (char)((uint)uVar8 >> 0x10);
    cmd_pl.field_1.nwk.key_seq = (char)*(undefined2 *)puVar1;
    cmd_pl.field_1.nwk.key[0xf] = (char)((uint)uVar8 >> 0x18);
    cmd_pl.field_1._17_1_ = (char)((uint)uVar9 >> 8);
    cmd_pl.field_1._18_1_ = (char)((uint)uVar9 >> 0x10);
    cmd_pl.field_1._20_1_ = (req->field_2).app.initiator != false;
    cmd_pl.field_1._19_1_ = (char)((uint)uVar9 >> 0x18);
    uVar9 = 0x18;
    uVar8 = 0x1a;
  }
  else if (bVar2 == 4) {
    memcpy(&aps_hdr.aps_cntr,&req->field_2,0x10);
    uVar8 = *(undefined4 *)&(req->dst_address).field_0;
    puVar5 = (undefined4 *)((int)&(req->dst_address).field_0 + 4);
    uVar9 = *puVar5;
    cmd_pl.field_1.nwk.key[0xc] = (char)*(undefined2 *)&(req->dst_address).field_0;
    cmd_pl.field_1.nwk.key[0xd] = (char)((uint)uVar8 >> 8);
    cmd_pl.field_1.nwk.key[0xe] = (char)((uint)uVar8 >> 0x10);
    cmd_pl.field_1.nwk.key_seq = (char)*(undefined2 *)puVar5;
    cmd_pl.field_1.nwk.key[0xf] = (char)((uint)uVar8 >> 0x18);
    cmd_pl.field_1._17_1_ = (char)((uint)uVar9 >> 8);
    cmd_pl.field_1._18_1_ = (char)((uint)uVar9 >> 0x10);
    cmd_pl.field_1._19_1_ = (char)((uint)uVar9 >> 0x18);
    puVar5 = (undefined4 *)nwk_get_extended_address();
    uVar8 = *puVar5;
    uVar9 = puVar5[1];
    cmd_pl.field_1._20_1_ = (char)*(undefined3 *)puVar5;
    cmd_pl.field_1._21_1_ = (char)((uint)uVar8 >> 8);
    cmd_pl.field_1._22_1_ = (char)((uint)uVar8 >> 0x10);
    cmd_pl.field_1.app.initiator = (char)*(undefined3 *)(puVar5 + 1);
    cmd_pl.field_1._23_1_ = (char)((uint)uVar8 >> 0x18);
    cmd_pl.field_1._25_1_ = (char)((uint)uVar9 >> 8);
    cmd_pl.field_1._26_1_ = (char)((uint)uVar9 >> 0x10);
    cmd_pl.field_1._27_1_ = (char)((uint)uVar9 >> 0x18);
    uVar9 = 0x18;
    uVar8 = 0x21;
  }
  else {
    if (bVar2 != 1) {
      iVar4 = 2;
      goto _L0;
    }
    uVar9 = 0x10;
    memcpy(&aps_hdr.aps_cntr,&req->field_2,0x10);
    cmd_pl.field_1.nwk.key[0xc] = (req->field_2).nwk.key_seq;
    puVar5 = (undefined4 *)((int)&(req->dst_address).field_0 + 4);
    cmd_pl.field_1._13_2_ = *(undefined2 *)&(req->dst_address).field_0;
    cmd_pl.field_1._17_2_ = *(undefined2 *)puVar5;
    cmd_pl.field_1._15_2_ = (short)((uint)*(undefined4 *)&(req->dst_address).field_0 >> 0x10);
    cmd_pl.field_1._19_2_ = (short)((uint)*puVar5 >> 0x10);
    puVar5 = (undefined4 *)aps_secur_get_tc_address();
    cmd_pl.field_1._21_2_ = (short)*(undefined3 *)puVar5;
    cmd_pl.field_1._25_2_ = (short)*(undefined3 *)(puVar5 + 1);
    cmd_pl.field_1._23_2_ = (short)((uint)*puVar5 >> 0x10);
    cmd_pl.field_1._27_2_ = (undefined2)((uint)puVar5[1] >> 0x10);
    uVar8 = 0x22;
  }
  aps_frame_append_cmd_hdr(msg,0,iVar4,1,uVar9);
  uStack_48 = 5;
  zmsg_append_bytes(msg,1,&uStack_48);
  zmsg_append_bytes(msg,uVar8,&aps_hdr);
  if (iVar4 == 0) {
    iVar4 = aps_process_transmit_security(req,msg);
    if (iVar4 != 0) goto _L0;
    piVar6 = (int *)nwk_get_extended_address();
    if ((*(int *)&(req->tunnel_address).field_0 != *piVar6) ||
       (*(int *)((int)&(req->tunnel_address).field_0 + 4) != piVar6[1])) {
      uStack_48 = 1;
      pcVar7 = (char *)core_globals_get();
      cStack_47 = *pcVar7;
      *pcVar7 = cStack_47 + '\x01';
      zmsg_prepend_bytes(msg,8,req);
      cmd_pl.field_1._30_1_ = 0xe;
      zmsg_prepend_bytes(msg,1,(undefined1 *)((int)&cmd_pl.field_1 + 0x1e));
      zmsg_prepend_bytes(msg,2,&uStack_48);
      req = (apsme_transport_key_req_t *)&req->tunnel_address;
      goto _L0;
    }
    iVar4 = aps_relay_cmd(msg,&req->dst_address);
  }
  else {
    if (req->key_type == '\x01') {
      iVar4 = *(int *)((int)&req->field_2 + 0x11);
      iVar3 = *(int *)((int)&req->field_2 + 0x15);
      if ((iVar4 != 0 || iVar3 != 0) && ((iVar4 != -1 || (iVar3 != -1)))) {
        req = (apsme_transport_key_req_t *)&(req->field_2).nwk.parent_address;
      }
    }
_L0:
    iVar4 = aps_send_cmd(msg,&req->dst_address,true);
  }
  if (iVar4 == 0) {
    return 0;
  }
_L0:
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return iVar4;
}

