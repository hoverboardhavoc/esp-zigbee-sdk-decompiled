/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_bind_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_op_nwk_mgmt_bind_rsp(int param_1,char *param_2,int param_3)

{
  char *unaff_s0;
  int iVar1;
  void *pvVar2;
  char *extraout_a1;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ushort auStack_32 [7];
  
  if ((param_1 == 0) || (unaff_s0 = param_2, param_2 == (char *)0x0)) {
    param_3 = 0;
    param_1 = __assert_func(0,0,0);
    param_2 = extraout_a1;
  }
  if (param_3 == 0) {
    auStack_32[0] = 0;
    uVar3 = zmsg_get_length();
    af_read_le8_isra_0(param_1,auStack_32,unaff_s0);
    af_read_le8_isra_0(param_1,auStack_32,unaff_s0 + 1);
    af_read_le8_isra_0(param_1,auStack_32,unaff_s0 + 2);
    af_read_le8_isra_0(param_1,auStack_32,unaff_s0 + 3);
    if (uVar3 < auStack_32[0]) {
      return 0xfe;
    }
    if ((*unaff_s0 == '\0') && ((byte)unaff_s0[3] != 0)) {
      pvVar2 = calloc((uint)(byte)unaff_s0[3],0x18);
      *(void **)(unaff_s0 + 4) = pvVar2;
      if (pvVar2 == (void *)0x0) {
        return 0xfe;
      }
      for (uVar4 = 0; uVar4 < (byte)unaff_s0[3]; uVar4 = uVar4 + 1 & 0xff) {
        iVar1 = uVar4 * 0x18;
        af_read_bytes_isra_0(param_1,auStack_32,8,*(int *)(unaff_s0 + 4) + iVar1);
        af_read_le8_isra_0(param_1,auStack_32,*(int *)(unaff_s0 + 4) + iVar1 + 8);
        af_read_le16_isra_0(param_1,auStack_32,*(int *)(unaff_s0 + 4) + iVar1 + 10);
        af_read_le8_isra_0(param_1,auStack_32,*(int *)(unaff_s0 + 4) + iVar1 + 0xc);
        if (uVar3 < auStack_32[0]) {
          return 0xfe;
        }
        iVar5 = *(int *)(unaff_s0 + 4) + iVar1;
        if (*(char *)(iVar5 + 0xc) == '\x01') {
          af_read_le16_isra_0(param_1,auStack_32,iVar5 + 0xe);
          *(undefined1 *)(*(int *)(unaff_s0 + 4) + iVar1 + 0x16) = 0;
        }
        else {
          if (*(char *)(iVar5 + 0xc) != '\x03') {
            return 0x80;
          }
          af_read_bytes_isra_0(param_1,auStack_32,8,iVar5 + 0xe);
          af_read_le8_isra_0(param_1,auStack_32,*(int *)(unaff_s0 + 4) + iVar1 + 0x16);
        }
        if (uVar3 < auStack_32[0]) {
          return 0xfe;
        }
      }
    }
  }
  else {
    iVar1 = zmsg_append_u8(*param_2);
    if ((((iVar1 != 0) || (iVar1 = zmsg_append_u8(param_1,unaff_s0[1]), iVar1 != 0)) ||
        (iVar1 = zmsg_append_u8(param_1,unaff_s0[2]), iVar1 != 0)) ||
       (iVar1 = zmsg_append_u8(param_1,unaff_s0[3]), iVar1 != 0)) {
      return 0x8a;
    }
    if (((*unaff_s0 == '\0') && (*(int *)(unaff_s0 + 4) != 0)) && (unaff_s0[3] != '\0')) {
      for (uVar3 = 0; uVar3 < (byte)unaff_s0[3]; uVar3 = uVar3 + 1 & 0xff) {
        iVar5 = uVar3 * 0x18;
        iVar1 = zmsg_append_bytes(param_1,8,*(int *)(unaff_s0 + 4) + iVar5);
        if (iVar1 != 0) {
          return 0x8a;
        }
        iVar1 = zmsg_append_u8(param_1,*(undefined1 *)(*(int *)(unaff_s0 + 4) + iVar5 + 8));
        if (iVar1 != 0) {
          return 0x8a;
        }
        auStack_32[0] = *(ushort *)(*(int *)(unaff_s0 + 4) + iVar5 + 10);
        iVar1 = zmsg_append_bytes(param_1,2,auStack_32);
        if (iVar1 != 0) {
          return 0x8a;
        }
        iVar1 = zmsg_append_u8(param_1,*(undefined1 *)(*(int *)(unaff_s0 + 4) + iVar5 + 0xc));
        if (iVar1 != 0) {
          return 0x8a;
        }
        iVar1 = *(int *)(unaff_s0 + 4) + iVar5;
        if (*(char *)(iVar1 + 0xc) == '\x01') {
          auStack_32[0] = *(ushort *)(iVar1 + 0xe);
          iVar1 = zmsg_append_bytes(param_1,2,auStack_32);
_L0:
          if (iVar1 != 0) {
            return 0x8a;
          }
        }
        else if (*(char *)(iVar1 + 0xc) == '\x03') {
          iVar1 = zmsg_append_bytes(param_1,8,iVar1 + 0xe);
          if (iVar1 != 0) {
            return 0x8a;
          }
          iVar1 = zmsg_append_u8(param_1,*(undefined1 *)(*(int *)(unaff_s0 + 4) + iVar5 + 0x16));
          goto _L0;
        }
      }
    }
  }
  return 0;
}

