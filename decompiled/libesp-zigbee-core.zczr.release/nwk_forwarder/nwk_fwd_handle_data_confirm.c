/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_handle_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_handle_data_confirm(undefined4 param_1,int *param_2)

{
  int iVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  byte bVar6;
  char cStack_2c;
  byte bStack_2b;
  ushort uStack_2a;
  undefined1 auStack_28 [2];
  ushort uStack_26;
  ushort uStack_24;
  ushort auStack_22 [5];
  
  uStack_2a = 0;
  if (*param_2 == 0) {
    return;
  }
  zmsg_read_le16_isra_0(0,&uStack_2a);
  if ((uStack_2a & 0x3c) != 8) {
    return;
  }
  iVar1 = *param_2;
  if ((uStack_2a & 3) == 3) {
    auStack_22[0] = 0;
    uVar5 = 3;
    if ((iVar1 != 0) && (zmsg_read_le16_isra_0(iVar1,0,auStack_22), (auStack_22[0] & 3) == 3)) {
      uVar5 = 0;
      if (*(byte *)(param_2 + 1) != 0) {
        uVar5 = *(byte *)(param_2 + 1) | 0x200;
      }
      nwk_handle_intrp_data_sent(iVar1,uVar5);
      return;
    }
_L0:
    __assert_func(0,0,0,0);
  }
  else {
    uVar5 = 0;
    if (*(byte *)(param_2 + 1) != 0) {
      uVar5 = *(byte *)(param_2 + 1) | 0x100;
    }
    iVar3 = nwk_process_receive_security(param_1,iVar1);
    if (iVar3 != 0) goto _L0;
  }
  zmsg_read_le16_isra_0(iVar1,4,auStack_28);
  zmsg_read_le16_isra_0(iVar1,2,&uStack_26);
  if ((((uint)param_2[1] >> 8 & 1) != 0) ||
     ((uStack_26 < 0xfff8 &&
      ((0x10 < uVar5 - 0x1e1 || ((0x10101U >> (uVar5 - 0x1e1 & 0x1f) & 1) == 0)))))) goto _L0;
  cStack_2c = '\0';
  zmsg_read_le16_isra_0(iVar1,0,&uStack_24);
  zmsg_read_le16_isra_0(iVar1,2,auStack_22);
  if ((uStack_24 & 3) == 1) {
    uVar4 = zmsg_get_offset(iVar1);
    zmsg_read_u8_isra_0(iVar1,uVar4,&cStack_2c);
  }
  if ((cStack_2c == '\b') || (cStack_2c == '\r')) goto _L0;
  if (cStack_2c == '\x01') {
    sVar2 = zmsg_get_offset(iVar1);
    zmsg_read_u8_isra_0(iVar1,sVar2 + 1,&bStack_2b);
    if ((bStack_2b & 0x18) != 0) goto _L0;
    iVar3 = 0xfe;
    if ((*(ushort *)(iVar1 + 0x16) & 8) == 0) goto _L0;
    iVar3 = random_add_jitter(2,0x7e);
    bVar6 = 2;
  }
  else {
    iVar3 = 0x32;
    if (auStack_22[0] < 0xfff8) {
_L0:
      bVar6 = 3;
    }
    else {
      iVar3 = core_globals_get();
      bVar6 = *(byte *)(iVar3 + 0x9d8);
      iVar3 = core_globals_get();
      iVar3 = random_add_jitter(*(undefined2 *)(iVar3 + 0x9d6),0x40);
    }
  }
  if (*(byte *)(iVar1 + 0x14) < bVar6) {
    *(byte *)(iVar1 + 0x14) = *(byte *)(iVar1 + 0x14) + 1;
    if (iVar3 != 0) {
      zmsg_tmque_enqueue(&s_nwk_fwd,iVar1);
      return;
    }
    nwk_fwd_do_send_msg(iVar1);
    return;
  }
_L0:
  if ((((uint)param_2[1] >> 8 & 1) != 0) && (0xfff7 < uStack_26)) {
    zmsg_free(iVar1);
    return;
  }
  nwk_fwd_finish_tx(iVar1,uVar5);
  return;
}

