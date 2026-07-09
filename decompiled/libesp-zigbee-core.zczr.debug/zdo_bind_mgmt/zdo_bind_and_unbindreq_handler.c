/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_bind_mgmt.o -> zdo_bind_and_unbindreq_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_bind_and_unbindreq_handler(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined1 auStack_2c [4];
  int iStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iStack_28 = 0;
  iStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  auStack_2c[0] = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  if (param_1 == 0) {
    return 0xfe;
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    return 0xfe;
  }
  if (param_2 == 0) {
    return 0xfe;
  }
  if (0xfff7 < *(ushort *)(param_1 + 2)) {
    return 0xfe;
  }
  iVar1 = zdo_op_bind_and_unbind_req(&iStack_28,0);
  if (iVar1 != 0) {
    return 0xfe;
  }
  iVar1 = nwk_get_extended_address();
  if (iVar1 != 0) {
    piVar2 = (int *)nwk_get_extended_address();
    if ((iStack_28 == *piVar2) && (iStack_24 == piVar2[1])) {
      if (((uStack_20 & 0xff) - 1 & 0xff) < 0xfe) {
        uVar5 = uStack_1c & 0xff;
        if ((uVar5 != 3) && (uVar5 != 1)) {
          iVar1 = 0x80;
          goto _L0;
        }
        uStack_38 = CONCAT31(uStack_38._1_3_,(undefined1)uStack_1c);
        if (uVar5 == 3) {
          uStack_30 = (undefined2)uStack_14;
          uStack_38 = CONCAT22(uStack_1c._2_2_,(undefined2)uStack_38);
          uStack_34 = uStack_18;
        }
        else if (uVar5 == 1) {
          uStack_38 = CONCAT22(uStack_1c._2_2_,(undefined2)uStack_38);
          uStack_34 = CONCAT22(uStack_34._2_2_,(undefined2)uStack_18);
        }
        if (*(short *)(param_1 + 6) == 0x21) {
          aps_bind_table_add(&iStack_28,uStack_20._2_2_,&uStack_38,uStack_14._2_1_);
          iVar1 = ezb_err_to_zdp_status();
          if (iVar1 == 0x8a) {
            iVar1 = 0x8c;
          }
          else if (iVar1 == 0xfe) {
            return 0xfe;
          }
          goto _L0;
        }
        if (*(short *)(param_1 + 6) == 0x22) {
          iVar4 = aps_bind_table_remove(&iStack_28,uStack_20._2_2_,&uStack_38,uStack_14._2_1_);
          iVar1 = 0;
          if (iVar4 != 0) {
            iVar1 = 0x88;
          }
          goto _L0;
        }
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_bind_mgmt.c",0xc2,
                      "zdo_bind_and_unbindreq_handler",&_LC3);
      }
      iVar1 = 0x82;
      goto _L0;
    }
  }
  iVar1 = 0x84;
_L0:
  auStack_2c[0] = (undefined1)iVar1;
  uVar3 = zdo_op_bind_and_unbind_rsp(*(undefined4 *)(param_2 + 0x14),auStack_2c,1);
  return uVar3;
}

