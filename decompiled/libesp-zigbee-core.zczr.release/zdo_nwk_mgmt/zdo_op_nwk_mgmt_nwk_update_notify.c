/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_nwk_update_notify
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_op_nwk_mgmt_nwk_update_notify(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *unaff_s0;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 *extraout_a1;
  short sVar4;
  undefined4 uStack_24;
  
  if ((param_1 == 0) || (unaff_s0 = param_2, param_2 == (undefined1 *)0x0)) {
    param_3 = 0;
    param_1 = __assert_func(0,0,0);
    param_2 = extraout_a1;
  }
  if (param_3 == 0) {
    uStack_24 = (uint)uStack_24._2_2_ << 0x10;
    uVar3 = zmsg_get_length();
    af_read_le8_isra_0(param_1,&uStack_24,unaff_s0);
    sVar4 = (short)uStack_24;
    iVar1 = zmsg_read_bytes(param_1,uStack_24 & 0xffff,4,unaff_s0 + 4);
    if (iVar1 == 0) {
      sVar4 = -1;
    }
    else {
      sVar4 = sVar4 + (short)iVar1;
    }
    uStack_24 = CONCAT22(uStack_24._2_2_,sVar4);
    af_read_le16_isra_0(param_1,&uStack_24,unaff_s0 + 8);
    af_read_le16_isra_0(param_1,&uStack_24,unaff_s0 + 10);
    af_read_le8_isra_0(param_1,&uStack_24,unaff_s0 + 0xc);
    af_read_bytes_isra_0(param_1,&uStack_24,unaff_s0[0xc],unaff_s0 + 0xd);
    if (uVar3 < (uStack_24 & 0xffff)) {
      return 0xfe;
    }
_L0:
    uVar2 = 0;
  }
  else {
    iVar1 = zmsg_append_u8(*param_2);
    if (iVar1 == 0) {
      uStack_24 = *(uint *)(unaff_s0 + 4);
      iVar1 = zmsg_append_bytes(param_1,4,&uStack_24);
      if (iVar1 == 0) {
        uStack_24._0_2_ = *(undefined2 *)(unaff_s0 + 8);
        iVar1 = zmsg_append_bytes(param_1,2,&uStack_24);
        if (iVar1 == 0) {
          uStack_24 = CONCAT22(uStack_24._2_2_,*(undefined2 *)(unaff_s0 + 10));
          iVar1 = zmsg_append_bytes(param_1,2,&uStack_24);
          if (((iVar1 == 0) && (iVar1 = zmsg_append_u8(param_1,unaff_s0[0xc]), iVar1 == 0)) &&
             (iVar1 = zmsg_append_bytes(param_1,unaff_s0[0xc],unaff_s0 + 0xd), iVar1 == 0))
          goto _L0;
        }
      }
    }
    uVar2 = 0x8a;
  }
  return uVar2;
}

