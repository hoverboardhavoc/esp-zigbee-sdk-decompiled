/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
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
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  zmsg_t *msg;
  undefined4 *puVar7;
  int *piVar8;
  char *pcVar9;
  undefined4 uVar10;
  int iVar11;
  bool bVar12;
  undefined4 uVar13;
  undefined1 uStack_58;
  char cStack_57;
  aps_cmd_hdr_t aps_hdr;
  aps_cmd_transport_key_t cmd_pl;
  
  iVar5 = *(int *)&(req->tunnel_address).field_0;
  iVar11 = *(int *)((int)&(req->tunnel_address).field_0 + 4);
  if (iVar5 == 0 && iVar11 == 0) {
    bVar12 = true;
  }
  else if ((iVar5 == -1) && (iVar11 == -1)) {
    bVar12 = true;
  }
  else {
    bVar12 = false;
  }
  uVar3 = *(uint *)&(req->dst_address).field_0;
  uVar4 = *(uint *)((int)&(req->dst_address).field_0 + 4);
  if (bVar12) {
    if ((uVar3 == 0xffffffff) && (uVar4 == 0xffffffff)) {
      uVar13 = 0;
    }
    else {
      uVar13 = 1;
    }
    if (req == (apsme_transport_key_req_t *)0x0) {
      iVar5 = 2;
      msg = (zmsg_t *)0x0;
      goto _L0;
    }
  }
  else {
    uVar13 = 0;
  }
  if (uVar3 == 0 && uVar4 == 0) {
    msg = (zmsg_t *)0x0;
    iVar5 = 2;
    goto _L0;
  }
  if ((uVar3 == 0xffffffff) && (uVar4 == 0xffffffff)) {
    iVar5 = 0x27;
    iVar11 = 0;
  }
  else {
    iVar5 = 0x2f;
    iVar11 = 0xd;
  }
  msg = (zmsg_t *)zmsg_alloc(iVar5 + iVar11);
  if (msg == (zmsg_t *)0x0) {
    iVar5 = 1;
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
    puVar7 = (undefined4 *)((int)&req->field_2 + 0x10);
    uVar6 = *puVar7;
    puVar1 = (undefined4 *)((int)&req->field_2 + 0x14);
    uVar10 = *puVar1;
    cmd_pl.field_1.nwk.key[0xc] = (char)*(undefined2 *)puVar7;
    cmd_pl.field_1.nwk.key[0xd] = (char)((uint)uVar6 >> 8);
    cmd_pl.field_1.nwk.key[0xe] = (char)((uint)uVar6 >> 0x10);
    cmd_pl.field_1.nwk.key_seq = (char)*(undefined2 *)puVar1;
    cmd_pl.field_1.nwk.key[0xf] = (char)((uint)uVar6 >> 0x18);
    cmd_pl.field_1._17_1_ = (char)((uint)uVar10 >> 8);
    cmd_pl.field_1._18_1_ = (char)((uint)uVar10 >> 0x10);
    cmd_pl.field_1._20_1_ = (req->field_2).app.initiator != false;
    cmd_pl.field_1._19_1_ = (char)((uint)uVar10 >> 0x18);
    uVar10 = 0x18;
    uVar6 = 0x1a;
  }
  else if (bVar2 == 4) {
    memcpy(&aps_hdr.aps_cntr,&req->field_2,0x10);
    uVar6 = *(undefined4 *)&(req->dst_address).field_0;
    puVar7 = (undefined4 *)((int)&(req->dst_address).field_0 + 4);
    uVar10 = *puVar7;
    cmd_pl.field_1.nwk.key[0xc] = (char)*(undefined2 *)&(req->dst_address).field_0;
    cmd_pl.field_1.nwk.key[0xd] = (char)((uint)uVar6 >> 8);
    cmd_pl.field_1.nwk.key[0xe] = (char)((uint)uVar6 >> 0x10);
    cmd_pl.field_1.nwk.key_seq = (char)*(undefined2 *)puVar7;
    cmd_pl.field_1.nwk.key[0xf] = (char)((uint)uVar6 >> 0x18);
    cmd_pl.field_1._17_1_ = (char)((uint)uVar10 >> 8);
    cmd_pl.field_1._18_1_ = (char)((uint)uVar10 >> 0x10);
    cmd_pl.field_1._19_1_ = (char)((uint)uVar10 >> 0x18);
    puVar7 = (undefined4 *)nwk_get_extended_address();
    uVar6 = *puVar7;
    uVar10 = puVar7[1];
    cmd_pl.field_1._20_1_ = (char)*(undefined3 *)puVar7;
    cmd_pl.field_1._21_1_ = (char)((uint)uVar6 >> 8);
    cmd_pl.field_1._22_1_ = (char)((uint)uVar6 >> 0x10);
    cmd_pl.field_1.app.initiator = (char)*(undefined3 *)(puVar7 + 1);
    cmd_pl.field_1._23_1_ = (char)((uint)uVar6 >> 0x18);
    cmd_pl.field_1._25_1_ = (char)((uint)uVar10 >> 8);
    cmd_pl.field_1._26_1_ = (char)((uint)uVar10 >> 0x10);
    cmd_pl.field_1._27_1_ = (char)((uint)uVar10 >> 0x18);
    uVar10 = 0x18;
    uVar6 = 0x21;
  }
  else {
    if (bVar2 != 1) {
      iVar5 = 2;
      goto _L0;
    }
    memcpy(&aps_hdr.aps_cntr,&req->field_2,0x10);
    cmd_pl.field_1.nwk.key[0xc] = (req->field_2).nwk.key_seq;
    if ((uVar3 != 0xffffffff) || (uVar4 != 0xffffffff)) {
      cmd_pl.field_1._13_2_ = *(undefined2 *)&(req->dst_address).field_0;
      puVar7 = (undefined4 *)((int)&(req->dst_address).field_0 + 4);
      cmd_pl.field_1._17_2_ = *(undefined2 *)puVar7;
      cmd_pl.field_1._15_2_ = (short)((uint)*(undefined4 *)&(req->dst_address).field_0 >> 0x10);
      cmd_pl.field_1._19_2_ = (short)((uint)*puVar7 >> 0x10);
    }
    puVar7 = (undefined4 *)aps_secur_get_tc_address();
    cmd_pl.field_1._21_2_ = (short)*(undefined3 *)puVar7;
    cmd_pl.field_1._25_2_ = (short)*(undefined3 *)(puVar7 + 1);
    cmd_pl.field_1._23_2_ = (short)((uint)*puVar7 >> 0x10);
    cmd_pl.field_1._27_2_ = (undefined2)((uint)puVar7[1] >> 0x10);
    uVar10 = 0x10;
    uVar6 = 0x22;
  }
  aps_frame_append_cmd_hdr
            (msg,(uVar3 & uVar4) == 0xffffffff,uVar13,(uVar3 & uVar4) != 0xffffffff,uVar10);
  uStack_58 = 5;
  zmsg_append_bytes(msg,1,&uStack_58);
  zmsg_append_bytes(msg,uVar6,&aps_hdr);
  if (bVar12) {
    if (req->key_type == '\x01') {
      iVar5 = *(int *)((int)&req->field_2 + 0x11);
      iVar11 = *(int *)((int)&req->field_2 + 0x15);
      if ((iVar5 != 0 || iVar11 != 0) && ((iVar5 != -1 || (iVar11 != -1)))) {
        req = (apsme_transport_key_req_t *)&(req->field_2).nwk.parent_address;
      }
    }
_L0:
    iVar5 = aps_send_cmd(msg,&req->dst_address);
  }
  else {
    iVar5 = aps_process_transmit_security(req,msg);
    if (iVar5 != 0) goto _L0;
    piVar8 = (int *)nwk_get_extended_address();
    if ((*(int *)&(req->tunnel_address).field_0 != *piVar8) ||
       (*(int *)((int)&(req->tunnel_address).field_0 + 4) != piVar8[1])) {
      uStack_58 = 1;
      pcVar9 = (char *)core_globals_get();
      cStack_57 = *pcVar9;
      *pcVar9 = cStack_57 + '\x01';
      zmsg_prepend_bytes(msg,8,req);
      cmd_pl.field_1._30_1_ = 0xe;
      zmsg_prepend_bytes(msg,1,(undefined1 *)((int)&cmd_pl.field_1 + 0x1e));
      zmsg_prepend_bytes(msg,2,&uStack_58);
      req = (apsme_transport_key_req_t *)&req->tunnel_address;
      goto _L0;
    }
    iVar5 = aps_relay_cmd(msg,&req->dst_address);
  }
  if (iVar5 == 0) {
    return 0;
  }
_L0:
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return iVar5;
}

