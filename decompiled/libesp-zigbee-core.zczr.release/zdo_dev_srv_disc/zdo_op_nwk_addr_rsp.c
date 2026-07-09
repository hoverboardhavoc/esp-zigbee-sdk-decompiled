/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_op_nwk_addr_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_op_nwk_addr_rsp(int param_1,int param_2,char *param_3,int param_4)

{
  char *unaff_s0;
  int iVar1;
  void *pvVar2;
  int extraout_a1;
  uint uVar3;
  uint uVar4;
  ushort auStack_22 [7];
  
  if ((param_1 == 0) || (unaff_s0 = param_3, param_3 == (char *)0x0)) {
    param_4 = 0;
    param_3 = (char *)0x0;
    param_1 = __assert_func(0,0);
    param_2 = extraout_a1;
  }
  if (param_4 == 0) {
    auStack_22[0] = 0;
    uVar3 = zmsg_get_length();
    af_read_le8_isra_0(param_1,auStack_22,unaff_s0);
    af_read_bytes_isra_0(param_1,auStack_22,8,unaff_s0 + 1);
    af_read_le16_isra_0(param_1,auStack_22,unaff_s0 + 10);
    if ((*unaff_s0 == '\0') && (auStack_22[0] < uVar3)) {
      af_read_le8_isra_0(param_1,auStack_22,unaff_s0 + 0xc);
      if ((byte)unaff_s0[0xc] != 0) {
        pvVar2 = calloc((uint)(byte)unaff_s0[0xc],2);
        *(void **)(unaff_s0 + 0x10) = pvVar2;
        if (pvVar2 == (void *)0x0) {
          return 0x8a;
        }
        af_read_le8_isra_0(param_1,auStack_22,unaff_s0 + 0xd);
        for (uVar4 = 0; uVar4 < (byte)unaff_s0[0xc]; uVar4 = uVar4 + 1 & 0xff) {
          af_read_le16_isra_0(param_1,auStack_22,*(int *)(unaff_s0 + 0x10) + uVar4 * 2);
        }
      }
    }
    else {
      unaff_s0[0xc] = '\0';
      unaff_s0[0xd] = '\0';
      unaff_s0[0x10] = '\0';
      unaff_s0[0x11] = '\0';
      unaff_s0[0x12] = '\0';
      unaff_s0[0x13] = '\0';
    }
    if (uVar3 < auStack_22[0]) {
      return 0xfe;
    }
  }
  else {
    iVar1 = zmsg_append_u8(*param_3);
    if (((iVar1 != 0) || (iVar1 = zmsg_append_bytes(param_1,8,unaff_s0 + 1), iVar1 != 0)) ||
       (iVar1 = zmsg_append_le16(param_1,*(undefined2 *)(unaff_s0 + 10)), iVar1 != 0)) {
      return 0x8a;
    }
    if ((*unaff_s0 == '\0') && (param_2 == 1)) {
      iVar1 = zmsg_append_u8(param_1,unaff_s0[0xc]);
      if (iVar1 != 0) {
        return 0x8a;
      }
      if ((unaff_s0[0xc] != '\0') && (*(int *)(unaff_s0 + 0x10) != 0)) {
        iVar1 = zmsg_append_u8(param_1,unaff_s0[0xd]);
        uVar3 = 0;
        if (iVar1 != 0) {
          return 0x8a;
        }
        for (; uVar3 < (byte)unaff_s0[0xc]; uVar3 = uVar3 + 1 & 0xff) {
          iVar1 = zmsg_append_le16(param_1,*(undefined2 *)(*(int *)(unaff_s0 + 0x10) + uVar3 * 2));
          if (iVar1 != 0) {
            return 0x8a;
          }
        }
      }
    }
  }
  return 0;
}

