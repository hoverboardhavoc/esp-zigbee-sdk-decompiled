/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_match_desc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_match_desc_req_handler(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auStack_68 [64];
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 *puStack_20;
  uint auStack_1c [3];
  
  auStack_1c[0] = 0;
  auStack_1c[1] = 0;
  auStack_1c[2] = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  puStack_20 = (undefined1 *)0x0;
  if (param_1 == 0) {
    uVar4 = 0xfe;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    uVar4 = 0xfe;
  }
  else {
    iVar2 = zdo_op_match_desc_req(auStack_1c,0);
    if (iVar2 == 0) {
      uStack_28 = uStack_28 & 0xffffff00;
      uVar1 = (ushort)auStack_1c[0];
      if (0xfff7 < (auStack_1c[0] & 0xffff)) {
        uVar1 = nwk_get_short_address();
      }
      uStack_28 = CONCAT22(uVar1,(undefined2)uStack_28);
      uStack_24 = uStack_24 & 0xffffff00;
      memset(auStack_68,0,0x40);
      uVar5 = auStack_1c[0] & 0xffff;
      puStack_20 = auStack_68;
      uVar3 = nwk_get_short_address();
      if ((uVar5 == uVar3) || (0xfff7 < (auStack_1c[0] & 0xffff))) {
        iVar2 = zdo_match_desc_add_matched_ep_ids(auStack_1c,&uStack_28);
        uStack_24 = CONCAT31(uStack_24._1_3_,(char)iVar2);
        if ((iVar2 == 0) && (0xfff7 < (ushort)auStack_1c[0])) {
          uVar4 = 0xfe;
          goto _L0;
        }
        uStack_28 = uStack_28 & 0xffffff00;
      }
      else {
        iVar2 = nwk_is_device_zed();
        if (iVar2 == 0) {
          uStack_28 = CONCAT31(uStack_28._1_3_,0x81);
          iVar2 = 0;
          do {
            iVar2 = nwk_child_table_next(iVar2);
            if (iVar2 == 0) goto _L0;
          } while (((*(uint *)(iVar2 + 0xc) & 0x3c0) != 0x40) ||
                  (uVar5 = auStack_1c[0] & 0xffff, uVar3 = nwk_neighbor_get_shortaddr(iVar2),
                  uVar5 != uVar3));
          uStack_28 = CONCAT31(uStack_28._1_3_,0x89);
        }
        else {
          if (0xfff7 < *(ushort *)(param_1 + 2)) {
            uVar4 = 0xfe;
            goto _L0;
          }
          uStack_28 = CONCAT31(uStack_28._1_3_,0x80);
        }
      }
_L0:
      uVar4 = zdo_op_match_desc_rsp(*(undefined4 *)(param_2 + 0x14),&uStack_28,1);
    }
    else {
      uVar4 = 0xfe;
    }
  }
_L0:
  if (auStack_1c[2] != 0) {
    mm_free();
  }
  return uVar4;
}

